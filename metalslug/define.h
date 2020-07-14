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
#define BACKGROUNDMOVE 10
#define BGWSIZE 753
#define BGHSIZE 224
#define BGADD 4.5

// �÷��̾� object ����ü�� �� define
// object�� �����̴� �Ÿ�
#define USERDMOVE 10
// object �̹����� ���� ����
#define PLAYERWANIMATION 35
// object �̹����� ���� ����
#define PLAYERHANIMATION 36
// object �̹����� ���� ĭ ��
#define PLAYERWNUM 4
// object �̹����� ���� ĭ ��
#define PLAYERHNUM 4

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
	EOBJECT_OBJ,
	EOBJECT_BULLET,
	EOBJECT_MONSTER,
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

