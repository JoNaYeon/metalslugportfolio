#include "Object.h"
#include "Mainfrm.h"
#include "Background.h"

DWORD Object::m_dPrevTime = timeGetTime();


// ������
Object::Object()
{
	//m_iobjsize = 1;

	m_iobjstate = -1;
	m_dcurTime = timeGetTime();
	m_fdelay = 1;

	//m_fvelocity = -VELOCITY;
	//m_bgravity = true;

	m_bdead = false;
	m_bfire = false;
	//m_bypos = false;

	m_bCollisionCheck = false;
	
	// �ӽ� - ���� �浹 �˻縦 ���� �ӽ÷� true �ص�
	m_bypos = true;


	int m_gravitytemp = 0;
};

void Object::Aniimage(DISPLAYINFO& _displayInfo, IMAGEINFO _imageInfo)
{
	// state�� �޶����� originsrc�� 0,0���� �����Ͽ� �߷����̴� ���� ���ֱ�
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
	//static int temp = 0;		// ��ü�� �ð� 

	// gravity �� true �� �� �߷� ����
	if (m_bgravity == true)
	{
		for (int i = 0; i < ObjManager::GetInstance()->GetVector(_eobj).size(); i++)
		{
			RECT rectemp = { 0,0,0,0 };
			RECT recHitPlayer = ObjManager::GetInstance()->GetVector(_eobj)[i]->GetHitBox();

			for (int j = 0; j < ObjManager::GetInstance()->GetVector(_eobj).size(); j++)
			{
				RECT recHitBG = ObjManager::GetInstance()->GetVector(EOBJECT_BG)[j]->GetHitBox();

				// ���� user�� �浹�� �Ͼ�� ���� �� �߷� ���� 
				if (IntersectRect(&rectemp, &recHitPlayer, &recHitBG) == false && m_bjump == false)
				{
					// �ӽ� �߷� 
					_objdis->ptDestPos.y += 0.5f * 0.4f * m_gravitytemp * m_gravitytemp;
					//_objdis->ptDestPos.y += 10;
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

// ��ü�� ��ġ�� �������� �Լ�
DISPLAYINFO* Object::GetDisTop()
{
	return &m_DisTop;
}

DISPLAYINFO* Object::GetDisBot()
{
	return &m_DisBot;
}


// ��ü�� ��ġ�� �����ϴ� �Լ�
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

// y��(��ġ ����)�� ����Ͽ� ��ġ���� �������ִ� �Լ�
int Object:: ObjectyLevel(int _iobjdistancey)
{
	// ������Ʈ�� ���κ��� �Ʒ��� ���� ��� m_iobjstate �ʱ�ȭ
	if (m_DisTop.ptDestPos.y - _iobjdistancey > -((m_DisTop.ptDestSize.y * PLAYERSIZE) + OBJALLOWEDPIXEL))
	{
		m_iobjstate = 0;
	}

	// �����ϴ� ���� �ƴ� ��쿡�� �˻��ϱ�
	if (m_iobjstate != E_USERSTATE_JUMP)
	{
		// ������Ʈ�� ���δ�
		if (m_DisTop.ptDestPos.y - _iobjdistancey < - ((m_DisTop.ptDestSize.y * PLAYERSIZE) + OBJALLOWEDPIXEL))
		{
			m_iuserycase = E_USERYUPDOWN_UP;
			m_bgravity = false;

		}
		// ������Ʈ�� �����
		else if (m_DisTop.ptDestPos.y - _iobjdistancey >= ((m_DisTop.ptDestSize.y * PLAYERSIZE) + OBJALLOWEDPIXEL))
		{
			m_iuserycase = E_USERYUPDOWN_DOWN;
		}
		// ������Ʈ�� �����
		else if (m_DisTop.ptDestPos.y - _iobjdistancey >= ((m_DisTop.ptDestSize.y * PLAYERSIZE) + OBJALLOWEDPIXEL)
			|| m_DisTop.ptDestPos.y - _iobjdistancey < - ((m_DisTop.ptDestSize.y * PLAYERSIZE) + OBJALLOWEDPIXEL))
		{
			m_iuserycase = E_USERYUPDOWN_STOP;
		}
	}
	// �������� ��
	else
	{
		if (m_DisTop.ptDestPos.y - _iobjdistancey > ((m_DisTop.ptDestSize.y * PLAYERSIZE) + OBJALLOWEDPIXEL))
		{
			m_iuserycase = E_USERYUPDOWN_JUMP;
		}
		else if (m_DisTop.ptDestPos.y - _iobjdistancey > ((m_DisTop.ptDestSize.y * PLAYERSIZE) + OBJALLOWEDPIXEL))
		{
			m_iuserycase = E_USERUPDOWN_JUMPSTOP;

			// ������ �ƴ� �߿��� ���� false�� �ٲ��ֱ�
			m_bjump = false;
		}

	}

	return m_iuserycase;
}

// ������Ʈ�� y���� �ö��� ���ƾ� �� �� �¿�� ������ �� ������ �ϴ� �Լ�
/*void Object::ObjectStopYLevelControl(int _iobjyLevel)
{
	// ������ ��� 
	if (ObjectyLevel(_iobjyLevel) == E_USERYUPDOWN_STOP)
	{
		if (m_iobjstate == E_USERSTATE_LWALK)
		{
			
		}
		else if (m_iobjstate == E_USERSTATE_RWALK)
		{

		}
	}
	return;
}*/