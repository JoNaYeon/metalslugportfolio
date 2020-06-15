#pragma once

#include "define.h"

class Scene
{
public:
	// 최고 추상클래스 이기 때문에 생성자/소멸자 모두 public
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