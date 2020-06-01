#include "Background.h"

#include "framework.h"
#include "metalslug.h"
#include "ObjectImage.h"

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
void Background::Run(HWND _hWnd, HDC _hdc, HINSTANCE _hInst, RECT _recClient)
{
    /*static int ibitx1 = 0;
    static int ibitx2 = 0;
    static int ibitxclient = 0;
    static bool bx = false;*/

    // 그림 저장할 도화지 변수 
    static HBITMAP hBit = NULL;
    // 이전 도화지 저장해줄 변수
    HBITMAP hOldBit = NULL;
    // 메모리 dc
    HDC hMemdc = CreateCompatibleDC(_hdc);

    // 비트맵을 hBIt에 뿌려주기
    hBit = (HBITMAP)LoadBitmap(_hInst, MAKEINTRESOURCE(IDB_BACKGROUND1));

    // hdc와 hMemdc를 바꿔줌
    BitBlt(_hdc, 0, 0, _recClient.right, _recClient.bottom, hMemdc, 0, 0, SRCCOPY);

    // hMemdc 를 선택하고 hOldBit에 가지고 있던 도화지를 바꿔서 저장해둠
    hOldBit = (HBITMAP)SelectObject(hMemdc, hBit);

    // 이미지를 넣을 class 불러옴
    ObjectImage obimg1;
    ObjectImage obimg2;

    // 이미지 로딩을 하는 함수에 background 넣어줌!
    hMemdc = obimg1.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, 960, 180, 460, 240);
    hMemdc = obimg2.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, 960, 180, 460, 240);

    /*
    // ibitx1 > 시작점
    // 시작점이 900픽셀 보다 작을 때에만 그려주기
    if (ibitx1 <= 900)
    {
        
        ibitx1 += 3;
    }
    // 작지 않을 때에는 시작점을 0으로 돌려서 처음부터 다시 그려주게 하기 
    else
    {
        ibitx1 = 0;
    }

    // 만약에 첫번째 그림의 시작점이 500픽셀을 넘었을 때 두번재 그림 그려주기 
    if (ibitx1 >= 500)
    {
        bx = true;
    }

    // 만약에 두번째 그림의 시작점이 클라이언트 x변 길이보다 커질 경우에 
    // 두번째 그림의 시작점을 클라이언트 x변 길이로 고정
    if (ibitxclient >= _recClient.right)
    {
        ibitxclient = _recClient.right;
    }
    // 만약에 클라이언트 x변 길이보다 작을 경우에
    // 시작점을 클라이언트 x변 길이에서 -3씩 해서 오른쪽에서 왼쪽으로 들어가면서 그려지게
    else
    {
        ibitxclient = _recClient.right - ibitx2;
    }

    // 만약에 시작점이 900픽셀보다 커지면 두번째 그림을 그리지 않아 
    if (ibitxclient >= 900)
    {
        ibitx2 = 0;
        bx = false;
    }
    // 900픽셀보다 작으면 그려줌
    else if (bx)
    {
        ibitx2 += 3;
        TransparentBlt(_hdc, ibitxclient, 0, _recClient.right, _recClient.bottom,
            hMemdc, 960, 186, 460, 236, RGB(255, 255, 255));
    }
    */
    // 남은 건 이 이미지를 어떻게 옮기느냐 하는 것이다... 


    // 다시 hOldBit 으로 갈아주기
    SelectObject(hMemdc, hOldBit);

    // dc 해제
    DeleteDC(hMemdc);
    // HBITMAP 해제
    DeleteObject(hBit);

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
