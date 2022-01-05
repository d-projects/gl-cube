#include "RubiksCube.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Constants.h"


RubiksCube::RubiksCube() {}

RubiksCube::RubiksCube(std::map<std::string, std::vector<std::vector<std::string>>> faceColors) {
	_rh = RotationHandler();
	_faceColors = faceColors;
	_cubes.resize(3);

	int cubeCount = 1;
	std::vector<std::string> cubeletFaceColors;
	for (int i = 0; i < 3; i++) {
		_cubes[i].resize(3);
		for (int j = 0; j < 3; j++) {
			_cubes[i][j].resize(3);
			for (int k = 0; k < 3; k++) {
				cubeletFaceColors = getCubeletFaceColors(i, j, k);
;				_cubes[i][j][k] = Cubelet(cubeletFaceColors, cubeCount, cubeCount, i, j, k);
				cubeCount++;
			}
		}
	}
}

std::vector<std::string> RubiksCube::getCubeletFaceColors(int i, int j, int k) {
	std::vector<std::vector<std::string>> frontFace = _faceColors["front"];
	std::vector<std::vector<std::string>> backFace = _faceColors["back"];
	std::vector<std::vector<std::string>> leftFace = _faceColors["left"];
	std::vector<std::vector<std::string>> rightFace = _faceColors["right"];
	std::vector<std::vector<std::string>> topFace = _faceColors["top"];
	std::vector<std::vector<std::string>> bottomFace = _faceColors["bottom"];

	// i indexes slice (of 9 Cubelets), j indexes row, and k indexes column
	// Order of value indices in map: {front, back, left, right, top, bottom}
	std::map<std::vector<int>, std::vector<std::string>> faceColorMap = {
		{ {0, 0, 0}, {frontFace[0][0], "black", leftFace[0][2], "black", topFace[2][0], "black" } },
		{ {0, 0, 1}, {frontFace[0][1], "black", "black", "black", topFace[2][1], "black"} },
		{ {0, 0, 2}, {frontFace[0][2], "black", "black", rightFace[0][0], topFace[2][2], "black"} },
		{ {0, 1, 0}, {frontFace[1][0], "black", leftFace[1][2], "black", "black", "black"} },
		{ {0, 1, 1}, {frontFace[1][1], "black", "black", "black", "black", "black"} },
		{ {0, 1, 2}, {frontFace[0][0], "black", "black", rightFace[1][0], "black", "black"} },
		{ {0, 2, 0}, {frontFace[0][0], "black", leftFace[2][2], "black", "black", bottomFace[2][1]} },
		{ {0, 2, 1}, {frontFace[0][0], "black", "black", "black", "black", bottomFace[2][2]} },
		{ {0, 2, 2}, {frontFace[0][0], "black", "black", rightFace[2][0], "black", bottomFace[2][0]} },

		{ {1, 0, 0}, {"black", "black", leftFace[0][1], "black", topFace[1][0], "black"} },
		{ {1, 0, 1}, {"black", "black", "black", "black", topFace[1][1], "black"} },
		{ {1, 0, 2}, {"black", "black", "black", rightFace[0][1], topFace[1][1], "black"} },
		{ {1, 1, 0}, {"black", "black", leftFace[1][1], "black", "black", "black"} },
		{ {1, 1, 1}, {"black", "black", "black", "black", "black", "black"} },
		{ {1, 1, 2}, {"black", "black", "black", rightFace[1][1], "black", "black"} },
		{ {1, 2, 0}, {"black", "black", leftFace[2][1], "black", "black", bottomFace[1][2]} },
		{ {1, 2, 1}, {"black", "black", "black", "black", "black", bottomFace[1][1]}},
		{ {1, 2, 2}, {"black", "black", "black", rightFace[2][1], "black", bottomFace[1][0]} },

		{ {2, 0, 0}, {"black", backFace[0][0], leftFace[0][0], "black", topFace[0][0], "black"} },
		{ {2, 0, 1}, {"black", backFace[0][1], "black", "black", topFace[0][1], "black"} },
		{ {2, 0, 2}, {"black", backFace[0][2], "black", rightFace[0][2], topFace[0][2], "black"} },
		{ {2, 1, 0}, {"black", backFace[1][0], leftFace[1][0], "black", "black", "black"} },
		{ {2, 1, 1}, {"black", backFace[1][1], "black", "black", "black", "black"} },
		{ {2, 1, 2}, {"black", backFace[1][2], "black", rightFace[1][2], "black", "black"} },
		{ {2, 2, 0}, {"black", backFace[2][0], leftFace[2][0], "black", "black", bottomFace[0][2]} },
		{ {2, 2, 1}, {"black", backFace[2][1], "black", "black", "black", bottomFace[0][1]} },
		{ {2, 2, 2}, {"black", backFace[2][2], "black", rightFace[2][2], "black", bottomFace[0][0]} },
	};

	return faceColorMap[{i, j, k}];
}


void RubiksCube::rotate(enum Rotation r) {
	_rh.startRotation(r);

	for (int i = 0; i < _cubes.size(); i++) {
		for (int j = 0; j < _cubes[0].size(); j++) {
			for (int k = 0; k < _cubes[0][0].size(); k++) {
				if ((r == FRONT_RIGHT || r == FRONT_LEFT) && i == 0) {
					_rh.rotationCubes.push_back(&_cubes[i][j][k]);
				} else if ((r == BACK_RIGHT || r == BACK_LEFT) && i == 2) {
					_rh.rotationCubes.push_back(&_cubes[i][j][k]);
				} else if ((r == LEFT_RIGHT || r == LEFT_LEFT) && k == 0) {
					_rh.rotationCubes.push_back(&_cubes[i][j][k]);
				} else if ((r == RIGHT_RIGHT || r == RIGHT_LEFT) && k == 2) {
					_rh.rotationCubes.push_back(&_cubes[i][j][k]);
				} else if ((r == TOP_RIGHT || r == TOP_LEFT) && j == 0) {
					_rh.rotationCubes.push_back(&_cubes[i][j][k]);
				} else if ((r == BOTTOM_RIGHT || r == BOTTOM_LEFT) && j == 2) {
					_rh.rotationCubes.push_back(&_cubes[i][j][k]);
				}
			}
		}
	}
}

bool RubiksCube::isRotationHappening() {
	return _rh.rotationStarted;
}

void RubiksCube::render() {
	for (int i = 0; i < _cubes.size(); i++) {
		for (int j = 0; j < _cubes[0].size(); j++) {
			for (int k = 0; k < _cubes[0][0].size(); k++) {
				Cubelet cube = _cubes[i][j][k];
				Shader s = cube.getShader();
				s.use();
				cube.bindVAO();

				glm::mat4 model = glm::mat4(1.0f);
				model = glm::rotate(model, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				model *= cube.getModel();

				glm::mat4 view = glm::mat4(1.0f);
				view = glm::translate(view, glm::vec3(0.0f, 0.0f, -9.0f));

				glm::mat4 projection = glm::mat4(1.0f);
				projection = glm::perspective(glm::radians(45.0f), 600.0f / 600.0f, 0.1f, 100.0f);

				glm::mat4 transform = projection * view * model;
				s.setMat4("transform", transform);

				glDrawArrays(GL_TRIANGLES, 0, 36);
				cube.unbindVAO();
			}
		}
	}

	if (_rh.rotationStarted) {
		_rh.handleRotation();
		if (!_rh.rotationStarted) _rh.repositionCubes(_cubes);
	}
}