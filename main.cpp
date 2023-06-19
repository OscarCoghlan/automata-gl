#include "main.h"
#include <iostream>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}


static const GLfloat g_vertex_buffer_data[] = {
   -1.0f, -1.0f,  0.0f,
    1.0f, -1.0f,  0.0f,
   -1.0f,  1.0f,  0.0f,
   -1.0f,  1.0f,  0.0f,
	1.0f,  1.0f,  0.0f,
	1.0f, -1.0f,  0.0f
};

static const GLfloat g_uv_buffer_data[] = {
    0.0f, 0.0f, 
    1.0f, 0.0f,
    0.0f, 1.0f,
    0.0f, 1.0f,
	1.0f, 1.0f,
	1.0f, 0.0f,
};




int main() {

	if (!glfwInit())
	{
		std::cerr << "Failed to init glfw\n";
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); //4x antialiasing
	//gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World", NULL, NULL);	

	if (!window) {
		std::cerr << "Failed to open glfw window";
        glfwTerminate();
        return -1;
	}

	glfwSetErrorCallback(error_callback);
	glfwSetKeyCallback(window, key_callback);

	glfwMakeContextCurrent(window);

	gladLoadGL();

	printf("OpenGL version: %s\n", glGetString(GL_VERSION));

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// This will identify our vertex buffer
	GLuint vertexbuffer;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	//same for color buffer
	GLuint uvbuffer;
	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);


	GLuint programID = LoadShaders("basic.vert", "basic.frag");

	glClearColor(0.0f, 0.0f, 0.6f, 1.f);

	char * world = GenWorld();

	world[1595] = 1;
	world[1597] = 1;

	unsigned char * data = GenImage(world);

	/*unsigned char data[] = {
		255,185,185,
		255,100,100,
		255,0,0,
		0,0,0,
		185,255,185,
		255,255,255,
		0,255,0,
		0,0,0,
		185,185,255,
		100,100,255,
		0,0,255,
	};*/
	const int height = 3;
	const int width = 3;


	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Give the image to OpenGL
	//glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	//textureID = loadBMP_custom("./land.bmp");

	while (!glfwWindowShouldClose(window))
    {
		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, WINDOW_WIDTH, WINDOW_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        // Render here
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		data[15] += 1;
		data[16] += 1;
		data[17] += 1;

		glUseProgram(programID);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		// glVertexAttribPointer(attribute, size, type, normalised, stride, array buffer offset);
		glVertexAttribPointer(0 , 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 6); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glDisableVertexAttribArray(0);

		// 2nd attribute buffer : texture
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
		// glVertexAttribPointer(attribute, size, type, normalised, stride, array buffer offset);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

        // Swap front and back buffers
		glfwSwapBuffers(window);

        //Poll for and process events
        glfwPollEvents();
		
    }




	glfwTerminate();

	return 0;
}
