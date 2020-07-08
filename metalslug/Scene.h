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

	Scene* GetNextScene() { return m_nextscene; };
	void SetNextScene(Scene* _scene) { m_nextscene = _scene; return; };

	virtual void NextScene() PURE;
	//static Scene* GetNext() { return m_nextscene; };
};