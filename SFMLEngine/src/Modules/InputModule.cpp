#include "Modules/InputModule.h"

#include <imgui-SFML.h>
#include <SFML/Window/Event.hpp>

#include "Engine.h"
#include "ModuleManager.h"
#include "Modules/WindowModule.h"

Maths::Vector2i InputModule::mousePosition = Maths::Vector2i::Zero;
Maths::Vector2i InputModule::mouseDelta = Maths::Vector2i::Zero;

void InputModule::Start()
{
	Module::Start();

	window = moduleManager->GetModule<WindowModule>()->GetWindow();
}

void InputModule::Update()
{
	Module::Update();

	sf::Event event;
	while (window->pollEvent(event))
	{
		ImGui::SFML::ProcessEvent(*window, event);

		if (event.type == sf::Event::Closed)
		{
			Engine::GetInstance()->Quit();
		}
	}

	const sf::Vector2i previous_mouse_position = sf::Vector2i(mousePosition);
	const sf::Vector2i new_mouse_position = sf::Mouse::getPosition(*window);

	mouseDelta = new_mouse_position - previous_mouse_position;
	mousePosition = new_mouse_position;
}
