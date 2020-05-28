#pragma once
#include "Item.h"
class ItemGun :
	public Item
{
protected:

public:
	// 생성자
	ItemGun()
	{

	};
	// 소멸자
	virtual ~ItemGun()
	{

	};

	// 오브젝트 초기화
	void Init();
	// 오브젝트 움직임
	void Run();
	// 오브젝트 출력
	void Render();
	// 오브젝트 파괴
	void Destroy();

	void StateBullet();
};

