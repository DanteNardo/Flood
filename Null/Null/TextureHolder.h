// Author: Dante Nardo
// Last Modified: 1/1/2017
// Purpose: Defines the container class for all game textures

#pragma once
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map>

class TextureHolder
{
private:
	// A static singleton that can be accessed via the class name
	static TextureHolder* m_singleton;

	// A map that contains all of the game textures
	std::map<std::string, sf::Texture> m_textures;

public:
	TextureHolder();
	~TextureHolder();

	static sf::Texture& GetTexture(std::string const& filename);
};

#endif