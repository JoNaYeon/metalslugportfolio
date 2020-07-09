#pragma once
#include "Player.h"
#include "ObjectImage.h"
#include <vector>

class PlayerNormal :
	public Player
{
protected:
	ObjectImage m_playerimg;
	// object ���� ����ü
	ST_OBJECT m_normalplayertop;
	ST_OBJECT m_normalplayerbottom;
	// �̹��� ��Ʈ���� ���� ����
	int m_itopBitmapImg;
	int m_ibottomBitmapImg;
	bool m_bleftright;
	std::vector<Object*> m_vbullet;

public:
	// ������
	PlayerNormal();
	// �Ҹ���
	virtual ~PlayerNormal()
	{

	};

	// ������Ʈ �ʱ�ȭ (�������̵�)
	void Init();
	// ������Ʈ ������ (�������̵�)
	void Run();
	// ������Ʈ ��� (�������̵�)
	void Render(HDC& _hdc, HWND& _hWnd);
	// ������Ʈ �ı� (�������̵�)
	void Destroy();

	// ���� �Ǵ� �ִϸ��̼� 
	void DeadZombie();
	// ���� - �� (�������̵�)
	void AttackGun();
	// ���� - ������ (�������̵�)
	void AttackKnife();
	// ���� - ��ź (�������̵�)
	void AttackBomb();
	// ���� (�������̵�)
	void Jump();
	
	std::vector<Object*> Getbulletvec() { return m_vbullet; };
};

