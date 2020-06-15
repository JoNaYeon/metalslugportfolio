#pragma once
#include "Game.h"


class BossStage :
    public Game
{
private:
	BossStage()
	{

	}
	virtual ~BossStage()
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

