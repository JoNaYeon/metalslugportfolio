#pragma once
#include "Monster.h"
class MonsterZombieWm :
	public Monster
{
protected:
public:
	// 생성자
	MonsterZombieWm()
	{

	};
	// 소멸자
	virtual ~MonsterZombieWm()
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

	// 몹 공격 - 침뱉기 애니메이션
	void Attack();
};

