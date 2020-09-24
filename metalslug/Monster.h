#pragma once
#include "Object.h"
class Monster :
	public Object
{
protected:
	int m_ihp;
	int m_istrength;
	int m_ispeed;

	// 몬스터 구조체
	//DISPLAYINFO m_DisMon;
	//IMAGEINFO m_ImgMon;

	bool m_bsee;

public:
	// 생성자
	Monster()
	{
		m_ihp = 0;
		m_istrength = 0;
		m_ispeed = 0;

	};
	// 소멸자
	virtual ~Monster()
	{

	};

	// 오브젝트 초기화 (오버라이딩)
	virtual void Init() PURE;
	// 오브젝트 움직임 (오버라이딩)
	virtual void Run() PURE;
	// 오브젝트 출력 (오버라이딩)
	virtual void Render(HDC& _hdc, HWND& _hWnd) PURE;
	// 오브젝트 파괴 (오버라이딩)
	virtual void Destroy() PURE;
	bool bObjDead();

	// 몹 공격 
	virtual void Attack() PURE;

	void MonsterMove(E_USERSTATE _e_state);
	void MovePattern();

	void Hit();

	int GetHP() { return m_ihp; };

	//DISPLAYINFO* GetDisTop() { return &m_DisMon; };
	//void SetDisTop(POINT _disobj) { m_DisMon.ptDestPos = _disobj; return; }
	DISPLAYINFO* GetDisTop() { return &m_DisTop; };
	void SetDisTop(POINT _disobj) { m_DisTop.ptDestPos = _disobj; return; }
	bool GetSee() { return m_bsee; };
};

