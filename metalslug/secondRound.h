#pragma once
#include "Game.h"
class secondRound :
    public Game
{
private:
	secondRound()
	{

	}
	virtual ~secondRound()
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

