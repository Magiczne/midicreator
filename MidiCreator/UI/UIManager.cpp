﻿#include "UIManager.h"

#include "../Sequence.h"
#include "Util/Maps.h"

using namespace std;
using namespace SMF;
using namespace UI;

//Forward declarations
int Util::writtenLines;

UIManager::UIManager(Sequence& seq) : seq(seq) {}

void UIManager::drawMenu() const
{
	Util::clearConsole();
	Util::newLine(2);
	Util::setColor(Color::DarkGreen);
	Util::writeCentered("MIDI Creator v0.0.41");
	Util::newLine();

	Util::setColor(Color::Gray);
	Util::writeCentered("1. Start a new sequence");
	Util::writeCentered("2. Load a sequence");
	Util::writeCentered("3. Quit");
}

Nullable<COORD> UIManager::drawSequenceScreen()
{
	Nullable<COORD> ret;

	ConsoleSize size = Util::getConsoleSize();

	this->pianoRollWidth = size.cols - 20;

	Util::clearConsole();

	//this->sequence title + this->sequence Type
	Util::setColor(Color::DarkGreen);
	Util::writeMulti(
		this->seq.name(), this->seq.getFormatString(), 
		Util::createColor(Color::DarkCyan)
	);
	
	//Measure
	Util::setColor(Color::DarkCyan);
	Util::writeMulti(
		"Mode: " + ModeMap[this->_mode],
		"Measure: " + to_string(this->seq.numerator()) + "/" + to_string(this->seq.denominator())
	);
	Util::newLine(2);

	//Bars numbers
	Util::setColor(Color::Red);
	cout << "    ";
	for (unsigned i = 0 + this->seq.firstBarToShow;
		i < this->pianoRollWidth / this->seq.numerator() + this->seq.firstBarToShow;
		i++)
	{
		cout << i;

		for (int j = 0;
			j < this->seq.numerator() - Util::getNumberOfDigits(i);
			j++)
		{
			cout << ' ';
		}
	}
	Util::newLine();

	cout << "    ";
	Util::makeLine(this->pianoRollWidth,
		Util::createColor(Color::DarkRed));

	for (unsigned k = 0; k < this->pianoRollHeight; k++)
	{
		Util::setColor(Color::Red);
		NotePitch p = NotePitch(static_cast<uint8_t>(this->seq.firstNoteToShow) + k);
		string text = SMF::NotePitchMap[p];
		cout << text;

		for (size_t i = 0; i < 4 - text.size(); i++)
		{
			cout << ' ';
		}

		for (unsigned i = 0;
			i < this->pianoRollWidth / this->seq.numerator() * this->seq.numerator(); i++)
		{
			Color c = Color::Black;

			//Selected note indicator
			if(this->_mode == Mode::EDIT)
			{
				if (i == this->seq.currentBar && k == this->seq.currentNote)
				{
					c = Color::DarkRed;
				}
			}

			if (i % this->seq.numerator() == 0)
			{
				Util::setColor(Color::DarkGreen, c);
			}
			else
			{
				Util::setColor(Color::DarkGray, c);
			}

			cout << '*';
		}
		Util::newLine();
	}
	Util::newLine();


	switch (this->_action)
	{
	case Action::CHANGE_SEQ_NAME:
		ret = COORD{ 0, this->drawParamEditor(size, "Enter sequence name:") };
		break;

	case Action::CHANGE_MEASURE:
		ret = COORD
		{
			0, this->drawParamEditor(size, "Choose measure: ",{
				"1. 2/4",
				"2. 3/4",
				"3. 4/4",
				"4. 6/8"
			})
		};
		break;

	default:
		break;
	}

	if (this->_mode == Mode::VIEW)
	{
		this->drawViewMenu(size);
	}
	else
	{
		this->drawEditMenu(size);
	}

	return ret;
}

void UIManager::drawViewMenu(ConsoleSize& size) const
{
	Util::newLine(size.rows - Util::writtenLines - 2);

	vector<string> cmds = { 
		"UP", "DN", "LT", "RT", 
		" N", " S", " M" };
	vector<string> names = { 
		"Roll up", "Roll down", "Roll left", "Roll right", 
		"Edit mode", "Seq name", "Set measure" };

	for (size_t i = 0; i < names.size(); i++)
	{
		Util::setColor(Color::Black, Color::Gray);
		cout << cmds[i];
		Util::setColor(Color::DarkGray);
		cout << ' ' << names[i];
	
		//TODO: Fix for consoleSize
		if ((i + 1) % 8 == 0)
		{
			cout << endl;
		}
		else
		{
			cout << '\t';
		}
	}
}

void UIManager::drawEditMenu(ConsoleSize& size) const
{
	Util::newLine(size.rows - Util::writtenLines - 2);

	vector<string> cmds = { 
		"UP", "DN", "LT", "RT", 
		" N", 
		" W", " S", " A", " D" };
	vector<string> names = { 
		"Roll up", "Roll down", "Roll left", "Roll right", 
		"View mode",
		"Note up", "Note down", "Note left", "Note right" };

	for (size_t i = 0; i < names.size(); i++)
	{
		Util::setColor(Color::Black, Color::Gray);
		cout << cmds[i];
		Util::setColor(Color::DarkGray);
		cout << ' ' << names[i];

		//TODO: Fix for consoleSize
		if((i+1) % 8 == 0)
		{
			cout << endl;
		}
		else
		{
			cout << '\t';
		}
	}
}

SHORT UIManager::drawParamEditor(ConsoleSize& size, string msg, vector<string> additional) const
{
	SHORT tmp = Util::writtenLines;

	Util::setColor(Color::DarkRed, Color::Gray);
	Util::makeLine(size.cols);

	Util::setColor(Color::Red);
	Util::writeLeft(msg);

	for (auto& m : additional)
	{
		Util::writeLeft(m);
	}

	Util::newLine();	//Here will be cursor

	Util::setColor(Color::DarkRed, Color::Gray);
	Util::makeLine(size.cols);

	return tmp + 2 + static_cast<SHORT>(additional.size());
}
