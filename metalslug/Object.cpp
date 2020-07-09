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

		if (_obj.posoriginDest.x >= (recclient.right - (_obj.recDest.right * 4)))
		// 만약 개체가 client 이상 가면 나갈 수 없도록 함 
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
			_obj.posoriginDest.x -= USERDMOVE;
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

		if (_obj.posoriginDest.x <= recclient.left + BULLETSIZE)
		// 만약 개체가 client + 총알 사이즈 보다 클 경우, 개체 파괴
		{
			// 파괴해주기 
			break;
		}

		// 이미지 움직이는 함수 
		Aniimage(_obj);

		_obj.posoriginDest.x -= BULLETMOVE;
	}
	break;
	}

	return;
}


/*void Object::Animation(HDC& _hdc, ST_OBJECT& _objtop, ST_OBJECT& _objbottom, int& _iobjstate)
{
	// 애니메이션 - ST_OBJECT 를 하나만 받아서 쓸 수 있도록 변경 

	// 시간을 받아옴
	m_dcurTime = timeGetTime();
	
	// 만약 이전 시간에서 현재 시간이 0.1float 지났을 때 
	if (m_dcurTime - m_dPrevTime >= 0.1f * m_fdelay)
	{
		switch (_iobjstate)
		{
			// 멈춤 상태
			case E_USERSTATE_IDLE:
			{
				// 이미지 움직이는 함수 
				Aniimage(_objtop);
				Aniimage(_objbottom);
			}
			break;
			case E_USERSTATE_RWALK:
			{
				// 오른쪽 버튼 눌렀을 때 반응
				RECT recclient;
				GetClientRect(Mainfrm::GethWnd(), &recclient);

				// 이미지 움직이는 함수 
				Aniimage(_objtop);
				Aniimage(_objbottom);

				if (_objtop.posoriginDest.x >= (recclient.right - (_objtop.recDest.right * 4)))
					// 만약 개체가 client 이상 가면 나갈 수 없도록 함 
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
				// 왼쪽 버튼 눌렀을 때 반응
				RECT recclient;
				GetClientRect(Mainfrm::GethWnd(), &recclient);

				// 이미지 움직이는 함수 
				Aniimage(_objtop);
				Aniimage(_objbottom);

				if (_objtop.posoriginDest.x <= recclient.left)
					// 만약 개체가 client 이상 가면 갈 수 없도록 함 
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
				// 이미지 움직이는 함수 
				Aniimage(_objtop);
				//Aniimage(_objbottom);
			}
			break;
			case E_GUNSTATE_NORMAL:
			{
				// 발사 버튼 눌렀을 때의 함수 
				RECT recclient;
				GetClientRect(Mainfrm::GethWnd(), &recclient);

				if (_objtop.posoriginDest.x <= recclient.left + 30)
					// 만약 개체가 client + 총알 사이즈 보다 클 경우, 개체 파괴
				{
					// 파괴해주기 
					break;
				}

				// 이미지 움직이는 함수 
				Aniimage(_objtop);
			}
			break;
		}

		// 이전 시간을 현재 시간으로 대체
		m_dPrevTime = m_dcurTime;

	}

	return;
}*/

void Object::hitbox(RECT _rec1, RECT _rec2)
{
	// 히트판정 
	IntersectRect(NULL, &_rec1, &_rec2);

	return;
}