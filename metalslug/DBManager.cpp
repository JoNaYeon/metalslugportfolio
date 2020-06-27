#include "DBManager.h"
#include "Object.h"

// �ʱ�ȭ
DBManager* DBManager::m_pinstance = NULL;

DBManager* DBManager::GetInstance()
{
	// m_pinstance �� �ƹ��͵� ���� ���, ����
	if (m_pinstance == NULL)
	{
		m_pinstance = new DBManager;
	}
	return m_pinstance;
};

void DBManager::Create()
{
	// m_pinstance �� �ƹ��͵� ���� ���, ����
	if (m_pinstance == NULL)
	{
		m_pinstance = new DBManager;
	}	
	return;
};

void DBManager::Destroy()
{
	// �� �� instance (�����Ҵ�) ����
	delete m_pinstance;
	m_pinstance = NULL;

	// Object (�����Ҵ�) delete ���� �Լ� ȣ��
	DeleteData();

	return;
};

void DBManager::DeleteData()
{
	// m_pinstance �� ���� ������� ���, delete
	if (m_pinstance != NULL)
	{
		for (int i = 0; i < EOBJECT_OBJNUM; i++)
		{
			for (int j = 0; j < m_vecBackObj[i].size(); j++)
			{
				delete (m_vecBackObj[i])[j];
				(m_vecBackObj[i])[j] = NULL;
			}
		}
	}
	return;
};

void DBManager::Run()
{
	for (int i = 0; i < EOBJECT_OBJNUM; i++)
	{
		for (int j = 0; j < m_vecBackObj[i].size(); j++)
		{
			// ���� ���ο� �����Ͽ� Object class �� ���� �Լ� (Run) ���
			(m_vecBackObj[i])[j]->Run();
		}
	}
	return;
};

void DBManager::SetVector(Object* _object, E_OBJECT _Eobjectkind)
{
	// vector ptr �� �־ Rend() �� �� �ֵ���.
	m_vecBackObj[_Eobjectkind].push_back(_object);

	return;
}