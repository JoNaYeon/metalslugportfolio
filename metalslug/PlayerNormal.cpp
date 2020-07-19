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

	m_itopBitmapImg = USERIDLETOP0;
	m_ibottomBitmapImg = USERIDLEBOTTOM1;
	m_fdelay = 1;

	m_bleftright = true;

	return;
}



void PlayerNormal::AnimationStateCheck()
{
	// bottom ����
	// ������ �� 
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
	// ������
	else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
	{
		m_iobjstate = E_USERSTATE_RWALK;
		m_ibottomBitmapImg = USERRUNBOTTOM1;
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


	// top ����
	// ���� �� �� 
	if (InputManager::GetInstance()->Keyboard(E_KEYFIRE) == true)
	{
		// ������ �������� �߻� 
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_FIRE;
			m_itopBitmapImg = USERFIRETOP1;

			// struct�� �ڷ� �������ִ� �Լ�
			SetObjStruct(m_normalplayertop, FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
				FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, FIREUSERDMOVE,
				FIREPLAYERWNUM, FIREPLAYERHNUM);
		}
		// ���� �������� �߻� 
		else
		{
			m_iobjstate = E_USERSTATE_FIRE;
			m_itopBitmapImg = USERFIRETOP1;

			SetObjStruct(m_normalplayertop, FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
				FIREPLAYERWANIMATION, FIREPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, FIREUSERDMOVE,
				FIREPLAYERWNUM, FIREPLAYERHNUM);
		}
	}
	// ������ �� 
	else if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{

	}
	// ����
	else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
	{
		m_iobjstate = E_USERSTATE_LWALK;
		m_itopBitmapImg = USERIDLETOP2;
		m_bleftright = false;

		SetObjStruct(m_normalplayertop, IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
			IDLEPLAYERWANIMATION, IDLEPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, IDLEUSERDMOVE,
			IDLEPLAYERWNUM, IDLEPLAYERHNUM);
	}
	// ������
	else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
	{
		m_iobjstate = E_USERSTATE_RWALK;
		m_itopBitmapImg = USERIDLETOP0;
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
			// ���� ����
		case E_USERSTATE_IDLE:
		{
			// �̹��� �����̴� �Լ� 
			Aniimage(m_normalplayertop);
		}
		break;
		case E_USERSTATE_RWALK:
		{
			// ������ ��ư ������ �� ����
			// �̹��� �����̴� �Լ� 
			Aniimage(m_normalplayertop);

			if (m_normalplayertop.posoriginDest.x >= (recclient.right - (m_normalplayertop.recDest.right * m_normalplayertop.iWidthnum)))
				// ���� ��ü�� client �̻� ���� ���� �� ������ �� 
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
			// ���� ��ư ������ �� ����
			// �̹��� �����̴� �Լ� 
			Aniimage(m_normalplayertop);

			if (m_normalplayertop.posoriginDest.x <= recclient.left)
				// ���� ��ü�� client �̻� ���� �� �� ������ �� 
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
			// �̹��� �����̴� �Լ� 
			Aniimage(m_normalplayertop);
		}
		break;
		case E_USERSTATE_FIRE:
		{
			// �̹��� �����̴� �Լ� 
			Aniimage(m_normalplayertop);

			// �Ѿ� ��ü ���� 
			Object* objbullet = new Bullet(m_normalplayertop.posoriginDest);
			ObjManager::GetInstance()->SetVector(objbullet, EOBJECT_BULLET);

		}
		break;
	}


	// bottom
	switch (m_iobjstate)
		{
			// ���� ����
		case E_USERSTATE_IDLE:
		{
			// �̹��� �����̴� �Լ� 
			Aniimage(m_normalplayerbottom);
		}
		break;
		case E_USERSTATE_RWALK:
		{
			// ������ ��ư ������ �� ����
			// �̹��� �����̴� �Լ� 
			Aniimage(m_normalplayerbottom);

			if (m_normalplayerbottom.posoriginDest.x >= (recclient.right - (m_normalplayerbottom.recDest.right * m_normalplayerbottom.iWidthnum)))
				// ���� ��ü�� client �̻� ���� ���� �� ������ �� 
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
			// �̹��� �����̴� �Լ� 
			Aniimage(m_normalplayerbottom);

			if (m_normalplayerbottom.posoriginDest.x <= recclient.left)
				// ���� ��ü�� client �̻� ���� �� �� ������ �� 
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
			// �̹��� �����̴� �Լ� 
			Aniimage(m_normalplayerbottom);
		}
		break;
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
	AnimationStateMove();


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
	hbottomobjBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(m_ibottomBitmapImg));
	// oldbit �� �̹��� ���� 
	holdBit = (HBITMAP)SelectObject(hobjdc, hbottomobjBit);

	// ��ü �̹��� ���
	TransparentBlt(_hdc, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y,
		m_normalplayerbottom.recDest.right * PLAYERSIZE, m_normalplayerbottom.recDest.bottom * PLAYERSIZE,
		hobjdc, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
		m_normalplayerbottom.recSrc.right, m_normalplayerbottom.recSrc.bottom, RGB(255, 255, 255));


	// ��Ʈ���� hBIt�� �ѷ��ֱ�
	// hinst�� null�� ���� ���� 
	htopobjBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(m_itopBitmapImg));
	// oldbit �� ��ü �̹��� ���� 
	holdBit = (HBITMAP)SelectObject(hobjdc, htopobjBit);

	// ��ü �̹��� ���
	TransparentBlt(_hdc, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y,
		m_normalplayertop.recDest.right * 4, m_normalplayertop.recDest.bottom * 4,
		hobjdc, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
		m_normalplayertop.recSrc.right, m_normalplayertop.recSrc.bottom, RGB(255, 255, 255));
	

	// �ð��� �޾ƿ�
	m_dcurTime = timeGetTime();

	// ���� ���� �ð����� ���� �ð��� 0.1float ������ �� 
	if (m_dcurTime - m_dPrevTime >= 0.1f * m_fdelay)
	{
		// object ���� ������ ���� 
		Animation(_hdc, m_normalplayertop, m_iobjstate);
		Animation(_hdc, m_normalplayerbottom, m_iobjstate);

		// ���� �ð��� ���� �ð����� ��ü
		m_dPrevTime = m_dcurTime;
	}

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
	return;
};


bool PlayerNormal::bObjDead()
{
	return false;
}

