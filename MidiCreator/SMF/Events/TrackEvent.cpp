#include "TrackEvent.h"

using namespace SMF;
using namespace SMF::Exceptions;

TrackEvent::TrackEvent(EventType eventType)
{
	switch (eventType)
	{
		case EventType::META_EVENT: 
			this->event = new MetaEvent();
			break;
		case EventType::MIDI_EVENT:
			this->event = new MidiEvent();
			break;
		case EventType::SYSTEM_EXCLUSIVE_EVENT:
			this->event = new SystemExclusiveEvent();
			break;
		default:
			break;
		//TODO: Throw some exception
	}
}

TrackEvent* TrackEvent::setDeltaTime(int time)
{ 
	this->deltaTime = new VLQ(time); 
	return this; 
}

std::vector<uint8_t> TrackEvent::toByteVector()
{
	#ifdef DEBUG
		printf("TrackEvent::toByteVector()\n");
	#endif // DEBUG

	if (this->deltaTime == nullptr || this->event == nullptr)
	{
		throw new EventNotInitializedException;
	}
	
	std::vector<uint8_t> ret = this->deltaTime->getVlq();

	std::vector<uint8_t> eventBytes = this->event->toByteVector();

	ret.insert(ret.end(), eventBytes.begin(), eventBytes.end());

	return ret;
}

TrackEvent::~TrackEvent()
{
	delete this->deltaTime;
	delete this->event;
}
