#include "snake.h"

Snake::Snake() : lSnake(), size(1.0f, 1.0f), color(1.0f), velocity(0.0f), length(1), rotation(0.0f), direction("right") {

}

Snake::Snake(std::deque<glm::vec2> lSnake, glm::vec2 size, glm::vec3 color, float velocity, int length, float rotation, std::string direction)
	: lSnake(lSnake), size(size), color(color), velocity(velocity), length(length), rotation(0.0f), direction(direction) {

}

void Snake::drawSnake(Sprite& sprite) {	
	std::deque<glm::vec2>::iterator it;
	for (it = this->lSnake.begin(); it != this->lSnake.end(); ++it) {
		sprite.drawSprite(*it, this->size, this->rotation, this->color);
	}
	
}

void Snake::move(float dt, unsigned int window_width, std::string direction = "right") {

	float xPos = this->lSnake.begin()->x;
	float yPos = this->lSnake.begin()->y;
	this->lastSqr = glm::vec2(this->lSnake.back());

	this->lSnake.pop_back();

	

	if (direction == "left") {
		this->lSnake.push_front(glm::vec2(xPos - this->velocity, yPos));
	}
	else if (direction == "right") {
		this->lSnake.push_front(glm::vec2(xPos + this->velocity, yPos));
	}
	else if (direction == "up") {
		this->lSnake.push_front(glm::vec2(xPos, yPos - this->velocity));
	}
	else if (direction == "down") {
		this->lSnake.push_front(glm::vec2(xPos, yPos + this->velocity));
	}
	else {
		std::cout << "ERROR: DIRECTION";
	}
	
}

void Snake::grow() {
	this->lSnake.push_back(this->lastSqr);
	this->length++;
}