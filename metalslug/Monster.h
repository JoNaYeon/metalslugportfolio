#pragma once
#include "Object.h"
class Monster :
	public Object
{
protected:
	int m_ihp;
	int m_istrength;
	int m_ispeed;

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
	virtual void Init() PURE
	// 오브젝트 움직임 (오버라이딩)
	virtual void Run() PURE
	// 오브젝트 출력 (오버라이딩)
	virtual void Render(HDC& _hdc, HWND& _hWnd) PURE
	// 오브젝트 파괴 (오버라이딩)
	virtual void Destroy() PURE

	// 몹 공격 
	virtual void Attack() PURE
};

