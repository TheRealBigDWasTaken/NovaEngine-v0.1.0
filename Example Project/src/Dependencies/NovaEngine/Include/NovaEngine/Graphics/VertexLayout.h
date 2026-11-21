#pragma once

#include <cstdint>
#include <vector>

namespace NovaE {
	enum class VertexSemantic {
		Position,
		Normal,
		UV,
		Color
	};
	enum class VertexDataType {
		Float,
		Int,
		UnsignedInt,
		UnsignedByte
	};
	enum class VertexAttributeInterpretation {
		FloatingPoint,
		Integer
	};

	inline uint32_t GetVertexDataTypeSize(VertexDataType type) {
		switch (type) {
		case VertexDataType::Float:
			return sizeof(float);
		case VertexDataType::UnsignedInt:
			return sizeof(unsigned int);
		case VertexDataType::UnsignedByte:
			return sizeof(unsigned char);
		case VertexDataType::Int:
			return sizeof(int);
		}
		return 0;
	}
	
	inline uint32_t GetMinVertexElementCount(VertexSemantic semantic) {
		switch (semantic) {
		case VertexSemantic::Position:
			return 2;
		case VertexSemantic::Normal:
			return 3;
		case VertexSemantic::UV:
			return 2;
		case VertexSemantic::Color:
			return 3;
		}
		return 0;
	}
	inline uint32_t GetExpectedVertexElementCount(VertexSemantic semantic) {
		switch (semantic) {
		case VertexSemantic::Position:
			return 3;
		case VertexSemantic::Normal:
			return 3;
		case VertexSemantic::UV:
			return 2;
		case VertexSemantic::Color:
			return 4;
		}
		return 0;
	}
	
	struct VertexElement {
		VertexSemantic semantic;
		uint32_t semanticIndex;

		VertexDataType type;
		VertexAttributeInterpretation interpretation;

		uint32_t count;
		bool normalized;

		uint32_t offset;
		uint32_t size;

		VertexElement(
			VertexSemantic semantic,
			uint32_t semanticIndex,
			VertexDataType type,
			VertexAttributeInterpretation interpretation,
			uint32_t count,
			bool normalized,
			uint32_t offset
		)
			: semantic(semantic),
			semanticIndex(semanticIndex),
			type(type),
			interpretation(interpretation),
			count(count),
			normalized(normalized),
			offset(offset),
			size(count* GetVertexDataTypeSize(type))
		{
		}
	};

	class VertexLayout {
	public:
		VertexLayout() = default;

		template<typename T>
		void Push(
			VertexSemantic semantic,
			uint32_t count,
			bool normalized = false,
			VertexAttributeInterpretation interpretation =
			VertexAttributeInterpretation::FloatingPoint,
			uint32_t semanticIndex = 0
		);

		const std::vector<VertexElement>& GetElements() const;

		uint32_t GetStride() const;

		bool IsValidElement(const VertexElement& element) const;

		bool HasSemantic(VertexSemantic semantic) const;
	private:
		std::vector<VertexElement> m_Elements;
		uint32_t m_Stride = 0;
	};
	//float
	template<>
	inline void VertexLayout::Push<float>(
		VertexSemantic semantic,
		uint32_t count,
		bool normalized,
		VertexAttributeInterpretation interpretation,
		uint32_t semanticIndex
	) {
		m_Elements.emplace_back(
			semantic,
			semanticIndex,
			VertexDataType::Float,
			interpretation,
			count,
			normalized,
			m_Stride
		);

		m_Stride += sizeof(float) * count;
	}

	//unsigned int
	template<>
	inline void VertexLayout::Push<unsigned int>(
		VertexSemantic semantic,
		uint32_t count,
		bool normalized,
		VertexAttributeInterpretation interpretation,
		uint32_t semanticIndex
	) {
		m_Elements.emplace_back(semantic, semanticIndex, VertexDataType::UnsignedInt, interpretation, count, normalized, m_Stride);
		m_Stride += sizeof(unsigned int) * count;
	}

	//unsigned char
	template<>
	inline void VertexLayout::Push<unsigned char>(
		VertexSemantic semantic,
		uint32_t count,
		bool normalized,
		VertexAttributeInterpretation interpretation,
		uint32_t semanticIndex
	) {
		m_Elements.emplace_back(semantic, semanticIndex, VertexDataType::UnsignedByte, interpretation, count, normalized, m_Stride);
		m_Stride += sizeof(unsigned char) * count;
	}

	template<>
	inline void VertexLayout::Push<int>(
		VertexSemantic semantic,
		uint32_t count,
		bool normalized,
		VertexAttributeInterpretation interpretation,
		uint32_t semanticIndex
	) {
		m_Elements.emplace_back(semantic, semanticIndex, VertexDataType::Int, interpretation, count, normalized, m_Stride);
		m_Stride += sizeof(int) * count;
	}
}