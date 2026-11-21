#include "NovaEngine/Core/DeltaTime.h"
#include <GLFW/glfw3.h>
#include <cmath>

namespace NovaE {
	double DeltaTime::m_LastTime = 0.0;
	float DeltaTime::m_DeltaTime = 0.0f;

	void DeltaTime::Update() {
		double currentTime = glfwGetTime();

		if (m_LastTime == 0.0){
			m_LastTime = currentTime;
			return;
		}
		m_DeltaTime = static_cast<float>(currentTime - m_LastTime);
		m_DeltaTime = m_DeltaTime > 0.1f ? 0.1f : m_DeltaTime;
		m_LastTime = currentTime;
	}
	float DeltaTime::Get() {
		return m_DeltaTime;
	}
}