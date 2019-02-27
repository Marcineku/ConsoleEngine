#pragma once

#include "Vector2Int.h"
#include "Key.h"

namespace ce
{
	struct Event
	{
		enum class Type
		{
			Key, Mouse, Resize
		};

		Event();

		Type type;
		union
		{
			std::pair<ce::Key, bool> key;
			Vector2Int mousePosition;
			Vector2Int windowSize;
		};
	};
}