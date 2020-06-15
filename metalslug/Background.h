#pragma once
//#include "Object.h"
#include "ObjectImage.h"
//#include "framework.h"
//#include "metalslug.h"
//#include "define.h"
#include "RendManager.h"



class Background :
	public Object
{
private:
	// �̹����� ����� ������ ����
	POINT m_pimagesize;
	// �̹��� ������ ��� ��ŸƮ ��ǥ��
	POINT m_pimagestartposition;
	// �̹����� ��ǥ�� �������� ����
	POINT m_pbackgroundposition1;
	POINT m_pbackgroundposition2;
	ObjectImage m_obimg1;
	ObjectImage m_obimg2;
	HWND m_hWnd;

public:
	enum backgroundsize
	{
		BACKGROUNDX = 740,
		BACKGROUNDY = 220
	};
	enum backgroundposition
	{
		BACKGROUNDPOSX = 960,
		BACKGROUNDPOSY = 180
	};

	// class �����Ϸ��� public �ؾ� ��
	// ������
	Background(HWND _hWnd)
	{
		m_hWnd = _hWnd;
		m_pimagesize = { 0, };
		m_pimagestartposition = { 0, };
		m_pbackgroundposition1 = { 0, 0 };
		m_pbackgroundposition2 = { 3 * BACKGROUNDX, 0 };
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
	//void Run(HWND _hWnd, HDC& _hdc, HINSTANCE _hInst, RECT _recClient);
	// ������Ʈ ���
	void Render(HDC& _hdc, HWND& _hWnd);
	// ������Ʈ �ı�
	void Destroy();
};

 