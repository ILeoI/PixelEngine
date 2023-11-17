#pragma once

namespace Wasabi {

	struct Sprite
	{
		// Index of the sprite
		int X = -1, Y = -1;

		Sprite(int x, int y)
			: X(x), Y(y) {};
	};

	namespace Sprites
	{
		static Sprite One{ 0,0 };
		static Sprite Two{ 1,0 };
		static Sprite Three{ 0,1 };
		static Sprite Four{ 1,1 };
	}
}
