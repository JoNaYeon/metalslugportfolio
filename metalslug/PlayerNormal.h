#pragma once
#include "Player.h"
#include "ObjectImage.h"
#include <vector>

class PlayerNormal :
	public Player
{
protected:
	//ObjectImage m_playerimg;
	// 이미지 비트맵을 담을 변수
	int m_itopBitmapImg;
	int m_ibottomBitmapImg;
	// Player가 왼쪽을 보는지 오른쪽을 보는지 확인 할 bool 변수
	bool m_bleftright;

	// 플레이어 구조체
	ST_OBJECT m_normalplayertop;
	ST_OBJECT m_normalplayerbottom;

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
	//virtual ST_OBJECT GetStruct() PURE;

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
	
	// Object가 살아있는지 죽었는지 체크해주는 함수
	bool bObjDead();
	// 어떤 애니메이션이 들어가는지 체크해주는 함수
	void AnimationStateCheck();
	// 애니메이션의 움직임을 실행해주는 함수
	void AnimationStateMove();
	// Player의 위치를 확인하여 m_iobjPosState 에 enum을 박아주는 함수
	void ObjectPosCheck();
	bool PlayerPosStateInClientMid();
};

