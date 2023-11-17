#pragma once


#include <iostream>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Wasabi.h"

namespace Wasabi {

	class Engine
	{
	public:
		Engine(int width, int height, const std::string& name);
		void Run();

	private:
		void CreateWindow();
		void SetUpRenderQuad();
		void CleanUp();
		void PollAndDraw();

		float GetDeltaTime();

		int width, height;
		std::string name;

		GLFWwindow* window;

		unsigned int VBO, VAO, EBO;

		float lastTime;
		float deltaTime;

	};

}

