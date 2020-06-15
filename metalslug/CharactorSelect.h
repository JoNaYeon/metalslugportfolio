#pragma once
#include "Scene.h"
class CharactorSelect :
    public Scene
{
private:
	CharactorSelect()
	{

	}
	virtual ~CharactorSelect()
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

