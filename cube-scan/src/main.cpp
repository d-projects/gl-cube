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

// sleep
#include <chrono>
#include <thread>

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window, RubiksCube* rc)
{

    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(TURN_COUNTERCLOCKWISE);

    else if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(TURN_CLOCKWISE);
    
    else if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(FRONT_LEFT);

    else if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(FRONT_RIGHT);

    ////////////////////////////////////////////////////////////////////////////////////

    else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(BACK_LEFT);

    else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(BACK_RIGHT);

    ////////////////////////////////////////////////////////////////////////////////////

    else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(TURN_DOWN);

    else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(TURN_UP);

    else if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(LEFT_LEFT);

    else if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(LEFT_RIGHT);

    ////////////////////////////////////////////////////////////////////////////////////

    else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(RIGHT_LEFT);

    else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(RIGHT_RIGHT);

    ////////////////////////////////////////////////////////////////////////////////////

    else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(TURN_RIGHT);

    else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(TURN_LEFT);

    else if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(TOP_LEFT);

    else if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(TOP_RIGHT);

    ////////////////////////////////////////////////////////////////////////////////////

    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(BOTTOM_LEFT);

    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && !rc->isRotationHappening())
        rc->rotate(BOTTOM_RIGHT);

    ////////////////////////////////////////////////////////////////////////////////////

    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS && !rc->solving())
        rc->solve();
}

int main() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Cube Scan", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /* Fetch openGL function pointers using glew */
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cout << "Error" << std::endl;
    }

    RubiksCube* rc = new RubiksCube(Constants::DEFAULT_FACE_COLORS);


    int i = 0;
    std::vector<std::string> solverMoves;

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        processInput(window, rc);
        if (rc->solving() && !rc->isRotationHappening()) rc->nextSolveMove();
        
        // render the cube
        rc->render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}