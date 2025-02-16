#pragma once

#include <vector>
#include "memory"
#include "Transform.h"
#include "BaseComponent.h"
#include "unordered_map"

namespace dae
{
	class Texture2D;
	// todo: this should become final.
	class GameObject
	{
	public:

		template <typename ComponentType, typename... Args>
		void AddComponent(Args&&... args) {
			static_assert(std::is_base_of<BaseComponent, ComponentType>::value, "ComponentType must be derived from BaseComponent");
			m_ComponentMap[typeid(ComponentType).name()] = std::make_unique<ComponentType>(std::forward<Args>(args)...);
		}

		template<class ComponentType>
		ComponentType* GetComponent()
		{
			static_assert(std::is_base_of<BaseComponent, ComponentType>::value, "ComponentType must be derived from BaseComponent");
			auto test = m_ComponentMap.find(typeid(ComponentType).name());
			if (test != m_ComponentMap.end())
				return static_cast<ComponentType*>(test->second.get());
			return nullptr;
		}

		template<class ComponentType>
		bool IsComponentPresent()
		{
			static_assert(std::is_base_of<BaseComponent, ComponentType>::value, "ComponentType must be derived from BaseComponent");
			auto test = m_ComponentMap.find(typeid(ComponentType).name());
			if (test != m_ComponentMap.end())
				return true;
			return false;
		}

		template<class ComponentType>
		void RemoveComponent()
		{
			static_assert(std::is_base_of<BaseComponent, ComponentType>::value, "ComponentType must be derived from BaseComponent");
			auto test = m_ComponentMap.find(typeid(ComponentType).name());
			if (test != m_ComponentMap.end()) {
				m_ComponentMap.erase(test);
			}
		}
		
		virtual void Update();
		virtual void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);
		bool RemoveComponent(const std::string& name);
		

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_transform{};
		// todo: mmm, every gameobject has a texture? Is that correct?
		std::shared_ptr<Texture2D> m_texture{};
		std::unordered_map<std::string, std::unique_ptr<BaseComponent>> m_ComponentMap{};

	};
}
