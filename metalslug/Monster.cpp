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
            //m_DisMon.ptDestPos.x -= (BACKGROUNDMOVE * BGSIZE);
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
    // ������ �и� switch
    /*switch
    {
        //
    }*/
    
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
