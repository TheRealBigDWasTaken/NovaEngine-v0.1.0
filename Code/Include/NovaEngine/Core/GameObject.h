#pragma once

#include "NovaEngine/Math/Transform.h"
#include "NovaEngine/Math/Vec3.h"

namespace NovaE {
	class Mesh;
	class Texture;
	class Shader;

	class GameObject {
	public:
		Transform transform;

		const Mesh* mesh = nullptr;
		const Texture* texture = nullptr;
		const Shader* shader = nullptr;

		Vec3 color = Vec3::One;

		GameObject(
			const Mesh& meshRef,
			const Texture& textureRef,
			const Shader& shaderRef,
			const Vec3& colorRef = Vec3::One
		)
		  : transform(),
			mesh(&meshRef),
			texture(&textureRef),
			shader(&shaderRef),
			color(colorRef)
		{}
		GameObject(const Mesh& meshRef, const Shader& shaderRef, const Vec3& colorRef = Vec3::One) 
			:transform(), mesh(&meshRef), texture(nullptr), shader(&shaderRef), color(colorRef)
		{}
	};
}