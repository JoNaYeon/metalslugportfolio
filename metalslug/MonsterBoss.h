#pragma once
#include "Monster.h"
class MonsterBoss :
	public Monster
{
protected:
public:
	// ������
	MonsterBoss()
	{

	};
	// �Ҹ���
	virtual ~MonsterBoss()
	{

	};

	// ������Ʈ �ʱ�ȭ (�������̵�)
	virtual void Init();
	// ������Ʈ ������ (�������̵�)
	virtual void Run();
	// ������Ʈ ��� (�������̵�)
	virtual void Render();
	// ������Ʈ �ı� (�������̵�)
	virtual void Destroy();

	// �� ����
	virtual void Attack();
};

