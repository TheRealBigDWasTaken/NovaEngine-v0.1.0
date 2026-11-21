#include "NovaEngine/Graphics/Shader.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include <glad/glad.h>  // OpenGL functions
#include <glm/glm.hpp>	
#include <glm/gtc/type_ptr.hpp>

namespace NovaE {
    Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
    {
        std::ifstream vertexFile(vertexPath);
        std::ifstream fragmentFile(fragmentPath);

        if (!vertexFile.is_open())
            throw std::runtime_error("Couldn't open vertex shader: " + vertexPath);

        if (!fragmentFile.is_open())
            throw std::runtime_error("Couldn't open fragment shader: " + fragmentPath);

        std::string vertexCode;
        std::string fragmentCode;

        std::stringstream vertexStream;
        vertexStream << vertexFile.rdbuf();
        vertexCode = vertexStream.str();

        std::stringstream fragmentStream;
        fragmentStream << fragmentFile.rdbuf();
        fragmentCode = fragmentStream.str();

        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

        const char* source = vertexCode.c_str();

        glShaderSource(vertexShader, 1, &source, nullptr);
        glCompileShader(vertexShader);

        int success;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

        if (!success) {
            char infoLog[512];

            glGetShaderInfoLog(
                vertexShader,
                512,
                nullptr,
                infoLog
            );
            glDeleteShader(vertexShader);
            throw std::runtime_error(
                std::string("Vertex shader compilation failed:\n") + infoLog
            );
        }

        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        const char* fragmentSource = fragmentCode.c_str();

        glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);

        glCompileShader(fragmentShader);
        int successTwo;
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &successTwo);

        if (!successTwo) {
            char infoLog[512];

            glGetShaderInfoLog(
                fragmentShader,
                512,
                nullptr,
                infoLog
            );

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
            throw std::runtime_error(
                std::string("Fragment shader compilation failed:\n") + infoLog
            );
        }

        m_ID = glCreateProgram();
        glAttachShader(m_ID, vertexShader);
        glAttachShader(m_ID, fragmentShader);

        glLinkProgram(m_ID);

        int successThree;

        glGetProgramiv(m_ID, GL_LINK_STATUS, &successThree);

        if (!successThree) {
            char infoLog[512];

            glGetProgramInfoLog(
                m_ID,
                512,
                nullptr,
                infoLog
            );

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
            glDeleteProgram(m_ID);
            
            throw std::runtime_error(
                std::string("Shader linking failed:\n") + infoLog
            );
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    Shader::~Shader() {
        glDeleteProgram(m_ID);
    }
    void Shader::Use() const{
        glUseProgram(m_ID);
    }

    //Uniforms
    void Shader::SetUniform3f(const std::string& name, float x, float y, float z) const {
        GLint location = glGetUniformLocation(m_ID, name.c_str());
        if (location == -1)
            return;
        glUniform3f(location, x, y, z);
    }
    void Shader::SetUniformMat4(const std::string& name, const glm::mat4& matrix) const {
        GLint location = glGetUniformLocation(m_ID, name.c_str());
        if (location == -1)
            return;
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }
    void Shader::SetUniform1i(const std::string& name, int value) const{
        GLint location = glGetUniformLocation(m_ID, name.c_str());
        if (location == -1)
            return;
        glUniform1i(location, value);
    }
}