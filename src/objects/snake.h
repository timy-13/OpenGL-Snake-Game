#include <glad/glad.h>
#include <glm/glm.hpp>

#include "sprite.h"
#include <deque>

class Snake {
public:
	std::deque<glm::vec2> lSnake;

	// glm::vec2 position
	glm::vec2 size;
	glm::vec2 lastSqr;
	glm::vec3 color;
	float velocity;
	float rotation;
	int length;
	std::string direction;
	

	// constructor
	Snake();
	Snake(std::deque<glm::vec2> lSnake, glm::vec2 size, glm::vec3 color = glm::vec3(1.0f), float velocity = 0.0f, int length = 1, float rotation = 0.0f, std::string direction = "right");

	// draw snake
	virtual void drawSnake(Sprite& sprite);
	void move(float dt, unsigned int window_width, std::string direction);
	void grow();
};