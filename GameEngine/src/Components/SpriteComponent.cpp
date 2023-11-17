#include "SpriteComponent.h"

#include "../Core/Entity.h"

namespace Wasabi {

	SpriteComponent::SpriteComponent(Entity& owner, Sprite sprite, Spritesheet* spriteSheet, PixelRenderer* pixelRenderer)
		: spriteSheet(spriteSheet), pixelRenderer(pixelRenderer), Component(owner)
	{
		spriteCoords = sprite;
	}
	SpriteComponent::SpriteComponent(Entity& owner, int spriteIndex, Spritesheet* spriteSheet, PixelRenderer* pixelRenderer)
		: spriteSheet(spriteSheet), pixelRenderer(pixelRenderer), Component(owner)
	{
		spriteCoords = spriteSheet->GetSprite(spriteIndex);
	}


	void SpriteComponent::Start()
	{

	}

	void SpriteComponent::Update(float dt)
	{
		Draw();
	}

	void SpriteComponent::Draw()
	{
		pixelRenderer->DrawSprite(spriteSheet, spriteCoords, GetOwner().transform.Position);
	}

	void SpriteComponent::SetSprite(Sprite sprite)
	{
		spriteCoords = sprite;
	}
}