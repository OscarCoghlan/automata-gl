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


int main() {

	if (!glfwInit())
	{
		std::cerr << "Failed to init glfw\n";
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); //4x antialiasing
	//gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);	

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


	GLuint programID = LoadShaders("basic.vert", "basic.frag");

	glClearColor(0.0f, 0.0f, 0.6f, 0.8f);

	while (!glfwWindowShouldClose(window))
    {
		
        // Render here
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(programID);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(0 , 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 6); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glDisableVertexAttribArray(0);

        // Swap front and back buffers
		glfwSwapBuffers(window);

        //Poll for and process events
        glfwPollEvents();
		
    }




	glfwTerminate();

	return 0;
}
