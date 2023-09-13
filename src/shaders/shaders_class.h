#ifndef SHADER_H
#define SHADER_H

#pragma once

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

class Shader {
public:
	unsigned int ID;

	// constructor for vertex and fragment shaders
	// Shader(const char* vPath, const char* fpath);

	Shader();

	void    SetVector3f(const char* name, float x, float y, float z, bool useShader = false);
	void    SetVector3f(const char* name, const glm::vec3& value, bool useShader = false);
	void    SetMatrix4(const char* name, const glm::mat4& matrix, bool useShader = false);

	void compile(const char* vPath, const char* fpath);

	// sets shader as active
	Shader &use();

private:
	void checkCompileErrors(unsigned int shader, std::string type) {
		int success;
		char infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
	}
};

#endif