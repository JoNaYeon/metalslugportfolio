#include "Game.h"
#include "Background.h"
#include "ObjManager.h"
#include "InputManager.h"
#include "PlayerNormal.h"
#include "MonsterZombieMan.h"


Game::Game()
{
	Scene::m_iscenestate = E_SCENESTATE_GAME;
	// 게임이 생성될 때 백그라운드 생성될 수 있도록.
	// 그러면 함수를 쓸 것이 없어짐! 
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
		// 싱글톤을 이용하여 static 으로 선언된 함수인 GetInstance() 로 백터를 저장하는 함수를 불러옴.
		// 백터 포인터를 ObjManager 클래스에 넣음으로서 알아서 오브젝트가 존재하도록 함.
		// Destroy 할 때에 rend 매니저에서 clear 하고 dm 매니저에서 delete
		ObjManager::GetInstance()->SetVector(classbgptr, EOBJECT_BG);
	}

	if (classuserptr == NULL)
	{
		// 플레이어 생성해주기 
		classuserptr = new PlayerNormal();
		ObjManager::GetInstance()->SetVector(classuserptr, EOBJECT_USER);
	}

	if (classmonsterptr == NULL)
	{
		// 몬스터 생성해주기 
		classmonsterptr = new MonsterZombieMan();
		ObjManager::GetInstance()->SetVector(classmonsterptr, EOBJECT_MONSTER);
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