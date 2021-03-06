#include "Object.h"
#include "Mainfrm.h"
#include "Background.h"

DWORD Object::m_dPrevTime = timeGetTime();


// 생성자
Object::Object()
{
	m_iobjstate = -1;
	m_dcurTime = timeGetTime();
	m_fdelay = 1;

	// 중력 true
	m_bgravity = true;

	m_bdead = false;
	m_bfire = false;

	m_bCollisionCheck = false;
	
	// 임시 - 라인 충돌 검사를 위해 임시로 true 해둠
	m_bypos = true;


	int m_gravitytemp = 0;
};

void Object::Aniimage(DISPLAYINFO& _displayInfo, IMAGEINFO _imageInfo)
{
	// state가 달라지면 originsrc를 0,0부터 시작하여 잘려보이는 현상 없애기
	if (m_iobjstatetemp != m_iobjstate)
	{
		m_iobjstatetemp = m_iobjstate;
		_displayInfo.ptSrcPos = { 0,0 };
	}

	if (_displayInfo.ptSrcPos.x < _displayInfo.ptDestSize.x * (_imageInfo.iWidthnum - 1))
	{
		_displayInfo.ptSrcPos.x += _displayInfo.ptDestSize.x;
	}
	else
	{
		_displayInfo.ptSrcPos.x = 0;
		_displayInfo.ptSrcPos.y += _displayInfo.ptDestSize.y;

		if (_displayInfo.ptSrcPos.y >= _displayInfo.ptDestSize.y * (_imageInfo.iHightnum - 1))
		{
			_displayInfo.ptSrcPos.y = 0;
		}
	}
}

bool Object::IntersectRectCheck(RECT* _rec1, RECT* _rec2)
{
	if ((_rec1->right >= _rec2->left) && (_rec1->left <= _rec2->right))
	{
		if ((_rec1->bottom >= _rec2->top) && (_rec1->top <= _rec2->bottom))
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

void Object::SetImgInfo(IMAGEINFO& _imgInfo, POINT _ptSrcSize, int _iWidthNum, int _iHightNum)
{
	_imgInfo.iHightnum = _iHightNum;
	_imgInfo.iWidthnum = _iWidthNum;
	_imgInfo.ptSrcSize = _ptSrcSize;
}

void Object::Gravity(DISPLAYINFO* _objdis, E_OBJECT _eobj)
{
	// 중력이 true 일 때 
	if (m_bgravity == true && m_iobjstate != E_USERSTATE_JUMP)
	{
		for (int i = 0; i < ObjManager::GetInstance()->GetVector(_eobj).size(); i++)
		{
			RECT rectemp = { 0,0,0,0 };
			RECT recHitPlayer = ObjManager::GetInstance()->GetVector(_eobj)[i]->GetHitBox();

			for (int j = 0; j < ObjManager::GetInstance()->GetVector(_eobj).size(); j++)
			{
				RECT recHitBG = ObjManager::GetInstance()->GetVector(EOBJECT_BG)[j]->GetHitBox();

				// 배경과 user가 충돌이 일어나지 않을 때 중력 적용 
				if (IntersectRect(&rectemp, &recHitPlayer, &recHitBG) == false && m_bjump == false)
				{
					// 임시 중력 
					_objdis->ptDestPos.y += 0.5f * 0.4f * m_gravitytemp * m_gravitytemp;
				}
			}
		}
	}
	else
	{
		m_gravitytemp = 0;
	}

	m_gravitytemp++;

	return;
}

void Object::SetboolGravity(bool _bGravity)
{ 
	m_bgravity = _bGravity;
	
	return; 
};

// 객체의 위치를 가져오는 함수
DISPLAYINFO* Object::GetDisTop()
{
	return &m_DisTop;
}

DISPLAYINFO* Object::GetDisBot()
{
	return &m_DisBot;
}


// 객체의 위치를 세팅하는 함수
void Object::SetDisTop(POINT _disTop)
{
	return;
}

void Object::SetDisBot(POINT _disTop)
{
	return;
}

int Object::Getobjstate()
{
	return m_iobjstate; 
};

// y값(위치 높이)을 계산하여 위치값을 지정해주는 함수
int Object:: ObjectyLevel(int _iobjdistancey)
{
	// 점프하는 중이 아닐 경우에만 검사하기
	//if (m_iobjstate != E_USERSTATE_JUMP)
	if (m_bjump == false)
	{
		// 점프가 아닐시, 중력 true
		m_bgravity = true;

		// 오브젝트가 line보다 아래에 있을 때 
		if (_iobjdistancey - m_DisTop.ptDestPos.y <= ((m_DisTop.ptDestSize.y * PLAYERSIZE)))
		{
			m_bgravity = false;
			m_iuserycase = E_USERYUPDOWN_UP;

			// 오브젝트 상태 IDLE
			m_iobjstate = E_USERSTATE_IDLE;
		}
		// 오브젝트가 line보다 위에 있을 때
		/*else if (_iobjdistancey - m_DisTop.ptDestPos.y > ((m_DisTop.ptDestSize.y * PLAYERSIZE)))
		{
			m_iuserycase = E_USERYUPDOWN_DOWN;

			// 오브젝트 상태 JUMP
			m_iobjstate = E_USERSTATE_IDLE;
		}*/
	}
	// 점프중일 경우
	else
	{
		// 오브젝트 상태 JUMP
		m_iobjstate = E_USERSTATE_JUMP;
		m_iuserycase = E_USERYUPDOWN_JUMP;

		// 점프중에 line과 부딪힐 경우 
		if (_iobjdistancey - m_DisTop.ptDestPos.y <= ((m_DisTop.ptDestSize.y * PLAYERSIZE)))
		{
			m_bgravity = false;

			// 오브젝트 상태 IDLE
			m_iobjstate = E_USERSTATE_IDLE;
		}
	}

	// 오브젝트 + (IDLE의 크기 - JUMP의 크기) 가 라인보다 아래에 있을 경우 m_iobjstate 초기화
	if (_iobjdistancey - m_DisTop.ptDestPos.y <= (m_DisTop.ptDestSize.y * PLAYERSIZE))
	{
		m_iobjstate = 0;
	}

	return m_iuserycase;
}

// 오브젝트의 y값이 올라가지 말아야 할 때 좌우로 움직일 수 없도록 하는 함수
void Object::ObjectStopYLevelControl(int _iobjyLevel)
{
	

	return;
}