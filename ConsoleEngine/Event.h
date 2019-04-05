#pragma once

#include "Vector2Int.h"
#include "Key.h"

namespace ce
{
	struct Event
	{
		enum class Type { KeyStateChange, MouseMove, WindowResize };

		struct KeyState
		{
			ce::Key key;
			bool isDown;

			KeyState();
		};

		Event();

		Type type;
		union
		{
			KeyState keyState;
			Vector2Int mousePosition;
			Vector2Int windowSize;
		};
	};
}