#include "PixelRenderer.h"

namespace Wasabi {

	PixelRenderer::PixelRenderer(Texture* renderTexture)
		: texture(renderTexture)
	{
		size = texture->GetSize();
	}

	PixelRenderer::~PixelRenderer()
	{

	}

	void PixelRenderer::DrawSprite(Spritesheet* sheet, Sprite sprite, int xPos, int yPos)
	{
		auto spriteSheetPixels = sheet->GetPixels();
		auto spriteSheetTileSize = sheet->GetTileSize();
		auto spriteSheetSize = sheet->GetSheetSize();

		auto pixelData = texture->GetPixelData();
		auto texSize = texture->GetSize();

		int spritePosX = sprite.X * spriteSheetTileSize.x,
			spritePosY = sprite.Y * spriteSheetTileSize.y;

		for (int y = 0; y < spriteSheetTileSize.y; y++)
		{
			for (int x = 0; x < spriteSheetTileSize.x; x++)
			{
				if (y + yPos > texSize.y || x + xPos > texSize.x || x + xPos < 0 || y + yPos < 0)
					continue;

				uint32_t colour = spriteSheetPixels[(spritePosX + x) + (spritePosY + y) * spriteSheetSize.x];
				
				if (colour == 0xFFFF00FF)
					continue;

				pixelData[(xPos + x) + (yPos + y) * size.x] = colour;
			}
		}
	}

	void PixelRenderer::DrawSprite(Spritesheet* sheet, int spriteIndex, int xPos, int yPos)
	{
		Sprite sprite = sheet->GetSprite(spriteIndex);
		DrawSprite(sheet, sprite, xPos, yPos);
	}

	void PixelRenderer::DrawSprite(Spritesheet* sheet, Sprite sprite, glm::ivec2 position)
	{
		DrawSprite(sheet, sprite, position.x, position.y);
	}

	void PixelRenderer::DrawSprite(Spritesheet* sheet, int spriteIndex, glm::ivec2 position)
	{
		DrawSprite(sheet, spriteIndex, position.x, position.y);
	}
}