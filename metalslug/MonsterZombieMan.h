#pragma once
#include "Monster.h"
class MonsterZombieMan :
	public Monster
{
protected:
public:
	// ������
	MonsterZombieMan();
	// �Ҹ���
	virtual ~MonsterZombieMan()
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

	// �� ���� - �� ���� �ִϸ��̼�
	void Attack();
	// ���� ������ 
	void MovePattern();

	bool bObjDead();

};

