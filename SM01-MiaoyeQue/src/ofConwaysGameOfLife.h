#pragma once

#include "ofMain.h"

/**
 * @file ofConwaysGameOfLife.cc
 * @author Miaoye Que
 * @brief Conway's Game of Life, assignment #1 for Seeing Machines
 *
 * In this version of Conway's Game of Life, each cell is made of 10 by 10 pixels.
 *
 * Keyboard options:
 * p - Pause / unpause animation;
 * r - Switch graphics to a random pattern;
 * l - Change all cells to live cells;
 * d - Change all cells to dead cells.
 *
 * Press on a cell to toggle its state.
 */

class ofConwaysGameOfLife : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
    
    int w = 400;
    int h = 300;

    // Length of the side of a cell.
    int l = 10;
    
    // -----------------------Starting Patterns -----------------------
    // Generate a random starting pattern.
    void random();
    // A simple methuselah used to test if the game is working.
    // See https://conwaylife.com/wiki/Methuselah.
    void rPentomino();
    
    // Set the grid to either all live or dead cells: true for live, false for
    // dead.
    void setAllCells(bool isAlive);
    
    // Change the color of the cell with top-left corner [x, y] to `color` given
    // an image's pixels.
    void drawCell(int x, int y, ofPixels& pixels, ofColor color);
    
    // Checks if the cell that [x, y] is in is alive.
    int isAlive(int x, int y);
    
    // Get the number of alive neighbors for each cell. Each cell has 8
    // neighbors in total.
    int countNumAliveNeighbors(int x, int y);
    ofImage canvas;
    
    bool paused = false;
};
