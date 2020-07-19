#include "Mainfrm.h"
#include <stdio.h>
#include <iostream>
#include "InputManager.h"
// intro �ӽ� ���Ƴ���� header
#include "Game.h"

// ����� �߰�


// static �� cpp�� NULL�� �ʱ�ȭ �ؾ��� �� �� ����.
HWND Mainfrm::m_hWnd = NULL;
Scene* Mainfrm::m_scene = NULL;



Mainfrm::Mainfrm()
{
	m_scene = NULL;
	m_msg = NULL;
};

void Mainfrm::Create()
{
	// Create �� �Ŵ��� �������ֱ� 
	InputManager::Create();
	ObjManager::Create();

	return;
}

void Mainfrm::Initialize()
{
	if (m_scene == NULL)
	{
		// �� ó�� ���� �� 
		// intro ���Ƴ��� 
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

// �޼��� �޾ƿ��� �Լ�
void Mainfrm::SetMsg(MSG* _msg)
{
	m_msg = _msg;
	return;
}

// �޼��� �������� �Լ�
MSG* Mainfrm::GetMsg()
{
	return m_msg;
}


// ���� ������ �ѱ��
void Mainfrm::NextScene()
{	
	if (m_scene != NULL)
	{
		if (m_scene->GetNextScene() == NULL)
		{
			// ���� �� ����
			m_scene->NextScene();

			// ���� nextscene �������� 
			Scene* tempscene = m_scene->GetNextScene();

			// ���� �� �ı�
			m_scene->Destroy();
			if (m_scene != NULL)
			{
				// Scene�� �ִ� �� û�� 
				delete m_scene;
				m_scene = NULL;
			}

			// scene �� nextscene �ֱ�
			m_scene = tempscene;

			// nextscene û��
			m_scene->SetNextScene(NULL);
		}
	}
	return;
}