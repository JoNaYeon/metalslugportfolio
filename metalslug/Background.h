#pragma once
#include "Object.h"
#include "framework.h"


class Background :
	public Object
{
public:
	// class �����Ϸ��� public �ؾ� ��
	// ������
	Background()
	{

	};
	// �Ҹ���
	virtual ~Background()
	{

	};

	// ������Ʈ �ʱ�ȭ
	void Init();
	// ������Ʈ ������
	// ���������Լ��� ������ �������̵� �Ǿ�� �ϴµ� �������̵��� 
	// �Ű������� �ٸ��� �� �ǹǷ� �Ű����� �ٸ� �Լ��� �������ְ� ������
	// �������̵� �� �Լ��� ���� �ڿ� �����ε� ����� ��. 
	void Run();
	void Run(HWND _hWnd, HDC _hdc, HINSTANCE _hInst, RECT _recClient);
	// ������Ʈ ���
	void Render();
	// ������Ʈ �ı�
	void Destroy();
};

