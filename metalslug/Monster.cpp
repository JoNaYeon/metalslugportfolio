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
            m_Monster.posoriginDest.x -= MONSTERMOVE;
        }
    }

    return;
}