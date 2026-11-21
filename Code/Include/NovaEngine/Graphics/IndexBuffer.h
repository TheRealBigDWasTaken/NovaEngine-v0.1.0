#pragma once

#include <glad/glad.h>

namespace NovaE {
	class IndexBuffer {
	public:
		IndexBuffer(const unsigned int* indices, unsigned int count);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;
	private:
		GLuint m_ID = 0;
	};
}