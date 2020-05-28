#pragma once
#include "define.h"
#include <vector>

class Object;

class RendManager
	// 오브젝트가 출력되는 것을 관리 
{
private:
	// Rend 매니저 내부를 조종할 instance
	static RendManager* m_pinstance;
	// 오브젝트를 종류별로 담을 백터
	std::vector<Object*> m_vecRendObj[EOBJECT_OBJNUM];

	// 생성자
	RendManager()
	{

	};
	// 소멸자
	virtual ~RendManager()
	{

	}
public:
	static RendManager* GetInstance();
	static void Create();
	void Destroy();
	void Rend();
};

