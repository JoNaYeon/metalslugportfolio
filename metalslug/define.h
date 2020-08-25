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

#define VELOCITY 18.f

#define BGSIZE 4
#define BGEND 5482
// 배경 움직이는 거리
#define BACKGROUNDMOVE 10
// 출력될 배경 이미지의 시작부분
#define BGORIGINSRCX 0
#define BGORIGINSRCY 186
// 배경 이미지의 가로 길이
#define BGWANIMATION 753
// 배경 이미지의 세로 길이
#define BGHANIMATION 224
// 배경 이미지의 가로 칸 수
#define BGWNUM 1
// 배경 이미지의 세로 칸 수
#define BGHNUM 1

#define PLAYERSIZE 4

// 플레이어 RUN / IDEL object 구조체에 들어갈 define
// object가 움직이는 거리
#define IDLEUSERDMOVE BACKGROUNDMOVE * PLAYERSIZE
// object 이미지의 가로 길이
#define IDLEPLAYERWANIMATION 35
// object 이미지의 세로 길이
#define IDLEPLAYERHANIMATION 36
// object 이미지의 가로 칸 수
#define IDLEPLAYERWNUM 4
// object 이미지의 세로 칸 수
#define IDLEPLAYERHNUM 4

// 플레이어 FIRE object 구조체에 들어갈 define
// object가 움직이는 거리
#define FIREUSERDMOVE BACKGROUNDMOVE * PLAYERSIZE
// object 이미지의 가로 길이
#define FIREPLAYERWANIMATION 59
// object 이미지의 세로 길이
#define FIREPLAYERHANIMATION 36
// object 이미지의 가로 칸 수
#define FIREPLAYERWNUM 5
// object 이미지의 세로 칸 수
#define FIREPLAYERHNUM 3

// 플레이어 Jump object 구조체에 들어갈 define
// object가 움직이는 거리
#define JUMPUSERDMOVE BACKGROUNDMOVE * PLAYERSIZE
// object 이미지의 가로 길이
#define JUMPPLAYERWANIMATION 31
// object 이미지의 세로 길이
#define JUMPPLAYERHANIMATION 45
// object 이미지의 가로 칸 수
#define JUMPPLAYERWNUM 3
// object 이미지의 세로 칸 수
#define JUMPPLAYERHNUM 2

// 몬스터 object 구조체에 들어갈 define
// object가 움직이는 거리
#define MONSTERMOVE 10  //BACKGROUNDMOVE * PLAYERSIZE
// object 이미지의 가로 길이
#define MONSTERWANIMATION 36
// object 이미지의 세로 길이
#define MONSTERHANIMATION 42
// object 이미지의 가로 칸 수
#define MONSTERWNUM 10
// object 이미지의 세로 칸 수
#define MONSTERHNUM 2

// 몬스터 피격시 뒤로 가기
#define MONHITEDMOTION 8

// 총알 object 구조체에 들어갈 define
// 총알이 움직이는 길이
#define BULLETMOVE 30 
// 총알이 움직이는 가로세로 사이즈
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





// 오브젝트 종류 enum
enum E_OBJECT
{
	EOBJECT_BG = 0,
	EOBJECT_TERRAIN,
	EOBJECT_BULLET,
	EOBJECT_MONSTER,
	EOBJECT_USER,
	EOBJECT_OBJ,
	EOBJECT_UI,
	// 오브젝트의 갯수를 마지막에 넣어서 담아야 할 오브젝트의 갯수 자동 지정
	EOBJECT_OBJNUM,
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
	E_USERSTATE_JUMP,
	E_USERSTATE_FIRE,
	E_USERSTATE_DROP,
};

// 총알의 상태 enum
enum E_GUNSTATE
{
	E_GUNSTATE_NORMAL = 100
};

// 행동패턴 enum
enum E_KEY
{
	E_KEYSPACE = 0,
	E_KEYLEFT,
	E_KEYRIGHT,
	E_KEYJUMP,
	E_KEYFIRE,
	E_KEYBOMB
};

// 객체 종류 enum
enum E_OBJECTKIND
{
	E_OBJECTKIND_PLAYERTOP = 0,
	E_OBJECTKIND_PLAYERBOTTOM,
	E_OBJECTKIND_BULLET,
	E_OBJECTKIND_BG1,
	E_OBJECTKIND_BG2

};

// 총알별 데미지 enum
enum E_DAMAGE
{
	E_DAMAGE_NORMAL = 10
};

// 스코어 아이템 enum
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

// 총알 아이템 enum
enum E_ITEMWEAPON
{
	E_ITEMWEAPON_BOMB = 2100,
	E_ITEMWEAPON_H = 2101,
	E_ITEMWEAPON_R = 2102,
	E_ITEMWEAPON_S = 2103,
	E_ITEMWEAPON_F = 2104,
	E_ITEMWEAPON_L = 2105
};

// 오브젝트 특징 담은 구조체 
typedef struct stImageInfo
{
	// bmp과 관련된 정보.
	// 이미지 자체의 정보 
	// 이미지의 원본 크기
	POINT ptSrcSize; 
	int iWidthnum; // 이미지 스프라이트 가로칸 수
	int iHightnum; // 이미지 스프라이트 세로칸 수
} IMAGEINFO;

typedef struct stDisplayInfo
{
	// 화면에 그릴때 필요한 정보
	// 그리는 특성과 관련된 변수들
	// 이미지의 시작 위치
	POINT ptSrcPos;
	// 이미지가 출력 될 위치
	POINT ptDestPos;

	// 이미지의 출력 사이즈
	POINT ptDestSize;
} DISPLAYINFO;


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

