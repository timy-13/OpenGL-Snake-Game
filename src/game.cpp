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
    shader.compile("src/shaders/snake.vs", "src/shaders/snake.fs");

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
    snake->drawSnake();
}