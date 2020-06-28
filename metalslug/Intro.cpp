#include "Intro.h"

#include "Mainfrm.h"
#include <string.h>
#include "Game.h"


Intro::Intro()
{
	m_ptrAVIFileNmae = NULL;
	m_hWndAVI = NULL;
	m_recintro = { 0,0,0,0 };
	MainhWnd = NULL;
	Scene::m_iscenestate = E_SCENESTATE_INTRO;
}


void Intro::Create()
// mainfrm ������ �� �ѹ� ����
{
	char ctemp[100] = "MetalSlugOpening.avi";
	int iLen = strlen(ctemp);

	m_ptrAVIFileNmae = new char[iLen + 1];
	strcpy_s(m_ptrAVIFileNmae, iLen + 1, ctemp);

	// Mainfrm ���� �޾ƿ� �������� �ڵ� �־��ֱ�
	MainhWnd = Mainfrm::GethWnd();

	// ���� �ڵ��� ���� ��� 
	if (m_hWndAVI)
	{
		// �ڵ� ���� �� ������ �ʱ�ȭ
		MCIWndClose(m_hWndAVI);
		MCIWndDestroy(m_hWndAVI);
		m_hWndAVI = 0;
	}

	// �ڵ� ���� ����� 
	m_hWndAVI = MCIWndCreateA(MainhWnd, hInst,
		MCIWNDF_NOTIFYANSI | MCIWNDF_NOMENU |
		MCIWNDF_NOTIFYALL | MCIWNDF_NOPLAYBAR, m_ptrAVIFileNmae);

	if (m_hWndAVI && Scene::m_iscenestate == E_SCENESTATE_INTRO)
	{
		GetClientRect(MainhWnd, &m_recintro);
		// rect ũ�⸸ŭ avi ���� 
		SetWindowPos(m_hWndAVI, NULL, 0, 0, m_recintro.right, m_recintro.bottom,
			SWP_NOZORDER | SWP_NOMOVE);
		MCIWndPlay(m_hWndAVI);
	}

	return;
}


void Intro::Rend()
{
	return;
}


void Intro::Destroy()
{
	// ���� avi �̸��� ���� ��� 
	if (m_ptrAVIFileNmae != NULL)
	{ 
		// ����� �ʱ�ȭ 
		delete[] m_ptrAVIFileNmae;
		m_ptrAVIFileNmae = NULL;
	}

	// �ڵ� �ı� �۾� 
	DestroyWindow(m_hWndAVI);

	return;
}

/*Scene* Intro::Next()
{
	// ���� intro ���� �Ѿ���� ��� ù scene ó�� 
	if (m_iscenestate == E_SCENESTATE_INTRO)
	{
		m_iscenestate = E_SCENESTATE_GAME;

		delete m_nextscene;
		m_nextscene = NULL;

		m_nextscene = new Game;
	}

	Destroy();

	return m_nextscene;
}*/


/*Scene* Intro::Next()
{
	if (Scene::m_nextscene != NULL)
	{
		delete Scene::m_nextscene;
		Scene::m_nextscene = NULL;
	}
	else
	{
		Scene::m_nextscene = new Game;
	}

	return 0;
}*/

void Intro::NextScene()
{
	if (m_nextscene != NULL)
	{
		delete m_nextscene;
		m_nextscene = NULL;
	}
	else
	{
		m_nextscene = new Game;
	}
	return;
}