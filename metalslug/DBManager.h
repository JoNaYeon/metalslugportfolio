#pragma once
#include "define.h"
/*#include "framework.h"
#include "Object.h"
#include <vector>*/

class Object;

class DBManager
	// 오브젝트가 생성되고 파괴되는 것을 관리
{
private:
	// DB 매니저 내부를 조종할 instance
	static DBManager* m_pinstance;
	// 오브젝트를 종류별로 담을 백터
	std::vector<Object*> m_vecBackObj[EOBJECT_OBJNUM];

	// 생성자
	DBManager()
	{

	};
	// 소멸자
	virtual ~DBManager()
	{

	}
public:
	// static 함수 : class의 선언 없이 사용이 가능.
	static DBManager* GetInstance();
	static void Create();
	void Destroy();
	void DeleteData();
	void Run();
};

