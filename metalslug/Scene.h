#pragma once

#include "define.h"
#include "framework.h"

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

	virtual void Create() PURE;
	virtual void Rend() PURE;
	virtual void Destroy() PURE;

	//virtual void BackgroundProduce() PURE;
	//virtual void BackgroundRend() PURE;
	//virtual void BackgroundDestroy() PURE;

};