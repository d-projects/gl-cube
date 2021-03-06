#include "Cubelet.h"
#include "Constants.h"
#include "glm/gtc/matrix_transform.hpp"

Cubelet::Cubelet() {}

Cubelet::Cubelet(std::vector<std::string> faceColors, unsigned int vao, unsigned int vbo, int i, int j, int k) {
	_vao = vao;
	_shader = Shader("shaders/shader.vs", "shaders/shader.fs");
	_rotationModel = glm::mat4(1.0f);
    _rotationModel = glm::translate(_rotationModel, glm::vec3(
        Constants::SEPARATION_FACTOR * (k - 1) * Constants::SCALE,
        Constants::SEPARATION_FACTOR * -1 * (j - 1) * Constants::SCALE,
        Constants::SEPARATION_FACTOR * -1 * (i - 1) * Constants::SCALE)
    );
    _faceColors = {
        {"front", faceColors[0]},
        {"back", faceColors[1]},
        {"left", faceColors[2]},
        {"right", faceColors[3]},
        {"top", faceColors[4]},
        {"bottom", faceColors[5]},
    };

    std::vector<float>* vertices = getVerticesWithColors(faceColors);
    float vv[216];
    for (int i = 0; i < 216; i++) {
        vv[i] = vertices->at(i);
    }
    vertices->clear();
    delete vertices;


    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vv), vv, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // unbind vbo and vao
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

std::vector<float>* Cubelet::getVerticesWithColors(std::vector<std::string> colors) {
    std::vector<float>* vertexVector = new std::vector<float>();
    std::vector<float> faceColor;

    for (int i = 0; i < Constants::VERTEX_COORDINATES.size(); i++) {
        // push scaled axis coordinate
        vertexVector->push_back(Constants::VERTEX_COORDINATES[i] * Constants::SCALE);

        // after every coordinate, push the coordinate's color
        if (i % 3 == 2) {
            if (i < 18) faceColor = Constants::COLOR_TO_RGB.at(_faceColors.at("front"));
            else if (i < 36) faceColor = Constants::COLOR_TO_RGB.at(_faceColors.at("back"));
            else if (i < 54) faceColor = Constants::COLOR_TO_RGB.at(_faceColors.at("left"));
            else if (i < 72) faceColor = Constants::COLOR_TO_RGB.at(_faceColors.at("right"));
            else if (i < 90) faceColor = Constants::COLOR_TO_RGB.at(_faceColors.at("top"));
            else faceColor = Constants::COLOR_TO_RGB.at(_faceColors.at("bottom"));

            vertexVector->insert(vertexVector->end(), faceColor.begin(), faceColor.end());
        }
    }

    return vertexVector;
}

void Cubelet::bindVAO() {
    glBindVertexArray(_vao);
}

void Cubelet::unbindVAO() {
    glBindVertexArray(0);
}

Shader Cubelet::getShader() {
    return _shader;
}

glm::mat4 Cubelet::getModel() {
    return _rotationModel;
}

std::map<std::string, std::string> Cubelet::getFaceColors() {
    return _faceColors;
}

void Cubelet::setModel(glm::mat4 model) {
    _rotationModel = model;
}

void Cubelet::setFaceColors(std::map<std::string, std::string> faceColors) {
    _faceColors = faceColors;
}
