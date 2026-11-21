#include "NovaEngine/Graphics/VertexLayout.h"

namespace NovaE {
	const std::vector<VertexElement>& VertexLayout::GetElements() const {
		return m_Elements;
	}
	uint32_t VertexLayout::GetStride() const {
		return m_Stride;
	}
	bool VertexLayout::IsValidElement(const VertexElement& element) const{
		return element.count >= GetMinVertexElementCount(element.semantic) 
			&& element.count <= GetExpectedVertexElementCount(element.semantic);
	}
	bool VertexLayout::HasSemantic(VertexSemantic semantic) const {
		for (const VertexElement& e : m_Elements) {
			if (e.semantic == semantic)
				return true;
		}
		return false;
	}
}