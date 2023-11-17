#pragma once

#include <glm/glm.hpp>

#include "../Core/Texture.h"
#include "../Core/Utils.h"

#include "Component.h"

namespace Wasabi {

	class BackgroundComponent : public Component
	{
	public:
		BackgroundComponent() = delete;
		BackgroundComponent(Wasabi::Entity& entity, const std::string& path, Texture* texture);

		virtual void Start();
		virtual void Update(float dt);
		virtual void CleanUp();

		void Load(const std::string& path, Texture* texture);
	private:
		void DrawBackground();
	
		uint32_t* pixelData;
		Texture* texture;
	
		glm::ivec2 size;
		int channels;
		bool loaded = false;
	};
}