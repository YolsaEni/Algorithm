#ifndef MODULES_YVIBE_H_
#define MODULES_YVIBE_H_

typedef struct yvibe {
	int width;
	int height; //data
	unsigned char* samples;
	unsigned char* segMap;
} VIBE;

VIBE* vibeCreate(int width, int height);
int vibeProcessFirstFrame(VIBE* xjvibe,unsigned char* image);
int vibeUpdate(VIBE* xjvibe, unsigned char* image);
int vibeDestroy(VIBE* xjvibe);

unsigned char* vibegetMask(VIBE* xjvibe);

#endif
