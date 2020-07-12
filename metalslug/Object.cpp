#include "Object.h"
#include "Mainfrm.h"

DWORD Object::m_dPrevTime = timeGetTime();


// ������
Object::Object()
{
	m_iobjstate = -1;
	m_dcurTime = timeGetTime();
	m_fdelay = 1;
};

void Object::Aniimage(ST_OBJECT& _obj)
{
	// top ����
	if (_obj.poriginSrc.x < _obj.recSrc.right * (_obj.iWidthnum - 1))
	{
		_obj.poriginSrc.x += _obj.recSrc.right;
	}
	else
	{
		_obj.poriginSrc.x = 0;
		_obj.poriginSrc.y += _obj.recSrc.bottom;

		if (_obj.poriginSrc.y >= _obj.recSrc.bottom * (_obj.iHightnum - 1))
		{
			_obj.poriginSrc.y = 0;
		}
	}
}

void Object::Animation(HDC& _hdc, ST_OBJECT& _obj, int& _iobjstate)
{
	switch (_iobjstate)
	{
		// ���� ����
	case E_USERSTATE_IDLE:
	{
		// �̹��� �����̴� �Լ� 
		Aniimage(_obj);
	}
	break;
	case E_USERSTATE_RWALK:
	{
		// ������ ��ư ������ �� ����
		RECT recclient;
		GetClientRect(Mainfrm::GethWnd(), &recclient);

		// �̹��� �����̴� �Լ� 
		Aniimage(_obj);

		if (_obj.posoriginDest.x >= (recclient.right - (_obj.recDest.right * _obj.iWidthnum)))
		// ���� ��ü�� client �̻� ���� ���� �� ������ �� 
		{
			break;
		}

		if (InputManager::GetInstance()->Getbkeyboard() == false)
		{
			_obj.posoriginDest.x += _obj.iobjmove;
		}
	}
	break;
	case E_USERSTATE_LWALK:
	{
		// ���� ��ư ������ �� ����
		RECT recclient;
		GetClientRect(Mainfrm::GethWnd(), &recclient);

		// �̹��� �����̴� �Լ� 
		Aniimage(_obj);

		if (_obj.posoriginDest.x <= recclient.left)
		// ���� ��ü�� client �̻� ���� �� �� ������ �� 
		{
			break;
		}

		if (InputManager::GetInstance()->Getbkeyboard() == false)
		{
			_obj.posoriginDest.x -= _obj.iobjmove;
		}
	}
	break;
	case E_USERSTATE_JUMP:
	{
		// �̹��� �����̴� �Լ� 
		Aniimage(_obj);
	}
	break;
	case E_GUNSTATE_NORMAL:
	{
		// �߻� ��ư ������ ���� �Լ� 
		RECT recclient;
		GetClientRect(Mainfrm::GethWnd(), &recclient);

		// �̹��� �����̴� �Լ� 
		Aniimage(_obj);

		_obj.posoriginDest.x += _obj.iobjmove;
	}
	break;
	}

	return;
}



void Object::hitbox(RECT _rec1, RECT _rec2)
{
	// ��Ʈ���� 
	IntersectRect(NULL, &_rec1, &_rec2);

	return;
}

// iter �� vector �ֱ�
bool Object::GetIter(std::vector<Object*>& _obj)
{

	return false;
};


// object�� ȭ�� ������ ������
void Object::ObjectOut(Object& _obj, std::vector<Object*>& _vecobj)
{
	if (_obj.m_bullet.posoriginDest.x >= RendManager::GetInstance()->GetRect().right)
	{
		m_objiter = _vecobj.begin();

		// for ���� bullet vector �� �����ŭ ���鼭 iter�� �ϳ��� ����.
		for (int i = 0; i < _vecobj.size(); i++)
		{
			// ���� i��° bullet vector �� ������ bullet�� ���ٸ� 
			//���� iter�� ����Ű�� bullet�� �����ϰ� ���� iter�� ����Ű�� ��
			if (_vecobj[i] == &_obj)
			{
				_vecobj[i]->Destroy();
				m_objiter = _vecobj.erase(m_objiter);
			}
			else
			{
				// iter �� ����Ű�� �κ� �ϳ��� �ű��
				++m_objiter;
			}

		}
	}
	return;
}

ST_OBJECT Object::GetStruct(int _iobjkind)
{
	switch (_iobjkind)
	{
		case E_OBJECTKIND_PLAYERTOP:
		{
			return m_normalplayertop;
		}
		break;
		case E_OBJECTKIND_PLAYERBOTTOM:
		{
			return m_normalplayerbottom;
		}
		break;
		case E_OBJECTKIND_BULLET:
		{
			return m_bullet;
		}
		break;
		case E_OBJECTKIND_BG1:
		{
			return m_BG1;
		}
		case E_OBJECTKIND_BG2:
		{
			return m_BG2;
		}
		break;
	}
}