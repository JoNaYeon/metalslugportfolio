#include "Bullet.h"
#include "InputManager.h"
#include "RendManager.h"
#include "DBManager.h"
#include "define.h"


Bullet::Bullet()
{
	m_bullet.poriginSrc = { 0,0 };
	m_bullet.posoriginDest = { 100, 100 };
	m_bullet.recDest = { 0, 0, BULLETSIZE, BULLETSIZE };
	m_bullet.recSrc = { 0, 0, BULLETSIZE, BULLETSIZE };
	m_iobjstate = E_GUNSTATE_NORMAL;
};


// 오브젝트 초기화
void Bullet::Init()
{
	return;
};

// 오브젝트 움직임
void Bullet::Run()
{
	return;
};

// 오브젝트 출력
void Bullet::Render(HDC& _hdc, HWND& _hWnd)
{
	// 이미지를 담을 HDC
	HDC hMemdc = NULL;
	// 이미지를 담을 hbitmap
	HBITMAP hbit;
	HBITMAP holdbit;

	// client 갱신 
	RECT recClient = RendManager::GetInstance()->GetRect();
	GetClientRect(_hWnd, &recClient);

	hMemdc = CreateCompatibleDC(_hdc);
	hbit = CreateCompatibleBitmap(_hdc, m_bullet.recSrc.right, m_bullet.recSrc.bottom);

	// 이미지 HBITMAP 에 로드하여 넣음 
	hbit = LoadBitmap(hInst, MAKEINTRESOURCE(BULLET1));
	holdbit = (HBITMAP)SelectObject(hMemdc, hbit);


	// 시간을 받아옴
	//m_dcurTime = timeGetTime();

	// 만약 이전 시간에서 현재 시간이 0.1float 지났을 때 
	if (m_dcurTime - m_dPrevTime >= 0.1f * m_fdelay)
	{
		// object 상태 움직임 변경 
		Animation(_hdc, m_bullet, m_iobjstate);

		// 이전 시간을 현재 시간으로 대체
		//m_dPrevTime = m_dcurTime;
	}


	// client 보다 큰 bullet 은 출력하지 않기
	// 나중에 고쳐줘야 함.... 임시임. 
	if (BulletOut() == true)
	{
		return;
	}
	

	TransparentBlt(_hdc, m_bullet.posoriginDest.x, m_bullet.posoriginDest.y, m_bullet.recDest.right, m_bullet.recDest.bottom,
		hMemdc, m_bullet.poriginSrc.x, m_bullet.poriginSrc.y, m_bullet.recSrc.right, m_bullet.recSrc.bottom, RGB(255,255,255));

	SelectObject(hMemdc, holdbit);

	DeleteDC(hMemdc);
	DeleteObject(hbit);

	return;
};

// 오브젝트 파괴
void Bullet::Destroy()
{
	return;
};


// 총알 닿으면
void Bullet::Hit()
{
	return;
};

void Bullet::ItemState()
{
	return;
}


bool Bullet::BulletOut()
{
	// client 사이즈보다 총알의 위치가 더 크면 
	if (RendManager::GetInstance()->GetRect().left + BULLETSIZE <= m_bullet.posoriginDest.x)
	{
		return true;
	}
	else
	{
		return false;
	}
	return true;
}