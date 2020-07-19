#include "Game.h"
#include "Background.h"
#include "ObjManager.h"
#include "InputManager.h"
#include "PlayerNormal.h"
#include "MonsterZombieMan.h"


Game::Game()
{
	Scene::m_iscenestate = E_SCENESTATE_GAME;
	// ������ ������ �� ��׶��� ������ �� �ֵ���.
	// �׷��� �Լ��� �� ���� ������! 
	//Create();

	m_bmakebullet = false;


	return;
}

void Game::Create()
{
	Object* classbgptr = NULL;
	Object* classuserptr = NULL;
	Object* classmonsterptr = NULL;

	if (classbgptr == NULL)
	{
		classbgptr = new Background();
		// �̱����� �̿��Ͽ� static ���� ����� �Լ��� GetInstance() �� ���͸� �����ϴ� �Լ��� �ҷ���.
		// ���� �����͸� ObjManager Ŭ������ �������μ� �˾Ƽ� ������Ʈ�� �����ϵ��� ��.
		// Destroy �� ���� rend �Ŵ������� clear �ϰ� dm �Ŵ������� delete
		ObjManager::GetInstance()->SetVector(classbgptr, EOBJECT_BG);
	}

	if (classuserptr == NULL)
	{
		// �÷��̾� �������ֱ� 
		classuserptr = new PlayerNormal();
		ObjManager::GetInstance()->SetVector(classuserptr, EOBJECT_OBJ);
	}

	if (classmonsterptr == NULL)
	{
		// ���� �������ֱ� 
		classmonsterptr = new MonsterZombieMan();
		ObjManager::GetInstance()->SetVector(classmonsterptr, EOBJECT_OBJ);
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

bool Game::bObjDead()
{
	return false;
}