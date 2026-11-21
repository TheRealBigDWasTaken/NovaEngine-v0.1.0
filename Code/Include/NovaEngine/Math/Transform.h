#pragma once
#include "NovaEngine/Math/Vec3.h"
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace NovaE {
	class Transform {
	public:
		Vec3 Position;
		glm::quat Rotation;
		Vec3 Scale;

		Transform();

		glm::mat4 GetMatrix() const;

		void Rotate(const Vec3& axis, float angleDegrees);
	};
}