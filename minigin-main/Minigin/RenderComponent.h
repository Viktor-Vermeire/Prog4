#pragma once
#include "BaseComponent.h"
#include "TextComponent.h"
#include "Renderer.h"
#include "Font.h"
#include <SDL_ttf.h>
namespace dae {
    class RenderComponent : public BaseComponent
    {
    public:
        /*
        template <typename T, typename... Args>
        void Render(Args&&... args) {
            static_assert(std::is_base_of<TextComponent, T>::value, "T must be derived from BaseComponent");
            const SDL_Color color = { 255,255,255,255 }; // only white text is supported now
            const auto surf = TTF_RenderText_Blended(m_font->GetFont(), m_text.c_str(), color);
            // Construct a unique_ptr<T> and store it in the parent vector
        }*/
    private:

    };
}

