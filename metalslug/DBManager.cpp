#include "DBManager.h"
#include "Object.h"

// 초기화
DBManager* DBManager::m_pinstance = NULL;

DBManager* DBManager::GetInstance()
{
	// m_pinstance 에 아무것도 없을 경우, 생성
	if (m_pinstance == NULL)
	{
		m_pinstance = new DBManager;
	}
	return m_pinstance;
};

void DBManager::Create()
{
	// m_pinstance 에 아무것도 없을 경우, 생성
	if (m_pinstance == NULL)
	{
		m_pinstance = new DBManager;
	}	
	return;
};

void DBManager::Destroy()
{
	// 다 쓴 instance (동적할당) 삭제
	delete m_pinstance;
	m_pinstance = NULL;

	// Object (동적할당) delete 해줄 함수 호출
	DeleteData();

	return;
};

void DBManager::DeleteData()
{
	// m_pinstance 에 뭔가 들어있을 경우, delete
	if (m_pinstance != NULL)
	{
		for (int i = 0; i < EOBJECT_OBJNUM; i++)
		{
			for (int j = 0; j < m_vecBackObj[i].size(); j++)
			{
				delete (m_vecBackObj[i])[j];
				(m_vecBackObj[i])[j] = NULL;
			}
		}
	}
	return;
};

void DBManager::Run()
{
	for (int i = 0; i < EOBJECT_OBJNUM; i++)
	{
		for (int j = 0; j < m_vecBackObj[i].size(); j++)
		{
			// 백터 내부에 접근하여 Object class 의 내부 함수 (Run) 출력
			(m_vecBackObj[i])[j]->Run();
		}
	}
	return;
};

void DBManager::SetVector(Object* _object, E_OBJECT _Eobjectkind)
{
	// vector ptr 을 넣어서 Rend() 할 수 있도록.
	m_vecBackObj[_Eobjectkind].push_back(_object);

	return;
}