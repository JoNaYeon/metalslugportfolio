#include "Monster.h"

void Monster::MonsterMove(E_USERSTATE _e_state)
{
    switch (_e_state)
    {
        /*case E_USERSTATE_LWALK:
        {
            m_Monster.posoriginDest.x -= BACKGROUNDMOVE;
        }*/
        case E_USERSTATE_RWALK:
        {
            m_DisMon.ptDestPos.x -= MONSTERMOVE;
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


void MovePattern()
{
    return;
}