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

<<<<<<< HEAD
	//Scene* Next();
=======
	void NextScene();
>>>>>>> c4b6101c5499d62d22223c1428cc6798c773b7bb
};

