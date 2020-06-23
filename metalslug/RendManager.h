#pragma once
#include "define.h"
#include "framework.h"
#include "Object.h"
#include <vector>


class Object;

class RendManager
	// 오브젝트가 출력되는 것을 관리 
{
private:
	// Rend 매니저 내부를 조종할 instance
	static RendManager* m_pinstance;
	// 오브젝트를 종류별로 담을 백터
	std::vector<Object*> m_vecRendObj[EOBJECT_OBJNUM];
	// 윈도우 크기 담을 RECT 변수
	RECT m_recClient;

	// 생성자
	RendManager()
	{
		m_recClient = { NULL, };
	};
	// 소멸자
	virtual ~RendManager()
	{

	}
public:
	static RendManager* GetInstance();
	static void Create();
	void Destroy();
	void Rend(HWND& _hWnd);
	void SetVector(Object* _object, E_OBJECT _Eobjectkind);
	RECT GetRect();
	void SetRect(RECT _recClient);
	// 특정 vector에 들어있는 값 동적할당 해제하여 Object 지워주기
	void DeleteVector(E_OBJECT e_obj);
};

