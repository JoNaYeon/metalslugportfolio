#include "ObjectImage.h"


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
void ObjectImage::Render(HDC& _hdc, HWND& _hWnd)
{
    return;
}

// 오브젝트 파괴
void ObjectImage::Destroy()
{
    return;
}

// 이미지를 뿌려줄 함수
void ObjectImage::ImageLoading(HDC& _hMemdc, RECT _recClientImgSize, HDC& _hImage, POINT _recImageposition, POINT _pImagesize)
{
    // 이미지 뿌려주기
    TransparentBlt(_hMemdc, position.x, position.y, _recClientImgSize.right / 0.49, _recClientImgSize.bottom, _hImage,
        _recImageposition.x, _recImageposition.y, _pImagesize.x, _pImagesize.y, RGB(000, 255, 000));
    //Rectangle(_hMemdc, 100, 200, 500, 600);
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