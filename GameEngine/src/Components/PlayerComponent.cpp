#include "PlayerComponent.h"

#include "../Core/InputHandler.h"
#include "../Core/Entity.h"

namespace Wasabi {

	static Sprite UP(0, 1);
	static Sprite DOWN(0, 0);
	static Sprite RIGHT(1, 0);
	static Sprite LEFT(1, 1);

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

		lastTime = glfwGetTime();

	}

	void PlayerComponent::Update(float dt)
	{
		UpdateSprite();

		float time = glfwGetTime();

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
			currentTime = glfwGetTime();
			if ((currentTime - lastTime) < movementDelayAfterRotating)
			{
				return;
			}

			if (InputHandler::IsKeyPressed(GLFW_KEY_W))
			{
				HandleInput(Utils::DIR_UP);
			}
			else if (InputHandler::IsKeyPressed(GLFW_KEY_S))
			{
				HandleInput(Utils::DIR_DOWN);
			}
			else if (InputHandler::IsKeyPressed(GLFW_KEY_A))
			{
				HandleInput(Utils::DIR_LEFT);
			}
			else if (InputHandler::IsKeyPressed(GLFW_KEY_D))
			{
				HandleInput(Utils::DIR_RIGHT);
			}
		}
	}

	void PlayerComponent::CleanUp()
	{

	}

	void PlayerComponent::HandleInput(Utils::Direction dir)
	{
		if (direction != dir)
		{
			lastTime = currentTime;
			direction = dir;
			return;
		}

		movementFinishPosition = Utils::Move(GetOwner().transform.Position, dir, 16);
		isMoving = true;
	}

	void PlayerComponent::UpdateSprite()
	{
		if (prevDirection == direction)
		{
			return;
		}

		if (direction == Utils::DIR_UP)
			SetSprite(UP);
		if (direction == Utils::DIR_DOWN)
			SetSprite(DOWN);
		if (direction == Utils::DIR_LEFT)
			SetSprite(LEFT);
		if (direction == Utils::DIR_RIGHT)
			SetSprite(RIGHT);

		prevDirection = direction;
	}

	void PlayerComponent::SetSprite(Sprite sprite)
	{
		spriteComponent->SetSprite(sprite);
	}
}
