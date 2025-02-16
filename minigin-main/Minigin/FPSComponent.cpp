#include "FPSComponent.h"
#include "Minigin.h"
#include "GameObject.h"
#include "TextComponent.h"

dae::FPSComponent::FPSComponent()
{
	m_FPS = 0;
}

void dae::FPSComponent::Update(dae::GameObject* gameObject)
{
	CalculateFPS();
	gameObject->GetComponent<TextComponent>()->SetText(std::to_string(m_FPS));
}

float dae::FPSComponent::GetFPS()
{
	return m_FPS;
}

void dae::FPSComponent::CalculateFPS()
{
		m_FPS = 1000000.f / dae::Minigin::DELTATIME;
}
