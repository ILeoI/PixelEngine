#include "Spritesheet.h"

#include "Sprite.h"

namespace Wasabi {

	Spritesheet::Spritesheet(const std::string& path, int tileWidth, int tileHeight)
		: tileSize({tileWidth, tileHeight})
	{
		pixelData = Utils::GetPixelDataFromImage(path.c_str(), sheetSize.x, sheetSize.y, channels);
		if (!pixelData)
		{
			std::cout << "Failed to load spritesheet: " << path << std::endl;
		}

		numberOfSprites = { sheetSize.x / tileWidth, sheetSize.y / tileHeight };
	}

	Sprite Spritesheet::GetSprite(int spriteIndex) const
	{
		return { spriteIndex % numberOfSprites.x, spriteIndex / numberOfSprites.y };
	}

	Spritesheet::~Spritesheet()
	{
		delete[] pixelData;
	}
}