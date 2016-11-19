#pragma once

#include "../../stdafx.h"
#include "../Enums/FileFormat.h"
#include "../Enums/MIDIChannel.h"
#include "../Enums/NotePitch.h"
#include "../Enums/GMPercussion.h"

namespace SMF
{
	static std::map<FileFormat, std::string> FileFormatMap =
	{
		{ FileFormat::SINGLE_TRACK, "Single track" },
		{ FileFormat::MULTIPLE_TRACK, "Multiple tracks" },
		{ FileFormat::MULTIPLE_SONG, "Multiple songs" }
	};

	static std::map<NotePitch, std::string> NotePitchMap =
	{
		//Octave -1
		{ NotePitch::C_MINUS_1, "C-1" },
		{ NotePitch::C_MINUS_1_SHARP, "C#-1" },
		{ NotePitch::D_MINUS_1, "D-1" },
		{ NotePitch::D_MINUS_1_SHARP, "Eb-1" },
		{ NotePitch::E_MINUS_1, "E-1" },
		{ NotePitch::F_MINUS_1, "F-1" },
		{ NotePitch::F_MINUS_1_SHARP, "F-1" },
		{ NotePitch::G_MINUS_1, "G-1" },
		{ NotePitch::G_MINUS_1_SHARP, "G#-1" },
		{ NotePitch::A_MINUS_1, "A-1" },
		{ NotePitch::A_MINUS_1_SHARP , "Bb-1" },
		{ NotePitch::B_MINUS_1 , "B-1" },

		//Octave 2
		{ NotePitch::C0, "C0" },
		{ NotePitch::C0_SHARP, "C#0" },
		{ NotePitch::D0, "D0" },
		{ NotePitch::D0_SHARP, "Eb0" },
		{ NotePitch::E0, "E0" },
		{ NotePitch::F0, "F0" },
		{ NotePitch::F0_SHARP, "F#0" },
		{ NotePitch::G0, "G0" },
		{ NotePitch::G0_SHARP, "G#0" },
		{ NotePitch::A0, "A0" },
		{ NotePitch::A0_SHARP, "Bb0" },
		{ NotePitch::B0, "B0" },
		
		//Octave 1
		{ NotePitch::C1, "C1" },
		{ NotePitch::C1_SHARP, "C#1" },
		{ NotePitch::D1, "D1" },
		{ NotePitch::D1_SHARP, "Eb1" },
		{ NotePitch::E1, "E1" },
		{ NotePitch::F1, "F1" },
		{ NotePitch::F1_SHARP, "F#1" },
		{ NotePitch::G1, "G1" },
		{ NotePitch::G1_SHARP, "G#1" },
		{ NotePitch::A1, "A1" },
		{ NotePitch::A1_SHARP, "Bb1" },
		{ NotePitch::B1, "B1" },

		//Octave 2
		{ NotePitch::C2, "C2" },
		{ NotePitch::C2_SHARP, "C#2" },
		{ NotePitch::D2, "D2" },
		{ NotePitch::D2_SHARP, "Eb2" },
		{ NotePitch::E2, "E2" },
		{ NotePitch::F2, "F2" },
		{ NotePitch::F2_SHARP, "F#2" },
		{ NotePitch::G2, "G2" },
		{ NotePitch::G2_SHARP, "G#2" },
		{ NotePitch::A2, "A2" },
		{ NotePitch::A2_SHARP, "Bb2" },
		{ NotePitch::B2, "B2" },

		//Octave 3
		{ NotePitch::C3, "C3" },
		{ NotePitch::C3_SHARP, "C#3" },
		{ NotePitch::D3, "D3" },
		{ NotePitch::D3_SHARP, "Eb3" },
		{ NotePitch::E3, "E3" },
		{ NotePitch::F3, "F3" },
		{ NotePitch::F3_SHARP, "F#3" },
		{ NotePitch::G3, "G3" },
		{ NotePitch::G3_SHARP, "G#3" },
		{ NotePitch::A3, "A3" },
		{ NotePitch::A3_SHARP, "Bb3" },
		{ NotePitch::B3, "B3" },

		//Octave 4
		{ NotePitch::C4, "C4" },
		{ NotePitch::C4_SHARP, "C#4" },
		{ NotePitch::D4, "D4" },
		{ NotePitch::D4_SHARP, "Eb4" },
		{ NotePitch::E4, "E4" },
		{ NotePitch::F4, "F4" },
		{ NotePitch::F4_SHARP, "F#4" },
		{ NotePitch::G4, "G4" },
		{ NotePitch::G4_SHARP, "G#4" },
		{ NotePitch::A4, "A4" },
		{ NotePitch::A4_SHARP, "Bb4" },
		{ NotePitch::B4, "B4" },

		//Octave 5
		{ NotePitch::C5, "C5" },
		{ NotePitch::C5_SHARP, "C#5" },
		{ NotePitch::D5, "D5" },
		{ NotePitch::D5_SHARP, "Eb5" },
		{ NotePitch::E5, "E5" },
		{ NotePitch::F5, "F5" },
		{ NotePitch::F5_SHARP, "F#5" },
		{ NotePitch::G5, "G5" },
		{ NotePitch::G5_SHARP, "G#5" },
		{ NotePitch::A5, "A5" },
		{ NotePitch::A5_SHARP, "Bb5" },
		{ NotePitch::B5, "B5" },

		//Octave 6
		{ NotePitch::C6, "C6" },
		{ NotePitch::C6_SHARP, "C#6" },
		{ NotePitch::D6, "D6" },
		{ NotePitch::D6_SHARP, "Eb6" },
		{ NotePitch::E6, "E6" },
		{ NotePitch::F6, "F6" },
		{ NotePitch::F6_SHARP, "F#6" },
		{ NotePitch::G6, "G6" },
		{ NotePitch::G6_SHARP, "G#6" },
		{ NotePitch::A6, "A6" },
		{ NotePitch::A6_SHARP, "Bb6" },
		{ NotePitch::B6, "B6" },

		//Octave 7
		{ NotePitch::C7, "C7" },
		{ NotePitch::C7_SHARP, "C#7" },
		{ NotePitch::D7, "D7" },
		{ NotePitch::D7_SHARP, "Eb7" },
		{ NotePitch::E7, "E7" },
		{ NotePitch::F7, "F7" },
		{ NotePitch::F7_SHARP, "F#7" },
		{ NotePitch::G7, "G7" },
		{ NotePitch::G7_SHARP, "G#7" },
		{ NotePitch::A7, "A7" },
		{ NotePitch::A7_SHARP, "Bb7" },
		{ NotePitch::B7, "B7" },

		//Octave 8
		{ NotePitch::C8, "C8" },
		{ NotePitch::C8_SHARP, "C#8" },
		{ NotePitch::D8, "D8" },
		{ NotePitch::D8_SHARP, "Eb8" },
		{ NotePitch::E8, "E8" },
		{ NotePitch::F8, "F8" },
		{ NotePitch::F8_SHARP, "F#8" },
		{ NotePitch::G8, "G8" },
		{ NotePitch::G8_SHARP, "G#8" },
		{ NotePitch::A8, "A8" },
		{ NotePitch::A8_SHARP, "Bb8" },
		{ NotePitch::B8, "B8" },

		//Octave 9
		{ NotePitch::C9, "C9" },
		{ NotePitch::C9_SHARP, "C#9" },
		{ NotePitch::D9, "D9" },
		{ NotePitch::D9_SHARP, "Eb9" },
		{ NotePitch::E9, "E9" },
		{ NotePitch::F9, "F9" },
		{ NotePitch::F9_SHARP, "F#9" },
		{ NotePitch::G9, "G9" }
	};

	static std::map<MIDIChannel, std::string> MIDIChannelMap =
	{
		{ MIDIChannel::CHANNEL_1, "1" },
		{ MIDIChannel::CHANNEL_2, "2" },
		{ MIDIChannel::CHANNEL_3, "3" },
		{ MIDIChannel::CHANNEL_4, "4" },
		{ MIDIChannel::CHANNEL_5, "5" },
		{ MIDIChannel::CHANNEL_6, "6" },
		{ MIDIChannel::CHANNEL_7, "7" },
		{ MIDIChannel::CHANNEL_8, "8" },
		{ MIDIChannel::CHANNEL_9, "9" },
		{ MIDIChannel::CHANNEL_10, "Percussion" },
		{ MIDIChannel::CHANNEL_11, "11" },
		{ MIDIChannel::CHANNEL_12, "12" },
		{ MIDIChannel::CHANNEL_13, "13" },
		{ MIDIChannel::CHANNEL_14, "14" },
		{ MIDIChannel::CHANNEL_15, "15" },
		{ MIDIChannel::CHANNEL_16, "16" }
	};

	static std::map<GMPercussion, std::string> GMPercussionMap = 
	{
		{ GMPercussion::ACOUSTIC_BASS_DRUM, "Acoustic Bass Drum" },
		{ GMPercussion::BASS_DRUM_1, "Bass Drum 1" },
		{ GMPercussion::SIDE_STICK, "Side Stick" },
		{ GMPercussion::ACOUSTIC_SNARE, "Acoustic Snare" },
		{ GMPercussion::HAND_CLAP, "Hand Clap" },
		{ GMPercussion::ELECTRIC_SNARE, "Electric Snare" },
		{ GMPercussion::LOW_FLOOR_TOM, "Low Floor Tom" },
		{ GMPercussion::CLOSED_HIHAT, "Closed Hi-Hat" },
		{ GMPercussion::HIGH_FLOOR_TOM, "High Floor Tom" },
		{ GMPercussion::PEDAL_HIHAT, "Pedal Hi-Hat" },
		{ GMPercussion::LOW_TOM, "Low Tom" },
		{ GMPercussion::OPEN_HIHAT, "Open Hi-Hat" },
		{ GMPercussion::LOW_MID_TOM, "Low Mid Tom" },
		{ GMPercussion::HI_MID_TOM, "Hi Mid Tom" },
		{ GMPercussion::CRASH_CYMBAL_1, "Crash Cymbal 1" },
		{ GMPercussion::HIGH_TOM, "High Tom" },
		{ GMPercussion::RIDE_CYMBAL_1, "Ride Cymbal 1" },
		{ GMPercussion::CHINESE_CYMBAL, "Chinese Cymbal" },
		{ GMPercussion::RIDE_BELL, "Ride Bell" },
		{ GMPercussion::TAMBUORINE, "Tambuorine" },
		{ GMPercussion::SPLASH_CYMBAL, "Splash Cymbal" },
		{ GMPercussion::COWBELL, "Cowbell" },
		{ GMPercussion::CRASH_CYMBAL_2, "Crash Cymbal 2" },
		{ GMPercussion::VIBRASLAP, "Vibraslap" },
		{ GMPercussion::RIDE_CYMBAL_2, "Ride Cymbal 2" },
		{ GMPercussion::HI_BONGO, "Hi Bongo" },
		{ GMPercussion::LOW_BONGO, "Low Bongo" },
		{ GMPercussion::MUTE_HI_CONGA, "Mute Hi Conga" },
		{ GMPercussion::OPEN_HI_CONGA, "Open Hi Conga" },
		{ GMPercussion::LOW_CONGA, "Low Conga" },
		{ GMPercussion::HIGH_TIMABLE, "High Timable" },
		{ GMPercussion::LOW_TIMABLE, "Low Timable" },
		{ GMPercussion::HIGH_AGOGO, "High Agogo" },
		{ GMPercussion::LOW_AGOGO, "Low Agogo" },
		{ GMPercussion::CABASA, "Cabasa" },
		{ GMPercussion::MARACAS, "Maracas" },
		{ GMPercussion::SHORT_WHISTLE, "Short Whistle" },
		{ GMPercussion::LONG_WHISTLE, "Long Whistle" },
		{ GMPercussion::SHORT_GUIRO, "Short Guiro" },
		{ GMPercussion::LONG_GUIRO, "Long Guiro" },
		{ GMPercussion::CLAVES, "Claves" },
		{ GMPercussion::HI_WOOD_BLOCK, "Hi Wood Block" },
		{ GMPercussion::LOW_WOOD_BLOCK, "Low Wood Block" },
		{ GMPercussion::MUTE_CUICA, "Mute Cuica" },
		{ GMPercussion::OPEN_CUICA, "Open Cuica" },
		{ GMPercussion::MUTE_TRIANGLE, "Mute Triangle" },
		{ GMPercussion::OPEN_TRIANGLE, "Open Triangle" }
	};
}
