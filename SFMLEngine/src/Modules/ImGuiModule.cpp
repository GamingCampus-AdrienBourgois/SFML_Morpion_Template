#include "Modules/ImGuiModule.h"

#include <imgui-SFML.h>
#include <imgui.h>

#include "ModuleManager.h"
#include "Modules/WindowModule.h"

void ImGuiModule::Start()
{
	Module::Start();

	windowModule = moduleManager->GetModule<WindowModule>();
	timeModule = moduleManager->GetModule<TimeModule>();

	ImGui::SFML::Init(*windowModule->GetWindow());
}

void ImGuiModule::Update()
{
	Module::Update();

	ImGui::SFML::Update(*windowModule->GetWindow(), timeModule->GetDeltaClock().getElapsedTime());
}

void ImGuiModule::Render()
{
	Module::Render();
	ImGui::EndFrame();

	ImGui::SFML::Render(*windowModule->GetWindow());
}

void ImGuiModule::Finalize()
{
	Module::Finalize();

	ImGui::SFML::Shutdown(*windowModule->GetWindow());
}
