#include "Mainfrm.h"

// ����� �߰�

void Mainfrm::Create()
{
	// Create �� �Ŵ��� �������ֱ� 
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
	// Rend() �� WN_PAINT �� �ű�.
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
	// scene ����
	if (scene != NULL)
	{
		scene->BackgroundProduce();
	}
	return;
}