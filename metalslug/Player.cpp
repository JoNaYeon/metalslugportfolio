#include "Player.h"
#include "DBManager.h"
#include "InputManager.h"
#include "RendManager.h"
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
	/*if (InputManager::GetInstance()->Keyboard(E_KEYFIRE) == true && m_classobjptr == NULL)
	{
		m_classobjptr = new Bullet();

		m_classobjptr->Setobjstate(E_GUNSTATE_NORMAL);
		RendManager::GetInstance()->SetVector(m_classobjptr, EOBJECT_BULLET);
		DBManager::GetInstance()->SetVector(m_classobjptr, EOBJECT_BULLET);
	}*/

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
	return;
};