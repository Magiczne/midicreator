#pragma once

#include "../stdafx.h"

using namespace std;

namespace UI
{
	struct ConsoleSize
	{
		int cols;
		int rows;
	};

	enum class Color : uint8_t
	{
		Black			= 0,
		DarkBlue		= 1,
		DarkGreen		= 2,
		DarkCyan		= 3,
		DarkRed	 		= 4,
		DarkMagenta		= 5,
		DarkYellow		= 6,
		Gray			= 7,
		DarkGray		= 8,
		Blue			= 9,
		Green			= 10,
		Cyan			= 11,
		Red				= 12,
		Magenta			= 13,
		Yellow			= 14,
		White			= 15
	};
	
	static class Util
	{
	public:
		static ConsoleSize getConsoleSize();
		static void setConsoleSize(int width, int height);
		static void setColor(Color background, Color text);

		static void writeCentered(string msg);
	};
}
