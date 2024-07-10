
#pragma once
#include "../MeteorClass.hpp"
#include <imgui.h>


namespace Meteor::Types {
struct InfoHandler
{
        const char* Name = "v";
        const char* Devs = "";
        const char* id = "v.v";  
        const char* tabID = "Meteor.Utils";  
        int posnum = 1;
        bool cheat = false;
        bool showdevs = false;  
};
        
class Mod {
        public:
                virtual  Meteor::Types::InfoHandler ModInfo() {
                Meteor::Types::InfoHandler info;
                        info.Name = "Name";
                        info.id = "ID";
                        info.showdevs = false;
                        info.Devs = "Viper :3";
                        info.tabID = "UTILS";
                        return info;
                };
                bool enabled = false;
                void update(float delta);
                void draw();
                void init();
};
class MeteorTab {
        public:
                virtual Meteor::Types::InfoHandler ModInfo() {
                Meteor::Types::InfoHandler info;
                        info.Name = "Name";
                        info.id = "ID";
                        info.posnum = 0;
                        return info;
                };
                bool enabled = true;
                std::vector<Meteor::Types::Mod*> mods = {};
    };
};
