#include <Geode/Geode.hpp>
#include <MeteorMain/Includes.hpp>
using namespace geode::prelude;
using namespace Meteor;
class TestMod : public Meteor::Types::MeteorTab {
    InfoHandler ModInfo() override {
                Meteor::Types::InfoHandler info;
                        info.Name = "HEY!";
                        info.id = "ID";
                        info.showdevs = false;
                        info.Devs = "Viper :3";
                        info.tabID = "Meteor.Utils";
                        return info;
                };
};

REGISTER_NEWMOD(TestMod)

