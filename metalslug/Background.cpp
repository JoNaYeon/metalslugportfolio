#include "Background.h"

#include "metalslug.h"
#include "define.h"

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

void Background::Run(HWND _hWnd, HDC& _hdc, HINSTANCE _hInst, RECT _recClient)
{
    // �̹����� �׷��� �޸� dc
    HDC hMemdc = CreateCompatibleDC(_hdc);
    //�̹����� ��� ���� �޸� dc
    HDC himgdc = CreateCompatibleDC(_hdc);

    // �̹����� ������ HBITMAP
    HBITMAP himgBit = CreateCompatibleBitmap(_hdc, _recClient.right, _recClient.bottom);
    // Memdc �� ������ HBITMAP
    HBITMAP hBit = CreateCompatibleBitmap(_hdc, _recClient.right, _recClient.bottom);
    // ���� ��ȭ�� �������� ����
    HBITMAP hOldBit_img = NULL;
    HBITMAP hOldBit_mem = NULL;

    // �̹����� ����� ������ ����
    m_pimagesize = { BACKGROUNDX , BACKGROUNDY };
    // �̹��� ������ ��� ��ŸƮ ��ǥ��
    m_pimagestartposition = { BACKGROUNDPOSX, BACKGROUNDPOSY };
    // �̹����� ��ǥ�� �������� ����

    // ��Ʈ���� hBIt�� �ѷ��ֱ�
    himgBit = (HBITMAP)LoadBitmap(_hInst, MAKEINTRESOURCE(IDB_BACKGROUND1));

    // himgdc �� hBit�� �����ϰ� hOldBit�� himgdc�� ������ �ִ� ��ȭ���� �ٲ㼭 �����ص�
    // �̹����� ������ ���� ���� + ��ȭ��
    hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit);
    // �̹����� �׷��� ���� + ��ȭ��
    hOldBit_mem = (HBITMAP)SelectObject(hMemdc, hBit);


    // �̹��� �����̼� ��ǥ ����
    // ���� �̹���1�� ���� ��ǥ�� �������� left ��ǥ�� ���ų� �������� right ��ǥ�� ������
    /*if (m_pbackgroundposition1.x == _recClient.left && m_pbackgroundposition2.x > _recClient.left)
    {
        // ��ǥ�� �������ֱ�
        // ù��° �̹����� ��ǥ��
        m_pbackgroundposition1.x = 0;
        // �ι�° �̹����� ��ǥ���� �̹����� ũ��
        m_pbackgroundposition2.x = BACKGROUNDX;
    }
    // ���� �̹���2�� ��ǥ�� 0�� ������
    else if (m_pbackgroundposition2.x == _recClient.left && m_pbackgroundposition1.x > _recClient.left)
    {
        // ��ǥ�� �ٲ��ֱ�
        // �ι�° �̹����� ��ǥ��
        m_pbackgroundposition2.x = 0;
        // ù��° �̹����� ��ǥ���� �̹����� ũ��
        m_pbackgroundposition1.x = BACKGROUNDX;
    }*/


    // ���� �̹���1�� ��ǥ�� ������ left ������ �۰ų� ������ 
    if (m_pbackgroundposition1.x <= _recClient.right)
    {
        // �̹��� 1�� �������� �������� BACKGROUNDMOVE �� �̵�
        m_pbackgroundposition1.x -= BACKGROUNDMOVE;
        // ���� ������ ũ�� + ��ǥ ��ġ�� ������ left ��ǥ���� ���� ��
        if (m_pbackgroundposition1.x + _recClient.right <= _recClient.left)
        {
            // ��ǥ �ʱ�ȭ
            m_pbackgroundposition1.x = _recClient.right;
        }
    }
    
    // ���� �̹���2�� ��ǥ�� ������ left ������ �۳� ������ 
    if (m_pbackgroundposition2.x <= _recClient.right)
    {
        // �̹��� 2�� �������� �������� BACKGROUNDMOVE�� �̵�
        m_pbackgroundposition2.x -= BACKGROUNDMOVE;
        // ���� ������ ũ�� + ��ǥ ��ġ�� ������ left ��ǥ���� ���� ��
        if (m_pbackgroundposition2.x + _recClient.right <= _recClient.left)
        {
            // ��ǥ �ʱ�ȭ
            m_pbackgroundposition2.x = _recClient.right;
        }
    }

    // class�� ��ǥ�� �־��ֱ�
    m_obimg1.SetPosition(m_pbackgroundposition1);
    m_obimg2.SetPosition(m_pbackgroundposition2);


    // �̹��� �ε��ϱ�
    m_obimg1.ImageLoading(hMemdc, _recClient, himgdc, m_pimagestartposition, m_pimagesize);
    m_obimg2.ImageLoading(hMemdc, _recClient, himgdc, m_pimagestartposition, m_pimagesize);
    
    // hMemdc�� �ִ� �׸��� _hdc�� �Űܴ�� 
    BitBlt(_hdc, 0, 0, _recClient.right, _recClient.bottom, hMemdc, 0, 0, SRCCOPY);


    // �ٽ� hOldBit ���� �����ֱ�
    SelectObject(himgdc, hOldBit_img);
    SelectObject(hMemdc, hOldBit_mem);

    // dc ����
    DeleteDC(hMemdc);
    DeleteDC(himgdc);
    // HBITMAP ����
    DeleteObject(hBit);
    DeleteObject(himgBit);

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
