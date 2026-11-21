#pragma once
#include <glm/glm.hpp>
#include "NovaEngine/Math/Vec3.h"

namespace NovaE {
    class Camera
    {
    public:
        Camera(float fov, float aspectRatio, float nearClip, float farClip);

        const glm::mat4& GetViewMatrix() const;
        const glm::mat4& GetProjectionMatrix() const;

        const Vec3& GetPosition() const;
        void SetPosition(const Vec3& pos);

        void UpdateViewMatrix();
        void UpdateProjectionMatrix();

        void SetFOV(float fov);
    private:
        float m_FOV;
        float m_AspectRatio;
        float m_NearClip;
        float m_FarClip;

        Vec3 m_Position;

        glm::mat4 m_ViewMatrix;
        glm::mat4 m_ProjectionMatrix;
    };
}