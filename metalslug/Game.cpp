#include "Game.h"


Game::Game()
{
	// ������ ������ �� ��׶��� ������ �� �ֵ���.
	// �׷��� �Լ��� �� ���� ������! 
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
	// hWnd�� �������� �Լ�
	//HWND hWnd = GetConsoleHwnd();
	// �����Ҵ� �� ��� ������ ����
	//Object* ptr_objbg = new Background(hWnd);

	// Rend ���Ϳ� �־��༭ ������
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