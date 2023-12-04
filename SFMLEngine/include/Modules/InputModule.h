#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "Module.h"
#include "Maths/Vector2.h"

class InputModule final : public Module
{
public:
	void Start() override;
	void Update() override;

	static Maths::Vector2i GetMousePosition() { return mousePosition; }
	static Maths::Vector2i GetMouseDelta() { return mouseDelta; }

	static bool IsMouseButtonDown(const sf::Mouse::Button _button) { return sf::Mouse::isButtonPressed(_button); }
	static bool IsKeyDown(const sf::Keyboard::Key _key) { return sf::Keyboard::isKeyPressed(_key); }

private:
	sf::RenderWindow* window = nullptr;

	static Maths::Vector2i mousePosition;
	static Maths::Vector2i mouseDelta;
};
