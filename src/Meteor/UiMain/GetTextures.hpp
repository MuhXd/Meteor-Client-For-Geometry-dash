
#pragma once
#include "../MeteorClass.hpp"
#include <imgui.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "../uilibs/stb_image.h"

namespace Meteor {
const char* LoadTexture(std::string texture) {
    if (texture == "DefaultFont.ttf") {
        return (Mod::get()->getResourcesDir() / "JetBrains Mono.ttf").string().c_str();
    } else if ( texture == "UiTriangle.ImGui")
    {
     return (Mod::get()->getResourcesDir() / "triangle.png").string().c_str();
    } else {
        return (Mod::get()->getResourcesDir() / texture).string().c_str();
    }
}


ImTextureID TEXTURE_TO_OPENGL(const char* filename)
{

    int width, height, channels;
    unsigned char* data = stbi_load(filename, &width, &height, &channels, 0);
    if (data == nullptr) {
        geode::log::error("Unable to load {}", filename);
        return nullptr;
    }


    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    GLenum format = GL_RGB;
    if (channels == 1)
    #ifdef GL_RED
        format = GL_RED;
    #else
        geode::log::debug("GL_RED NOT SUPPORTED!");
        format = GL_RGB;
    #endif
    else if (channels == 3)
        format = GL_RGB;
    else if (channels == 4)
        format = GL_RGBA;


    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);


    stbi_image_free(data);


    return (ImTextureID)(intptr_t)textureID;
}




}