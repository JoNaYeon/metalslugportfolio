#pragma once
#include "Scene.h"
// 영상 재생을 위한 헤더 
#include <vfw.h>

class Intro :
    public Scene
{
private:
	//// 영상 재생을 위한 hwnd 와 이름 담는 변수
	char* m_ptrAVIFileNmae;
	HWND m_hWndAVI;
	RECT m_recintro;
	// Mainfrm 에서 받아온 윈도우의 핸들 넣어주기
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

