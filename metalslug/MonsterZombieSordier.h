#pragma once
#include "Monster.h"
class MonsterZombieSordier :
	public Monster
{
protected:
public:
	// ������
	MonsterZombieSordier()
	{

	};
	// �Ҹ���
	virtual ~MonsterZombieSordier()
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

