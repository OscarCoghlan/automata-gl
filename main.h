#include "glad/glad.h"
#include "GLFW/glfw3.h"

const int WINDOW_HEIGHT = 640;
const int WINDOW_WIDTH = 640;

GLuint LoadShaders(const char *, const char *);

unsigned char * GenImage(char *);

char * StepWorld(char *);

char * GenWorld();
