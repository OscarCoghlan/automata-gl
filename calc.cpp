#include "main.h"
#include <cstdlib>
#include <iostream>

char * StepWorld(char * world) {
	char * worldstepped = (char *) calloc(WINDOW_WIDTH * WINDOW_HEIGHT, sizeof(char));

	for (int i = 1; i < WINDOW_HEIGHT - 1; i++) {
		for (int j = 1; j < WINDOW_WIDTH - 1; j++) {
			int accesscoord = i * WINDOW_WIDTH + j;
			for (int m = 0; m < masksize / 2; m++) {
				short xmask = mask[2 * m + 0];
				short ymask = mask[2 * m + 1] * WINDOW_WIDTH;

				if (accesscoord + xmask + ymask < 0 || accesscoord + xmask + ymask >= WINDOW_LENGTH) {
					continue;
				}

				if (world[accesscoord + xmask + ymask] > 0) {
					worldstepped[accesscoord] += 1;
				}

			}

				worldstepped[accesscoord] = rule[worldstepped[accesscoord] * 2 + world[accesscoord]];
		}
	}

	free(world);
	return worldstepped;
}

char * GenWorld() {
	return (char *)calloc(WINDOW_WIDTH * WINDOW_HEIGHT, sizeof(char));
}

char * Draw(char * world, double xpos, double ypos, int xsize, int ysize) {
	xpos = xpos / SCALE;
	ypos = ypos / SCALE;

	ypos = WINDOW_HEIGHT - ypos;

	for (int i = ypos - ysize / 2; i < ypos + ysize / 2; i++) {
		for (int j = xpos - xsize / 2; j < xpos + xsize / 2; j++) {
			world[i * WINDOW_WIDTH + j] = 1;
		}
	}
	return world;
}
