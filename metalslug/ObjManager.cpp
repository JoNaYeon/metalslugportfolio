#include "Object.h"
#include "ObjManager.h"

// 초기화
ObjManager* ObjManager::m_pinstance = NULL;


// 생성자
ObjManager::ObjManager()
{
	m_recClient = { 0, 0, 0, 0 };
};

ObjManager* ObjManager::GetInstance()
{
	// m_pinstance 에 아무것도 없을 경우, 생성
	if (m_pinstance == NULL)
	{
		m_pinstance = new ObjManager;
	}
	return m_pinstance;
};

void ObjManager::Create()
{
	// m_pinstance 에 아무것도 없을 경우, 생성
	if (m_pinstance == NULL)
	{
		m_pinstance = new ObjManager;
	}	
	return;
};

void ObjManager::Destroy()
{
	// 다 쓴 instance (동적할당) 삭제
	delete m_pinstance;
	m_pinstance = NULL;
	 
	// Object (동적할당) delete 해줄 함수 호출
	DeleteData();

	return;
};

void ObjManager::DeleteData()
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


void ObjManager::SetVector(Object* _object, E_OBJECT _Eobjectkind)
{
	// vector ptr 을 넣어서 Rend() 할 수 있도록. 
	m_vecBackObj[_Eobjectkind].push_back(_object);

	return;
}


// Rect
RECT ObjManager::GetRect()
{
	return m_recClient;
}

void ObjManager::SetRect(RECT _recClient)
{
	m_recClient = _recClient;
	return;
}



// DB
void ObjManager::Run()
{
	for (int i = 0; i < EOBJECT_OBJNUM; i++)
	{
		m_DBobjiter = m_vecBackObj[i].begin();

 		for (int j = 0; j < m_vecBackObj[i].size(); j++)
		{
			// 백터 내부에 있는 bobjdead 가 true일 경우 내부 정보 삭제 및 백터 삭제 
			// iter 과 vector의 위치가 같을 때에만 삭제하도록 
			if ((m_vecBackObj[i])[j]->bObjDead() == true && (m_vecBackObj[i])[j] == *m_DBobjiter)
			{
				delete (m_vecBackObj[i])[j];
				((m_vecBackObj[i])[j]) = NULL;
				
				m_DBobjiter = (m_vecBackObj[i]).erase(m_DBobjiter);
				continue;
			}
			// 만약 NULL이 들어있고 제대로 erase 가 안 되어 있다면 
			else if ((m_vecBackObj[i])[j] == NULL)
			{
				m_DBobjiter = (m_vecBackObj[i]).erase(m_DBobjiter);
			}
			else
			{
				// 백터 내부에 접근하여 Object class 의 내부 함수 (Run) 출력
				(m_vecBackObj[i])[j]->Run();
			}

			m_DBobjiter++;
		}
	}
	return;
};


// Rend
void ObjManager::Rend(HWND& _hWnd)
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

		
		for (int i = 0; i < EOBJECT_OBJNUM; i++)
		{
			for (int j = 0; j < m_vecBackObj[i].size(); j++)
			{
				// 백터 내부에 접근하여 Object class 의 내부 함수 (Render) 출력
				// 동시에  bullet이 삭제되면 이 부분에서 문제가 남
				(m_vecBackObj[i])[j]->Render(hMemdc, _hWnd);
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


std::vector<Object*> ObjManager::GetVector(E_OBJECT _e_obj)
{
	switch (_e_obj)
	{
		case EOBJECT_BG:
		{
			return m_vecBackObj[EOBJECT_BG];
		}
		case EOBJECT_TERRAIN:
		{
			return m_vecBackObj[EOBJECT_TERRAIN];
		}
		case EOBJECT_BULLET:
		{
			return m_vecBackObj[EOBJECT_BULLET];
		}
		case EOBJECT_MONSTER:
		{
			return m_vecBackObj[EOBJECT_MONSTER];
		}
		case EOBJECT_OBJ:
		{
			return m_vecBackObj[EOBJECT_OBJ];
		}
		case EOBJECT_UI:
		{
			return m_vecBackObj[EOBJECT_UI];
		}
	}
}