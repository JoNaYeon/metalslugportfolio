#include "ObjectImage.h"
#include "framework.h"
#include "metalslug.h"
#include "define.h"


// ������Ʈ �ʱ�ȭ
void ObjectImage::Init()
{
    return;
}

// ������Ʈ ������
void ObjectImage::Run()
{
    return;
}

// ������Ʈ ��� 
void ObjectImage::Render()
{
    return;
}

// ������Ʈ �ı�
void ObjectImage::Destroy()
{
    return;
}


HDC ObjectImage::ImageLoading(HWND _hWnd, HDC _hdc, HDC _hMemdc, HINSTANCE _hInst, RECT _recClient,
    HBITMAP _hBit, int ixoriginSrc, int iyoriginSrc, int iwSrc, int ihSrc)
{
    // �̹��� �ѷ��ֱ�
    TransparentBlt(_hdc, 0, 0, _recClient.right, _recClient.bottom,
        _hMemdc, ixoriginSrc, iyoriginSrc, iwSrc, ihSrc, RGB(000, 255, 000));

	return _hMemdc;
}


void ObjectImage::ImageSize()
{
    return;
}