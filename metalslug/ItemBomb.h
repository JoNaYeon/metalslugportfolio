#pragma once
#include "Item.h"
class ItemBomb :
	public Item
{
protected:

public:
	// ������
	ItemBomb()
	{

	};
	// �Ҹ���
	virtual ~ItemBomb()
	{

	};

	// ������Ʈ �ʱ�ȭ
	void Init();
	// ������Ʈ ������
	void Run();
	// ������Ʈ ���
	void Render();
	// ������Ʈ �ı�
	void Destroy();

	// ��ź �پ���
	void StateAttack();
	// ��ź �΋H��
	void Hit();
};

