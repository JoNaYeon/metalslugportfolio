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
	// metalslug���� �޼��� ��� �� ���� 
	static MSG* m_msg;

public:

	// ������
	Mainfrm();
	// �Ҹ���
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

