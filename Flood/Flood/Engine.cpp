// Author: Dante Nardo
// Last Modified: 1/1/2017
// Purpose: Implements the key functions that the game uses to run

#include "stdafx.h"
#include "Engine.h"

using namespace sf;

Engine::Engine()
{
	// Initialize window
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	m_window.create(VideoMode(resolution.x, resolution.y), "Flood", Style::Fullscreen);

	// Initialize views
	m_vmain.setSize(resolution);
	m_vhud.reset(FloatRect(0, 0, resolution.x, resolution.y));
	m_vleft.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_vright.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_bg_vleft.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_bg_vright.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_texBackground = TextureHolder::GetTexture("graphics/background.png");
	m_sprBackground.setTexture(m_texBackground);
}

Engine::~Engine()
{
}

void Engine::input()
{
	Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == Event::KeyPressed) {
			switch (event.key.code) {
			case Keyboard::Escape:
				m_window.close();
				break;
			case Keyboard::Return:
				m_playing = true;
				break;
			case Keyboard::Q:
				m_character = m_character == MAX_CHARACTERS ? 0 : m_character++;
				break;
			case Keyboard::E:
				m_splitscreen = !m_splitscreen;
				break;
			}
		}
	}
}

void Engine::update(float dtAsSeconds)
{
	if (m_playing) {
		m_timeRemaining -= dtAsSeconds;
		if (m_timeRemaining <= 0) {
			m_newLevelRequired = true;
		}
	}
}

void Engine::draw()
{
	m_window.clear(Color::White);
	
	if (!m_splitscreen) {
		m_window.setView(m_bg_vmain);
		m_window.draw(m_sprBackground);
		m_window.setView(m_vmain);
	}
	else {
		m_window.setView(m_bg_vleft);
		m_window.draw(m_sprBackground);
		m_window.setView(m_vleft);

		m_window.setView(m_bg_vright);
		m_window.draw(m_sprBackground);
		m_window.setView(m_vright);
	}

	m_window.setView(m_vhud);
	m_window.display();
}

void Engine::run()
{
	Clock clock;

	while (m_window.isOpen()) {
		// Get the change in time since the last frame
		Time dt = clock.restart();
		m_gameTime += dt;
		float dtAsSeconds = dt.asSeconds();

		// Call the three game running functions
		input();
		update(dtAsSeconds);
		draw();
	}
}