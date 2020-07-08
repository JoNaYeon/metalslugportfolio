#pragma once

#include "define.h"
//#include "framework.h"



class Object
{
protected:
	int m_iobjstate;

	// �ð��� ������ ����
	DWORD m_dcurTime;
	static DWORD m_dPrevTime;
	float m_fdelay;
	
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

	// Object�� �������� �ִϸ��̼� 
	void Animation(HDC& _hdc, ST_OBJECT& _objtop, ST_OBJECT& _objbottom, int& _iobjstate);
	// dbject�� �������� �ִϸ��̼ǿ� �߰��� �Լ�
	void Aniimage(ST_OBJECT& _objtop);
	void hitbox(RECT _rec1, RECT _rec2);

	int Getobjstate() { return m_iobjstate; };
	void Setobjstate(int _objstate) { m_iobjstate = _objstate; };
};

