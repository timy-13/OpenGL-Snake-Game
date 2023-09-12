#include "game.h"
#include "objects/snake.h"

Snake *snake;

Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
    delete snake;
}

void Game::Init()
{
    // load shaders
    Shader shader;
    shader.compile("shaders/snake.vs", "shaders/snake.fs");

    snake = new Snake(shader);
}

void Game::Update(float dt)
{

}

void Game::ProcessInput(float dt)
{

}

void Game::Render()
{
    snake->drawSnake(glm::vec3(1.0f, 0.5f, 0.2f));
}