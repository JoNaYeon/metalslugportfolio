#pragma once
#include "Scene.h"
class Menu :
    public Scene
{
private:
	Menu()
	{

	}
	virtual ~Menu()
	{

	}
public:
	void ObjectProduce();
	void ObjectRend();
	void ObjectDestroy();

	void BackgroundProduce();
	void BackgroundRend();
	void BackgroundDestroy();
};

