#include "Background.h"

#include "metalslug.h"
#include "define.h"

// 오브젝트 초기화
void Background::Init()
{
	return;
};

void Background::Run()
{
    return; 
}

// 오브젝트 움직임

void Background::Run(HWND _hWnd, HDC& _hdc, HINSTANCE _hInst, RECT _recClient)
{
    // 이미지를 그려줄 메모리 dc
    HDC hMemdc = CreateCompatibleDC(_hdc);
    //이미지를 들고 있을 메모리 dc
    HDC himgdc = CreateCompatibleDC(_hdc);

    // 이미지를 저장할 HBITMAP
    HBITMAP himgBit = CreateCompatibleBitmap(_hdc, _recClient.right, _recClient.bottom);
    // Memdc 를 저장할 HBITMAP
    HBITMAP hBit = CreateCompatibleBitmap(_hdc, _recClient.right, _recClient.bottom);
    // 이전 도화지 저장해줄 변수
    HBITMAP hOldBit_img = NULL;
    HBITMAP hOldBit_mem = NULL;

    // 이미지의 사이즈를 저장할 변수
    m_pimagesize = { BACKGROUNDX , BACKGROUNDY };
    // 이미지 내부의 출력 스타트 좌표값
    m_pimagestartposition = { BACKGROUNDPOSX, BACKGROUNDPOSY };
    // 이미지의 좌표를 지정해줄 변수

    // 비트맵을 hBIt에 뿌려주기
    himgBit = (HBITMAP)LoadBitmap(_hInst, MAKEINTRESOURCE(IDB_BACKGROUND1));

    // himgdc 에 hBit을 저장하고 hOldBit에 himgdc가 가지고 있던 도화지를 바꿔서 저장해둠
    // 이미지를 가지고 있을 도구 + 도화지
    hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit);
    // 이미지를 그려줄 도구 + 도화지
    hOldBit_mem = (HBITMAP)SelectObject(hMemdc, hBit);


    // 이미지 로테이션 좌표 설정
    // 만약 이미지1의 시작 좌표가 윈도우의 left 좌표와 같거나 윈도우의 right 좌표와 같으면
    /*if (m_pbackgroundposition1.x == _recClient.left && m_pbackgroundposition2.x > _recClient.left)
    {
        // 좌표값 설정해주기
        // 첫번째 이미지의 좌표값
        m_pbackgroundposition1.x = 0;
        // 두번째 이미지의 좌표값은 이미지의 크기
        m_pbackgroundposition2.x = BACKGROUNDX;
    }
    // 만약 이미지2의 좌표가 0과 같으면
    else if (m_pbackgroundposition2.x == _recClient.left && m_pbackgroundposition1.x > _recClient.left)
    {
        // 좌표값 바꿔주기
        // 두번째 이미지의 좌표값
        m_pbackgroundposition2.x = 0;
        // 첫번째 이미지의 좌표값은 이미지의 크기
        m_pbackgroundposition1.x = BACKGROUNDX;
    }*/


    // 만약 이미지1의 좌표가 윈도우 left 값보다 작거나 같으면 
    if (m_pbackgroundposition1.x <= _recClient.right)
    {
        // 이미지 1의 포지션을 왼쪽으로 BACKGROUNDMOVE 씩 이동
        m_pbackgroundposition1.x -= BACKGROUNDMOVE;
        // 만약 윈도우 크기 + 좌표 위치가 윈도우 left 좌표보다 작을 때
        if (m_pbackgroundposition1.x + _recClient.right <= _recClient.left)
        {
            // 좌표 초기화
            m_pbackgroundposition1.x = _recClient.right;
        }
    }
    
    // 만약 이미지2의 좌표가 윈도우 left 값보다 작나 같으면 
    if (m_pbackgroundposition2.x <= _recClient.right)
    {
        // 이미지 2의 포지션을 왼쪽으로 BACKGROUNDMOVE씩 이동
        m_pbackgroundposition2.x -= BACKGROUNDMOVE;
        // 만약 윈도우 크기 + 좌표 위치가 윈도우 left 좌표보다 작을 때
        if (m_pbackgroundposition2.x + _recClient.right <= _recClient.left)
        {
            // 좌표 초기화
            m_pbackgroundposition2.x = _recClient.right;
        }
    }

    // class에 좌표값 넣어주기
    m_obimg1.SetPosition(m_pbackgroundposition1);
    m_obimg2.SetPosition(m_pbackgroundposition2);


    // 이미지 로딩하기
    m_obimg1.ImageLoading(hMemdc, _recClient, himgdc, m_pimagestartposition, m_pimagesize);
    m_obimg2.ImageLoading(hMemdc, _recClient, himgdc, m_pimagestartposition, m_pimagesize);
    
    // hMemdc에 있던 그림을 _hdc에 옮겨담기 
    BitBlt(_hdc, 0, 0, _recClient.right, _recClient.bottom, hMemdc, 0, 0, SRCCOPY);


    // 다시 hOldBit 으로 갈아주기
    SelectObject(himgdc, hOldBit_img);
    SelectObject(hMemdc, hOldBit_mem);

    // dc 해제
    DeleteDC(hMemdc);
    DeleteDC(himgdc);
    // HBITMAP 해제
    DeleteObject(hBit);
    DeleteObject(himgBit);

    return;
};

// 오브젝트 출력
void Background::Render()
{
	return;
};

// 오브젝트 파괴
void Background::Destroy()
{
	return;
};
