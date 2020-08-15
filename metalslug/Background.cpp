#include "Background.h"

#include "Object.h"
#include "ObjManager.h"

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
    // 배경화면에 타일을 깔아주는 함수 
    BackgroundTile();

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
    Rectangle(_hdc, m_recHitBox.left, m_recHitBox.top, m_recHitBox.right, m_recHitBox.bottom);


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




void Background::BackgroundTile()
{
    POINT ptTile = { 50,50 };

    /*for (int i = 0; i < 500; i++)
    {
        RECT recTile = { 0,0,0,0 };
    }*/
    
    // 임시로 깔아둠
    m_recHitBox = { 0, 600, 2000, 2000 };

    return;
}

bool Background::bObjDead()
{
    return false;
}
