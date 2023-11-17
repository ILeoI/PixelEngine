#pragma once

#include "Component.h"
#include "../Core/Texture.h"
#include "../Core/Spritesheet.h"
#include "../Core/PixelRenderer.h"
#include "../Core/Sprite.h"

namespace Wasabi {

	class Entity;

	class SpriteComponent : public Component
	{
	public:
		SpriteComponent() = delete;
		SpriteComponent(Entity& owner, Sprite sprite, Spritesheet* spriteSheet, PixelRenderer* pixelRenderer);
		SpriteComponent(Entity& owner, int spriteIndex, Spritesheet* spriteSheet, PixelRenderer* pixelRenderer);

		virtual void Start();
		virtual void Update(float dt);

		void SetSprite(Sprite spite);
		void Draw();

	private:
		Sprite spriteCoords = {0, 0};
		Spritesheet* spriteSheet;
		PixelRenderer* pixelRenderer;
	};
}
