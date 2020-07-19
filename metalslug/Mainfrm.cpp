#include "Mainfrm.h"
#include <stdio.h>
#include <iostream>
#include "InputManager.h"
// intro 임시 막아놓기용 header
#include "Game.h"

// 깃허브 추가


// static 을 cpp에 NULL로 초기화 해야지 쓸 수 있음.
HWND Mainfrm::m_hWnd = NULL;
Scene* Mainfrm::m_scene = NULL;



Mainfrm::Mainfrm()
{
	m_scene = NULL;
	m_msg = NULL;
};

void Mainfrm::Create()
{
	// Create 에 매니저 생성해주기 
	InputManager::Create();
	ObjManager::Create();

	return;
}

void Mainfrm::Initialize()
{
	if (m_scene == NULL)
	{
		// 맨 처음 만들 씬 
		// intro 막아놓기 
		Scene* ptrintro = new Game;

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
	ObjManager::GetInstance()->Run();
	InputManager::GetInstance()->Run();

	if (m_scene != NULL && m_scene->GetState() != E_SCENESTATE_INTRO)
	{
		ObjManager::GetInstance()->Rend(m_hWnd);
	}

	if (InputManager::GetInstance()->Keyboard(E_KEYSPACE) == true && m_scene->GetState() == E_SCENESTATE_INTRO)
	{
		NextScene();
	}

	return;
}

void Mainfrm::Destroy()
{
	ObjManager::GetInstance()->Destroy();
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

// 메세지 받아오는 함수
void Mainfrm::SetMsg(MSG* _msg)
{
	m_msg = _msg;
	return;
}

// 메세지 내보내는 함수
MSG* Mainfrm::GetMsg()
{
	return m_msg;
}


// 다음 씬으로 넘기기
void Mainfrm::NextScene()
{	
	if (m_scene != NULL)
	{
		if (m_scene->GetNextScene() == NULL)
		{
			// 다음 씬 생성
			m_scene->NextScene();

			// 다음 nextscene 가져오기 
			Scene* tempscene = m_scene->GetNextScene();

			// 현재 씬 파괴
			m_scene->Destroy();
			if (m_scene != NULL)
			{
				// Scene에 있던 것 청소 
				delete m_scene;
				m_scene = NULL;
			}

			// scene 에 nextscene 넣기
			m_scene = tempscene;

			// nextscene 청소
			m_scene->SetNextScene(NULL);
		}
	}
	return;
}