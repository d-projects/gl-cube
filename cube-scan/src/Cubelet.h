#pragma once
#include <vector>
#include "Shader.h"

class Cubelet {
public:

	Shader _shader;
	glm::mat4 _rotationModel;
	unsigned int _vao;

	float* getVerticesWithColors(std::vector<std::string>);

	Cubelet();
	
	// 0: front, 1: back, 2: left, 3: right, 4: top, 5: bottom
	Cubelet(std::vector<std::string>, unsigned int, unsigned int);
	void bindVAO();
	void unbindVAO();
	Shader getShader();
	glm::mat4 getModel();
};
