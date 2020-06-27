#include "Object.h"
#include "Mainfrm.h"


void Object::Animation(HDC _hdc, ST_OBJECT _obj, char* _cname)
{
	//이미지 크기 w - 32px h - 28px / 35px 간격 3px
	
	PAINTSTRUCT ps;
	HWND hWnd = Mainfrm::GethWnd();
	// 이미지를 담을 핸들 생성
	HDC hdc = 0;
	HBITMAP hOldbit;
	// 이미지를 담을 hbitmap
	HBITMAP hImage;
	
	hdc = CreateCompatibleDC(hdc);
	//hImage = (HBITMAP)LoadImage(NULL, _cname, IMAGE_BITMAP, 0, 0, NULL);
	hImage = LoadBitmap(NULL, _cname);

	hOldbit = (HBITMAP)SelectObject(hdc, hImage);

	// object를 출력 
	TransparentBlt(_hdc, _obj.imgpos.x, _obj.imgpos.y, _obj.iimgwitdh, _obj.iimgheight,
		hdc, _obj.imgstartpos.x, _obj.imgstartpos.y, _obj.imgpos.x, _obj.imgpos.y, NULL);

	if (hdc != NULL)
	{
		DeleteDC(hdc);
	}

	return;
}