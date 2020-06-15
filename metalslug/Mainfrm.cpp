#include "Mainfrm.h"

// ����� �߰�

void Mainfrm::Create()
{
	// Create �� �Ŵ��� �������ֱ� 
	InputManager::Create();
	DBManager::Create();
	RendManager::Create();
	// scene ����
	if (scene != NULL)
	{
		scene->BackgroundProduce();
	}

	return;
}

void Mainfrm::Initialize()
{
	return;
}


void Mainfrm::Run()
{
	//RendManager::GetInstance()->Rend();
	// Rend() �� WN_PAINT �� �ű�.
	DBManager::GetInstance()->Run();
	InputManager::GetInstance()->Run();

	return;
}

void Mainfrm::Destroy()
{
	RendManager::GetInstance()->Destroy();
	DBManager::GetInstance()->Destroy();
	InputManager::GetInstance()->Destroy();

	return;
}

void Mainfrm::GetScene(Scene* _scene)
{
	scene = _scene;
	return;
}