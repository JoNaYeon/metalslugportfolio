#include "Mainfrm.h"
#include "RendManager.h"
#include "DBManager.h"
#include "InputManager.h"

// ����� �߰�

void Mainfrm::Create()
{
	// Create �� �Ŵ��� �������ֱ� 
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