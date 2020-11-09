#include "Object.h"
#include "ObjManager.h"
#include "Monster.h"
#include "Player.h"
#include "Background.h"
#include "PlayerNormal.h"

// 초기화
ObjManager* ObjManager::m_pinstance = NULL;


// 생성자
ObjManager::ObjManager()
{
	m_recClient = { 0, 0, 0, 0 };
	m_bTile = false;
	m_itile = 0;

	 for (int i = 0; i <= POSPOINT; i++)
    {
        POINT postemp = { 0,0 };
        if (i == 0)
        { postemp = { POSX0, POSY0 }; }
        else if (i == 1)
        { postemp = { POSX1, POSY1 }; }
        else if (i == 2)
        { postemp = { POSX2, POSY2 }; }
        else if (i == 3)
        { postemp = { POSX3, POSY3 }; }
        else if (i == 4)
        { postemp = { POSX4, POSY4 }; }
        else if (i == 5)
        { postemp = { POSX5, POSY5 }; }
        else if (i == 6)
        { postemp = { POSX6, POSY6 }; }
        else if (i == 7)
        { postemp = { POSX7, POSY7 }; }
        else if (i == 8)
        { postemp = { POSX8, POSY8 }; }
        else if (i == 9)
        { postemp = { POSX9, POSY9 }; }
        else if (i == 10)
        { postemp = { POSX10, POSY10 }; }
        else if (i == 11)
        { postemp = { POSX11, POSY11 }; }
        else if (i == 12)
        { postemp = { POSX12, POSY12 }; }
        else if (i == 13)
        { postemp = { POSX13, POSY13 }; }
        else if (i == 14)
        { postemp = { POSX14, POSY14 }; }
        else if (i == 15)
        { postemp = { POSX15, POSY15 }; }
        else if (i == 16)
        { postemp = { POSX16, POSY16 }; }
        else if (i == 17)
        { postemp = { POSX17, POSY17 }; }
        else if (i == 18)
        { postemp = { POSX18, POSY18 }; }
        else if (i == 19)
        { postemp = { POSX19, POSY19 }; }
        else if (i == 20)
        { postemp = { POSX20, POSY20 }; }
        else if (i == 21)
        { postemp = { POSX21, POSY21 }; }
        else if (i == 22)
        { postemp = { POSX22, POSY22 }; }
        else if (i == 23)
        { postemp = { POSX23, POSY23 }; }
        else if (i == 24)
        { postemp = { POSX24, POSY24 }; }
        else if (i == 25)
        { postemp = { POSX25, POSY25 }; }
        else if (i == 26)
        { postemp = { POSX26, POSY26 }; }
        else if (i == 27)
        { postemp = { POSX27, POSY27 }; }
        
        // POINT 의 x값 위치 조정
        postemp.x = postemp.x * BGSIZE;
        // POINT 의 y값 위치 조정
        postemp.y = (postemp.y - BGDELETESIZE) * BGSIZE;

        m_vecpos.push_back(postemp);
    }
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
	BackgroundMove();

	// Object 와 Tile 충돌시
	// 이후 CollisionCheck() 와 합치기.
	for (int i = 0; i < EOBJECT_OBJNUM; i++)
	{
		BackgroundLineCollision((E_OBJECT)i);
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

		// client 화면 크기 받아오기
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
		
		// 바닥 그려주기
		for (int i = 0; i < m_vecpos.size() - 1; i++)
		{
			MoveToEx(hdc, m_vecpos[i].x, m_vecpos[i].y, NULL);
			LineTo(hdc, m_vecpos[i + 1].x, m_vecpos[i + 1].y);
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
		case EOBJECT_USER:
		{
			return m_vecObj[EOBJECT_USER];
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
		bool bright = false;

		for (int j = 0; j < m_vecObj[EOBJECT_MONSTER].size(); j++)
		{
			RECT recHitMonster = m_vecObj[EOBJECT_MONSTER][j]->GetHitBox();

			// 왼쪽에서 피격당했을 때
			if ( (recHitMonster.left + (recHitMonster.left - recHitMonster.right / 2)) >= recHitBullet.right)
			{
				bright = false;
			}
			// 오른쪽에서 피격당했을 때
			else if ((recHitMonster.left + (recHitMonster.left - recHitMonster.right / 2)) < recHitBullet.right)
			{
				bright = true;
			}

			if (IntersectRect(&rectemp, &recHitBullet, &recHitMonster) == true)
			{
				// bullet 파괴
				delete m_vecObj[EOBJECT_BULLET][i];
				m_vecObj[EOBJECT_BULLET][i] = NULL;

				
				iter = (m_vecObj[EOBJECT_BULLET]).erase(iter);
				bCollisiontemp = true;

				// 몬스터가 피격되었음을 알려주고 
				m_vecObj[EOBJECT_MONSTER][j]->SetCollisionCheck(bCollisiontemp);

				// 몬스터 피격 좌우 알려주기
				// 오른쪽에서 맞을 때
				if (bright == true)
				{
					// Monster 뒤로 밀리기
					DISPLAYINFO MonDisTemp = *((m_vecObj[EOBJECT_MONSTER][j])->GetDisTop());
					MonDisTemp.ptDestPos.x -= MONHITEDMOTION;

					m_vecObj[EOBJECT_MONSTER][j]->SetDisTop(MonDisTemp.ptDestPos);
				}
				// 왼쪽에서 맞을 때
				//else
				{
					// Monster 뒤로 밀리기
					DISPLAYINFO MonDisTemp = *((m_vecObj[EOBJECT_MONSTER][j])->GetDisTop());
					MonDisTemp.ptDestPos.x += MONHITEDMOTION;

					m_vecObj[EOBJECT_MONSTER][j]->SetDisTop(MonDisTemp.ptDestPos);
				}

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

	return; 
}



// 선타일을 깔아주는 함수
void ObjManager::BackgroundLineCollision(E_OBJECT _Eobj)
{
	// 오브젝트 갯수만큼 돌아주기
	for (int i = 0; i < m_vecObj[_Eobj].size(); i++)
	{
		// false일 경우 continue로 하단 코드 넘어가기
		if (m_vecObj[_Eobj][i]->GetbCollision() == false)
		{
			continue;
		}


		// 이미지의 위치값 가져오기
		int ixobjectpos = m_vecObj[_Eobj][i]->GetDisTop()->ptDestPos.x;
		int iyobjectpos = m_vecObj[_Eobj][i]->GetDisTop()->ptDestPos.y; // 해당 오브젝트의 세로축값

		// 이미지 사이즈 가져오기 
		POINT pImgSizetemp = { (m_vecObj[_Eobj][i]->GetDisTop()->ptDestSize.x) ,
			(m_vecObj[_Eobj][i]->GetDisTop()->ptDestSize.y)};


		// 충돌할 라인의 POINT 의 갯수만큼 돌아서 검사해주기 
		for (int j = 0; j < m_vecpos.size() - 1; j++)
		{
			// Object 의 x 위치가 POINT 사이값에 존재할 경우
			if (m_vecpos[j].x <= ixobjectpos && ixobjectpos < m_vecpos[j + 1].x)
			{
				// 직선의 기울기
				float fm = 0;
				// y의 절편
				int iy = 0;
				// 움직인 위치의 y 값
				int iobjdistancey = 0;

				// 기울기 구하기
				float fnextjy =  (float)m_vecpos[j + 1].y;
				float fjy = (float)m_vecpos[j].y;
				float fnextjx = (float)m_vecpos[j + 1].x;
				float fjx = (float)m_vecpos[j].x;

				fm = ((fnextjy - fjy) / (fnextjx - fjx));

				// y절편 구하기
				iy = m_vecpos[j].y - (fm * m_vecpos[j].x); // j번째에 있는 선의 y값에서 기울기 * 선의 x값을 더한걸 뺀다. 

				// y의 타일 위치 계산
				iobjdistancey = (fm * ixobjectpos) + iy;


				// 임시 - y위치를 계산하여 좌우 레벨 움직임의 상하와 움직이지 않음 등을 가려주는 함수
				switch (m_vecObj[_Eobj][i]->ObjectyLevel(iobjdistancey))
				{
					// 캐릭터가 올라가야 할 때
					case E_USERYUPDOWN_UP:
					{
						// Object 의 위치값을 구해온 뒤
						POINT ptobjectpos = { m_vecObj[_Eobj][i]->GetDisTop()->ptDestPos.x, iobjdistancey - (m_vecObj[_Eobj][i]->GetDisTop()->ptDestSize.y * PLAYERSIZE) };

						// y 위치값 대입해주기...
						m_vecObj[_Eobj][i]->SetDisTop(ptobjectpos);
						// 만약 들어온 Object가 User 일 경우, Bot 부분도 세팅해주기
						if (_Eobj == EOBJECT_USER)
						{
							// top 위치에 bot 맞춰주기
							(m_vecObj[_Eobj][i])->SetDisBot(ptobjectpos);
						}
					}
						break;

					// 캐릭터가 멈춰야 할 때
					case E_USERYUPDOWN_STOP:
					{
						// 임시 - 한번 더 ObjectState를 검사하기 위해 함수를 또 사용하는 것이 옳은가...? 고민고민... 
						// 하지만 임시처리를 해놓지 않으면 혹시 다른 곳에서 사용할 때 오류가 날 수도 있을 것 같음.
						//m_vecObj[_Eobj][i]->ObjectStopYLevelControl(iobjdistancey);
					}
						break;
				
					case E_USERYUPDOWN_JUMP:
					{
						m_vecObj[_Eobj][i]->SetJump(true);
						m_vecObj[_Eobj][i]->Setobjstate(E_USERSTATE_JUMP);

						// Object 의 위치값을 구해온 뒤
						/*POINT ptobjectpos = { m_vecObj[_Eobj][i]->GetDisTop()->ptDestPos.x, iobjdistancey - (m_vecObj[_Eobj][i]->GetDisTop()->ptDestSize.y * PLAYERSIZE) };

						m_vecObj[_Eobj][i]->SetDisTop(ptobjectpos);
						// 만약 들어온 Object가 User 일 경우, Bot 부분도 세팅해주기
						if (_Eobj == EOBJECT_USER)
						{
							// top 위치에 bot 맞춰주기
							(m_vecObj[_Eobj][i])->SetDisBot(ptobjectpos);
						}*/
					}
						break;
					case E_USERUPDOWN_JUMPSTOP:
					{

					}
						break;
				}



				// Object 의 상태가 jump 가 아닐 때에만 gravity를 false 로 바꿔주기
				if (m_vecObj[_Eobj][i]->Getobjstate() == E_USERSTATE_JUMP)
				{
					m_vecObj[_Eobj][i]->SetJump(false);
					m_vecObj[_Eobj][i]->Setobjstate(E_USERSTATE_IDLE);
				}
				else
				{
					m_vecObj[_Eobj][i]->SetboolGravity(true);
				}

				// 오브젝트의 y값이 나아갈 위치의 y값보다 많이 작을 경우 나아가지 못하도록.
				/*if ((iyplayerpos + (pImgSizetemp.y * PLAYERSIZE)) - iobjdistancey >= 10)
				{
					if(m_vecObj[_Eobj][i]->Getobjstate() == )
					POINT posobjectreposition = { ixplayerpos , iyplayerpos };

					// 나아가지 못하도록 하는 코드
					m_vecObj[_Eobj][i]->SetDisTop();
				}*/

				break;
			}
		}
		
	}


	return;
}

// 유저의 위치에 따라서 배경과 오브젝트들을 움직여주는 함수
void ObjManager::BackgroundMove()
{
	std::vector<Object*> vecusertemp = ObjManager::GetInstance()->GetVector(EOBJECT_USER);

	std::vector<Object*> vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_BG);

	for (int i = 0; i < vecusertemp.size(); i++)
	{
		// 유저가 가지고 있는 b_BGMove 변수가 true 일 경우에만 움직여주도록.
		if (((Player*)(vecusertemp[i]))->GetBGMove() == true)
		{
			// 배경 움직여주기
			for (int i = 0; i < vectemp.size(); i++)
			{
				Background* bgtemp = (Background*)vectemp[i];
				// 배경 움직이기
				bgtemp->BackgroundMove(E_USERSTATE_RWALK);
				// 타일 움직여주기
				TileMove(E_USERSTATE_RWALK);
			}

			// 몬스터 움직여주기
			vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_MONSTER);

			for (int i = 0; i < vectemp.size(); i++)
			{
				Monster* Monstertemp = (Monster*)vectemp[i];
				Monstertemp->MonsterMove(E_USERSTATE_RWALK);
			}
		}
	}
	return;
}



// 타일 움직여주는 함수
void ObjManager::TileMove(E_USERSTATE _e_state)
{
	switch (_e_state)
	{
		case E_USERSTATE_LWALK:
		{
			for (int i = 0; i < m_vecpos.size() - 1; i++)
			{
				(m_vecpos)[i].x += (BACKGROUNDMOVE * BGTILESIZE);
				(m_vecpos)[i + 1].x += (BACKGROUNDMOVE * BGTILESIZE);
			}
		}
		case E_USERSTATE_RWALK:
		{
			for (int i = 0; i < m_vecpos.size() - 1; i++)
			{
				(m_vecpos)[i].x -= (BACKGROUNDMOVE * BGTILESIZE);
				(m_vecpos)[i + 1].x -= (BACKGROUNDMOVE * BGTILESIZE);
			}
	}
	}

	return;
}