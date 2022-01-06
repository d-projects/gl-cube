#pragma once
#include "Cubelet.h"
#include "Rotations.h";
#include <vector>
#include <string>
#include <map>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include "RotationHandler.h"

class RubiksCube {
	std::vector<std::vector<std::vector<Cubelet*>>> _cubes;
	RotationHandler _rh;
	bool _solving;

	std::vector<std::string> getCubeletInitialFaceColors(std::map<std::string, std::vector<std::vector<std::string>>>, int, int, int);

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

	void rotate(enum Rotation);
	void render();
	bool isRotationHappening();
	std::vector<std::string> getOrderedFaceColors();
	void solve();
};

