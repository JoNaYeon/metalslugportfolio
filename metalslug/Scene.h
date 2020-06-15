#pragma once

#include "define.h"

class Scene
{
public:
	// �ְ� �߻�Ŭ���� �̱� ������ ������/�Ҹ��� ��� public
	Scene()
	{
	}
	virtual ~Scene()
	{

	} 

	virtual void ObjectProduce() PURE;
	virtual void ObjectRend() PURE;
	virtual void ObjectDestroy() PURE;

	virtual void BackgroundProduce() PURE;
	virtual void BackgroundRend() PURE;
	virtual void BackgroundDestroy() PURE;

};

/*
class SceneBackground : Scene
{
public:
	SceneBackground() : Scene()
	{
	}
	~SceneBackground()
	{

	}
	void ObjectProduce();
	void BackgroundProduce();
};
*/