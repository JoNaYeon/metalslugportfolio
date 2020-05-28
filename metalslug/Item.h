#pragma once
#include "Object.h"

class Item :
	public Object
{
protected:

public:
	// 생성자
	Item()
	{

	};
	// 소멸자
	virtual ~Item()
	{

	};

	// 오브젝트 초기화
	virtual void Init() PURE
	// 오브젝트 움직임
	virtual void Run() PURE
	// 오브젝트 출력
	virtual void Render() PURE
	// 오브젝트 파괴
	virtual void Destroy() PURE

	virtual void ItemState() PURE
};

