#pragma once
#include "MonsterBoss.h"
class BossSpaceship :
	public MonsterBoss
{
protected:
public:
	// ������
	BossSpaceship()
	{

	};
	// �Ҹ���
	virtual ~BossSpaceship()
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

	// �� ���� - ������Ʈ ����
	void Attack();
};

