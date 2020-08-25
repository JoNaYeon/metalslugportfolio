#include "Background.h"

#include "Object.h"
#include "ObjManager.h"
#include "PlayerNormal.h"
#include "InputManager.h"

// 생성자
Background::Background()
{
    // 각 배경 구조체 채워주기
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


// 오브젝트 초기화
void Background::Init()
{
	return;
};

void Background::Run()
{


    return; 
}

// 오브젝트 출력
void Background::Render(HDC& _hdc, HWND& _hWnd)
{
    //이미지를 들고 있을 메모리 dc
    HDC himgdc;
    // 이미지를 저장할 HBITMAP
    HBITMAP himgBit1 = NULL;
    HBITMAP himgBit2 = NULL;
    // 이전 도화지 저장해줄 변수
    HBITMAP hOldBit_img = NULL;

    // 이미지 저장할 HDC 생성 
    himgdc = CreateCompatibleDC(_hdc);

    // 비트맵을 hBIt에 뿌려주기
    himgBit1 = (HBITMAP)LoadImage(NULL,"..\\source\\background\\background2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    // himgdc 에 hBit을 저장하고 hOldBit에 himgdc가 가지고 있던 도화지를 바꿔서 저장해둠
    // 이미지를 가지고 있을 도구 + 도화지
    hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit1);
    // 이미지 출력
    TransparentBlt(_hdc, m_DisBG.ptDestPos.x, m_DisBG.ptDestPos.y,
        m_DisBG.ptDestSize.x, m_DisBG.ptDestSize.y,
        himgdc, m_DisBG.ptSrcPos.x, m_DisBG.ptSrcPos.y,
        m_ImgBG.ptSrcSize.x, m_ImgBG.ptSrcSize.y, RGB(255, 255, 255));

    //TransparentBlt(_hdc, 0, 0, 1000, 1000, himgdc, 0, 0, 1000, 1000, RGB(255, 255, 255));


    // 배경 타일 깔아주는 함수
    //BackgroundTile(_hdc, BACKGROUNDMOVE);

    // 바닥을 보여주는 임시 수식
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

    // 다시 hOldBit 으로 갈아주기
    SelectObject(himgdc, hOldBit_img);

    // dc 해제
    DeleteDC(himgdc);
    // HBITMAP 해제
    DeleteObject(himgBit1);
    DeleteObject(himgBit2);

	return;
};

// 오브젝트 파괴
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

        // vector 에 rect 를 하나씩 넣어주기
        //(ObjManager::GetInstance()->GetvecBGpos())->push_back(rectemp);
    }

    //m_recHitBox = { m_DisBG.ptDestPos.x, ptTile.y * 2, (m_DisBG.ptDestPos.x) + ptTile.x, (ptTile.y * 2) + 3 };

    //Rectangle(_hdc, m_recHitBox.left, m_recHitBox.top, m_recHitBox.right, m_recHitBox.bottom);
    
    // vector 에 들은 Tile RECT 를 하나씩 그려줌
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
