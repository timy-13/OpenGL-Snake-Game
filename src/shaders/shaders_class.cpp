#include "shaders_class.h"

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader() {

}

void Shader::compile(const char* vPath, const char* fPath) {

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
	this->ID = glCreateProgram();
	glAttachShader(this->ID, vs);
	glAttachShader(this->ID, fs);
	glLinkProgram(this->ID);
	checkCompileErrors(this->ID, "PROGRAM");

	// delete shaders since they have been linked
	glDeleteShader(vs);
	glDeleteShader(fs);
}

Shader &Shader::use() {
	glUseProgram(this->ID);
	return *this;
}

void Shader::SetVector3f(const char* name, float x, float y, float z, bool useShader)
{
	if (useShader)
		this->use();
	glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
}
void Shader::SetVector3f(const char* name, const glm::vec3& value, bool useShader)
{
	if (useShader)
		this->use();
	glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z);
}

void Shader::SetMatrix4(const char* name, const glm::mat4& matrix, bool useShader)
{
	if (useShader)
		this->use();
	glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, false, glm::value_ptr(matrix));
}
