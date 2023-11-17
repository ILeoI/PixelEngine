#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>

#include "Utils.h"

namespace Wasabi {

	class Texture
	{
	public:
		Texture(const std::string& path);
		Texture(int width, int height, int channels = 4);

		~Texture();

		const glm::ivec2 GetSize() const { return size; }
		const unsigned int GetTextureID() const { return textureID; }

		void SetPixels();
		void Clear();
		void SetColour(uint32_t colour);
		uint32_t* GetPixelData() { return pixelData; }

	private:
		unsigned int textureID = -1;

		glm::ivec2 size;
		int channels;
		uint32_t* pixelData;
		uint32_t pixelDataSize;
	};

}