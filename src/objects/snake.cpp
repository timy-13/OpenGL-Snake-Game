#include "snake.h"
#include "../shaders/shaders_class.h"

// configures quad VAO
Snake::Snake(Shader &shader) {
    this->shader = shader;
    this->initRenderData();
}

Snake::~Snake() {
    glDeleteVertexArrays(1, &this->quadVAO);
}

void Snake::drawSnake() {
    this->shader.use();

    // this->shader.SetVector3f("spriteColor", color);

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

void Snake::initRenderData() {
    // configure VAO/VBO
    unsigned int VBO;

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    };

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

// void Snake::move()