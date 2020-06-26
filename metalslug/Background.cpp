#include "Background.h"

#include "Object.h"
#include "RendManager.h"
#include "framework.h"
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

// ������Ʈ ���
void Background::Render(HDC& _hdc, HWND& _hWnd)
{
    // RendManager �� �ִ� ���� �������� 
    RECT recClient = RendManager::GetInstance()->GetRect();
    //�̹����� ��� ���� �޸� dc
    HDC himgdc = CreateCompatibleDC(_hdc);

    // �̹����� ������ HBITMAP
    HBITMAP himgBit = CreateCompatibleBitmap(_hdc, recClient.right, recClient.bottom);
    // ���� ��ȭ�� �������� ����
    HBITMAP hOldBit_img = NULL;

    // client ȭ�� ũ�⸦ �� �޾ƿ��� ������ ȭ�鿡 �ƹ��͵� �� ����! 
    GetClientRect(_hWnd, &recClient);

    // �̹����� ����� ������ ����
    m_pimagesize = { BACKGROUNDX , BACKGROUNDY };
    // �̹��� ������ ��� ��ŸƮ ��ǥ��
    m_pimagestartposition = { BACKGROUNDPOSX, BACKGROUNDPOSY };
    // �̹����� ��ǥ�� �������� ����

    // ��Ʈ���� hBIt�� �ѷ��ֱ�
    himgBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BACKGROUND1));

    // himgdc �� hBit�� �����ϰ� hOldBit�� himgdc�� ������ �ִ� ��ȭ���� �ٲ㼭 �����ص�
    // �̹����� ������ ���� ���� + ��ȭ��
    hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit);

    // �̹��� 1�� �������� �������� BACKGROUNDMOVE �� �̵�
    m_pbackgroundposition1.x -= BACKGROUNDMOVE;
    // �̹��� 2�� �������� �������� BACKGROUNDMOVE�� �̵�
    m_pbackgroundposition2.x -= BACKGROUNDMOVE;

    if (m_pbackgroundposition1.x <= -(2*BACKGROUNDX + recClient.right))
    {
        // ��ǥ �ʱ�ȭ
        m_pbackgroundposition1.x = recClient.right;
    }

    if (m_pbackgroundposition2.x <= -(2 * BACKGROUNDX + recClient.right))
    {
        // ��ǥ �ʱ�ȭ
        m_pbackgroundposition2.x = recClient.right;
    }

    // class�� ��ǥ�� �־��ֱ�
    m_obimg1.SetPosition(m_pbackgroundposition1);
    m_obimg2.SetPosition(m_pbackgroundposition2);

    // �̹��� �ε��ϱ�
    m_obimg1.ImageLoading(_hdc, recClient, himgdc, m_pimagestartposition, m_pimagesize);
    m_obimg2.ImageLoading(_hdc, recClient, himgdc, m_pimagestartposition, m_pimagesize);

    // �ٽ� hOldBit ���� �����ֱ�
    SelectObject(himgdc, hOldBit_img);

    // dc ����
    DeleteDC(himgdc);
    // HBITMAP ����
    DeleteObject(himgBit);

	return;
};

// ������Ʈ �ı�
void Background::Destroy()
{
	return;
};
