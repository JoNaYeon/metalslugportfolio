#pragma once

#include "define.h"

class Scene
{
protected:
	// ���� �ӽ�, ���� 
	int m_iscenestate;
	// ���� ���� ���� ����
	static Scene* m_nextscene;

public:

	// �ְ� �߻�Ŭ���� �̱� ������ ������/�Ҹ��� ��� public
	Scene()
	{
		m_iscenestate = 0;
		m_nextscene = NULL;
	}
	virtual ~Scene()
	{

	} 

	virtual void Create() PURE;
	virtual void Rend() PURE;
	virtual void Destroy() PURE;

	int GetState()
	{
		return m_iscenestate;
	}

<<<<<<< HEAD
	//virtual Scene* Next() PURE;

=======
	virtual void NextScene() PURE;
	static Scene* GetNext() { return m_nextscene; };
>>>>>>> c4b6101c5499d62d22223c1428cc6798c773b7bb
};