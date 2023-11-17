#pragma once

#include <string>
#include <unordered_map>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>

#include "Utils.h"

namespace Wasabi {

	struct Sprite;

	class Spritesheet
	{
	public:
		Spritesheet(const std::string& path, int tileWidth, int tileHeight);
		~Spritesheet();

		glm::ivec2 GetTileSize() const { return tileSize; }
		glm::ivec2 GetSheetSize() const { return sheetSize; }

		uint32_t* GetPixels() const { return pixelData; };

		Sprite GetSprite(int spriteIndex) const;

	private:
		glm::ivec2 sheetSize;
		glm::ivec2 tileSize;
		glm::ivec2 numberOfSprites;

		int channels;
		uint32_t* pixelData;

		int count = 0;
	};	
}