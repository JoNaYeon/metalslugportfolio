#pragma once
#include "define.h"


class Object;

class ObjManager
	// ������Ʈ�� �����ǰ� �ı��Ǵ� ���� ����
{
private:
	// DB �Ŵ��� ���θ� ������ instance
	static ObjManager* m_pinstance;
	// ������Ʈ�� �������� ���� ����
	std::vector<Object*> m_vecObj[EOBJECT_OBJNUM];

	//  objcet�� vector�� ���� iter
	std::vector<Object*>::iterator m_DBobjiter;

	// tile �� ��� vector ���� 
	//std::vector<RECT> m_vecBGpos;
	std::vector<POINT> m_vecpos;

	// Tile ���� ���θ� Ȯ�����ִ� bool ����
	bool m_bTile;
	int m_itile;

	// ������ ũ�� ���� RECT ����
	RECT m_recClient;

	// ������
	ObjManager();
	// �Ҹ���
	virtual ~ObjManager()
	{

	}
public:
	// static �Լ� : class�� ���� ���� ����� ����.
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

	// �� Object ���� HitBox���� �ε��� ���� üũ���ִ� �Լ�
	void CollisionCheck();
	// ������ �����ӿ� ���� background �� �������ִ� �Լ�
	void BackgroundMove();

	// Ÿ�� ����ִ� �Լ�
	//void BackgroundTileSet(E_OBJECT _Eobj, std::vector<Object*> _objvec);
	// �� ����ִ� �Լ�
	void BackgroundLineCollision(E_OBJECT _Eobj);
	// Ÿ���� �������ִ� �Լ�
	void TileMove(E_USERSTATE _e_state);
	std::vector<POINT>* GetTile() { return &m_vecpos; };

};

