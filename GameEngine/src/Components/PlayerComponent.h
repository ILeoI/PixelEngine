#pragma once

#include "glm/glm.hpp"

#include "../Core/Utils.h"
#include "../Core/Sprite.h"

#include "SpriteComponent.h"
#include "Component.h"

namespace Wasabi {

	class PlayerComponent : public Component
	{
	public:
		PlayerComponent() = delete;
		PlayerComponent(Wasabi::Entity& entity);

		virtual void Start();
		virtual void Update(float dt);
		virtual void CleanUp();

		void SetSprite(Sprite sprite);

	private:
		bool isMoving = false;
		Utils::Direction direction = Utils::DIR_UP;
		glm::ivec2 movementFinishPosition{};
		std::shared_ptr<SpriteComponent> spriteComponent;
	};
}
