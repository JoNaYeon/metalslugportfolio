#include "Player.h"

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
	static int t = 0;		// ��ü�� �ð� 
	// x������ ��ġ ���� 
	// 4.0 < �̰� �ڱ�ġ�� ����, �ӷ�
	// 0.4f < �������� ����. �߷�
	// t : ���а� -> ������ -> �̺� -> ������ -> ���׽� -> ������(x,y,x) 
	m_DisTop.ptDestPos.y = 0.5f * 0.4f * t * t + (-4.0f) * t + m_DisTop.ptDestPos.y;
	m_DisBot.ptDestPos.y = 0.5f * 0.4f * t * t + (-4.0f) * t + m_DisBot.ptDestPos.y;

	t++; // ��ü�� �ð��� �����Ѵ� 
	
	if (m_bgravity == false)
	{
		t = 0;
		m_bjump = false;
	}

	return;
};