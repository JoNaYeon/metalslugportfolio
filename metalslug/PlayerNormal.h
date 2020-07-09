#pragma once
#include "Player.h"
#include "ObjectImage.h"
#include <vector>

class PlayerNormal :
	public Player
{
protected:
	ObjectImage m_playerimg;
	// object 담을 구조체
	ST_OBJECT m_normalplayertop;
	ST_OBJECT m_normalplayerbottom;
	// 이미지 비트맵을 담을 변수
	int m_itopBitmapImg;
	int m_ibottomBitmapImg;
	bool m_bleftright;
	std::vector<Object*> m_vbullet;

public:
	// 생성자
	PlayerNormal();
	// 소멸자
	virtual ~PlayerNormal()
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

	// 좀비가 되는 애니메이션 
	void DeadZombie();
	// 공격 - 총 (오버라이딩)
	void AttackGun();
	// 공격 - 나이프 (오버라이딩)
	void AttackKnife();
	// 공격 - 폭탄 (오버라이딩)
	void AttackBomb();
	// 점프 (오버라이딩)
	void Jump();
	
	std::vector<Object*> Getbulletvec() { return m_vbullet; };
};

