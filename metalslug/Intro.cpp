#include "Intro.h"

void Intro::ObjectProduce()
{
	char ctemp[100] = "MetalSlugOpening.avi";
	int iLen = strlen(ctemp);

	m_ptrAVIFileNmae = new char[iLen + 1];
	strcpy_s(m_ptrAVIFileNmae, iLen + 1, ctemp);

	// Mainfrm 에서 받아온 윈도우의 핸들 넣어주기
	MainhWnd = Mainfrm::GethWnd();

	if (m_hWndAVI)
	{
		MCIWndClose(m_hWndAVI);
		MCIWndDestroy(m_hWndAVI);
		m_hWndAVI = 0;
	}
	m_hWndAVI = MCIWndCreateA(MainhWnd, hInst,
		MCIWNDF_NOTIFYANSI | MCIWNDF_NOMENU |
		MCIWNDF_NOTIFYALL | MCIWNDF_NOPLAYBAR, m_ptrAVIFileNmae);

	return;
}
void Intro::ObjectRend()
{
	if (m_hWndAVI)
	{
		GetClientRect(MainhWnd, &m_recintro);
		SetWindowPos(m_hWndAVI, NULL, 0, 0, m_recintro.right, m_recintro.bottom,
			SWP_NOZORDER | SWP_NOMOVE);
		MCIWndPlay(m_hWndAVI);
	}
	return;
}
void Intro::ObjectDestroy()
{
	if (m_ptrAVIFileNmae != NULL)
	{
		delete[] m_ptrAVIFileNmae;
		m_ptrAVIFileNmae = NULL;
	}
	// 핸들 파괴 작업 추가해야 함 
	return;
}

void Intro::BackgroundProduce()
{
	return;
}
void Intro::BackgroundRend()
{
	return;
}
void Intro::BackgroundDestroy()
{
	return;
}