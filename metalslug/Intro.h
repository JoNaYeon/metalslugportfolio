#pragma once
#include "Scene.h"
#include "Mainfrm.h"
#include <string.h>
// ���� ����� ���� ��� 
#include <vfw.h>

class Intro :
    public Scene
{
private:
	//// ���� ����� ���� hwnd �� �̸� ��� ����
	char* m_ptrAVIFileNmae;
	HWND m_hWndAVI;
	RECT m_recintro;
	// Mainfrm ���� �޾ƿ� �������� �ڵ� �־��ֱ�
	HWND MainhWnd;

	Intro()
	{
		m_hWndAVI = 0;
	}
	virtual ~Intro()
	{

	}
public:
	void ObjectProduce();
	void ObjectRend();
	void ObjectDestroy();

	void BackgroundProduce();
	void BackgroundRend();
	void BackgroundDestroy();

};

