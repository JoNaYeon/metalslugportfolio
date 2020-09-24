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

	// ���ȭ���� ������ ������ ��� POINT
	POINT ptTileMove;

	//std::vector<POINT> m_vecpos;



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
	//void BackgroundTile(int _i);
	// ��ü���� y�� ��ġ�� ����� �Լ�
	//int GetTileY(Object* _obj);
	/*void BackgroundTileset(int _i, int _iposy1, int _iposy2, 
		int _iposx1, int _iposx2, RECT* _rec);*/
	//POINT GetRatio(int iwidth, int iheight);

	bool bObjDead();

	// ��� �̵� �Լ� 
	void BackgroundMove(E_USERSTATE _e_state);
	DISPLAYINFO GetBG() { return m_DisBG; };

	//std::vector<POINT>* GetBGTilevecpt() { return &m_vecpos; };
	
};

 