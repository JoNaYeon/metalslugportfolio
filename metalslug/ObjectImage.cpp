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


/*HDC ObjectImage::ImageLoading(HWND _hWnd, HDC _hdc, HDC _hMemdc, HINSTANCE _hInst, RECT _recClient,
    HBITMAP _hBit, int istartpointx, int istartpointy, int ixoriginSrc, int iyoriginSrc, int iwSrc, int ihSrc)
{
    // 이미지 뿌려주기
    TransparentBlt(_hdc, istartpointx, istartpointy, _recClient.right, _recClient.bottom,
        _hMemdc, ixoriginSrc, iyoriginSrc, iwSrc, ihSrc, RGB(000, 255, 000));

	return _hMemdc;
}*/

// 이미지를 뿌려줄 함수
void ObjectImage::ImageLoading(HDC _hMemdc, RECT _recClientImgSize, HDC _hImage, POINT _recImageposition, POINT _pImagesize)
{
    // 이미지 뿌려주기
    TransparentBlt(_hMemdc, position.x, position.y, _recClientImgSize.right, _recClientImgSize.bottom, _hImage,
        _recImageposition.x, _recImageposition.y, _pImagesize.x, _pImagesize.y, RGB(000, 255, 000));

    return;
}


void ObjectImage::ImageSize()
{
    return;
}

// 좌표를 내보낼 함수
POINT ObjectImage::GetPosition()
{
    return position;
}

// 좌표를 받을 함수
void ObjectImage::SetPosition(POINT _pposition)
{
    position = _pposition;
    return;
}