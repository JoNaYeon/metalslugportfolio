#pragma once
#include "ItemGun.h"
class Bullet :
	public ItemGun
{
protected:

public:
	// ������
	Bullet()
	{

	};
	// �Ҹ���
	virtual ~Bullet()
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

	// �Ѿ� ������
	void Hit();
};

