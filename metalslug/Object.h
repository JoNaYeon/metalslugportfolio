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

	// �Ѿ� ����ü
	//ST_OBJECT m_bullet;
	// �÷��̾� ����ü
	ST_OBJECT m_normalplayertop;
	ST_OBJECT m_normalplayerbottom;
	// ���� ����ü
	ST_OBJECT m_Monster;
	// ���ȭ�� ����ü
	ST_OBJECT m_BG1;
	ST_OBJECT m_BG2;


	//  objcet�� vector�� ���� iter
	std::vector<Object*>::iterator m_objiter;

	// �Ѿ��� ���� vector
	std::vector<Object*> m_vbullet;
	
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

	// Object�� �������� �ִϸ��̼� 
	void Animation(HDC& _hdc, ST_OBJECT& _obj, int& _iobjstate);
	// dbject�� �������� �ִϸ��̼ǿ� �߰��� �Լ�
	void Aniimage(ST_OBJECT& _objtop);
	void hitbox(RECT _rec1, RECT _rec2);

	int Getobjstate() { return m_iobjstate; };
	void Setobjstate(int _objstate) { m_iobjstate = _objstate; };
	// iter �� vector �ֱ�
	bool GetIter(std::vector<Object*>& _obj);
	// object�� ȭ�� ������ ������
	void ObjectOut(Object& _obj, std::vector<Object*>& _vecobj);
	ST_OBJECT GetStruct(int _iobjstate);

};

