#pragma once
#include "define.h"


class Object;

class ObjManager
	// 오브젝트가 생성되고 파괴되는 것을 관리
{
private:
	// DB 매니저 내부를 조종할 instance
	static ObjManager* m_pinstance;
	// 오브젝트를 종류별로 담을 백터
	std::vector<Object*> m_vecBackObj[EOBJECT_OBJNUM];

	//  objcet의 vector를 담을 iter
	std::vector<Object*>::iterator m_DBobjiter;

	// 윈도우 크기 담을 RECT 변수
	RECT m_recClient;

	// 생성자
	ObjManager();
	// 소멸자
	virtual ~ObjManager()
	{

	}
public:
	// static 함수 : class의 선언 없이 사용이 가능.
	static ObjManager* GetInstance();
	static void Create();
	void Destroy();

	void SetVector(Object* _object, E_OBJECT _Eobjectkind);
	void DeleteData();

	RECT GetRect();
	void SetRect(RECT _recClient);

	// DB
	void Run();

	// Rend
	void Rend(HWND& _hWnd);

	std::vector<Object*> GetVector(E_OBJECT _e_obj);
};

