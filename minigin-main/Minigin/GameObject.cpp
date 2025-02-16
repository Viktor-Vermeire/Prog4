#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "iostream"
#include "unordered_map"
#include "memory"
#include "BaseComponent.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(){
	for (const auto& component : m_ComponentMap) {
		component.second->Update(this);
	}
	
}

void dae::GameObject::Render() const
{
	const auto& pos = m_transform.GetPosition();
	Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
	for (const auto& component : m_ComponentMap) {
		component.second->Render();
	}
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);

}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}



bool dae::GameObject::RemoveComponent(const std::string& name)
{
	for (auto& component : m_ComponentMap) {
		if (component.first._Equal(name)){}
			
	}
	return false;
}
