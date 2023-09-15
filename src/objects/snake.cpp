#include "snake.h"

Snake::Snake() : position(0.0f, 0.0f), size(1.0f, 1.0f), velocity(0.0f), color(1.0f), rotation(0.0f), direction("right") {

}

Snake::Snake(glm::vec2 pos, glm::vec2 size, glm::vec3 color, float velocity, std::string direction, std::string nextDirection)
	: position(pos), size(size), velocity(velocity), color(color), rotation(0.0f), direction(direction), nextDirection(nextDirection) {

}

void Snake::drawSnake(Sprite& sprite) {
	sprite.drawSprite(this->position, this->size, this->rotation, this->color);
}

glm::vec2 Snake::move(float dt, unsigned int window_width, std::string direction = "right", std::string nextDirection = "right") {
	// if (std::fmod(this->position.x, 30.0f) == 0 && std::fmod(this->position.y, 30.0f) == 0) {
		direction = this->nextDirection;
	// }
	// * dt

	if (direction == "left") {
		this->position.x -= this->velocity;
	}
	else if (direction == "right") {
		this->position.x += this->velocity;
	}
	else if (direction == "up") {
		this->position.y -= this->velocity;
	}
	else if (direction == "down") {
		this->position.y += this->velocity;
	}
	else {
		std::cout << "ERROR: DIRECTION";
	}
	
	return this->position;
}

glm::vec2 Snake::grow() {
	this->size.x += 30.0f;

	return this->size;
}