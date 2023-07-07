#include <cstddef>

const double SCALE = 2;
const int WINDOW_HEIGHT = 800 / SCALE;
const int WINDOW_WIDTH = 800 / SCALE;
const int WINDOW_LENGTH = WINDOW_HEIGHT * WINDOW_WIDTH;

const int BRUSH_SIZE = 6;

const int BRUSH_SIZE_CLEAR = 12;

const short mask[] = {-1, -1, 0, -1, 1, -1, -1, 0, 1, 0, -1, 1, 0, 1, 1, 1};
const int masksize = 16;

//Conway's game of life
const short rule[] = {0,0, 0,0, 0,1, 1,1, 0,0, 0,0, 0,0, 0,0, 0,0}; 
const size_t rulesize = 18;

//Maze
//const short rule[] = {0,1, 0,1, 0,1, 1,1, 0,1, 0,1, 0,0, 0,0, 0,0}; 
//const size_t rulesize = 18;

//H-Trees
//const short rule[] = {0,1, 1,1, 0,1, 0,1, 0,1, 0,1, 0,1, 0,1, 0,1}; 
//const size_t rulesize = 18;
