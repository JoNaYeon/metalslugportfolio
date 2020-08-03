#include "Player.h"
#include "InputManager.h"
#include "ObjManager.h"
#include "Bullet.h"



// 생성자
Player::Player()
{
	m_ihp = 0;
	m_istrength = 0;
	m_ispeed = 0;
	m_igun = 0;
	m_ibomb = 0;
	m_ivirous = 0;
	m_bhuman = 0;


	m_fgravity = 0;
	m_bjump = false;

	m_classobjptr = NULL;
};


// 오브젝트 초기화 (오버라이딩)
void Player::Init()
{
	return;
};

// 오브젝트 움직임 (오버라이딩)
void Player::Run()
{
	return;
};

// 오브젝트 출력 (오버라이딩)
void Player::Render()
{
	return;
};

// 오브젝트 파괴 (오버라이딩)
void Player::Destroy()
{
	return;
};

// 좀비가 되는 애니메이션 
void Player::DeadZombie()
{
	return;
};

// 공격 - 총 (오버라이딩)
void Player::AttackGun()
{
	return;
};

// 공격 - 나이프 (오버라이딩)
void Player::AttackKnife()
{
	return;
};

// 공격 - 폭탄 (오버라이딩)
void Player::AttackBomb()
{
	return;
};

// 점프 (오버라이딩)
void Player::Jump()
{
	// jump bottom
	m_iobjstate = E_USERSTATE_JUMP;
	m_strBitmapBottom = "..\\source\\user\\userjunp.bmp";

	SetObjStruct(m_normalplayerbottom, JUMPPLAYERWANIMATION, JUMPPLAYERHANIMATION, m_normalplayerbottom.poriginSrc.x, m_normalplayerbottom.poriginSrc.y,
		JUMPPLAYERWANIMATION, JUMPPLAYERHANIMATION, m_normalplayerbottom.posoriginDest.x, m_normalplayerbottom.posoriginDest.y, JUMPUSERDMOVE,
		JUMPPLAYERWNUM, JUMPPLAYERHNUM);

	// jump top
	m_iobjstate = E_USERSTATE_JUMP;
	m_strBitmapTop = "..\\source\\user\\userjunptop.bmp";

	SetObjStruct(m_normalplayertop, JUMPPLAYERWANIMATION, JUMPPLAYERHANIMATION, m_normalplayertop.poriginSrc.x, m_normalplayertop.poriginSrc.y,
		JUMPPLAYERWANIMATION, JUMPPLAYERHANIMATION, m_normalplayertop.posoriginDest.x, m_normalplayertop.posoriginDest.y, JUMPUSERDMOVE,
		JUMPPLAYERWNUM, JUMPPLAYERHNUM);

	static int t = 0;		// 물체의 시각 
						    // x방향의 위치 결정 
	// 4.0 < 이게 솟구치는 정도, 속력
	// 0.4f < 떨어지는 정도. 중력
	// t : 적분값 -> 정적분 -> 미분 -> 방정식 -> 다항식 -> 미지수(x,y,x) 
	m_normalplayertop.posoriginDest.y = 0.5f * 0.4f * t * t + (-4.0f) * t + m_normalplayertop.posoriginDest.y;
	m_normalplayerbottom.posoriginDest.y = 0.5f * 0.4f * t * t + (-4.0f) * t + m_normalplayerbottom.posoriginDest.y;

	t++;										// 물체의 시각을 진행한다 
	
	if (m_bgravity == false)
	{
		t = 0;
		m_bjump = false;
	}

	return;
};