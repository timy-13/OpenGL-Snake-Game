#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Board {
public:

	// constructor deconstructor
	Board();
	~Board();

	// initialize board
	void initBoard(unsigned int xLength, unsigned int yLength);

	// draw board
	void drawBoard();

	// square used to draw grid
	void unitSquare(int x, int y);

private:
	unsigned int xLength;
	unsigned int yLength;
};
