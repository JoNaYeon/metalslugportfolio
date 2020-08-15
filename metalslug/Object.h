#pragma once

#include "define.h"

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
	//float m_fvelocity;
	//float m_fgravity;
	// jump 유무
	bool m_bjump;
	// fire 유무
	bool m_bfire;
	// 중력의 유무
	bool m_bgravity;
	// collision Check 
	bool m_bCollisionCheck;

	// 충돌 판정하는 충돌 박스
	RECT m_recHitBox;

	// 전에 존재했던 st_object에 있던 변수, 오브젝트 이동관련이라 이동
	int m_iobjmove;
	
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

	// dbject를 움직여줄 애니메이션에 추가된 함수
	void Aniimage(DISPLAYINFO& _displayInfo, IMAGEINFO _imageInfo);

	int Getobjstate() { return m_iobjstate; };
	void Setobjstate(int _objstate) { m_iobjstate = _objstate; };
	
	// object의 사망여부 함수
	virtual bool bObjDead() PURE;

	void SetImgInfo(IMAGEINFO& _imgInfo, POINT _ptSrcSize, int _iWidthNum, int _iHightNum);
	void Gravity(DISPLAYINFO* _objdis, E_OBJECT _eobj);
	bool IntersectRectCheck(RECT* _rec1, RECT* _rec2);
	// Object들이 배경에 설 수 있도록 해주는 함수 
	//void ObjStand(ST_OBJECT* _obj);

	RECT GetHitBox() { return m_recHitBox; };
	// 피격 체크
	void SetCollisionCheck(bool _CollisionCheck) { m_bCollisionCheck = _CollisionCheck; };
	
	void SetboolGravity(bool _bGravity) { m_bgravity = _bGravity; return; };
	bool GetboolGravity() { return m_bgravity; };

	bool GetJump() { return m_bjump; };
};

