#pragma once
#include "BaseComponent.h"
#include "memory"
#include "TextObject.h"
#include "Texture2D.h"
namespace dae
{
	class GameObject;
	class TextComponent : public BaseComponent
	{
	public:
		TextComponent(const std::string& text, std::shared_ptr<Font> font);
		void Update(GameObject* gameObject) override;
		void SetText(const std::string& text);
		void SetPosition(float x, float y);
		void Render() override;
		virtual ~TextComponent() = default;
		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = default;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = default;
	private:
		std::string m_Text;
		Transform m_Transform{};
		std::shared_ptr<Font> m_pFont;
		std::shared_ptr<Texture2D> m_pTextTexture;
		bool m_NeedsUpdate;
	};
}

