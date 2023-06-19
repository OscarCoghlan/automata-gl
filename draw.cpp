#include "main.h"
#include <cstdlib>
#include <iostream>


unsigned char * GenImage(char * input) {
	std::cout << "AWEJHI\n";
	unsigned char * image = (unsigned char *) calloc( (WINDOW_WIDTH + 1) * WINDOW_HEIGHT * 3, sizeof(unsigned char));
	
	for (int i = 0; i < WINDOW_HEIGHT; i++) {
		for (int j = 0; j < WINDOW_WIDTH; j++) {
			image[(i * (WINDOW_WIDTH + 1) + j) * 3 + 0] = input[i * WINDOW_WIDTH + j] * 255;
			image[(i * (WINDOW_WIDTH + 1) + j) * 3 + 1] = input[i * WINDOW_WIDTH + j] * 255;
			image[(i * (WINDOW_WIDTH + 1) + j) * 3 + 2] = input[i * WINDOW_WIDTH + j] * 255;
		}
	}
	return image;
}
