#pragma once
#include "Scene.h"
#include "Background.h"
#include "RendManager.h"
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
	void ObjectProduce();
	void ObjectRend();
	void ObjectDestroy();

	void BackgroundProduce();
	void BackgroundRend();
	void BackgroundDestroy();
};

