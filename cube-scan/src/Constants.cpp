#pragma once
#include "Constants.h"

namespace Constants {
    extern const float SCALE = 0.5;

    extern const std::map<std::string, std::vector<float>> COLOR_TO_RGB = {
        {"green", {0.0f, 1.0f, 0.0f}},
        {"white", {1.0f, 0.0f, 0.0f}},
        {"blue", {0.0f, 0.0f, 1.0f}},
        {"red", {1.0f, 1.0f, 1.0f}},
        {"orange", {1.0f, 0.5f, 0.0f,}},
        {"yellow", {1.0f, 1.0f, 0.0f}},
        {"black", {0.0f, 0.0f, 0.0f}},
    };

    extern const std::vector<float> VERTEX_COORDINATES = {
        // front
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

        // back
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,

        // left
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,

        // right
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,

         // top
         -1.0f,  1.0f, -1.0f,
          1.0f,  1.0f, -1.0f,
          1.0f,  1.0f,  1.0f,
          1.0f,  1.0f,  1.0f,
         -1.0f,  1.0f,  1.0f,
         -1.0f,  1.0f, -1.0f,

         // bottom
         -1.0f, -1.0f, -1.0f,
          1.0f, -1.0f, -1.0f,
          1.0f, -1.0f,  1.0f,
          1.0f, -1.0f,  1.0f,
         -1.0f, -1.0f,  1.0f,
         -1.0f, -1.0f, -1.0f
    };

    extern const std::map<std::string, std::vector<std::vector<std::string>>> DEFAULT_FACE_COLORS = {
        { "front", std::vector<std::vector<std::string>>(3, {"white", "white", "white"}) },
        { "back", std::vector<std::vector<std::string>>(3, {"red", "red", "red"}) },
        { "left", std::vector<std::vector<std::string>>(3, {"blue", "blue", "blue"}) },
        { "right", std::vector<std::vector<std::string>>(3, {"green", "green", "green"}) },
        { "bottom", std::vector<std::vector<std::string>>(3, {"yellow", "yellow", "yellow"}) },
        { "top", std::vector<std::vector<std::string>>(3, {"red", "red", "red"}) },
    };
}
