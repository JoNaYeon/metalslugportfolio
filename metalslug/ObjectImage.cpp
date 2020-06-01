#include "ObjectImage.h"
#include "framework.h"
#include "metalslug.h"
#include "define.h"


// 오브젝트 초기화
void ObjectImage::Init()
{
    return;
}

// 오브젝트 움직임
void ObjectImage::Run()
{
    return;
}

// 오브젝트 출력 
void ObjectImage::Render()
{
    return;
}

// 오브젝트 파괴
void ObjectImage::Destroy()
{
    return;
}


HDC ObjectImage::ImageLoading(HWND _hWnd, HDC _hdc, HDC _hMemdc, HINSTANCE _hInst, RECT _recClient,
    HBITMAP _hBit, int ixoriginSrc, int iyoriginSrc, int iwSrc, int ihSrc)
{
    // 이미지 뿌려주기
    TransparentBlt(_hdc, 0, 0, _recClient.right, _recClient.bottom,
        _hMemdc, ixoriginSrc, iyoriginSrc, iwSrc, ihSrc, RGB(000, 255, 000));

	return _hMemdc;
}


void ObjectImage::ImageSize()
{
    return;
}