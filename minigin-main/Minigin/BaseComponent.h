#pragma once
#include <string>
#include "memory"
namespace dae
{
	class GameObject;
	class BaseComponent
	{
	public:
		BaseComponent();
		virtual ~BaseComponent();
		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = default;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = default;
		
		virtual void Update(GameObject* gameObject);
		virtual void Render();
	private:
		bool m_IsRendered;

	};
}

