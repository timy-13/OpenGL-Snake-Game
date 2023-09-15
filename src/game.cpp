#include "game.h"
#include "objects/sprite.h"
#include "objects/snake.h"
#include "objects/treat.h"

Sprite *sprite;
Snake* snake;
Treat* treat;


Game::Game(unsigned int width, unsigned int height)
    : State(GAME_MENU), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
    delete sprite;
    delete snake;
    delete treat;
}

void Game::Init()
{
    // load shaders
    Shader shader;
    shader.compile("src/shaders/snake.vs", "src/shaders/snake.fs");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    shader.use();
    shader.SetMatrix4("projection", projection);
    sprite = new Sprite(shader);

    // configure snake object
    snake = new Snake(glm::vec2(0.0f, 0.0f), SQR_SIZE, SNAKE_COLOR, SNAKE_VELOCITY);
    treat = new Treat(glm::vec2(60.0f, 210.0f), SQR_SIZE, TREAT_COLOR);

}

void Game::Update(float dt)
{
    if (this->State == GAME_ACTIVE) {
        snake->move(dt, this->Width, snake->direction, snake->nextDirection);

        if (snake->position.x < 0 || snake->position.x > (this->Width - SQR_SIZE.x) || snake->position.y < 0 || snake->position.y >(this->Height - SQR_SIZE.y)) {
            this->Reset();
        }
        
        if (snake->position == treat->position) {
            treat->respawn();
            treat->drawTreat(*sprite);
        }
    }
    
}

void Game::ProcessInput(float dt)
{
    if (this->State == GAME_MENU) {
        if (this->Keys[GLFW_KEY_LEFT]) {
            this->State = GAME_ACTIVE;
            snake->nextDirection = "left";
        }
        if (this->Keys[GLFW_KEY_RIGHT]) {
            this->State = GAME_ACTIVE;
            snake->nextDirection = "right";
        }
        if (this->Keys[GLFW_KEY_UP]) {
            this->State = GAME_ACTIVE;
            snake->nextDirection = "up";
        }
        if (this->Keys[GLFW_KEY_DOWN]) {
            this->State = GAME_ACTIVE;
            snake->nextDirection = "down";
        }
    }

    if (this->State == GAME_ACTIVE) {

        if (this->Keys[GLFW_KEY_LEFT]) {
            snake->nextDirection = "left";
        }
        if (this->Keys[GLFW_KEY_RIGHT]) {
            snake->nextDirection = "right";
        }
        if (this->Keys[GLFW_KEY_UP]) {
            snake->nextDirection = "up";
        }
        if (this->Keys[GLFW_KEY_DOWN]) {
            snake->nextDirection = "down";
        }

    }
}

void Game::Render()
{
    if (this->State == GAME_ACTIVE) {
        treat->drawTreat(*sprite);
        snake->drawSnake(*sprite);
    }
    
}

void Game::Reset() {
    this->State = GAME_MENU;
    snake->size = SQR_SIZE;
    snake->position = glm::vec2(400.0f, 300.0f);
}