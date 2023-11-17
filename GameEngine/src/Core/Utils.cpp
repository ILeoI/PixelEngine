#include "Utils.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace Wasabi 
{
    namespace Utils
    {
        bool IsEqual(const glm::ivec2& first, const glm::ivec2& second) 
        {
            return first.x == second.x && first.y == second.y;
        }

        bool IsNotEqual(const glm::ivec2& first, const glm::ivec2& second) 
        {
            return first.x != second.x || first.y != second.y;
        }

        bool IsLessThan(const glm::ivec2& first, const glm::ivec2& second) 
        {
            return first.x < second.x && first.y < second.y;
        }

        bool IsLessThanOrEqual(const glm::ivec2& first, const glm::ivec2& second) 
        {
            return first.x <= second.x && first.y <= second.y;
        }

        bool IsGreaterThan(const glm::ivec2& first, const glm::ivec2& second) 
        {
            return first.x > second.x && first.y > second.y;
        }

        bool IsGreaterThanOrEqual(const glm::ivec2& first, const glm::ivec2& second) 
        {
            return first.x >= second.x && first.y >= second.y;
        }

        void FlipImage(bool flip)
        {
            stbi_set_flip_vertically_on_load(flip);
        }

        uint32_t* GetPixelDataFromImage(const std::string& path, int& width, int& height, int& channels)
        {
            std::string resourcePath = "C:\\Users\\leojw\\source\\repos\\GameEngine\\GameEngine\\resources\\" + path;
            uint32_t* pixelData = (uint32_t*)stbi_load(resourcePath.c_str(), &width, &height, &channels, 0);
            if (pixelData)
            {
                return pixelData;
            }
            else 
            {
                std::cout << "Failed to load image: " << resourcePath << std::endl;
                return nullptr;
            }
        }

        void FreeImageData(uint32_t* data)
        {
            stbi_image_free(data);
        }

        glm::ivec2 Move(glm::ivec2 start, Utils::Direction direction, int units)
        {
            switch (direction)
            {
                case Utils::DIR_UP:
                {
                    start.y += units;
                    break;
                }
                case Utils::DIR_DOWN:
                {
                    start.y += -units;
                    break;
                }
                case Utils::DIR_LEFT:
                {
                    start.x += -units;
                    break;
                }
                case Utils::DIR_RIGHT:
                {
                    start.x += units;
                    break;
                }
                case Utils::DIR_UP_LEFT:
                {
                    start += glm::ivec2{ -units, units };
                    break;
                }
                case Utils::DIR_UP_RIGHT:
                {
                    start += glm::ivec2{ units, units };
                    break;
                }
                case Utils::DIR_DOWN_LEFT:
                {
                    start += glm::ivec2{ -units, -units };
                    break;
                }
                case Utils::DIR_DOWN_RIGHT:
                {
                    start += glm::ivec2{ units, -units };
                    break;
                }
            }

            return start;
        }

        glm::ivec2 MoveTowards(const glm::ivec2& currentPos, const glm::ivec2& targetPos, float speed) 
        {
            glm::ivec2 direction = targetPos - currentPos;

            float distance = glm::length(glm::vec2(direction));

            if (distance > 0) 
            {
                glm::vec2 normalizedDirection = glm::normalize(glm::vec2(direction));
                glm::vec2 newPosition = glm::vec2(currentPos) + normalizedDirection * speed;

                return glm::round(newPosition);
            }

            return currentPos;
        }
    }
}