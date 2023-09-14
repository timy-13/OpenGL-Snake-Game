#include <glad/glad.h>
#include <glm/glm.hpp>

#include "sprite.h"

class Treat {
public:
	glm::vec2 position, size;
	glm::vec3 color;
	float rotation;

	// constructor
	Treat();
	Treat(glm::vec2 pos, glm::vec2 size, glm::vec3 color = glm::vec3(1.0f));

	// draw snake
	void drawTreat(Sprite& sprite);
	glm::vec2 respawn();

};