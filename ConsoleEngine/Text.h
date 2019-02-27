#pragma once

namespace ce
{
	namespace Text
	{
		enum class Color
		{
			Black = 0x0000,
			Blue = 0x0001,
			Green = 0x0002,
			Azure = 0x0003,
			Red = 0x0004,
			Violet = 0x0005,
			Orange = 0x0006,
			LightGrey = 0x0007,
			Grey = 0x0008,
			LightBlue = 0x0009,
			LightGreen = 0x000A,
			Cyan = 0x000B,
			LightRed = 0x000C,
			Magenta = 0x000D,
			Yellow = 0x000E,
			White = 0x000F
		};

		enum class Type
		{
			None = 0x0,
			FullBlock = 0x2588,
			LightShade = 0x2591,
			MediumShade = 0x2592,
			DarkShade = 0x2593
		};
	}
}