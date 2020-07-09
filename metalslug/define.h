#pragma once
#pragma warning(disable: 4005)

#include <time.h>
#include <random>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include "resource.h"
// 타이머 사용 가능하도록 포함하는 라이브러리
#pragma comment(lib, "winmm.lib")


#define PURE = 0;
#define BACKGROUNDMOVE 10
#define USERDMOVE 1
#define BULLETMOVE 1
#define BULLETSIZE 30
#define PLAYERWANIMATION 35
#define PLAYERHANIMATION 36

extern HINSTANCE hInst;

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
	E_USERSTATE_IDLE = 0,
	E_USERSTATE_LWALK,
	E_USERSTATE_RWALK ,
	E_USERSTATE_JUMP
};

enum E_GUNSTATE
{
	E_GUNSTATE_NORMAL = 100
};

enum E_KEY
{
	E_KEYSPACE = 0,
	E_KEYLEFT,
	E_KEYRIGHT,
	E_KEYJUMP,
	E_KEYFIRE,
	E_KEYBOMB
};





// 오브젝트 특징 담은 구조체 
typedef struct st_object
{
	// 이미지의 출력 사이즈
	//RECT rec_imgprintsize;
	RECT recSrc;
	// 이미지의 시작 위치
	//POINT imgstartpos;
	POINT poriginSrc;
	// 이미지의 크기
	//RECT recimg;
	RECT recDest;
	// 이미지의 위치
	POINT posoriginDest;

	st_object()
	{
		recSrc = { 0,0, 0, 0 };
		poriginSrc = { 0,0 };
		recDest = { 0,0,0,0 };
		posoriginDest = { 0,0 };
	}
	~st_object()
	{

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

