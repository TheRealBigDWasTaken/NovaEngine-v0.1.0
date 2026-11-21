#include "NovaEngine/Core/Window.h"

namespace NovaE {
    //Window class
    int Window::Initialize() {
        this->m_window = glfwCreateWindow(this->m_width, this->m_height, this->m_windowName.c_str(), nullptr, nullptr);
        if (!this->m_window) {
            return -1;
        }
        glfwMakeContextCurrent(this->m_window);

        if (!gladLoadGL())
        {
            return -2;
        }
        return 1;
    }

    void Window::Exit() {
        glfwSetWindowShouldClose(m_window, GLFW_TRUE);
    }

    void Window::Clear(float r, float g, float b, float a) {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    void Window::Terminate() {
        glfwDestroyWindow(this->m_window);
        glfwTerminate();
    }
    void Window::EndFrame() {
        glfwSwapBuffers(this->m_window);
    }
    void Window::PollEvents() {
        glfwPollEvents();
    }
}