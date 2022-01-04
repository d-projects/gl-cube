#include <iostream>
#include "Constants.h"
#include "RubiksCube.h"

// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;

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

    /* Fetch openGL function pointers using glew */
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cout << "Error" << std::endl;
    }

    RubiksCube* rc = new RubiksCube(Constants::DEFAULT_FACE_COLORS);
    //RubiksCube* rc = new RubiksCube();

    rc->test(window);
    //while (!glfwWindowShouldClose(window)) {
    //    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //    glEnable(GL_DEPTH_TEST);
    //    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //    // input check will go here
    //    // ....
    //    
    //    // render the cube
    //    rc->test();

    //    //rc->render();

    //    glfwSwapBuffers(window);
    //    glfwPollEvents();
    //}

    glfwTerminate();
}