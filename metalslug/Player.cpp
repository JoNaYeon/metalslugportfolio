#include "Player.h"
#include "InputManager.h"
#include "ObjManager.h"
#include "Bullet.h"



// ������
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


// ������Ʈ �ʱ�ȭ (�������̵�)
void Player::Init()
{
	return;
};

// ������Ʈ ������ (�������̵�)
void Player::Run()
{
	return;
};

// ������Ʈ ��� (�������̵�)
void Player::Render()
{
	return;
};

// ������Ʈ �ı� (�������̵�)
void Player::Destroy()
{
	return;
};

// ���� �Ǵ� �ִϸ��̼� 
void Player::DeadZombie()
{
	return;
};

// ���� - �� (�������̵�)
void Player::AttackGun()
{
	return;
};

// ���� - ������ (�������̵�)
void Player::AttackKnife()
{
	return;
};

// ���� - ��ź (�������̵�)
void Player::AttackBomb()
{
	return;
};

// ���� (�������̵�)
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

	static int t = 0;		// ��ü�� �ð� 
						    // x������ ��ġ ���� 
	// 4.0 < �̰� �ڱ�ġ�� ����, �ӷ�
	// 0.4f < �������� ����. �߷�
	// t : ���а� -> ������ -> �̺� -> ������ -> ���׽� -> ������(x,y,x) 
	m_normalplayertop.posoriginDest.y = 0.5f * 0.4f * t * t + (-4.0f) * t + m_normalplayertop.posoriginDest.y;
	m_normalplayerbottom.posoriginDest.y = 0.5f * 0.4f * t * t + (-4.0f) * t + m_normalplayerbottom.posoriginDest.y;

	t++;										// ��ü�� �ð��� �����Ѵ� 
	
	if (m_bgravity == false)
	{
		t = 0;
		m_bjump = false;
	}

	return;
};