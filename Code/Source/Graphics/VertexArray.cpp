#include "NovaEngine/Graphics/VertexArray.h"

namespace NovaE {
	VertexArray::VertexArray() {
		glGenVertexArrays(1, &m_ID);
		glBindVertexArray(m_ID);
	}
	VertexArray::~VertexArray() {
		glDeleteVertexArrays(1, &m_ID);
	}
	void VertexArray::Bind() const{
		glBindVertexArray(m_ID);
	}
	void VertexArray::Unbind() const{
		glBindVertexArray(0);
	}
}