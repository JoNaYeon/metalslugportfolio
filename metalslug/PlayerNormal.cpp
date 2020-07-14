#include "PlayerNormal.h"
#include "RendManager.h"
#include "InputManager.h"
#include "define.h"
#include "Mainfrm.h"
#include "Bullet.h"

MSG* Mainfrm::m_msg;

PlayerNormal::PlayerNormal()
{
	m_iobjstate = E_USERSTATE_IDLE;

	// ��ü ����ü ����
	m_normalplayertop.recSrc = { 0, 0, PLAYERWANIMATION, PLAYERHANIMATION };
	m_normalplayertop.poriginSrc = { 0,0 };
	m_normalplayertop.recDest = { 0, 0, PLAYERWANIMATION, PLAYERHANIMATION };
	m_normalplayertop.posoriginDest = { 0, 500 };
	m_normalplayertop.iobjmove = USERDMOVE;
	m_normalplayertop.iWidthnum = PLAYERWNUM;
	m_normalplayertop.iHightnum = PLAYERHNUM;
	// ��ü ����ü ����
	m_normalplayerbottom.recSrc = { 0, 0, PLAYERWANIMATION, PLAYERHANIMATION };
	m_normalplayerbottom.poriginSrc = { 0,0 };
	m_normalplayerbottom.recDest = { 0, 0, PLAYERWANIMATION, PLAYERHANIMATION };
	m_normalplayerbottom.posoriginDest = { 0, 500 };
	m_normalplayerbottom.iobjmove = USERDMOVE;
	m_normalplayerbottom.iWidthnum = PLAYERWNUM;
	m_normalplayerbottom.iHightnum = PLAYERHNUM;

	m_itopBitmapImg = USERIDLETOP0;
	m_ibottomBitmapImg = USERIDLEBOTTOM1;
	m_fdelay = 1;


	m_bleftright = true;


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
	// ������ �� 
	if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{

	}

	// ���� �� �� 
	if (InputManager::GetInstance()->Keyboard(E_KEYFIRE) == true)
	{
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_itopBitmapImg = USERIDLETOP0;
			m_ibottomBitmapImg = USERIDLEBOTTOM1;
			// �Ѿ� ��ü ���� 
			Object* objbullet = new Bullet;

			RendManager::GetInstance()->SetVector(objbullet, EOBJECT_BULLET);
			DBManager::GetInstance()->SetVector(objbullet, EOBJECT_BULLET);
		}
		else
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_itopBitmapImg = USERIDLETOP2;
			m_ibottomBitmapImg = USERIDLEBOTTOM2;
			// �Ѿ� ��ü ���� 
			Object* objbullet = new Bullet;
			m_vbullet.push_back(objbullet);

			RendManager::GetInstance()->SetVector(objbullet, EOBJECT_BULLET);
			DBManager::GetInstance()->SetVector(objbullet, EOBJECT_BULLET);
			
			/*for (int i = 0; i < m_vbullet.size(); i++)
			{
				RendManager::GetInstance()->SetVector(m_vbullet[i], EOBJECT_BULLET);
				DBManager::GetInstance()->SetVector(m_vbullet[i], EOBJECT_BULLET);
			}*/
		}

	}
	// ���� 
	else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
	{
		m_iobjstate = E_USERSTATE_LWALK;
		m_itopBitmapImg = USERIDLETOP2;
		m_ibottomBitmapImg = USERRUNBOTTOM2;
		m_bleftright = false;
	}
	// ������
	else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
	{
		m_iobjstate = E_USERSTATE_RWALK;
		m_itopBitmapImg = USERIDLETOP0;
		m_ibottomBitmapImg = USERRUNBOTTOM1;
		m_bleftright = true;
	}
	// �ƹ��͵� �ƴ� �� 
	else
	{
		// bool ���� Ȥ�� enum ���� �¿� ��ġ Ȯ�����ֱ�
		if (m_bleftright == true)
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_itopBitmapImg = USERIDLETOP0;
			m_ibottomBitmapImg = USERIDLEBOTTOM1;
		}
		else
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_itopBitmapImg = USERIDLETOP2;
			m_ibottomBitmapImg = USERIDLEBOTTOM2;
		}
	}

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
	RECT recClient = RendManager::GetInstance()->GetRect();
	GetClientRect(_hWnd, &recClient);

	// �̹��� ����� hdc ��� 
	hobjdc = CreateCompatibleDC(_hdc);


	// ��ü �̹����� ������ HBITMAP
	hbottomobjBit = CreateCompatibleBitmap(_hdc,
		m_normalplayerbottom.recSrc.right, m_normalplayerbottom.recSrc.bottom);
	// ��ü �̹����� ������ HBITMAP
	htopobjBit = CreateCompatibleBitmap(_hdc,
		m_normalplayertop.recSrc.right, m_normalplayertop.recSrc.bottom);


	// ��Ʈ���� hBIt�� �ѷ��ֱ�
	// hinst�� null�� ���� ���� 
	hbottomobjBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(m_ibottomBitmapImg));
	// oldbit �� �̹��� ���� 
	holdBit = (HBITMAP)SelectObject(hobjdc, hbottomobjBit);

	// ��ü �̹��� ���
	TransparentBlt(_hdc, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y,
		m_normalplayerbottom.recDest.right * 4, m_normalplayerbottom.recDest.bottom * 4,
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
	for (int i = 0; i < m_vbullet.size(); i++)
	{
		m_vbullet[i] = NULL;
	}
	m_vbullet.clear();

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