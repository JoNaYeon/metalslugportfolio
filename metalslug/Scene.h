#pragma once

#include "define.h"

class Scene
{
protected:
	// ���� �ӽ�, ���� 
	int m_iscenestate;
	// ���� ���� ���� ����
	Scene* m_nextscene;

public:
	// �ְ� �߻�Ŭ���� �̱� ������ ������/�Ҹ��� ��� public
	Scene()
	{
		m_iscenestate = 0;
		m_nextscene = 0;
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

	virtual Scene* Next() PURE;

};