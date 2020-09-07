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
        postemp.y = postemp.y * BGTILESIZE;

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

	/*if (m_bTile == false)
	{
		BackgroundTileSet();
	}*/

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
		
		// 임의로 바닥 그려주기
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
					DISPLAYINFO MonDisTemp = *(((Monster*)m_vecObj[EOBJECT_MONSTER][j])->GetMonsterDis());
					MonDisTemp.ptDestPos.x -= MONHITEDMOTION;

					((Monster*)m_vecObj[EOBJECT_MONSTER][j])->SetMonsterDis(MonDisTemp.ptDestPos);
				}
				// 왼쪽에서 맞을 때
				//else
				{
					// Monster 뒤로 밀리기
					DISPLAYINFO MonDisTemp = *(((Monster*)m_vecObj[EOBJECT_MONSTER][j])->GetMonsterDis());
					MonDisTemp.ptDestPos.x += MONHITEDMOTION;

					((Monster*)m_vecObj[EOBJECT_MONSTER][j])->SetMonsterDis(MonDisTemp.ptDestPos);
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

	// Object 와 Tile 충돌시
	for (int i = 0; i < EOBJECT_OBJNUM; i++)
	{
		switch (i)
		{
			// 몬스터와 타일 충돌시
			case EOBJECT_MONSTER:
				BackgroundTileSet(EOBJECT_MONSTER, m_vecObj[EOBJECT_MONSTER]);
				break;

			// 유저와 타일 충돌시
			case EOBJECT_USER:
				BackgroundTileSet(EOBJECT_USER, m_vecObj[EOBJECT_USER]);
				BackgroundTileSet(EOBJECT_USER, m_vecObj[EOBJECT_USER]);
				break;
		}
	}


	/*for (int i = 0; i < EOBJECT_OBJNUM; i++)
	{
		int iobj = 0;

		switch(i)
		{
			case EOBJECT_MONSTER:
			{
				iobj = EOBJECT_MONSTER;

				for (int j = 0; j < m_vecObj[iobj].size(); j++)
				{
					BackgroundTileSet((E_OBJECT)iobj, ((Monster*)(m_vecObj[iobj])[j])->GetMonsterDis());
				}
			}
				break;
			case EOBJECT_USER:
			{
				iobj = EOBJECT_USER; 
				
				for (int j = 0; j < m_vecObj[iobj].size(); j++)
				{
					BackgroundTileSet((E_OBJECT)iobj, ((PlayerNormal*)(m_vecObj[iobj])[j])->GetPlayerDisTop());
					BackgroundTileSet((E_OBJECT)iobj, ((PlayerNormal*)(m_vecObj[iobj])[j])->GetPlayerDisBot());
				}
			}
				break;
		}

		/*for (int j = 0; j < m_vecObj[iobj].size(); j++)
		{
			switch (iobj)
			{
			case EOBJECT_MONSTER:
				BackgroundTileSet((E_OBJECT)iobj, ((Monster*)(m_vecObj[iobj])[j])->GetMonsterDis());
				break;
			case EOBJECT_USER:
				BackgroundTileSet((E_OBJECT)iobj, ((PlayerNormal*)(m_vecObj[iobj])[j])->GetPlayerDisTop());
				BackgroundTileSet((E_OBJECT)iobj, ((PlayerNormal*)(m_vecObj[iobj])[j])->GetPlayerDisBot());
				break;

			}
		}
	}*/


	// Player 과 BackgroundTile 의 충돌시 
	/*for (int i = 0; i < m_vecObj[EOBJECT_USER].size(); i++)
	{
		RECT recHitPlayer = m_vecObj[EOBJECT_USER][i]->GetHitBox();


		for (int j = 0; j < m_vecBGpos.size(); j++)
		{
			RECT recHitBG = m_vecBGpos[j];

			// background Tile 과 Player 의 HitBox 가 부딪혔을 때 조금씩 올라오도록.
			if (IntersectRect(&rectemp, &recHitPlayer, &recHitBG) == true)
			{
				// top과 bot을 일정한 위치에 위치하도록 해주기.
				DISPLAYINFO* disinfotemp = ((Player*)(m_vecObj[EOBJECT_USER][i]))->GetPlayerDisTop();
				disinfotemp->ptDestPos.y = recHitBG.top - (disinfotemp->ptDestSize.y * PLAYERSIZE);

				disinfotemp = ((Player*)(m_vecObj[EOBJECT_USER][i]))->GetPlayerDisBot();
				disinfotemp->ptDestPos.y = recHitBG.top - (disinfotemp->ptDestSize.y * PLAYERSIZE);

				(m_vecObj[EOBJECT_USER][i])->SetboolGravity(false);

				// 부딫힐 경우 다른 background tile 과는 비교하지 않도록 
				break;
			}
			// backgoround 와 부딪히지 않았을 경우 계속 gravity 받도록. 
			else
			{
				(m_vecObj[EOBJECT_USER][i])->SetboolGravity(true);
			}
		}
	}*/

	// Monster 과 Background Tile 충돌
	/*for (int i = 0; i < m_vecObj[EOBJECT_MONSTER].size(); i++)
	{
		RECT recHitPlayer = m_vecObj[EOBJECT_MONSTER][i]->GetHitBox();

		for (int j = 0; j < m_vecBGpos.size(); j++)
		{
			RECT recHitBG = m_vecBGpos[j];
			
			// background tile 의 위치 조정 
			//recHitBG.left += m_itile;
			//recHitBG.right += m_itile;

			// background Tile 과 Monster 의 HitBox 가 부딪혔을 때 조금씩 올라오도록.
			if (IntersectRect(&rectemp, &recHitPlayer, &recHitBG) == true)
			{
				DISPLAYINFO* disinfotemp = ((Monster*)(m_vecObj[EOBJECT_MONSTER][i]))->GetMonsterDis();
				disinfotemp->ptDestPos.y -= 0.4f;

				disinfotemp = ((Monster*)(m_vecObj[EOBJECT_MONSTER][i]))->GetMonsterDis();
				disinfotemp->ptDestPos.y -= 0.4f;

				(m_vecObj[EOBJECT_MONSTER][i])->SetboolGravity(false);

				// 부딫힐 경우 다른 background tile 과는 비교하지 않도록 
				break;
			}
			// backgoround 와 부딪히지 않았을 경우 계속 gravity 받도록. 
			else
			{
				(m_vecObj[EOBJECT_MONSTER][i])->SetboolGravity(true);
			}
		}
	}*/



	
	return; 
}


// 선타일을 깔아주는 함수
void ObjManager::BackgroundTileSet(E_OBJECT _Eobj, std::vector<Object*> _objvec)
{
	/*for (int i = 0; i < m_vecObj[EOBJECT_BG].size(); i++)
	{
		for (int j = 0; j < BGEND; j++)
		{
			m_vecBGpos.push_back(((Background*)(m_vecObj[EOBJECT_BG][i]))->BackgroundTile(j));
		}
	}

	m_bTile = true;*/

	// 직선의 기울기
	int im = 0;
	// y의 절편
	int iy = 0;
	// y의 값
	int iypostemp = 0;

	// 직선의 기울기 구하기
	for (int i = 0; i < m_vecpos.size() - 1; i++)
	{
		// 기울기 구하기
		im = (m_vecpos[i + 1].y - m_vecpos[i].y) / (m_vecpos[i + 1].x - m_vecpos[i].x);
		// y절편 구하기
		iy = m_vecpos[i].y - (im * m_vecpos[i].x);

		// x 위치에 따른 y의 값
		for (int j = 0; j < m_vecObj[EOBJECT_USER].size(); j++)
		{
			int ixplayerpos = ((PlayerNormal*)_objvec[j])->GetPlayerDisTop()->ptDestPos.x;
			int iyplayerpos = ((PlayerNormal*)_objvec[j])->GetPlayerDisTop()->ptDestPos.y;

			// y의 타일 위치 계산
			iypostemp = (im * ixplayerpos) + iy;

			// 플레이어의 이미지 시작점이 타일의 위치 - 플레이어의 세로 크기 보다 작다면 위치 고정시켜주기
			if (iyplayerpos < iypostemp - iyplayerpos)
			{
				POINT pitplayerpos = { ixplayerpos - (ixplayerpos / 2) ,iyplayerpos };

				//((PlayerNormal*)_objvec[j])->SetPlayerDisTop(pitplayerpos);
				((PlayerNormal*)_objvec[j])->SetPlayerDisBot(pitplayerpos);
				break;
			}
		}

	}


	/*for (int i = 0; i < _objvec.size(); i++)
	{
		if (((PlayerNormal*)_objvec[i])->GetPlayerDisTop() tile 의 y값 - ((PlayerNormal*)_objvec[i])->GetPlayerDisTop().y / 2 보다 크다면)
		{
			// 위치 고정시키기
		}
	}

	for (int i = 0; i < m_vecObj[_Eobj].size(); i++)
	{
		for (int j = 0; j < m_vecObj[EOBJECT_BG].size(); j++)
		{
			int ix = 0;
			int iy = 0;

			switch (_Eobj)
			{
			case EOBJECT_USER:
			{
				ix = (((PlayerNormal*)(m_vecObj[_Eobj])[i])->GetPlayerDisTop()->ptDestPos.x)
					- (((PlayerNormal*)(m_vecObj[_Eobj])[i])->GetPlayerDisTop()->ptDestSize.x / 2);
				iy = (((Background*)(m_vecObj[EOBJECT_BG])[j])->GetTileY(m_vecObj[_Eobj][i]))
					- (((PlayerNormal*)(m_vecObj[_Eobj])[i])->GetPlayerDisTop()->ptDestSize.y);

				POINT postemp = { ix,iy };

				// object 의 y의 위치가 postemp.y 보다 작을 경우
				if (((PlayerNormal*)m_vecObj[_Eobj][i])->GetPlayerDisTop()->ptDestPos.y <= postemp.y)
				{
					((PlayerNormal*)(m_vecObj[_Eobj])[i])->SetPlayerDisTop(postemp);
					((PlayerNormal*)(m_vecObj[_Eobj])[i])->SetPlayerDisBot(postemp);
				}
			}
			break;
			case EOBJECT_MONSTER:
			{
				ix = (((Monster*)(m_vecObj[_Eobj])[i])->GetMonsterDis()->ptDestPos.x)
					- (((Monster*)(m_vecObj[_Eobj])[i])->GetMonsterDis()->ptDestSize.x / 2);
				iy = (((Background*)(m_vecObj[EOBJECT_BG])[j])->GetTileY(m_vecObj[_Eobj][i]))
					- (((Monster*)(m_vecObj[_Eobj])[i])->GetMonsterDis()->ptDestSize.y);

				POINT postemp = { ix,iy };

				// object 의 y의 위치가 postemp.y 보다 작을 경우
				if (((Monster*)m_vecObj[_Eobj][i])->GetMonsterDis()->ptDestPos.y <= postemp.y)
				{
					((Monster*)(m_vecObj[_Eobj])[i])->SetMonsterDis(postemp);
				}
			}
			break;
			}

			//POINT postemp = { ((PlayerNormal*)(m_vecObj[EOBJECT_USER])[i])->GetPlayerDisTop()->ptDestPos.x, 
			//	((Background*)(m_vecObj[EOBJECT_BG])[j])->GetTileY(m_vecObj[EOBJECT_USER][i]) };
		}
	}*/

	m_bTile = true;

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

	/*std::vector<POINT>* vecBGTilePos = NULL;

	for (int i = 0; i < m_vecObj[EOBJECT_BG].size(); i++)
	{
		vecBGTilePos = ((Background*)(m_vecObj[EOBJECT_BG])[i])->GetBGTilevecpt();
	}*/

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