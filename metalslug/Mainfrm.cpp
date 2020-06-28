#include "Mainfrm.h"
#include <stdio.h>
#include <iostream>

// 깃허브 추가

// static 을 cpp에 NULL로 초기화 해야지 쓸 수 있음.
HWND Mainfrm::m_hWnd = NULL;
PAINTSTRUCT Mainfrm::m_ps;

Mainfrm::Mainfrm()
{
	m_scene = NULL;
	//m_hdc = NULL;
	m_imsg = 0;
};

void Mainfrm::Create()
{
	// Create 에 매니저 생성해주기 
	InputManager::Create();
	DBManager::Create();
	RendManager::Create();

	// 영상 재생을 위한 hwnd 와 이름 담는 변수
	/*HWND hWndAVI = 0;
	char cAVIFileNmae[] = "MetalSlugOpening.avi";
	RECT rt = { NULL, };*/

	return;
}

void Mainfrm::Initialize()
{
	if (m_scene == NULL)
	{
		// 맨 처음 만들 씬 
		Scene* ptrintro = new Intro;

		if (ptrintro != NULL)
		{
			SetScene(ptrintro);
			m_scene->Create();
		}
	}
	return;
}


void Mainfrm::Run()
{
	
	DBManager::GetInstance()->Run();
	InputManager::GetInstance()->Run();
	if (m_scene != NULL && m_scene->GetState() != E_SCENESTATE_INTRO)
	{
		RendManager::GetInstance()->Rend(m_hWnd);
	}

	return;
}

void Mainfrm::Destroy()
{
	RendManager::GetInstance()->Destroy();
	DBManager::GetInstance()->Destroy();
	InputManager::GetInstance()->Destroy();

	if (m_scene != NULL)
	{
		delete m_scene;
		m_scene = NULL;
	}
	return;
}

void Mainfrm::SetScene(Scene* _scene)
{
	if (_scene != NULL)
	{
		m_scene = _scene;
	}
	return;
}


void Mainfrm::SethWnd(HWND hWnd)
{
	if (hWnd != NULL)
	{
		m_hWnd = hWnd;
		//CreateDC();
	}
	return;
}


HWND Mainfrm::GethWnd(void)
{
	if (m_hWnd != NULL)
	{
		return m_hWnd;
	}
	return FALSE;
}


void Mainfrm::NextScene(Scene* _scene)
{
	// 입력 받으면

	Scene* mainfrmnextscene = Scene::GetNext();

	if (mainfrmnextscene != NULL)
	{
		delete mainfrmnextscene;
		mainfrmnextscene = NULL;
	}
	else
	{
		// 다음 씬 생성
		_scene->NextScene();
	}

	return;
}