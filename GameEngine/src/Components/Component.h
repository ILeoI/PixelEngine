#pragma once

namespace Wasabi {

	class Entity;

	class Component
	{
	public:
		Component(Wasabi::Entity& entity);
		virtual ~Component();

		virtual void Start();
		virtual void Update(float dt);
		virtual void CleanUp();

		Wasabi::Entity& GetOwner() const { return Owner; }
	private:
		Wasabi::Entity& Owner;
	};
}
