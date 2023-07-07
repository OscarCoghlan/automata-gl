#include "main.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "config.h"
#include <unistd.h>
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

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH * SCALE, WINDOW_HEIGHT * SCALE, "Glfw Window", NULL, NULL);	

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


	GLuint programID = LoadShaders();

	glClearColor(0.0f, 0.0f, 0.6f, 1.f);


	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	char * world = GenWorld();

	unsigned char * data;

	data = GenImage(world);
	int count = 0;

	double xpos, ypos;

	while (!glfwWindowShouldClose(window))
    {
		
		glfwGetCursorPos(window, &xpos, &ypos);
		int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
		if (state == GLFW_PRESS)
		{
			Draw(world, xpos, ypos, BRUSH_SIZE, BRUSH_SIZE, 1);
		}
		int state2 = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
		if (state2 == GLFW_PRESS)
		{
			Draw(world, xpos, ypos, BRUSH_SIZE_CLEAR, BRUSH_SIZE_CLEAR, 0);
		}

#ifdef DEBUG
		if (count % 144 == 0) {
			std::cout << "1 sec\n";
		}
		std::cout << "Cursor: (" << xpos <<", " << ypos <<")\n";
#endif
		count += 1;
		//logic
		world = StepWorld(world);

		data = GenImage(world);


		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, WINDOW_WIDTH, WINDOW_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		free(data);
        // Render here
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
