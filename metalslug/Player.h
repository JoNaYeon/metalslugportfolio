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

	Object* m_classobjptr;
	// �Ѿ��� ���� vector
	std::vector<Object*> m_vbullet;

public:
	// ������
	Player();
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

