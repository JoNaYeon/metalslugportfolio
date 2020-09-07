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
	// �߷� �ޱ�
	m_bgravity = true;
	
	// �÷��̾� ��� �����̱�
	m_bmove = false;

	// ��ü ����ü ����
	m_DisTop.ptDestPos = { 0, 400 };
	m_DisTop.ptSrcPos = { 0, 0 };
	m_DisTop.ptDestSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };
	
	m_ImgTop.iWidthnum = IDLEPLAYERWNUM;
	m_ImgTop.iHightnum = IDLEPLAYERHNUM;
	m_ImgTop.ptSrcSize = { IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };

	// ��ü ����ü ����
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



// � �ִϸ��̼��� ������ üũ���ִ� �Լ�
void PlayerNormal::AnimationStateCheck()
{
	POINT ptImgSize = { 0, 0 };


	// �ѹ� ���� �� ������ ���̴� �̹�����
	// �������� �� 
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

		// �� �� �� 
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

				m_iobjmove = -FIREUSERDMOVE;
				ptImgSize = { FIREPLAYERWANIMATION , FIREPLAYERHANIMATION };
				m_DisTop.ptDestSize = ptImgSize;
				SetImgInfo(m_ImgTop, ptImgSize, FIREPLAYERWNUM, FIREPLAYERHNUM);
			}
			m_bfire = true;
		}
		// ���� �������� �����̱�
		else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
		{
			// �߷� true
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
		// ������ �������� �����̱�
		else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
		{
			// �߷� true
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
	// �������� �ƴ� ��
	else
	{
		// �� �� �� 
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

				m_iobjmove = -FIREUSERDMOVE;
				ptImgSize = { FIREPLAYERWANIMATION , FIREPLAYERHANIMATION };
				m_DisTop.ptDestSize = ptImgSize;
				SetImgInfo(m_ImgTop, ptImgSize, FIREPLAYERWNUM, FIREPLAYERHNUM);
			}

			m_bfire = true;
		}
		// ������ �� 
		else if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
		{
			// �߷� false
			m_bleftright = false;
			// ���� true
			m_bjump = true;
		}
		// ���� �������� �����̱�
		else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
		{
			// �߷� true
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
		// ������ �������� �����̱�
		else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
		{
			// �߷� true
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
			// bool ���� Ȥ�� enum ���� �¿� ��ġ Ȯ�����ֱ�
			if (m_bleftright == true)
			{
				// �߷� true
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
				// �߷� true
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
	
	//////////////////////////////////////// top ����
	/*// ���� �� �� 
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
			
			m_iobjmove = -FIREUSERDMOVE;
			ptImgSize = { FIREPLAYERWANIMATION , FIREPLAYERHANIMATION };
			m_DisTop.ptDestSize = ptImgSize;
			SetImgInfo(m_ImgTop, ptImgSize, FIREPLAYERWNUM, FIREPLAYERHNUM);
		}

		m_bfire = true;
	}
	// ������ �� 
	else if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{
		// �߷� false
		m_bleftright = false;
		// ���� true
		m_bjump = true;

	}
	// �������� �ȱ�
	else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
	{
		m_iobjstate = E_USERSTATE_LWALK;
		m_strBitmapTop = "..\\source\\user\\UserIdle_Top2.bmp";
		// �߷� true
		m_bleftright = true;

		m_iobjmove = IDLEUSERDMOVE;
		ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
		m_DisTop.ptDestSize = ptImgSize;
		SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// ���������� �ȱ�
	else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
	{
		m_iobjstate = E_USERSTATE_RWALK;
		m_strBitmapTop = "..\\source\\user\\UserIdle_Top1.bmp";
		// �߷� true
		m_bleftright = true;

		m_iobjmove = IDLEUSERDMOVE;
		ptImgSize = { IDLEPLAYERWANIMATION , IDLEPLAYERHANIMATION };
		m_DisTop.ptDestSize = ptImgSize;
		SetImgInfo(m_ImgTop, ptImgSize, IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// IDLE
	else
	{
		// bool ���� Ȥ�� enum ���� �¿� ��ġ Ȯ�����ֱ�
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_strBitmapTop = "..\\source\\user\\UserIdle_Top1.bmp";
			// �߷� true
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
			// �߷� true
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

	// �¿� Ȯ�� 
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




// �ִϸ��̼��� �������� �������ִ� �Լ�
void PlayerNormal::AnimationStateMove()
{
	if (m_bjump == true)
	{
		switch (m_iobjstate)
		{
			// ���� ����
		case E_USERSTATE_IDLE:
		{
			m_bmove = false;
		}
		break;
		case E_USERSTATE_RWALK:
			// ������ ��ư ������ �� ����
		{
			// ȭ�� ������ ���� �� ������
			if (ObjManager::GetInstance()->GetRect().right - (m_DisTop.ptSrcPos.x * PLAYERSIZE) <= (m_DisTop.ptDestPos.x))
			{
				break;
			}
			else
			{
				// �÷��̾ ȭ�� �߾ӿ� ��ġ�� ���� �ƴ� ��
				if (PlayerPosCheck() == false)
				{
					m_bmove = false;

					m_DisTop.ptDestPos.x += IDLEUSERDMOVE;
					m_DisBot.ptDestPos.x += IDLEUSERDMOVE;
				}
				// �÷��̾ ȭ�� �߾ӿ� ��ġ�� ��
				else
				{
					m_bmove = true;
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
			// ���� ����
		case E_USERSTATE_IDLE:
		{
			m_bmove = false;
		}
		break;
		case E_USERSTATE_RWALK:
			// ������ ��ư ������ �� ����
		{
			// ȭ�� ������ ���� �� ������
			if (ObjManager::GetInstance()->GetRect().right - (m_DisTop.ptSrcPos.x * PLAYERSIZE) <= (m_DisTop.ptDestPos.x))
			{
				break;
			}
			else
			{
				// �÷��̾ ȭ�� �߾ӿ� ��ġ�� ���� �ƴ� ��
				if (PlayerPosCheck() == false)
				{
					m_bmove = false;

					m_DisTop.ptDestPos.x += IDLEUSERDMOVE;
					m_DisBot.ptDestPos.x += IDLEUSERDMOVE;
				}
				// �÷��̾ ȭ�� �߾ӿ� ��ġ�� ��
				else
				{
					m_bmove = true;
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
				m_bmove = false;

				m_DisTop.ptDestPos.x -= IDLEUSERDMOVE;
				m_DisBot.ptDestPos.x -= IDLEUSERDMOVE;
			}
		}
		break;
		}
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

	AnimationStateCheck();

	// jump üũ�ϰ� ����
	if (m_bjump == true)
	{
		Jump();
	}
	// fire ����
	if (m_bfire == true)
	{
		AttackGun();
	}

	AnimationStateMove();


	// #�ӽ� - �ʿ��ϴٸ� �����ϱ�
	// bottom hitbox ���ǽ����ֱ� 
	m_recHitBox = { m_DisBot.ptDestPos.x, m_DisBot.ptDestPos.y,
		m_DisBot.ptDestPos.x + (m_DisBot.ptDestSize.x * PLAYERSIZE),
		m_DisBot.ptDestPos.y + (m_DisBot.ptDestSize.y * PLAYERSIZE) };
	// #�ӽ�
	Gravity(&m_DisBot, EOBJECT_USER);

	// top hitbox ���ǽ����ֱ� 
	m_recHitBox = { m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		m_DisTop.ptDestPos.x + (m_DisTop.ptDestSize.x * PLAYERSIZE),
		m_DisTop.ptDestPos.y + (m_DisTop.ptDestSize.y * PLAYERSIZE) };
	Gravity(&m_DisTop, EOBJECT_USER);

	// #�ӽ� - ��ü�� ��ü�� �и��Ǵ� �� �����ֱ�
	m_DisBot.ptDestPos.y = m_DisTop.ptDestPos.y;

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
	Player::AttackGun();
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

