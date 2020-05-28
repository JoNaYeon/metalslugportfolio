#include "RendManager.h"
#include "framework.h"
#include "Object.h"

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
		// �� �� instance (�����Ҵ�) ����
		delete m_pinstance;
		m_pinstance = NULL;

		for (int i = 0; i < EOBJECT_OBJNUM; i++)
		{
			m_vecRendObj[i].clear();
		}
	}
	return;
};

void RendManager::Rend()
{
	for (int i = 0; i < EOBJECT_OBJNUM; i++)
	{
		for (int j = 0; j < m_vecRendObj[i].size(); j++)
		{
			// ���� ���ο� �����Ͽ� Object class �� ���� �Լ� (Render) ���
			(m_vecRendObj[i])[j]->Render();
		}
	}
	return;
};