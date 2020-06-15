#include "RendManager.h"

// �ʱ�ȭ
RendManager* RendManager::m_pinstance = NULL;

RendManager* RendManager::GetInstance()
{
	// create �� ���� �ʾ��� ���, ����ó��
	if (m_pinstance == NULL)
	{
		m_pinstance = new RendManager;
	}
	return m_pinstance;
};

void RendManager::Create(void)
{
	// m_pinstance �� �ƹ��͵� ������� ���� �� �����ϱ�
	if (m_pinstance == NULL)
	{
		m_pinstance = new RendManager;
	}
	return;
};

void RendManager::Destroy()
{
	// m_pinstance �� ���� ������� ���, delete
	if (m_pinstance != NULL)
	{
		// ���� �����͸� �������� �ڿ� �����Ҵ� �� �ּҰ��� ����Ű�� m_pinstance ����.
		// ������ �߸� �Ǹ� �ּҰ��� ������ �� ��� �߸��� �ּҰ��� clear() �ϰ� ���� �ִ� ������ clear�� �� ��.
		for (int i = 0; i < EOBJECT_OBJNUM; i++)
		{
			m_vecRendObj[i].clear();
		}

		// �� �� instance (�����Ҵ�) ����
		delete m_pinstance;
		m_pinstance = NULL;

	}
	return;
};

void RendManager::Rend(HDC& _hdc, HWND& _hWnd)
{
	for (int i = 0; i < EOBJECT_OBJNUM; i++)
	{
		for (int j = 0; j < m_vecRendObj[i].size(); j++)
		{
			// ���� ���ο� �����Ͽ� Object class �� ���� �Լ� (Render) ���
			(m_vecRendObj[i])[j]->Render(_hdc, _hWnd);
		}
	}
	return;
};

void RendManager::SetVector(Object* _object, E_OBJECT _Eobjectkind)
{
	// vector ptr �� �־ Rend() �� �� �ֵ���.
	// enum �ڷ������� ���
	// ������Ʈ���� �ٸ� enum ����ؼ� �������� vector�� ���� �� �ֵ���
	m_vecRendObj[_Eobjectkind].push_back(_object);

	return;
}

RECT RendManager::GetRect()
{
	return m_recClient;
}

void RendManager::SetRect(RECT _recClient)
{
	m_recClient = _recClient;
	return;
}


void RendManager::DeleteVector(E_OBJECT e_obj)
{
	std::vector<Object*>::iterator obj_iter = m_vecRendObj[e_obj].begin();

	for (; obj_iter != m_vecRendObj[e_obj].end(); obj_iter++)
	{
		Object* deleteptr = (Object*)*obj_iter;
		delete deleteptr;
		deleteptr = NULL;
	}

	m_vecRendObj[e_obj].clear();

	return;
}