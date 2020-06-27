#pragma once
#include "Object.h"


class Player :
	public Object
{
protected:
	int m_ihp;
	int m_istrength;
	int m_ispeed;
	int m_igun;
	int m_ibomb;
	int m_ivirous;
	bool m_bhuman;

public:
	// ������
	Player()
	{
		m_ihp = 0;
		m_istrength = 0;
		m_ispeed = 0;
		m_igun = 0;
		m_ibomb = 0;
		m_ivirous = 0;
		m_bhuman = 0;
	}
	// �Ҹ���
	virtual ~Player()
	{

	}

	// ������Ʈ �ʱ�ȭ (�������̵�)
	void Init();
	// ������Ʈ ������ (�������̵�)
	void Run();
	// ������Ʈ ��� (�������̵�)
	void Render();
	// ������Ʈ �ı� (�������̵�)
	void Destroy();


	// ���� - �� (�������̵�)
	void AttackGun();
	// ���� - ������ (�������̵�)
	void AttackKnife();
	// ���� - ��ź (�������̵�)
	void AttackBomb();
	// ���� (�������̵�)
	void Jump();

	// ���� �Ǵ� �ִϸ��̼� 
	void DeadZombie();
};

