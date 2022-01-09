#pragma once
#include <vector>
#include "Cubelet.h"
#include "Constants.h"
#include "glm/glm.hpp";
#include "glm/gtc/type_ptr.hpp"

class RotationHandler {
	float degreeRotated;
	enum Rotation type;

	glm::vec3 getRotationAxis();

	std::vector<std::vector<int>> getRotationIndices();

	std::map<std::string, std::string> getFaceSwaps();

	void transposeMatrix(std::vector<std::vector<Cubelet*>>& matrix);

	void flipMatrixRows(std::vector<std::vector<Cubelet*>>& matrix);

	void flipMatrixCols(std::vector<std::vector<Cubelet*>>& matrix);
	void genericReposition(std::vector<std::vector<std::vector<Cubelet*>>>& cubes);

	void specificReposition(std::vector<std::vector<std::vector<Cubelet*>>>& cubes, enum Rotation r);

public:
	bool rotationStarted;
	std::vector<Cubelet*> rotationCubes;

	RotationHandler();

	void startRotation(enum Rotation r);

	void handleRotation();

	void repositionCubes(std::vector<std::vector<std::vector<Cubelet*>>>& cubes);
};