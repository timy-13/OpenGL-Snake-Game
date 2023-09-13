#include "game.h"
#include "objects/sprite.h"
#include "objects/snake.h"

Sprite *sprite;
Snake* snake;



Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
    delete sprite;
    delete snake;
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
    snake = new Snake(glm::vec2(400.0f, 300.0f), SQR_SIZE);

}

void Game::Update(float dt)
{

}

void Game::ProcessInput(float dt)
{
    if (this->State == GAME_ACTIVE) {
        float velocity = SNAKE_VELOCITY * dt;

        if (this->Keys[GLFW_KEY_LEFT]) {
            if (snake->position.x >= 0.0f) {
                snake->position.x -= velocity;
            }
            else {
                this->State = GAME_OVER;
            }
        }
        if (this->Keys[GLFW_KEY_RIGHT]) {
            snake->position.x += velocity;
        }
        if (this->Keys[GLFW_KEY_UP]) {
            snake->position.y += velocity;
        }
        if (this->Keys[GLFW_KEY_DOWN]) {
            snake->position -= velocity;
        }

    }
}

void Game::Render()
{
    if (this->State == GAME_ACTIVE) {
        // sprite->drawSprite(glm::vec2(300.0f, 200.0f), glm::vec2(300.0f, 400.0f), 45.0f, glm::vec3(1.0f, 0.0f, 0.0f));

        snake->drawSnake(*sprite);
    }
    
}