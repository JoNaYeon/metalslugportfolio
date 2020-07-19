#include "Background.h"

#include "Object.h"
#include "ObjManager.h"
//#include "metalslug.h"
#include "define.h"


 
// 생성자
Background::Background()
{
    pBGsize = { BGWSIZE, BGHSIZE };

    m_BG1.iHightnum = 0;
    m_BG1.iWidthnum = 0;
    m_BG1.iobjmove = BACKGROUNDMOVE;
    m_BG1.recSrc = { 0, 0, 0, 0 };
    m_BG1.poriginSrc = { 0, 0 };
    m_BG1.recDest = { 0, 0, 0, 0 };
    m_BG1.posoriginDest = { 0, 0 };

    m_BG2.iHightnum = 0;
    m_BG2.iWidthnum = 0;
    m_BG2.iobjmove = BACKGROUNDMOVE;
    m_BG2.recSrc = { 0, 0, 0, 0 };
    m_BG2.poriginSrc = { 0, 0 };
    m_BG2.recDest = { 0, 0, 0, 0 };
    m_BG2.posoriginDest = { 0, 0 };

    m_ibgTile1 = 0;
    m_ibgTile2 = 0;
};

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



    // ObjManager 에 있던 것을 가져오기 
    RECT recClient = ObjManager::GetInstance()->GetRect();
    // client 화면 크기를 안 받아오고 있으니 화면에 아무것도 안 뜨죠! 
    GetClientRect(_hWnd, &recClient);



    // 이미지 저장할 HDC 생성 
    himgdc = CreateCompatibleDC(_hdc);



    // 첫번째 배경 위치/크기 조정
    m_BG1.recDest.right = pBGsize.x * BGADD;
    m_BG1.recDest.bottom = pBGsize.y * BGADD;
    m_BG1.recSrc.right = pBGsize.x;
    m_BG1.recSrc.bottom = pBGsize.y;
    // 두번째 배경 위치/크기 조정
    m_BG2.recDest.right = pBGsize.x * BGADD;
    m_BG2.recDest.bottom = pBGsize.y * BGADD;
    m_BG2.recSrc.right = pBGsize.x;
    m_BG2.recSrc.bottom = pBGsize.y;



    // 각각의 배경 HBITMAP에 배경 이미지 넣기
    //himgBit1 = CreateCompatibleBitmap(_hdc, m_BG1.recSrc.right, m_BG1.recSrc.bottom);
    //himgBit2 = CreateCompatibleBitmap(_hdc, m_BG2.recSrc.right, m_BG2.recSrc.bottom);



    // 만약 첫번째 배경의 시작점이 client 가로 길이보다 작거나 두번째 배경 가로 길이의 - 보다 작다면 
    if (m_BG1.posoriginDest.x <= recClient.right && m_BG1.posoriginDest.x >= -(m_BG2.recDest.right))
    {
        // 비트맵을 hBIt에 뿌려주기
        himgBit1 = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(BACKGROUND01));
        // himgdc 에 hBit을 저장하고 hOldBit에 himgdc가 가지고 있던 도화지를 바꿔서 저장해둠
        // 이미지를 가지고 있을 도구 + 도화지
        hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit1);
        // 첫번째 이미지 출력
        TransparentBlt(_hdc, m_BG1.posoriginDest.x, m_BG1.posoriginDest.y,
            m_BG1.recDest.right, m_BG1.recDest.bottom,
            himgdc, m_BG1.poriginSrc.x, m_BG1.poriginSrc.y,
            m_BG1.recSrc.right, m_BG1.recSrc.bottom, RGB(255, 255, 255));

        // 이미지 1의 포지션을 왼쪽으로 BACKGROUNDMOVE 씩 이동
        m_BG1.posoriginDest.x -= BACKGROUNDMOVE;

        // 만약 첫번째 배경의 시작점이 (첫번째 배경의 가로 길이 - 배경 가로 길이) 의 - 값보다 작거나
        // 두번째 배경의 시작점이 (두번째 배경의 가로 길이 - client 가로 길이) 의 - 값보다 작다면
        if (m_BG1.posoriginDest.x <= - (m_BG1.recDest.right - recClient.right) 
            && m_BG2.posoriginDest.x <= - (m_BG2.recDest.right - recClient.right))
        {
            m_BG2.posoriginDest.x = recClient.right;
            m_ibgTile2 = 0;
        }
    }



    // 만약 두번째 배경의 시작점이 client 가로 길이보다 작거나 첫번째 배경 가로 길이의 - 보다 작다면 
    if (m_BG2.posoriginDest.x <= recClient.right && m_BG2.posoriginDest.x >= -(m_BG1.recDest.right))
    {
        himgBit2 = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(BACKGROUND01));
        // 이미지를 가지고 있을 도구 + 도화지
        hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit2);
        // 두번재 이미지 출력
        TransparentBlt(_hdc, m_BG2.posoriginDest.x, m_BG2.posoriginDest.y,
            m_BG2.recDest.right, m_BG2.recDest.bottom,
            himgdc, m_BG2.poriginSrc.x, m_BG2.poriginSrc.y,
            m_BG2.recSrc.right, m_BG2.recSrc.bottom, RGB(255, 255, 255));

        // 이미지 1의 포지션을 왼쪽으로 BACKGROUNDMOVE 씩 이동
        m_BG2.posoriginDest.x -= BACKGROUNDMOVE;

        // 만약 두번째 배경의 시작점이 (두번째 배경의 가로 길이 - 배경 가로 길이) 의 - 값보다 작거나
        // 첫번째 배경의 시작점이 (첫번째 배경의 가로 길이 - client 가로 길이) 의 - 값보다 작다면
        if (m_BG2.posoriginDest.x <= - (m_BG2.recDest.right - recClient.right)
            && m_BG1.posoriginDest.x <= - (m_BG1.recDest.right - recClient.right))
        {
            m_BG1.posoriginDest.x = recClient.right;
            m_ibgTile1 = 0;
        }
    }


    // 배경 타일 깔아주는 함수
    //BackgroundTile(_hdc, BACKGROUNDMOVE);

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




void Background::BackgroundTile(HDC _hdc, int _itilemove)
{
    m_ibgTile1 += BACKGROUNDMOVE;
    m_ibgTile2 += BACKGROUNDMOVE;

    Rectangle(_hdc, 0 - m_ibgTile1, 860, 100 * BGADD - m_ibgTile1, 1000);
    //(_hdc, 113 * BGADD, 860 - (11 * BGADD) , 210 * BGADD, 1000);
    Rectangle(_hdc, 113 * BGADD - m_ibgTile1, 860, 95 * BGADD - m_ibgTile1, 1000);
    Rectangle(_hdc, 262 * BGADD - m_ibgTile1, 860, 156 * BGADD - m_ibgTile1, 1000);
    Rectangle(_hdc, 434 * BGADD - m_ibgTile1, 860, 91 * BGADD - m_ibgTile1, 1000);
    Rectangle(_hdc, 606 * BGADD - m_ibgTile1, 860, 147 * BGADD - m_ibgTile1, 1000);

    /*
    Rectangle(_hdc, 0 - m_ibgTile2, 860, 100 * BGADD - m_ibgTile2, 1000);
    //(_hdc, 113 * BGADD, 860 - (11 * BGADD) , 210 * BGADD, 1000);
    Rectangle(_hdc, 113 * BGADD - m_ibgTile2, 860, 95 * BGADD - m_ibgTile2, 1000);
    Rectangle(_hdc, 262 * BGADD - m_ibgTile2, 860, 156 * BGADD - m_ibgTile2, 1000);
    Rectangle(_hdc, 434 * BGADD - m_ibgTile2, 860, 91 * BGADD - m_ibgTile2, 1000);
    Rectangle(_hdc, 606 * BGADD - m_ibgTile2, 860, 147 * BGADD - m_ibgTile2, 1000);
    */


    return;
}

POINT Background::GetRatio(int iwidth, int iheight)
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
}

bool Background::bObjDead()
{
    return false;
}