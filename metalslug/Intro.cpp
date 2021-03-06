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
// mainfrm 생성될 때 한번 실행
{
	char ctemp[100] = "MetalSlugOpening.avi";
	int iLen = strlen(ctemp);

	m_ptrAVIFileNmae = new char[iLen + 1];
	strcpy_s(m_ptrAVIFileNmae, iLen + 1, ctemp);

	// Mainfrm 에서 받아온 윈도우의 핸들 넣어주기
	MainhWnd = Mainfrm::GethWnd();

	// 만약 핸들이 있을 경우 
	if (m_hWndAVI)
	{
		// 핸들 내부 값 지우기고 초기화
		MCIWndClose(m_hWndAVI);
		MCIWndDestroy(m_hWndAVI);
		m_hWndAVI = 0;
	}

	// 핸들 새로 만들기 
	m_hWndAVI = MCIWndCreateA(MainhWnd, hInst,
		MCIWNDF_NOTIFYANSI | MCIWNDF_NOMENU |
		MCIWNDF_NOTIFYALL | MCIWNDF_NOPLAYBAR, m_ptrAVIFileNmae);

	if (m_hWndAVI && Scene::m_iscenestate == E_SCENESTATE_INTRO)
	{
		GetClientRect(MainhWnd, &m_recintro);
		// rect 크기만큼 avi 실행 
		SetWindowPos(m_hWndAVI, NULL, 0, 0, m_recintro.right, m_recintro.bottom,
			SWP_NOZORDER | SWP_NOMOVE);
		MCIWndPlay(m_hWndAVI);
	}

	return;
}


void Intro::Rend()
{
	if (m_hWndAVI && Scene::m_iscenestate == E_SCENESTATE_INTRO)
	{
		GetClientRect(MainhWnd, &m_recintro);
		// rect 크기만큼 avi 실행 
		SetWindowPos(m_hWndAVI, NULL, 0, 0, m_recintro.right, m_recintro.bottom, SWP_NOZORDER | SWP_NOMOVE);
		MCIWndPlay(m_hWndAVI);
	}
	return;
}


void Intro::Destroy()
{
	// 만약 avi 이름이 있을 경우 
	if (m_ptrAVIFileNmae != NULL)
	{ 
		// 지우고 초기화 
		delete[] m_ptrAVIFileNmae;
		m_ptrAVIFileNmae = NULL;
	}

	// 핸들 파괴 작업 
	DestroyWindow(m_hWndAVI);

	return;
}


void Intro::NextScene()
{
	if (m_nextscene != NULL)
	{
		delete m_nextscene;
		m_nextscene = NULL;
	}
	else
	{
		// 게임 실행하기 
		m_nextscene = new Game;
		m_iscenestate = E_SCENESTATE_GAME;
	}
	return;
}
