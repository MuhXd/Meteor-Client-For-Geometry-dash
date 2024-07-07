
#pragma once
#include "../MeteorClass.hpp"
#include <imgui.h>


namespace Meteor::Types {
struct InfoHandler
{
        const char* Name = "v";
        const char* Devs = "";
        const char* id = "v.v";            
};
        
class Mod {
        public:
                InfoHandler ModJson() {return InfoHandler {"Name","ID",0}; };
                bool showdevs = false;
                bool enabled = false;
                bool cheat = false;
                void update(float delta);
                void draw();
                void init();
};
class MeteorTab {
        public:
                InfoHandler ModJson() {return InfoHandler {"Name","ID",0}; };
                int posnum = 1;
                std::vector<Meteor::Types::Mod> mods = {};
    };
};
