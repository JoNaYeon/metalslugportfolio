#include "Background.h"

#include "Object.h"
#include "ObjManager.h"
//#include "metalslug.h"
#include "define.h"


 
// ������
Background::Background()
{
    // �� ��� ����ü ä���ֱ�
    SetObjStruct(m_BG, BGWANIMATION, BGHANIMATION, BGORIGINSRCX, BGORIGINSRCY, BGWANIMATION * BGSIZE, BGHANIMATION * BGSIZE, m_BG.posoriginDest.x, m_BG.posoriginDest.y,
        BACKGROUNDMOVE, BGWNUM, BGHNUM);

    //m_ibgTile1 = 0;
    //m_ibgTile2 = 0;
};


void Background::BackgroundMove(E_USERSTATE _e_state)
{
    switch (_e_state)
    {
        case E_USERSTATE_LWALK:
        {
            m_BG.poriginSrc.x -= BACKGROUNDMOVE;
        }
        case E_USERSTATE_RWALK:
        {
            m_BG.poriginSrc.x += BACKGROUNDMOVE;
        }
    }

    return;
}


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



    // �̹��� ������ HDC ���� 
    himgdc = CreateCompatibleDC(_hdc);




    // ��Ʈ���� hBIt�� �ѷ��ֱ�
    //himgBit1 = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(BACKGROUND02));
    himgBit1 = (HBITMAP)LoadImage(NULL,"..\\source\\background\\background2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    // himgdc �� hBit�� �����ϰ� hOldBit�� himgdc�� ������ �ִ� ��ȭ���� �ٲ㼭 �����ص�
    // �̹����� ������ ���� ���� + ��ȭ��
    hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit1);
    // ù��° �̹��� ���
    TransparentBlt(_hdc, m_BG.posoriginDest.x, m_BG.posoriginDest.y,
        m_BG.recDest.right, m_BG.recDest.bottom,
        himgdc, m_BG.poriginSrc.x, m_BG.poriginSrc.y,
        m_BG.recSrc.right, m_BG.recSrc.bottom, RGB(255, 255, 255));


    // ��� Ÿ�� ����ִ� �Լ�
    //BackgroundTile(_hdc, BACKGROUNDMOVE);

    // �ٴ��� �����ִ� �ӽ� ����
    m_recClient = ObjManager::GetInstance()->GetRect();
    m_recClient.top = m_recClient.bottom - 300;
    Rectangle(_hdc, m_recClient.left, m_recClient.top, m_recClient.right, m_recClient.bottom);




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




RECT* Background::BackgroundTile(int _itilemove)
{
    /*RECT recTile = ObjManager::GetInstance()->GetRect();
    recTile.top = recTile.bottom - 300;*/

    //Rectangle(_hdc, recTile.left, recTile.top, recTile.right, recTile.bottom);

    return &m_recClient;
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
