#include <Meteor/UiMain/modhandler.hpp>
#include <Meteor/MeteorClass.hpp>
#include <Meteor/Shared/Theme.hpp>  // Ensure this header is included

void ExampleFunction() {
    Meteor::UI::Theme::NewTab({.Name = "Name", .id = "Id", .posnum = 1});
}
