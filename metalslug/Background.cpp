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
/*void Background::Run(HWND _hWnd, HDC _hdc, HINSTANCE _hInst, RECT _recClient)
{
    static int ibitx1 = 0;
    static int ibitx2 = 0;
    static int ibitxclient = 0;
    static bool bx = false;

    // �׸� ������ ��ȭ�� ���� 
    static HBITMAP hBit = NULL;
    // ���� ��ȭ�� �������� ����
    HBITMAP hOldBit = NULL;
    // �޸� dc
    HDC hMemdc = CreateCompatibleDC(_hdc);
    static RECT recbackground1 = { NULL, };
    static RECT recbackground2 = { NULL, };
    static int ix1 = 0;
    static int ix2 = 1000;
    static int istartpointx = 0;
    static int istartpointy = 0;
    static int iclientprint = 0;

    // ��Ʈ���� hBIt�� �ѷ��ֱ�
    hBit = (HBITMAP)LoadBitmap(_hInst, MAKEINTRESOURCE(IDB_BACKGROUND1));

    // hdc�� hMemdc�� �ٲ���
    BitBlt(_hdc, 0, 0, _recClient.right, _recClient.bottom, hMemdc, 0, 0, SRCCOPY);

    // hMemdc �� �����ϰ� hOldBit�� ������ �ִ� ��ȭ���� �ٲ㼭 �����ص�
    hOldBit = (HBITMAP)SelectObject(hMemdc, hBit);

    // �̹����� ���� class �ҷ���
    ObjectImage obimg1;
    ObjectImage obimg2;

    // rect�� �̹��� ��ǥ ��������
    //recbackground1 = { 950, 200 , _recClient.right , _recClient.bottom };
    //recbackground2 = { 950, 200 , _recClient.right , _recClient.bottom };
    //recbackground1 = { 1000 + ix1, 200 , 1800 , 400 };
    //recbackground2 = { 1000 + ix2, 200 , 1800 , 400 };

    // ó���� ȭ��1�� ���
    if (ix1 <= 600)
    {
        // �̹��� �ε��� �ϴ� �Լ��� background �־���!
        hMemdc = obimg1.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, istartpointx, istartpointy,
            recbackground1.left + ix1, recbackground1.top, 460, 240);
        ix1 += 3;
    }
    else if (ix2 >= 600)
    {
        //ix1 = 0;
        //ix2 = 0;
    }

    // ȭ��1�� �� �Ǿ��� ��� ȭ��2 ���
    if (ix2 < 600)
    {
        // ���� ���� �ٲ�� ��....
        if (istartpointx >= 0 || istartpointx < recbackground2.right)
        {
            istartpointx += 3;
        }
        else if(istartpointx >= recbackground2.right)
        {
            istartpointx = 0;
        }
        // �̹��� �ε��� �ϴ� �Լ��� background �־���!
        hMemdc = obimg2.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, recbackground2.right - istartpointx, istartpointy,
            recbackground1.left + ix2, recbackground1.top, 460, 240);

        if(istartpointx <= 0)
        {
            // ���⵵ �� ����
            ix2 += 3;
        }
    }
    else if (ix1 >= 600 - recbackground1.right)
    {
        ix2 = 0;
    }

    
    // ù��° �̹��� ���
    if (ix1 >= 0 && ix1 < 601)
    {
    // �̹��� �ε��� �ϴ� �Լ��� background �־���!
    hMemdc = obimg1.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, istartpointx, istartpointy,
        recbackground1.left, recbackground1.top, 460, 240);
    ix1 += 3;
    }
    else if (600 <= ix1 && 600 <= ix2)
    {
        ix2 = 0;
        iclientprint = _recClient.right;
    }
    // �ι�° �̹��� ���
    else if (ix2 >= 0 && ix2 < 601)
    {
        hMemdc = obimg2.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, _recClient.right, istartpointy,
            recbackground2.left, recbackground2.top, 460, 240);
        ix2 += 3;
        if (ix2 >= 600)
        {
            // �ʱ�ȭ ���·� �ǵ����༭ �ٽ� ó������ ������ �� �ֵ��� ���ֱ�
            ix2 = 1000;
            ix1 = 0;
            iclientprint = _recClient.right;
        }
    }

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
    
    // ���� �� �� �̹����� ��� �ű���� �ϴ� ���̴�... 

    // �ٽ� hOldBit ���� �����ֱ�
    SelectObject(hMemdc, hOldBit);

    // dc ����
    DeleteDC(hMemdc);
    // HBITMAP ����
    DeleteObject(hBit);

	return;
};*/

void Background::Run(HWND _hWnd, HDC _hdc, HINSTANCE _hInst, RECT _recClient)
{
    // �׸� ������ ��ȭ�� ���� 
    static HBITMAP hBit = NULL;
    // ���� ��ȭ�� �������� ����
    HBITMAP hOldBit = NULL;
    // �޸� dc
    HDC hMemdc = CreateCompatibleDC(_hdc);
    /*static RECT recbackground1 = { NULL, };
    static RECT recbackground2 = { NULL, };
    static int ix1 = 0;
    static int ix2 = 1000;
    static int istartpointx = 0;
    static int istartpointy = 0;
    static int iclientprint = 0;*/
    // �̹����� ����� ������ ����
    POINT pimagesize = { 700 , 230 };
    // �̹��� ������ ��� ��ŸƮ ��ǥ��
    POINT pimagestartposition = { 1000, 180 };
    // �̹����� ��ǥ�� �������� ����
    static POINT pbackgroundposition1 = { 0, };
    static POINT pbackgroundposition2 = { 0, };

    // ��Ʈ���� hBIt�� �ѷ��ֱ�
    hBit = (HBITMAP)LoadBitmap(_hInst, MAKEINTRESOURCE(IDB_BACKGROUND1));

    // hdc�� hMemdc�� �ٲ���
    BitBlt(_hdc, 0, 0, _recClient.right, _recClient.bottom, hMemdc, 0, 0, SRCCOPY);

    // hMemdc �� �����ϰ� hOldBit�� ������ �ִ� ��ȭ���� �ٲ㼭 �����ص�
    hOldBit = (HBITMAP)SelectObject(hMemdc, hBit);

    // �̹����� ���� class �ҷ���
    ObjectImage obimg1;
    ObjectImage obimg2;

    // ù��° �̹��� ���
    /*if (ix1 >= 0 && ix1 < 601)
    {
        // �̹��� �ε��� �ϴ� �Լ��� background �־���!
        hMemdc = obimg1.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, istartpointx, istartpointy,
            recbackground1.left, recbackground1.top, 460, 240);
        ix1 += 3;
    }
    else if (600 <= ix1 && 600 <= ix2)
    {
        ix2 = 0;
        iclientprint = _recClient.right;
    }
    // �ι�° �̹��� ���
    else if (ix2 >= 0 && ix2 < 601)
    {
        hMemdc = obimg2.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, _recClient.right, istartpointy,
            recbackground2.left, recbackground2.top, 460, 240);
        ix2 += 3;
        if (ix2 >= 600)
        {
            // �ʱ�ȭ ���·� �ǵ����༭ �ٽ� ó������ ������ �� �ֵ��� ���ֱ�
            ix2 = 1000;
            ix1 = 0;
            iclientprint = _recClient.right;
        }
    }*/

    // ���� �̹���1�� ��ǥ�� 0�� ������
    if (pbackgroundposition1.x == _recClient.left)
    {
        // ��ǥ�� �������ֱ�
        // ù��° �̹����� ��ǥ��
        pbackgroundposition1.x = 0;
        // �ι�° �̹����� ��ǥ��
        pbackgroundposition2.x = pimagestartposition.x;
    }
    // ���� �̹���2�� ��ǥ�� 0�� ������
    else if (pbackgroundposition2.x == _recClient.left)
    {
        // ��ǥ�� �ٲ��ֱ�
        // �ι�° �̹����� ��ǥ��
        pbackgroundposition2.x = 0;
        // ù��° �̹����� ��ǥ��
        pbackgroundposition1.x = pimagestartposition.x;
    }

    // class�� ��ǥ�� �־��ֱ�
    obimg1.SetPosition(pbackgroundposition1);
    obimg2.SetPosition(pbackgroundposition2);

    // �̹��� �ε��ϱ�
    obimg1.ImageLoading(_hdc, _recClient, hMemdc, pimagestartposition, pimagesize);
    obimg2.ImageLoading(_hdc, _recClient, hMemdc, pimagestartposition, pimagesize);

    // ���� �̹���1�� ��ǥ�� ������ left ������ �۳� ������ 
    if (pbackgroundposition1.x <= _recClient.left)
    {
        // �̹��� 1�� �������� �������� 3�� �̵�
        pbackgroundposition1.x -= 3;
        obimg1.SetPosition(pbackgroundposition1);
        // ���� ������ ũ�� + ��ǥ ��ġ�� ������ left ��ǥ���� ���� ��
        if (pbackgroundposition1.x + _recClient.right <= _recClient.left)
        {
            // ��ǥ �ʱ�ȭ
            pbackgroundposition1.x = 0;
        }
    }
    // ���� �̹���2�� ��ǥ�� ������ left ������ �۳� ������ 
    else if (pbackgroundposition2.x <= _recClient.left)
    {
        // �̹��� 2�� �������� �������� 3�� �̵�
        pbackgroundposition2.x -= 3;
        obimg2.SetPosition(pbackgroundposition2);
        // ���� ������ ũ�� + ��ǥ ��ġ�� ������ left ��ǥ���� ���� ��
        if (pbackgroundposition2.x + _recClient.right <= _recClient.left)
        {
            // ��ǥ �ʱ�ȭ
            pbackgroundposition2.x = 0;
        }
    }

    /*
        �̹��� 2�� ��ġ�� ���缭 �Բ� �̵��� �� �ֵ��� ����
        �̹����� ������� ������ ����. ���� �����Ͽ� ���صα�
        �� �� �� �� 
    */

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
