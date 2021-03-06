#pragma once
#include <vector>
#include <map>
#include "Shader.h"

class Cubelet {
	Shader _shader;
	glm::mat4 _rotationModel;
	unsigned int _vao;
	std::map<std::string, std::string> _faceColors;
	std::vector<float>* getVerticesWithColors(std::vector<std::string>);


public:
	Cubelet();
	
	// 0: front, 1: back, 2: left, 3: right, 4: top, 5: bottom
	Cubelet(std::vector<std::string>, unsigned int, unsigned int, int, int, int);
	void bindVAO();
	void unbindVAO();
	Shader getShader();
	glm::mat4 getModel();
	void setModel(glm::mat4 model);
	void setFaceColors(std::map<std::string, std::string>);
	std::map<std::string, std::string> getFaceColors();
};
