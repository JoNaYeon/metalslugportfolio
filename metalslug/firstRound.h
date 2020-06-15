#pragma once
#include "Game.h"
class firstRound :
    public Game
{
private:
	firstRound()
	{

	}
	virtual ~firstRound()
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

