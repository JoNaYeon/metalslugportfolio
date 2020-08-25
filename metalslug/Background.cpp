#include "Background.h"

#include "Object.h"
#include "ObjManager.h"
#include "PlayerNormal.h"
#include "InputManager.h"

// ������
Background::Background()
{
    // �� ��� ����ü ä���ֱ�
    m_DisBG.ptDestPos = { 0 , 0 };
    m_DisBG.ptSrcPos = { BGORIGINSRCX , BGORIGINSRCY };
    m_DisBG.ptDestSize = { BGWANIMATION * BGSIZE , BGHANIMATION * BGSIZE };

    POINT ptImgSize = { BGWANIMATION , BGHANIMATION };
    SetImgInfo(m_ImgBG, ptImgSize, BGWNUM, BGHNUM);

    m_recHitBox = { 0,0,0,0 };


    ptTileMove = { 0,0 };


    //m_ibgTile1 = 0;
    //m_ibgTile2 = 0;
};


void Background::BackgroundMove(E_USERSTATE _e_state)
{
    switch (_e_state)
    {
        case E_USERSTATE_LWALK:
        {
            m_DisBG.ptSrcPos.x -= BACKGROUNDMOVE;
        }
        case E_USERSTATE_RWALK:
        {
            m_DisBG.ptSrcPos.x += BACKGROUNDMOVE;
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
    himgBit1 = (HBITMAP)LoadImage(NULL,"..\\source\\background\\background2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    // himgdc �� hBit�� �����ϰ� hOldBit�� himgdc�� ������ �ִ� ��ȭ���� �ٲ㼭 �����ص�
    // �̹����� ������ ���� ���� + ��ȭ��
    hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit1);
    // �̹��� ���
    TransparentBlt(_hdc, m_DisBG.ptDestPos.x, m_DisBG.ptDestPos.y,
        m_DisBG.ptDestSize.x, m_DisBG.ptDestSize.y,
        himgdc, m_DisBG.ptSrcPos.x, m_DisBG.ptSrcPos.y,
        m_ImgBG.ptSrcSize.x, m_ImgBG.ptSrcSize.y, RGB(255, 255, 255));

    //TransparentBlt(_hdc, 0, 0, 1000, 1000, himgdc, 0, 0, 1000, 1000, RGB(255, 255, 255));


    // ��� Ÿ�� ����ִ� �Լ�
    //BackgroundTile(_hdc, BACKGROUNDMOVE);

    // �ٴ��� �����ִ� �ӽ� ����
    //Rectangle(_hdc, m_recHitBox.left, m_recHitBox.top, m_recHitBox.right, m_recHitBox.bottom);
    //BackgroundTile();
    for (int i = 0; i < ObjManager::GetInstance()->GetVector(EOBJECT_BG).size(); i++)
    {
        for (int j = 0; j < (*(ObjManager::GetInstance()->GetvecBGpos())).size(); j++)
        {
            //std::vector<RECT>* recBGTemp = (ObjManager::GetInstance()->GetvecBGpos());
            RECT recBGTemp = (*(ObjManager::GetInstance()->GetvecBGpos()))[j];

            Rectangle(_hdc, recBGTemp.left, recBGTemp.top, recBGTemp.right, recBGTemp.bottom);
        }
    }

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





RECT Background::BackgroundTile(int _i)
{
    //POINT ptTiletemp = { 1,1 };
    /*int iposx = 0;
    int iposy = 0;*/

    POINT ptTile = { 0,0 };
    RECT recClient = ObjManager::GetInstance()->GetRect();
    RECT recTemp = { 0,0,0,0 };

    int iyDown = 0;
    int iyUp = 0;

    /*if (m_DisBG.ptSrcPos.x <= POSX1)
    {
        iposx = POSX1;
        iposy = POSY1;
    }*/

    /*for (int i = 0; i < BGEND; i++)
    {
        //ptTile.x += (((i * ptTiletemp.x) + ptTiletemp.x) * BGSIZE) - ((i * ptTiletemp.x) * BGSIZE);
       
        ptTile.x = i;

        if (i <= POSX1)
        {
            ptTile.y = POSY1;
        }
        else if (POSX1 <= i && i < POSX2)
        {
            int ipos = 0;


            ptTile.y += 1;
        }


        RECT rectemp = { ptTile.x, ptTile.y, ptTile.x + 1, ptTile.y + 1 };

        // vector �� rect �� �ϳ��� �־��ֱ�
        //(ObjManager::GetInstance()->GetvecBGpos())->push_back(rectemp);
    }

    //m_recHitBox = { m_DisBG.ptDestPos.x, ptTile.y * 2, (m_DisBG.ptDestPos.x) + ptTile.x, (ptTile.y * 2) + 3 };

    //Rectangle(_hdc, m_recHitBox.left, m_recHitBox.top, m_recHitBox.right, m_recHitBox.bottom);
    
    // vector �� ���� Tile RECT �� �ϳ��� �׷���
    for (int i = 0; i < (ObjManager::GetInstance()->GetvecBGpos())->size(); i++)
    {
        Rectangle(_hdc, (&(ObjManager::GetInstance()->GetvecBGpos())[i]).left, (&(ObjManager::GetInstance()->GetvecBGpos())[i]).top, 
            (&(ObjManager::GetInstance()->GetvecBGpos())[i]).right, (&(ObjManager::GetInstance()->GetvecBGpos())[i]).bottom);
    }*/

    if (POSX0 * BGSIZE < _i && _i < POSX1 * BGSIZE)
    {
        if (POSY0 != POSY1)
        {
            int imax = 0;
            int imin = 0;

            if (POSY0 > POSY1)
            {
                imax = POSY0;
                imin = POSY1;
            }
            else
            {
                imax = POSY1;
                imin = POSY0;
            }

            int iytemp = imax - imin;
            int ixtemp = POSX1 - POSX0;
            int itemp = (_i - imin) * (iytemp / ixtemp);

            recTemp = { _i, (POSY0 * 2) + itemp, _i + 1, ((POSY0 + 1) * 2) + itemp };
        }
        else
        {
            recTemp = { _i, (POSY0 * 2), _i + 1, (POSY0 + 1) * 2 };
        }

    }
    else if (POSX1 * BGSIZE < _i && _i < POSX2 * BGSIZE)
    {
        if (POSY1 != POSY2)
        {
            int imax = 0;
            int imin = 0;

            if (POSY1 > POSY2)
            {
                imax = POSY1;
                imin = POSY2;
            }
            else
            {
                imax = POSY2;
                imin = POSY1;
            }

            int iytemp = imax - imin;
            int ixtemp = POSX2 - POSX1;
            int itemp = (_i - imin) * (iytemp / ixtemp);

            recTemp = { _i, (POSY1 * 2) + itemp, _i + 1, ((POSY2 + 1) * 2) + itemp };
        }
        else
        {
            recTemp = { _i, (POSY1 * 2), _i + 1, (POSY1 + 1) * 2 };
        }
    }
    else if (POSX2 * BGSIZE < _i && _i < POSX3 * BGSIZE)
    {
        recTemp = { _i, POSY3 * 2, _i + 1, (POSY3 + 1) * 2 };
    }
    else if (POSX3 * BGSIZE < _i && _i < POSX4 * BGSIZE)
    {
        recTemp = { _i, POSY4 * 2, _i + 1, (POSY4 + 1) * 2 };
    }
    else if (POSX4 * BGSIZE < _i && _i < POSX5 * BGSIZE)
    {
        recTemp = { _i, POSY5 * 2, _i + 1, (POSY5 + 1) * 2 };
    }
    else if (POSX5 * BGSIZE < _i && _i < POSX6 * BGSIZE)
    {
        recTemp = { _i, POSY6 * 2, _i + 1, (POSY6 + 1) * 2 };
    }
    else if (POSX6 * BGSIZE < _i && _i < POSX7 * BGSIZE)
    {
        recTemp = { _i, POSY7 * 2, _i + 1, (POSY7 + 1) * 2 };
    }
    else if (POSX7 * BGSIZE < _i && _i < POSX8 * BGSIZE)
    {
        recTemp = { _i, POSY8 * 2, _i + 1, (POSY8 + 1) * 2 };
    }
    else if (POSX8 * BGSIZE < _i && _i < POSX9 * BGSIZE)
    {
        recTemp = { _i, POSY9 * 2, _i + 1, (POSY9 + 1) * 2 };
    }
    else if (POSX9 * BGSIZE < _i && _i < POSX10 * BGSIZE)
    {
        recTemp = { _i, POSY10 * 2, _i + 1, (POSY10 + 1) * 2 };
    }
    else if (POSX10 * BGSIZE < _i && _i < POSX11 * BGSIZE)
    {
        recTemp = { _i, POSY11 * 2, _i + 1, (POSY11 + 1) * 2 };
    }
    else if (POSX11 * BGSIZE < _i && _i < POSX12 * BGSIZE)
    {
        recTemp = { _i, POSY12 * 2, _i + 1, (POSY12 + 1) * 2 };
    }
    else if (POSX12 * BGSIZE < _i && _i < POSX13 * BGSIZE)
    {
        recTemp = { _i, POSY13 * 2, _i + 1, (POSY13 + 1) * 2 };
    }
    else if (POSX13 * BGSIZE < _i && _i < POSX14 * BGSIZE)
    {
        recTemp = { _i, POSY14 * 2, _i + 1, (POSY14 + 1) * 2 };
    }
    else if (POSX14 * BGSIZE < _i && _i < POSX15 * BGSIZE)
    {
        recTemp = { _i, POSY15 * 2, _i + 1, (POSY15 + 1) * 2 };
    }
    else if (POSX15 * BGSIZE < _i && _i < POSX16 * BGSIZE)
    {
        recTemp = { _i, POSY16 * 2, _i + 1, (POSY16 + 1) * 2 };
    }
    else if (POSX16 * BGSIZE < _i && _i < POSX17 * BGSIZE)
    {
        recTemp = { _i, POSY17 * 2, _i + 1, (POSY17 + 1) * 2 };
    }
    else if (POSX17 * BGSIZE < _i && _i < POSX18 * BGSIZE)
    {
        recTemp = { _i, POSY18 * 2, _i + 1, (POSY18 + 1) * 2 };
    }
    else if (POSX18 * BGSIZE < _i && _i < POSX19 * BGSIZE)
    {
        recTemp = { _i, POSY19 * 2, _i + 1, (POSY19 + 1) * 2 };
    }
    else if (POSX19 * BGSIZE < _i && _i < POSX20 * BGSIZE)
    {
        recTemp = { _i, POSY20 * 2, _i + 1, (POSY20 + 1) * 2 };
    }
    else if (POSX20 * BGSIZE < _i && _i < POSX21 * BGSIZE)
    {
        recTemp = { _i, POSY21 * 2, _i + 1, (POSY21 + 1) * 2 };
    }
    else if (POSX21 * BGSIZE < _i && _i < POSX22 * BGSIZE)
    {
        recTemp = { _i, POSY22 * 2, _i + 1, (POSY22 + 1) * 2 };
    }
    else if (POSX22 * BGSIZE < _i && _i < POSX23 * BGSIZE)
    {
        recTemp = { _i, POSY23 * 2, _i + 1, (POSY23 + 1) * 2 };
    }
    else if (POSX23 * BGSIZE < _i && _i < POSX24 * BGSIZE)
    {
        recTemp = { _i, POSY24 * 2, _i + 1, (POSY24 + 1) * 2 };
    }
    else if (POSX24 * BGSIZE < _i && _i < POSX25 * BGSIZE)
    {
        recTemp = { _i, POSY25 * 2, _i + 1, (POSY25 + 1) * 2 };
    }
    else if (POSX25 * BGSIZE < _i && _i < POSX26 * BGSIZE)
    {
        recTemp = { _i, POSY26 * 2, _i + 1, (POSY26 + 1) * 2 };
    }
    else if (POSX26 * BGSIZE < _i && _i < POSX27 * BGSIZE)
    {
    recTemp = { _i, POSY27 * 2, _i + 1, (POSY27 + 1) * 2 };
    }

    return recTemp;
}



bool Background::bObjDead()
{
    return false;
}
