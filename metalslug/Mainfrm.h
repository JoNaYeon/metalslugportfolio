#pragma once
#include "framework.h"
#include "RendManager.h"
#include "DBManager.h"
#include "InputManager.h"
#include "Scene.h"
#include "Intro.h"
#include "define.h"


class Mainfrm
{
protected:
	Scene* m_scene;
	static HWND m_hWnd;
	static PAINTSTRUCT m_ps;
	int m_imsg;
public:

	// 持失切
	Mainfrm();
	// 社瑚切
	virtual ~Mainfrm()
	{

	}

	void Create();
	void Initialize();
	void Run();
	void Destroy();
	void SetScene(Scene* _scene);

	static void SethWnd(HWND _hWnd);
	static HWND GethWnd(void);
	
<<<<<<< HEAD
	void NextScene();
=======
	void NextScene(Scene* _scene);
>>>>>>> c4b6101c5499d62d22223c1428cc6798c773b7bb
};

