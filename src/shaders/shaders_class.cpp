#include "shaders_class.h"

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const char* vPath, const char* fPath) {

	// retrieve shader source code from file
	// --------------------------------------
	std::string vCode;
	std::string fCode;
	std::ifstream vsFile;
	std::ifstream fsFile;

	vsFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fsFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		// open files
		vsFile.open(vPath);
		fsFile.open(fPath);
		std::stringstream vsStream, fsStream;

		// read file buffer contents into streams
		vsStream << vsFile.rdbuf();
		fsStream << fsFile.rdbuf();

		// close file
		vsFile.close();
		fsFile.close();
		
		// convert stream into string
		vCode = vsStream.str();
		fCode = fsStream.str();
	}
	catch (std::ifstream::failure& e) {
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
	}

	const char* vsCode = vCode.c_str();
	const char* fsCode = fCode.c_str();

	// compile shaders
	// ----------------
	unsigned int vs, fs;

	// vertex shader
	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vsCode, NULL);
	glCompileShader(vs);
	checkCompileErrors(vs, "VERTEX");

	// fragment shader
	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fsCode, NULL);
	glCompileShader(fs);
	checkCompileErrors(fs, "FRAGMENT");

	// shader program
	ID = glCreateProgram();
	glAttachShader(ID, vs);
	glAttachShader(ID, fs);
	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAM");

	// delete shaders since they have been linked
	glDeleteShader(vs);
	glDeleteShader(fs);
}

void Shader::use() {
	glUseProgram(ID);
}