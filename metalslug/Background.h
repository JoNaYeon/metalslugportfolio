#pragma once
#include "ObjectImage.h"
//#include "framework.h"


class Background :
	public Object
{
private:
	ObjectImage m_obimg1;
	ObjectImage m_obimg2;
	POINT pBGsize;

	int m_ibgTile1;
	int m_ibgTile2;

public:

	// class 선언하려면 public 해야 됨
	// 생성자
	Background();
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
	// 오브젝트 출력
	void Render(HDC& _hdc, HWND& _hWnd);
	// 오브젝트 파괴
	void Destroy();
	// 타일을 깔아 줄 함수
	void BackgroundTile(HDC _hdc, int _itilemove);
	POINT GetRatio(int iwidth, int iheight);

	bool bObjDead();
};

 