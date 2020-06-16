#pragma once
#include "Scene.h"
#include "Background.h"
#include "RendManager.h"
//#include "generalfunction.h"

class Game :
    public Scene
{
private:
public:
	Game();

	virtual ~Game()
	{

	}
	void ObjectProduce();
	void ObjectRend();
	void ObjectDestroy();

	void BackgroundProduce();
	void BackgroundRend();
	void BackgroundDestroy();

	static void SethWnd(HWND _hWnd);
	static HWND GethWnd(void);
	static void Sethdc(HDC _hdc);
	static HDC Gethdc(void);
};

