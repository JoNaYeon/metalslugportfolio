#pragma once
#include "Scene.h"
#include "Object.h"
//#include "generalfunction.h"

class Game :
    public Scene
{
private:
	bool m_bmakebullet;
public:
	Game();

	virtual ~Game()
	{

	}
	void Create();
	void Rend();
	void Destroy();
	//virtual ST_OBJECT GetStruct() PURE;

	void NextScene();
	bool bObjDead();
};

