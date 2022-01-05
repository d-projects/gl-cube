#pragma once
#include <vector>
#include "Cubelet.h"
#include "Constants.h"
#include "glm/glm.hpp";

struct RotationHandler {
	bool rotationStarted;
	std::vector<Cubelet*> rotationCubes;
	float degreeRotated;
	enum Rotation type;

	RotationHandler() {
		rotationStarted = false;
		rotationCubes = {};
		degreeRotated = 0;
	}

	void startRotation(enum Rotation r) {
		degreeRotated = 0;
		rotationCubes.clear();
		type = r;
		rotationStarted = true;
	}

	glm::vec3 getRotationAxis() {
		switch (type) {
			case FRONT_LEFT: return glm::vec3(0.0f, 0.0f, 1.0f);
			case FRONT_RIGHT: return glm::vec3(0.0f, 0.0f, -1.0f);
			case BACK_LEFT: return glm::vec3(0.0f, 0.0f, -1.0f);
			case BACK_RIGHT: return glm::vec3(0.0f, 0.0f, 1.0f);
			case LEFT_LEFT: return glm::vec3(-1.0f, 0.0f, 0.0f);
			case LEFT_RIGHT: return glm::vec3(1.0f, 0.0f, 0.0f);
			case RIGHT_LEFT: return glm::vec3(1.0f, 0.0f, 0.0f);
			case RIGHT_RIGHT: return glm::vec3(-1.0f, 0.0f, 0.0f);
			case BOTTOM_LEFT: return glm::vec3(0.0f, -1.0f, 0.0f);
			case BOTTOM_RIGHT: return glm::vec3(0.0f, 1.0f, 0.0f);
			case TOP_LEFT: return glm::vec3(0.0f, 1.0f, 0.0f);
			case TOP_RIGHT: return glm::vec3(0.0f, -1.0f, 0.0f);
		}
	}

	void handleRotation() {
		glm::vec3 rotationAxis = getRotationAxis();
		for (auto cube : rotationCubes) {
			glm::mat4 model = cube->getModel();

			glm::mat4 newRotation(1.0f);
			newRotation = glm::rotate(newRotation, glm::radians(Constants::FRAME_ROTATION_DEGREE), rotationAxis);
			model = newRotation * model;
			cube->setModel(model);
		}

		degreeRotated += Constants::FRAME_ROTATION_DEGREE;
		if (degreeRotated == 90)
			rotationStarted = false;
	}

	void frontRightReposition(std::vector<std::vector<std::vector<Cubelet>>>& cubes) {
		std::vector<std::vector<std::vector<Cubelet>>> newCubes = cubes;

		newCubes[0][0][0] = cubes[0][2][0];
		newCubes[0][0][1] = cubes[0][1][0];
		newCubes[0][0][2] = cubes[0][0][0];
		newCubes[0][1][0] = cubes[0][2][1];
		newCubes[0][1][2] = cubes[0][0][1];
		newCubes[0][2][0] = cubes[0][2][2];
		newCubes[0][2][1] = cubes[0][1][2];
		newCubes[0][2][2] = cubes[0][0][2];

		cubes = newCubes;
	}

	void frontLeftReposition(std::vector<std::vector<std::vector<Cubelet>>>& cubes) {
		std::vector<std::vector<std::vector<Cubelet>>> newCubes = cubes;

		newCubes[0][2][0] = cubes[0][0][0];
		newCubes[0][1][0] = cubes[0][0][1];
		newCubes[0][0][0] = cubes[0][0][2];
		newCubes[0][2][1] = cubes[0][1][0];
		newCubes[0][0][1] = cubes[0][1][2];
		newCubes[0][2][2] = cubes[0][2][0];
		newCubes[0][1][2] = cubes[0][2][1];
		newCubes[0][0][2] = cubes[0][2][2];

		cubes = newCubes;
	}

	void backRightReposition(std::vector<std::vector<std::vector<Cubelet>>>& cubes) {
		std::vector<std::vector<std::vector<Cubelet>>> newCubes = cubes;

		newCubes[2][0][2] = cubes[2][2][2];
		newCubes[2][0][1] = cubes[2][1][2];
		newCubes[2][0][0] = cubes[2][0][2];
		newCubes[2][1][2] = cubes[2][2][1];
		newCubes[2][1][0] = cubes[2][0][1];
		newCubes[2][2][2] = cubes[2][2][0];
		newCubes[2][2][1] = cubes[2][1][0];
		newCubes[2][2][0] = cubes[2][0][0];

		cubes = newCubes;
	}

	void backLeftReposition(std::vector<std::vector<std::vector<Cubelet>>>& cubes) {
		std::vector<std::vector<std::vector<Cubelet>>> newCubes = cubes;

		newCubes[2][2][2] = cubes[2][0][2];
		newCubes[2][1][2] = cubes[2][0][1];
		newCubes[2][0][2] = cubes[2][0][0];
		newCubes[2][2][1] = cubes[2][1][2];
		newCubes[2][0][1] = cubes[2][1][0];
		newCubes[2][2][0] = cubes[2][2][2];
		newCubes[2][1][0] = cubes[2][2][1];
		newCubes[2][0][0] = cubes[2][2][0];

		cubes = newCubes;
	}

	void leftRightReposistion(std::vector<std::vector<std::vector<Cubelet>>>& cubes) {
		std::vector<std::vector<std::vector<Cubelet>>> newCubes = cubes;

		newCubes[2][0][0] = cubes[2][2][0];
		newCubes[1][0][0] = cubes[2][1][0];
		newCubes[0][0][0] = cubes[2][0][0];
		newCubes[2][1][0] = cubes[1][2][0];
		newCubes[0][1][0] = cubes[1][0][0];
		newCubes[2][2][0] = cubes[0][2][0];
		newCubes[1][2][0] = cubes[0][1][0];
		newCubes[0][2][0] = cubes[0][0][0];

		cubes = newCubes;
	}

	void leftLeftReposition(std::vector<std::vector<std::vector<Cubelet>>>& cubes) {
		std::vector<std::vector<std::vector<Cubelet>>> newCubes = cubes;

		newCubes[2][2][0] = cubes[2][0][0];
		newCubes[2][1][0] =	cubes[1][0][0];
		newCubes[2][0][0] =	cubes[0][0][0];
		newCubes[1][2][0] =	cubes[2][1][0];
		newCubes[1][0][0] =	cubes[0][1][0];
		newCubes[0][2][0] =	cubes[2][2][0];
		newCubes[0][1][0] =	cubes[1][2][0];
		newCubes[0][0][0] =	cubes[0][2][0];

		cubes = newCubes;
	}

	void rightRightReposistion(std::vector<std::vector<std::vector<Cubelet>>>& cubes) {
		std::vector<std::vector<std::vector<Cubelet>>> newCubes = cubes;

		newCubes[0][0][2] = cubes[0][2][2];
		newCubes[1][0][2] = cubes[0][1][2];
		newCubes[2][0][2] = cubes[0][0][2];
		newCubes[0][1][2] = cubes[1][2][2];
		newCubes[2][1][2] = cubes[1][0][2];
		newCubes[0][2][2] = cubes[2][2][2];
		newCubes[1][2][2] = cubes[2][1][2];
		newCubes[2][2][2] = cubes[2][0][2];

		cubes = newCubes;
	}

	void rightLeftReposition(std::vector<std::vector<std::vector<Cubelet>>>& cubes) {
		std::vector<std::vector<std::vector<Cubelet>>> newCubes = cubes;

		newCubes[0][2][2] = cubes[0][0][2];
		newCubes[0][1][2] = cubes[1][0][2];
		newCubes[0][0][2] = cubes[2][0][2];
		newCubes[1][2][2] = cubes[0][1][2];
		newCubes[1][0][2] = cubes[2][1][2];
		newCubes[2][2][2] = cubes[0][2][2];
		newCubes[2][1][2] = cubes[1][2][2];
		newCubes[2][0][2] = cubes[2][2][2];

		cubes = newCubes;
	}

	void topRightReposition(std::vector<std::vector<std::vector<Cubelet>>>& cubes) {
		std::vector<std::vector<std::vector<Cubelet>>> newCubes = cubes;

		newCubes[2][0][0] = cubes[0][0][0];
		newCubes[2][0][1] = cubes[1][0][0];
		newCubes[2][0][2] = cubes[2][0][0];
		newCubes[1][0][0] = cubes[0][0][1];
		newCubes[1][0][2] = cubes[2][0][1];
		newCubes[0][0][0] = cubes[0][0][2];
		newCubes[0][0][1] = cubes[1][0][2];
		newCubes[0][0][2] = cubes[2][0][2];

		cubes = newCubes;
	}

	void topLeftReposition(std::vector<std::vector<std::vector<Cubelet>>>& cubes) {
		std::vector<std::vector<std::vector<Cubelet>>> newCubes = cubes;

		newCubes[0][0][0] = cubes[2][0][0];
		newCubes[1][0][0] = cubes[2][0][1];
		newCubes[2][0][0] = cubes[2][0][2];
		newCubes[0][0][1] = cubes[1][0][0];
		newCubes[2][0][1] = cubes[1][0][2];
		newCubes[0][0][2] = cubes[0][0][0];
		newCubes[1][0][2] = cubes[0][0][1];
		newCubes[2][0][2] = cubes[0][0][2];

		cubes = newCubes;
	}

	void bottomRightReposition(std::vector<std::vector<std::vector<Cubelet>>>& cubes) {
		std::vector<std::vector<std::vector<Cubelet>>> newCubes = cubes;

		newCubes[2][2][2] = cubes[0][2][2];
		newCubes[2][2][1] = cubes[1][2][2];
		newCubes[2][2][0] = cubes[2][2][2];
		newCubes[1][2][2] = cubes[0][2][1];
		newCubes[1][2][0] = cubes[2][2][1];
		newCubes[0][2][2] = cubes[0][2][0];
		newCubes[0][2][1] = cubes[1][2][0];
		newCubes[0][2][0] = cubes[2][2][0];

		cubes = newCubes;
	}

	void bottomLeftReposition(std::vector<std::vector<std::vector<Cubelet>>>& cubes) {
		std::vector<std::vector<std::vector<Cubelet>>> newCubes = cubes;

		newCubes[0][2][2] = cubes[2][2][2];
		newCubes[1][2][2] = cubes[2][2][1];
		newCubes[2][2][2] = cubes[2][2][0];
		newCubes[0][2][1] = cubes[1][2][2];
		newCubes[2][2][1] = cubes[1][2][0];
		newCubes[0][2][0] = cubes[0][2][2];
		newCubes[1][2][0] = cubes[0][2][1];
		newCubes[2][2][0] = cubes[0][2][0];

		cubes = newCubes;
	}

	void repositionCubes(std::vector<std::vector<std::vector<Cubelet>>>& cubes) {
		switch (type) {
			case FRONT_RIGHT: frontRightReposition(cubes); break;
			case FRONT_LEFT: frontLeftReposition(cubes); break;
			case BACK_RIGHT: backRightReposition(cubes); break;
			case BACK_LEFT: backLeftReposition(cubes); break;
			case LEFT_RIGHT: leftRightReposistion(cubes); break;
			case LEFT_LEFT: leftLeftReposition(cubes); break;
			case RIGHT_RIGHT: rightRightReposistion(cubes); break;
			case RIGHT_LEFT: rightLeftReposition(cubes); break;
			case TOP_RIGHT: topRightReposition(cubes); break;
			case TOP_LEFT: topLeftReposition(cubes); break;
			case BOTTOM_RIGHT: bottomRightReposition(cubes); break;
			case BOTTOM_LEFT: bottomLeftReposition(cubes); break;
		}
	}
};