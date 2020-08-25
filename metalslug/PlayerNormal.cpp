#include "PlayerNormal.h"
#include "InputManager.h"
#include "define.h"
#include "Mainfrm.h"
#include "Background.h"
#include "Monster.h"

MSG* Mainfrm::m_msg;

PlayerNormal::PlayerNormal()
{
	m_iobjstate = E_USERSTATE_IDLE;
	m_iobjmove = IDLEUSERDMOVE;

	m_fdelay = 0.5;
	m_bleftright = true;
	// 중력 받기
	m_bgravity = true;
	
	// 플레이어 배경 움직이기
	m_bmove = false;

	// 상체 구조체 정의
	m_DisTop.ptDestPos = { 0, 400 };
	m_DisTop.ptSrcPos = { 0, 0 };
	m_DisTop.ptDestSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };
	
	m_ImgTop.iWidthnum = IDLEPLAYERWNUM;
	m_ImgTop.iHightnum = IDLEPLAYERHNUM;
	m_ImgTop.ptSrcSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };

	// 하체 구조체 정의
	m_DisBot.ptDestPos = { 0, 400 };
	m_DisBot.ptSrcPos = { 0, 0 };
	m_DisBot.ptDestSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };

	m_ImgBot.iWidthnum = IDLEPLAYERWNUM;
	m_ImgBot.iHightnum = IDLEPLAYERHNUM;
	m_ImgBot.ptSrcSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };

	m_recHitBox = { m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		m_DisTop.ptDestPos.x + (m_DisTop.ptDestSize.x * PLAYERSIZE), m_DisTop.ptDestPos.y + (m_DisTop.ptDestSize.y * PLAYERSIZE) };

	return;
}



// 어떤 애니메이션이 들어가는지 체크해주는 함수
void PlayerNormal::AnimationStateCheck()
{
	POINT ptImgSize = { 0, 0 };


	// 한번 누를 때 반응을 보이는 이미지들
	// 점프중일 때 
	if (m_bjump == true)
	{
		m_iobjstate = E_USERSTATE_JUMP;
		m_iobjmove = JUMPUSERDMOVE;
		ptImgSize = { JUMPPLAYERWANIMATION , JUMPPLAYERHANIMATION };

		m_strBitmapBottom = "..\\source\\user\\userjunp.bmp";
		m_DisBot.ptDestSize = ptImgSize;
		SetImgInfo(m_ImgBot, ptImgSize, JUMPPLAYERWNUM, JUMPPLAYERHNUM);

		m_strBitmapTop = "..\\source\\user\\userjunptop.bmp";
		m_DisTop.ptDestSize = ptImgSize;
		SetImgInfo(m_ImgTop, ptImgSize, JUMPPLAYERWNUM, JUMPPLAYERHNUM);

		// 총 쏠 때 
		if (InputManager::GetInstance()->Keyboard(E_KEYFIRE) == true)
		{
			// 오른쪽 방향으로 발사 
			if (m_bleftright == true)
			{
				m_iobjstate = E_USERSTATE_FIRE;
				m_strBitmapTop = "..\\source\\user\\usertopfire.bmp";

				// struct에 자료 삽입해주는 함수
				m_iobjmove = FIREUSERDMOVE;
				ptImgSize = { FIREPLAYERWANIMATION , FIREPLAYERHANIMATION };
				m_DisTop.ptDestSize = ptImgSize;
				SetImgInfo(m_ImgTop, ptImgSize, FIREPLAYERWNUM, FIREPLAYERHNUM);
			}
			// 왼쪽 방향으로 발사 
			else
			{
				m_iobjstate = E_USERSTATE_FIRE;
				m_strBitmapTop = "..\\source\\user\\usertopfire.bmp";

				m_iobjmove = -FIREUSERDMOVE;
				ptImgSize = { FIREPLAYERWANIMATION , FIREPLAYERHANIMATION };
				m_DisTop.ptDestSize = ptImgSize;
				SetImgInfo(m_ImgTop, ptImgSize, FIREPLAYERWNUM, FIREPLAYERHNUM);
			}
			m_bfire = true;
		}
		// 왼쪽 방향으로 움직이기
		else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
		{
			// 중력 true
			m_bleftright = true;

			m_iobjstate = E_USERSTATE_LWALK;
			m_iobjmove = IDLEUSERDMOVE;
			ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };

			m_strBitmapBottom = "..\\source\\user\\UserRun_Bottom2.bmp";
			m_DisBot.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgBot, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);

			m_strBitmapTop = "..\\source\\user\\UserIdle_Top2.bmp";
			m_DisTop.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);

		}
		// 오른쪽 방향으로 움직이기
		else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
		{
			// 중력 true
			m_bleftright = true;

			m_iobjstate = E_USERSTATE_RWALK;
			m_iobjmove = IDLEUSERDMOVE;
			ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };

			m_strBitmapBottom = "..\\source\\user\\UserRun_Bottom1.bmp";
			m_DisBot.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgBot, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);

			m_strBitmapTop = "..\\source\\user\\UserIdle_Top1.bmp";
			m_DisTop.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
		}
	}
	// 점프중이 아닐 때
	else
	{
		// 총 쏠 때 
		if (InputManager::GetInstance()->Keyboard(E_KEYFIRE) == true)
		{
			// 오른쪽 방향으로 발사 
			if (m_bleftright == true)
			{
				m_iobjstate = E_USERSTATE_FIRE;
				m_strBitmapTop = "..\\source\\user\\usertopfire.bmp";

				// struct에 자료 삽입해주는 함수
				m_iobjmove = FIREUSERDMOVE;
				ptImgSize = { FIREPLAYERWANIMATION , FIREPLAYERHANIMATION };
				m_DisTop.ptDestSize = ptImgSize;
				SetImgInfo(m_ImgTop, ptImgSize, FIREPLAYERWNUM, FIREPLAYERHNUM);
			}
			// 왼쪽 방향으로 발사 
			else
			{
				m_iobjstate = E_USERSTATE_FIRE;
				m_strBitmapTop = "..\\source\\user\\usertopfire.bmp";

				m_iobjmove = -FIREUSERDMOVE;
				ptImgSize = { FIREPLAYERWANIMATION , FIREPLAYERHANIMATION };
				m_DisTop.ptDestSize = ptImgSize;
				SetImgInfo(m_ImgTop, ptImgSize, FIREPLAYERWNUM, FIREPLAYERHNUM);
			}

			m_bfire = true;
		}
		// 점프할 때 
		else if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
		{
			// 중력 false
			m_bleftright = false;
			// 점프 true
			m_bjump = true;
		}
		// 왼쪽 방향으로 움직이기
		else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
		{
			// 중력 true
			m_bleftright = true;

			m_iobjstate = E_USERSTATE_LWALK;
			m_iobjmove = IDLEUSERDMOVE;
			ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };

			m_strBitmapBottom = "..\\source\\user\\UserRun_Bottom2.bmp";
			m_DisBot.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgBot, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);

			m_strBitmapTop = "..\\source\\user\\UserIdle_Top2.bmp";
			m_DisTop.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);

		}
		// 오른쪽 방향으로 움직이기
		else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
		{
			// 중력 true
			m_bleftright = true;

			m_iobjstate = E_USERSTATE_RWALK;
			m_iobjmove = IDLEUSERDMOVE;
			ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };

			m_strBitmapBottom = "..\\source\\user\\UserRun_Bottom1.bmp";
			m_DisBot.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgBot, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);

			m_strBitmapTop = "..\\source\\user\\UserIdle_Top1.bmp";
			m_DisTop.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
		}
		// IDELE
		else
		{
			// bool 변수 혹은 enum 으로 좌우 위치 확인해주기
			if (m_bleftright == true)
			{
				// 중력 true
				m_bleftright = true;

				m_iobjstate = E_USERSTATE_IDLE;
				m_iobjmove = IDLEUSERDMOVE;

				ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };

				m_strBitmapBottom = "..\\source\\user\\UserIdle_Bottom1.bmp";
				m_DisBot.ptDestSize = ptImgSize;
				SetImgInfo(m_ImgBot, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);

				m_strBitmapTop = "..\\source\\user\\UserIdle_Top1.bmp";
				m_DisTop.ptDestSize = ptImgSize;
				SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
			}
			else
			{
				// 중력 true
				m_bleftright = true;

				m_iobjstate = E_USERSTATE_IDLE;
				m_iobjmove = IDLEUSERDMOVE;

				ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };

				m_strBitmapBottom = "..\\source\\user\\UserIdle_Bottom2.bmp";
				m_DisBot.ptDestSize = ptImgSize;
				SetImgInfo(m_ImgBot, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);

				m_strBitmapTop = "..\\source\\user\\UserIdle_Top2.bmp";
				m_DisTop.ptDestSize = ptImgSize;
				SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);

			}
		}
	}
	
	//////////////////////////////////////// top 반응
	/*// 총을 쏠 때 
	if (InputManager::GetInstance()->Keyboard(E_KEYFIRE) == true)
	{
		// 오른쪽 방향으로 발사 
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_FIRE;
			m_strBitmapTop = "..\\source\\user\\usertopfire.bmp";

			// struct에 자료 삽입해주는 함수
			m_iobjmove = FIREUSERDMOVE;
			ptImgSize = { FIREPLAYERWANIMATION , FIREPLAYERHANIMATION };
			m_DisTop.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgTop, ptImgSize, FIREPLAYERWNUM, FIREPLAYERHNUM);
		}
		// 왼쪽 방향으로 발사 
		else
		{
			m_iobjstate = E_USERSTATE_FIRE;
			m_strBitmapTop = "..\\source\\user\\usertopfire.bmp";
			
			m_iobjmove = -FIREUSERDMOVE;
			ptImgSize = { FIREPLAYERWANIMATION , FIREPLAYERHANIMATION };
			m_DisTop.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgTop, ptImgSize, FIREPLAYERWNUM, FIREPLAYERHNUM);
		}

		m_bfire = true;
	}
	// 점프할 때 
	else if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{
		// 중력 false
		m_bleftright = false;
		// 점프 true
		m_bjump = true;

	}
	// 왼쪽으로 걷기
	else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
	{
		m_iobjstate = E_USERSTATE_LWALK;
		m_strBitmapTop = "..\\source\\user\\UserIdle_Top2.bmp";
		// 중력 true
		m_bleftright = true;

		m_iobjmove = IDLEUSERDMOVE;
		ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
		m_DisTop.ptDestSize = ptImgSize;
		SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// 오른쪽으로 걷기
	else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
	{
		m_iobjstate = E_USERSTATE_RWALK;
		m_strBitmapTop = "..\\source\\user\\UserIdle_Top1.bmp";
		// 중력 true
		m_bleftright = true;

		m_iobjmove = IDLEUSERDMOVE;
		ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
		m_DisTop.ptDestSize = ptImgSize;
		SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// IDLE
	else
	{
		// bool 변수 혹은 enum 으로 좌우 위치 확인해주기
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_strBitmapTop = "..\\source\\user\\UserIdle_Top1.bmp";
			// 중력 true
			m_bleftright = true;

			m_iobjmove = IDLEUSERDMOVE;
			ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
			m_DisTop.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
		}
		else
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_strBitmapTop = "..\\source\\user\\UserIdle_Top2.bmp";
			// 중력 true
			m_bleftright = true;

			m_iobjmove = IDLEUSERDMOVE;
			ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
			m_DisTop.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
		}
	}*/
	

	return;
}




bool PlayerNormal::PlayerPosCheck()
{
	RECT recClient = ObjManager::GetInstance()->GetRect();
	std::vector<Object*> vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_BG);

	Background* bgtemp = (Background*)vectemp[EOBJECT_BG];

	bool btemp = false;

	// 좌우 확인 
	if (m_DisTop.ptDestPos.x <= (recClient.right / 2) - (m_ImgTop.ptSrcSize.x))
	{
		btemp = false;
	}
	else if (bgtemp->GetBG().ptSrcPos.x >= BGEND)
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
	if (m_bjump == true)
	{
		switch (m_iobjstate)
		{
			// 멈춤 상태
		case E_USERSTATE_IDLE:
		{
			m_bmove = false;
		}
		break;
		case E_USERSTATE_RWALK:
			// 오른쪽 버튼 눌렀을 때 반응
		{
			// 화면 밖으로 나갈 수 없도록
			if (ObjManager::GetInstance()->GetRect().right - (m_DisTop.ptSrcPos.x * PLAYERSIZE) <= (m_DisTop.ptDestPos.x))
			{
				break;
			}
			else
			{
				// 플레이어가 화면 중앙에 위치한 것이 아닐 때
				if (PlayerPosCheck() == false)
				{
					m_bmove = false;

					m_DisTop.ptDestPos.x += IDLEUSERDMOVE;
					m_DisBot.ptDestPos.x += IDLEUSERDMOVE;
				}
				// 플레이어가 화면 중앙에 위치할 때
				else
				{
					m_bmove = true;
				}
			}
		}
		break;
		case E_USERSTATE_LWALK:
			// 왼쪽 버튼 눌렀을 때 반응
		{
			// client 밖으로 못 나가도록 
			if (ObjManager::GetInstance()->GetRect().left >= m_DisTop.ptDestPos.x)
			{
				break;
			}
			else
			{
				m_bmove = false;

				m_DisTop.ptDestPos.x -= IDLEUSERDMOVE;
				m_DisBot.ptDestPos.x -= IDLEUSERDMOVE;
			}
		}
		break;
		}
	}
	else
	{
		switch (m_iobjstate)
		{
			// 멈춤 상태
		case E_USERSTATE_IDLE:
		{
			m_bmove = false;
		}
		break;
		case E_USERSTATE_RWALK:
			// 오른쪽 버튼 눌렀을 때 반응
		{
			// 화면 밖으로 나갈 수 없도록
			if (ObjManager::GetInstance()->GetRect().right - (m_DisTop.ptSrcPos.x * PLAYERSIZE) <= (m_DisTop.ptDestPos.x))
			{
				break;
			}
			else
			{
				// 플레이어가 화면 중앙에 위치한 것이 아닐 때
				if (PlayerPosCheck() == false)
				{
					m_bmove = false;

					m_DisTop.ptDestPos.x += IDLEUSERDMOVE;
					m_DisBot.ptDestPos.x += IDLEUSERDMOVE;
				}
				// 플레이어가 화면 중앙에 위치할 때
				else
				{
					m_bmove = true;
				}
			}
		}
		break;
		case E_USERSTATE_LWALK:
			// 왼쪽 버튼 눌렀을 때 반응
		{
			// client 밖으로 못 나가도록 
			if (ObjManager::GetInstance()->GetRect().left >= m_DisTop.ptDestPos.x)
			{
				break;
			}
			else
			{
				m_bmove = false;

				m_DisTop.ptDestPos.x -= IDLEUSERDMOVE;
				m_DisBot.ptDestPos.x -= IDLEUSERDMOVE;
			}
		}
		break;
		}
	}


	m_fdelay = 0.5;

	// 시간을 받아옴
	m_dcurTime = timeGetTime();

	// 만약 이전 시간에서 현재 시간이 0.1float 지났을 때 
	if (m_dcurTime - m_dPrevTime >= 0.1f * m_fdelay)
	{
		// 내부에서 SetDisplayInfo를 호출하게 한다
		Aniimage(m_DisTop, m_ImgTop);
		Aniimage(m_DisBot, m_ImgBot);

		// 이전 시간을 현재 시간으로 대체
		m_dPrevTime = m_dcurTime;
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

	// jump 체크하고 실행
	if (m_bjump == true)
	{
		Jump();
	}
	// fire 실행
	if (m_bfire == true)
	{
		AttackGun();
	}

	AnimationStateMove();


	// #임시 - 필요하다면 수정하기
	// bottom hitbox 정의시켜주기 
	m_recHitBox = { m_DisBot.ptDestPos.x, m_DisBot.ptDestPos.y,
		m_DisBot.ptDestPos.x + (m_DisBot.ptDestSize.x * PLAYERSIZE),
		m_DisBot.ptDestPos.y + (m_DisBot.ptDestSize.y * PLAYERSIZE) };
	// #임시
	Gravity(&m_DisBot, EOBJECT_USER);

	// top hitbox 정의시켜주기 
	m_recHitBox = { m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		m_DisTop.ptDestPos.x + (m_DisTop.ptDestSize.x * PLAYERSIZE),
		m_DisTop.ptDestPos.y + (m_DisTop.ptDestSize.y * PLAYERSIZE) };
	Gravity(&m_DisTop, EOBJECT_USER);

	// #임시 - 상체와 하체가 분리되는 것 막아주기
	m_DisBot.ptDestPos.y = m_DisTop.ptDestPos.y;

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
	hbottomobjBit = (HBITMAP)LoadImage(NULL, m_strBitmapBottom, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// oldbit 에 이미지 저장 
	holdBit = (HBITMAP)SelectObject(hobjdc, hbottomobjBit);

	// 하체 이미지 출력
	TransparentBlt(_hdc, m_DisBot.ptDestPos.x, m_DisBot.ptDestPos.y,
		m_DisBot.ptDestSize.x * PLAYERSIZE, m_DisBot.ptDestSize.y * PLAYERSIZE,
		hobjdc, m_DisBot.ptSrcPos.x, m_DisBot.ptSrcPos.y,
		m_DisBot.ptDestSize.x, m_DisBot.ptDestSize.y, RGB(255, 255, 255));

	// 비트맵을 hBIt에 뿌려주기
	// hinst를 null로 하지 말자 
	htopobjBit = (HBITMAP)LoadImage(NULL, m_strBitmapTop , IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// oldbit 에 상체 이미지 저장 
	holdBit = (HBITMAP)SelectObject(hobjdc, htopobjBit);

	// 상체 이미지 출력
	TransparentBlt(_hdc, m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		m_DisTop.ptDestSize.x * PLAYERSIZE, m_DisTop.ptDestSize.y * PLAYERSIZE,
		hobjdc, m_DisTop.ptSrcPos.x, m_DisTop.ptSrcPos.y,
		m_ImgTop.ptSrcSize.x, m_ImgTop.ptSrcSize.y, RGB(255, 255, 255));

	
	// 플레이어 하체 출력
	/*Rectangle(_hdc, m_DisBot.ptDestPos.x, m_DisBot.ptDestPos.y,
		(m_DisBot.ptDestSize.x * PLAYERSIZE) + m_DisBot.ptDestPos.x, 
		(m_DisBot.ptDestSize.y * PLAYERSIZE) + m_DisBot.ptDestPos.y);*/

	// 플레이어 상체 출력
	/*Rectangle(_hdc, m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		(m_DisTop.ptDestSize.x * PLAYERSIZE) + m_DisTop.ptDestPos.x, 
		(m_DisTop.ptDestSize.y * PLAYERSIZE) + m_DisTop.ptDestPos.y);*/

	// 히트박스 디스플레이
	//Rectangle(_hdc, m_recHitBox.left, m_recHitBox.top, m_recHitBox.right, m_recHitBox.bottom);

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
	Player::AttackGun();
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

