#include <Geode/Geode.hpp>
#include <MeteorMain/Includes.hpp>
using namespace geode::prelude;
using namespace Meteor;
class TestTab : public Meteor::Types::MeteorTab {
    Meteor::Types::InfoHandler ModInfo() override {
        Meteor::Types::InfoHandler info;
        info.Name = "UTILS";
        info.id = "Meteor.Utils";
        info.posnum = 0;
        return info;
   };
};

REGISTER_NEWTAB(TestTab)

