#include "Background.h"

#include "Object.h"
#include "ObjManager.h"
//#include "metalslug.h"
#include "define.h"


 
// 생성자
Background::Background()
{
    // 각 배경 구조체 채워주기
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
    //himgBit1 = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(BACKGROUND02));
    himgBit1 = (HBITMAP)LoadImage(NULL,"..\\source\\background\\background2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    // himgdc 에 hBit을 저장하고 hOldBit에 himgdc가 가지고 있던 도화지를 바꿔서 저장해둠
    // 이미지를 가지고 있을 도구 + 도화지
    hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit1);
    // 첫번째 이미지 출력
    TransparentBlt(_hdc, m_BG.posoriginDest.x, m_BG.posoriginDest.y,
        m_BG.recDest.right, m_BG.recDest.bottom,
        himgdc, m_BG.poriginSrc.x, m_BG.poriginSrc.y,
        m_BG.recSrc.right, m_BG.recSrc.bottom, RGB(255, 255, 255));


    // 배경 타일 깔아주는 함수
    //BackgroundTile(_hdc, BACKGROUNDMOVE);

    // 바닥을 보여주는 임시 수식
    m_recClient = ObjManager::GetInstance()->GetRect();
    m_recClient.top = m_recClient.bottom - 300;
    Rectangle(_hdc, m_recClient.left, m_recClient.top, m_recClient.right, m_recClient.bottom);




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




RECT* Background::BackgroundTile(int _itilemove)
{
    /*RECT recTile = ObjManager::GetInstance()->GetRect();
    recTile.top = recTile.bottom - 300;*/

    //Rectangle(_hdc, recTile.left, recTile.top, recTile.right, recTile.bottom);

    return &m_recClient;
}

/*POINT Background::GetRatio(int iwidth, int iheight)
{
    // 화면 비율 구하는 함수
    int imax = 0;
    int imin = 0;
    int igcd = 0;
    int itemp = 0;

    RECT rectemp = ObjManager::GetInstance()->GetRect();

    POINT proit = { 0,0 };

    // 큰 값을 imax에 넣어주기
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
