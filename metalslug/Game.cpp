#include "Game.h"


Game::Game()
{
	// 게임이 생성될 때 백그라운드 생성될 수 있도록.
	// 그러면 함수를 쓸 것이 없어짐! 
	BackgroundProduce();

	return;
}

void Game::ObjectProduce()
{
	return;
}
void Game::ObjectRend()
{
	return;
}
void Game::ObjectDestroy()
{
	return;
}

void Game::BackgroundProduce()
{
	// hWnd를 가져오는 함수
	//HWND hWnd = GetConsoleHwnd();
	// 동적할당 된 배경 포인터 변수
	//Object* ptr_objbg = new Background(hWnd);

	// Rend 백터에 넣어줘서 돌리기
	//RendManager::GetInstance()->SetVector(ptr_objbg, EOBJECT_BG);

	return;
}
void Game::BackgroundRend()
{
	return;
}
void Game::BackgroundDestroy()
{
	return;
}