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
void ObjectImage::ImageLoading(HDC& _hMemdc, RECT _recClientImgSize, HDC& _hImage, 
    POINT _recImageposition, POINT _pImagesize)
{
    // �̹��� �ѷ��ֱ�
    TransparentBlt(_hMemdc, m_position.x, m_position.y, _recClientImgSize.right,
        _recClientImgSize.bottom, _hImage, _recImageposition.x, _recImageposition.y, 
        _pImagesize.x, _pImagesize.y, RGB(000, 255, 000));
    return;
}


void ObjectImage::ImageSize()
{
    return;
}

// ��ǥ�� ������ �Լ�
POINT ObjectImage::GetPosition()
{
    return m_position;
}

// ��ǥ�� ���� �Լ�
void ObjectImage::SetPosition(POINT _pposition)
{
    m_position = _pposition;
    return;
}


bool ObjectImage::bObjDead()
{
    return false;
}