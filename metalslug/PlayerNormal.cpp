#include "PlayerNormal.h"

// ������Ʈ �ʱ�ȭ (�������̵�)
void PlayerNormal::Init()
{
	return;
};

// ������Ʈ ������ (�������̵�)
void PlayerNormal::Run()
{
	return;
};

// ������Ʈ ��� (�������̵�)
void PlayerNormal::Render(HDC& _hdc, HWND& _hWnd)
{ 
	static ST_OBJECT st_normalplayer;
	char cimgname[] = "..\\source\\user\\useridle1_1";

	// ����ü ����
	//�̹��� ũ�� w - 32px h - 28px / 35px ���� 3px
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

// ������Ʈ �ı� (�������̵�)
void PlayerNormal::Destroy()
{
	return;
};

// ���� �Ǵ� �ִϸ��̼� 
void PlayerNormal::DeadZombie()
{
	return;
};

// ���� - �� (�������̵�)
void PlayerNormal::AttackGun()
{
	return;
};

// ���� - ������ (�������̵�)
void PlayerNormal::AttackKnife()
{
	return;
};

// ���� - ��ź (�������̵�)
void PlayerNormal::AttackBomb()
{
	return;
};

// ���� (�������̵�)
void PlayerNormal::Jump()
{
	return;
};