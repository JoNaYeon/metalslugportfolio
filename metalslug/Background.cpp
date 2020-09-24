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


    m_bypos = false;


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
    /*for (int i = 0; i < ObjManager::GetInstance()->GetVector(EOBJECT_BG).size(); i++)
    {
        for (int j = 0; j < (*(ObjManager::GetInstance()->GetvecBGpos())).size(); j++)
        {
            //std::vector<RECT>* recBGTemp = (ObjManager::GetInstance()->GetvecBGpos());
            RECT recBGTemp = (*(ObjManager::GetInstance()->GetvecBGpos()))[j];

            Rectangle(_hdc, recBGTemp.left, recBGTemp.top, recBGTemp.right, recBGTemp.bottom);
        }
    }*/
    /*for (int i = 0; i < m_vecpos.size() - 1; i++)
    {
        MoveToEx(_hdc, m_vecpos[i].x, m_vecpos[i].y, NULL);
        LineTo(_hdc, m_vecpos[i + 1].x, m_vecpos[i + 1].y);
    }*/


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


/*void Background::BackgroundTileset(int _i, int _iposy1, int _iposy2, int _iposx1, int _iposx2, RECT* _rec)
{
    if (_iposy1 != _iposy2)
    {
        int imax = 0;
        int imin = 0;

        if (_iposy1 > _iposy2)
        {
            imax = _iposy1;
            imin = _iposy2;
        }
        else
        {
            imax = _iposy2;
            imin = _iposy1;
        }

        int iytemp = imax - imin;
        int ixtemp = _iposx2 - _iposx1;

        int itemp = (_i - imin) * (iytemp / ixtemp);

        _rec->left = _i;
        _rec->top = (_iposy1 + itemp) * BGTILESIZE;
        _rec->right = _i + 1;
        _rec->bottom = ((_iposy1 + itemp) * BGTILESIZE) + 1;
    }
    else
    {
        _rec->left = _i;
        _rec->top = (_iposy1 * BGTILESIZE);
        _rec->right = _i + 1;
        _rec->bottom = (_iposy1 + 1) * BGTILESIZE;
    }

    return;
}*/

// POINT �� POINT ������ ���⸦ ����Ͽ� object �� y���� ���ϴ� �Լ�
/*int Background::GetTileY(Object* _obj)
{
    std::vector<Object*> vecObjTemp = ObjManager::GetInstance()->GetVector(EOBJECT_USER);

    int iPlayerX = 0;
    int iPlayerY = 0;

    int im = 0;

    int iY = 0;

    POINT posleft = { 0,0 };
    POINT posright = { 0,0 };

    for (int i = 0; i < vecObjTemp.size(); i++)
    {
        DISPLAYINFO* distemp = ((PlayerNormal*)(vecObjTemp)[i])->GetPlayerDisTop();
        iPlayerX = distemp->ptDestPos.x;
    }

    for (int i = 0; i < m_vecpos.size() - 1; i++)
    {
        if (iPlayerX >= m_vecpos[i].x && iPlayerX < m_vecpos[i + 1].x)
        {
            posleft = m_vecpos[i];
            posright = m_vecpos[i + 1];
        }
    }

    // ������ ���� = (y�� ������ / x�� ������)
    im = (posright.y - posleft.y) / (posright.x - posleft.x);

    // y�� ����
    iY = posleft.y - (posleft.x * im);

    // y�� ��ġ�� = (���� ���� X ���� x�� ��ġ��) + y�� ����
    iPlayerY = (im * iPlayerX) + iY;

    return iPlayerY;
}*/


/*void Background::BackgroundTile(int _i)
{
    //POINT ptTiletemp = { 1,1 };
    /*int iposx = 0;
    int iposy = 0;

    POINT ptTile = { 0,0 };
    RECT recClient = ObjManager::GetInstance()->GetRect();
    RECT recTemp = { 0,0,0,0 };

    if (m_DisBG.ptSrcPos.x <= POSX1)
    {
        iposx = POSX1;
        iposy = POSY1;
    }

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
    }

    /*if (POSX0 * BGSIZE < _i && _i < POSX1 * BGSIZE)
    {
        BackgroundTileset(_i, POSY0, POSY1, POSX0, POSX1, &recTemp);
    }
    else if (POSX1 * BGSIZE < _i && _i < POSX2 * BGSIZE)
    {
        BackgroundTileset(_i, POSY1, POSY2, POSX1, POSX2, &recTemp);
    }
    else if (POSX2 * BGSIZE < _i && _i < POSX3 * BGSIZE)
    {
        BackgroundTileset(_i, POSY2, POSY3, POSX2, POSX3, &recTemp);
    }
    else if (POSX3 * BGSIZE < _i && _i < POSX4 * BGSIZE)
    {
        BackgroundTileset(_i, POSY3, POSY4, POSX3, POSX4, &recTemp);
    }
    else if (POSX4 * BGSIZE < _i && _i < POSX5 * BGSIZE)
    {
        BackgroundTileset(_i, POSY4, POSY5, POSX4, POSX5, &recTemp);
    }
    else if (POSX5 * BGSIZE < _i && _i < POSX6 * BGSIZE)
    {
        BackgroundTileset(_i, POSY5, POSY6, POSX5, POSX6, &recTemp);
    }
    else if (POSX6 * BGSIZE < _i && _i < POSX7 * BGSIZE)
    {
        BackgroundTileset(_i, POSY6, POSY7, POSX6, POSX7, &recTemp);
    }
    else if (POSX7 * BGSIZE < _i && _i < POSX8 * BGSIZE)
    {
        BackgroundTileset(_i, POSY7, POSY8, POSX7, POSX8, &recTemp);
    }
    else if (POSX8 * BGSIZE < _i && _i < POSX9 * BGSIZE)
    {
        BackgroundTileset(_i, POSY8, POSY9, POSX8, POSX9, &recTemp);
    }
    else if (POSX9 * BGSIZE < _i && _i < POSX10 * BGSIZE)
    {
        BackgroundTileset(_i, POSY9, POSY10, POSX9, POSX10, &recTemp);
    }
    else if (POSX10 * BGSIZE < _i && _i < POSX11 * BGSIZE)
    {
        BackgroundTileset(_i, POSY10, POSY11, POSX10, POSX11, &recTemp);
    }
    else if (POSX11 * BGSIZE < _i && _i < POSX12 * BGSIZE)
    {
        BackgroundTileset(_i, POSY11, POSY12, POSX11, POSX12, &recTemp);
    }
    else if (POSX12 * BGSIZE < _i && _i < POSX13 * BGSIZE)
    {
        BackgroundTileset(_i, POSY12, POSY13, POSX12, POSX13, &recTemp);
    }
    else if (POSX13 * BGSIZE < _i && _i < POSX14 * BGSIZE)
    {
        BackgroundTileset(_i, POSY13, POSY14, POSX13, POSX14, &recTemp);
    }
    else if (POSX14 * BGSIZE < _i && _i < POSX15 * BGSIZE)
    {
        BackgroundTileset(_i, POSY14, POSY15, POSX14, POSX15, &recTemp);
    }
    else if (POSX15 * BGSIZE < _i && _i < POSX16 * BGSIZE)
    {
        BackgroundTileset(_i, POSY15, POSY16, POSX15, POSX16, &recTemp);
    }
    else if (POSX16 * BGSIZE < _i && _i < POSX17 * BGSIZE)
    {
        BackgroundTileset(_i, POSY16, POSY17, POSX16, POSX17, &recTemp);
    }
    else if (POSX17 * BGSIZE < _i && _i < POSX18 * BGSIZE)
    {
        BackgroundTileset(_i, POSY17, POSY18, POSX17, POSX18, &recTemp);
    }
    else if (POSX18 * BGSIZE < _i && _i < POSX19 * BGSIZE)
    {
        BackgroundTileset(_i, POSY18, POSY19, POSX18, POSX19, &recTemp);
    }
    else if (POSX19 * BGSIZE < _i && _i < POSX20 * BGSIZE)
    {
        BackgroundTileset(_i, POSY19, POSY20, POSX19, POSX20, &recTemp);
    }
    else if (POSX20 * BGSIZE < _i && _i < POSX21 * BGSIZE)
    {
        BackgroundTileset(_i, POSY20, POSY21, POSX20, POSX21, &recTemp);
    }
    else if (POSX21 * BGSIZE < _i && _i < POSX22 * BGSIZE)
    {
        BackgroundTileset(_i, POSY21, POSY22, POSX21, POSX22, &recTemp);
    }
    else if (POSX22 * BGSIZE < _i && _i < POSX23 * BGSIZE)
    {
        BackgroundTileset(_i, POSY22, POSY23, POSX22, POSX23, &recTemp);
    }
    else if (POSX23 * BGSIZE < _i && _i < POSX24 * BGSIZE)
    {
        BackgroundTileset(_i, POSY23, POSY24, POSX23, POSX24, &recTemp);
    }
    else if (POSX24 * BGSIZE < _i && _i < POSX25 * BGSIZE)
    {
        BackgroundTileset(_i, POSY24, POSY25, POSX24, POSX25, &recTemp);
    }
    else if (POSX25 * BGSIZE < _i && _i < POSX26 * BGSIZE)
    {
        BackgroundTileset(_i, POSY25, POSY26, POSX25, POSX26, &recTemp);
    }
    else if (POSX26 * BGSIZE < _i && _i < POSX27 * BGSIZE)
    {
        BackgroundTileset(_i, POSY26, POSY27, POSX26, POSX27, &recTemp);
    }


    for (int i = 0; i < ObjManager::GetInstance()->GetVector(EOBJECT_USER).size(); i++)
    {
        //POINT postemp = { ((PlayerNormal*)(ObjManager::GetInstance()->GetVector(EOBJECT_USER))[i])->GetPlayerDisTop()->ptDestPos.x,GetTileY() };
        //((PlayerNormal*)(ObjManager::GetInstance()->GetVector(EOBJECT_USER))[i])->SetPlayerDisTop(postemp);
        //((PlayerNormal*)(ObjManager::GetInstance()->GetVector(EOBJECT_USER))[i])->SetPlayerDisBot(postemp);
    }

    return;
}*/



bool Background::bObjDead()
{
    return false;
}
