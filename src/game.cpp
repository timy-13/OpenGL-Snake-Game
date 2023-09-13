#include "game.h"
#include "objects/sprite.h"

Sprite *sprite;

Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
    delete sprite;
}

void Game::Init()
{
    // load shaders
    Shader shader;
    shader.compile("src/shaders/snake.vs", "src/shaders/snake.fs");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    shader.SetMatrix4("projection", projection);
    sprite = new Sprite(shader);
}

void Game::Update(float dt)
{

}

void Game::ProcessInput(float dt)
{

}

void Game::Render()
{
    sprite->drawSprite(glm::vec2(300.0f, 200.0f), glm::vec2(300.0f, 400.0f), 45.0f, glm::vec3(1.0f, 0.0f, 0.0f));
}