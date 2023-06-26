#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <vector>

const double SCALE = 2;
const int WINDOW_HEIGHT = 1000 / SCALE;
const int WINDOW_WIDTH = 1840 / SCALE;
const int WINDOW_LENGTH = WINDOW_HEIGHT * WINDOW_WIDTH;

GLuint LoadShaders(const char *, const char *);

unsigned char * GenImage(char *);

char * StepWorld(char *);

char * GenWorld();

char * Draw(char *, double, double, int, int);

const short mask[] = {-1, -1, 0, -1, 1, -1, -1, 0, 1, 0, -1, 1, 0, 1, 1, 1};
const size_t masksize = 16;

const short rule[] = {0,0, 0,0, 0,1, 1,1, 0,0, 0,0, 0,0, 0,0, 0,0}; 
const size_t rulesize = 18;
