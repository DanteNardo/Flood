// Author: Dante Nardo
// Last Modified: 1/1/2017
// Purpose: Defines the Engine that the entire game runs on

#pragma once
#include <SFML\Graphics.hpp>
#include "TextureHolder.h"

class Engine
{
private:
	TextureHolder th;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;
	const int MAX_CHARACTERS = 2;

	sf::RenderWindow m_window;
	sf::View m_vmain;
	sf::View m_vleft;
	sf::View m_vright;
	sf::View m_bg_vmain;
	sf::View m_bg_vleft;
	sf::View m_bg_vright;
	sf::View m_vhud;

	sf::Sprite m_sprBackground;
	sf::Texture m_texBackground;

	bool m_playing = false;
	bool m_splitscreen = false;
	bool m_newLevelRequired = true;
	int m_character = 1;

	sf::Time m_gameTime;
	float m_timeRemaining = 10;

	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	Engine();
	~Engine();

	void run();
};

