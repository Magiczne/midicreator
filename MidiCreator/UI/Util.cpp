#include "Util.h"

using namespace UI;

ConsoleSize Util::getConsoleSize()
{
	ConsoleSize size;

	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	size.cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	size.rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	return size;
}

void Util::setConsoleSize(int width, int height)
{
	COORD coord;
	coord.X = height;
	coord.Y = width;

	SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = height - 1;
	rect.Right = width - 1;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(handle, coord);
	SetConsoleWindowInfo(handle, true, &rect);
}

void Util::setColor(Color background, Color text)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	uint8_t val = ((uint8_t)background << 4) + (uint8_t)text;

	SetConsoleTextAttribute(hConsole, val);
}

void Util::writeCentered(string msg)
{
	ConsoleSize size = Util::getConsoleSize();

	int width = (size.cols + msg.size()) / 2;
	cout << setw(width) << msg << endl;
}