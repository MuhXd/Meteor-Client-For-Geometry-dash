#pragma once
#include "../MeteorClass.hpp"
#include <imgui.h>
// put imgui theming in here
namespace Meteor::UI::Theme {
void Draw() {
// called each frame when drawing
// draw mostly used for placing ui elements
return;
}
void Setup() {
// It's a callback as ImGui will be re-initialized when toggling fullscreen,
// so use this to setup any themes and/or fonts!
return;
}

}