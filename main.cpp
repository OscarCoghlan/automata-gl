#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>


int main() {
	if (!glfwInit())
	{
		// Initialization failed
		std::cout << "AH";
	}

	glfwTerminate();

	return 0;
}
