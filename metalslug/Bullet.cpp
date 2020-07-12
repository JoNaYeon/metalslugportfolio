#include "Bullet.h"
#include "InputManager.h"
#include "RendManager.h"
#include "DBManager.h"
#include "define.h"


Bullet::Bullet()
{
	// dest = 출력 , src = 원본
	// 화면 상에서 어디에서부터 이미지를 출력할 것인지 지정 
	m_bullet.posoriginDest = { 0, 0 };
	// 화면상에서의 이미지 높이/너비 지정
	// left top right bottom
	m_bullet.recDest = { 0, 0, BULLETSIZE, BULLETSIZE };
	// 이미지 대상에서 어디 좌표에서부터 출력할 것인지 지정
	m_bullet.poriginSrc = { 0, 0 }; 
	// 출력할 이미지를 얼마의 크기로 출력할지 지정
	m_bullet.recSrc = { 0, 0, BULLETSIZE, BULLETSIZE };
	m_bullet.iobjmove = BULLETMOVE;
	m_bullet.iWidthnum = BULLETWNUM;
	m_bullet.iHightnum = BULLETHNUM;

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
	//GetClientRect(_hWnd, &recClient);

	hMemdc = CreateCompatibleDC(_hdc);
	hbit = CreateCompatibleBitmap(_hdc, m_bullet.recSrc.right, m_bullet.recSrc.bottom);

	// 이미지 HBITMAP 에 로드하여 넣음 
	hbit = LoadBitmap(hInst, MAKEINTRESOURCE(BULLET1));
	holdbit = (HBITMAP)SelectObject(hMemdc, hbit);


	// 시간을 받아옴
	m_dcurTime = timeGetTime();

	// 만약 이전 시간에서 현재 시간이 0.1float 지났을 때 
	if (m_dcurTime - m_dPrevTime >= 0.1f * m_fdelay)
	{
		// object 상태 움직임 변경 
		Animation(_hdc, m_bullet, m_iobjstate);

		// 이전 시간을 현재 시간으로 대체
		m_dPrevTime = m_dcurTime;
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

