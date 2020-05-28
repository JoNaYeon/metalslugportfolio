#include "RendManager.h"
#include "framework.h"
#include "Object.h"

// 초기화
RendManager* RendManager::m_pinstance = NULL;

RendManager* RendManager::GetInstance()
{
	// create 를 하지 않았을 경우, 예외처리
	if (m_pinstance == NULL)
	{
		m_pinstance = new RendManager;
	}
	return m_pinstance;
};

void RendManager::Create(void)
{
	// m_pinstance 에 아무것도 들어있지 않을 때 생성하기
	if (m_pinstance == NULL)
	{
		m_pinstance = new RendManager;
	}
	return;
};

void RendManager::Destroy()
{
	// m_pinstance 에 뭔가 들어있을 경우, delete
	if (m_pinstance != NULL)
	{
		// 다 쓴 instance (동적할당) 삭제
		delete m_pinstance;
		m_pinstance = NULL;

		for (int i = 0; i < EOBJECT_OBJNUM; i++)
		{
			m_vecRendObj[i].clear();
		}
	}
	return;
};

void RendManager::Rend()
{
	for (int i = 0; i < EOBJECT_OBJNUM; i++)
	{
		for (int j = 0; j < m_vecRendObj[i].size(); j++)
		{
			// 백터 내부에 접근하여 Object class 의 내부 함수 (Render) 출력
			(m_vecRendObj[i])[j]->Render();
		}
	}
	return;
};