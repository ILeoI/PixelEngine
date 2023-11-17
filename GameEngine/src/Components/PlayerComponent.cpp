#include "PlayerComponent.h"

#include <thread>
#include <chrono>

#include "../Core/InputHandler.h"
#include "../Core/Entity.h"

namespace Wasabi {

	PlayerComponent::PlayerComponent(Wasabi::Entity& entity)
		: Component(entity)
	{

	}

	void PlayerComponent::Start()
	{
		auto component = GetOwner().GetComponent<SpriteComponent>();
		if (component)
		{
			spriteComponent = component;
		}

	}

	void PlayerComponent::Update(float dt)
	{
		spriteComponent->SetSprite({ 1, 1 });

		if (isMoving)
		{
			if (movementFinishPosition == GetOwner().transform.Position)
			{
				isMoving = false;
			}
			else
			{
				auto result = Utils::MoveTowards(GetOwner().transform.Position, movementFinishPosition, 200.0f * dt);
				GetOwner().transform.Position = result;
			}
		}
		else
		{
			if (InputHandler::IsKeyPressed(GLFW_KEY_W))
			{
				if (direction != Utils::DIR_UP)
				{
					direction = Utils::DIR_UP;
					return;
				}
				movementFinishPosition = Utils::Move(GetOwner().transform.Position, direction, 16);
				isMoving = true;
			}
			if (InputHandler::IsKeyPressed(GLFW_KEY_S))
			{
				if (direction != Utils::DIR_DOWN)
				{
					direction = Utils::DIR_DOWN;
					return;
				}
				movementFinishPosition = Utils::Move(GetOwner().transform.Position, direction, 16);
				isMoving = true;
			}
			if (InputHandler::IsKeyPressed(GLFW_KEY_A))
			{
				if (direction != Utils::DIR_LEFT)
				{
					direction = Utils::DIR_LEFT;
					return;
				}
				movementFinishPosition = Utils::Move(GetOwner().transform.Position, direction, 16);
				isMoving = true;
			}
			if (InputHandler::IsKeyPressed(GLFW_KEY_D))
			{
				if (direction != Utils::DIR_RIGHT)
				{
					direction = Utils::DIR_RIGHT;
					return;
				}
				movementFinishPosition = Utils::Move(GetOwner().transform.Position, direction, 16);
				isMoving = true;
			}
		}
	}

	void PlayerComponent::CleanUp()
	{

	}

	void PlayerComponent::SetSprite(Sprite sprite)
	{

	}
}
