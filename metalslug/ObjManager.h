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
	std::vector<Object*> m_vecObj[EOBJECT_OBJNUM];

	//  objcet의 vector를 담을 iter
	std::vector<Object*>::iterator m_DBobjiter;

	// tile 을 담는 vector 변수 
	//std::vector<RECT> m_vecBGpos;
	std::vector<POINT> m_vecpos;

	// Tile 생성 여부를 확인해주는 bool 변수
	bool m_bTile;
	int m_itile;

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

	//std::vector<RECT>* GetvecBGpos() { return &m_vecBGpos; };

	// DB
	void Run();
	// Rend
	void Rend(HWND& _hWnd);

	std::vector<Object*> GetVector(E_OBJECT _e_obj);

	// 각 Object 들의 HitBox들이 부딪힌 것을 체크해주는 함수
	void CollisionCheck();
	// 유저의 움직임에 따라서 background 를 움직여주는 함수
	void BackgroundMove();

	// 타일 깔아주는 함수
	//void BackgroundTileSet(E_OBJECT _Eobj, std::vector<Object*> _objvec);
	// 선 깔아주는 함수
	void BackgroundLineCollision(E_OBJECT _Eobj);
	// 타일을 움직여주는 함수
	void TileMove(E_USERSTATE _e_state);
	std::vector<POINT>* GetTile() { return &m_vecpos; };

};

