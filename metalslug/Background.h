#pragma once
#include "Object.h"
class Background :
	public Object
{
	// 생성자
	Background()
	{

	};
	// 소멸자
	virtual ~Background()
	{

	};

	// 오브젝트 초기화
	void Init();
	// 오브젝트 움직임
	void Run();
	// 오브젝트 출력
	void Render();
	// 오브젝트 파괴
	void Destroy();
};

