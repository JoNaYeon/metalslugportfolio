#pragma once

#include "define.h"

class Scene
{
protected:
	// 상태 머신, 패턴 
	int m_iscenestate;
	// 다음 씬을 담을 변수
	Scene* m_nextscene;

public:
	// 최고 추상클래스 이기 때문에 생성자/소멸자 모두 public
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