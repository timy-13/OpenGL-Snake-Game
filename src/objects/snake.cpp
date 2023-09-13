#include "snake.h"

Snake::Snake() : position(0.0f, 0.0f), size(1.0f, 1.0f), velocity(0.0f), color(1.0f), rotation(0.0f) {

}

Snake::Snake(glm::vec2 pos, glm::vec2 size, glm::vec3 color, glm::vec2 velocity)
	: position(pos), size(size), velocity(velocity), color(color), rotation(0.0f) {

}

void Snake::drawSnake(Sprite& sprite) {
	sprite.drawSprite(this->position, this->size, this->rotation, this->color);
}