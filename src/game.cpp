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
    snake = new Snake(glm::vec2(255.0f, 200.0f), SQR_SIZE, SNAKE_COLOR, SNAKE_VELOCITY);
    treat = new Treat(glm::vec2(255.0f, 200.0f), SQR_SIZE, TREAT_COLOR);

}

void Game::Update(float dt)
{
    if (this->State == GAME_ACTIVE) {
        snake->move(dt, this->Width, snake->direction);

        if (snake->position.x <= 0 || snake->position.x >= this->Width || snake->position.y <= 0 || snake->position.y >= this->Height) {
            this->Reset();
        }
        
        if (snake->position.x == treat->position.x ) {
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
            snake->direction = "left";
        }
        if (this->Keys[GLFW_KEY_RIGHT]) {
            this->State = GAME_ACTIVE;
            snake->direction = "right";
        }
        if (this->Keys[GLFW_KEY_UP]) {
            this->State = GAME_ACTIVE;
            snake->direction = "up";
        }
        if (this->Keys[GLFW_KEY_DOWN]) {
            this->State = GAME_ACTIVE;
            snake->direction = "down";
        }
    }

    if (this->State == GAME_ACTIVE) {

        if (this->Keys[GLFW_KEY_LEFT]) {
            snake->direction = "left";
        }
        if (this->Keys[GLFW_KEY_RIGHT]) {
            snake->direction = "right";
        }
        if (this->Keys[GLFW_KEY_UP]) {
            snake->direction = "up";
        }
        if (this->Keys[GLFW_KEY_DOWN]) {
            snake->direction = "down";
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