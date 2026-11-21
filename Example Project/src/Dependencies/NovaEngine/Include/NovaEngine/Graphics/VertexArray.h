#pragma once
#include <glad/glad.h>

namespace NovaE {
	class VertexArray {
	public:
		VertexArray();
		~VertexArray();

		void Bind() const;
		void Unbind() const;
	private:
		GLuint m_ID = 0;
	};
}