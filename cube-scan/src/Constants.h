#pragma once
#include <string>
#include <vector>
#include <map>

namespace Constants {
    extern const float SCALE;

    extern const std::map<std::string, std::vector<float>> COLOR_TO_RGB;

    extern const std::vector<float> VERTEX_COORDINATES;

    extern const std::map<std::string, std::vector<std::vector<std::string>>> DEFAULT_FACE_COLORS;
}
