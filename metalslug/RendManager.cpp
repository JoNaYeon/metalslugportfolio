#include "RendManager.h"

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
		// 내부 데이터를 삭제해준 뒤에 동적할당 된 주소값을 가리키는 m_pinstance 삭제.
		// 순서가 잘못 되면 주소값에 접근할 수 없어서 잘못된 주소값을 clear() 하고 본래 있던 데이터 clear가 안 됨.
		for (int i = 0; i < EOBJECT_OBJNUM; i++)
		{
			m_vecRendObj[i].clear();
		}

		// 다 쓴 instance (동적할당) 삭제
		delete m_pinstance;
		m_pinstance = NULL;

	}
	return;
};

void RendManager::Rend(HDC& _hdc, HWND& _hWnd)
{
	for (int i = 0; i < EOBJECT_OBJNUM; i++)
	{
		for (int j = 0; j < m_vecRendObj[i].size(); j++)
		{
			// 백터 내부에 접근하여 Object class 의 내부 함수 (Render) 출력
			(m_vecRendObj[i])[j]->Render(_hdc, _hWnd);
		}
	}
	return;
};

void RendManager::SetVector(Object* _object, E_OBJECT _Eobjectkind)
{
	// vector ptr 을 넣어서 Rend() 할 수 있도록.
	// enum 자료형으로 사용
	// 오브젝트별로 다른 enum 사용해서 구분지어 vector에 넣을 수 있도록
	m_vecRendObj[_Eobjectkind].push_back(_object);

	return;
}

RECT RendManager::GetRect()
{
	return m_recClient;
}

void RendManager::SetRect(RECT _recClient)
{
	m_recClient = _recClient;
	return;
}


void RendManager::DeleteVector(E_OBJECT e_obj)
{
	std::vector<Object*>::iterator obj_iter = m_vecRendObj[e_obj].begin();

	for (; obj_iter != m_vecRendObj[e_obj].end(); obj_iter++)
	{
		Object* deleteptr = (Object*)*obj_iter;
		delete deleteptr;
		deleteptr = NULL;
	}

	m_vecRendObj[e_obj].clear();

	return;
}