#include "NovaEngine/Math/Transform.h"
#include "NovaEngine/Math/Vec3.h"
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace NovaE {
	Transform::Transform() :
		Position(Vec3::Zero), 
		Rotation(glm::quat(1.0f, 0.0f, 0.0f, 0.0f)),
		Scale(Vec3::One)
	{
	}
	glm::mat4 Transform::GetMatrix() const {
        glm::mat4 translation(1.0f);

        translation[3][0] = Position.x;
        translation[3][1] = Position.y;
        translation[3][2] = Position.z;

        //matrix *= glm::mat4_cast(Rotation);

        glm::mat4 scale(1.0f); //i know i sould not make a seperate matrix for scale but i trust the compiler
        
        scale[0][0] = Scale.x;
        scale[1][1] = Scale.y;
        scale[2][2] = Scale.z;
        
        glm::mat4 rotation = glm::mat4_cast(Rotation);
        
		return translation * rotation * scale;
	};

    void Transform::Rotate(const Vec3& axis, float angleDegrees) {
        glm::vec3 glmAxis(axis.x, axis.y, axis.z);

        glm::quat deltaRotation = glm::angleAxis(glm::radians(angleDegrees), glm::normalize(glmAxis));
        Rotation = deltaRotation * Rotation;
    }
}