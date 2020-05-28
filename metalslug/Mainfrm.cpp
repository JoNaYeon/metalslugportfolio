#include "Mainfrm.h"
#include "RendManager.h"
#include "DBManager.h"
#include "InputManager.h"

// 깃허브 추가

void Mainfrm::Create()
{
	// Create 에 매니저 생성해주기 
	InputManager::Create();
	DBManager::Create();
	RendManager::Create();

	return;
};

void Mainfrm::Initialize()
{
	return;
};

void Mainfrm::Run()
{
	RendManager::GetInstance()->Rend();
	DBManager::GetInstance()->Run();
	InputManager::GetInstance()->Run();

	return;
};

void Mainfrm::Destroy()
{
	RendManager::GetInstance()->Destroy();
	DBManager::GetInstance()->Destroy();
	InputManager::GetInstance()->Destroy();

	return;
};