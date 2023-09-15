#include <glad/glad.h>
#include <glm/glm.hpp>

#include "sprite.h"

class Snake {
public:
	glm::vec2 position, size;
	glm::vec3 color;
	float velocity;
	float rotation;
	std::string direction;
	std::string nextDirection;

	// constructor
	Snake();
	Snake(glm::vec2 pos, glm::vec2 size, glm::vec3 color = glm::vec3(1.0f), float velocity = 0.0f, std::string direction = "right", std::string nextDirection = "right");

	// draw snake
	virtual void drawSnake(Sprite& sprite);
	glm::vec2 move(float dt, unsigned int window_width, std::string direction, std::string nextDirection);
	glm::vec2 grow();
};