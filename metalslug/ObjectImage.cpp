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


/*HDC ObjectImage::ImageLoading(HWND _hWnd, HDC _hdc, HDC _hMemdc, HINSTANCE _hInst, RECT _recClient,
    HBITMAP _hBit, int istartpointx, int istartpointy, int ixoriginSrc, int iyoriginSrc, int iwSrc, int ihSrc)
{
    // �̹��� �ѷ��ֱ�
    TransparentBlt(_hdc, istartpointx, istartpointy, _recClient.right, _recClient.bottom,
        _hMemdc, ixoriginSrc, iyoriginSrc, iwSrc, ihSrc, RGB(000, 255, 000));

	return _hMemdc;
}*/

// �̹����� �ѷ��� �Լ�
void ObjectImage::ImageLoading(HDC _hMemdc, RECT _recClientImgSize, HDC _hImage, POINT _recImageposition, POINT _pImagesize)
{
    // �̹��� �ѷ��ֱ�
    TransparentBlt(_hMemdc, position.x, position.y, _recClientImgSize.right, _recClientImgSize.bottom, _hImage,
        _recImageposition.x, _recImageposition.y, _pImagesize.x, _pImagesize.y, RGB(000, 255, 000));

    return;
}


void ObjectImage::ImageSize()
{
    return;
}

// ��ǥ�� ������ �Լ�
POINT ObjectImage::GetPosition()
{
    return position;
}

// ��ǥ�� ���� �Լ�
void ObjectImage::SetPosition(POINT _pposition)
{
    position = _pposition;
    return;
}