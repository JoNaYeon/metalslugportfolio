#pragma once
#include "Scene.h"
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
	 
public:
	Intro();
	virtual ~Intro()
	{
		
	}
	void Create();
	void Rend();
	void Destroy();

	Scene* Next();
};

