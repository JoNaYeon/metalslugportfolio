#pragma once
#include "ItemGun.h"
class Bullet :
	public ItemGun
{
protected:
	ST_OBJECT m_bullet;
public:
	// ������
	Bullet();
	// �Ҹ���
	virtual ~Bullet()
	{

	};

	// ������Ʈ �ʱ�ȭ
	void Init();
	// ������Ʈ ������
	void Run();
	// ������Ʈ ���
	void Render(HDC& _hdc, HWND& _hWnd);
	// ������Ʈ �ı�
	void Destroy();

	// �Ѿ� ������
	void Hit();
	void ItemState();
};

