#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "Scene.h"
#include "TextComponent.h"
#include "FPSComponent.h"
#include "TransformComponent.h"
#include "iostream"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_shared<dae::GameObject>();
	go->SetTexture("background.tga");
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->SetTexture("logo.tga");
	go->SetPosition(216, 180);
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	go->AddComponent<dae::TextComponent>(dae::TextComponent("here", font));
	go->AddComponent<dae::FPSComponent>(dae::FPSComponent());
	std::cout << go->IsComponentPresent< dae::FPSComponent>();
	go->RemoveComponent< dae::FPSComponent>();
	std::cout << go->IsComponentPresent< dae::FPSComponent>();
	go->AddComponent<dae::FPSComponent>(dae::FPSComponent());
	go->AddComponent<dae::TransformComponent>(dae::TransformComponent());
	scene.Add(go);

	auto to = std::make_shared<dae::TextObject>("Programming 4 Assignment", font);
	to->SetPosition(80, 20);
	scene.Add(to);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}