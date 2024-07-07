#include <Geode/Geode.hpp>
#include <MeteorMain/Includes.hpp>
using namespace geode::prelude;
using namespace Meteor;
class TestTab : public Meteor::Types::MeteorTab {
    Meteor::Types::InfoHandler ModJson() {
        return Meteor::Types::InfoHandler {"Name","ID",0}; 
   };
};

REGISTER_NEWTAB(TestTab)

