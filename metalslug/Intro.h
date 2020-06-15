#pragma once
#include "Scene.h"
class Intro :
    public Scene
{
private:
	Intro()
	{

	}
	virtual ~Intro()
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

