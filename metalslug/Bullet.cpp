#include "Bullet.h"
#include "InputManager.h"
#include "ObjManager.h"
#include "define.h"


Bullet::Bullet(POINT _playerpos)
{
	// dest = ��� , src = ����
	// ȭ�� �󿡼� ��𿡼����� �̹����� ����� ������ ���� 
	m_bullet.posoriginDest = { _playerpos.x + (FIREPLAYERWANIMATION * 3), _playerpos.y + (FIREPLAYERHANIMATION)};
	// ȭ��󿡼��� �̹��� ����/�ʺ� ����
	// left top right bottom
	m_bullet.recDest = { 0, 0, BULLETSIZE, BULLETSIZE };
	// �̹��� ��󿡼� ��� ��ǥ�������� ����� ������ ����
	m_bullet.poriginSrc = { 0, 0 };
	// ����� �̹����� ���� ũ��� ������� ����
	m_bullet.recSrc = { 0, 0, BULLETSIZE, BULLETSIZE };
	m_bullet.iobjmove = BULLETMOVE;
	m_bullet.iWidthnum = BULLETWNUM;
	m_bullet.iHightnum = BULLETHNUM;

	m_fdelay = 0.2;
	
	m_iobjstate = E_GUNSTATE_NORMAL;
};


// ������Ʈ �ʱ�ȭ
void Bullet::Init()
{
	return;
};

// ������Ʈ ������
void Bullet::Run()
{
	// Object ����
	switch (m_iobjstate)
	{
		case E_GUNSTATE_NORMAL:
		{
			// �� �߻� ��ư (A) ������ ���� �Լ� ;
			// �̹��� �����̴� �Լ� 
			//Aniimage(_obj);

			// �Ѿ� �߻��Ű�� 
			m_bullet.posoriginDest.x += m_bullet.iobjmove;


			// �Ѿ� ���� �� ������ ObjManager ���� ���ְ� ����. 
		}
	break;
	}

	return;
};

// ������Ʈ ���
void Bullet::Render(HDC& _hdc, HWND& _hWnd)
{
	// �̹����� ���� HDC
	HDC hMemdc = NULL;
	// �̹����� ���� hbitmap
	HBITMAP hbit = NULL;
	HBITMAP holdbit = NULL;

	// client ���� 
	RECT recClient = ObjManager::GetInstance()->GetRect();
	//GetClientRect(_hWnd, &recClient);

	hMemdc = CreateCompatibleDC(_hdc);
	//hbit = CreateCompatibleBitmap(_hdc, m_bullet.recSrc.right, m_bullet.recSrc.bottom);

	// �̹��� HBITMAP �� �ε��Ͽ� ���� 
	hbit = LoadBitmap(hInst, MAKEINTRESOURCE(BULLET1));
	holdbit = (HBITMAP)SelectObject(hMemdc, hbit);


	// �ð��� �޾ƿ�
	m_dcurTime = timeGetTime();

	// ���� ���� �ð����� ���� �ð��� 0.1float ������ �� 
	if (m_dcurTime - m_dPrevTime >= 0.1f * m_fdelay)
	{
		// object ���� ������ ���� 
		Animation(_hdc, m_bullet, m_iobjstate);

		// ���� �ð��� ���� �ð����� ��ü
		m_dPrevTime = m_dcurTime;
	}


	TransparentBlt(_hdc, m_bullet.posoriginDest.x, m_bullet.posoriginDest.y, m_bullet.recDest.right, m_bullet.recDest.bottom,
		hMemdc, m_bullet.poriginSrc.x, m_bullet.poriginSrc.y, m_bullet.recSrc.right, m_bullet.recSrc.bottom, RGB(255, 255, 255));


	SelectObject(hMemdc, holdbit);


	DeleteDC(hMemdc);
	DeleteObject(hbit);
	
	return;
};

// ������Ʈ �ı�
void Bullet::Destroy()
{
	return;
};


// �Ѿ� ������
bool Bullet::Hit()
{
	return false;
};

void Bullet::ItemState()
{
	return;
}

bool Bullet::bObjDead()
{
	// client ������ ������ 
	if (this->m_bullet.posoriginDest.x > ObjManager::GetInstance()->GetRect().right
		/*|| this->m_bullet.posoriginDest.x < ObjManager::GetInstance()->GetRect().left
		|| this->m_bullet.posoriginDest.y > ObjManager::GetInstance()->GetRect().bottom
		|| this->m_bullet.posoriginDest.y < ObjManager::GetInstance()->GetRect().bottom*/)
	{
		m_bdead = true;
	}
	// ��򰡿� �΋H���� (intercetcRect())
	else if (Hit() == true)
	{
		m_bdead = true;
	}
	else
	{
		m_bdead = false;
	}
	return m_bdead;
}