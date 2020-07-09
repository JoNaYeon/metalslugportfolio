#pragma once
#pragma warning(disable: 4005)

#include <time.h>
#include <random>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include "resource.h"
// Ÿ�̸� ��� �����ϵ��� �����ϴ� ���̺귯��
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
	// ������Ʈ�� ������ �������� �־ ��ƾ� �� ������Ʈ�� ���� �ڵ� ����
	EOBJECT_OBJNUM,
};

enum E_BGSCENE
{
	E_BGSCENE_GAME = 0
};

// scene �� ���� ǥ�� 
enum E_SCENESTATE
{
	E_SCENESTATE_NONE = 0,
	E_SCENESTATE_INTRO,
	E_SCENESTATE_GAME
};

// �÷��̾� �̹����� ���¸� ǥ��
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





// ������Ʈ Ư¡ ���� ����ü 
typedef struct st_object
{
	// �̹����� ��� ������
	//RECT rec_imgprintsize;
	RECT recSrc;
	// �̹����� ���� ��ġ
	//POINT imgstartpos;
	POINT poriginSrc;
	// �̹����� ũ��
	//RECT recimg;
	RECT recDest;
	// �̹����� ��ġ
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







// CreateCompatableBitmap() �� ������ �ٲپ Ŀ���� �� �Լ�
// �ѽ���ǥ
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

