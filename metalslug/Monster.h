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
	virtual void Init() PURE
	// ������Ʈ ������ (�������̵�)
	virtual void Run() PURE
	// ������Ʈ ��� (�������̵�)
	virtual void Render(HDC& _hdc, HWND& _hWnd) PURE
	// ������Ʈ �ı� (�������̵�)
	virtual void Destroy() PURE

	// �� ���� 
	virtual void Attack() PURE
};

