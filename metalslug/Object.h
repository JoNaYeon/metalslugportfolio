#pragma once

#include "define.h"
//#include "framework.h"



class Object
{
protected:
	int m_iobjstate;

	// 시간을 통제할 변수
	DWORD m_dcurTime;
	static DWORD m_dPrevTime;
	float m_fdelay;

	// 총알 구조체
	//ST_OBJECT m_bullet;
	// 플레이어 구조체
	ST_OBJECT m_normalplayertop;
	ST_OBJECT m_normalplayerbottom;
	// 몬스터 구조체
	ST_OBJECT m_Monster;
	// 배경화면 구조체
	ST_OBJECT m_BG1;
	ST_OBJECT m_BG2;


	//  objcet의 vector를 담을 iter
	std::vector<Object*>::iterator m_objiter;

	// 총알을 담을 vector
	std::vector<Object*> m_vbullet;
	
public:
	// 생성자
	Object();
	// 소멸자
	virtual ~Object()
	{

	};

	// 오브젝트 초기화z
	virtual void Init() PURE;
	// 오브젝트 움직임
	virtual void Run() PURE;
	// 오브젝트 출력 
	virtual void Render(HDC& _hdc, HWND& _hWnd) PURE;
	// 오브젝트 파괴
	virtual void Destroy() PURE;
	// struct 내보내기 
	//virtual ST_OBJECT GetStruct() PURE;

	// Object를 움직여줄 애니메이션 
	void Animation(HDC& _hdc, ST_OBJECT& _obj, int& _iobjstate);
	// dbject를 움직여줄 애니메이션에 추가된 함수
	void Aniimage(ST_OBJECT& _objtop);
	void hitbox(RECT _rec1, RECT _rec2);

	int Getobjstate() { return m_iobjstate; };
	void Setobjstate(int _objstate) { m_iobjstate = _objstate; };
	// iter 에 vector 넣기
	bool GetIter(std::vector<Object*>& _obj);
	// object가 화면 밖으로 나가면
	void ObjectOut(Object& _obj, std::vector<Object*>& _vecobj);
	ST_OBJECT GetStruct(int _iobjstate);

};

