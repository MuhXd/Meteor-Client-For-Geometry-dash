#pragma once
#include "../MeteorClass.hpp"
#include <imgui.h>
#include "GetTextures.hpp"
// put imgui theming in here


namespace Meteor::UI::Theme {
void Draw() {
// called each frame when drawing
// draw mostly used for placing ui elements
// Begin the window
ImGui::Begin("Drag", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground| ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoScrollbar);
ImGui::SetWindowSize(ImVec2(300,1000)); // 30
ImVec2 frameSize = ImVec2(300, 30); 
ImVec2 frametriSize = ImVec2(300, 30); 
ImVec2 framePos = ImVec2(0,0);
ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0, 0, 0, 0)); 
ImDrawList* drawList = ImGui::GetWindowDrawList();
ImVec2 frameMin = ImGui::GetCursorScreenPos();
ImVec2 frameMax = ImVec2(frameMin.x + frameSize.x, frameMin.y + frameSize.y);
drawList->AddRectFilledMultiColor(frameMin,frameMax,IM_COL32(127, 0, 255, 255),IM_COL32(100, 0, 255, 255),IM_COL32(127, 0, 255, 255),IM_COL32(127, 0, 255, 255));
const char* text = "UTILS";
ImVec2 textSize = ImGui::CalcTextSize(text);
ImVec2 textPosition;
textPosition.x = frameMin.x + (frameMax.x - frameMin.x - textSize.x) / 2.0f;
textPosition.y = frameMin.y + (frameMax.y - frameMin.y - (textSize.y  + 5)  ) / 2.0f;
drawList->AddText(textPosition, IM_COL32(255, 255, 255, 255),text);
//1032, 732
geode::log::debug("{}, {}",frameMax.x,frameMin.x);
drawList->AddImage(Meteor::TEXTURE_TO_OPENGL((Meteor::LoadTexture("UiTriangle.ImGui"))), ( ImVec2( (frameMax.x - 32) - 5 ,frameMin.y - 5)),frameMax,ImVec2(0,0),ImVec2(1,1),IM_COL32(0, 0, 0, 255) );
ImGui::PopStyleColor(); 
ImGui::End();
return;
}
void Setup() {
// It's a callback as ImGui will be re-initialized when toggling fullscreen,
// so use this to setup any themes and/or fonts!
auto* font = ImGui::GetIO().Fonts->AddFontFromFileTTF((Mod::get()->getResourcesDir() / "JetBrains Mono.ttf").string().c_str(), 20.0f);
return;
}

}