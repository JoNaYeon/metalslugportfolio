#pragma once
#include "MonsterBoss.h"
class BossET :
	public MonsterBoss
{
protected:
public:
	// ������
	BossET()
	{

	};
	// �Ҹ���
	virtual ~BossET()
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

	// �� ���� - ������Ʈ ��ȯ
	void Attack();
	// �� ���ּ��� ����
	void StateHide();
	// �� �����̱�
	void StateMove();
	// �� �� �پ�� �� ���� ��������
	void StateNum();
};

