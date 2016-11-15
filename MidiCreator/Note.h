#pragma once

#include "SMF/Enums/NotePitch.h"

class Note
{
private:
	SMF::NotePitch _pitch;
	uint8_t _volume;
	uint16_t _duration;

public:
	static const uint8_t MAX_VOLUME = 127;

	Note(SMF::NotePitch pitch, uint16_t duration);
	Note(SMF::NotePitch pitch, uint8_t volume, uint16_t duration);

	void pitch(const SMF::NotePitch& val) { this->_pitch = val; }
	const SMF::NotePitch& pitch() const { return this->_pitch; }

	void volume(const uint8_t& val) { this->_volume = val; }
	const uint8_t& volume() const { return this->_volume; }

	void duration(const uint16_t& val) { this->_duration = val; }
	const uint16_t& duration() const { return this->_duration; }
};