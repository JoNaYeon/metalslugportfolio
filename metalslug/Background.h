#pragma once
#include "ObjectImage.h"
//#include "framework.h"


class Background :
	public Object
{
private:
	ObjectImage m_obimg1;
	ObjectImage m_obimg2;

	// ���ȭ�� ����ü
	DISPLAYINFO m_DisBG;
	IMAGEINFO m_ImgBG;

	// ��ü�� ��ġ ���¸� ǥ���ϴ� E_OBJECTMOVEPOS enum�� ���� int ����
	int m_objPosState;

	RECT m_recClient;

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
	RECT* BackgroundTile(int _itilemove);
	//POINT GetRatio(int iwidth, int iheight);

	bool bObjDead();

	// ��� �̵� �Լ� 
	void BackgroundMove(E_USERSTATE _e_state);
	DISPLAYINFO GetBG() { return m_DisBG; };
	
};

 