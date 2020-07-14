#pragma once
#include "Player.h"
#include "ObjectImage.h"
#include <vector>

class PlayerNormal :
	public Player
{
protected:
	ObjectImage m_playerimg;
	// �̹��� ��Ʈ���� ���� ����
	int m_itopBitmapImg;
	int m_ibottomBitmapImg;
	bool m_bleftright;

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
	//virtual ST_OBJECT GetStruct() PURE;

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
	bool bObjDead();
	
	std::vector<Object*> Getbulletvec() { return m_vbullet; };
};

