#pragma once

#include <iostream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "Utils.h"
#include "Sprite.h"
#include "Texture.h"
#include "Spritesheet.h"

namespace Wasabi {

	class PixelRenderer
	{
	public:
		PixelRenderer(Texture* renderTexture);
		~PixelRenderer();

		void DrawSprite(Spritesheet* sheet, int spriteIndex, int xPos, int yPos);
		void DrawSprite(Spritesheet* sheet, Sprite sprite, int xPos, int yPos);

		void DrawSprite(Spritesheet* sheet, int spriteIndex, glm::ivec2 position);
		void DrawSprite(Spritesheet* sheet, Sprite sprite, glm::ivec2 position);

	private:
		glm::ivec2 size;
		Texture* texture;
	};
}