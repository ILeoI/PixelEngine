#include "Texture.h"

namespace Wasabi {

	Texture::Texture(const std::string& path)
	{
		pixelData = Utils::GetPixelDataFromImage(path, size.x, size.y, channels);
		pixelDataSize = size.x * size.y;

		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (pixelData)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, size.x, size.y, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelData);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture: " << path << std::endl;
		}
	}

	Texture::Texture(int width, int height, int channels)
		: channels(channels)
	{
		size = { width, height };
		pixelDataSize = size.x * size.y;

		glGenTextures(1, &textureID);

		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		pixelData = new uint32_t[width * height];

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size.x, size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixelData);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	Texture::~Texture()
	{
		Utils::FreeImageData(pixelData);
	}

	void Texture::SetPixels()
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size.x, size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixelData);
	}

	void Texture::SetColour(uint32_t colour)
	{
		for (uint32_t i = 0; i < pixelDataSize; i++)
		{
			pixelData[i] = colour;
		}
	}

	void Texture::Clear()
	{
		for (uint32_t i = 0; i < pixelDataSize; i++)
		{
			pixelData[i] = 0xFF000000;
		}
	}
}