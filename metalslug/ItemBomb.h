#pragma once
#include "Item.h"
class ItemBomb :
	public Item
{
protected:

public:
	// 생성자
	ItemBomb()
	{

	};
	// 소멸자
	virtual ~ItemBomb()
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

	// 폭탄 줄어들기
	void StateAttack();
	// 폭탄 부딫힘
	void Hit();
};

