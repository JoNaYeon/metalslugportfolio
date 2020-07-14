#pragma once
#include "ObjectImage.h"
//#include "framework.h"


class Background :
	public Object
{
private:
	ObjectImage m_obimg1;
	ObjectImage m_obimg2;
	POINT pBGsize;

	int m_ibgTile1;
	int m_ibgTile2;

public:

	// class �����Ϸ��� public �ؾ� ��
	// ������
	Background();
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
	// ������Ʈ ���
	void Render(HDC& _hdc, HWND& _hWnd);
	// ������Ʈ �ı�
	void Destroy();
	// Ÿ���� ��� �� �Լ�
	void BackgroundTile(HDC _hdc, int _itilemove);
	POINT GetRatio(int iwidth, int iheight);

	bool bObjDead();
};

 