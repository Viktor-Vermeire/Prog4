#include "TransformComponent.h"
#include "Transform.h"

dae::TransformComponent::TransformComponent(std::unique_ptr<Transform> pTransform):
	m_pTransform {std::move(pTransform)}
{
}

dae::TransformComponent::TransformComponent()
{
	m_pTransform = std::make_unique<Transform>();
}

void dae::TransformComponent::SetLocation(float x, float y, float z)
{
	m_pTransform->SetPosition(x, y, z);
}

const dae::Transform* dae::TransformComponent::GetLocation()
{
	return nullptr;
}




