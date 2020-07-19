#pragma once
//#include <vector>
//#include "framework.h"
/*#include "define.h"


class Object;

class ObjManager
	// 오브젝트가 출력되는 것을 관리 
{
private:
	// Rend 매니저 내부를 조종할 instance
	static ObjManager* m_pinstance;
	// 오브젝트를 종류별로 담을 백터
	std::vector<Object*> m_vecRendObj[EOBJECT_OBJNUM];
	// 윈도우 크기 담을 RECT 변수
	RECT m_recClient;

	//  objcet의 vector를 담을 iter
	std::vector<Object*>::iterator m_Rendobjiter;
	 
	// 생성자
	ObjManager()
	{
		m_recClient = { 0, 0, 0, 0 };
	};
	// 소멸자
	virtual ~ObjManager()
	{

	}
public:
	static ObjManager* GetInstance();
	static void Create();
	void Destroy();
	void Rend(HWND& _hWnd);
	void SetVector(Object* _object, E_OBJECT _Eobjectkind);
	RECT GetRect();
	void SetRect(RECT _recClient);
	// 특정 vector에 들어있는 값 동적할당 해제하여 Object 지워주기
	void DeleteVector(E_OBJECT e_obj);
};
*/