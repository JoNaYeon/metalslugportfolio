#pragma once
#include "framework.h"

class InputManager
	// 사용자의 입력값을 관리
{
private:
	// Input 매니저 내부를 조종할 instance
	static InputManager* m_pinstance;
	// 생성자
	InputManager()
	{

	};
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
};

