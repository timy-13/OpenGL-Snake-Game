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
    // glm::vec2(0.0f, 0.0f)
    std::deque<glm::vec2> lSnake;
    lSnake.push_back(glm::vec2(0.0f, 0.0f));

    snake = new Snake(lSnake, SQR_SIZE, SNAKE_COLOR, SNAKE_VELOCITY);
    treat = new Treat(glm::vec2(60.0f, 210.0f), SQR_SIZE, TREAT_COLOR);

}

void Game::Update(float dt)
{
    if (this->State == GAME_ACTIVE) {
        snake->move(dt, this->Width, snake->direction, snake->nextDirection);

        float posX = snake->lSnake.begin()->x;
        float posY = snake->lSnake.begin()->y;

        if (posX < 0 || posX > (this->Width - SQR_SIZE.x) || posY < 0 || posY >(this->Height - SQR_SIZE.y)) {
            this->Reset();
        }
        
        if (glm::vec2(posX, posY) == treat->position) {
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
    snake->lSnake.clear();
    snake->lSnake.push_back(glm::vec2(400.0f, 300.0f));
}