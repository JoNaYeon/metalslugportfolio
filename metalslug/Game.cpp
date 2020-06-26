#include "Game.h"
#include "Background.h"
#include "RendManager.h"


Game::Game()
{
	Scene::m_iscenestate = E_SCENESTATE_GAME;
	// ������ ������ �� ��׶��� ������ �� �ֵ���.
	// �׷��� �Լ��� �� ���� ������! 
	Create();


	return;
}

void Game::Create()
{
	static Object* classbgptr = NULL;

	if (classbgptr == NULL)
	{
		classbgptr = new Background();
		// �̱����� �̿��Ͽ� static ���� ����� �Լ��� GetInstance() �� ���͸� �����ϴ� �Լ��� �ҷ���.
		// ���� �����͸� RendManager Ŭ������ �������μ� �˾Ƽ� ������Ʈ�� �����ϵ��� ��.
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
	// hWnd�� �������� �Լ�
	//HWND hWnd = GetConsoleHwnd();
	// �����Ҵ� �� ��� ������ ����
	//Object* ptr_objbg = new Background(hWnd);

	// Rend ���Ϳ� �־��༭ ������
	//RendManager::GetInstance()->SetVector(ptr_objbg, EOBJECT_BG);

	static Object* classbgptr = NULL;

	if (classbgptr == NULL)
	{
		classbgptr = new Background(m_hWnd);
		// �̱����� �̿��Ͽ� static ���� ����� �Լ��� GetInstance() �� ���͸� �����ϴ� �Լ��� �ҷ���.
		// ���� �����͸� RendManager Ŭ������ �������μ� �˾Ƽ� ������Ʈ�� �����ϵ��� ��.
		RendManager::GetInstance()->SetVector(classbgptr, EOBJECT_BG);
	}

	BackgroundRend();

	return;
}
void Game::BackgroundRend()
{
	if (m_hdc != NULL && m_hWnd != NULL)
	{
		// Rend class ���� �޾ƿ� Ŭ���̾�Ʈ ũ�� ��������
		RECT recClient = RendManager::GetInstance()->GetRect();

		// client ȭ�� ũ�⸦ �� �޾ƿ��� ������ ȭ�鿡 �ƹ��͵� �� ����! 
		GetClientRect(m_hWnd, &recClient);

		HBITMAP oldmembit;
		// ������۸� �� Memdc ����
		HDC hMemdc = CreateCompatibleDC(m_hdc);
		// �������� CreateCompatibleBitmap() ��� ����ϴ� Ŀ���� �Լ� (�ѽ�ǥ)
		HBITMAP hmembit = MakeDIBSection(hMemdc, recClient.right, recClient.bottom);
		oldmembit = (HBITMAP)SelectObject(hMemdc, hmembit);
		// ������ ����� �Ͼ�� �ٲ��ִ� �Լ�
		PatBlt(hMemdc, 0, 0, recClient.right, recClient.bottom, WHITENESS);

		// �ٲ���� mainfrm���� �����ϴ� backgr �ҷ��;���
		// ������Ʈ �׷��� �Լ� �ҷ����� 
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
