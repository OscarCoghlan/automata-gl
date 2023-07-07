#include <cstddef>

const double SCALE = 4;
const int WINDOW_HEIGHT = 800 / SCALE;
const int WINDOW_WIDTH = 800 / SCALE;
const int WINDOW_LENGTH = WINDOW_HEIGHT * WINDOW_WIDTH;

const int BRUSH_SIZE = 6;

const int BRUSH_SIZE_CLEAR = 12;

//regular neighbourhood
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

//Wall
//const short rule[] = {0,0, 0,0, 0,1, 0,1, 1,1, 1,1, 1,0, 1,0, 1,0};
//const size_t rulesize = 18;

//For QR world (irregular neighbourhood)
//const int rule[] = {0, 0, 0, 0, 1, 1, 0, 1, 1, 0};
//const size_t rulesize = 10;

//QR world square
//const int mask[] = {0,1,-1,0,1,0,0,-1};
//const int masksize = 8;

//QR world diagonal
//const int mask[] = {1,1,-1,-1,1,-1,-1,1};
//const int masksize = 8;

