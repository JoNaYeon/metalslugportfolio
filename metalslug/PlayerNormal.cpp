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
	m_normalplayertop.poriginSrc = { 100,100 };
	m_normalplayertop.recDest = { 0, 0, PLAYERWANIMATION, PLAYERHANIMATION };
	// ��ü ����ü ����
	m_normalplayerbottom.recSrc = { 0, 0, PLAYERWANIMATION, PLAYERHANIMATION };
	m_normalplayerbottom.poriginSrc = { 100,100 };
	m_normalplayerbottom.recDest = { 0, 0, PLAYERWANIMATION, PLAYERHANIMATION };

	m_itopBitmapImg = USERIDLETOP0;
	m_ibottomBitmapImg = USERIDLEBOTTOM1;

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
			m_vbullet.push_back(objbullet);


			// �Ѿ� ��ü vector �� �־��ֱ� 
			for (int i = 0; i < m_vbullet.size(); i++)
			{
				RendManager::GetInstance()->SetVector(m_vbullet[i], EOBJECT_OBJ);
				DBManager::GetInstance()->SetVector(m_vbullet[i], EOBJECT_OBJ);
			}
		}
		else
		{
			m_iobjstate = E_USERSTATE_IDLE;
			m_itopBitmapImg = USERIDLETOP2;
			m_ibottomBitmapImg = USERIDLEBOTTOM2;
			// �Ѿ� ��ü ���� 
			Object* objbullet = new Bullet;
			m_vbullet.push_back(objbullet);

			for (int i = 0; i < m_vbullet.size(); i++)
			{
				RendManager::GetInstance()->SetVector(m_vbullet[i], EOBJECT_OBJ);
				DBManager::GetInstance()->SetVector(m_vbullet[i], EOBJECT_OBJ);
			}
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
		m_normalplayerbottom.recSrc.right * 4, m_normalplayerbottom.recSrc.bottom * 4,
		hobjdc, m_normalplayerbottom.recDest.left, m_normalplayerbottom.recDest.top,
		m_normalplayerbottom.recSrc.right, m_normalplayerbottom.recSrc.bottom, RGB(255, 255, 255));


	// ��Ʈ���� hBIt�� �ѷ��ֱ�
	// hinst�� null�� ���� ���� 
	htopobjBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(m_itopBitmapImg));
	// oldbit �� ��ü �̹��� ���� 
	holdBit = (HBITMAP)SelectObject(hobjdc, htopobjBit);

	// ��ü �̹��� ���
	TransparentBlt(_hdc, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y,
		m_normalplayertop.recSrc.right * 4, m_normalplayertop.recSrc.bottom * 4,
		hobjdc, m_normalplayertop.recDest.left, m_normalplayertop.recDest.top,
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

