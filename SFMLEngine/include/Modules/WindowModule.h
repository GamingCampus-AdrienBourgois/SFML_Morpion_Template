#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Module.h"

class WindowModule final : public Module
{
public:
	sf::RenderWindow* GetWindow() const { return window; }

	void Init() override;
	void PreRender() override;
	void PostRender() override;
	void Release() override;

private:
	sf::RenderWindow* window = nullptr;
};
