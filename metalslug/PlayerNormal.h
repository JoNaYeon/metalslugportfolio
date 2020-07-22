#pragma once
#include "Player.h"
#include "ObjectImage.h"
#include <vector>

class PlayerNormal :
	public Player
{
protected:
	//ObjectImage m_playerimg;
	// �̹��� ��Ʈ���� ���� ����
	int m_itopBitmapImg;
	int m_ibottomBitmapImg;
	// Player�� ������ ������ �������� ������ Ȯ�� �� bool ����
	bool m_bleftright;

	// �÷��̾� ����ü
	ST_OBJECT m_normalplayertop;
	ST_OBJECT m_normalplayerbottom;

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
	
	// Object�� ����ִ��� �׾����� üũ���ִ� �Լ�
	bool bObjDead();
	// � �ִϸ��̼��� ������ üũ���ִ� �Լ�
	void AnimationStateCheck();
	// �ִϸ��̼��� �������� �������ִ� �Լ�
	void AnimationStateMove();
	// Player�� ��ġ�� Ȯ���Ͽ� m_iobjPosState �� enum�� �ھ��ִ� �Լ�
	void ObjectPosCheck();
	bool PlayerPosStateInClientMid();
};

