#pragma once
#include "Object.h"
#include "framework.h"

class ObjectImage :
    public Object
{
public:
    ObjectImage()
    {

    }
    ~ObjectImage()
    {

    }

    HDC ImageLoading(HWND _hWnd, HDC _hdc, HDC hMemdc, HINSTANCE _hInst, RECT _recClient,
        HBITMAP _hBit, int ixoriginSrc, int iyoriginSrc, int iwSrc, int ihSrc);
    void ImageSize();

    // 오브젝트 초기화
    void Init();
    // 오브젝트 움직임
    void Run();
    // 오브젝트 출력 
    void Render();
    // 오브젝트 파괴
    void Destroy();
};

