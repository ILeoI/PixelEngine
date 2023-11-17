#include "BackgroundComponent.h"

#include "../Core/Entity.h"

namespace Wasabi {

	BackgroundComponent::BackgroundComponent(Wasabi::Entity& entity, const std::string& path, Texture* texture)
		: texture(texture), Component(entity)
	{
		pixelData = Utils::GetPixelDataFromImage(path, size.x, size.y, channels);
		if (pixelData)
			loaded = true;
	}

	void BackgroundComponent::Start()
	{

	}

	void BackgroundComponent::Update(float dt)
	{
		DrawBackground();
	}

	void BackgroundComponent::CleanUp()
	{

	}

	void BackgroundComponent::Load(const std::string& path, Texture* texture)
	{
		if (loaded)
			return;
		this->texture = texture;
		pixelData = Utils::GetPixelDataFromImage(path, size.x, size.y, channels);
		loaded = true;
	}

	void BackgroundComponent::DrawBackground()
	{
		if (!loaded)
			return;

		auto texturePictureData = texture->GetPixelData();
		auto textureSize = texture->GetSize();

		auto& position = GetOwner().transform.Position;

		for (int y = 0; y < size.y; y++)
		{
			for (int x = 0; x < size.x; x++)
			{
				int xp = x + position.x,
					yp = y + position.y;

				if (yp > textureSize.y || xp > textureSize.x || yp < 0 || xp < 0)
					continue;

				texturePictureData[xp + yp * size.x] = pixelData[x + y * size.x];
			}
		}
	}
}