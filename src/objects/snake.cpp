#include "snake.h"

Snake::Snake() : lSnake(), size(1.0f, 1.0f), velocity(0.0f), length(1), color(1.0f), rotation(0.0f), direction("right") {

}

Snake::Snake(std::deque<glm::vec2> lSnake, glm::vec2 size, glm::vec3 color, float velocity, std::string direction, std::string nextDirection)
	: lSnake(lSnake), size(size), velocity(velocity), color(color), rotation(0.0f), direction(direction), nextDirection(nextDirection) {

}

void Snake::drawSnake(Sprite& sprite) {	
	std::deque<glm::vec2>::iterator it;
	for (it = this->lSnake.begin(); it != this->lSnake.end(); ++it) {
		sprite.drawSprite(*it, this->size, this->rotation, this->color);
	}
	
}

void Snake::move(float dt, unsigned int window_width, std::string direction = "right", std::string nextDirection = "right") {
	direction = this->nextDirection;

	if (direction == "left") {
		this->lSnake.begin()->x -= this->velocity;
	}
	else if (direction == "right") {
		this->lSnake.begin()->x += this->velocity;
	}
	else if (direction == "up") {
		this->lSnake.begin()->y -= this->velocity;
	}
	else if (direction == "down") {
		this->lSnake.begin()->y += this->velocity;
	}
	else {
		std::cout << "ERROR: DIRECTION";
	}
	
	// return this->position;
}

glm::vec2 Snake::grow() {
	this->size.x += 30.0f;

	return this->size;
}