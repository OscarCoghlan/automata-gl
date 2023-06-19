#include "main.h"
#include <cstdlib>

char * StepWorld(char * world) {
	for (int i = 0; i < WINDOW_HEIGHT; i++) {
		for (int j = 0; j < WINDOW_WIDTH; j++) {
			int activecell = i * WINDOW_WIDTH + j;

		}
	}
}

char * GenWorld() {
	return (char *)calloc(WINDOW_WIDTH * WINDOW_HEIGHT, sizeof(char));
}





