#pragma once
#include "define.h"
#include <vector>

class Object;

class RendManager
	// ������Ʈ�� ��µǴ� ���� ���� 
{
private:
	// Rend �Ŵ��� ���θ� ������ instance
	static RendManager* m_pinstance;
	// ������Ʈ�� �������� ���� ����
	std::vector<Object*> m_vecRendObj[EOBJECT_OBJNUM];

	// ������
	RendManager()
	{

	};
	// �Ҹ���
	virtual ~RendManager()
	{

	}
public:
	static RendManager* GetInstance();
	static void Create();
	void Destroy();
	void Rend();
};

