// Author: Dante Nardo
// Last Modified: 1/1/2017
// Purpose: Implements the container methods for texture holder

#include "stdafx.h"
#include "TextureHolder.h"
#include <assert.h>

TextureHolder* TextureHolder::m_s_instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(m_s_instance == nullptr);
	m_s_instance = this;
}

TextureHolder::~TextureHolder()
{
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
	auto& m = m_s_instance->m_textures;
	auto kvp = m.find(filename);

	// Return the texture if we did not reach the end of the map
	if (kvp != m.end()) {
		return kvp->second;
	}
	// Otherwise, create a new key value pair
	else {
		auto& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}
