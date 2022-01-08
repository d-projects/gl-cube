#pragma once
#include "RotationHandler.h"

	glm::vec3 RotationHandler::getRotationAxis() {
		switch (type) {
			case FRONT_LEFT:
			case Z_MIDDLE_LEFT:
			case TURN_COUNTERCLOCKWISE:
				return glm::vec3(0.0f, 0.0f, 1.0f);

			case FRONT_RIGHT:
			case Z_MIDDLE_RIGHT:
			case TURN_CLOCKWISE:
				return glm::vec3(0.0f, 0.0f, -1.0f);

			case BACK_LEFT: return glm::vec3(0.0f, 0.0f, -1.0f);
			case BACK_RIGHT: return glm::vec3(0.0f, 0.0f, 1.0f);

			case LEFT_LEFT:
			case X_MIDDLE_LEFT:
			case TURN_UP:
				return glm::vec3(-1.0f, 0.0f, 0.0f);

			case LEFT_RIGHT:
			case X_MIDDLE_RIGHT:
			case TURN_DOWN:
				return glm::vec3(1.0f, 0.0f, 0.0f);

			case RIGHT_LEFT: return glm::vec3(1.0f, 0.0f, 0.0f);
			case RIGHT_RIGHT: return glm::vec3(-1.0f, 0.0f, 0.0f);

			case TOP_LEFT:
			case Y_MIDDLE_LEFT:
			case TURN_RIGHT:
				return glm::vec3(0.0f, 1.0f, 0.0f);

			case TOP_RIGHT:
			case Y_MIDDLE_RIGHT:
			case TURN_LEFT:
				return glm::vec3(0.0f, -1.0f, 0.0f);

			case BOTTOM_LEFT: return glm::vec3(0.0f, -1.0f, 0.0f);
			case BOTTOM_RIGHT: return glm::vec3(0.0f, 1.0f, 0.0f);
		}
	}

	std::vector<std::vector<int>> RotationHandler::getRotationIndices() {
		switch (type) {
			case FRONT_LEFT: return { {0, 0, 0}, {0, 2, 2}, {0} };
			case FRONT_RIGHT: return { {0, 0, 0}, {0, 2, 2}, {1} };
			case BACK_LEFT: return { {2, 0, 2}, {2, 2, 0}, {0} };
			case BACK_RIGHT: return { {2, 0, 2}, {2, 2, 0}, {1} };
			case LEFT_LEFT: return { {2, 0, 0}, {0, 2, 0}, {0} };
			case LEFT_RIGHT: return { {2, 0, 0}, {0, 2, 0}, {1} };
			case RIGHT_LEFT: return { {0, 0, 2}, {2, 2, 2}, {0} };
			case RIGHT_RIGHT: return { {0, 0, 2}, {2, 2, 2}, {1} };
			case BOTTOM_LEFT: return { {2, 2, 2}, {0, 2, 0}, {0} };
			case BOTTOM_RIGHT: return { {2, 2, 2}, {0, 2, 0}, {1} };
			case TOP_LEFT: return { {2, 0, 0}, {0, 0, 2}, {0} };
			case TOP_RIGHT: return { {2, 0, 0}, {0, 0, 2}, {1} };
			case X_MIDDLE_LEFT: return { {2, 0, 1}, {0, 2, 1}, {0} };
			case X_MIDDLE_RIGHT: return { {2, 0, 1}, {0, 2, 1}, {1} };
			case Y_MIDDLE_LEFT: return { {2, 1, 0}, {0, 1, 2}, {0} };
			case Y_MIDDLE_RIGHT: return { {2, 1, 0}, {0, 1, 2}, {1} };
			case Z_MIDDLE_LEFT: return { {1, 0, 0}, {1, 2, 2}, {0} };
			case Z_MIDDLE_RIGHT: return { {1, 0, 0}, {1, 2, 2}, {1} };
		}
	}

	std::map<std::string, std::string> RotationHandler::getFaceSwaps() {
		switch (type) {
			case FRONT_LEFT:
			case Z_MIDDLE_LEFT:
				return { { "front", "front" }, { "back", "back" }, { "left", "top" }, { "right", "bottom" }, { "top", "right" }, { "bottom", "left" } };

			case FRONT_RIGHT:
			case Z_MIDDLE_RIGHT:
				return { { "front", "front" }, { "back", "back" }, { "left", "bottom" }, { "right", "top" }, { "top", "left" }, { "bottom", "right" } };

			case BACK_RIGHT: return { { "front", "front" }, { "back", "back" }, { "left", "top" }, { "right", "bottom" }, { "top", "right" }, { "bottom", "left" } };
			case BACK_LEFT: return { { "front", "front" }, { "back", "back" }, { "left", "bottom" }, { "right", "top" }, { "top", "left" }, { "bottom", "right" } };

			case LEFT_LEFT:
			case X_MIDDLE_LEFT:
				return { { "front", "bottom" }, { "back", "top" }, { "left", "left" }, { "right", "right" }, { "top", "front" }, { "bottom", "back" } };

			case LEFT_RIGHT:
			case X_MIDDLE_RIGHT:
				return { { "front", "top" }, { "back", "bottom" }, { "left", "left" }, { "right", "right" }, { "top", "back" }, { "bottom", "front" } };

			case RIGHT_LEFT: return { { "front", "top" }, { "back", "bottom" }, { "left", "left" }, { "right", "right" }, { "top", "back" }, { "bottom", "front" } };
			case RIGHT_RIGHT: return { { "front", "bottom" }, { "back", "top" }, { "left", "left" }, { "right", "right" }, { "top", "front" }, { "bottom", "back" } };

			case TOP_LEFT:
			case Y_MIDDLE_LEFT:
				return { { "front", "left" }, { "back", "right" }, { "left", "back" }, { "right", "front" }, { "top", "top" }, { "bottom", "bottom" } };

			case TOP_RIGHT:
			case Y_MIDDLE_RIGHT:
				return { { "front", "right" }, { "back", "left" }, { "left", "front" }, { "right", "back" }, { "top", "top" }, { "bottom", "bottom" } };

			case BOTTOM_LEFT: return { { "front", "right" }, { "back", "left" }, { "left", "front" }, { "right", "back" }, { "top", "top" }, { "bottom", "bottom" } };
			case BOTTOM_RIGHT: return { { "front", "left" }, { "back", "right" }, { "left", "back" }, { "right", "front" }, { "top", "top" }, { "bottom", "bottom" } };
		}
	}

	void RotationHandler::transposeMatrix(std::vector<std::vector<Cubelet*>>& matrix) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < i; j++) {
				std::swap(matrix[i][j], matrix[j][i]);
			}
		}
	}

	void RotationHandler::flipMatrixRows(std::vector<std::vector<Cubelet*>>& matrix) {
		for (int i = 0; i < 3 / 2; i++) {
			std::swap(matrix[i], matrix[2 - i]);
		}
	}

	void RotationHandler::flipMatrixCols(std::vector<std::vector<Cubelet*>>& matrix) {
		for (int j = 0; j < 3 / 2; j++) {
			for (int i = 0; i < 3; i++) {
				std::swap(matrix[i][j], matrix[i][2 - j]);
			}
		}
	}

	void RotationHandler::genericReposition(std::vector<std::vector<std::vector<Cubelet*>>>& cubes) {
		std::vector<std::vector<int>> v = getRotationIndices();
		int i_begin = v[0][0]; int i_end = v[1][0]; int i_increment = i_end >= i_begin ? 1 : -1;

		int j_begin = v[0][1]; int j_end = v[1][1]; int j_increment = j_end >= j_begin ? 1 : -1;

		int k_begin = v[0][2]; int k_end = v[1][2]; int k_increment = k_end >= k_begin ? 1 : -1;

		std::vector<std::vector<Cubelet*>> matrix;
		matrix.resize(3);
		for (int i = 0; i < 3; i++) matrix[i].resize(3);

		int matrix_i = 0; int matrix_j = 0;

		// get face matrix
		for (int j = j_begin; j != j_end + j_increment; j += j_increment) {
			for (int i = i_begin; i != i_end + i_increment; i += i_increment) {
				for (int k = k_begin; k != k_end + k_increment; k += k_increment) {
					matrix[matrix_i][matrix_j] = cubes[i][j][k];
					matrix_j++;
					if (matrix_j > 2) {
						matrix_i++;
						matrix_j = 0;
					}
				}
			}
		}

		transposeMatrix(matrix);
		if (v[2][0] == 1) flipMatrixCols(matrix); // clockwise rotation
		else flipMatrixRows(matrix); // counter-clockwise rotation

		matrix_i = 0; matrix_j = 0;
		std::map<std::string, std::string> faceSwaps = getFaceSwaps();

		// set face matrix and face colors
		for (int j = j_begin; j != j_end + j_increment; j += j_increment) {
			for (int i = i_begin; i != i_end + i_increment; i += i_increment) {
				for (int k = k_begin; k != k_end + k_increment; k += k_increment) {
					cubes[i][j][k] = matrix[matrix_i][matrix_j];

					std::map<std::string, std::string> faceColors = cubes[i][j][k]->getFaceColors();
					std::map<std::string, std::string> newFaceColors;
					for (auto fc : faceColors) {
						newFaceColors[fc.first] = faceColors[faceSwaps[fc.first]];
					}
					cubes[i][j][k]->setFaceColors(newFaceColors);

					matrix_j++;
					if (matrix_j > 2) {
						matrix_i++;
						matrix_j = 0;
					}
				}
			}
		}
	}

	void RotationHandler::specificReposition(std::vector<std::vector<std::vector<Cubelet*>>>& cubes, enum Rotation r) {
		enum Rotation temp = type;
		type = r;
		genericReposition(cubes);
		type = temp;
	}

	RotationHandler::RotationHandler() {
		rotationStarted = false;
		rotationCubes = {};
		degreeRotated = 0;
	}

	void RotationHandler::startRotation(enum Rotation r) {
		degreeRotated = 0;
		rotationCubes.clear();
		type = r;
		rotationStarted = true;
	}

	void RotationHandler::handleRotation() {
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

	void RotationHandler::repositionCubes(std::vector<std::vector<std::vector<Cubelet*>>>& cubes) {
		if (type == TURN_RIGHT) {
			specificReposition(cubes, TOP_LEFT);
			specificReposition(cubes, Y_MIDDLE_LEFT);
			specificReposition(cubes, BOTTOM_RIGHT);
		}
		else if (type == TURN_LEFT) {
			specificReposition(cubes, TOP_RIGHT);
			specificReposition(cubes, Y_MIDDLE_RIGHT);
			specificReposition(cubes, BOTTOM_LEFT);
		}
		else if (type == TURN_UP) {
			specificReposition(cubes, LEFT_LEFT);
			specificReposition(cubes, X_MIDDLE_LEFT);
			specificReposition(cubes, RIGHT_RIGHT);
		}
		else if (type == TURN_DOWN) {
			specificReposition(cubes, LEFT_RIGHT);
			specificReposition(cubes, X_MIDDLE_RIGHT);
			specificReposition(cubes, RIGHT_LEFT);
		}
		else if (type == TURN_CLOCKWISE) {
			specificReposition(cubes, FRONT_RIGHT);
			specificReposition(cubes, Z_MIDDLE_RIGHT);
			specificReposition(cubes, BACK_LEFT);
		}
		else if (type == TURN_COUNTERCLOCKWISE) {
			specificReposition(cubes, FRONT_LEFT);
			specificReposition(cubes, Z_MIDDLE_LEFT);
			specificReposition(cubes, BACK_RIGHT);
		}
		else {
			genericReposition(cubes);
		}
	}