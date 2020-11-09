#pragma once
//#include "framework.h"
#include "define.h"

class InputManager
	// 사용자의 입력값을 관리
{
private:
	// Input 매니저 내부를 조종할 instance
	static InputManager* m_pinstance;
	// 키보드가 눌리고 안 눌리고를 표시할 bool 변수
	bool m_bkeyboard;

	// 생성자
	InputManager();
	// 소멸자
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

