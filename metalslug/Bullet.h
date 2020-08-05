#pragma once
#include "ItemGun.h"
class Bullet :
	public ItemGun
{
protected:
	// �Ѿ� ����ü
	DISPLAYINFO m_DisBullet;
	IMAGEINFO m_ImgBullet;


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
	bool Hit();
	void ItemState();
	// recclient ������ ������ 
	//void ObjectOut();
	//ST_OBJECT GetStruct() { return m_bullet; };
	// �Ѿ� ��� ���� ��ȯ
	bool bObjDead();
};

