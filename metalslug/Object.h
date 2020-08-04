#pragma once

#include "define.h"
//#include "framework.h"



class Object
{
protected:
	int m_iobjstate;
	int m_iobjstatetemp;

	// 시간을 통제할 변수
	DWORD m_dcurTime;
	static DWORD m_dPrevTime;
	float m_fdelay;

	// 객체의 존재 여부 확인하는 bool 변수
	bool m_bdead;

	// 중력을 컨트롤 할 변수들
	float m_fvelocity;
	float m_fgravity;
	// jump 유무
	bool m_bjump;
	// fire 유무
	bool m_bfire;

	bool m_bgravity;

	RECT m_recHitBox;
	
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

	// dbject를 움직여줄 애니메이션에 추가된 함수
	void Aniimage(ST_OBJECT& _obj);
	//void hitbox(RECT _rec1, RECT _rec2);

	int Getobjstate() { return m_iobjstate; };
	void Setobjstate(int _objstate) { m_iobjstate = _objstate; };
	// iter 에 vector 넣기
	bool GetIter(std::vector<Object*>& _obj);

	// object의 사망여부 함수
	virtual bool bObjDead() PURE;

	// struct 채우는 함수 
	void SetObjStruct(ST_OBJECT& _obj, int _recSrcright, int _recSrcbottom, int _poriginSrcx, int _poriginSrcy,
		int _recDestright, int _recDestbottom, int _posoriginDestx, int _posoriginDesty, 
		int _iobjmove, int _iWidthnum, int _iHightnum);

	void Gravity(ST_OBJECT* _obj);
	bool IntersectRectCheck(RECT* _rec1, RECT* _rec2);
	// Object들이 배경에 설 수 있도록 해주는 함수 
	void ObjStand(ST_OBJECT* _obj);
};

