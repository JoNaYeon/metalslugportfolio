#include "Mainfrm.h"

// ����� �߰�

// static �� cpp�� NULL�� �ʱ�ȭ �ؾ��� �� �� ����.
HWND Mainfrm::m_hWnd = NULL;
HDC Mainfrm::m_hdc = NULL;
PAINTSTRUCT Mainfrm::m_ps;

Mainfrm::Mainfrm()
{
	m_scene = NULL;
	//m_hdc = NULL;
};

void Mainfrm::Create()
{
	// Create �� �Ŵ��� �������ֱ� 
	InputManager::Create();
	DBManager::Create();
	RendManager::Create();

	return;
}

void Mainfrm::Initialize()
{
	if (m_scene == NULL)
	{
		// �� ó�� ���� �� 
		Scene* ptrgame = new Game;

		if (ptrgame != NULL)
		{
			SetScene(ptrgame);
			m_scene->Create();
		}
	}
	return;
}


void Mainfrm::Run()
{
	// �ӽù��� 
	CreateDC();

	RendManager::GetInstance()->Rend(m_hdc, m_hWnd);
	DBManager::GetInstance()->Run();
	InputManager::GetInstance()->Run();

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
	if (m_hdc != NULL)
	{
		EndPaint(m_hWnd, &m_ps);
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


void Mainfrm::CreateDC()
{
	// dc�� ���� 
	if (m_hdc == NULL)
	{
		m_hdc = BeginPaint(m_hWnd, &m_ps);
	}

	return;
}