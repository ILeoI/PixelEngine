#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Wasabi {

	class Shader
	{
	private:
		unsigned int shaderID;

	public:
		Shader(const std::string& vertexPath, const std::string& fragmentPath);
		~Shader();
		void Use();

		void SetBool(const std::string& name, bool value);
		void SetInt(const std::string& name, int value);
		void SetFloat(const std::string& name, float value);
		void SetVec3(const std::string& name, glm::vec3 value);
		void SetVec4(const std::string& name, glm::vec4 value);

		const int GetShaderID() const { return shaderID; }
	};
}
