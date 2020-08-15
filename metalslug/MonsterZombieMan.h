#pragma once
#include "Monster.h"
class MonsterZombieMan :
	public Monster
{
protected:
public:
	// 생성자
	MonsterZombieMan();
	// 소멸자
	virtual ~MonsterZombieMan()
	{

	};

	// 오브젝트 초기화 (오버라이딩)
	void Init();
	// 오브젝트 움직임 (오버라이딩)
	void Run();
	// 오브젝트 출력 (오버라이딩)
	void Render(HDC& _hdc, HWND& _hWnd);
	// 오브젝트 파괴 (오버라이딩)
	void Destroy();

	// 몹 공격 - 뇌 공격 애니메이션
	void Attack();
	// 몬스터 움직임 
	void MovePattern();

	bool bObjDead();

};

