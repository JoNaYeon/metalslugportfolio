#include "PlayerNormal.h"
#include "ObjManager.h"
#include "InputManager.h"
#include "define.h"
#include "Mainfrm.h"
#include "Bullet.h"
#include "Background.h"
#include "Monster.h"

MSG* Mainfrm::m_msg;

PlayerNormal::PlayerNormal()
{
	m_iobjstate = E_USERSTATE_IDLE;

	// 상체 구조체 정의
	m_normalplayertop.recSrc = { 0, 0, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };
	m_normalplayertop.poriginSrc = { 0, 0 };
	m_normalplayertop.recDest = { 0, 0, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };
	m_normalplayertop.posoriginDest = { 0, 500 };
	m_normalplayertop.iobjmove = IDLEUSERDMOVE;
	m_normalplayertop.iWidthnum = IDLEPLAYERWNUM;
	m_normalplayertop.iHightnum = IDLEPLAYERHNUM;
	// 하체 구조체 정의
	m_normalplayerbottom.recSrc = { 0, 0, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };
	m_normalplayerbottom.poriginSrc = { 0, 0 };
	m_normalplayerbottom.recDest = { 0, 0, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };
	m_normalplayerbottom.posoriginDest = { 0, 500 };
	m_normalplayerbottom.iobjmove = IDLEUSERDMOVE;
	m_normalplayerbottom.iWidthnum = IDLEPLAYERWNUM;
	m_normalplayerbottom.iHightnum = IDLEPLAYERHNUM;

	//m_itopBitmapImg = USERIDLETOP0;
	//m_ibottomBitmapImg = USERIDLEBOTTOM1;

	m_fdelay = 0.5;

	m_bleftright = true;

	return;
}



// 어떤 애니메이션이 들어가는지 체크해주는 함수
void PlayerNormal::AnimationStateCheck()
{
	//////////////////////////////////// bottom 반응
	// 점프할 때 
	if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{
		/*m_iobjstate = E_USERSTATE_JUMP;
		m_strBitmapBottom = "..\\source\\user\\userjunp.bmp";

		SetObjStruct(m_normalplayerbottom, JUMPPLAYERWANIMATION, JUMPPLAYERHANIMATION, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
			JUMPPLAYERWANIMATION, JUMPPLAYERHANIMATION, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y, JUMPUSERDMOVE,
			JUMPPLAYERWNUM, JUMPPLAYERHNUM);*/

		m_bjump = true;
	}
	// 왼쪽 
	else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
	{
		m_iobjstate = E_USERSTATE_LWALK;
		m_strBitmapBottom = "..\\source\\user\\UserRun_Bottom2.bmp";
		m_bleftright = false;

		SetObjStruct(m_normalplayerbottom, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
			IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y, IDLEUSERDMOVE,
			IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// 오른쪽
	else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
	{
		m_iobjstate = E_USERSTATE_RWALK;
		//m_ibottomBitmapImg = USERRUNBOTTOM1;
		m_strBitmapBottom = "..\\source\\user\\UserRun_Bottom1.bmp";
		m_bleftright = true;

		SetObjStruct(m_normalplayerbottom, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
			IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y, IDLEUSERDMOVE,
			IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// 아무것도 아닐 때 
	else
	{
		// bool 변수 혹은 enum 으로 좌우 위치 확인해주기
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_IDLE;
			//m_ibottomBitmapImg = USERIDLEBOTTOM1;
			m_strBitmapBottom = "..\\source\\user\\UserIdle_Bottom1.bmp";

			SetObjStruct(m_normalplayerbottom, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
				IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y, IDLEUSERDMOVE,
				IDLEPLAYERWNUM, IDLEPLAYERHNUM);
		}
		else
		{
			m_iobjstate = E_USERSTATE_IDLE;
			//m_ibottomBitmapImg = USERIDLEBOTTOM2;
			m_strBitmapBottom = "..\\source\\user\\UserIdle_Bottom2.bmp";

			SetObjStruct(m_normalplayerbottom, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
				IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y, IDLEUSERDMOVE,
				IDLEPLAYERWNUM, IDLEPLAYERHNUM);
		}
	}


	//////////////////////////////////////// top 반응
	// 총을 쏠 때 
	if (InputManager::GetInstance()->Keyboard(E_KEYFIRE) == true)
	{
		// 오른쪽 방향으로 발사 
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_FIRE;
			//m_itopBitmapImg = USERFIRETOP1;
			m_strBitmapTop = "..\\source\\user\\usertopfire.bmp";

			// struct에 자료 삽입해주는 함수
			SetObjStruct(m_normalplayertop, FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
				FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, FIREUSERDMOVE,
				FIREPLAYERWNUM, FIREPLAYERHNUM);
		}
		// 왼쪽 방향으로 발사 
		else
		{
			m_iobjstate = E_USERSTATE_FIRE;
			//m_itopBitmapImg = USERFIRETOP1;
			m_strBitmapTop = "..\\source\\user\\usertopfire.bmp";

			SetObjStruct(m_normalplayertop, FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
				FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, FIREUSERDMOVE,
				FIREPLAYERWNUM, FIREPLAYERHNUM);
		}
	}
	// 점프할 때 
	else if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{
		/*m_iobjstate = E_USERSTATE_JUMP;
		//m_itopBitmapImg = USERIDLETOP2;
		m_strBitmapTop = "..\\source\\user\\userjunptop.bmp";

		SetObjStruct(m_normalplayertop, JUMPPLAYERWANIMATION, JUMPPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
			JUMPPLAYERWANIMATION, JUMPPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, JUMPUSERDMOVE,
			JUMPPLAYERWNUM, JUMPPLAYERHNUM);*/

	}
	// 왼쪽
	else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
	{
		m_iobjstate = E_USERSTATE_LWALK;
		//m_itopBitmapImg = USERIDLETOP2;
		m_strBitmapTop = "..\\source\\user\\UserIdle_Top2.bmp";
		m_bleftright = false;

		SetObjStruct(m_normalplayertop, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
			IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, IDLEUSERDMOVE,
			IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// 오른쪽
	else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
	{
		m_iobjstate = E_USERSTATE_RWALK;
		//m_itopBitmapImg = USERIDLETOP0;
		m_strBitmapTop = "..\\source\\user\\UserIdle_Top1.bmp";
		m_bleftright = true;

		SetObjStruct(m_normalplayertop, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
			IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, IDLEUSERDMOVE,
			IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// 아무것도 아닐 때 
	else
	{
		// bool 변수 혹은 enum 으로 좌우 위치 확인해주기
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_IDLE;
			//m_itopBitmapImg = USERIDLETOP0;
			m_strBitmapTop = "..\\source\\user\\UserIdle_Top1.bmp";

			SetObjStruct(m_normalplayertop, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
				IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, IDLEUSERDMOVE,
				IDLEPLAYERWNUM, IDLEPLAYERHNUM);
		}
		else
		{
			m_iobjstate = E_USERSTATE_IDLE;
			//m_itopBitmapImg = USERIDLETOP2;
			m_strBitmapTop = "..\\source\\user\\UserIdle_Top2.bmp";

			SetObjStruct(m_normalplayertop, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
				IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, IDLEUSERDMOVE,
				IDLEPLAYERWNUM, IDLEPLAYERHNUM);

		}
	}

	m_recHitBox = { m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y,
		m_normalplayertop.posoriginDest.x + m_normalplayertop.recDest.right * PLAYERSIZE,
		m_normalplayertop.posoriginDest.y + m_normalplayertop.recDest.bottom * PLAYERSIZE };

	return;
}




bool PlayerNormal::PlayerPosCheck()
{
	RECT recClient = ObjManager::GetInstance()->GetRect();
	std::vector<Object*> vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_BG);

	Background* bgtemp = (Background*)vectemp[EOBJECT_BG];

	bool btemp = false;

	// 좌우 확인 
	if (m_normalplayertop.posoriginDest.x <= (recClient.right / 2) - (m_normalplayertop.recDest.right * PLAYERSIZE))
	{
		btemp = false;
	}
	else if (bgtemp->GetBG().poriginSrc.x >= BGEND)
	{
		btemp = false;
	}
	else 
	{
		btemp = true;
	}

	

	return btemp;
}




// 애니메이션의 움직임을 실행해주는 함수
void PlayerNormal::AnimationStateMove()
{
	/////////////////////////////////// top 
	switch (m_iobjstate)
	{
		// 멈춤 상태
		case E_USERSTATE_IDLE:
		{
		}
		break;
		case E_USERSTATE_RWALK:
		// 오른쪽 버튼 눌렀을 때 반응
		{
			if (ObjManager::GetInstance()->GetRect().right - (m_normalplayertop.recSrc.right * PLAYERSIZE) <= (m_normalplayertop.posoriginDest.x))
			{
				break;
			}
			else if (PlayerPosCheck() == false)
			{
				m_normalplayertop.posoriginDest.x += IDLEUSERDMOVE;
				m_normalplayerbottom.posoriginDest.x += IDLEUSERDMOVE;
			}
			else
			{
				// 배경 움직이기
				std::vector<Object*> vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_BG);

				for (int i = 0; i < vectemp.size(); i++)
				{
					Background* bgtemp = (Background*)vectemp[i];
					//Monster* monstertemp = (Monster*)vectemp[i];
					bgtemp->BackgroundMove(E_USERSTATE_RWALK);
				}

				// 몬스터 움직이기
				vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_MONSTER);

				for (int i = 0; i < vectemp.size(); i++)
				{
					Monster* Monstertemp = (Monster*)vectemp[i];
					Monstertemp->MonsterMove(E_USERSTATE_RWALK);
				}
			}
		}
		break;
		case E_USERSTATE_LWALK:
		// 왼쪽 버튼 눌렀을 때 반응
		{
			// client 밖으로 못 나가도록 
			if (ObjManager::GetInstance()->GetRect().left >= m_normalplayertop.posoriginDest.x)
			{
				break;
			}
			else
			{
				m_normalplayertop.posoriginDest.x -= IDLEUSERDMOVE;
				m_normalplayerbottom.posoriginDest.x -= IDLEUSERDMOVE;
			}
		}
		break;
		case E_USERSTATE_JUMP:
		// 점프
		{
			m_bjump = true;
		}
		break;
		case E_USERSTATE_FIRE:
		// 총알 발사
		{
			Object* objbullet = new Bullet(m_normalplayertop.posoriginDest);
			ObjManager::GetInstance()->SetVector(objbullet, EOBJECT_BULLET);

		}
		break;
	}



	/////////////////////////////// bottom
	switch (m_iobjstate)
	{
			// 멈춤 상태
		case E_USERSTATE_IDLE:
		{
		}
		break;
		case E_USERSTATE_RWALK:
		// 오른쪽 버튼 눌렀을 때 반응
		{

		}
		break;
		case E_USERSTATE_LWALK:
		// 왼쪽 버튼 눌렀을 때 반응
		{
			
		}
		break;
		case E_USERSTATE_JUMP:
		// 점프
		{
		}
		break;
	}

	m_fdelay = 0.5;

	// 시간을 받아옴
	m_dcurTime = timeGetTime();

	// 만약 이전 시간에서 현재 시간이 0.1float 지났을 때 
	if (m_dcurTime - m_dPrevTime >= 0.1f * m_fdelay)
	{
		Aniimage(m_normalplayertop);
		Aniimage(m_normalplayerbottom);

		// 이전 시간을 현재 시간으로 대체
		m_dPrevTime = m_dcurTime;
	}

	return;
}




// rect가 부딪힌 것을 확인해주는 함수
/*bool PlayerNormal::IntersectRectCheck(RECT* _rec1, RECT* _rec2)
{
	//bool bInter = IntersectRect(recInter, _rec1, _rec2);

	if ((_rec1->right >= _rec2->left) && (_rec1->left <= _rec2->right))
	{
		if ((_rec1->bottom >= _rec2->top) && (_rec1->top <= _rec2->bottom))
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}*/



// 오브젝트 초기화 (오버라이딩)
void PlayerNormal::Init()
{
	return;
};

// 오브젝트 움직임 (오버라이딩)
void PlayerNormal::Run()
{
	// 키보드 입력 받기
	// 키보드 입력은 정리해서 판정에 우선순위를 구분할 것 

	AnimationStateCheck();
	AnimationStateMove();

	if (m_bjump == true)
	{
		Jump();
	}

	Gravity(&m_normalplayertop);
	Gravity(&m_normalplayerbottom);		// 껍데기 함수, 해결방안 고안 해야함 < 한슬이가 해야함

	// 배경 위에 설 수 있게 해주는 함수
	ObjStand(&m_normalplayertop);
	ObjStand(&m_normalplayerbottom);	// 하나의 함수로 해결할 수 있도록 하는 것 ☆

	return;
};

// 오브젝트 출력 (오버라이딩)
void PlayerNormal::Render(HDC& _hdc, HWND& _hWnd)
{ 
	// 이미지의 hdc
	HDC hobjdc;
	// 이미지 로드받을 hbitmap
	HBITMAP htopobjBit;
	HBITMAP hbottomobjBit;
	// 이미지 저장받을 hbitmap
	HBITMAP holdBit;
	
	// 범위 리셋 
	RECT recClient = ObjManager::GetInstance()->GetRect();
	GetClientRect(_hWnd, &recClient);

	// 이미지 출력할 hdc 출력 
	hobjdc = CreateCompatibleDC(_hdc);


	// 비트맵을 hBIt에 뿌려주기
	// hinst를 null로 하지 말자 
	//htopobjBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(m_itopBitmapImg));
	htopobjBit = (HBITMAP)LoadImage(NULL, m_strBitmapBottom, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// oldbit 에 상체 이미지 저장 
	holdBit = (HBITMAP)SelectObject(hobjdc, htopobjBit);

	// 상체 이미지 출력
	TransparentBlt(_hdc, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y,
		m_normalplayertop.recDest.right * 4, m_normalplayertop.recDest.bottom * 4,
		hobjdc, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
		m_normalplayertop.recSrc.right, m_normalplayertop.recSrc.bottom, RGB(255, 255, 255));


	// 비트맵을 hBIt에 뿌려주기
	// hinst를 null로 하지 말자 
	//hbottomobjBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(m_ibottomBitmapImg));
	hbottomobjBit = (HBITMAP)LoadImage(NULL, m_strBitmapTop, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// oldbit 에 이미지 저장 
	holdBit = (HBITMAP)SelectObject(hobjdc, hbottomobjBit);

	// 하체 이미지 출력
	TransparentBlt(_hdc, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y,
		m_normalplayerbottom.recDest.right * PLAYERSIZE, m_normalplayerbottom.recDest.bottom * PLAYERSIZE,
		hobjdc, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
		m_normalplayerbottom.recSrc.right, m_normalplayerbottom.recSrc.bottom, RGB(255, 255, 255));
	

	// 히트박스 임시 
	Rectangle(_hdc, m_recHitBox.left, m_recHitBox.top, m_recHitBox.right, m_recHitBox.bottom);

	// oldbit로 바꿔주기
	SelectObject(hobjdc, holdBit);

	DeleteDC(hobjdc);
	DeleteObject(htopobjBit);
	DeleteObject(hbottomobjBit);

	return;
};

// 오브젝트 파괴 (오버라이딩)
void PlayerNormal::Destroy()
{
	return;
};

// 좀비가 되는 애니메이션 
void PlayerNormal::DeadZombie()
{
	return;
};

// 공격 - 총 (오버라이딩)
void PlayerNormal::AttackGun()
{
	return;
};

// 공격 - 나이프 (오버라이딩)
void PlayerNormal::AttackKnife()
{
	return;
};

// 공격 - 폭탄 (오버라이딩)
void PlayerNormal::AttackBomb()
{
	return;
};

// 점프 (오버라이딩)
void PlayerNormal::Jump()
{
	Player::Jump();

	return;
};


bool PlayerNormal::bObjDead()
{
	return false;
}

