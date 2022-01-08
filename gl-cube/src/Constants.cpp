#pragma once
#include "Constants.h"

namespace Constants {
    extern const float SCALE = 0.5f;

    extern const std::map<std::string, std::vector<float>> COLOR_TO_RGB = {
        {"green", {0.0f, 1.0f, 0.0f}},
        {"red", {1.0f, 0.0f, 0.0f}},
        {"blue", {0.0f, 0.0f, 1.0f}},
        {"white", {1.0f, 1.0f, 1.0f}},
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
        { "back", std::vector<std::vector<std::string>>(3, {"orange", "orange", "orange"}) },
        { "left", std::vector<std::vector<std::string>>(3, {"blue", "blue", "blue"}) },
        { "right", std::vector<std::vector<std::string>>(3, {"green", "green", "green"}) },
        { "bottom", std::vector<std::vector<std::string>>(3, {"yellow", "yellow", "yellow"}) },
        { "top", std::vector<std::vector<std::string>>(3, {"red", "red", "red"}) },
    };

    extern const float FRAME_ROTATION_DEGREE = 1.0f;

    extern const float SEPARATION_FACTOR = 2.5f;

    extern std::map<std::string, enum Rotation> ROTATION_ABBREVIATIONS = {
        {"Xi", TURN_DOWN},
        {"Y", TURN_LEFT},
        {"Z", TURN_CLOCKWISE},
        {"X", TURN_UP},
        {"Yi", TURN_RIGHT},
        {"Zi", TURN_COUNTERCLOCKWISE},
        {"F", FRONT_RIGHT},
        {"Fi", FRONT_LEFT},
        {"B", BACK_RIGHT},
        {"Bi", BACK_LEFT},
        {"U", TOP_RIGHT},
        {"Ui", TOP_LEFT},
        {"D", BOTTOM_RIGHT},
        {"Di", BOTTOM_LEFT},
        {"L", LEFT_RIGHT},
        {"Li", LEFT_LEFT},
        {"R", RIGHT_RIGHT},
        {"Ri", RIGHT_LEFT},

        {"S", Z_MIDDLE_RIGHT},
        {"Si", Z_MIDDLE_LEFT},
        {"E", Y_MIDDLE_LEFT},
        {"Ei", Y_MIDDLE_RIGHT},
        {"M", X_MIDDLE_RIGHT},
        {"Mi", X_MIDDLE_LEFT},
    };

    extern const int WINDOW_WIDTH = 600;
    extern const int WINDOW_HEIGHT = 600;

    extern const char* TITLE = "GL Cube";
}
