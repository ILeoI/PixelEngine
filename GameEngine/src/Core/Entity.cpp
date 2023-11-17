#include "Entity.h"

#include "../Components/Component.h"

namespace Wasabi {

	Entity::Entity(glm::ivec2 pos, int rotation)
	{
		transform.Position = pos;
		transform.Rotation = rotation;
	}

	Entity::Entity(Transform transform)
	{
		transform = transform;
	}

	Entity::~Entity()
	{
		CleanUp();
	}

	void Entity::Start()
	{
		for (const auto& component : m_Components)
		{
			if (component != nullptr)
			{
				component->Start();
			}
		}
	}

	void Entity::Update(float dt)
	{
		for (const auto& component : m_Components)
		{
			if (component != nullptr && component)
			{
				component->Update(dt);
			}
		}
	}

	void Entity::SetPosition(glm::ivec2 pos)
	{
		transform.Position = pos;
	}

	void Entity::CleanUp()
	{
		for (const auto& component : m_Components)
		{
			if (component != nullptr)
			{
				component->CleanUp();
			}
		}
	}

	std::shared_ptr<Component>& Entity::AddComponent(Component* component)
	{
		m_Components.emplace_back(component);
		return m_Components.back();
	}
}