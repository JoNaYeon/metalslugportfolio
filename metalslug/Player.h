#pragma once
#include "Object.h"


class Player :
	public Object
{
protected:
	int m_ihp;
	int m_istrength;
	int m_ispeed;
	int m_igun;
	int m_ibomb;
	int m_ivirous;
	bool m_bhuman;

	bool m_bmove;

	// player의 이미지 경로를 담을 변수
	LPCSTR m_strBitmapTop;
	LPCSTR m_strBitmapBottom;

	Object* m_classobjptr;

	// 플레이어 구조체
	DISPLAYINFO	m_DisTop;
	DISPLAYINFO	m_DisBot;

	IMAGEINFO	m_ImgTop;
	IMAGEINFO	m_ImgBot;

public:
	// 생성자
	Player();
	// 소멸자
	virtual ~Player()
	{

	}

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

	// 좀비가 되는 애니메이션 
	void DeadZombie();

	DISPLAYINFO* GetPlayerDisTop() { return &m_DisTop; };
	DISPLAYINFO* GetPlayerDisBot() { return &m_DisBot; };
	void SetPlayerDisTop(POINT _disTop) { m_DisTop.ptDestPos = _disTop; return; };
	void SetPlayerDisBot(POINT _disBot) { m_DisBot.ptDestPos = _disBot; return; };
	bool GetBGMove() { return m_bmove; };
};

