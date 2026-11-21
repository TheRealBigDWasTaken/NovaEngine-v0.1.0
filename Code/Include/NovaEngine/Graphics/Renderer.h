#pragma once
#include <vector>
#include "NovaEngine/Graphics/RenderCommand.h"
#include "NovaEngine/Graphics/Texture.h"
#include "NovaEngine/Graphics/Camera.h"

namespace NovaE {
	class GameObject;
	// Static renderer responsible for collecting GameObjects into a render queue
	// and executing that queue for the current scene.
	//
	// Typical usage:
	//     Renderer::Init();
	//     Renderer::BeginScene(camera);
	//     Renderer::Submit(object);
	//     Renderer::EndScene();
	//     Renderer::Shutdown();
	class Renderer
	{
	public:
		// Initializes renderer-wide OpenGL state and creates the default texture.
		static void Init();

		// Begins a new scene and sets the camera used for rendering.
		// The camera must remain alive until EndScene() has completed.
		static void BeginScene(const Camera& cam);

		// Adds a GameObject to the current render queue.
		// The renderer does not take ownership of the GameObject or any of
		// the resources referenced by it.
		static void Submit(const GameObject& gameObject);

		// Executes all queued render commands using the current scene camera,
		// then clears the render queue.
		static void EndScene();

		// Releases renderer-owned resources and resets renderer state.
		static void Shutdown();
	private:
		// Commands waiting to be rendered at the end of the current scene.
		static std::vector<RenderCommand> m_RenderQueue;

		// 1x1 white texture used when a GameObject has no texture.
		static Texture* m_DefaultTexture;

		// Camera used by the currently active scene.
		// Non-owning; the caller must keep the camera alive until EndScene().
		static const Camera* m_Camera;
	};
}