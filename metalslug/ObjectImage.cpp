#include "ObjectImage.h"


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
void ObjectImage::Render(HDC& _hdc, HWND& _hWnd)
{
    return;
}

// ������Ʈ �ı�
void ObjectImage::Destroy()
{
    return;
}

// �̹����� �ѷ��� �Լ�
void ObjectImage::ImageLoading(HDC& _hMemdc, RECT _recClientImgSize, HDC& _hImage, POINT _recImageposition, POINT _pImagesize)
{
    // �̹��� �ѷ��ֱ�
    TransparentBlt(_hMemdc, position.x, position.y, _recClientImgSize.right / 0.49, _recClientImgSize.bottom, _hImage,
        _recImageposition.x, _recImageposition.y, _pImagesize.x, _pImagesize.y, RGB(000, 255, 000));
    //Rectangle(_hMemdc, 100, 200, 500, 600);
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