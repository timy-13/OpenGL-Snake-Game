#include <glad/glad.h>
#include <glm/glm.hpp>

#include "sprite.h"
#include <deque>

class Snake {
public:
	std::deque<glm::vec2> lSnake;

	// glm::vec2 position
	glm::vec2 size;
	glm::vec3 color;
	float velocity;
	float rotation;
	int length;
	std::string direction;
	std::string nextDirection;

	// constructor
	Snake();
	Snake(std::deque<glm::vec2> lSnake, glm::vec2 size, glm::vec3 color = glm::vec3(1.0f), float velocity = 0.0f, std::string direction = "right", std::string nextDirection = "right");

	// draw snake
	virtual void drawSnake(Sprite& sprite);
	void move(float dt, unsigned int window_width, std::string direction, std::string nextDirection);
	glm::vec2 grow();
};