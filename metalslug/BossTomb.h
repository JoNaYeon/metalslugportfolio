#pragma once
#include "MonsterBoss.h"
class BossTomb :
	public MonsterBoss
{
protected:
public:
	// 생성자
	BossTomb()
	{

	};
	// 소멸자
	virtual ~BossTomb()
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

	// 몹 공격 - 떨어짐
	void Attack();
	// 공격받을 경우, 빨리 가라앉도록
	void StateHit();
};

