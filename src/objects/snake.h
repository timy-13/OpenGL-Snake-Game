#ifndef SNAKE_H
#define SNAKE_H

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../shaders/shaders_class.h"


class Snake {
public:
	// constructor, deconstructor
	Snake(Shader &shader);
	~Snake();

	void drawSnake(glm::vec3 color);

private:
	Shader shader;
	unsigned int quadVAO;

	void initRenderData();

	// void move();
};

#endif