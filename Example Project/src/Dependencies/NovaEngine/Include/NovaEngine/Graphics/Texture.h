#pragma once

#include <glad/glad.h>
#include <string>

namespace NovaE {
	class Texture {
	public:
		Texture(const std::string& path);
		Texture(unsigned int width, unsigned int height, const unsigned char* data);
		~Texture();

		void Bind(unsigned int slot = 0) const;
		void Unbind() const;
	private:
		GLuint m_ID;
		int m_width;
		int m_height;
		int m_channels;
	};
}