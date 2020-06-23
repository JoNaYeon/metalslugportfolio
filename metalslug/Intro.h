#pragma once
#include "Scene.h"
#include "Mainfrm.h"
#include <string.h>
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

