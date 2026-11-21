#pragma once
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace NovaE {
	class Window {
	private:
		int m_width; int m_height;
		std::string m_windowName;
		GLFWwindow* m_window = nullptr;
	public:
		Window(int width, int height, const std::string& windowName)
			: m_width(width),
			m_height(height),
			m_windowName(windowName)
		{ }
		void Exit();
		int GetWidth() const {
			return m_width;
		}
		int GetHeight() const {
			return m_height;
		}
		void SetViewPort(int x, int y, int width, int height) {
			glViewport(x, y, width, height);
		}
		int Initialize();
		bool IsOpen() const {
			return !glfwWindowShouldClose(this->m_window);
		}
		GLFWwindow* GetNativeWindow() const {
			return this->m_window;
		}
		void Terminate();
		void Clear(float r, float g, float b, float a);
		void EndFrame();
		void PollEvents();

		static bool InitGLFW() {
			return glfwInit() == GLFW_TRUE;
		}
	};
}