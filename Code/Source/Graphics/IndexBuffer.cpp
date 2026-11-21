#include "NovaEngine/Graphics/IndexBuffer.h"

namespace NovaE {
	IndexBuffer::IndexBuffer(const unsigned int* indices, unsigned int count) {
		glGenBuffers(1, &m_ID);
		// Upload the index data without modifying the currently bound VAO's
		// element-buffer association. Mesh is responsible for associating this
		// IBO with its VAO by calling Bind() after binding the VAO.
		
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		glBindBuffer(GL_COPY_WRITE_BUFFER, m_ID);
		glBufferData(GL_COPY_WRITE_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);
	}
	IndexBuffer::~IndexBuffer() {
		glDeleteBuffers(1, &m_ID);
	}
	void IndexBuffer::Bind() const{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	}
	void IndexBuffer::Unbind() const{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); // or just use another IndexBuffer
	}
}