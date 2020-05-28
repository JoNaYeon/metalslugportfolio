#include "InputManager.h"
#include "framework.h"

// √ ±‚»≠
InputManager* InputManager::m_pinstance = NULL;

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