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

	// ��ü ����ü ����
	m_normalplayertop.recSrc = { 0, 0, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };
	m_normalplayertop.poriginSrc = { 0, 0 };
	m_normalplayertop.recDest = { 0, 0, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION };
	m_normalplayertop.posoriginDest = { 0, 500 };
	m_normalplayertop.iobjmove = IDLEUSERDMOVE;
	m_normalplayertop.iWidthnum = IDLEPLAYERWNUM;
	m_normalplayertop.iHightnum = IDLEPLAYERHNUM;
	// ��ü ����ü ����
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



// � �ִϸ��̼��� ������ üũ���ִ� �Լ�
void PlayerNormal::AnimationStateCheck()
{
	//////////////////////////////////// bottom ����
	// ������ �� 
	if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{
		/*m_iobjstate = E_USERSTATE_JUMP;
		m_strBitmapBottom = "..\\source\\user\\userjunp.bmp";

		SetObjStruct(m_normalplayerbottom, JUMPPLAYERWANIMATION, JUMPPLAYERHANIMATION, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
			JUMPPLAYERWANIMATION, JUMPPLAYERHANIMATION, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y, JUMPUSERDMOVE,
			JUMPPLAYERWNUM, JUMPPLAYERHNUM);*/

		m_bjump = true;
	}
	// ���� 
	else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
	{
		m_iobjstate = E_USERSTATE_LWALK;
		m_strBitmapBottom = "..\\source\\user\\UserRun_Bottom2.bmp";
		m_bleftright = false;

		SetObjStruct(m_normalplayerbottom, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
			IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y, IDLEUSERDMOVE,
			IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// ������
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
	// �ƹ��͵� �ƴ� �� 
	else
	{
		// bool ���� Ȥ�� enum ���� �¿� ��ġ Ȯ�����ֱ�
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


	//////////////////////////////////////// top ����
	// ���� �� �� 
	if (InputManager::GetInstance()->Keyboard(E_KEYFIRE) == true)
	{
		// ������ �������� �߻� 
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_FIRE;
			//m_itopBitmapImg = USERFIRETOP1;
			m_strBitmapTop = "..\\source\\user\\usertopfire.bmp";

			// struct�� �ڷ� �������ִ� �Լ�
			SetObjStruct(m_normalplayertop, FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
				FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, FIREUSERDMOVE,
				FIREPLAYERWNUM, FIREPLAYERHNUM);
		}
		// ���� �������� �߻� 
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
	// ������ �� 
	else if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{
		/*m_iobjstate = E_USERSTATE_JUMP;
		//m_itopBitmapImg = USERIDLETOP2;
		m_strBitmapTop = "..\\source\\user\\userjunptop.bmp";

		SetObjStruct(m_normalplayertop, JUMPPLAYERWANIMATION, JUMPPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
			JUMPPLAYERWANIMATION, JUMPPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, JUMPUSERDMOVE,
			JUMPPLAYERWNUM, JUMPPLAYERHNUM);*/

	}
	// ����
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
	// ������
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
	// �ƹ��͵� �ƴ� �� 
	else
	{
		// bool ���� Ȥ�� enum ���� �¿� ��ġ Ȯ�����ֱ�
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

	// �¿� Ȯ�� 
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
				// ��� �����̱�
				std::vector<Object*> vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_BG);

				for (int i = 0; i < vectemp.size(); i++)
				{
					Background* bgtemp = (Background*)vectemp[i];
					//Monster* monstertemp = (Monster*)vectemp[i];
					bgtemp->BackgroundMove(E_USERSTATE_RWALK);
				}

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
		// ����
		{
			m_bjump = true;
		}
		break;
		case E_USERSTATE_FIRE:
		// �Ѿ� �߻�
		{
			Object* objbullet = new Bullet(m_normalplayertop.posoriginDest);
			ObjManager::GetInstance()->SetVector(objbullet, EOBJECT_BULLET);

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
		Aniimage(m_normalplayertop);
		Aniimage(m_normalplayerbottom);

		// ���� �ð��� ���� �ð����� ��ü
		m_dPrevTime = m_dcurTime;
	}

	return;
}




// rect�� �ε��� ���� Ȯ�����ִ� �Լ�
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
	AnimationStateMove();

	if (m_bjump == true)
	{
		Jump();
	}

	Gravity(&m_normalplayertop);
	Gravity(&m_normalplayerbottom);		// ������ �Լ�, �ذ��� ��� �ؾ��� < �ѽ��̰� �ؾ���

	// ��� ���� �� �� �ְ� ���ִ� �Լ�
	ObjStand(&m_normalplayertop);
	ObjStand(&m_normalplayerbottom);	// �ϳ��� �Լ��� �ذ��� �� �ֵ��� �ϴ� �� ��

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
	//htopobjBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(m_itopBitmapImg));
	htopobjBit = (HBITMAP)LoadImage(NULL, m_strBitmapBottom, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// oldbit �� ��ü �̹��� ���� 
	holdBit = (HBITMAP)SelectObject(hobjdc, htopobjBit);

	// ��ü �̹��� ���
	TransparentBlt(_hdc, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y,
		m_normalplayertop.recDest.right * 4, m_normalplayertop.recDest.bottom * 4,
		hobjdc, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
		m_normalplayertop.recSrc.right, m_normalplayertop.recSrc.bottom, RGB(255, 255, 255));


	// ��Ʈ���� hBIt�� �ѷ��ֱ�
	// hinst�� null�� ���� ���� 
	//hbottomobjBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(m_ibottomBitmapImg));
	hbottomobjBit = (HBITMAP)LoadImage(NULL, m_strBitmapTop, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// oldbit �� �̹��� ���� 
	holdBit = (HBITMAP)SelectObject(hobjdc, hbottomobjBit);

	// ��ü �̹��� ���
	TransparentBlt(_hdc, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y,
		m_normalplayerbottom.recDest.right * PLAYERSIZE, m_normalplayerbottom.recDest.bottom * PLAYERSIZE,
		hobjdc, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
		m_normalplayerbottom.recSrc.right, m_normalplayerbottom.recSrc.bottom, RGB(255, 255, 255));
	

	// ��Ʈ�ڽ� �ӽ� 
	Rectangle(_hdc, m_recHitBox.left, m_recHitBox.top, m_recHitBox.right, m_recHitBox.bottom);

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

