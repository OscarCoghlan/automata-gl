#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <vector>

const double SCALE = 4;
const int WINDOW_HEIGHT = 800 / SCALE;
const int WINDOW_WIDTH = 800 / SCALE;
const int WINDOW_LENGTH = WINDOW_HEIGHT * WINDOW_WIDTH;

const int BRUSH_SIZE = 6;

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

GLuint LoadShaders(const char *, const char *);

unsigned char * GenImage(char *);

char * StepWorld(char *);

char * GenWorld();

char * Draw(char *, double, double, int, int);

