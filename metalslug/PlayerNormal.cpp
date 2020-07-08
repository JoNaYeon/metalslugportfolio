#include "PlayerNormal.h"
#include "RendManager.h"
#include "InputManager.h"
#include "define.h"
#include "Mainfrm.h"

MSG* Mainfrm::m_msg;

PlayerNormal::PlayerNormal()
{
	m_iobjstate = E_USERSTATE_IDLE;
	// 상체 구조체 정의
	m_normalplayertop.recSrc = { 0, 0, PLAYERWANIMATION, PLAYERHANIMATION };
	m_normalplayertop.poriginSrc = { 100,100 };
	m_normalplayertop.recDest = { 0, 0, PLAYERWANIMATION, PLAYERHANIMATION };
	// 하체 구조체 정의
	m_normalplayerbottom.recSrc = { 0, 0, PLAYERWANIMATION, PLAYERHANIMATION };
	m_normalplayerbottom.poriginSrc = { 100,100 };
	m_normalplayerbottom.recDest = { 0, 0, PLAYERWANIMATION, PLAYERHANIMATION };

	m_itopBitmapImg = USERIDLETOP0;
	m_ibottomBitmapImg = USERIDLEBOTTOM1;

	m_bleftright = true;

	return;
}


// 오브젝트 초기화 (오버라이딩)
void PlayerNormal::Init()
{
	return;
};

// 오브젝트 움직임 (오버라이딩)
void PlayerNormal::Run()
{
	// 키보드 입력 받기
	// 키보드 입력은 정리해서 판정에 우선순위를 구분할 것 
	if (InputManager::GetInstance()->Keyboard(E_KEYJUMP) == true)
	{

	}
	else if (InputManager::GetInstance()->Keyboard(E_KEYLEFT) == true)
	{
		m_iobjstate = E_USERSTATE_LWALK;
		m_itopBitmapImg = USERIDLETOP2;
		m_ibottomBitmapImg = USERRUNBOTTOM2;
		m_bleftright = false;
	}
	else if (InputManager::GetInstance()->Keyboard(E_KEYRIGHT) == true)
	{
		m_iobjstate = E_USERSTATE_RWALK;
		m_itopBitmapImg = USERIDLETOP0;
		m_ibottomBitmapImg = USERRUNBOTTOM1;
		m_bleftright = true;
	}
	else
	{
		// bool 변수 혹은 enum 으로 좌우 위치 확인해주기
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

// 오브젝트 출력 (오버라이딩)
void PlayerNormal::Render(HDC& _hdc, HWND& _hWnd)
{ 
	// 이미지의 hdc
	HDC hobjdc;
	// 이미지 로드받을 hbitmap
	HBITMAP htopobjBit;
	HBITMAP hbottomobjBit;
	// 이미지 저장받을 hbitmap
	HBITMAP holdBit;
	
	// 범위 리셋 
	RECT recClient = RendManager::GetInstance()->GetRect();
	GetClientRect(_hWnd, &recClient);

	// 이미지 출력할 hdc 출력 
	hobjdc = CreateCompatibleDC(_hdc);


	// 하체 이미지를 저장할 HBITMAP
	hbottomobjBit = CreateCompatibleBitmap(_hdc,
		m_normalplayerbottom.recSrc.right, m_normalplayerbottom.recSrc.bottom);
	// 상체 이미지를 저장할 HBITMAP
	htopobjBit = CreateCompatibleBitmap(_hdc,
		m_normalplayertop.recSrc.right, m_normalplayertop.recSrc.bottom);


	// 비트맵을 hBIt에 뿌려주기
	// hinst를 null로 하지 말자 
	hbottomobjBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(m_ibottomBitmapImg));
	// oldbit 에 이미지 저장 
	holdBit = (HBITMAP)SelectObject(hobjdc, hbottomobjBit);

	// 하체 이미지 출력
	TransparentBlt(_hdc, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y,
		m_normalplayerbottom.recSrc.right * 4, m_normalplayerbottom.recSrc.bottom * 4,
		hobjdc, m_normalplayerbottom.recDest.left, m_normalplayerbottom.recDest.top,
		m_normalplayerbottom.recSrc.right, m_normalplayerbottom.recSrc.bottom, RGB(255, 255, 255));


	// 비트맵을 hBIt에 뿌려주기
	// hinst를 null로 하지 말자 
	htopobjBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(m_itopBitmapImg));
	// oldbit 에 상체 이미지 저장 
	holdBit = (HBITMAP)SelectObject(hobjdc, htopobjBit);

	// 상체 이미지 출력
	TransparentBlt(_hdc, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y,
		m_normalplayertop.recSrc.right * 4, m_normalplayertop.recSrc.bottom * 4,
		hobjdc, m_normalplayertop.recDest.left, m_normalplayertop.recDest.top,
		m_normalplayertop.recSrc.right, m_normalplayertop.recSrc.bottom, RGB(255, 255, 255));
	

	// object 상태 움직임 변경 
	Animation(_hdc, m_normalplayertop, m_normalplayerbottom, m_iobjstate);


	// oldbit로 바꿔주기
	SelectObject(hobjdc, holdBit);

	DeleteDC(hobjdc);
	DeleteObject(htopobjBit);
	DeleteObject(hbottomobjBit);

	return;
};

// 오브젝트 파괴 (오버라이딩)
void PlayerNormal::Destroy()
{
	return;
};

// 좀비가 되는 애니메이션 
void PlayerNormal::DeadZombie()
{
	return;
};

// 공격 - 총 (오버라이딩)
void PlayerNormal::AttackGun()
{
	return;
};

// 공격 - 나이프 (오버라이딩)
void PlayerNormal::AttackKnife()
{
	return;
};

// 공격 - 폭탄 (오버라이딩)
void PlayerNormal::AttackBomb()
{
	return;
};

// 점프 (오버라이딩)
void PlayerNormal::Jump()
{
	return;
};

