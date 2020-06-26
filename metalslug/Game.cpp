#include "Game.h"
#include "Background.h"
#include "RendManager.h"


Game::Game()
{
	Scene::m_iscenestate = E_SCENESTATE_GAME;
	// 게임이 생성될 때 백그라운드 생성될 수 있도록.
	// 그러면 함수를 쓸 것이 없어짐! 
	Create();


	return;
}

void Game::Create()
{
	static Object* classbgptr = NULL;

	if (classbgptr == NULL)
	{
		classbgptr = new Background();
		// 싱글톤을 이용하여 static 으로 선언된 함수인 GetInstance() 로 백터를 저장하는 함수를 불러옴.
		// 백터 포인터를 RendManager 클래스에 넣음으로서 알아서 오브젝트가 존재하도록 함.
		RendManager::GetInstance()->SetVector(classbgptr, EOBJECT_BG);
	}

	Rend();
	return;
}
void Game::Rend()
{
	return;
}
void Game::Destroy()
{
	return;
}

Scene* Game::Next()
{
	return 0;
}

/*void Game::BackgroundProduce()
{
	// hWnd를 가져오는 함수
	//HWND hWnd = GetConsoleHwnd();
	// 동적할당 된 배경 포인터 변수
	//Object* ptr_objbg = new Background(hWnd);

	// Rend 백터에 넣어줘서 돌리기
	//RendManager::GetInstance()->SetVector(ptr_objbg, EOBJECT_BG);

	static Object* classbgptr = NULL;

	if (classbgptr == NULL)
	{
		classbgptr = new Background(m_hWnd);
		// 싱글톤을 이용하여 static 으로 선언된 함수인 GetInstance() 로 백터를 저장하는 함수를 불러옴.
		// 백터 포인터를 RendManager 클래스에 넣음으로서 알아서 오브젝트가 존재하도록 함.
		RendManager::GetInstance()->SetVector(classbgptr, EOBJECT_BG);
	}

	BackgroundRend();

	return;
}
void Game::BackgroundRend()
{
	if (m_hdc != NULL && m_hWnd != NULL)
	{
		// Rend class 에서 받아온 클라이언트 크기 가져오기
		RECT recClient = RendManager::GetInstance()->GetRect();

		// client 화면 크기를 안 받아오고 있으니 화면에 아무것도 안 뜨죠! 
		GetClientRect(m_hWnd, &recClient);

		HBITMAP oldmembit;
		// 더블버퍼링 할 Memdc 생성
		HDC hMemdc = CreateCompatibleDC(m_hdc);
		// 오류나서 CreateCompatibleBitmap() 대신 사용하는 커스텀 함수 (한슬표)
		HBITMAP hmembit = MakeDIBSection(hMemdc, recClient.right, recClient.bottom);
		oldmembit = (HBITMAP)SelectObject(hMemdc, hmembit);
		// 윈도우 배경을 하얗게 바꿔주는 함수
		PatBlt(hMemdc, 0, 0, recClient.right, recClient.bottom, WHITENESS);

		// 바꿔야함 mainfrm에서 진행하니 backgr 불러와야함
		// 오브젝트 그려줄 함수 불러오기 
		RendManager::GetInstance()->Rend(hMemdc, m_hWnd);

		BitBlt(m_hdc, 0, 0, recClient.right, recClient.bottom, hMemdc, 0, 0, SRCCOPY);

		SelectObject(hMemdc, oldmembit);

		DeleteDC(hMemdc);
		DeleteObject(hmembit);
	}

	return;
}
void Game::BackgroundDestroy()
{
	return;
}*/
