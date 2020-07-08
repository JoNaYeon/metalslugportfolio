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
	static Scene* m_scene;
	static HWND m_hWnd;
	// metalslug에서 메세지 담아 올 변수 
	static MSG* m_msg;

public:

	// 생성자
	Mainfrm();
	// 소멸자
	virtual ~Mainfrm()
	{

	}

	void Create();
	void Initialize();
	void Run();
	void Destroy();

	static MSG* GetMsg();
	void SetMsg(MSG* _msg);

	static void SetScene(Scene* _scene);
	static void SethWnd(HWND _hWnd);
	static HWND GethWnd(void);

	static void NextScene();
};

