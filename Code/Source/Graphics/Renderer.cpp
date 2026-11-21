#include "NovaEngine/Graphics/Renderer.h"
#include <stdexcept>

#include "NovaEngine/Core/GameObject.h"
#include "NovaEngine/Graphics/Mesh.h"
#include "NovaEngine/Graphics/Shader.h"
#include "NovaEngine/Graphics/Texture.h"
#include "NovaEngine/Math/Transform.h"
#include "NovaEngine/Graphics/Camera.h"

namespace NovaE {
	std::vector<RenderCommand> Renderer::m_RenderQueue;
	Texture* Renderer::m_DefaultTexture = nullptr;
	const Camera* Renderer::m_Camera = nullptr;

	void Renderer::Init() {
		// Prevent creating another default texture if the renderer is
		// initialized more than once.
		if (m_DefaultTexture)
			return;
		// White texture used for untextured objects.
		// Multiplying a texture sample by white leaves the original color unchanged.
		unsigned char whitePixel[] = {
		255, 255, 255, 255
		};

		m_DefaultTexture = new Texture(1, 1, whitePixel);

		// Enable depth testing globally for 3D rendering.
		glEnable(GL_DEPTH_TEST);
	}

	void Renderer::BeginScene(const Camera& cam)
	{
		m_Camera = &cam;
	}

	void Renderer::Submit(const GameObject& gameObject) {
		RenderCommand command;

		command.meshPtr = gameObject.mesh;
		command.shaderPtr = gameObject.shader;
		command.transformPtr = &gameObject.transform;
		command.texturePtr = gameObject.texture;
		command.color = gameObject.color;

		m_RenderQueue.push_back(command);
	}

	void Renderer::EndScene() {
		//we can't render an object without somewhere to look at so we return
		if (!m_Camera) {
			m_RenderQueue.clear();
			return;
		}
		for (const RenderCommand& command : m_RenderQueue) {
			if (!command.shaderPtr || !command.transformPtr || !command.meshPtr)
				throw std::runtime_error("Submited GameObject doesn't have a mesh, shader or transform");
			command.shaderPtr->Use();
			command.shaderPtr->SetUniformMat4("uTransform", command.transformPtr->GetMatrix());
			command.shaderPtr->SetUniformMat4("uView", m_Camera->GetViewMatrix());
			command.shaderPtr->SetUniformMat4("uProjection", m_Camera->GetProjectionMatrix());

			command.shaderPtr->SetUniform3f("uColor", command.color.x, command.color.y, command.color.z);
			if (command.texturePtr) {
				command.texturePtr->Bind(0);
			}
			else {
				m_DefaultTexture->Bind(0);
			}
			command.shaderPtr->SetUniform1i("uTexture", 0);
			command.meshPtr->Draw();
		}
		m_RenderQueue.clear();
	}

	void Renderer::Shutdown() {
		delete m_DefaultTexture;
		m_DefaultTexture = nullptr;
		m_Camera = nullptr;
		//will get more complex with Renderer Expanding
	}
}