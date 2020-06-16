#pragma once

#include "define.h"
#include "framework.h"

class Scene
{
public:

	static HWND m_hWnd;
	static HDC m_hdc;

	// 최고 추상클래스 이기 때문에 생성자/소멸자 모두 public
	Scene()
	{
	}
	virtual ~Scene()
	{

	} 

	virtual void ObjectProduce() PURE;
	virtual void ObjectRend() PURE;
	virtual void ObjectDestroy() PURE;

	virtual void BackgroundProduce() PURE;
	virtual void BackgroundRend() PURE;
	virtual void BackgroundDestroy() PURE;

	virtual void SethWnd(HWND _hWnd) PURE;
	virtual HWND GethWnd(void) PURE;
	virtual void Sethdc(HDC _hdc) PURE;
	virtual HDC Gethdc(void) PURE;

};