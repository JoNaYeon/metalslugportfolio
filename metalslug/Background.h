#pragma once
//#include "Object.h"
#include "ObjectImage.h"
//#include "framework.h"
//#include "metalslug.h"
//#include "define.h"
#include "RendManager.h"



class Background :
	public Object
{
private:
	// 이미지의 사이즈를 저장할 변수
	POINT m_pimagesize;
	// 이미지 내부의 출력 스타트 좌표값
	POINT m_pimagestartposition;
	// 이미지의 좌표를 지정해줄 변수
	POINT m_pbackgroundposition1;
	POINT m_pbackgroundposition2;
	ObjectImage m_obimg1;
	ObjectImage m_obimg2;
	HWND m_hWnd;

public:
	enum backgroundsize
	{
		BACKGROUNDX = 740,
		BACKGROUNDY = 220
	};
	enum backgroundposition
	{
		BACKGROUNDPOSX = 960,
		BACKGROUNDPOSY = 180
	};

	// class 선언하려면 public 해야 됨
	// 생성자
	Background(HWND _hWnd)
	{
		m_hWnd = _hWnd;
		m_pimagesize = { 0, };
		m_pimagestartposition = { 0, };
		m_pbackgroundposition1 = { 0, 0 };
		m_pbackgroundposition2 = { 3 * BACKGROUNDX, 0 };
	};
	// 소멸자
	virtual ~Background()
	{

	};

	// 오브젝트 초기화
	void Init();
	// 오브젝트 움직임
	// 순수가상함수는 무조건 오버라이딩 되어야 하는데 오버라이딩이 
	// 매개변수가 다르면 안 되므로 매개변수 다른 함수를 정의해주고 싶으면
	// 오버라이딩 한 함수를 넣은 뒤에 오버로딩 해줘야 함. 
	void Run();
	//void Run(HWND _hWnd, HDC& _hdc, HINSTANCE _hInst, RECT _recClient);
	// 오브젝트 출력
	void Render(HDC& _hdc, HWND& _hWnd);
	// 오브젝트 파괴
	void Destroy();
};

 