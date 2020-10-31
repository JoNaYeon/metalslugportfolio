#include "Monster.h"

// ������
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
    // ��� ���� �� ���� return
    return false;
}


void Monster::Hit()
{    
    // �ǰ� ��� �߰�

    if (m_bCollisionCheck == true)
    {
        m_ihp -= E_DAMAGE_NORMAL;
    }

    // �ǰ� ��� �ֱ� 

    return;
}


void Monster::MovePattern()
{
    return;
}


// ������Ʈ ������ (�������̵�)
void Monster::Run()
{
	//AnimationStateCheck();

	//AnimationStateMove();

	// top hitbox ���ǽ����ֱ� 
	m_recHitBox = { m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		m_DisTop.ptDestPos.x + (m_DisTop.ptDestSize.x * PLAYERSIZE),
		m_DisTop.ptDestPos.y + (m_DisTop.ptDestSize.y * PLAYERSIZE) };
	// #�ӽ�
	Gravity(&m_DisTop, EOBJECT_MONSTER);

	// #�ӽ� - ��ü�� ��ü�� �и��Ǵ� �� �����ֱ�
	m_DisBot.ptDestPos.y = m_DisTop.ptDestPos.y;

	return;
};