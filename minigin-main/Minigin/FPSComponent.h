#pragma once
#include "BaseComponent.h"
namespace dae {
    class GameObject;
    class FPSComponent : public BaseComponent
    {
    public:
        FPSComponent();
        void Update(GameObject* gameObject) override;
        float GetFPS();
    private:
        void CalculateFPS();
        float m_FPS;
    };
}

