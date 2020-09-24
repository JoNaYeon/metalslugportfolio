#pragma once
#include "ObjectImage.h"
//#include "framework.h"


class Background :
	public Object
{
private:
	ObjectImage m_obimg1;
	ObjectImage m_obimg2;

	// 배경화면 구조체
	DISPLAYINFO m_DisBG;
	IMAGEINFO m_ImgBG;

	// 객체의 위치 상태를 표시하는 E_OBJECTMOVEPOS enum을 담을 int 변수
	int m_objPosState;

	// 배경화면이 움직인 정도를 담는 POINT
	POINT ptTileMove;

	//std::vector<POINT> m_vecpos;



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
	//void BackgroundTile(int _i);
	// 개체들의 y의 위치를 잡아줄 함수
	//int GetTileY(Object* _obj);
	/*void BackgroundTileset(int _i, int _iposy1, int _iposy2, 
		int _iposx1, int _iposx2, RECT* _rec);*/
	//POINT GetRatio(int iwidth, int iheight);

	bool bObjDead();

	// 배경 이동 함수 
	void BackgroundMove(E_USERSTATE _e_state);
	DISPLAYINFO GetBG() { return m_DisBG; };

	//std::vector<POINT>* GetBGTilevecpt() { return &m_vecpos; };
	
};

 