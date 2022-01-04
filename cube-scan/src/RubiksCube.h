#pragma once
#include "Cubelet.h"
#include "Rotations.h";
#include <vector>
#include <string>
#include <map>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

class RubiksCube {
	std::vector<std::vector<std::vector<Cubelet>>> _cubes;
	std::map<std::string, std::vector<std::vector<std::string>>> _faceColors;
	std::vector<std::string> getCubeletFaceColors(int, int, int);

public:
	RubiksCube();

	/*
		Position of indices on face
	    -----
		0 1 2 -> TOP
		3 4 5
		6 7 8 -> BOTTOM

		For a regular cube orientation:
		-------------------------------
		- front, back, left, and right faces have TOP facing upwards
		- top and bottom faces have TOP pointing towards back face	
	*/
	RubiksCube(std::map<std::string, std::vector<std::vector<std::string>>>);

	//void rotate(enum Rotation);
	void render();

	void test(GLFWwindow* window) {
		Cubelet cube = _cubes[0][0][0];

		//unsigned int _vao, _vbo;
		//Shader _shader = Shader("src/shader.vs", "src/shader.fs");
		//glm::mat4 _rotationModel = glm::mat4(1.0f);

		//Cubelet cube;



		//glGenVertexArrays(1, &_vao);
		//glGenBuffers(1, &_vbo);

		//glBindVertexArray(_vao);
		//glBindBuffer(GL_ARRAY_BUFFER, _vbo);

		//glBufferData(GL_ARRAY_BUFFER, sizeof(vv), vv, GL_STATIC_DRAW);

		//// position attribute
		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		//glEnableVertexAttribArray(0);

		//// color attribute
		//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		//glEnableVertexAttribArray(1);

		//// unbind vbo and vao
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
		//glBindVertexArray(0);


		while (!glfwWindowShouldClose(window)) {
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glEnable(GL_DEPTH_TEST);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


			cube.getShader().use();
			cube.bindVAO();

			glm::mat4 model = glm::mat4(1.0f);
			model = glm::rotate(model, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			model *= cube.getModel();

			glm::mat4 view = glm::mat4(1.0f);
			view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

			glm::mat4 projection = glm::mat4(1.0f);
			projection = glm::perspective(glm::radians(45.0f), 600.0f / 600.0f, 0.1f, 100.0f);

			glm::mat4 transform = projection * view * model;
			cube.getShader().setMat4("transform", transform);

			glDrawArrays(GL_TRIANGLES, 0, 36);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
};

