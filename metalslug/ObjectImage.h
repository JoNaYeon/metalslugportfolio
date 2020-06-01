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

    // ������Ʈ �ʱ�ȭ
    void Init();
    // ������Ʈ ������
    void Run();
    // ������Ʈ ��� 
    void Render();
    // ������Ʈ �ı�
    void Destroy();
};

