#pragma once
#include "Item.h"
class ItemGun :
	public Item
{
protected:

public:
	// ������
	ItemGun()
	{

	};
	// �Ҹ���
	virtual ~ItemGun()
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

	void StateBullet();
};

