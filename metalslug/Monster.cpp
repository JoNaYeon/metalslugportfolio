#include "Monster.h"

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
    // 모션 진행 후 삭제 return
    return false;
}


void Monster::Hit()
{
    // 데미지 분리 switch
    /*switch
    {
        //
    }*/
    
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
