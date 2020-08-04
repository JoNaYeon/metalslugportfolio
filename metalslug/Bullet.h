#pragma once
#include "ItemGun.h"
class Bullet :
	public ItemGun
{
protected:
	// �Ѿ� ����ü
	ST_OBJECT m_bullet;
public:
	// ������
	Bullet(POINT _playerpos);
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
	bool Hit(ST_OBJECT& _obj);
	void ItemState();
	// recclient ������ ������ 
	//void ObjectOut();
	ST_OBJECT GetStruct() { return m_bullet; };
	// �Ѿ� ��� ���� ��ȯ
	bool bObjDead();
};

