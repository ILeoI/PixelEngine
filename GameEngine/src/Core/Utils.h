#pragma once

#include <glm/glm.hpp>

#include <string>
#include <iostream>

namespace Wasabi 
{
	namespace Utils 
	{
		enum Direction
		{
			DIR_NONE = 0,
			DIR_UP = 1,
			DIR_DOWN = -1,
			DIR_LEFT = 2,
			DIR_RIGHT = -2,
			DIR_UP_LEFT = 3,
			DIR_UP_RIGHT = -3,
			DIR_DOWN_LEFT = 4,
			DIR_DOWN_RIGHT = -4
		};

		bool IsEqual(const glm::ivec2& first, const glm::ivec2& second);
		bool IsNotEqual(const glm::ivec2& first, const glm::ivec2& second);
		bool IsLessThan(const glm::ivec2& first, const glm::ivec2& second);
		bool IsLessThanOrEqual(const glm::ivec2& first, const glm::ivec2& second);
		bool IsGreaterThan(const glm::ivec2& first, const glm::ivec2& second);
		bool IsGreaterThanOrEqual(const glm::ivec2& first, const glm::ivec2& second);

		uint32_t* GetPixelDataFromImage(const std::string& path, int& width, int& height, int& channels);
		void FreeImageData(uint32_t* data);
		void FlipImage(bool flip);

		glm::ivec2 Move(glm::ivec2 start, Utils::Direction direction, int units);
		
		//void Move(glm::ivec2& start, Utils::Direction direction, int units);
		
		glm::ivec2 MoveTowards(const glm::ivec2& start, const glm::ivec2& end, float speed);
	}
}