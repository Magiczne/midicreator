#pragma once

#include "Abstract/IConvertibleToByteCollection.h"
#include "Enums/EventType.h"
#include "Enums/GMPatch.h"
#include "Enums/MIDIChannel.h"

namespace SMF 
{
	class TrackEvent;
	class Note;

	class TrackChunk : public IConvertibleToByteCollection
	{
	private:
		const std::array<char, 4> _chunkType = { 'M', 'T', 'r', 'k' };
		uint32_t _tracksLength = 0;
		std::vector<std::shared_ptr<TrackEvent>> _trackEvents;

		MIDIChannel _currentChannel = MIDIChannel::CHANNEL_1;
		bool _closed = false;
		bool _tracksCalculated = false;

		void calculateTracksLength();
	public:
		std::shared_ptr<TrackEvent> addTrackEvent(EventType eventType);

		TrackChunk& setCurrentChannel(MIDIChannel channel);

		TrackChunk& setVoiceProgram(GMPatch patch);

		TrackChunk& addNote(const Note& note);
		TrackChunk& addNotes(std::vector<Note>& notes);

		void closeTrack();
		void reopenTrack();

		void prepareToExport();

		//IConvertibleToByteCollection
		std::vector<uint8_t> toByteVector() const override;
	};
}