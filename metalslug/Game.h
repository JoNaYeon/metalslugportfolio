#pragma once
#include "Scene.h"
//#include "generalfunction.h"

class Game :
    public Scene
{
private:
public:
	Game();

	virtual ~Game()
	{

	}
	void Create();
	void Rend();
	void Destroy();

	Scene* Next();
};

