#pragma once
#include "Monster.h"
class MonsterZombieWm :
	public Monster
{
protected:
public:
	// ������
	MonsterZombieWm()
	{

	};
	// �Ҹ���
	virtual ~MonsterZombieWm()
	{

	};

	// ������Ʈ �ʱ�ȭ (�������̵�)
	void Init();
	// ������Ʈ ������ (�������̵�)
	void Run();
	// ������Ʈ ��� (�������̵�)
	void Render();
	// ������Ʈ �ı� (�������̵�)
	void Destroy();

	// �� ���� - ħ��� �ִϸ��̼�
	void Attack();
};

