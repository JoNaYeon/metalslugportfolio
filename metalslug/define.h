#pragma once
#pragma warning(disable: 4005)

#include <time.h>
#include <random>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include "resource.h"

#define PURE = 0;
#define BACKGROUNDMOVE 5

enum E_OBJECT
{
	EOBJECT_BG = 0,
	EOBJECT_TERRAIN,
	EOBJECT_OBJ,
	EOBJECT_UI,
	// 오브젝트의 갯수를 마지막에 넣어서 담아야 할 오브젝트의 갯수 자동 지정
	EOBJECT_OBJNUM,
};

enum E_BGSCENE
{
	E_BGSCENE_GAME = 0
};

// scene 의 상태 표시 
enum E_SCENESTATE
{
	E_SCENESTATE_NONE = 0,
	E_SCENESTATE_INTRO,
	E_SCENESTATE_GAME
};

// 플레이어 이미지의 상태를 표시
enum E_USERSTATE
{
	E_USERSTATE_IDLE = 0
};





// 오브젝트 특징 담은 구조체 
typedef struct st_object
{
	int iimgwitdh;
	int iimgheight;
	POINT imgpos;
	POINT imgstartpos;

	st_object()
	{
		iimgwitdh = 0;
		iimgheight = 0;
		imgpos = { 0,0 };
		imgstartpos = { 0,0 };
	}
} ST_OBJECT;







// CreateCompatableBitmap() 의 내용을 바꾸어서 커스텀 한 함수
// 한슬이표
static HBITMAP MakeDIBSection(HDC& dc, int width, int height)
{
	BITMAPINFO bmi;
	LPVOID pBits;
	HBITMAP hBitmap;
	memset(&bmi.bmiHeader, 0, sizeof(BITMAPINFOHEADER));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = height;
	bmi.bmiHeader.biPlanes = 1;
	hBitmap = ::CreateDIBSection(dc, &bmi, DIB_RGB_COLORS, (void**)&pBits, NULL, 0);
	return hBitmap;
}

