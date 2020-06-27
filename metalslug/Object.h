#pragma once

#include "define.h"
//#include "framework.h"



class Object
{
protected:
	int iobjstate;
	
public:
	// ������
	Object()
	{

	};
	// �Ҹ���
	virtual ~Object()
	{

	};

	// ������Ʈ �ʱ�ȭ
	virtual void Init() PURE;
	// ������Ʈ ������
	virtual void Run() PURE;
	// ������Ʈ ��� 
	virtual void Render(HDC& _hdc, HWND& _hWnd) PURE;
	// ������Ʈ �ı�
	virtual void Destroy() PURE;

	// Object�� �������� �ִϸ��̼� 
	void Animation(HDC _hdc, ST_OBJECT _obj, char* _cname);
};

