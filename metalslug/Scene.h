#pragma once

#include "define.h"
#include "framework.h"

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

	virtual void Create() PURE;
	virtual void Rend() PURE;
	virtual void Destroy() PURE;

	//virtual void BackgroundProduce() PURE;
	//virtual void BackgroundRend() PURE;
	//virtual void BackgroundDestroy() PURE;

};