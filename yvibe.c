#include "yvibe.h"

int N = 10; //number of samples per pixel
int R = 20; //radius of the sphere
int bg_min = 2; //number of close samples for being part of the background
int phi = 16; //amount of random subsampling

unsigned char background = 0;
unsigned char foreground = 255;

int c_off[9] = { -1, 0, 1, -1, 1, -1, 0, 1, 0 };

int euclidDist(int x, int y) {
	return x > y ? x - y : y - x;
}

int randint(int i)
{
	int ret, val;
	val = rand();
	ret = val % i;
	return ret;
}
int getRandomNeighbrCoordinate(int x, int length) {
	int rand = randint(9);
	int xn = x + c_off[rand];
	if (xn < 0)
		xn = 0;
	if (xn >= length)
		xn = length - 1;
	return xn;
}

VIBE* vibeCreate(int width, int height) {
	VIBE* xjvibe = (VIBE*)malloc(sizeof(VIBE));
	xjvibe->width = width;
	xjvibe->height = height;
	xjvibe->samples = (unsigned char*)malloc(sizeof(unsigned char) * width * height * N);
	xjvibe->segMap = (unsigned char*)malloc(sizeof(unsigned char) * width * height);
	return xjvibe;
}

int vibeDestroy(VIBE* xjvibe) {
	free(xjvibe->samples);
	free(xjvibe->segMap);
	free(xjvibe);
	return 1;
}
int vibeProcessFirstFrame(VIBE* xjvibe, unsigned char* image) {
	int width = xjvibe->width;
	int height = xjvibe->height;
	unsigned char* samples = xjvibe->samples;
	unsigned char* segMap = xjvibe->segMap;
	int x, y;
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			int index = 0;
			while (index < N) {
				int x_ng, y_ng;
				x_ng = getRandomNeighbrCoordinate(x, width);
				y_ng = getRandomNeighbrCoordinate(y, height);
				samples[y * width * N + x * N + index] = image[y_ng * width
						+ x_ng];
				index++;
			}
		}
	}
	return 1;
}
int vibeUpdate(VIBE* xjvibe, unsigned char* image) {
	int width = xjvibe->width;
	int height = xjvibe->height;
	unsigned char* samples = xjvibe->samples;
	unsigned char* segMap = xjvibe->segMap;
//for each pixel
	int x, y;
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {

			// 1. compare pixel to background
			int count = 0, index = 0, dist = 0;
			while ((count < bg_min) && (index < N)) {
				//Euclidean distance computation
				dist = euclidDist(image[y * width + x],
						samples[y * width * N + x * N + index]);
				if (dist < R) {
					count++;
				}
				index++;
			} //end while

			// 2. Classify pixel and update model
			if (count >= bg_min) {
				//store that image[y*height+x] in background
				segMap[y * width + x] = background;
				// 3. Update current pixel model
				//get random number between 0 and phi-1
				int rand = randint(phi);
				if (rand == 0) {				//random time subsampling
					//replace randomly chosen sample
					rand = randint(N);
					samples[y * width * N + x * N + rand]
							=image[y * width + x];
				}
				// 4. Update neighboring pixel model
				rand = randint(phi);
				if (rand == 0) {					//random subsampling
					//choose neighboring pixel randomly
					int x_ng, y_ng;
					x_ng = getRandomNeighbrCoordinate(x, width);
					y_ng = getRandomNeighbrCoordinate(y, height);
					//replace randomly chosen sample
					rand = randint(N);
					samples[y_ng * width * N + x_ng * N + rand]
							=image[y * width + x];
				}
			} else {					//count<bg_min
				//store that image[y*height+x] in foreground
				segMap[y * width + x] = foreground;
			}
		}
	}
	return 1;
}

unsigned char* vibegetMask(VIBE* xjvibe) {
	return xjvibe->segMap;
}
