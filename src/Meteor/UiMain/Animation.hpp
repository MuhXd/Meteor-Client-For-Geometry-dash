#pragma once
#include "../MeteorClass.hpp"
#include <imgui.h>
#include <functional>
// prob won't be used
// https://github.com/EclipseMenu/EclipseMenu/blob/main/src/modules/gui/themes/megahack/animation/move-action.cpp
namespace Meteor::UI::Animate {
    class AnimateObject {
    public:

        AnimateObject* create(double duration, ImVec2* vector, ImVec2 target, EasingFunction easing) {
            auto *instance = new MoveAction();
            instance->m_duration = duration;
            instance->m_target = vector;
            instance->m_start = {vector->x, vector->y};
            instance->m_end = target;
            instance->m_delta = {target.x - vector->x, target.y - vector->y};
            instance->m_easing = easing;
            instance->m_totalTime = 0;
            return instance;
        };

       
        void update(double deltaTime) {
        if (m_duration == 0) {
            m_target->x = m_end.x;
            m_target->y = m_end.y;
            return;
        }

        if (isFinished())
            return;

        m_totalTime += deltaTime;

        if (isFinished()) {
            m_target->x = m_end.x;
            m_target->y = m_end.y;
            return;
        }

        double time = m_totalTime / m_duration;
        auto eased = static_cast<float>(m_easing(time));

        ImVec2 current = {m_delta.x * eased, m_delta.y * eased};
        m_target->x = m_start.x + current.x;
        m_target->y = m_start.y + current.y;
    };

      
    [[nodiscard]] double getProgress() {
        return m_easing(m_totalTime / m_duration);
    };

        
        [[nodiscard]] bool isFinished() const {
        return m_totalTime >= m_duration;
    };

    private:
        ImVec2* m_target{};
        ImVec2 m_start;
        ImVec2 m_end;
        ImVec2 m_delta;

        double m_duration{}, m_totalTime{};
        EasingFunction m_easing{};
    };
}