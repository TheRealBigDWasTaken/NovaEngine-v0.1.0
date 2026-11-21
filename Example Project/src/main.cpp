// this Example project will be compiled in x64 Release mode so the NovaEngine-v0.1.0-x64-Release.lib will be used

// First, configure the include directory:
// C/C++ -> General -> Additional Include Directories
// Add the path to NovaEngine's public include directory:
// NovaEngine v0.1/Code/Include

// Next, configure the library directory:
// Linker -> General -> Additional Library Directories
// Add the path to the folder containing the .lib file

// Finally, specify which library to link:
// Linker -> Input -> Additional Depencies
// Add NovaEngine-v0.1.0-x64-Release.lib

// Now we can use the engine!
#include <NovaEngine/NovaEngine.h>

int main() {
	// Initialize GLFW, which is used by NovaEngine to create and manage windows.
	if (!NovaE::Window::InitGLFW())		
		return -1;

	// Creates a 1280x720 window named "NovaEngine example project!"
	NovaE::Window window(1280, 720, "NovaEngine example project!");

	// Check if window initalized correctly.
	if (window.Initialize() != 1) {
		// Releases window recources if it failed.
		window.Terminate();
		return -1;
	}

	// Set the OpenGL viewport to cover the entire window.
	window.SetViewPort(0, 0, 1280, 720);

	// Tell NovaEngine's Input system which window to check for keyboard input.
	NovaE::Input::Bind(window.GetNativeWindow());

	// Initialize the renderer and create its default 1x1 white texture.
	// This texture is used when a GameObject doesn't have a texture assigned.
	NovaE::Renderer::Init();

	// Enable alpha blending so transparent textures can show what's behind them.
	// This is currently configured manually because NovaEngine doesn't support it yet.
	glEnable(GL_BLEND);		
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Define how vertex data is structured.
	// This layout must be compatible with the vertex attributes expected by the shader.
	NovaE::VertexLayout Vlayout;
	
	// Each vertex contains a 2D position (X, Y) and a texture coordinate (U, V).
	Vlayout.Push<float>(NovaE::VertexSemantic::Position, 2);
	Vlayout.Push<float>(NovaE::VertexSemantic::UV, 2);

	// Define the vertices of our rectangle.
	// It has to match with the VertexLayout that will be used when creating the Mesh
	float vertices[] = {
		//	 position		  UV
			 0.25f,  0.25f,   1.0f, 1.0f,
			 0.25f, -0.25f,   1.0f, 0.0f,
			-0.25f,  0.25f,   0.0f, 1.0f,
			-0.25f, -0.25f,   0.0f, 0.0f
	};
	
	// Define the vertex indices used to construct the two triangles making up the rectangle.
	// Or just the indices for the IBO for you non-traumatized individuals
	unsigned int indices[]{
		0,1,2,
		3,2,1
	};


	// creates a Mesh, required for a GameObject
	NovaE::Mesh rectangle(
		vertices,								// what verices are used
		sizeof(vertices),						// how many bytes is the array
		indices,								// indices for the mesh
		sizeof(indices) / sizeof(unsigned int),	// how many unsigned ints are in the array
		Vlayout									// how the vertices are layed out
	);

	// the shader is also required for a GameObject
	NovaE::Shader shader(
		"Assets/Shader/triangle.vert",	// the vertex shader, the .vert is not required, it can be any text file
		"Assets/Shader/triangle.frag"	// the fragment shader, the .frag is not required, it can be any text file
	);

	// The Texture constructor loads the image into the GPU's memory, where it can be used by the engine
	NovaE::Texture playerTexture("Assets/Textures/playerTexture.png");
	NovaE::Texture grassTexture("Assets/Textures/grassTexture.png");

	// we create a GameObject with a rectangle mesh, the player texture and a white color (white doesn't change anything)
	NovaE::GameObject player(rectangle, playerTexture, shader, { 1.0f, 1.0f, 1.0f });

	// we create 9 grass objects to spread around the world
	NovaE::GameObject grass1(rectangle, grassTexture, shader, { 1.0f, 1.0f, 1.0f });
	NovaE::GameObject grass2(rectangle, grassTexture, shader, { 1.0f, 1.0f, 1.0f });
	NovaE::GameObject grass3(rectangle, grassTexture, shader, { 1.0f, 1.0f, 1.0f });
	NovaE::GameObject grass4(rectangle, grassTexture, shader, { 1.0f, 1.0f, 1.0f });
	NovaE::GameObject grass5(rectangle, grassTexture, shader, { 1.0f, 1.0f, 1.0f });
	NovaE::GameObject grass6(rectangle, grassTexture, shader, { 1.0f, 1.0f, 1.0f });
	NovaE::GameObject grass7(rectangle, grassTexture, shader, { 1.0f, 1.0f, 1.0f });
	NovaE::GameObject grass8(rectangle, grassTexture, shader, { 1.0f, 1.0f, 1.0f });

	// we create the background platform, this one doesn't have a texture
	NovaE::GameObject background(rectangle, shader, { 150.0f / 255.0f, 1.0f, 120.0f / 255.0f });


	player.transform.Position = { 0.0f, 0.0f, 0.0f }; // default but just to be safe
	player.transform.Scale = { 5.0f, 5.0f, 0.0f }; // make the player a bit bigger
	player.transform.Scale.y *= 1.5f; //questionable design choices (jk, to make the player a rectangle)

	// we set the scale and position for the grass
	grass1.transform.Scale = {5.0f, 5.0f, 0.0f};
	grass2.transform.Scale = {5.0f, 5.0f, 0.0f};
	grass3.transform.Scale = {5.0f, 5.0f, 0.0f};
	grass4.transform.Scale = {5.0f, 5.0f, 0.0f};
	grass5.transform.Scale = {5.0f, 5.0f, 0.0f};
	grass6.transform.Scale = {5.0f, 5.0f, 0.0f};
	grass7.transform.Scale = {5.0f, 5.0f, 0.0f};
	grass8.transform.Scale = {5.0f, 5.0f, 0.0f};

	grass1.transform.Position = { 15.0f, 5.0f, -0.05f };
	grass2.transform.Position = { -11.0f, 2.0f, -0.05f };
	grass3.transform.Position = { -4.0f, -7.0f, -0.05f };
	grass4.transform.Position = { 5.0f, -4.0f, -0.05f };
	grass5.transform.Position = { 6.0f, -2.0f, -0.05f };
	grass6.transform.Position = { 22.0f, -10.0f, -0.05f };
	grass7.transform.Position = { 0.0f, 4.0f, -0.05f };
	grass8.transform.Position = { -14.0f, -9.0f, -0.05f };


	background.transform.Position = { 0.0f, 0.0f, -0.1f }; //behind the player
	background.transform.Scale = {100.0f, 50.0f, 0.0f};

	// The camera allows us to have a new perspective and to
	NovaE::Camera cam(60.0f, 1280.0f / 720.0f, 0.1f, 100.0f);
	cam.SetPosition({0.0f, 0.0f, 20.0f}); // set the position
	cam.UpdateViewMatrix();	
	cam.UpdateProjectionMatrix(); // it is technically useless because we didn't change the FOV or something like that

	constexpr float PLAYER_SPEED = 8.0f;

	// these are used to tell when to turn the sprite around
	int lastDir = 1;
	int currDir = 1;
	while (window.IsOpen()) {
		// we clear the back buffer with the this color
		window.Clear(0.2f, 0.2f, 0.5f, 1.0f);

		// we update the DeltaTime, tells us the time between 2 consecutive frames
		NovaE::DeltaTime::Update();
		float dt = NovaE::DeltaTime::Get();
		

		NovaE::Vec3 velocity;

		// we check for user input and change the velocity accordingly
		if (NovaE::Input::IsKeyPressed(NovaE::Key::W))
			velocity.y += 1;
		if (NovaE::Input::IsKeyPressed(NovaE::Key::S))
			velocity.y -= 1;
		if (NovaE::Input::IsKeyPressed(NovaE::Key::A)) {
			if (!NovaE::Input::IsKeyPressed(NovaE::Key::D))
				currDir = -1;
			velocity.x -= 1;
		}
		if (NovaE::Input::IsKeyPressed(NovaE::Key::D)) {
			if (!NovaE::Input::IsKeyPressed(NovaE::Key::A))
				currDir = 1;
			velocity.x += 1;
		}

	
		velocity.Normalize();
		player.transform.Position = player.transform.Position + velocity * PLAYER_SPEED * dt;

		if (player.transform.Position.x > 25.0f - (5.0f / 6.0f)) {
			player.transform.Position.x = 25.0f - (5.0f / 6.0f);
			velocity.x = 0;
		}

		if (player.transform.Position.x < -25.0f + (5.0f / 6.0f)) {
			player.transform.Position.x = -25.0f + (5.0f / 6.0f);
			velocity.x = 0;
		}

		if (player.transform.Position.y > 12.5f - (1.25f)) {
			player.transform.Position.y = 12.5f - (1.25f);
			velocity.y = 0;
		}

		if (player.transform.Position.y < -12.5f + (1.25f)) {
			player.transform.Position.y = -12.5f + (1.25f); //the description of lazyness
			velocity.y = 0;
		}

		float t = 1.0f - std::exp(-dt * 2);			//complex lerp-math
		NovaE::Vec3 camPos = cam.GetPosition();
		NovaE::Vec3 target = player.transform.Position;
		target.z = 20.0f;
		cam.SetPosition(
			camPos + (target - camPos) * t
		); //even more complex lerp-math
		cam.UpdateViewMatrix();

		if (currDir != lastDir)
			player.transform.Scale.x *= -1;
		lastDir = currDir;

		NovaE::Renderer::BeginScene(cam);

		NovaE::Renderer::Submit(background);

		NovaE::Renderer::Submit(grass1);	// we submit everything to the renderer
		NovaE::Renderer::Submit(grass2);
		NovaE::Renderer::Submit(grass3);
		NovaE::Renderer::Submit(grass4);
		NovaE::Renderer::Submit(grass5);
		NovaE::Renderer::Submit(grass6);
		NovaE::Renderer::Submit(grass7);
		NovaE::Renderer::Submit(grass8);
		
		NovaE::Renderer::Submit(player);

		NovaE::Renderer::EndScene();

		window.PollEvents();

		window.EndFrame();
	}

	// we release stored recources
	NovaE::Renderer::Shutdown();
	window.Terminate();

	return 0;
}