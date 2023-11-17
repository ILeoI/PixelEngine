#include "Engine.h"

namespace Wasabi {

	Engine::Engine(int width, int height, const std::string& name)
		: width(width), height(height), name(name)
	{

	}

	void Engine::CreateWindow()
	{
		glfwInit();
		
		glfwWindowHint(GLFW_RESIZABLE, false);

		window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create window" << std::endl;
			glfwTerminate();
		}

		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
		{
			std::cout << "Failed to init GLAD" << std::endl;
		}

		glViewport(0, 0, width, height);

		InputHandler::SetCallbacks(window);
	}
	
	void Engine::SetUpRenderQuad()
	{
		float vertices[] = {
			// positions           // texture coords
			 1.0f,  1.0f, 0.0f,    1.0f, 1.0f, // top right
			 1.0f, -1.0f, 0.0f,    1.0f, 0.0f, // bottom right
			-1.0f, -1.0f, 0.0f,    0.0f, 0.0f, // bottom left
			-1.0f,  1.0f, 0.0f,    0.0f, 1.0f  // top left 
		};

		unsigned int indicies[] = {
			0, 1, 2,
			2, 3, 0
		};

		glGenVertexArrays(1, &VBO);
		glGenBuffers(1, &VAO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	void Engine::CleanUp()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);

		glfwTerminate();
	}

	void Engine::PollAndDraw()
	{
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	float Engine::GetDeltaTime()
	{
		float currentTime = (float) glfwGetTime();
		float dt = currentTime - lastTime;
		lastTime = currentTime;
		deltaTime = dt;
		return dt;
	}

	void Engine::Run()
	{
		CreateWindow();
		SetUpRenderQuad();

		Utils::FlipImage(true);

		std::string fragmentShaderLoc = "shaders\\fragmentShader.glsl";
		std::string vertexShaderLoc = "shaders\\vertexShader.glsl";

		Shader shader(vertexShaderLoc, fragmentShaderLoc);
		
		Texture texture(width, height);
		
		PixelRenderer pixelRenderer(&texture);
		
		std::string spritesheetPath = "spritesheets\\player-spritesheet.png";
		Spritesheet playerSpritesheet(spritesheetPath, 16, 16);

		std::string backgroundPath = "textures\\testBackground.png";

		Scene scene(0);
		
		Entity backgroundEntity;
		auto& comp = backgroundEntity.AddComponent(new BackgroundComponent(backgroundEntity, backgroundPath, &texture));
		scene.SetBackgroundEntity(backgroundEntity);
		
		auto& testSprite = scene.AddEntity({ { 400, 400 }, 0 });
		testSprite.AddComponent(new SpriteComponent(testSprite, 0, &playerSpritesheet, &pixelRenderer));
		testSprite.AddComponent(new PlayerComponent(testSprite));

		// Send pixel data to shader
		shader.SetInt("pixels", texture.GetTextureID());
		shader.Use();

		scene.Start();
		
		while (!glfwWindowShouldClose(window))
		{
			float dt = GetDeltaTime();
			
			if (InputHandler::IsKeyPressed(GLFW_KEY_ESCAPE))
			{
				glfwSetWindowShouldClose(window, true);
			}

			scene.Update(dt);
			
			texture.SetPixels();
			PollAndDraw();
		}

		CleanUp();
	}
}