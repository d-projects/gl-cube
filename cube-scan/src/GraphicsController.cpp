#pragma once
#include "GraphicsController.h"

    void GraphicsController::processInput(GLFWwindow* window, RubiksCube* rc) {

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

    void GraphicsController::createWindow() {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        _window = glfwCreateWindow(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, Constants::TITLE, NULL, NULL);
        if (!_window)
        {
            glfwTerminate();
            std::cout << "GLFW window could not be created";
            return;
        }

        glfwMakeContextCurrent(_window);
        glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

        GLenum err = glewInit();
        if (err != GLEW_OK) {
            std::cout << "Error initializing Glew" << std::endl;
            return;
        }
    }

    void GraphicsController::render() {
        _rc = new RubiksCube(Constants::DEFAULT_FACE_COLORS);

        while (!glfwWindowShouldClose(_window)) {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glEnable(GL_DEPTH_TEST);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            processInput(_window, _rc);
            if (_rc->solving() && !_rc->isRotationHappening()) _rc->nextSolveMove();

            // render the cube
            _rc->render();

            glfwSwapBuffers(_window);
            glfwPollEvents();
        }
    }

    GraphicsController::GraphicsController() {
        if (!glfwInit()) {
            std::cout << "GLFW failed to initialize" << std::endl;
        }
    }

    GraphicsController::~GraphicsController() {
        glfwTerminate();

        delete _window;
        delete _rc;
    }

    void GraphicsController::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    void GraphicsController::run() {
        createWindow();
        render();
    }
