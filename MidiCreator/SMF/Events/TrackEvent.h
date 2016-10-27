#pragma once

#include "../../stdafx.h"
#include "../../Abstract/IEvent.h"
#include "../../Abstract/IConvertibleToByteCollection.h"
#include "../Enums/EventType.h"
#include "MetaEvent.h"
#include "MidiEvent.h"
#include "SystemExclusiveEvent.h"

namespace SMF
{
	class TrackEvent :
		IConvertibleToByteCollection
	{
	private:
		VLQ* deltaTime;
		IEvent* event;

	public:
		TrackEvent(EventType);
		~TrackEvent();

		inline TrackEvent* setDeltaTime(int v) { this->deltaTime = new VLQ(v); }
		inline IEvent* getInnerEvent() { return this->event; }

		//IConvertibleToByteCollection
		virtual std::vector<uint8_t> toByteVector();
	};
}

