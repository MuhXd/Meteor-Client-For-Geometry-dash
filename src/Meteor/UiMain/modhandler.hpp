
#pragma once
#include "../MeteorClass.hpp"
#include <imgui.h>

namespace Meteor::Types {
struct Mod {
        std::string Name = "v";
        std::string Devs = "";
        std::string id = "v.v";
        bool showdevs = false;
        bool enabled = false;
        bool cheat = false;
        void update(float delta);
        void draw();
        void init();
};
struct MeteorTab {
        const char* Name = "";
        const char* id = "";
        int posnum = 0;
        std::vector<Meteor::Types::Mod> mods = {};
    };
};
