#include "Player.h"
#include "Bullet.h"
#include "ObjManager.h"

// ������
Player::Player()
{
	// �÷��̾� ������ ����
	//m_iobjsize = PLAYERSIZE;

	m_ihp = 0;
	m_istrength = 0;
	m_ispeed = 0;
	m_igun = 0;
	m_ibomb = 0;
	m_ivirous = 0;
	m_bhuman = 0;

	//m_fgravity = 0;
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
	// �̹��� �ѹ��� ���� false�� ������ֱ� 
	if (m_DisTop.ptSrcPos.y >= ((m_DisTop.ptDestSize.y) * (m_ImgTop.iHightnum - 1)))
	{
		Object* objbullet = new Bullet(m_DisTop.ptDestPos);
		ObjManager::GetInstance()->SetVector(objbullet, EOBJECT_BULLET);

		m_bfire = false;
	}

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
	// x������ ��ġ ���� 
	// 4.0 < �̰� �ڱ�ġ�� ����, �ӷ�
	// 0.4f < �������� ����. �߷�
	// t : ���а� -> ������ -> �̺� -> ������ -> ���׽� -> ������(x,y,x) 
	m_DisTop.ptDestPos.y = 0.5f * 0.4f * m_t * m_t + (-4.0f) * m_t + m_DisTop.ptDestPos.y;
	m_DisBot.ptDestPos.y = 0.5f * 0.4f * m_t * m_t + (-4.0f) * m_t + m_DisBot.ptDestPos.y;

	m_t++; // ��ü�� �ð��� �����Ѵ� 
	

	return;
};



void Player::SetDisTop(POINT _disTop)
{ 
	m_DisTop.ptDestPos = _disTop; 
	
	return; 
}

void Player::SetDisBot(POINT _disBot)
{ 
	m_DisBot.ptDestPos = _disBot; 
	
	return; 
};

void Player::SetboolGravity(bool _bGravity)
{ 
	m_bgravity = _bGravity; 

	if (m_bgravity == false)
	{
		if (m_iobjstate == E_USERSTATE_JUMP)
		{
			m_bjump = false;
			m_t = 0;
			m_iobjstate = E_USERSTATE_IDLE;
		}
	}
	
	return; 
};