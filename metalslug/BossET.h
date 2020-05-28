#pragma once
#include "MonsterBoss.h"
class BossET :
	public MonsterBoss
{
protected:
public:
	// 생성자
	BossET()
	{

	};
	// 소멸자
	virtual ~BossET()
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

	// 몹 공격 - 오브젝트 소환
	void Attack();
	// 몹 우주선에 숨기
	void StateHide();
	// 몹 움직이기
	void StateMove();
	// 몹 수 줄어들 때 마다 빨라지기
	void StateNum();
};

