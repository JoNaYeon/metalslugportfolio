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
	m_iobjmove = IDLEUSERDMOVE;

	m_fdelay = 0.5;
	m_bleftright = true;

	// 상체 구조체 정의
	m_DisTop.ptDestPos = { 0, 500 };
	m_DisTop.ptSrcPos = { 0, 0 };
	m_DisTop.ptDestSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };
	
	m_ImgTop.iWidthnum = IDLEPLAYERWNUM;
	m_ImgTop.iHightnum = IDLEPLAYERHNUM;
	m_ImgTop.ptSrcSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };

	// 하체 구조체 정의
	m_DisBot.ptDestPos = { 0, 500 };
	m_DisBot.ptSrcPos = { 0, 0 };
	m_DisBot.ptDestSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };

	m_ImgBot.iWidthnum = IDLEPLAYERWNUM;
	m_ImgBot.iHightnum = IDLEPLAYERHNUM;
	m_ImgBot.ptSrcSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };

	return;
}



// 어떤 애니메이션이 들어가는지 체크해주는 함수
void PlayerNormal::AnimationStateCheck()
{
	POINT ptImgSize = { 0, 0 };
	//////////////////////////////////// bottom 반응
	// 점프할 때 
	if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{
		m_iobjstate = E_USERSTATE_JUMP;
		m_strBitmapBottom = "..\\source\\user\\userjunp.bmp";

		m_iobjmove = JUMPUSERDMOVE;
		ptImgSize = { JUMPPLAYERWANIMATION , JUMPPLAYERHANIMATION };
		m_DisBot.ptDestSize = ptImgSize;
		SetImgInfo(m_ImgBot, ptImgSize, JUMPPLAYERWNUM, JUMPPLAYERHNUM);

		m_bjump = true;
	}
	// 왼쪽 
	else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
	{
		m_iobjstate = E_USERSTATE_LWALK;
		m_strBitmapBottom = "..\\source\\user\\UserRun_Bottom2.bmp";
		m_bleftright = false;

		m_iobjmove = IDLEUSERDMOVE;
		ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
		m_DisBot.ptDestSize = ptImgSize;
		SetImgInfo(m_ImgBot, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// 오른쪽
	else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
	{
		m_iobjstate = E_USERSTATE_RWALK;
		m_strBitmapBottom = "..\\source\\user\\UserRun_Bottom1.bmp";
		m_bleftright = true;

		m_iobjmove = IDLEUSERDMOVE;
		ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
		m_DisBot.ptDestSize = ptImgSize;
		SetImgInfo(m_ImgBot, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// 아무것도 아닐 때 
	else
	{
		// bool 변수 혹은 enum 으로 좌우 위치 확인해주기
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_strBitmapBottom = "..\\source\\user\\UserIdle_Bottom1.bmp";

			m_iobjmove = IDLEUSERDMOVE;
			ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
			m_DisBot.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgBot, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
		}
		else
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_strBitmapBottom = "..\\source\\user\\UserIdle_Bottom2.bmp";

			m_iobjmove = IDLEUSERDMOVE;
			ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
			m_DisBot.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgBot, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
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
			
			m_iobjmove = FIREUSERDMOVE;
			ptImgSize = { FIREPLAYERWANIMATION , FIREPLAYERHANIMATION };
			m_DisTop.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgTop, ptImgSize, FIREPLAYERWNUM, FIREPLAYERHNUM);
		}

		m_bfire = true;
	}
	// 점프할 때 
	else if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{
		m_iobjstate = E_USERSTATE_JUMP;
		m_strBitmapTop = "..\\source\\user\\userjunptop.bmp";

		m_iobjmove = JUMPUSERDMOVE;
		ptImgSize = { JUMPPLAYERWANIMATION , JUMPPLAYERHANIMATION };
		m_DisTop.ptDestSize = ptImgSize;
		SetImgInfo(m_ImgTop, ptImgSize, JUMPPLAYERWNUM, JUMPPLAYERHNUM);
	}
	// 왼쪽
	else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
	{
		m_iobjstate = E_USERSTATE_LWALK;
		m_strBitmapTop = "..\\source\\user\\UserIdle_Top2.bmp";
		m_bleftright = false;

		m_iobjmove = IDLEUSERDMOVE;
		ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
		m_DisTop.ptDestSize = ptImgSize;
		SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// 오른쪽
	else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
	{
		m_iobjstate = E_USERSTATE_RWALK;
		m_strBitmapTop = "..\\source\\user\\UserIdle_Top1.bmp";
		m_bleftright = true;

		m_iobjmove = IDLEUSERDMOVE;
		ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
		m_DisTop.ptDestSize = ptImgSize;
		SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// 아무것도 아닐 때 
	else
	{
		// bool 변수 혹은 enum 으로 좌우 위치 확인해주기
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_strBitmapTop = "..\\source\\user\\UserIdle_Top1.bmp";

			m_iobjmove = IDLEUSERDMOVE;
			ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
			m_DisTop.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
		}
		else
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_strBitmapTop = "..\\source\\user\\UserIdle_Top2.bmp";

			m_iobjmove = IDLEUSERDMOVE;
			ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
			m_DisTop.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
		}
	}


	return;
}




bool PlayerNormal::PlayerPosCheck()
{
	RECT recClient = ObjManager::GetInstance()->GetRect();
	std::vector<Object*> vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_BG);

	Background* bgtemp = (Background*)vectemp[EOBJECT_BG];

	bool btemp = false;

	// 좌우 확인 
	if (m_DisTop.ptDestPos.x <= (recClient.right / 2) - (m_ImgTop.ptSrcSize.x * PLAYERSIZE))
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
			if (ObjManager::GetInstance()->GetRect().right - (m_DisTop.ptSrcPos.x * PLAYERSIZE) <= (m_DisTop.ptDestPos.x))
			{
				break;
			}
			else if (PlayerPosCheck() == false)
			{
				m_DisTop.ptDestPos.x += IDLEUSERDMOVE;
				m_DisBot.ptDestPos.x += IDLEUSERDMOVE;
			}
			else
			{
				// 배경 움직이기
				std::vector<Object*> vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_BG);

				for (int i = 0; i < vectemp.size(); i++)
				{
					Background* bgtemp = (Background*)vectemp[i];
					bgtemp->BackgroundMove(E_USERSTATE_RWALK);
				}

				// 지금 게임의 원리 : 천동설 
				// -> 지동설
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
			if (ObjManager::GetInstance()->GetRect().left >= m_DisTop.ptDestPos.x)
			{
				break;
			}
			else
			{
				m_DisTop.ptDestPos.x -= IDLEUSERDMOVE;
				m_DisBot.ptDestPos.x -= IDLEUSERDMOVE;
			}
		}
		break;
		case E_USERSTATE_JUMP:
		// 점프
		{
			// 이미지 한바퀴 돌면 false로 만들어주기 
			if (m_DisTop.ptSrcPos.y >= m_DisTop.ptDestSize.y)
			{
				m_bjump = false;
			}
		}
		break;
		case E_USERSTATE_FIRE:
		// 총알 발사
		{
			// 이미지 한바퀴 돌면 false로 만들어주기 
			if (m_DisTop.ptSrcPos.y >= m_DisTop.ptDestSize.y)
			{
				Object* objbullet = new Bullet(m_DisTop.ptDestPos);
				ObjManager::GetInstance()->SetVector(objbullet, EOBJECT_BULLET);

				m_bfire = false;
			}
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

	// jump 체크하고 실행
	if (m_bjump == true)
	{
		Jump();
		// 움직이고 총쏘는 함수 하나 더 만들기 
	}
	else if (m_bfire == true)
	{
	}
	else
	{
		AnimationStateCheck();
	}

	AnimationStateMove();

	// hitbox 정의시켜주기 
	m_recHitBox = { m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		m_DisTop.ptDestPos.x + m_DisTop.ptDestSize.x * PLAYERSIZE,
		m_DisTop.ptDestPos.y + m_DisTop.ptDestSize.y * PLAYERSIZE };

	// 화이 함수
	//Gravity(&m_normalplayertop);
	//Gravity(&m_normalplayerbottom);		// 껍데기 함수, 해결방안 고안 해야함 < 한슬이가 해야함

	// 화이 함수
	// 함수 두개를 하나로 합쳐야함
	// 배경 위에 설 수 있게 해주는 함수
	//ObjStand(&m_normalplayertop);
	//ObjStand(&m_normalplayerbottom);	// 하나의 함수로 해결할 수 있도록 하는 것 ☆

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

