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

	// ��ü ����ü ����
	m_DisTop.ptDestPos = { 0, 500 };
	m_DisTop.ptSrcPos = { 0, 0 };
	m_DisTop.ptDestSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };
	
	m_ImgTop.iWidthnum = IDLEPLAYERWNUM;
	m_ImgTop.iHightnum = IDLEPLAYERHNUM;
	m_ImgTop.ptSrcSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };

	// ��ü ����ü ����
	m_DisBot.ptDestPos = { 0, 500 };
	m_DisBot.ptSrcPos = { 0, 0 };
	m_DisBot.ptDestSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };

	m_ImgBot.iWidthnum = IDLEPLAYERWNUM;
	m_ImgBot.iHightnum = IDLEPLAYERHNUM;
	m_ImgBot.ptSrcSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };

	return;
}



// � �ִϸ��̼��� ������ üũ���ִ� �Լ�
void PlayerNormal::AnimationStateCheck()
{
	POINT ptImgSize = { 0, 0 };
	//////////////////////////////////// bottom ����
	// ������ �� 
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
	// ���� 
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
	// ������
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
	// �ƹ��͵� �ƴ� �� 
	else
	{
		// bool ���� Ȥ�� enum ���� �¿� ��ġ Ȯ�����ֱ�
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


	//////////////////////////////////////// top ����
	// ���� �� �� 
	if (InputManager::GetInstance()->Keyboard(E_KEYFIRE) == true)
	{
		// ������ �������� �߻� 
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_FIRE;
			m_strBitmapTop = "..\\source\\user\\usertopfire.bmp";

			// struct�� �ڷ� �������ִ� �Լ�
			m_iobjmove = FIREUSERDMOVE;
			ptImgSize = { FIREPLAYERWANIMATION , FIREPLAYERHANIMATION };
			m_DisTop.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgTop, ptImgSize, FIREPLAYERWNUM, FIREPLAYERHNUM);
		}
		// ���� �������� �߻� 
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
	// ������ �� 
	else if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{
		m_iobjstate = E_USERSTATE_JUMP;
		m_strBitmapTop = "..\\source\\user\\userjunptop.bmp";

		m_iobjmove = JUMPUSERDMOVE;
		ptImgSize = { JUMPPLAYERWANIMATION , JUMPPLAYERHANIMATION };
		m_DisTop.ptDestSize = ptImgSize;
		SetImgInfo(m_ImgTop, ptImgSize, JUMPPLAYERWNUM, JUMPPLAYERHNUM);
	}
	// ����
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
	// ������
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
	// �ƹ��͵� �ƴ� �� 
	else
	{
		// bool ���� Ȥ�� enum ���� �¿� ��ġ Ȯ�����ֱ�
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

	// �¿� Ȯ�� 
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




// �ִϸ��̼��� �������� �������ִ� �Լ�
void PlayerNormal::AnimationStateMove()
{
	/////////////////////////////////// top 
	switch (m_iobjstate)
	{
		// ���� ����
		case E_USERSTATE_IDLE:
		{
		}
		break;
		case E_USERSTATE_RWALK:
		// ������ ��ư ������ �� ����
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
				// ��� �����̱�
				std::vector<Object*> vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_BG);

				for (int i = 0; i < vectemp.size(); i++)
				{
					Background* bgtemp = (Background*)vectemp[i];
					bgtemp->BackgroundMove(E_USERSTATE_RWALK);
				}

				// ���� ������ ���� : õ���� 
				// -> ������
				// ���� �����̱�
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
		// ���� ��ư ������ �� ����
		{
			// client ������ �� �������� 
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
		// ����
		{
			// �̹��� �ѹ��� ���� false�� ������ֱ� 
			if (m_DisTop.ptSrcPos.y >= m_DisTop.ptDestSize.y)
			{
				m_bjump = false;
			}
		}
		break;
		case E_USERSTATE_FIRE:
		// �Ѿ� �߻�
		{
			// �̹��� �ѹ��� ���� false�� ������ֱ� 
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
			// ���� ����
		case E_USERSTATE_IDLE:
		{
		}
		break;
		case E_USERSTATE_RWALK:
		// ������ ��ư ������ �� ����
		{

		}
		break;
		case E_USERSTATE_LWALK:
		// ���� ��ư ������ �� ����
		{
			
		}
		break;
		case E_USERSTATE_JUMP:
		// ����
		{

		}
		break;
	}

	m_fdelay = 0.5;

	// �ð��� �޾ƿ�
	m_dcurTime = timeGetTime();

	// ���� ���� �ð����� ���� �ð��� 0.1float ������ �� 
	if (m_dcurTime - m_dPrevTime >= 0.1f * m_fdelay)
	{
		// ���ο��� SetDisplayInfo�� ȣ���ϰ� �Ѵ�
		Aniimage(m_DisTop, m_ImgTop);
		Aniimage(m_DisBot, m_ImgBot);

		// ���� �ð��� ���� �ð����� ��ü
		m_dPrevTime = m_dcurTime;
	}

	return;
}



// ������Ʈ �ʱ�ȭ (�������̵�)
void PlayerNormal::Init()
{
	return;
};

// ������Ʈ ������ (�������̵�)
void PlayerNormal::Run()
{
	// Ű���� �Է� �ޱ�
	// Ű���� �Է��� �����ؼ� ������ �켱������ ������ �� 

	// jump üũ�ϰ� ����
	if (m_bjump == true)
	{
		Jump();
		// �����̰� �ѽ�� �Լ� �ϳ� �� ����� 
	}
	else if (m_bfire == true)
	{
	}
	else
	{
		AnimationStateCheck();
	}

	AnimationStateMove();

	// hitbox ���ǽ����ֱ� 
	m_recHitBox = { m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		m_DisTop.ptDestPos.x + m_DisTop.ptDestSize.x * PLAYERSIZE,
		m_DisTop.ptDestPos.y + m_DisTop.ptDestSize.y * PLAYERSIZE };

	// ȭ�� �Լ�
	//Gravity(&m_normalplayertop);
	//Gravity(&m_normalplayerbottom);		// ������ �Լ�, �ذ��� ��� �ؾ��� < �ѽ��̰� �ؾ���

	// ȭ�� �Լ�
	// �Լ� �ΰ��� �ϳ��� ���ľ���
	// ��� ���� �� �� �ְ� ���ִ� �Լ�
	//ObjStand(&m_normalplayertop);
	//ObjStand(&m_normalplayerbottom);	// �ϳ��� �Լ��� �ذ��� �� �ֵ��� �ϴ� �� ��

	return;
};

// ������Ʈ ��� (�������̵�)
void PlayerNormal::Render(HDC& _hdc, HWND& _hWnd)
{ 
	// �̹����� hdc
	HDC hobjdc;
	// �̹��� �ε���� hbitmap
	HBITMAP htopobjBit;
	HBITMAP hbottomobjBit;
	// �̹��� ������� hbitmap
	HBITMAP holdBit;
	
	// ���� ���� 
	RECT recClient = ObjManager::GetInstance()->GetRect();
	GetClientRect(_hWnd, &recClient);

	// �̹��� ����� hdc ��� 
	hobjdc = CreateCompatibleDC(_hdc);

	// ��Ʈ���� hBIt�� �ѷ��ֱ�
	// hinst�� null�� ���� ���� 
	hbottomobjBit = (HBITMAP)LoadImage(NULL, m_strBitmapBottom, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// oldbit �� �̹��� ���� 
	holdBit = (HBITMAP)SelectObject(hobjdc, hbottomobjBit);

	// ��ü �̹��� ���
	TransparentBlt(_hdc, m_DisBot.ptDestPos.x, m_DisBot.ptDestPos.y,
		m_DisBot.ptDestSize.x * PLAYERSIZE, m_DisBot.ptDestSize.y * PLAYERSIZE,
		hobjdc, m_DisBot.ptSrcPos.x, m_DisBot.ptSrcPos.y,
		m_DisBot.ptDestSize.x, m_DisBot.ptDestSize.y, RGB(255, 255, 255));

	// ��Ʈ���� hBIt�� �ѷ��ֱ�
	// hinst�� null�� ���� ���� 
	htopobjBit = (HBITMAP)LoadImage(NULL, m_strBitmapTop , IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// oldbit �� ��ü �̹��� ���� 
	holdBit = (HBITMAP)SelectObject(hobjdc, htopobjBit);

	// ��ü �̹��� ���
	TransparentBlt(_hdc, m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		m_DisTop.ptDestSize.x * PLAYERSIZE, m_DisTop.ptDestSize.y * PLAYERSIZE,
		hobjdc, m_DisTop.ptSrcPos.x, m_DisTop.ptSrcPos.y,
		m_ImgTop.ptSrcSize.x, m_ImgTop.ptSrcSize.y, RGB(255, 255, 255));
	
	// �÷��̾� ��ü ���
	/*Rectangle(_hdc, m_DisBot.ptDestPos.x, m_DisBot.ptDestPos.y,
		(m_DisBot.ptDestSize.x * PLAYERSIZE) + m_DisBot.ptDestPos.x, 
		(m_DisBot.ptDestSize.y * PLAYERSIZE) + m_DisBot.ptDestPos.y);*/

	// �÷��̾� ��ü ���
	/*Rectangle(_hdc, m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		(m_DisTop.ptDestSize.x * PLAYERSIZE) + m_DisTop.ptDestPos.x, 
		(m_DisTop.ptDestSize.y * PLAYERSIZE) + m_DisTop.ptDestPos.y);*/

	// ��Ʈ�ڽ� ���÷���
	//Rectangle(_hdc, m_recHitBox.left, m_recHitBox.top, m_recHitBox.right, m_recHitBox.bottom);

	// oldbit�� �ٲ��ֱ�
	SelectObject(hobjdc, holdBit);

	DeleteDC(hobjdc);
	DeleteObject(htopobjBit);
	DeleteObject(hbottomobjBit);

	return;
};

// ������Ʈ �ı� (�������̵�)
void PlayerNormal::Destroy()
{
	return;
};

// ���� �Ǵ� �ִϸ��̼� 
void PlayerNormal::DeadZombie()
{
	return;
};

// ���� - �� (�������̵�)
void PlayerNormal::AttackGun()
{
	return;
};

// ���� - ������ (�������̵�)
void PlayerNormal::AttackKnife()
{
	return;
};

// ���� - ��ź (�������̵�)
void PlayerNormal::AttackBomb()
{
	return;
};

// ���� (�������̵�)
void PlayerNormal::Jump()
{
	Player::Jump();

	return;
};


bool PlayerNormal::bObjDead()
{
	return false;
}

