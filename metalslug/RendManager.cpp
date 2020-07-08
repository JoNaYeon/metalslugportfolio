#include "RendManager.h"

//#include "define.h"
//#include "framework.h"
#include "Object.h"
//#include <vector>
#include "Scene.h"
#include "InputManager.h"

// 초기화`
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

void RendManager::Rend(HWND& _hWnd)
{
	if (_hWnd != NULL)
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(_hWnd, &ps);

		// client 화면 크기를 안 받아오고 있으니 화면에 아무것도 안 뜨죠! 
		GetClientRect(_hWnd, &m_recClient);

		HBITMAP oldmembit;
		// 더블버퍼링 할 Memdc 생성
		HDC hMemdc = CreateCompatibleDC(hdc);
		// 오류나서 CreateCompatibleBitmap() 대신 사용하는 커스텀 함수 (한슬표)
		HBITMAP hmembit = MakeDIBSection(hMemdc, m_recClient.right, m_recClient.bottom);
		oldmembit = (HBITMAP)SelectObject(hMemdc, hmembit);
		// 윈도우 배경을 하얗게 바꿔주는 함수
		PatBlt(hMemdc, 0, 0, m_recClient.right, m_recClient.bottom, WHITENESS);

		// 바꿔야함 mainfrm에서 진행하니 backgr 불러와야함
		// 오브젝트 그려줄 함수 불러오기 
		for (int i = 0; i < EOBJECT_OBJNUM; i++)
		{
			for (int j = 0; j < m_vecRendObj[i].size(); j++)
			{
				// 백터 내부에 접근하여 Object class 의 내부 함수 (Render) 출력
				(m_vecRendObj[i])[j]->Render(hMemdc, _hWnd);
			}
		}
		
		BitBlt(hdc, 0, 0, m_recClient.right, m_recClient.bottom, hMemdc, 0, 0, SRCCOPY);
		
		// 지정 영역 (null)을 갱신. NULL일 경우에 Client 전체를 리셋함 
		InvalidateRect(_hWnd, &m_recClient, false);

		SelectObject(hMemdc, oldmembit);

		DeleteDC(hMemdc);
		DeleteObject(hmembit);
		EndPaint(_hWnd, &ps);
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