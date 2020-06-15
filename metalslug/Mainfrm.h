#pragma once
#include "framework.h"
#include "RendManager.h"
#include "DBManager.h"
#include "InputManager.h"
#include "Scene.h"

class Mainfrm
{
protected:
	Scene* scene;
public:

	// 持失切
	Mainfrm()
	{
		scene = NULL;
	};
	// 社瑚切
	virtual ~Mainfrm()
	{

	}

	void Create();
	void Initialize();
	void Run();
	void Destroy();
	void GetScene(Scene* _scene);
};

