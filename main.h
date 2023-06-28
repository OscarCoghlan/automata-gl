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

GLuint LoadShaders();

unsigned char * GenImage(char *);

char * StepWorld(char *);

char * GenWorld();

char * Draw(char *, double, double, int, int);

const char basicvert[] = 
"#version 330 core\n"

"// Input vertex data, different for all executions of this shader.\n"
"layout(location = 0) in vec3 vertexPosition_modelspace;\n"
"layout(location = 1) in vec2 vertexUV;\n"
"\n"
"// Output data ; will be interpolated for each fragment.\n"
"out vec2 UV;\n"
"\n"
"// Values that stay constant for the whole mesh.\n"
"//uniform mat4 MVP;\n"
"\n"
"void main(){\n"
"\n"
"    // Output position of the vertex, in clip space : MVP * position\n"
"	gl_Position.xyz = vertexPosition_modelspace;\n"
"  	gl_Position.w = 1.0;\n"
"\n"
"    // UV of the vertex. No special space for this one.\n"
"    UV = vertexUV;\n"
"}\n";

const char basicfrag[] = 
"#version 330 core\n"
"in vec2 UV;\n"
"out vec3 color;\n"
"uniform sampler2D myTextureSampler;\n"
"void main(){\n"
"	color = texture(myTextureSampler, UV).rgb;\n"
"}\n";

