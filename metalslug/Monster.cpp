#include "Monster.h"

// 생성자
Monster::Monster()
{
    //m_iobjsize = 1;

    m_ihp = 0;
    m_istrength = 0;
    m_ispeed = 0;

};

void Monster::MonsterMove(E_USERSTATE _e_state)
{
    switch (_e_state)
    {
        case E_USERSTATE_RWALK:
        {
            m_DisTop.ptDestPos.x -= (BACKGROUNDMOVE * BGSIZE);
        }
    }

    return;
}

bool Monster::bObjDead()
{
    // 모션 진행 후 삭제 return
    return false;
}


void Monster::Hit()
{    
    // 피격 모션 추가

    if (m_bCollisionCheck == true)
    {
        m_ihp -= E_DAMAGE_NORMAL;
    }

    // 피격 모션 넣기 

    return;
}


void Monster::MovePattern()
{
    return;
}


// 오브젝트 움직임 (오버라이딩)
void Monster::Run()
{
	//AnimationStateCheck();

	//AnimationStateMove();

	// top hitbox 정의시켜주기 
	m_recHitBox = { m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		m_DisTop.ptDestPos.x + (m_DisTop.ptDestSize.x * PLAYERSIZE),
		m_DisTop.ptDestPos.y + (m_DisTop.ptDestSize.y * PLAYERSIZE) };
	// #임시
	Gravity(&m_DisTop, EOBJECT_MONSTER);

	// #임시 - 상체와 하체가 분리되는 것 막아주기
	m_DisBot.ptDestPos.y = m_DisTop.ptDestPos.y;

	return;
};