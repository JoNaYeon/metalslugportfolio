#pragma once
#include "MonsterBoss.h"
class BossTomb :
	public MonsterBoss
{
protected:
public:
	// ������
	BossTomb()
	{

	};
	// �Ҹ���
	virtual ~BossTomb()
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

	// �� ���� - ������
	void Attack();
	// ���ݹ��� ���, ���� ����ɵ���
	void StateHit();
};

