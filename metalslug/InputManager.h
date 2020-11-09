#pragma once
//#include "framework.h"
#include "define.h"

class InputManager
	// ������� �Է°��� ����
{
private:
	// Input �Ŵ��� ���θ� ������ instance
	static InputManager* m_pinstance;
	// Ű���尡 ������ �� ������ ǥ���� bool ����
	bool m_bkeyboard;

	// ������
	InputManager();
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

	bool Keyboard(E_KEY _E_KEY);
	bool Getbkeyboard() { return m_bkeyboard; };
};

