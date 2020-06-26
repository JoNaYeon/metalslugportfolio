#include "Background.h"

#include "Object.h"
#include "RendManager.h"
#include "framework.h"
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

// 오브젝트 출력
void Background::Render(HDC& _hdc, HWND& _hWnd)
{
    // RendManager 에 있던 것을 가져오기 
    RECT recClient = RendManager::GetInstance()->GetRect();
    //이미지를 들고 있을 메모리 dc
    HDC himgdc = CreateCompatibleDC(_hdc);

    // 이미지를 저장할 HBITMAP
    HBITMAP himgBit = CreateCompatibleBitmap(_hdc, recClient.right, recClient.bottom);
    // 이전 도화지 저장해줄 변수
    HBITMAP hOldBit_img = NULL;

    // client 화면 크기를 안 받아오고 있으니 화면에 아무것도 안 뜨죠! 
    GetClientRect(_hWnd, &recClient);

    // 이미지의 사이즈를 저장할 변수
    m_pimagesize = { BACKGROUNDX , BACKGROUNDY };
    // 이미지 내부의 출력 스타트 좌표값
    m_pimagestartposition = { BACKGROUNDPOSX, BACKGROUNDPOSY };
    // 이미지의 좌표를 지정해줄 변수

    // 비트맵을 hBIt에 뿌려주기
    himgBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BACKGROUND1));

    // himgdc 에 hBit을 저장하고 hOldBit에 himgdc가 가지고 있던 도화지를 바꿔서 저장해둠
    // 이미지를 가지고 있을 도구 + 도화지
    hOldBit_img = (HBITMAP)SelectObject(himgdc, himgBit);

    // 이미지 1의 포지션을 왼쪽으로 BACKGROUNDMOVE 씩 이동
    m_pbackgroundposition1.x -= BACKGROUNDMOVE;
    // 이미지 2의 포지션을 왼쪽으로 BACKGROUNDMOVE씩 이동
    m_pbackgroundposition2.x -= BACKGROUNDMOVE;

    if (m_pbackgroundposition1.x <= -(2*BACKGROUNDX + recClient.right))
    {
        // 좌표 초기화
        m_pbackgroundposition1.x = recClient.right;
    }

    if (m_pbackgroundposition2.x <= -(2 * BACKGROUNDX + recClient.right))
    {
        // 좌표 초기화
        m_pbackgroundposition2.x = recClient.right;
    }

    // class에 좌표값 넣어주기
    m_obimg1.SetPosition(m_pbackgroundposition1);
    m_obimg2.SetPosition(m_pbackgroundposition2);

    // 이미지 로딩하기
    m_obimg1.ImageLoading(_hdc, recClient, himgdc, m_pimagestartposition, m_pimagesize);
    m_obimg2.ImageLoading(_hdc, recClient, himgdc, m_pimagestartposition, m_pimagesize);

    // 다시 hOldBit 으로 갈아주기
    SelectObject(himgdc, hOldBit_img);

    // dc 해제
    DeleteDC(himgdc);
    // HBITMAP 해제
    DeleteObject(himgBit);

	return;
};

// 오브젝트 파괴
void Background::Destroy()
{
	return;
};
