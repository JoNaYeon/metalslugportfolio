#include "PlayerNormal.h"

// 오브젝트 초기화 (오버라이딩)
void PlayerNormal::Init()
{
	return;
};

// 오브젝트 움직임 (오버라이딩)
void PlayerNormal::Run()
{
	return;
};

// 오브젝트 출력 (오버라이딩)
void PlayerNormal::Render(HDC& _hdc, HWND& _hWnd)
{ 
	static ST_OBJECT st_normalplayer;
	char cimgname[] = "..\\source\\user\\useridle1_1";

	// 구조체 정의
	//이미지 크기 w - 32px h - 28px / 35px 간격 3px
	st_normalplayer.iimgheight = 28;
	st_normalplayer.iimgwitdh = 32;

	switch (iobjstate)
	{
		case E_USERSTATE_IDLE:
		{
			Animation(_hdc, st_normalplayer, cimgname);
		}
		return;
	}
	return;
};

// 오브젝트 파괴 (오버라이딩)
void PlayerNormal::Destroy()
{
	return;
};

// 좀비가 되는 애니메이션 
void PlayerNormal::DeadZombie()
{
	return;
};

// 공격 - 총 (오버라이딩)
void PlayerNormal::AttackGun()
{
	return;
};

// 공격 - 나이프 (오버라이딩)
void PlayerNormal::AttackKnife()
{
	return;
};

// 공격 - 폭탄 (오버라이딩)
void PlayerNormal::AttackBomb()
{
	return;
};

// 점프 (오버라이딩)
void PlayerNormal::Jump()
{
	return;
};