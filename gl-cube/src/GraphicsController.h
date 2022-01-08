#pragma once
#include <iostream>
#include "Constants.h"
#include "RubiksCube.h"
#include "Rotations.h"

// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// sleep libraries
#include <chrono>
#include <thread>

class GraphicsController {

    RubiksCube* _rc;
    GLFWwindow* _window;

    void processInput(GLFWwindow* window, RubiksCube* rc);

    void createWindow();

    void render();

public:
    GraphicsController();

    ~GraphicsController();

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    void run();
};
