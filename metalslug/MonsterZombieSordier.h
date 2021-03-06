#pragma once
#include "Monster.h"
class MonsterZombieSordier :
	public Monster
{
protected:
public:
	// 생성자
	MonsterZombieSordier()
	{

	};
	// 소멸자
	virtual ~MonsterZombieSordier()
	{

	};

	// 오브젝트 초기화 (오버라이딩)
	void Init();
	// 오브젝트 움직임 (오버라이딩)
	void Run();
	// 오브젝트 출력 (오버라이딩)
	void Render();
	// 오브젝트 파괴 (오버라이딩)
	void Destroy();

	// 몹 공격 - 자폭 공격 애니메이션
	void Attack();
};

