#pragma once

#include "../MeteorClass.hpp"
#include <imgui.h>
#include "GetTextures.hpp"
#include "modhandler.hpp"

#define REGISTER_NEWTAB(Class) $execute { Meteor::UI::Theme::NewTab<Class>(); }

#define REGISTER_NEWMOD(Class) $execute { Meteor::UI::Theme::NewMod<Class>(); }

namespace Meteor::UI::Theme {

inline std::vector<Meteor::Types::MeteorTab*> tabs;
inline std::vector<Meteor::Types::Mod*> ModsToAdd;

static void NewTab(Meteor::Types::MeteorTab* registerTab) {
    tabs.push_back(registerTab);
}

template<typename T, typename = std::enable_if_t<std::is_base_of_v<Meteor::Types::MeteorTab, T>>>
        static void NewTab() { NewTab(new T()); }


static void NewMod(Meteor::Types::Mod* registerTab) {
    Meteor::Types::InfoHandler ginfo = registerTab->ModInfo();
    bool found = false;
    for (Meteor::Types::MeteorTab* tab : Meteor::UI::Theme::tabs) {
        Meteor::Types::InfoHandler info = tab->ModInfo();
        if (info.id == ginfo.tabID) {
            tab->mods.push_back(registerTab);
            found = true;
            break;
        }
    }
    if (!found) {
        log::debug("A MOD WAS UNABLE TO BE ADDED");
         ModsToAdd.push_back(registerTab);
    }
}

template<typename T, typename = std::enable_if_t<std::is_base_of_v<Meteor::Types::Mod, T>>>
        static void NewMod() { NewMod(new T()); }



inline void DrawTab(Meteor::Types::MeteorTab* tab) {
    Meteor::Types::InfoHandler info = tab->ModInfo();
    ImGui::Begin(info.id, nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoScrollbar);
    ImGui::SetWindowSize(ImVec2(300, 1000));

    ImVec2 frameSize(300, 30);
    ImVec2 framePos(0, 0);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0, 0, 0, 0));
    ImDrawList* drawList = ImGui::GetWindowDrawList();

    ImVec2 frameMin = ImGui::GetCursorScreenPos();
    ImVec2 frameMax(frameMin.x + frameSize.x, frameMin.y + frameSize.y);
    drawList->AddRectFilledMultiColor(frameMin, frameMax, IM_COL32(127, 0, 255, 255), IM_COL32(100, 0, 255, 255), IM_COL32(127, 0, 255, 255), IM_COL32(127, 0, 255, 255));

    const char* text = info.Name;
    ImVec2 textSize = ImGui::CalcTextSize(text);
    ImVec2 textPosition;
    textPosition.x = frameMin.x + (frameMax.x - frameMin.x - textSize.x) / 2.0f;
    textPosition.y = frameMin.y + (frameMax.y - frameMin.y - textSize.y) / 2.0f;
    drawList->AddText(textPosition, IM_COL32(255, 255, 255, 255), text);

    ImVec4 originalButtonColor = ImGui::GetStyle().Colors[ImGuiCol_Button];
    ImVec4 originalButtonHoveredColor = ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered];
    ImVec4 originalButtonActiveColor = ImGui::GetStyle().Colors[ImGuiCol_ButtonActive];

    //ImGui::GetStyle().Colors[ImGuiCol_Button] = ImVec4(0, 0, 0, 0);
  //  ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered] = ImVec4(0, 0, 0, 0);
   // ImGui::GetStyle().Colors[ImGuiCol_ButtonActive] = ImVec4(0, 0, 0, 0);

    ImGui::SetCursorScreenPos(ImVec2((frameMax.x - 48), frameMin.y));
    ImTextureID myTexture = Meteor::TEXTURE_TO_OPENGL(Meteor::LoadTexture("UiTriangle.ImGui"));
    int index = 0;
    ImGui::PushID(index);
    if (ImGui::ImageButton(myTexture, ImVec2(32, frameMax.y - frameMin.y), ImVec2(0, 0), ImVec2(1, 1), 0, ImVec4(0, 0, 0, 0), ImVec4(1, 1, 1, 1))) {
        //tab->enabled = !tab->enabled;
        log::debug("click");
    }
    ImGui::PopID();
    index+=1;

    ImGui::SetCursorScreenPos(frameMin);

    ImGui::PopStyleColor();
    ImGui::GetStyle().Colors[ImGuiCol_Button] = originalButtonColor;
    ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered] = originalButtonHoveredColor;
    ImGui::GetStyle().Colors[ImGuiCol_ButtonActive] = originalButtonActiveColor;
    if (tab->enabled) {
        for (Meteor::Types::Mod* bew : tab->mods) {
            ImGui::Button(bew->ModInfo().Name);
            log::debug("{}",bew->ModInfo().Name);
         }
    }
    ImGui::End();
}

inline void Draw() {
    for (Meteor::Types::MeteorTab* tab : Meteor::UI::Theme::tabs) {
        DrawTab(tab);
    }
}

inline void Setup() {
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontFromFileTTF(Meteor::LoadTexture("DefaultFont.ttf"), 20.0f);
}

}
