#pragma once
#include "framework.h"
#include "RendManager.h"
#include "DBManager.h"
#include "InputManager.h"
#include "Scene.h"
#include "define.h"

class Mainfrm
{
protected:
	Scene* scene;
public:

	// ������
	Mainfrm()
	{
		scene = NULL;
	};
	// �Ҹ���
	virtual ~Mainfrm()
	{

	}

	void Create();
	void Initialize();
	void Run();
	void Destroy();
	bool SetScene(Scene* _scene);

	void BackgroundRun(Scene* _scene);
};

