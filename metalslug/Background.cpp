#include "Background.h"

#include "Object.h"
#include "ObjManager.h"
//#include "metalslug.h"
#include "define.h"


 
// ������
Background::Background()
{
    /*pBGsize = { 0, 0 };

    m_BG1.iHightnum = 0;
    m_BG1.iWidthnum = 0;
    m_BG1.iobjmove = 0;
    m_BG1.recSrc = { 0, 0, 0, 0 };
    m_BG1.poriginSrc = { 0, 0 };
    m_BG1.recDest = { 0, 0, 0, 0 };
    m_BG1.posoriginDest = { 0, 0 };

    m_BG2.iHightnum = 0;
    m_BG2.iWidthnum = 0;
    m_BG2.iobjmove = 0;
    m_BG2.recSrc = { 0, 0, 0, 0 };
    m_BG2.poriginSrc = { 0, 0 };
    m_BG2.recDest = { 0, 0, 0, 0 };
    m_BG2.posoriginDest = { 0, 0 };*/

    // �� ��� ����ü ä���ֱ�
    SetObjStruct(m_BG1, BGWANIMATION, BGHANIMATION, BGORIGINSRCX, BGORIGINSRCY, BGWANIMATION * BGSIZE, BGHANIMATION * BGSIZE, m_BG1.posoriginDest.x, m_BG1.posoriginDest.y,
        BACKGROUNDMOVE, BGWNUM, BGHNUM);

    SetObjStruct(m_BG2, BGWANIMATION, BGHANIMATION, BGORIGINSRCX, BGORIGINSRCY, BGWANIMATION * BGSIZE, BGHANIMATION * BGSIZE, m_BG2.posoriginDest.x, m_BG2.posoriginDest.y,
        BACKGROUNDMOVE, BGWNUM, BGHNUM);

    //m_ibgTile1 = 0;
    //m_ibgTile2 = 0;
};

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
    //�̹����� ��� ���� �޸� dc
    HDC himgdc;
    // �̹����� ������ HBITMAP
    HBITMAP himgBit1 = NULL;
    HBITMAP himgBit2 = NULL;
    // ���� ��ȭ�� �������� ����
    HBITMAP hOldBit_img = NULL;

    /*// ObjManager �� �ִ� ���� �������� 
    RECT recClient = ObjManager::GetInstance()->GetRect();
    // client ȭ�� ũ�⸦ �� �޾ƿ��� ������ ȭ�鿡 �ƹ��͵� �� ����! 
    GetClientRect(_hWnd, &recClient);*/



    // �̹��� ������ HDC ���� 
    himgdc = CreateCompatibleDC(_hdc);




    // ��Ʈ���� hBIt�� �ѷ��ֱ�
    himgBit1 = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(BACKGROUND02));
    // himgdc �� hBit�� �����ϰ� hOldBit�� himgdc�� ������ �ִ� ��ȭ���� �ٲ㼭 �����ص�
    // �̹����� ������ ���� ���� + ��ȭ��
    hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit1);
    // ù��° �̹��� ���
    TransparentBlt(_hdc, m_BG1.posoriginDest.x, m_BG1.posoriginDest.y,
        m_BG1.recDest.right, m_BG1.recDest.bottom,
        himgdc, m_BG1.poriginSrc.x, m_BG1.poriginSrc.y,
        m_BG1.recSrc.right, m_BG1.recSrc.bottom, RGB(255, 255, 255));


    himgBit2 = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(BACKGROUND02));
    // �̹����� ������ ���� ���� + ��ȭ��
    hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit2);
    // �ι��� �̹��� ���
    TransparentBlt(_hdc, m_BG2.posoriginDest.x, m_BG2.posoriginDest.y,
        m_BG2.recDest.right, m_BG2.recDest.bottom,
        himgdc, m_BG2.poriginSrc.x, m_BG2.poriginSrc.y,
        m_BG2.recSrc.right, m_BG2.recSrc.bottom, RGB(255, 255, 255));


    /*// ���� ù��° ����� �������� client ���� ���̺��� �۰ų� �ι�° ��� ���� ������ - ���� �۴ٸ� 
    if (m_BG1.posoriginDest.x <= recClient.right && m_BG1.posoriginDest.x >= -(m_BG2.recDest.right))
    {
        // ��Ʈ���� hBIt�� �ѷ��ֱ�
        himgBit1 = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(BACKGROUND01));
        // himgdc �� hBit�� �����ϰ� hOldBit�� himgdc�� ������ �ִ� ��ȭ���� �ٲ㼭 �����ص�
        // �̹����� ������ ���� ���� + ��ȭ��
        hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit1);
        // ù��° �̹��� ���
        TransparentBlt(_hdc, m_BG1.posoriginDest.x, m_BG1.posoriginDest.y,
            m_BG1.recDest.right, m_BG1.recDest.bottom,
            himgdc, m_BG1.poriginSrc.x, m_BG1.poriginSrc.y,
            m_BG1.recSrc.right, m_BG1.recSrc.bottom, RGB(255, 255, 255));

        // �̹��� 1�� �������� �������� BACKGROUNDMOVE �� �̵�
        m_BG1.posoriginDest.x -= BACKGROUNDMOVE;

        // ���� ù��° ����� �������� (ù��° ����� ���� ���� - ��� ���� ����) �� - ������ �۰ų�
        // �ι�° ����� �������� (�ι�° ����� ���� ���� - client ���� ����) �� - ������ �۴ٸ�
        if (m_BG1.posoriginDest.x <= - (m_BG1.recDest.right - recClient.right) 
            && m_BG2.posoriginDest.x <= - (m_BG2.recDest.right - recClient.right))
        {
            m_BG2.posoriginDest.x = recClient.right;
            m_ibgTile2 = 0;
        }
    }



    // ���� �ι�° ����� �������� client ���� ���̺��� �۰ų� ù��° ��� ���� ������ - ���� �۴ٸ� 
    if (m_BG2.posoriginDest.x <= recClient.right && m_BG2.posoriginDest.x >= -(m_BG1.recDest.right))
    {
        himgBit2 = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(BACKGROUND01));
        // �̹����� ������ ���� ���� + ��ȭ��
        hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit2);
        // �ι��� �̹��� ���
        TransparentBlt(_hdc, m_BG2.posoriginDest.x, m_BG2.posoriginDest.y,
            m_BG2.recDest.right, m_BG2.recDest.bottom,
            himgdc, m_BG2.poriginSrc.x, m_BG2.poriginSrc.y,
            m_BG2.recSrc.right, m_BG2.recSrc.bottom, RGB(255, 255, 255));

        // �̹��� 1�� �������� �������� BACKGROUNDMOVE �� �̵�
        m_BG2.posoriginDest.x -= BACKGROUNDMOVE;

        // ���� �ι�° ����� �������� (�ι�° ����� ���� ���� - ��� ���� ����) �� - ������ �۰ų�
        // ù��° ����� �������� (ù��° ����� ���� ���� - client ���� ����) �� - ������ �۴ٸ�
        if (m_BG2.posoriginDest.x <= - (m_BG2.recDest.right - recClient.right)
            && m_BG1.posoriginDest.x <= - (m_BG1.recDest.right - recClient.right))
        {
            m_BG1.posoriginDest.x = recClient.right;
            m_ibgTile1 = 0;
        }
    }*/


    // ��� Ÿ�� ����ִ� �Լ�
    //BackgroundTile(_hdc, BACKGROUNDMOVE);

    // �ٽ� hOldBit ���� �����ֱ�
    SelectObject(himgdc, hOldBit_img);

    // dc ����
    DeleteDC(himgdc);
    // HBITMAP ����
    DeleteObject(himgBit1);
    DeleteObject(himgBit2);

	return;
};

// ������Ʈ �ı�
void Background::Destroy()
{
	return;
};




void Background::BackgroundTile(HDC _hdc, int _itilemove)
{
    /*m_ibgTile1 += BACKGROUNDMOVE;
    m_ibgTile2 += BACKGROUNDMOVE;

    Rectangle(_hdc, 0 - m_ibgTile1, 860, 100 * BGSIZE - m_ibgTile1, 1000);
    //(_hdc, 113 * BGADD, 860 - (11 * BGADD) , 210 * BGADD, 1000);
    Rectangle(_hdc, 113 * BGSIZE - m_ibgTile1, 860, 95 * BGSIZE - m_ibgTile1, 1000);
    Rectangle(_hdc, 262 * BGSIZE - m_ibgTile1, 860, 156 * BGSIZE - m_ibgTile1, 1000);
    Rectangle(_hdc, 434 * BGSIZE - m_ibgTile1, 860, 91 * BGSIZE - m_ibgTile1, 1000);
    Rectangle(_hdc, 606 * BGSIZE - m_ibgTile1, 860, 147 * BGSIZE - m_ibgTile1, 1000);*/

    return;
}

/*POINT Background::GetRatio(int iwidth, int iheight)
{
    // ȭ�� ���� ���ϴ� �Լ�
    int imax = 0;
    int imin = 0;
    int igcd = 0;
    int itemp = 0;

    RECT rectemp = ObjManager::GetInstance()->GetRect();

    POINT proit = { 0,0 };

    // ū ���� imax�� �־��ֱ�
    if (iwidth >= iheight)
    {
        imax = iwidth;
        imin = iheight;
    }
    else
    {
        imax = iheight;
        imin = iwidth;
    }

    while (true)
    {
        itemp = imax % imin;

        if (itemp == 0)
        {
            break;
        }
        else
        {
            imax = imin;
            imin = itemp;
        }
    }

    igcd = imin;

    proit.x = rectemp.right / igcd;
    proit.y = rectemp.bottom / igcd;

    return proit;
}*/

bool Background::bObjDead()
{
    return false;
}