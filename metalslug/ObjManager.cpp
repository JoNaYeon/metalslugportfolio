#include "Object.h"
#include "ObjManager.h"
#include "Monster.h"
#include "Player.h"
#include "Background.h"
#include "PlayerNormal.h"

// �ʱ�ȭ
ObjManager* ObjManager::m_pinstance = NULL;


// ������
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
        
        // POINT �� x�� ��ġ ����
        postemp.x = postemp.x * BGSIZE;
        // POINT �� y�� ��ġ ����
        postemp.y = (postemp.y - BGDELETESIZE) * BGSIZE;

        m_vecpos.push_back(postemp);
    }
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
	BackgroundMove();

	// Object �� Tile �浹��
	// ���� CollisionCheck() �� ��ġ��.
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

		// client ȭ�� ũ�� �޾ƿ���
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
		
		// �ٴ� �׷��ֱ�
		for (int i = 0; i < m_vecpos.size() - 1; i++)
		{
			MoveToEx(hdc, m_vecpos[i].x, m_vecpos[i].y, NULL);
			LineTo(hdc, m_vecpos[i + 1].x, m_vecpos[i + 1].y);
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


	// Bullet �� Monster �� �浹�� 
	for (int i = 0; i < m_vecObj[EOBJECT_BULLET].size(); i++)
	{
		std::vector<Object*>::iterator iter = m_vecObj[EOBJECT_BULLET].begin();
		RECT recHitBullet = m_vecObj[EOBJECT_BULLET][i]->GetHitBox();
		bool bright = false;

		for (int j = 0; j < m_vecObj[EOBJECT_MONSTER].size(); j++)
		{
			RECT recHitMonster = m_vecObj[EOBJECT_MONSTER][j]->GetHitBox();

			// ���ʿ��� �ǰݴ����� ��
			if ( (recHitMonster.left + (recHitMonster.left - recHitMonster.right / 2)) >= recHitBullet.right)
			{
				bright = false;
			}
			// �����ʿ��� �ǰݴ����� ��
			else if ((recHitMonster.left + (recHitMonster.left - recHitMonster.right / 2)) < recHitBullet.right)
			{
				bright = true;
			}

			if (IntersectRect(&rectemp, &recHitBullet, &recHitMonster) == true)
			{
				// bullet �ı�
				delete m_vecObj[EOBJECT_BULLET][i];
				m_vecObj[EOBJECT_BULLET][i] = NULL;

				
				iter = (m_vecObj[EOBJECT_BULLET]).erase(iter);
				bCollisiontemp = true;

				// ���Ͱ� �ǰݵǾ����� �˷��ְ� 
				m_vecObj[EOBJECT_MONSTER][j]->SetCollisionCheck(bCollisiontemp);

				// ���� �ǰ� �¿� �˷��ֱ�
				// �����ʿ��� ���� ��
				if (bright == true)
				{
					// Monster �ڷ� �и���
					DISPLAYINFO MonDisTemp = *((m_vecObj[EOBJECT_MONSTER][j])->GetDisTop());
					MonDisTemp.ptDestPos.x -= MONHITEDMOTION;

					m_vecObj[EOBJECT_MONSTER][j]->SetDisTop(MonDisTemp.ptDestPos);
				}
				// ���ʿ��� ���� ��
				//else
				{
					// Monster �ڷ� �и���
					DISPLAYINFO MonDisTemp = *((m_vecObj[EOBJECT_MONSTER][j])->GetDisTop());
					MonDisTemp.ptDestPos.x += MONHITEDMOTION;

					m_vecObj[EOBJECT_MONSTER][j]->SetDisTop(MonDisTemp.ptDestPos);
				}

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

	return; 
}



// ��Ÿ���� ����ִ� �Լ�
void ObjManager::BackgroundLineCollision(E_OBJECT _Eobj)
{
	// ������Ʈ ������ŭ �����ֱ�
	for (int i = 0; i < m_vecObj[_Eobj].size(); i++)
	{
		// false�� ��� continue�� �ϴ� �ڵ� �Ѿ��
		if (m_vecObj[_Eobj][i]->GetbCollision() == false)
		{
			continue;
		}


		// �̹����� ��ġ�� ��������
		int ixobjectpos = m_vecObj[_Eobj][i]->GetDisTop()->ptDestPos.x;
		int iyobjectpos = m_vecObj[_Eobj][i]->GetDisTop()->ptDestPos.y; // �ش� ������Ʈ�� �����ప

		// �̹��� ������ �������� 
		POINT pImgSizetemp = { (m_vecObj[_Eobj][i]->GetDisTop()->ptDestSize.x) ,
			(m_vecObj[_Eobj][i]->GetDisTop()->ptDestSize.y)};


		// �浹�� ������ POINT �� ������ŭ ���Ƽ� �˻����ֱ� 
		for (int j = 0; j < m_vecpos.size() - 1; j++)
		{
			// Object �� x ��ġ�� POINT ���̰��� ������ ���
			if (m_vecpos[j].x <= ixobjectpos && ixobjectpos < m_vecpos[j + 1].x)
			{
				// ������ ����
				float fm = 0;
				// y�� ����
				int iy = 0;
				// ������ ��ġ�� y ��
				int iobjdistancey = 0;

				// ���� ���ϱ�
				float fnextjy =  (float)m_vecpos[j + 1].y;
				float fjy = (float)m_vecpos[j].y;
				float fnextjx = (float)m_vecpos[j + 1].x;
				float fjx = (float)m_vecpos[j].x;

				fm = ((fnextjy - fjy) / (fnextjx - fjx));

				// y���� ���ϱ�
				iy = m_vecpos[j].y - (fm * m_vecpos[j].x); // j��°�� �ִ� ���� y������ ���� * ���� x���� ���Ѱ� ����. 

				// y�� Ÿ�� ��ġ ���
				iobjdistancey = (fm * ixobjectpos) + iy;


				// �ӽ� - y��ġ�� ����Ͽ� �¿� ���� �������� ���Ͽ� �������� ���� ���� �����ִ� �Լ�
				switch (m_vecObj[_Eobj][i]->ObjectyLevel(iobjdistancey))
				{
					// ĳ���Ͱ� �ö󰡾� �� ��
					case E_USERYUPDOWN_UP:
					{
						// Object �� ��ġ���� ���ؿ� ��
						POINT ptobjectpos = { m_vecObj[_Eobj][i]->GetDisTop()->ptDestPos.x, iobjdistancey - (m_vecObj[_Eobj][i]->GetDisTop()->ptDestSize.y * PLAYERSIZE) };

						// y ��ġ�� �������ֱ�...
						m_vecObj[_Eobj][i]->SetDisTop(ptobjectpos);
						// ���� ���� Object�� User �� ���, Bot �κе� �������ֱ�
						if (_Eobj == EOBJECT_USER)
						{
							// top ��ġ�� bot �����ֱ�
							(m_vecObj[_Eobj][i])->SetDisBot(ptobjectpos);
						}
					}
						break;

					// ĳ���Ͱ� ����� �� ��
					case E_USERYUPDOWN_STOP:
					{
						// �ӽ� - �ѹ� �� ObjectState�� �˻��ϱ� ���� �Լ��� �� ����ϴ� ���� ������...? ��ΰ��... 
						// ������ �ӽ�ó���� �س��� ������ Ȥ�� �ٸ� ������ ����� �� ������ �� ���� ���� �� ����.
						//m_vecObj[_Eobj][i]->ObjectStopYLevelControl(iobjdistancey);
					}
						break;
				
					case E_USERYUPDOWN_JUMP:
					{
						m_vecObj[_Eobj][i]->SetJump(true);
						m_vecObj[_Eobj][i]->Setobjstate(E_USERSTATE_JUMP);

						// Object �� ��ġ���� ���ؿ� ��
						/*POINT ptobjectpos = { m_vecObj[_Eobj][i]->GetDisTop()->ptDestPos.x, iobjdistancey - (m_vecObj[_Eobj][i]->GetDisTop()->ptDestSize.y * PLAYERSIZE) };

						m_vecObj[_Eobj][i]->SetDisTop(ptobjectpos);
						// ���� ���� Object�� User �� ���, Bot �κе� �������ֱ�
						if (_Eobj == EOBJECT_USER)
						{
							// top ��ġ�� bot �����ֱ�
							(m_vecObj[_Eobj][i])->SetDisBot(ptobjectpos);
						}*/
					}
						break;
					case E_USERUPDOWN_JUMPSTOP:
					{

					}
						break;
				}



				// Object �� ���°� jump �� �ƴ� ������ gravity�� false �� �ٲ��ֱ�
				if (m_vecObj[_Eobj][i]->Getobjstate() == E_USERSTATE_JUMP)
				{
					m_vecObj[_Eobj][i]->SetJump(false);
					m_vecObj[_Eobj][i]->Setobjstate(E_USERSTATE_IDLE);
				}
				else
				{
					m_vecObj[_Eobj][i]->SetboolGravity(true);
				}

				// ������Ʈ�� y���� ���ư� ��ġ�� y������ ���� ���� ��� ���ư��� ���ϵ���.
				/*if ((iyplayerpos + (pImgSizetemp.y * PLAYERSIZE)) - iobjdistancey >= 10)
				{
					if(m_vecObj[_Eobj][i]->Getobjstate() == )
					POINT posobjectreposition = { ixplayerpos , iyplayerpos };

					// ���ư��� ���ϵ��� �ϴ� �ڵ�
					m_vecObj[_Eobj][i]->SetDisTop();
				}*/

				break;
			}
		}
		
	}


	return;
}

// ������ ��ġ�� ���� ���� ������Ʈ���� �������ִ� �Լ�
void ObjManager::BackgroundMove()
{
	std::vector<Object*> vecusertemp = ObjManager::GetInstance()->GetVector(EOBJECT_USER);

	std::vector<Object*> vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_BG);

	for (int i = 0; i < vecusertemp.size(); i++)
	{
		// ������ ������ �ִ� b_BGMove ������ true �� ��쿡�� �������ֵ���.
		if (((Player*)(vecusertemp[i]))->GetBGMove() == true)
		{
			// ��� �������ֱ�
			for (int i = 0; i < vectemp.size(); i++)
			{
				Background* bgtemp = (Background*)vectemp[i];
				// ��� �����̱�
				bgtemp->BackgroundMove(E_USERSTATE_RWALK);
				// Ÿ�� �������ֱ�
				TileMove(E_USERSTATE_RWALK);
			}

			// ���� �������ֱ�
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



// Ÿ�� �������ִ� �Լ�
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