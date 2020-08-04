#pragma once

#include "define.h"
//#include "framework.h"



class Object
{
protected:
	int m_iobjstate;
	int m_iobjstatetemp;

	// �ð��� ������ ����
	DWORD m_dcurTime;
	static DWORD m_dPrevTime;
	float m_fdelay;

	// ��ü�� ���� ���� Ȯ���ϴ� bool ����
	bool m_bdead;

	// �߷��� ��Ʈ�� �� ������
	float m_fvelocity;
	float m_fgravity;
	// jump ����
	bool m_bjump;
	// fire ����
	bool m_bfire;

	bool m_bgravity;

	RECT m_recHitBox;
	
public:
	// ������
	Object();
	// �Ҹ���
	virtual ~Object()
	{

	};

	// ������Ʈ �ʱ�ȭz
	virtual void Init() PURE;
	// ������Ʈ ������
	virtual void Run() PURE;
	// ������Ʈ ��� 
	virtual void Render(HDC& _hdc, HWND& _hWnd) PURE;
	// ������Ʈ �ı�
	virtual void Destroy() PURE;
	// struct �������� 
	//virtual ST_OBJECT GetStruct() PURE;

	// dbject�� �������� �ִϸ��̼ǿ� �߰��� �Լ�
	void Aniimage(ST_OBJECT& _obj);
	//void hitbox(RECT _rec1, RECT _rec2);

	int Getobjstate() { return m_iobjstate; };
	void Setobjstate(int _objstate) { m_iobjstate = _objstate; };
	// iter �� vector �ֱ�
	bool GetIter(std::vector<Object*>& _obj);

	// object�� ������� �Լ�
	virtual bool bObjDead() PURE;

	// struct ä��� �Լ� 
	void SetObjStruct(ST_OBJECT& _obj, int _recSrcright, int _recSrcbottom, int _poriginSrcx, int _poriginSrcy,
		int _recDestright, int _recDestbottom, int _posoriginDestx, int _posoriginDesty, 
		int _iobjmove, int _iWidthnum, int _iHightnum);

	void Gravity(ST_OBJECT* _obj);
	bool IntersectRectCheck(RECT* _rec1, RECT* _rec2);
	// Object���� ��濡 �� �� �ֵ��� ���ִ� �Լ� 
	void ObjStand(ST_OBJECT* _obj);
};

