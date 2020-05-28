#pragma once
#include "Monster.h"
class MonsterBoss :
	public Monster
{
protected:
public:
	// 생성자
	MonsterBoss()
	{

	};
	// 소멸자
	virtual ~MonsterBoss()
	{

	};

	// 오브젝트 초기화 (오버라이딩)
	virtual void Init();
	// 오브젝트 움직임 (오버라이딩)
	virtual void Run();
	// 오브젝트 출력 (오버라이딩)
	virtual void Render();
	// 오브젝트 파괴 (오버라이딩)
	virtual void Destroy();

	// 몹 공격
	virtual void Attack();
};

