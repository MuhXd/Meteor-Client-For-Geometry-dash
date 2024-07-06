#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <imgui-cocos.hpp>
#include <vector>
#include "MeteorClass.hpp"
#include "UiMain/theme.hpp"

using namespace geode::prelude;

namespace Meteor::UI {
    bool UiInit = false;
    void MetorInit() {
    if (UiInit) {
        return;
    }
    UiInit = true;
    ImGuiCocos::get().setup([] {
        Meteor::UI::Theme::Setup();
        // This runs after ImGui has been setup,
        // It's a callback as ImGui will be re-initialized when toggling fullscreen,
        // so use this to setup any themes and/or fonts!
    }).draw([] {
        Meteor::UI::Theme::Draw();
        ImGui::ShowDemoWindow();

        ImGui::End();
    });
    }
}
