#pragma once
#include "Monster.h"
class MonsterZombieBig :
	public Monster
{
protected:
public:
	// ������
	MonsterZombieBig()
	{

	};
	// �Ҹ���
	virtual ~MonsterZombieBig()
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

	// �� ���� - ���� ���� �ִϸ��̼�
	void Attack();
};

