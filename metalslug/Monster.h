#pragma once
#include "Object.h"
class Monster :
	public Object
{
protected:
	int m_ihp;
	int m_istrength;
	int m_ispeed;

	// ���� ����ü
	//DISPLAYINFO m_DisMon;
	//IMAGEINFO m_ImgMon;

	bool m_bsee;

public:
	// ������
	Monster()
	{
		m_ihp = 0;
		m_istrength = 0;
		m_ispeed = 0;

	};
	// �Ҹ���
	virtual ~Monster()
	{

	};

	// ������Ʈ �ʱ�ȭ (�������̵�)
	virtual void Init() PURE;
	// ������Ʈ ������ (�������̵�)
	virtual void Run() PURE;
	// ������Ʈ ��� (�������̵�)
	virtual void Render(HDC& _hdc, HWND& _hWnd) PURE;
	// ������Ʈ �ı� (�������̵�)
	virtual void Destroy() PURE;
	bool bObjDead();

	// �� ���� 
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

