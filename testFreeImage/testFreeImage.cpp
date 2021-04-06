// testFreeImage.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <string>
#include <iostream>
#include "FreeImage.h"

using namespace std;


int main()
{

	// 初始化
	FreeImage_Initialise(TRUE);

	// 文件名
	const char* imageFile = "D:\\123\\866-1154.jpg";
	const char* saveFile = "lenna_rotate.png";

	// 图片格式
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

	// 获取图片格式
	/* 此处需要特别注意，即使后缀名是.png并不代表图片格式就真是PNG格式，这里先通过FreeImage_GetFileType函数获取图片格式，
	然后再进行加载，否则，也许会出现加载失败的情况。
	*/
	fif = FreeImage_GetFileType(imageFile);
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(imageFile);

	FIBITMAP* bitmap1 = NULL;
	FIBITMAP* bitmap2 = NULL;
	if ((fif != FIF_UNKNOWN) && FreeImage_FIFSupportsReading(fif)) {
		bitmap1 = FreeImage_Load(fif, imageFile, PNG_DEFAULT);
	}
	if (!bitmap1) {
		fprintf(stderr, "Fail to Load Image!\n");
		exit(-1);
	}
	else {
		FreeImage_Save(fif, bitmap1, saveFile, PNG_DEFAULT);
		bitmap2 = FreeImage_Load(fif, saveFile, PNG_DEFAULT);
		if (!bitmap2) {
			fprintf(stderr, "Fail to Load saved Image!\n");
			exit(-1);
		}
	}

	// 获取影像的宽高，都以像素为单位
	int width = FreeImage_GetWidth(bitmap1);
	int height = FreeImage_GetHeight(bitmap1);




    return 0;
}

