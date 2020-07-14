#include "Player.h"
#include "DBManager.h"
#include "InputManager.h"
#include "RendManager.h"
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
	/*if (InputManager::GetInstance()->Keyboard(E_KEYFIRE) == true && m_classobjptr == NULL)
	{
		m_classobjptr = new Bullet();

		m_classobjptr->Setobjstate(E_GUNSTATE_NORMAL);
		RendManager::GetInstance()->SetVector(m_classobjptr, EOBJECT_BULLET);
		DBManager::GetInstance()->SetVector(m_classobjptr, EOBJECT_BULLET);
	}*/

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
	return;
};