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
/*void Background::Run(HWND _hWnd, HDC _hdc, HINSTANCE _hInst, RECT _recClient)
{
    static int ibitx1 = 0;
    static int ibitx2 = 0;
    static int ibitxclient = 0;
    static bool bx = false;

    // 그림 저장할 도화지 변수 
    static HBITMAP hBit = NULL;
    // 이전 도화지 저장해줄 변수
    HBITMAP hOldBit = NULL;
    // 메모리 dc
    HDC hMemdc = CreateCompatibleDC(_hdc);
    static RECT recbackground1 = { NULL, };
    static RECT recbackground2 = { NULL, };
    static int ix1 = 0;
    static int ix2 = 1000;
    static int istartpointx = 0;
    static int istartpointy = 0;
    static int iclientprint = 0;

    // 비트맵을 hBIt에 뿌려주기
    hBit = (HBITMAP)LoadBitmap(_hInst, MAKEINTRESOURCE(IDB_BACKGROUND1));

    // hdc와 hMemdc를 바꿔줌
    BitBlt(_hdc, 0, 0, _recClient.right, _recClient.bottom, hMemdc, 0, 0, SRCCOPY);

    // hMemdc 를 선택하고 hOldBit에 가지고 있던 도화지를 바꿔서 저장해둠
    hOldBit = (HBITMAP)SelectObject(hMemdc, hBit);

    // 이미지를 넣을 class 불러옴
    ObjectImage obimg1;
    ObjectImage obimg2;

    // rect에 이미지 좌표 가져오기
    //recbackground1 = { 950, 200 , _recClient.right , _recClient.bottom };
    //recbackground2 = { 950, 200 , _recClient.right , _recClient.bottom };
    //recbackground1 = { 1000 + ix1, 200 , 1800 , 400 };
    //recbackground2 = { 1000 + ix2, 200 , 1800 , 400 };

    // 처음에 화면1을 출력
    if (ix1 <= 600)
    {
        // 이미지 로딩을 하는 함수에 background 넣어줌!
        hMemdc = obimg1.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, istartpointx, istartpointy,
            recbackground1.left + ix1, recbackground1.top, 460, 240);
        ix1 += 3;
    }
    else if (ix2 >= 600)
    {
        //ix1 = 0;
        //ix2 = 0;
    }

    // 화면1이 다 되었을 경우 화면2 출력
    if (ix2 < 600)
    {
        // 루프 돌게 바꿔야 함....
        if (istartpointx >= 0 || istartpointx < recbackground2.right)
        {
            istartpointx += 3;
        }
        else if(istartpointx >= recbackground2.right)
        {
            istartpointx = 0;
        }
        // 이미지 로딩을 하는 함수에 background 넣어줌!
        hMemdc = obimg2.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, recbackground2.right - istartpointx, istartpointy,
            recbackground1.left + ix2, recbackground1.top, 460, 240);

        if(istartpointx <= 0)
        {
            // 여기도 안 들어옴
            ix2 += 3;
        }
    }
    else if (ix1 >= 600 - recbackground1.right)
    {
        ix2 = 0;
    }

    
    // 첫번째 이미지 출력
    if (ix1 >= 0 && ix1 < 601)
    {
    // 이미지 로딩을 하는 함수에 background 넣어줌!
    hMemdc = obimg1.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, istartpointx, istartpointy,
        recbackground1.left, recbackground1.top, 460, 240);
    ix1 += 3;
    }
    else if (600 <= ix1 && 600 <= ix2)
    {
        ix2 = 0;
        iclientprint = _recClient.right;
    }
    // 두번째 이미지 출력
    else if (ix2 >= 0 && ix2 < 601)
    {
        hMemdc = obimg2.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, _recClient.right, istartpointy,
            recbackground2.left, recbackground2.top, 460, 240);
        ix2 += 3;
        if (ix2 >= 600)
        {
            // 초기화 상태로 되돌려줘서 다시 처음부터 시작할 수 있도록 해주기
            ix2 = 1000;
            ix1 = 0;
            iclientprint = _recClient.right;
        }
    }

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
    
    // 남은 건 이 이미지를 어떻게 옮기느냐 하는 것이다... 

    // 다시 hOldBit 으로 갈아주기
    SelectObject(hMemdc, hOldBit);

    // dc 해제
    DeleteDC(hMemdc);
    // HBITMAP 해제
    DeleteObject(hBit);

	return;
};*/

void Background::Run(HWND _hWnd, HDC _hdc, HINSTANCE _hInst, RECT _recClient)
{
    // 그림 저장할 도화지 변수 
    static HBITMAP hBit = NULL;
    // 이전 도화지 저장해줄 변수
    HBITMAP hOldBit = NULL;
    // 메모리 dc
    HDC hMemdc = CreateCompatibleDC(_hdc);
    /*static RECT recbackground1 = { NULL, };
    static RECT recbackground2 = { NULL, };
    static int ix1 = 0;
    static int ix2 = 1000;
    static int istartpointx = 0;
    static int istartpointy = 0;
    static int iclientprint = 0;*/
    // 이미지의 사이즈를 저장할 변수
    POINT pimagesize = { 700 , 230 };
    // 이미지 내부의 출력 스타트 좌표값
    POINT pimagestartposition = { 1000, 180 };
    // 이미지의 좌표를 지정해줄 변수
    static POINT pbackgroundposition1 = { 0, };
    static POINT pbackgroundposition2 = { 0, };

    // 비트맵을 hBIt에 뿌려주기
    hBit = (HBITMAP)LoadBitmap(_hInst, MAKEINTRESOURCE(IDB_BACKGROUND1));

    // hdc와 hMemdc를 바꿔줌
    BitBlt(_hdc, 0, 0, _recClient.right, _recClient.bottom, hMemdc, 0, 0, SRCCOPY);

    // hMemdc 를 선택하고 hOldBit에 가지고 있던 도화지를 바꿔서 저장해둠
    hOldBit = (HBITMAP)SelectObject(hMemdc, hBit);

    // 이미지를 넣을 class 불러옴
    ObjectImage obimg1;
    ObjectImage obimg2;

    // 첫번째 이미지 출력
    /*if (ix1 >= 0 && ix1 < 601)
    {
        // 이미지 로딩을 하는 함수에 background 넣어줌!
        hMemdc = obimg1.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, istartpointx, istartpointy,
            recbackground1.left, recbackground1.top, 460, 240);
        ix1 += 3;
    }
    else if (600 <= ix1 && 600 <= ix2)
    {
        ix2 = 0;
        iclientprint = _recClient.right;
    }
    // 두번째 이미지 출력
    else if (ix2 >= 0 && ix2 < 601)
    {
        hMemdc = obimg2.ImageLoading(_hWnd, _hdc, hMemdc, _hInst, _recClient, hBit, _recClient.right, istartpointy,
            recbackground2.left, recbackground2.top, 460, 240);
        ix2 += 3;
        if (ix2 >= 600)
        {
            // 초기화 상태로 되돌려줘서 다시 처음부터 시작할 수 있도록 해주기
            ix2 = 1000;
            ix1 = 0;
            iclientprint = _recClient.right;
        }
    }*/

    // 만약 이미지1의 좌표가 0과 같으면
    if (pbackgroundposition1.x == _recClient.left)
    {
        // 좌표값 설정해주기
        // 첫번째 이미지의 좌표값
        pbackgroundposition1.x = 0;
        // 두번째 이미지의 좌표값
        pbackgroundposition2.x = pimagestartposition.x;
    }
    // 만약 이미지2의 좌표가 0과 같으면
    else if (pbackgroundposition2.x == _recClient.left)
    {
        // 좌표값 바꿔주기
        // 두번째 이미지의 좌표값
        pbackgroundposition2.x = 0;
        // 첫번째 이미지의 좌표값
        pbackgroundposition1.x = pimagestartposition.x;
    }

    // class에 좌표값 넣어주기
    obimg1.SetPosition(pbackgroundposition1);
    obimg2.SetPosition(pbackgroundposition2);

    // 이미지 로딩하기
    obimg1.ImageLoading(_hdc, _recClient, hMemdc, pimagestartposition, pimagesize);
    obimg2.ImageLoading(_hdc, _recClient, hMemdc, pimagestartposition, pimagesize);

    // 만약 이미지1의 좌표가 윈도우 left 값보다 작나 같으면 
    if (pbackgroundposition1.x <= _recClient.left)
    {
        // 이미지 1의 포지션을 왼쪽으로 3씩 이동
        pbackgroundposition1.x -= 3;
        obimg1.SetPosition(pbackgroundposition1);
        // 만약 윈도우 크기 + 좌표 위치가 윈도우 left 좌표보다 작을 때
        if (pbackgroundposition1.x + _recClient.right <= _recClient.left)
        {
            // 좌표 초기화
            pbackgroundposition1.x = 0;
        }
    }
    // 만약 이미지2의 좌표가 윈도우 left 값보다 작나 같으면 
    else if (pbackgroundposition2.x <= _recClient.left)
    {
        // 이미지 2의 포지션을 왼쪽으로 3씩 이동
        pbackgroundposition2.x -= 3;
        obimg2.SetPosition(pbackgroundposition2);
        // 만약 윈도우 크기 + 좌표 위치가 윈도우 left 좌표보다 작을 때
        if (pbackgroundposition2.x + _recClient.right <= _recClient.left)
        {
            // 좌표 초기화
            pbackgroundposition2.x = 0;
        }
    }

    /*
        이미지 2가 위치에 맞춰서 함께 이동할 수 있도록 수정
        이미지가 비율대로 나오지 않음. 비율 측정하여 곱해두기
        할 수 잇 다 
    */

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
