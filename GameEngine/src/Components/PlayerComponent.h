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

	private:
		void HandleInput(Utils::Direction dir);

		void UpdateSprite();
		void SetSprite(Sprite sprite);
	
	private:
		bool isMoving = false;
		bool sprinting = false;

		const double movementDelayAfterRotating = 0.08f;
		
		double lastTime = 0.0f;
		double currentTime = 0.0f;

		Utils::Direction direction = Utils::DIR_UP;
		Utils::Direction prevDirection = Utils::DIR_DOWN;
		
		glm::ivec2 movementFinishPosition{};
		
		std::shared_ptr<SpriteComponent> spriteComponent;
	};
}
