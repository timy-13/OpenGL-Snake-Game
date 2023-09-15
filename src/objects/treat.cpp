#include "treat.h"

Treat::Treat() : position(0.0f, 0.0f), size(1.0f, 1.0f), color(1.0f), rotation(0.0f) {

}

Treat::Treat(glm::vec2 pos, glm::vec2 size, glm::vec3 color)
	: position(pos), size(size), color(color), rotation(0.0f) {

}

void Treat::drawTreat(Sprite& sprite) {
	sprite.drawSprite(this->position, this->size, this->rotation, this->color);
}

glm::vec2 Treat::respawn() {
	int x, y;

	std::srand(time(0));
	x = (rand() % 17);
	y = (rand() % 15);

	this->position.x = x * 30.0f;
	this->position.y = y * 30.0f;

	return this->position;
}