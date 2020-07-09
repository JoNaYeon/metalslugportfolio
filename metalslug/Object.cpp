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
	if (_obj.recDest.left != PLAYERWANIMATION * 3)
	{
		_obj.recDest.left += PLAYERWANIMATION;
	}
	else
	{
		_obj.recDest.left = 0;
		_obj.recDest.top += PLAYERHANIMATION;

		if (_obj.recDest.top >= PLAYERHANIMATION * 3)
		{
			_obj.recDest.top = 0;
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

		if (_obj.posoriginDest.x >= (recclient.right - (_obj.recDest.right * 4)))
		// ���� ��ü�� client �̻� ���� ���� �� ������ �� 
		{
			break;
		}

		if (InputManager::GetInstance()->Getbkeyboard() == false)
		{
			_obj.posoriginDest.x += USERDMOVE;
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
			_obj.posoriginDest.x -= USERDMOVE;
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

		if (_obj.posoriginDest.x <= recclient.left + BULLETSIZE)
		// ���� ��ü�� client + �Ѿ� ������ ���� Ŭ ���, ��ü �ı�
		{
			// �ı����ֱ� 
			break;
		}

		// �̹��� �����̴� �Լ� 
		Aniimage(_obj);

		_obj.posoriginDest.x -= BULLETMOVE;
	}
	break;
	}

	return;
}


/*void Object::Animation(HDC& _hdc, ST_OBJECT& _objtop, ST_OBJECT& _objbottom, int& _iobjstate)
{
	// �ִϸ��̼� - ST_OBJECT �� �ϳ��� �޾Ƽ� �� �� �ֵ��� ���� 

	// �ð��� �޾ƿ�
	m_dcurTime = timeGetTime();
	
	// ���� ���� �ð����� ���� �ð��� 0.1float ������ �� 
	if (m_dcurTime - m_dPrevTime >= 0.1f * m_fdelay)
	{
		switch (_iobjstate)
		{
			// ���� ����
			case E_USERSTATE_IDLE:
			{
				// �̹��� �����̴� �Լ� 
				Aniimage(_objtop);
				Aniimage(_objbottom);
			}
			break;
			case E_USERSTATE_RWALK:
			{
				// ������ ��ư ������ �� ����
				RECT recclient;
				GetClientRect(Mainfrm::GethWnd(), &recclient);

				// �̹��� �����̴� �Լ� 
				Aniimage(_objtop);
				Aniimage(_objbottom);

				if (_objtop.posoriginDest.x >= (recclient.right - (_objtop.recDest.right * 4)))
					// ���� ��ü�� client �̻� ���� ���� �� ������ �� 
				{
					break;
				}

				if (InputManager::GetInstance()->Getbkeyboard() == false)
				{
					_objtop.posoriginDest.x += USERDMOVE;
					_objbottom.posoriginDest.x += USERDMOVE;
				}
			}
			break;
			case E_USERSTATE_LWALK:
			{
				// ���� ��ư ������ �� ����
				RECT recclient;
				GetClientRect(Mainfrm::GethWnd(), &recclient);

				// �̹��� �����̴� �Լ� 
				Aniimage(_objtop);
				Aniimage(_objbottom);

				if (_objtop.posoriginDest.x <= recclient.left)
					// ���� ��ü�� client �̻� ���� �� �� ������ �� 
				{
					break;
				}

				if (InputManager::GetInstance()->Getbkeyboard() == false)
				{
					_objtop.posoriginDest.x -= USERDMOVE;
					_objbottom.posoriginDest.x -= USERDMOVE;
				}
			}
			break;
			case E_USERSTATE_JUMP:
			{
				// �̹��� �����̴� �Լ� 
				Aniimage(_objtop);
				//Aniimage(_objbottom);
			}
			break;
			case E_GUNSTATE_NORMAL:
			{
				// �߻� ��ư ������ ���� �Լ� 
				RECT recclient;
				GetClientRect(Mainfrm::GethWnd(), &recclient);

				if (_objtop.posoriginDest.x <= recclient.left + 30)
					// ���� ��ü�� client + �Ѿ� ������ ���� Ŭ ���, ��ü �ı�
				{
					// �ı����ֱ� 
					break;
				}

				// �̹��� �����̴� �Լ� 
				Aniimage(_objtop);
			}
			break;
		}

		// ���� �ð��� ���� �ð����� ��ü
		m_dPrevTime = m_dcurTime;

	}

	return;
}*/

void Object::hitbox(RECT _rec1, RECT _rec2)
{
	// ��Ʈ���� 
	IntersectRect(NULL, &_rec1, &_rec2);

	return;
}