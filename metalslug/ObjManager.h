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
	std::vector<Object*> m_vecBackObj[EOBJECT_OBJNUM];

	//  objcet�� vector�� ���� iter
	std::vector<Object*>::iterator m_DBobjiter;

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

	// DB
	void Run();

	// Rend
	void Rend(HWND& _hWnd);

	std::vector<Object*> GetVector(E_OBJECT _e_obj);
};

