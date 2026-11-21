#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include "NovaEngine/Graphics/Texture.h"

#include <iostream>
#include <stdexcept>

namespace NovaE {
	Texture::Texture(const std::string& path) 
		: m_ID(0), 
		m_width(0), 
		m_height(0), 
		m_channels(0) 
	{
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(
			path.c_str(), 
			&m_width,
			&m_height,
			&m_channels,
			0
		);
		if (!data) {
			throw std::runtime_error("Failed to load texture: " + path);
		}
		GLenum format;

		if (m_channels == 4)
			format = GL_RGBA;
		else if (m_channels == 3)
			format = GL_RGB;
		else {
			stbi_image_free(data);
			throw std::runtime_error("Unsupported texture format: " + path);
		}
		// Create one OpenGL texture object and give us its ID.
		glGenTextures(1, &m_ID);

		// Make our texture the currently active OpenGL texture.
		glBindTexture(GL_TEXTURE_2D, m_ID);

		// When the texture is scaled up, use linear interpolation
		// between nearby pixels instead of making every pixel look blocky.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// If UV coordinates go outside the [0, 1] range,
		// repeat the texture instead of clamping it to the edge.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		// Tell OpenGL what the pixel data looks like and upload it
		// from CPU memory into the GPU texture.
		glTexImage2D(
			GL_TEXTURE_2D,    // The kind of texture we are creating
			0,                // Mipmap level 0 (the original image)
			format,           // How OpenGL should store the image
			m_width,          // Width in pixels
			m_height,         // Height in pixels
			0,                // Must be 0 in this case
			format,           // Format of our source pixel data
			GL_UNSIGNED_BYTE, // Each channel is an unsigned byte
			data              // The actual pixels
		);
		GLenum error = glGetError();

		if (error != GL_NO_ERROR) {
			std::cout << "OpenGL texture upload error: " << error << '\n';
		}
		// The GPU has the image now, so the CPU copy can be deleted.
		stbi_image_free(data);
	}
	Texture::Texture(unsigned int width, unsigned int height, const unsigned char* data) 
		:m_ID(0), m_width(static_cast<int>(width)), m_height(static_cast<int>(height)), m_channels(4)
	{
		glGenTextures(1, &m_ID);
		glBindTexture(GL_TEXTURE_2D, m_ID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA8,
			width,
			height,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			data
		);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::Bind(unsigned int slot) const {
		// Select which texture unit we want to use.
		glActiveTexture(GL_TEXTURE0 + slot);

		// Bind this texture to that texture unit.
		glBindTexture(GL_TEXTURE_2D, m_ID);
	}

	void Texture::Unbind() const
	{
		// Unbind the currently active 2D texture.
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	Texture::~Texture()
	{
		// Delete the OpenGL texture object from the GPU.
		glDeleteTextures(1, &m_ID);
	}
}