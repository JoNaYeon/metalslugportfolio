#include "Game.h"
#include "Background.h"
#include "RendManager.h"
#include "InputManager.h"
#include "DBManager.h"
#include "PlayerNormal.h"
#include "Bullet.h"


Game::Game()
{
	Scene::m_iscenestate = E_SCENESTATE_GAME;
	// ������ ������ �� ��׶��� ������ �� �ֵ���.
	// �׷��� �Լ��� �� ���� ������! 
	Create();

	m_bmakebullet = false;
	m_classobjptr = NULL;


	return;
}

void Game::Create()
{
	static Object* classbgptr = NULL;
	static Object* classuserptr = NULL;

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
	if (InputManager::GetInstance()->Keyboard(E_KEYFIRE) == true && m_classobjptr == NULL)
	{
		m_classobjptr = new Bullet();

		m_classobjptr->Setobjstate(E_GUNSTATE_NORMAL);
		RendManager::GetInstance()->SetVector(m_classobjptr, EOBJECT_OBJ);
		DBManager::GetInstance()->SetVector(m_classobjptr, EOBJECT_OBJ);

	}

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