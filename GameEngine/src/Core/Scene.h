#pragma once

#include <vector>
#include <memory>

#include <glm/glm.hpp>

namespace Wasabi {

	class Entity;
	class Component;
	struct Transform;

	class Scene
	{
	public:
		Scene(int id);
		~Scene();

		void Start();
		void Update(float dt);

		Wasabi::Entity& AddEntity(Transform transform);
		Wasabi::Entity& AddEntity();
		void SetBackgroundEntity(Wasabi::Entity& entity);

	private:
		int m_SceneID;
		std::shared_ptr<Wasabi::Entity> m_BackgroundEntity;
		std::vector<std::shared_ptr<Wasabi::Entity>> m_Entities{};
	};
}
