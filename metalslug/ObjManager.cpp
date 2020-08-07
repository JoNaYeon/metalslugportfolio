#include "Object.h"
#include "ObjManager.h"
#include "Monster.h"
#include "Player.h"
#include "Background.h"

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
	// vector ptr 을 넣어서 Rend() 할 수 있도록. 
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
			// 백터 내부에 있는 bobjdead 가 true일 경우 내부 정보 삭제 및 백터 삭제 
			// iter 과 vector의 위치가 같을 때에만 삭제하도록 
			if ((m_vecObj[i])[j]->bObjDead() == true && (m_vecObj[i])[j] == *m_DBobjiter)
			{
				delete (m_vecObj[i])[j];
				((m_vecObj[i])[j]) = NULL;
				
				m_DBobjiter = (m_vecObj[i]).erase(m_DBobjiter);
				continue;
			}
			// 만약 NULL이 들어있고 제대로 erase 가 안 되어 있다면 
			else if ((m_vecObj[i])[j] == NULL)
			{
				m_DBobjiter = (m_vecObj[i]).erase(m_DBobjiter);
			}
			else
			{
				// 백터 내부에 접근하여 Object class 의 내부 함수 (Run) 출력
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
			for (int j = 0; j < m_vecObj[i].size(); j++)
			{
				// 백터 내부에 접근하여 Object class 의 내부 함수 (Render) 출력
				// 동시에  bullet이 삭제되면 이 부분에서 문제가 남
				(m_vecObj[i])[j]->Render(hMemdc, _hWnd);
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

	// Bullet 과 Monster 의 충돌시 
	for (int i = 0; i < m_vecObj[EOBJECT_BULLET].size(); i++)
	{
		std::vector<Object*>::iterator iter = m_vecObj[EOBJECT_BULLET].begin();
		RECT recHitBullet = m_vecObj[EOBJECT_BULLET][i]->GetHitBox();

		for (int j = 0; j < m_vecObj[EOBJECT_MONSTER].size(); j++)
		{
			RECT recHitMonster = m_vecObj[EOBJECT_MONSTER][j]->GetHitBox();

			if (IntersectRect(&rectemp, &recHitBullet, &recHitMonster) == true)
			{
				// bullet 파괴
				delete m_vecObj[EOBJECT_BULLET][i];
				m_vecObj[EOBJECT_BULLET][i] = NULL;

				iter = (m_vecObj[EOBJECT_BULLET]).erase(iter);
				bCollisiontemp = true;

				// 몬스터가 피격되었음을 알려주고 
				m_vecObj[EOBJECT_MONSTER][j]->SetCollisionCheck(bCollisiontemp);
				// 몬스터 피격으로 HP 깎기 
				((Monster*)(m_vecObj[EOBJECT_MONSTER][j]))->Hit();
			}
		}
		// iter 가 vector 의 끝부분과 같다면 더이상 iter를 더해주지 않도록.
		if (iter == (m_vecObj[EOBJECT_BULLET]).end())
		{
			break;
		}
		else
		{
			iter++;
		}
	}


	// Player 과 BackgroundTile 의 충돌시 
	for (int i = 0; i < m_vecObj[EOBJECT_USER].size(); i++)
	{
		RECT recHitPlayer = m_vecObj[EOBJECT_USER][i]->GetHitBox();

		for (int j = 0; j < m_vecObj[EOBJECT_BG].size(); j++)
		{
			RECT recHitBG = m_vecObj[EOBJECT_BG][j]->GetHitBox();

			// background Tile 과 Player 의 HitBox 가 부딪혔을 때 조금씩 올라오도록.
			if (IntersectRect(&rectemp, &recHitPlayer, &recHitBG) == true)
			{
				DISPLAYINFO* disinfotemp = ((Player*)(m_vecObj[EOBJECT_USER][i]))->GetPlayerDisTop();
				disinfotemp->ptDestPos.y -= 0.4f;

				disinfotemp = ((Player*)(m_vecObj[EOBJECT_USER][i]))->GetPlayerDisBot();
				disinfotemp->ptDestPos.y -= 0.4f;

				// 점프중일 경우 점프 중단
				if ((m_vecObj[EOBJECT_USER][i])->GetJump() == true)
				{
					(m_vecObj[EOBJECT_USER][i])->SetboolGravity(false);
					
					// 점프를 마치면 처음 위치로 고정시켜줌 
					POINT ptTemp = { (((Player*)(m_vecObj[EOBJECT_USER][i]))->GetPlayerDisTop()->ptDestPos.x) ,
						(((Background*)(m_vecObj[EOBJECT_BG][i]))->GetHitBox().top) - 
						((((Player*)(m_vecObj[EOBJECT_USER][i]))->GetPlayerDisTop()->ptDestSize.y) * PLAYERSIZE) };
					((Player*)(m_vecObj[EOBJECT_USER][i]))->SetPlayerDisTop(ptTemp);
					((Player*)(m_vecObj[EOBJECT_USER][i]))->SetPlayerDisBot(ptTemp);
				}
			}
			// backgoround 와 부딪히지 않았을 경우 계속 gravity 받도록. 
			else
			{
				(m_vecObj[EOBJECT_USER][i])->SetboolGravity(true);
			}
		}
	}

	return; 
}