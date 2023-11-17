#include "Scene.h"

#include <iostream>

#include "Entity.h"
#include "../Components/Component.h"
#include "Time.h"

namespace Wasabi {

	Scene::Scene(int id)
		: m_SceneID(id)
	{

	}

	Scene::~Scene()
	{

	}

	void Scene::Start()
	{
		if (m_BackgroundEntity)
			m_BackgroundEntity->Start();

		for (auto& entity : m_Entities)
		{
			entity->Start();
		}
	}

	void Scene::Update(float dt)
	{
		if (m_BackgroundEntity)
			m_BackgroundEntity->Update(dt);

		for (auto& entity : m_Entities)
		{
			entity->Update(dt);
		}
	}

	void Scene::SetBackgroundEntity(Entity& entity)
	{
		m_BackgroundEntity = std::make_shared<Entity>(entity);
	}


	Entity& Scene::AddEntity(Transform transform)
	{
		m_Entities.emplace_back(std::make_shared<Entity>(transform));
		return *m_Entities.back();
	}

	Entity& Scene::AddEntity()
	{
		m_Entities.emplace_back(std::make_shared<Entity>());
		return *m_Entities.back();
	}
}