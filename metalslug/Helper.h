#pragma once
#include "Object.h"
class Helper :
	public Object
{
protected:
	int m_ispeed;
	int m_item;

public:
	// 생성자
	Helper()
	{

	};
	// 소멸자
	virtual ~Helper()
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

	// 아이템 떨어트리기
	void ItemDrop();
};


