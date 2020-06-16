#include "Mainfrm.h"

// 깃허브 추가

void Mainfrm::Create()
{
	// Create 에 매니저 생성해주기 
	InputManager::Create();
	DBManager::Create();
	RendManager::Create();

	return;
}

void Mainfrm::Initialize()
{
	return;
}


void Mainfrm::Run()
{
	//RendManager::GetInstance()->Rend();
	// Rend() 는 WN_PAINT 로 옮김.
	DBManager::GetInstance()->Run();
	InputManager::GetInstance()->Run();
	if (scene != NULL)
	{
		BackgroundRun(scene);
	}

	return;
}

void Mainfrm::Destroy()
{
	RendManager::GetInstance()->Destroy();
	DBManager::GetInstance()->Destroy();
	InputManager::GetInstance()->Destroy();

	return;
}

bool Mainfrm::SetScene(Scene* _scene)
{
	if (_scene != NULL)
	{
		scene = _scene;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void Mainfrm::BackgroundRun(Scene* _scene)
{
	// scene 생성
	if (scene != NULL)
	{
		scene->BackgroundProduce();
	}
	return;
}