#include <glad/glad.h>
#include <glm/glm.hpp>

#include "sprite.h"

class Snake {
public:
	glm::vec2 position, size, velocity;
	glm::vec3 color;
	float rotation;
	
	// constructor
	Snake();
	Snake(glm::vec2 pos, glm::vec2 size, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));

	// draw snake
	virtual void drawSnake(Sprite& sprite);
};