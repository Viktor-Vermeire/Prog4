#pragma once
#include "BaseComponent.h"
#include "Transform.h"
namespace dae {
	class GameObject;
	class TransformComponent : public BaseComponent
	{
	public:
		TransformComponent(std::unique_ptr<Transform> pTransform);
		TransformComponent();
		void SetLocation(float x, float y, float z);
		const Transform* GetLocation();
	private:
		std::unique_ptr<Transform> m_pTransform;
	};
}

