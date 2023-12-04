#include "ModuleManager.h"

#include "Modules/ImGuiModule.h"
#include "Modules/InputModule.h"
#include "Modules/MorpionModule.h"
#include "Modules/TimeModule.h"
#include "Modules/WindowModule.h"

ModuleManager::~ModuleManager()
{
	Release();
	modules.clear();
}

void ModuleManager::CreateDefaultModules()
{
	CreateModule<TimeModule>();
	CreateModule<InputModule>();
	CreateModule<WindowModule>();
	CreateModule<ImGuiModule>();
	CreateModule<MorpionModule>();
}

void ModuleManager::Init() const
{
	for (Module* module : modules)
	{
		module->Init();
	}
}

void ModuleManager::Start() const
{
	for (Module* module : modules)
	{
		module->Start();
	}
}

void ModuleManager::Update() const
{
	for (Module* module : modules)
	{
		module->Update();
	}
}

void ModuleManager::PreRender() const
{
	for (Module* module : modules)
	{
		module->PreRender();
	}
}

void ModuleManager::Render() const
{
	for (Module* module : modules)
	{
		module->Render();
	}
}

void ModuleManager::PostRender() const
{
	for (Module* module : modules)
	{
		module->PostRender();
	}
}

void ModuleManager::Release() const
{
	for (Module* module : modules)
	{
		module->Release();
	}
}

void ModuleManager::Finalize() const
{
	for (Module* module : modules)
	{
		module->Finalize();
	}
}
