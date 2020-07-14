#pragma once
#include "define.h"


class Object;

class DBManager
	// ������Ʈ�� �����ǰ� �ı��Ǵ� ���� ����
{
private:
	// DB �Ŵ��� ���θ� ������ instance
	static DBManager* m_pinstance;
	// ������Ʈ�� �������� ���� ����
	std::vector<Object*> m_vecBackObj[EOBJECT_OBJNUM];

	//  objcet�� vector�� ���� iter
	std::vector<Object*>::iterator m_DBobjiter;

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

	void SetVector(Object* _object, E_OBJECT _Eobjectkind);
};

