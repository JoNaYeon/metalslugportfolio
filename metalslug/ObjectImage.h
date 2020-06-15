#pragma once
#include "Object.h"
#include "framework.h"
//#include "metalslug.h"
#include "define.h"

class ObjectImage :
    public Object
{
private:
    // 좌표를 가질 POINT 변수
    POINT position;

public:
    ObjectImage()
    {
        position.x = 0;
        position.y = 0;
    }
    ~ObjectImage()
    {

    }

//    HDC ImageLoading(HWND _hWnd, HDC _hdc, HDC hMemdc, HINSTANCE _hInst, RECT _recClient,
//        HBITMAP _hBit, int istartpointx, int istartpointy, int ixoriginSrc, int iyoriginSrc, int iwSrc, int ihSrc);

    void ImageLoading(HDC& _hMemdc, RECT _recClientImgSize, HDC& _hImage, POINT _recImageposition, POINT _pImagesize);

    void ImageSize();

    // 오브젝트 초기화
    void Init();
    // 오브젝트 움직임
    void Run();
    // 오브젝트 출력 
    void Render(HDC& _hdc, HWND& _hWnd);
    // 오브젝트 파괴
    void Destroy();

    // 좌표를 내보낼 함수
    POINT GetPosition();
    // 좌표를 받을 함수
    void SetPosition(POINT _pposition);
};

