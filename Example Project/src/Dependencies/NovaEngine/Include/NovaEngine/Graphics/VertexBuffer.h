#pragma once

#include <glad/glad.h>

namespace NovaE {
	class VertexBuffer {
	public:
		VertexBuffer(const void* vertices, unsigned int size);
		~VertexBuffer();

		void Bind() const;
		void Unbind() const;
	private:
		GLuint m_ID = 0;
	};
}