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

// ��� object ����ü�� �� define
//#define BACKGROUNDMOVE 10
//#define BGWSIZE 753
//#define BGHSIZE 224
#define BGSIZE 4.5
#define BGEND 5483
// ��� �����̴� �Ÿ�
#define BACKGROUNDMOVE 10
// ��µ� ��� �̹����� ���ۺκ�
#define BGORIGINSRCX 0
#define BGORIGINSRCY 186 
// ��� �̹����� ���� ����
#define BGWANIMATION 753
// ��� �̹����� ���� ����
#define BGHANIMATION 224
// ��� �̹����� ���� ĭ ��
#define BGWNUM 1
// ��� �̹����� ���� ĭ ��
#define BGHNUM 1

#define PLAYERSIZE 4

// �÷��̾� RUN / IDEL object ����ü�� �� define
// object�� �����̴� �Ÿ�
#define IDLEUSERDMOVE 10
// object �̹����� ���� ����
#define IDLEPLAYERWANIMATION 35
// object �̹����� ���� ����
#define IDLEPLAYERHANIMATION 36
// object �̹����� ���� ĭ ��
#define IDLEPLAYERWNUM 4
// object �̹����� ���� ĭ ��
#define IDLEPLAYERHNUM 4

// �÷��̾� FIRE object ����ü�� �� define
// object�� �����̴� �Ÿ�
#define FIREUSERDMOVE 10
// object �̹����� ���� ����
#define FIREPLAYERWANIMATION 59
// object �̹����� ���� ����
#define FIREPLAYERHANIMATION 36
// object �̹����� ���� ĭ ��
#define FIREPLAYERWNUM 5
// object �̹����� ���� ĭ ��
#define FIREPLAYERHNUM 3

// ���� object ����ü�� �� define
// object�� �����̴� �Ÿ�
#define MONSTERMOVE 10
// object �̹����� ���� ����
#define MONSTERWANIMATION 36
// object �̹����� ���� ����
#define MONSTERHANIMATION 42
// object �̹����� ���� ĭ ��
#define MONSTERWNUM 10
// object �̹����� ���� ĭ ��
#define MONSTERHNUM 2

// �Ѿ� object ����ü�� �� define
// �Ѿ��� �����̴� ����
#define BULLETMOVE 30
// �Ѿ��� �����̴� ���μ��� ������
#define BULLETSIZE 30
#define BULLETWNUM 4
#define BULLETHNUM 4

extern HINSTANCE hInst;

enum E_OBJECT
{
	EOBJECT_BG = 0,
	EOBJECT_TERRAIN,
	EOBJECT_BULLET,
	EOBJECT_MONSTER,
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
	E_USERSTATE_JUMP,
	E_USERSTATE_FIRE
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

enum E_OBJECTKIND
{
	E_OBJECTKIND_PLAYERTOP = 0,
	E_OBJECTKIND_PLAYERBOTTOM,
	E_OBJECTKIND_BULLET,
	E_OBJECTKIND_BG1,
	E_OBJECTKIND_BG2

};





// ������Ʈ Ư¡ ���� ����ü 
typedef struct st_object
{
	// �̹����� ��� ������
	RECT recSrc;
	// �̹����� ���� ��ġ
	POINT poriginSrc;
	// �̹����� ũ��
	RECT recDest;
	// �̹����� ��ġ
	POINT posoriginDest;
	int iobjmove;
	int iWidthnum;
	int iHightnum;

	st_object()
	{
		recSrc = { 0,0, 0, 0 };
		poriginSrc = { 0,0 };
		recDest = { 0,0,0,0 };
		posoriginDest = { 0,0 };
		iobjmove = 0;
		iWidthnum = 0;
		iHightnum = 0;
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

