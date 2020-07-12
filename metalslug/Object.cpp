#include "Object.h"
#include "Mainfrm.h"

DWORD Object::m_dPrevTime = timeGetTime();


// 생성자
Object::Object()
{
	m_iobjstate = -1;
	m_dcurTime = timeGetTime();
	m_fdelay = 1;
};

void Object::Aniimage(ST_OBJECT& _obj)
{
	// top 반응
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
		// 멈춤 상태
	case E_USERSTATE_IDLE:
	{
		// 이미지 움직이는 함수 
		Aniimage(_obj);
	}
	break;
	case E_USERSTATE_RWALK:
	{
		// 오른쪽 버튼 눌렀을 때 반응
		RECT recclient;
		GetClientRect(Mainfrm::GethWnd(), &recclient);

		// 이미지 움직이는 함수 
		Aniimage(_obj);

		if (_obj.posoriginDest.x >= (recclient.right - (_obj.recDest.right * _obj.iWidthnum)))
		// 만약 개체가 client 이상 가면 나갈 수 없도록 함 
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
		// 왼쪽 버튼 눌렀을 때 반응
		RECT recclient;
		GetClientRect(Mainfrm::GethWnd(), &recclient);

		// 이미지 움직이는 함수 
		Aniimage(_obj);

		if (_obj.posoriginDest.x <= recclient.left)
		// 만약 개체가 client 이상 가면 갈 수 없도록 함 
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
		// 이미지 움직이는 함수 
		Aniimage(_obj);
	}
	break;
	case E_GUNSTATE_NORMAL:
	{
		// 발사 버튼 눌렀을 때의 함수 
		RECT recclient;
		GetClientRect(Mainfrm::GethWnd(), &recclient);

		// 이미지 움직이는 함수 
		Aniimage(_obj);

		_obj.posoriginDest.x += _obj.iobjmove;
	}
	break;
	}

	return;
}



void Object::hitbox(RECT _rec1, RECT _rec2)
{
	// 히트판정 
	IntersectRect(NULL, &_rec1, &_rec2);

	return;
}

// iter 에 vector 넣기
bool Object::GetIter(std::vector<Object*>& _obj)
{

	return false;
};


// object가 화면 밖으로 나가면
void Object::ObjectOut(Object& _obj, std::vector<Object*>& _vecobj)
{
	if (_obj.m_bullet.posoriginDest.x >= RendManager::GetInstance()->GetRect().right)
	{
		m_objiter = _vecobj.begin();

		// for 문을 bullet vector 의 사이즈만큼 돌면서 iter을 하나씩 증가.
		for (int i = 0; i < _vecobj.size(); i++)
		{
			// 만약 i번째 bullet vector 가 현재의 bullet과 같다면 
			//현재 iter가 가리키는 bullet을 삭제하고 다음 iter를 가리키게 함
			if (_vecobj[i] == &_obj)
			{
				_vecobj[i]->Destroy();
				m_objiter = _vecobj.erase(m_objiter);
			}
			else
			{
				// iter 가 가리키는 부분 하나씩 옮기기
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