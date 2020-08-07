#include "Object.h"
#include "ObjManager.h"
#include "Monster.h"
#include "Player.h"
#include "Background.h"

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
			for (int j = 0; j < m_vecObj[i].size(); j++)
			{
				delete (m_vecObj[i])[j];
				(m_vecObj[i])[j] = NULL;
			}
		}
	}
	return;
};


void ObjManager::SetVector(Object* _object, E_OBJECT _Eobjectkind)
{
	// vector ptr �� �־ Rend() �� �� �ֵ���. 
	m_vecObj[_Eobjectkind].push_back(_object);

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
		m_DBobjiter = m_vecObj[i].begin();

 		for (int j = 0; j < m_vecObj[i].size(); j++)
		{
			// ���� ���ο� �ִ� bobjdead �� true�� ��� ���� ���� ���� �� ���� ���� 
			// iter �� vector�� ��ġ�� ���� ������ �����ϵ��� 
			if ((m_vecObj[i])[j]->bObjDead() == true && (m_vecObj[i])[j] == *m_DBobjiter)
			{
				delete (m_vecObj[i])[j];
				((m_vecObj[i])[j]) = NULL;
				
				m_DBobjiter = (m_vecObj[i]).erase(m_DBobjiter);
				continue;
			}
			// ���� NULL�� ����ְ� ����� erase �� �� �Ǿ� �ִٸ� 
			else if ((m_vecObj[i])[j] == NULL)
			{
				m_DBobjiter = (m_vecObj[i]).erase(m_DBobjiter);
			}
			else
			{
				// ���� ���ο� �����Ͽ� Object class �� ���� �Լ� (Run) ���
				(m_vecObj[i])[j]->Run();
			}

			m_DBobjiter++;
		}
	}

	CollisionCheck();

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
			for (int j = 0; j < m_vecObj[i].size(); j++)
			{
				// ���� ���ο� �����Ͽ� Object class �� ���� �Լ� (Render) ���
				// ���ÿ�  bullet�� �����Ǹ� �� �κп��� ������ ��
				(m_vecObj[i])[j]->Render(hMemdc, _hWnd);
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
			return m_vecObj[EOBJECT_BG];
		}
		case EOBJECT_TERRAIN:
		{
			return m_vecObj[EOBJECT_TERRAIN];
		}
		case EOBJECT_BULLET:
		{
			return m_vecObj[EOBJECT_BULLET];
		}
		case EOBJECT_MONSTER:
		{
			return m_vecObj[EOBJECT_MONSTER];
		}
		case EOBJECT_OBJ:
		{
			return m_vecObj[EOBJECT_OBJ];
		}
		case EOBJECT_UI:
		{
			return m_vecObj[EOBJECT_UI];
		}
	}
}


void ObjManager::CollisionCheck()
{
	bool bCollisiontemp = false;
	RECT rectemp = { 0,0,0,0 };

	// Bullet �� Monster �� �浹�� 
	for (int i = 0; i < m_vecObj[EOBJECT_BULLET].size(); i++)
	{
		std::vector<Object*>::iterator iter = m_vecObj[EOBJECT_BULLET].begin();
		RECT recHitBullet = m_vecObj[EOBJECT_BULLET][i]->GetHitBox();

		for (int j = 0; j < m_vecObj[EOBJECT_MONSTER].size(); j++)
		{
			RECT recHitMonster = m_vecObj[EOBJECT_MONSTER][j]->GetHitBox();

			if (IntersectRect(&rectemp, &recHitBullet, &recHitMonster) == true)
			{
				// bullet �ı�
				delete m_vecObj[EOBJECT_BULLET][i];
				m_vecObj[EOBJECT_BULLET][i] = NULL;

				iter = (m_vecObj[EOBJECT_BULLET]).erase(iter);
				bCollisiontemp = true;

				// ���Ͱ� �ǰݵǾ����� �˷��ְ� 
				m_vecObj[EOBJECT_MONSTER][j]->SetCollisionCheck(bCollisiontemp);
				// ���� �ǰ����� HP ��� 
				((Monster*)(m_vecObj[EOBJECT_MONSTER][j]))->Hit();
			}
		}
		// iter �� vector �� ���κа� ���ٸ� ���̻� iter�� �������� �ʵ���.
		if (iter == (m_vecObj[EOBJECT_BULLET]).end())
		{
			break;
		}
		else
		{
			iter++;
		}
	}


	// Player �� BackgroundTile �� �浹�� 
	for (int i = 0; i < m_vecObj[EOBJECT_USER].size(); i++)
	{
		RECT recHitPlayer = m_vecObj[EOBJECT_USER][i]->GetHitBox();

		for (int j = 0; j < m_vecObj[EOBJECT_BG].size(); j++)
		{
			RECT recHitBG = m_vecObj[EOBJECT_BG][j]->GetHitBox();

			// background Tile �� Player �� HitBox �� �ε����� �� ���ݾ� �ö������.
			if (IntersectRect(&rectemp, &recHitPlayer, &recHitBG) == true)
			{
				DISPLAYINFO* disinfotemp = ((Player*)(m_vecObj[EOBJECT_USER][i]))->GetPlayerDisTop();
				disinfotemp->ptDestPos.y -= 0.4f;

				disinfotemp = ((Player*)(m_vecObj[EOBJECT_USER][i]))->GetPlayerDisBot();
				disinfotemp->ptDestPos.y -= 0.4f;

				// �������� ��� ���� �ߴ�
				if ((m_vecObj[EOBJECT_USER][i])->GetJump() == true)
				{
					(m_vecObj[EOBJECT_USER][i])->SetboolGravity(false);
					
					// ������ ��ġ�� ó�� ��ġ�� ���������� 
					POINT ptTemp = { (((Player*)(m_vecObj[EOBJECT_USER][i]))->GetPlayerDisTop()->ptDestPos.x) ,
						(((Background*)(m_vecObj[EOBJECT_BG][i]))->GetHitBox().top) - 
						((((Player*)(m_vecObj[EOBJECT_USER][i]))->GetPlayerDisTop()->ptDestSize.y) * PLAYERSIZE) };
					((Player*)(m_vecObj[EOBJECT_USER][i]))->SetPlayerDisTop(ptTemp);
					((Player*)(m_vecObj[EOBJECT_USER][i]))->SetPlayerDisBot(ptTemp);
				}
			}
			// backgoround �� �ε����� �ʾ��� ��� ��� gravity �޵���. 
			else
			{
				(m_vecObj[EOBJECT_USER][i])->SetboolGravity(true);
			}
		}
	}

	return; 
}