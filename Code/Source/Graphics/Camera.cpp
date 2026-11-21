#include "NovaEngine/Graphics/Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>

namespace NovaE {
	const Vec3& Camera::GetPosition() const {
		return m_Position;
	}
	void Camera::SetPosition(const Vec3& pos) {
		m_Position = pos;
	}
	Camera::Camera(float fov, float aspectRatio, float nearClip, float farClip) {
		m_ViewMatrix = glm::mat4(1.0f);
		m_FOV = fov;
		m_AspectRatio = aspectRatio;
		m_NearClip = nearClip;
		m_FarClip = farClip;
		m_Position = Vec3::Zero;

		UpdateProjectionMatrix();
		UpdateViewMatrix();
	}
	void Camera::UpdateViewMatrix() {
		m_ViewMatrix = glm::translate(glm::mat4(1.0f), 
			glm::vec3(-m_Position.x, -m_Position.y, -m_Position.z)
		);
	}
	void Camera::UpdateProjectionMatrix() {
		float fovRad = glm::radians(m_FOV);
		float halfTan = std::tan(fovRad / 2.0f);

		m_ProjectionMatrix = glm::mat4(0.0f);

		m_ProjectionMatrix[0][0] = 1 / (m_AspectRatio * halfTan);
		m_ProjectionMatrix[1][1] = 1 / halfTan;
		m_ProjectionMatrix[2][2] = -(m_FarClip + m_NearClip)/(m_FarClip - m_NearClip);
		m_ProjectionMatrix[2][3] = -1.0f;
		m_ProjectionMatrix[3][2] = -(2.0f * m_FarClip * m_NearClip) / (m_FarClip - m_NearClip);
	}
	const glm::mat4& Camera::GetViewMatrix() const
	{
		return m_ViewMatrix;
	}

	const glm::mat4& Camera::GetProjectionMatrix() const
	{
		return m_ProjectionMatrix;
	}

	void Camera::SetFOV(float fov) {
		m_FOV = fov;
	}
}