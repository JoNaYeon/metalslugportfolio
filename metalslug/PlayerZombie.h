#pragma once
#include "Player.h"
class PlayerZombie :
	public Player
{
protected:
public:
	// 생성자
	PlayerZombie()
	{

	};
	// 소멸자
	virtual ~PlayerZombie()
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

	// 공격 - 총 (오버라이딩)
	void AttackGun();
	// 공격 - 나이프 (오버라이딩)
	void AttackKnife();
	// 공격 - 폭탄 (오버라이딩)
	void AttackBomb();
	// 점프 (오버라이딩)
	void Jump();
};

