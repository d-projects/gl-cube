#pragma once
#include <string>
#include <vector>
#include <map>
#include "Rotations.h"


namespace Constants {
    extern const float SCALE;

    extern const std::map<std::string, std::vector<float>> COLOR_TO_RGB;

    extern const std::vector<float> VERTEX_COORDINATES;

    extern const std::map<std::string, std::vector<std::vector<std::string>>> DEFAULT_FACE_COLORS;

    extern const float FRAME_ROTATION_DEGREE;

    extern const float SEPARATION_FACTOR;

    extern std::map<std::string, enum Rotation> ROTATION_ABBREVIATIONS;
}
