#pragma once
#include "MonsterBoss.h"
class BossSpaceship :
	public MonsterBoss
{
protected:
public:
	// 생성자
	BossSpaceship()
	{

	};
	// 소멸자
	virtual ~BossSpaceship()
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

	// 몹 공격 - 오브젝트 생성
	void Attack();
};

