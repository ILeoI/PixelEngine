#include "Component.h"

#include "../Core/Entity.h"

namespace Wasabi {

	Component::Component(Wasabi::Entity& entity)
		: Owner(entity)
	{

	}

	Component::~Component()
	{

	}

	void Component::Start()
	{

	}

	void Component::Update(float dt)
	{

	}

	void Component::CleanUp()
	{

	}
}