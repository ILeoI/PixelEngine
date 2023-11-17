#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Wasabi {

	class InputHandler
	{
	public:
		static InputHandler& GetInstance()
		{
			static InputHandler handler;
			return handler;
		}

		static void SetCallbacks(GLFWwindow* windowPtr)
		{
			glfwSetKeyCallback(windowPtr, KeyCallback);
			glfwSetMouseButtonCallback(windowPtr, MouseButtonCallback);
		}

		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mod)
		{
			GetInstance().HandleKeyInput(key, action);
		}

		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mod)
		{
			GetInstance().HandleMouseButtonInput(button, action);
		}

		static bool IsKeyPressed(int key)
		{
			return GetInstance().keys[key];
		}

		static bool IsMouseButtonPressed(int button)
		{
			return GetInstance().mouseButtons[button];
		}

	private:

		InputHandler() = default;

		void HandleKeyInput(int key, int action)
		{
			if (action == GLFW_PRESS)
			{
				keys[key] = true;
			}
			else if (action == GLFW_RELEASE)
			{
				keys[key] = false;
			}
		}

		void HandleMouseButtonInput(int button, int action)
		{
			if (action == GLFW_PRESS)
			{
				mouseButtons[button] = true;
			}
			else if (action == GLFW_RELEASE)
			{
				mouseButtons[button] = false;
			}
		}

		bool keys[GLFW_KEY_LAST];
		bool mouseButtons[GLFW_MOUSE_BUTTON_LAST];
	};
}
