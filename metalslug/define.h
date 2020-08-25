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

#define VELOCITY 18.f

#define BGSIZE 4
#define BGEND 5482
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
#define IDLEUSERDMOVE BACKGROUNDMOVE * PLAYERSIZE
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
#define FIREUSERDMOVE BACKGROUNDMOVE * PLAYERSIZE
// object �̹����� ���� ����
#define FIREPLAYERWANIMATION 59
// object �̹����� ���� ����
#define FIREPLAYERHANIMATION 36
// object �̹����� ���� ĭ ��
#define FIREPLAYERWNUM 5
// object �̹����� ���� ĭ ��
#define FIREPLAYERHNUM 3

// �÷��̾� Jump object ����ü�� �� define
// object�� �����̴� �Ÿ�
#define JUMPUSERDMOVE BACKGROUNDMOVE * PLAYERSIZE
// object �̹����� ���� ����
#define JUMPPLAYERWANIMATION 31
// object �̹����� ���� ����
#define JUMPPLAYERHANIMATION 45
// object �̹����� ���� ĭ ��
#define JUMPPLAYERWNUM 3
// object �̹����� ���� ĭ ��
#define JUMPPLAYERHNUM 2

// ���� object ����ü�� �� define
// object�� �����̴� �Ÿ�
#define MONSTERMOVE 10  //BACKGROUNDMOVE * PLAYERSIZE
// object �̹����� ���� ����
#define MONSTERWANIMATION 36
// object �̹����� ���� ����
#define MONSTERHANIMATION 42
// object �̹����� ���� ĭ ��
#define MONSTERWNUM 10
// object �̹����� ���� ĭ ��
#define MONSTERHNUM 2

// ���� �ǰݽ� �ڷ� ����
#define MONHITEDMOTION 8

// �Ѿ� object ����ü�� �� define
// �Ѿ��� �����̴� ����
#define BULLETMOVE 30 
// �Ѿ��� �����̴� ���μ��� ������
#define BULLETSIZE 30
#define BULLETWNUM 4
#define BULLETHNUM 4

extern HINSTANCE hInst;


// BackgroundTile Pos define
#define POSX0 0 
#define POSY0 380
#define POSX1 100 
#define POSY1 380
#define POSX2 114
#define POSY2 366
#define POSX3 205
#define POSY3 366
#define POSX4 292
#define POSY4 380
#define POSX5 420
#define POSY5 380
#define POSX6 433
#define POSY6 366
#define POSX7 525
#define POSY7 366
#define POSX8 605
#define POSY8 380
#define POSX9 747
#define POSY9 380
#define POSX10 771
#define POSY10 357
#define POSX11 823
#define POSY11 356
#define POSX12 824
#define POSY12 380
#define POSX13 1038
#define POSY13 370
#define POSX14 1185
#define POSY14 370
#define POSX15 1743
#define POSY15 229
#define POSX16 1747
#define POSY16 360
#define POSX17 2056
#define POSY17 360
#define POSX18 2424
#define POSY18 445
#define POSX19 2495
#define POSY19 530
#define POSX20 2751
#define POSY20 530
#define POSX21 2840
#define POSY21 670
#define POSX22 3077
#define POSY22 670
#define POSX23 3216
#define POSY23 808
#define POSX24 3281
#define POSY24 820
#define POSX25 4471
#define POSY25 816
#define POSX26 6990
#define POSY26 884
#define POSX27 5428
#define POSY27 884





// ������Ʈ ���� enum
enum E_OBJECT
{
	EOBJECT_BG = 0,
	EOBJECT_TERRAIN,
	EOBJECT_BULLET,
	EOBJECT_MONSTER,
	EOBJECT_USER,
	EOBJECT_OBJ,
	EOBJECT_UI,
	// ������Ʈ�� ������ �������� �־ ��ƾ� �� ������Ʈ�� ���� �ڵ� ����
	EOBJECT_OBJNUM,
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
	E_USERSTATE_FIRE,
	E_USERSTATE_DROP,
};

// �Ѿ��� ���� enum
enum E_GUNSTATE
{
	E_GUNSTATE_NORMAL = 100
};

// �ൿ���� enum
enum E_KEY
{
	E_KEYSPACE = 0,
	E_KEYLEFT,
	E_KEYRIGHT,
	E_KEYJUMP,
	E_KEYFIRE,
	E_KEYBOMB
};

// ��ü ���� enum
enum E_OBJECTKIND
{
	E_OBJECTKIND_PLAYERTOP = 0,
	E_OBJECTKIND_PLAYERBOTTOM,
	E_OBJECTKIND_BULLET,
	E_OBJECTKIND_BG1,
	E_OBJECTKIND_BG2

};

// �Ѿ˺� ������ enum
enum E_DAMAGE
{
	E_DAMAGE_NORMAL = 10
};

// ���ھ� ������ enum
enum E_ITEMSCORE
{
	E_ITEMSCORE_CURE = 2000,
	E_ITEMSCORE_FISH = 2001,
	E_ITEMSCORE_BREAD = 2002,
	E_ITEMSCORE_MEAT = 2003,
	E_ITEMSCORE_CAN = 2004,
	E_ITEMSCORE_CHICKEN = 2005,
	E_ITEMSCORE_FRUIT = 2006,
	E_ITEMSCORE_CARRAT = 2007,
	E_ITEMSCORE_BANANA = 2008,
	E_ITEMSCORE_BONE = 2009
};

// �Ѿ� ������ enum
enum E_ITEMWEAPON
{
	E_ITEMWEAPON_BOMB = 2100,
	E_ITEMWEAPON_H = 2101,
	E_ITEMWEAPON_R = 2102,
	E_ITEMWEAPON_S = 2103,
	E_ITEMWEAPON_F = 2104,
	E_ITEMWEAPON_L = 2105
};

// ������Ʈ Ư¡ ���� ����ü 
typedef struct stImageInfo
{
	// bmp�� ���õ� ����.
	// �̹��� ��ü�� ���� 
	// �̹����� ���� ũ��
	POINT ptSrcSize; 
	int iWidthnum; // �̹��� ��������Ʈ ����ĭ ��
	int iHightnum; // �̹��� ��������Ʈ ����ĭ ��
} IMAGEINFO;

typedef struct stDisplayInfo
{
	// ȭ�鿡 �׸��� �ʿ��� ����
	// �׸��� Ư���� ���õ� ������
	// �̹����� ���� ��ġ
	POINT ptSrcPos;
	// �̹����� ��� �� ��ġ
	POINT ptDestPos;

	// �̹����� ��� ������
	POINT ptDestSize;
} DISPLAYINFO;


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

