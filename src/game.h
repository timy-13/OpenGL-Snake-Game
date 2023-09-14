#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaders/shaders_class.h"
#include "objects/sprite.h"

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

const glm::vec2 SQR_SIZE(30.0f, 30.0f);
const glm::vec3 SNAKE_COLOR(0.0f, 1.0f, 0.0f);
const float SNAKE_VELOCITY(150.0f);

const glm::vec3 TREAT_COLOR(1.0f, 0.0f, 0.0f);

class Game
{
public:
    // game state
    GameState    State;
    bool         Keys[1024];
    unsigned int Width, Height;

    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();

    // initialize game state (load all shaders/textures/levels)
    void Init();

    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
    void Reset();
};

#endif