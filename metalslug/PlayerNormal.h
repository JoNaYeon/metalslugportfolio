#pragma once
#include "Player.h"
#include "ObjectImage.h"
#include <vector>

class PlayerNormal :
	public Player
{
protected:
	// Player�� ������ ������ �������� ������ Ȯ�� �� bool ����
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
	
	// Object�� ����ִ��� �׾����� üũ���ִ� �Լ�
	bool bObjDead();
	// � �ִϸ��̼��� ������ üũ���ִ� �Լ�
	void AnimationStateCheck();
	// �ִϸ��̼��� �������� �������ִ� �Լ�
	void AnimationStateMove();

	// �÷��̾��� ��ġ üũ���ִ� �Լ�
	bool PlayerPosCheck();
};

