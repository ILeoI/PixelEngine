#include "Shader.h"

namespace Wasabi {

	Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
	{
		std::string resourcePath = "C:\\Users\\leojw\\source\\repos\\GameEngine\\GameEngine\\resources\\";
		std::string vertexCodeS, fragmentCodeS;
		std::ifstream vShaderFile, fShaderFile;

		vShaderFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
		fShaderFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
		try
		{
			vShaderFile.open(resourcePath + vertexPath);
			fShaderFile.open(resourcePath + fragmentPath);

			std::stringstream vShaderStream, fShaderStream;

			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();

			vShaderFile.close();
			fShaderFile.close();

			vertexCodeS = vShaderStream.str();
			fragmentCodeS = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "Failed to open: " << std::endl;
			std::cout << " - " << vertexPath << std::endl;
			std::cout << " - " << fragmentPath << std::endl;
		}

		const char* vertexCode = vertexCodeS.c_str();
		const char* fragmentCode = fragmentCodeS.c_str();

		unsigned int vertex, fragment;
		int success = 1;

		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertexCode, NULL);
		glCompileShader(vertex);

		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			char infoLog[512];
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			std::cout << "Vertex Shader: failed to compile\n" << infoLog << std::endl;
		}

		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragmentCode, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			char infoLog[512];
			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
			std::cout << "Fragment Shader: failed to compile\n" << infoLog << std::endl;
		}

		shaderID = glCreateProgram();
		glAttachShader(shaderID, vertex);
		glAttachShader(shaderID, fragment);

		glLinkProgram(shaderID);

		glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
		if (!success)
		{
			char infoLog[512];
			glGetProgramInfoLog(shaderID, 512, NULL, infoLog);
			std::cout << "Shader Linking: failed to link shaders\n" << infoLog << std::endl;
		}

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	Shader::~Shader()
	{
		glDeleteShader(shaderID);
	}

	void Shader::Use()
	{
		glUseProgram(shaderID);
	}

	void Shader::SetBool(const std::string& name, bool value)
	{
		glUniform1i(glGetUniformLocation(shaderID, name.c_str()), (int)value);
	}

	void Shader::SetInt(const std::string& name, int value)
	{
		glUniform1i(glGetUniformLocation(shaderID, name.c_str()), value);
	}

	void Shader::SetFloat(const std::string& name, float value)
	{
		glUniform1f(glGetUniformLocation(shaderID, name.c_str()), value);
	}

	void Shader::SetVec3(const std::string& name, glm::vec3 value)
	{
		glUniform3f(glGetUniformLocation(shaderID, name.c_str()), value.x, value.y, value.z);
	}

	void Shader::SetVec4(const std::string& name, glm::vec4 value)
	{
		glUniform4f(glGetUniformLocation(shaderID, name.c_str()), value.x, value.y, value.z, value.w);
	}
}