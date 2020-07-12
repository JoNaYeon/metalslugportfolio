#include "Bullet.h"
#include "InputManager.h"
#include "RendManager.h"
#include "DBManager.h"
#include "define.h"


Bullet::Bullet()
{
	// dest = ��� , src = ����
	// ȭ�� �󿡼� ��𿡼����� �̹����� ����� ������ ���� 
	m_bullet.posoriginDest = { 0, 0 };
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
	return;
};

// ������Ʈ ���
void Bullet::Render(HDC& _hdc, HWND& _hWnd)
{
	// �̹����� ���� HDC
	HDC hMemdc = NULL;
	// �̹����� ���� hbitmap
	HBITMAP hbit;
	HBITMAP holdbit;

	// client ���� 
	RECT recClient = RendManager::GetInstance()->GetRect();
	//GetClientRect(_hWnd, &recClient);

	hMemdc = CreateCompatibleDC(_hdc);
	hbit = CreateCompatibleBitmap(_hdc, m_bullet.recSrc.right, m_bullet.recSrc.bottom);

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
		hMemdc, m_bullet.poriginSrc.x, m_bullet.poriginSrc.y, m_bullet.recSrc.right, m_bullet.recSrc.bottom, RGB(255,255,255));

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
void Bullet::Hit()
{
	return;
};

void Bullet::ItemState()
{
	return;
}

