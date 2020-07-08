#pragma once
//#include <vector>
//#include "framework.h"
#include "define.h"


class Object;

class RendManager
	// ������Ʈ�� ��µǴ� ���� ���� 
{
private:
	// Rend �Ŵ��� ���θ� ������ instance
	static RendManager* m_pinstance;
	// ������Ʈ�� �������� ���� ����
	std::vector<Object*> m_vecRendObj[EOBJECT_OBJNUM];
	// ������ ũ�� ���� RECT ����
	RECT m_recClient;
	 
	// ������
	RendManager()
	{
		m_recClient = { 0, 0, 0, 0 };
	};
	// �Ҹ���
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
	// Ư�� vector�� ����ִ� �� �����Ҵ� �����Ͽ� Object �����ֱ�
	void DeleteVector(E_OBJECT e_obj);
};
