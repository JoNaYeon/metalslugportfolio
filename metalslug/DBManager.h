#pragma once
#include "define.h"
/*#include "framework.h"
#include "Object.h"
#include <vector>*/

class Object;

class DBManager
	// ������Ʈ�� �����ǰ� �ı��Ǵ� ���� ����
{
private:
	// DB �Ŵ��� ���θ� ������ instance
	static DBManager* m_pinstance;
	// ������Ʈ�� �������� ���� ����
	std::vector<Object*> m_vecBackObj[EOBJECT_OBJNUM];

	// ������
	DBManager()
	{

	};
	// �Ҹ���
	virtual ~DBManager()
	{

	}
public:
	// static �Լ� : class�� ���� ���� ����� ����.
	static DBManager* GetInstance();
	static void Create();
	void Destroy();
	void DeleteData();
	void Run();
};

