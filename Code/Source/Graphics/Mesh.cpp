#include "NovaEngine/Graphics/Mesh.h"
#include <glad/glad.h>
#include <cstdint>
#include <stdexcept>

namespace NovaE {

    static GLenum VertexDataTypeToOpenGL(VertexDataType type) {
        switch (type) {
        case VertexDataType::Float:
            return GL_FLOAT;
        case VertexDataType::UnsignedInt:
            return GL_UNSIGNED_INT;
        case VertexDataType::UnsignedByte:
            return GL_UNSIGNED_BYTE;
        case VertexDataType::Int:
            return GL_INT;
        }

        return 0;
    };
    Mesh::Mesh(const void* vertices, unsigned int vertexSize, const unsigned int* indices, unsigned int indexCount, const VertexLayout& vertexLayout)
        : m_VAO(), m_VBO(vertices, vertexSize), m_IBO(indices, indexCount), m_indexCount(indexCount)
    {
        if (!vertexLayout.HasSemantic(VertexSemantic::Position)) {
            throw std::runtime_error("Mesh layout must contain a Position attribute.");
        }

        m_VAO.Bind();
        m_VBO.Bind();
        m_IBO.Bind();

        for (const VertexElement& element : vertexLayout.GetElements()) {
            if (!vertexLayout.IsValidElement(element)) {
                throw std::runtime_error("Invalid vertex element in VertexLayout.");
            }

            GLuint location = VertexSemanticToLocation(element.semantic);
            if (element.interpretation ==
                VertexAttributeInterpretation::Integer)
            {
                glVertexAttribIPointer(
                    location,
                    element.count,
                    VertexDataTypeToOpenGL(element.type),
                    vertexLayout.GetStride(),
                    reinterpret_cast<const void*>(
                        static_cast<uintptr_t>(element.offset)
                        )
                );
            }
            else
            {
                glVertexAttribPointer(
                    location,
                    element.count,
                    VertexDataTypeToOpenGL(element.type),
                    element.normalized ? GL_TRUE : GL_FALSE,
                    vertexLayout.GetStride(),
                    reinterpret_cast<const void*>(
                        static_cast<uintptr_t>(element.offset)
                        )
                );
            }
            glEnableVertexAttribArray(location);
        }
    }
    void Mesh::Bind() const {
        m_VAO.Bind();
    }
    void Mesh::Draw() const {
        m_VAO.Bind();
        glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, nullptr);
    }
    GLuint Mesh::VertexSemanticToLocation(VertexSemantic semantic) {
        switch (semantic) {
            case VertexSemantic::Position:
                return 0;
            case VertexSemantic::Normal:
                return 1;
            case VertexSemantic::UV:
                return 2;
            case VertexSemantic::Color:
                return 3;
        }
        return 0;
    }
}