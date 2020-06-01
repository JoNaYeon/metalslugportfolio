#include "Background.h"

#include "framework.h"
#include "metalslug.h"
#include "ObjectImage.h"

// ������Ʈ �ʱ�ȭ
void Background::Init()
{
	return;
};

void Background::Run()
{
    return; 
}

// ������Ʈ ������
void Background::Run(HWND _hWnd, HDC _hdc, HINSTANCE _hInst, RECT _recClient)
{
    /*static int ibitx1 = 0;
    static int ibitx2 = 0;
    static int ibitxclient = 0;
    static bool bx = false;*/

    // �׸� ������ ��ȭ�� ���� 
    static HBITMAP hBit = NULL;
    // ���� ��ȭ�� �������� ����
    HBITMAP hOldBit = NULL;
    // �޸� dc
    HDC hMemdc = CreateCompatibleDC(_hdc);

    // ��Ʈ���� hBIt�� �ѷ��ֱ�
    hBit = (HBITMAP)LoadBitmap(_hInst, MAKEINTRESOURCE(IDB_BACKGROUND1));

    // hdc�� hMemdc�� �ٲ���
    BitBlt(_hdc, 0, 0, _recClient.right, _recClient.bottom, hMemdc, 0, 0, SRCCOPY);

    // hMemdc �� �����ϰ� hOldBit�� ������ �ִ� ��ȭ���� �ٲ㼭 �����ص�
    hOldBit = (HBITMAP)SelectObject(hMemdc, hBit);

    // �̹����� ���� class �ҷ���
    ObjectImage obimg1;
    ObjectImage obimg2;

    // �̹��� �ε��� �ϴ� �Լ��� background �־���!
    hMemdc = obimg1.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, 960, 180, 460, 240);
    hMemdc = obimg2.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, 960, 180, 460, 240);

    /*
    // ibitx1 > ������
    // �������� 900�ȼ� ���� ���� ������ �׷��ֱ�
    if (ibitx1 <= 900)
    {
        
        ibitx1 += 3;
    }
    // ���� ���� ������ �������� 0���� ������ ó������ �ٽ� �׷��ְ� �ϱ� 
    else
    {
        ibitx1 = 0;
    }

    // ���࿡ ù��° �׸��� �������� 500�ȼ��� �Ѿ��� �� �ι��� �׸� �׷��ֱ� 
    if (ibitx1 >= 500)
    {
        bx = true;
    }

    // ���࿡ �ι�° �׸��� �������� Ŭ���̾�Ʈ x�� ���̺��� Ŀ�� ��쿡 
    // �ι�° �׸��� �������� Ŭ���̾�Ʈ x�� ���̷� ����
    if (ibitxclient >= _recClient.right)
    {
        ibitxclient = _recClient.right;
    }
    // ���࿡ Ŭ���̾�Ʈ x�� ���̺��� ���� ��쿡
    // �������� Ŭ���̾�Ʈ x�� ���̿��� -3�� �ؼ� �����ʿ��� �������� ���鼭 �׷�����
    else
    {
        ibitxclient = _recClient.right - ibitx2;
    }

    // ���࿡ �������� 900�ȼ����� Ŀ���� �ι�° �׸��� �׸��� �ʾ� 
    if (ibitxclient >= 900)
    {
        ibitx2 = 0;
        bx = false;
    }
    // 900�ȼ����� ������ �׷���
    else if (bx)
    {
        ibitx2 += 3;
        TransparentBlt(_hdc, ibitxclient, 0, _recClient.right, _recClient.bottom,
            hMemdc, 960, 186, 460, 236, RGB(255, 255, 255));
    }
    */
    // ���� �� �� �̹����� ��� �ű���� �ϴ� ���̴�... 


    // �ٽ� hOldBit ���� �����ֱ�
    SelectObject(hMemdc, hOldBit);

    // dc ����
    DeleteDC(hMemdc);
    // HBITMAP ����
    DeleteObject(hBit);

	return;
};

// ������Ʈ ���
void Background::Render()
{
	return;
};

// ������Ʈ �ı�
void Background::Destroy()
{
	return;
};
