#pragma once
#include "ItemGun.h"
class Bullet :
	public ItemGun
{
protected:
	// 총알 구조체
	DISPLAYINFO m_DisBullet;
	IMAGEINFO m_ImgBullet;


public:
	// 생성자
	Bullet(POINT _playerpos);
	// 소멸자
	virtual ~Bullet()
	{

	};

	// 오브젝트 초기화
	void Init();
	// 오브젝트 움직임
	void Run();
	// 오브젝트 출력
	void Render(HDC& _hdc, HWND& _hWnd);
	// 오브젝트 파괴
	void Destroy();

	// 총알 닿으면
	bool Hit();
	void ItemState();
	// recclient 밖으로 나가면 
	//void ObjectOut();
	//ST_OBJECT GetStruct() { return m_bullet; };
	// 총알 사망 여부 반환
	bool bObjDead();
};

