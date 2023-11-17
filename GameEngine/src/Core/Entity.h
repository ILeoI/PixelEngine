#pragma once

#include <vector>
#include <memory>

#include <glm/glm.hpp>

#include "Utils.h"

namespace Wasabi {

	class Component;

	struct Transform
	{
		glm::ivec2 Position = { 0, 0 };
		int Rotation = 0;
	};

	class Entity
	{
	public:
		Entity() = default;
		Entity(glm::ivec2 pos, int rotation);
		Entity(Transform transform);
		~Entity();

		void Start();
		void Update(float dt);

		void SetPosition(glm::ivec2 pos);

		std::shared_ptr<Component>& AddComponent(Component* component);

		template <typename T>
		std::shared_ptr<T> GetComponent() const {
			for (const auto& component : m_Components) {
				if (auto castedComponent = std::dynamic_pointer_cast<T>(component)) {
					return castedComponent;
				}
			}
			return nullptr;
		}

		Transform transform{};

	private:
		void CleanUp();

		std::vector<std::shared_ptr<Component>> m_Components;
	};
}

