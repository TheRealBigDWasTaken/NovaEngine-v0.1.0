#pragma once

#include "NovaEngine/Math/Vec3.h"

namespace NovaE {
	class Mesh;
	class Shader;
	class Transform;
	class Texture;

	// Describes one object that the Renderer should draw.
	//
	// RenderCommand does not own any of these resources.
	// All pointers must remain valid until the command has been executed
	// by Renderer::EndScene().

	struct RenderCommand {
		// Mesh to draw.
		const Mesh* meshPtr = nullptr;

		// Shader used to render the mesh.
		const Shader* shaderPtr = nullptr;

		// Transform applied to the mesh.
		const Transform* transformPtr = nullptr;

		// Texture applied to the mesh.
		// nullptr means Renderer will use its default white texture.
		const Texture* texturePtr = nullptr;

		// Uniform color applied by the shader.
		Vec3 color = Vec3::One;
	};
}