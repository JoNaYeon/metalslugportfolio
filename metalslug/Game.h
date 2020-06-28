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

<<<<<<< HEAD
	//Scene* Next();
=======
	void NextScene();
>>>>>>> c4b6101c5499d62d22223c1428cc6798c773b7bb
};

