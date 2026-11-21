#include "NovaEngine/Graphics/VertexBuffer.h"

namespace NovaE {
	VertexBuffer::VertexBuffer(const void* vertices, unsigned int size) {
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);

		glBufferData(
			GL_ARRAY_BUFFER,
			size,
			vertices,
			GL_STATIC_DRAW
		);
	}
	VertexBuffer::~VertexBuffer() {
		glDeleteBuffers(1, &m_ID);
	}
	void VertexBuffer::Bind() const{
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}
	void VertexBuffer::Unbind() const{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}