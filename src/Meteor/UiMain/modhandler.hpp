
#pragma once
#include "../MeteorClass.hpp"
#include <imgui.h>


namespace Meteor::Types {
struct InfoHandler
{
        const char* Name = "v";
        const char* Devs = "";
        const char* id = "v.v";  
        int posnum = 1;          
};
        
class Mod {
        public:
                InfoHandler ModInfo() {
                Meteor::Types::InfoHandler info;
                        info.Name = "Name";
                        info.id = "ID";
                        info.posnum = 0;
                        return info;
                };
                bool showdevs = false;
                bool enabled = false;
                bool cheat = false;
                void update(float delta);
                void draw();
                void init();
};
class MeteorTab {
        public:
                InfoHandler ModInfo() {
                Meteor::Types::InfoHandler info;
                        info.Name = "Name";
                        info.id = "ID";
                        info.posnum = 0;
                        return info;
                };
                std::vector<Meteor::Types::Mod> mods = {};
    };
};
