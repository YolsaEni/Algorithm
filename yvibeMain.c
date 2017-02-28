#include "yvibe.h"

#include <stdio.h>

#define IS_OPENCV

#ifdef IS_OPENCV
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#endif

int imageProcess() {
	int s32SubSampleT = 1, i,j;

#ifdef IS_OPENCV
	CvCapture* pCapture = NULL;
	IplImage* gray = NULL;
	IplImage* mask = NULL;
	IplImage* tmp = NULL;

	IplImage* fg = NULL;
	IplImage *frame = 0;

	cvNamedWindow("input", 1);
	cvNamedWindow("foreground", 1);
//	cvNamedWindow("foreground", 1);
//	cvNamedWindow("background", 1);

	cvMoveWindow("input", 0, 0);
	cvMoveWindow("foreground", 360, 0);
//	cvMoveWindow("background", 0, 288);
//	cvMoveWindow("foreground", 360, 288);
#endif

	pCapture = cvCaptureFromFile("../../../assets/2.mp4");
	if (pCapture == NULL) {
		printf("failed to open avi file!: cFileName=%s\n", "mp4");
		pCapture = cvCaptureFromCAM(0);
		if (pCapture == NULL) {
			printf("failed to open Camera!\n");
			return 0;
		}
	}

	VIBE* vibe = NULL;
	int count = 0;

	while (1) {
		count++;

		frame = cvQueryFrame(pCapture);
		if (!frame)   // || nFrmNum % 100 == 0)
		{
			break;
		}
		printf("aa:%d\n",frame->nChannels);
//		if (count < 10)
//			continue;
//
//		if (count % s32SubSampleT != 0) {
//			continue;
//		}
		if (!gray) {
			fg = cvCreateImage(cvSize(frame->width, frame->height), 8, frame->nChannels);
			gray = cvCreateImage(cvSize(frame->width, frame->height), 8, 1);
			mask= cvCreateImage(cvSize(frame->width, frame->height), 8, 1);
			tmp= cvCreateImage(cvSize(frame->width, frame->height), 8, 1);
		}
		cvCvtColor(frame, gray, CV_RGB2GRAY);

		if (!vibe) {
			vibe = vibeCreate(frame->width, frame->height);
			vibeProcessFirstFrame(vibe, (unsigned char*)gray->imageData);
		}else {
			vibeUpdate(vibe, (unsigned char*)gray->imageData);
			char* maskdata=(char*)vibegetMask(vibe);
			memcpy( mask->imageData,maskdata, vibe->height*vibe->width);
			cvShowImage("mask", mask);
		}

		for (i = 0; i < frame->width*frame->height; i++) {
			for(j=0;j<frame->nChannels;j++){
				mask->imageData[i] != 0 ? fg->imageData[i*frame->nChannels+j]=frame->imageData[i*frame->nChannels+j] : 0;


//				mask->imageData[i] != 0 ? fg->imageData[i+j*frame->width*frame->height]=frame->imageData[i+j*frame->width*frame->height] : 0;
			}
		}
//		cvShowImage("foreground", fg);
		cvShowImage("input", frame);
		if (cvWaitKey(10) == 'q')
			break;
	}

	return 0;
}

int main(int argc, char* argv[]) {
//	std::cout<<" Tra"<<std::endl;
	imageProcess();
	return 0;
}
