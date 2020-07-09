#include "Game.h"
#include "Background.h"
#include "RendManager.h"
#include "InputManager.h"
#include "DBManager.h"
#include "PlayerNormal.h"


Game::Game()
{
	Scene::m_iscenestate = E_SCENESTATE_GAME;
	// ������ ������ �� ��׶��� ������ �� �ֵ���.
	// �׷��� �Լ��� �� ���� ������! 
	Create();

	m_bmakebullet = false;


	return;
}

void Game::Create()
{
	Object* classbgptr = NULL;
	Object* classuserptr = NULL;

	if (classbgptr == NULL)
	{
		classbgptr = new Background();
		// �̱����� �̿��Ͽ� static ���� ����� �Լ��� GetInstance() �� ���͸� �����ϴ� �Լ��� �ҷ���.
		// ���� �����͸� RendManager Ŭ������ �������μ� �˾Ƽ� ������Ʈ�� �����ϵ��� ��.
		// Destroy �� ���� rend �Ŵ������� clear �ϰ� dm �Ŵ������� delete
		RendManager::GetInstance()->SetVector(classbgptr, EOBJECT_BG);
		DBManager::GetInstance()->SetVector(classbgptr, EOBJECT_BG);
	}

	if (classuserptr == NULL)
	{
		// �÷��̾� �������ֱ� 
		classuserptr = new PlayerNormal();
		RendManager::GetInstance()->SetVector(classuserptr, EOBJECT_OBJ);
		DBManager::GetInstance()->SetVector(classuserptr, EOBJECT_OBJ);
	}

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


void Game::NextScene()
{
	return;
}