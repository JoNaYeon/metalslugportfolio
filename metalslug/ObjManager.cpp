#include "Object.h"
#include "ObjManager.h"

// �ʱ�ȭ
ObjManager* ObjManager::m_pinstance = NULL;


// ������
ObjManager::ObjManager()
{
	m_recClient = { 0, 0, 0, 0 };
};

ObjManager* ObjManager::GetInstance()
{
	// m_pinstance �� �ƹ��͵� ���� ���, ����
	if (m_pinstance == NULL)
	{
		m_pinstance = new ObjManager;
	}
	return m_pinstance;
};

void ObjManager::Create()
{
	// m_pinstance �� �ƹ��͵� ���� ���, ����
	if (m_pinstance == NULL)
	{
		m_pinstance = new ObjManager;
	}	
	return;
};

void ObjManager::Destroy()
{
	// �� �� instance (�����Ҵ�) ����
	delete m_pinstance;
	m_pinstance = NULL;
	 
	// Object (�����Ҵ�) delete ���� �Լ� ȣ��
	DeleteData();

	return;
};

void ObjManager::DeleteData()
{
	// m_pinstance �� ���� ������� ���, delete
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
	// vector ptr �� �־ Rend() �� �� �ֵ���. 
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
			// ���� ���ο� �ִ� bobjdead �� true�� ��� ���� ���� ���� �� ���� ���� 
			// iter �� vector�� ��ġ�� ���� ������ �����ϵ��� 
			if ((m_vecBackObj[i])[j]->bObjDead() == true && (m_vecBackObj[i])[j] == *m_DBobjiter)
			{
				delete (m_vecBackObj[i])[j];
				((m_vecBackObj[i])[j]) = NULL;
				
				m_DBobjiter = (m_vecBackObj[i]).erase(m_DBobjiter);
				continue;
			}
			// ���� NULL�� ����ְ� ����� erase �� �� �Ǿ� �ִٸ� 
			else if ((m_vecBackObj[i])[j] == NULL)
			{
				m_DBobjiter = (m_vecBackObj[i]).erase(m_DBobjiter);
			}
			else
			{
				// ���� ���ο� �����Ͽ� Object class �� ���� �Լ� (Run) ���
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

		// client ȭ�� ũ�⸦ �� �޾ƿ��� ������ ȭ�鿡 �ƹ��͵� �� ����! 
		GetClientRect(_hWnd, &m_recClient);

		HBITMAP oldmembit;
		// ������۸� �� Memdc ����
		HDC hMemdc = CreateCompatibleDC(hdc);
		// �������� CreateCompatibleBitmap() ��� ����ϴ� Ŀ���� �Լ� (�ѽ�ǥ)
		HBITMAP hmembit = MakeDIBSection(hMemdc, m_recClient.right, m_recClient.bottom);
		oldmembit = (HBITMAP)SelectObject(hMemdc, hmembit);
		// ������ ����� �Ͼ�� �ٲ��ִ� �Լ�
		PatBlt(hMemdc, 0, 0, m_recClient.right, m_recClient.bottom, WHITENESS);

		
		for (int i = 0; i < EOBJECT_OBJNUM; i++)
		{
			for (int j = 0; j < m_vecBackObj[i].size(); j++)
			{
				// ���� ���ο� �����Ͽ� Object class �� ���� �Լ� (Render) ���
				// ���ÿ�  bullet�� �����Ǹ� �� �κп��� ������ ��
				(m_vecBackObj[i])[j]->Render(hMemdc, _hWnd);
			}
		}


		BitBlt(hdc, 0, 0, m_recClient.right, m_recClient.bottom, hMemdc, 0, 0, SRCCOPY);

		// ���� ���� (null)�� ����. NULL�� ��쿡 Client ��ü�� ������ 
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