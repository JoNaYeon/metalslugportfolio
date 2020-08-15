#include "Player.h"
#include "Bullet.h"
#include "ObjManager.h"

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

	//m_fgravity = 0;
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
	// 이미지 한바퀴 돌면 false로 만들어주기 
	if (m_DisTop.ptSrcPos.y >= ((m_DisTop.ptDestSize.y) * (m_ImgTop.iHightnum - 1)))
	{
		Object* objbullet = new Bullet(m_DisTop.ptDestPos);
		ObjManager::GetInstance()->SetVector(objbullet, EOBJECT_BULLET);

		m_bfire = false;
	}

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
	static int t = 0;		// 물체의 시각 


	if (m_bgravity == true)
	{
		t = 0;
		m_bjump = false;
	}

	// 가장 높은 정점에 다달았을 때 
	/*if (m_DisTop.ptDestPos.y >= 100)
	{
		m_bjump = true;
	}*/


	// x방향의 위치 결정 
	// 4.0 < 이게 솟구치는 정도, 속력
	// 0.4f < 떨어지는 정도. 중력
	// t : 적분값 -> 정적분 -> 미분 -> 방정식 -> 다항식 -> 미지수(x,y,x) 
	m_DisTop.ptDestPos.y = 0.5f * 0.4f * t * t + (-4.0f) * t + m_DisTop.ptDestPos.y;
	m_DisBot.ptDestPos.y = 0.5f * 0.4f * t * t + (-4.0f) * t + m_DisBot.ptDestPos.y;

	t++; // 물체의 시각을 진행한다 
	

	return;
};