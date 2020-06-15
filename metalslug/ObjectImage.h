#pragma once
#include "Object.h"
#include "framework.h"
//#include "metalslug.h"
#include "define.h"

class ObjectImage :
    public Object
{
private:
    // ��ǥ�� ���� POINT ����
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

    // ������Ʈ �ʱ�ȭ
    void Init();
    // ������Ʈ ������
    void Run();
    // ������Ʈ ��� 
    void Render(HDC& _hdc, HWND& _hWnd);
    // ������Ʈ �ı�
    void Destroy();

    // ��ǥ�� ������ �Լ�
    POINT GetPosition();
    // ��ǥ�� ���� �Լ�
    void SetPosition(POINT _pposition);
};

