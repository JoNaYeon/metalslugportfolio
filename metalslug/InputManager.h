#pragma once
#include "framework.h"

class InputManager
	// ������� �Է°��� ����
{
private:
	// Input �Ŵ��� ���θ� ������ instance
	static InputManager* m_pinstance;
	// ������
	InputManager()
	{

	};
	// �Ҹ���
	virtual ~InputManager()
	{

	}
public:
	static InputManager* GetInstance();
	static void Create();
	static void Destroy();
	void DeleteData();
	void Run();
};

