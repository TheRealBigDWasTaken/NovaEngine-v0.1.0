#pragma once
#include <string>
#include <glm/glm.hpp>	

namespace NovaE {
	class Shader {
	public:
		// Loads, compiles, and links a vertex and fragment shader
		// from the specified files.
		//
		// Throws std::runtime_error if a shader file cannot be opened,
		// compilation fails, or linking fails.
		Shader(const std::string& vertexPath, const std::string& fragmentPath);
		
		// Releases the OpenGL shader program.
		~Shader();

		// Makes this shader program the active OpenGL program.
		void Use() const;

		// Uniforms
		// Uploads a 3-component floating-point value to the shader.
		void SetUniform3f(const std::string& name, float x, float y, float z) const;

		// Uploads a 4x4 matrix to the shader.
		void SetUniformMat4(const std::string& name, const glm::mat4& matrix) const;

		// Uploads an integer value to the shader.
		void SetUniform1i(const std::string& name, int value) const;
	private:
		// OpenGL handle for the linked shader program.
		unsigned int m_ID = 0;
	};
}