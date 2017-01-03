#include "StandardMIDIFile.h"

#include "HeaderChunk.h"
#include "TrackChunk.h"
#include "Events/TrackEvent.h"
#include "Events/MidiEvent.h"
#include "Events/MetaEvent.h"
#include "Exceptions/BpmOutOfRangeException.h"
#include "Exceptions/IllegalDenominatorException.h"
#include "Exceptions/NoTracksException.h"
#include "Exceptions/TrackNumberOutOfRangeException.h"

using namespace SMF;
using namespace SMF::Exceptions;

StandardMIDIFile::~StandardMIDIFile()
{
	delete this->headerChunk;

	for (auto &tc : this->trackChunks)
	{
		delete tc;
	}
}

void StandardMIDIFile::setCurrentTrack(size_t track)
{
	if (this->trackChunks.empty())
	{
		throw NoTracksException();
	}

	if (track >= this->trackChunks.size())
	{
		throw TrackNumberOutOfRangeException();
	}

	this->currentTrack = track;
}

/*
throws IllegalDenominatorException
throws NoTrackException
*/
void StandardMIDIFile::setTimeSignature(
	uint8_t numerator,
	uint8_t denominator,
	uint8_t midiClocksPerMetronomeClick,
	uint8_t numberOf32NotesInMidiQuarterNote)
{
	double convertedDenominator = log2(denominator);
	if (floor(convertedDenominator) != convertedDenominator)
	{
		throw IllegalDenominatorException();
	}

	if (this->headerChunk->fileFormat() == FileFormat::SINGLE_TRACK)
	{
		if (this->trackChunks.empty())
		{
			throw NoTracksException();
		}

		this->trackChunks.front()
			->addTrackEvent(EventType::META_EVENT)
			->setDeltaTime(0)
			->getInnerEvent<MetaEvent>()
			->setEventType(MetaEventType::TIME_SIGNATURE)
			->setLength(4)
			->addParam(numerator)
			->addParam(static_cast<uint8_t>(convertedDenominator))
			->addParam(midiClocksPerMetronomeClick)
			->addParam(numberOf32NotesInMidiQuarterNote);
	}
	else if(this->headerChunk->fileFormat() == FileFormat::MULTIPLE_TRACK)
	{
		//TODO
	}
	else
	{
		//Multiple Song. Find how to do that
	}
}

/*
throws SMF::BpmOutOfRangeException
throws SMF::NoTrackException
*/
void StandardMIDIFile::setTempo(short bpm)
{
	if (bpm < MIN_BPM || bpm > MAX_BPM) 
	{
		throw BpmOutOfRangeException();
	}

	int microSecoundsPerQuarterNote = 60000000 / bpm;

	if (this->headerChunk->fileFormat() == FileFormat::SINGLE_TRACK)
	{
		if (this->trackChunks.empty())
		{
			throw NoTracksException();
		}

		this->trackChunks.front()
			->addTrackEvent(EventType::META_EVENT)
			->setDeltaTime(0)
			->getInnerEvent<MetaEvent>()
			->setEventType(MetaEventType::TEMPO_SETTING)
			->setLength(3)
			->addParam((microSecoundsPerQuarterNote >> 16) & 0xFF)
			->addParam((microSecoundsPerQuarterNote >> 8) & 0xFF)
			->addParam(microSecoundsPerQuarterNote & 0xFF);
	}
	else if (this->headerChunk->fileFormat() == FileFormat::MULTIPLE_TRACK)
	{
		//TODO: Do that
	}
	else
	{
		//TODO: Multiple Song. Find how to do that
	}
}

void StandardMIDIFile::exportToFile(std::string filename)
{
	std::vector<uint8_t> ret = this->toByteVector();

	std::ofstream file(filename, std::ios::trunc | std::ios::binary);
	
	if (file.good())
	{
		for (auto &e : ret)
		{
			file << e;
		}

		file.close();
	}
}

/*
throws NoTracksException
*/
std::vector<uint8_t> StandardMIDIFile::toByteVector()
{
	if (this->trackChunks.empty())
	{
		throw NoTracksException();
	}

	std::vector<uint8_t> ret = this->headerChunk->toByteVector();

	std::vector<uint8_t> trackBytes;

	std::vector<uint8_t> tmpVector;
	for (auto &a : this->trackChunks)
	{
		tmpVector = a->toByteVector();
		trackBytes.insert(trackBytes.end(), tmpVector.begin(), tmpVector.end());
	}

	ret.insert(ret.end(), trackBytes.begin(), trackBytes.end());

	return ret;
}