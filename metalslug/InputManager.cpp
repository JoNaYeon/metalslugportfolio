#include "InputManager.h"
#include <stdio.h>
#include "Mainfrm.h"

// 초기화
InputManager* InputManager::m_pinstance = NULL;

InputManager::InputManager()
{
	m_bkeyboard = true;
};

InputManager* InputManager::GetInstance()
{
	if (m_pinstance == NULL)
	{
		m_pinstance = new InputManager;
	}
	return m_pinstance;
};

void InputManager::Create()
{
	if (m_pinstance == NULL)
	{
		m_pinstance = new InputManager;
	}
	return;
};

void InputManager::Destroy()
{
	if (m_pinstance != NULL)
	{
		delete m_pinstance;
		m_pinstance = NULL;
	}
	return;
};

void InputManager::DeleteData()
{
	return;
};

void InputManager::Run()
{ 
	return;
};


bool InputManager::Keyboard(E_KEY _E_KEY)
{
	// Key를 받아서 return값 설정해주기
	switch (_E_KEY)
	{
		// 스페이스 받을 경우 Scene 넘어가기
		case E_KEYSPACE:
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		break;
		case E_KEYLEFT:
		{
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				if (m_bkeyboard)
				{
					m_bkeyboard = false;
				}
				return true;
			}
			else
			{
				m_bkeyboard = true;
				return false;
			}
		}
		break;
		case E_KEYRIGHT:
		{
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				if (m_bkeyboard)
				{
					m_bkeyboard = false;
				}
				return true;
			}
			else
			{
				m_bkeyboard = true;
				return false;
			}
		}
		break;
		case E_KEYJUMP:
		{
			// 0x44 = D
			if (GetAsyncKeyState(0x44) & 0x8000)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		break;
		case E_KEYFIRE:
		{
			// 0x41 = A
			if (GetAsyncKeyState(0x41) & 0x8000)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		break;
		case E_KEYBOMB:
		{
			// 0x53 = S
			if (GetAsyncKeyState(0x53) & 0x8000)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		break;
	}

	return false;
}