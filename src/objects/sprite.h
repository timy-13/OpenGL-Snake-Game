#ifndef SNAKE_H
#define SNAKE_H

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../shaders/shaders_class.h"


class Sprite {
public:
	// constructor, deconstructor
	Sprite(Shader &shader);
	~Sprite();

	void drawSprite(glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(0.0f, 1.0f, 0.0f));

private:
	Shader shader;
	unsigned int quadVAO;

	void initRenderData();
};

#endif