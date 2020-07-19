#include "PlayerNormal.h"
#include "ObjManager.h"
#include "InputManager.h"
#include "define.h"
#include "Mainfrm.h"
#include "Bullet.h"

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

	m_itopBitmapImg = USERIDLETOP0;
	m_ibottomBitmapImg = USERIDLEBOTTOM1;
	m_fdelay = 1;

	m_bleftright = true;

	return;
}



void PlayerNormal::AnimationStateCheck()
{
	// bottom 반응
	// 점프할 때 
	if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{

	}
	else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
	{
		m_iobjstate = E_USERSTATE_LWALK;
		m_ibottomBitmapImg = USERRUNBOTTOM2;
		m_bleftright = false;

		SetObjStruct(m_normalplayerbottom, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
			IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y, IDLEUSERDMOVE,
			IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// 오른쪽
	else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
	{
		m_iobjstate = E_USERSTATE_RWALK;
		m_ibottomBitmapImg = USERRUNBOTTOM1;
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
			m_ibottomBitmapImg = USERIDLEBOTTOM1;

			SetObjStruct(m_normalplayerbottom, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
				IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y, IDLEUSERDMOVE,
				IDLEPLAYERWNUM, IDLEPLAYERHNUM);
		}
		else
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_ibottomBitmapImg = USERIDLEBOTTOM2;

			SetObjStruct(m_normalplayerbottom, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
				IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y, IDLEUSERDMOVE,
				IDLEPLAYERWNUM, IDLEPLAYERHNUM);
		}
	}


	// top 반응
	// 총을 쏠 때 
	if (InputManager::GetInstance()->Keyboard(E_KEYFIRE) == true)
	{
		// 오른쪽 방향으로 발사 
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_FIRE;
			m_itopBitmapImg = USERFIRETOP1;

			// struct에 자료 삽입해주는 함수
			SetObjStruct(m_normalplayertop, FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
				FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, FIREUSERDMOVE,
				FIREPLAYERWNUM, FIREPLAYERHNUM);
		}
		// 왼쪽 방향으로 발사 
		else
		{
			m_iobjstate = E_USERSTATE_FIRE;
			m_itopBitmapImg = USERFIRETOP1;

			SetObjStruct(m_normalplayertop, FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
				FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, FIREUSERDMOVE,
				FIREPLAYERWNUM, FIREPLAYERHNUM);
		}
	}
	// 점프할 때 
	else if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{

	}
	// 왼쪽
	else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
	{
		m_iobjstate = E_USERSTATE_LWALK;
		m_itopBitmapImg = USERIDLETOP2;
		m_bleftright = false;

		SetObjStruct(m_normalplayertop, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
			IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, IDLEUSERDMOVE,
			IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// 오른쪽
	else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
	{
		m_iobjstate = E_USERSTATE_RWALK;
		m_itopBitmapImg = USERIDLETOP0;
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
			m_itopBitmapImg = USERIDLETOP0;

			SetObjStruct(m_normalplayertop, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
				IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, IDLEUSERDMOVE,
				IDLEPLAYERWNUM, IDLEPLAYERHNUM);
		}
		else
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_itopBitmapImg = USERIDLETOP2;

			SetObjStruct(m_normalplayertop, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
				IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, IDLEUSERDMOVE,
				IDLEPLAYERWNUM, IDLEPLAYERHNUM);

		}
	}

	return;
}




void PlayerNormal::AnimationStateMove()
{
	RECT recclient;
	GetClientRect(Mainfrm::GethWnd(), &recclient);


	// top 
	switch (m_iobjstate)
		{
			// 멈춤 상태
		case E_USERSTATE_IDLE:
		{
			// 이미지 움직이는 함수 
			Aniimage(m_normalplayertop);
		}
		break;
		case E_USERSTATE_RWALK:
		{
			// 오른쪽 버튼 눌렀을 때 반응
			// 이미지 움직이는 함수 
			Aniimage(m_normalplayertop);

			if (m_normalplayertop.posoriginDest.x >= (recclient.right - (m_normalplayertop.recDest.right * m_normalplayertop.iWidthnum)))
				// 만약 개체가 client 이상 가면 나갈 수 없도록 함 
			{
				break;
			}
			else
			{
				if (InputManager::GetInstance()->Getbkeyboard() == false)
				{
					m_normalplayertop.posoriginDest.x += m_normalplayertop.iobjmove;
				}
			}
		}
		break;
		case E_USERSTATE_LWALK:
		{
			// 왼쪽 버튼 눌렀을 때 반응
			// 이미지 움직이는 함수 
			Aniimage(m_normalplayertop);

			if (m_normalplayertop.posoriginDest.x <= recclient.left)
				// 만약 개체가 client 이상 가면 갈 수 없도록 함 
			{
				break;
			}
			else
			{
				if (InputManager::GetInstance()->Getbkeyboard() == false)
				{
					m_normalplayertop.posoriginDest.x -= m_normalplayertop.iobjmove;
				}
			}
		}
		break;
		case E_USERSTATE_JUMP:
		{
			// 이미지 움직이는 함수 
			Aniimage(m_normalplayertop);
		}
		break;
		case E_USERSTATE_FIRE:
		{
			// 이미지 움직이는 함수 
			Aniimage(m_normalplayertop);

			// 총알 객체 생성 
			Object* objbullet = new Bullet(m_normalplayertop.posoriginDest);
			ObjManager::GetInstance()->SetVector(objbullet, EOBJECT_BULLET);

		}
		break;
	}


	// bottom
	switch (m_iobjstate)
		{
			// 멈춤 상태
		case E_USERSTATE_IDLE:
		{
			// 이미지 움직이는 함수 
			Aniimage(m_normalplayerbottom);
		}
		break;
		case E_USERSTATE_RWALK:
		{
			// 오른쪽 버튼 눌렀을 때 반응
			// 이미지 움직이는 함수 
			Aniimage(m_normalplayerbottom);

			if (m_normalplayerbottom.posoriginDest.x >= (recclient.right - (m_normalplayerbottom.recDest.right * m_normalplayerbottom.iWidthnum)))
				// 만약 개체가 client 이상 가면 나갈 수 없도록 함 
			{
				break;
			}else
			{
				if (InputManager::GetInstance()->Getbkeyboard() == false)
				{
					m_normalplayerbottom.posoriginDest.x += m_normalplayerbottom.iobjmove;
				}
			}

		}
		break;
		case E_USERSTATE_LWALK:
		{
			// 이미지 움직이는 함수 
			Aniimage(m_normalplayerbottom);

			if (m_normalplayerbottom.posoriginDest.x <= recclient.left)
				// 만약 개체가 client 이상 가면 갈 수 없도록 함 
			{
				break;
			}
			else
			{
				if (InputManager::GetInstance()->Getbkeyboard() == false)
				{
					m_normalplayerbottom.posoriginDest.x -= m_normalplayerbottom.iobjmove;
				}
			}

		}
		break;
		case E_USERSTATE_JUMP:
		{
			// 이미지 움직이는 함수 
			Aniimage(m_normalplayerbottom);
		}
		break;
	}

	return;
}







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
	hbottomobjBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(m_ibottomBitmapImg));
	// oldbit 에 이미지 저장 
	holdBit = (HBITMAP)SelectObject(hobjdc, hbottomobjBit);

	// 하체 이미지 출력
	TransparentBlt(_hdc, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y,
		m_normalplayerbottom.recDest.right * PLAYERSIZE, m_normalplayerbottom.recDest.bottom * PLAYERSIZE,
		hobjdc, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
		m_normalplayerbottom.recSrc.right, m_normalplayerbottom.recSrc.bottom, RGB(255, 255, 255));


	// 비트맵을 hBIt에 뿌려주기
	// hinst를 null로 하지 말자 
	htopobjBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(m_itopBitmapImg));
	// oldbit 에 상체 이미지 저장 
	holdBit = (HBITMAP)SelectObject(hobjdc, htopobjBit);

	// 상체 이미지 출력
	TransparentBlt(_hdc, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y,
		m_normalplayertop.recDest.right * 4, m_normalplayertop.recDest.bottom * 4,
		hobjdc, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
		m_normalplayertop.recSrc.right, m_normalplayertop.recSrc.bottom, RGB(255, 255, 255));
	

	// 시간을 받아옴
	m_dcurTime = timeGetTime();

	// 만약 이전 시간에서 현재 시간이 0.1float 지났을 때 
	if (m_dcurTime - m_dPrevTime >= 0.1f * m_fdelay)
	{
		// object 상태 움직임 변경 
		Animation(_hdc, m_normalplayertop, m_iobjstate);
		Animation(_hdc, m_normalplayerbottom, m_iobjstate);

		// 이전 시간을 현재 시간으로 대체
		m_dPrevTime = m_dcurTime;
	}

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
	return;
};


bool PlayerNormal::bObjDead()
{
	return false;
}

