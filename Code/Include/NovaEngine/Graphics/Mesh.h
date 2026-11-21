#pragma once
#include "NovaEngine/Graphics/VertexArray.h"
#include "NovaEngine/Graphics/VertexBuffer.h"
#include "NovaEngine/Graphics/VertexLayout.h"
#include "NovaEngine/Graphics/IndexBuffer.h"

namespace NovaE {
	class Mesh {
	public:
		Mesh(const void* vertices, unsigned int vertexSize, const unsigned int* indices, unsigned int indexCount, const VertexLayout& vertexLayout);
		void Bind() const;
		void Draw() const;
		static GLuint VertexSemanticToLocation(VertexSemantic semantic);
	private:
		VertexArray m_VAO;
		VertexBuffer m_VBO;
		IndexBuffer m_IBO;
		unsigned int m_indexCount;
	};
}