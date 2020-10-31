#include "MonsterZombieMan.h"
#include "ObjManager.h"
#include "define.h"
#include "Mainfrm.h"
#include "Background.h"


// 생성자
MonsterZombieMan::MonsterZombieMan()
{
	m_ihp = 100;
	m_istrength = 0;
	m_ispeed = 0;

	m_iobjstate = E_USERSTATE_IDLE;
	m_fdelay = 0.5;
	m_iobjmove = MONSTERMOVE;

	// 몬스터 구조체 정의
	m_DisTop.ptSrcPos = { 0,0 }; 
	m_DisTop.ptDestPos = { 1000, 400 };
	m_DisTop.ptDestSize = { MONSTERWANIMATION, MONSTERHANIMATION };
	

	m_ImgTop.iWidthnum = MONSTERWNUM;
	m_ImgTop.iHightnum = MONSTERHNUM;
	m_ImgTop.ptSrcSize = { MONSTERWANIMATION, MONSTERHANIMATION };

	m_fdelay = 0.5;

	m_recHitBox = { m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		m_DisTop.ptDestPos.x + (m_DisTop.ptDestSize.x * PLAYERSIZE), m_DisTop.ptDestPos.y + (m_DisTop.ptDestSize.y * PLAYERSIZE) };

	m_bjump = false;
	m_bsee = true;
	m_bypos = true;
};


// 오브젝트 초기화 (오버라이딩)
void MonsterZombieMan::Init()
{
	return;
};

// 오브젝트 움직임 (오버라이딩)
void MonsterZombieMan::Run()
{
	if (m_dcurTime - m_dPrevTime >= 0.1f * m_fdelay)
	{
		// object 상태 움직임 변경 
		Aniimage(m_DisTop, m_ImgTop);

		// 이전 시간을 현재 시간으로 대체
		m_dPrevTime = m_dcurTime;
	}

	// 중력 적용
	Gravity(&m_DisTop, EOBJECT_MONSTER);

	// 움직임 패턴 적용
	//MovePattern();

	// HitBox 갱신
		m_recHitBox = { m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		m_DisTop.ptDestPos.x + (m_DisTop.ptDestSize.x * PLAYERSIZE), m_DisTop.ptDestPos.y + (m_DisTop.ptDestSize.y * PLAYERSIZE) };

	return;
};

// 오브젝트 출력 (오버라이딩)
void MonsterZombieMan::Render(HDC& _hdc, HWND& _hWnd)
{
	// 이미지의 hdc
	HDC hobjdc;
	// 이미지 로드받을 hbitmap
	HBITMAP hMonsterobjBit;
	// 이미지 저장받을 hbitmap
	HBITMAP holdBit;

	// 범위 리셋 
	RECT recClient = ObjManager::GetInstance()->GetRect();
	GetClientRect(_hWnd, &recClient);

	// 이미지 출력할 hdc 출력 
	hobjdc = CreateCompatibleDC(_hdc);

	// 비트맵을 hBIt에 뿌려주기
	// hinst를 null로 하지 말자 
	hMonsterobjBit = (HBITMAP)LoadImage(NULL, "..\\source\\monster\\zombie1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// oldbit 에 상체 이미지 저장 
	holdBit = (HBITMAP)SelectObject(hobjdc, hMonsterobjBit);

	// 몬스터 이미지 출력
	/*TransparentBlt(_hdc, m_DisMon.ptDestPos.x, m_DisMon.ptDestPos.y,
		m_DisMon.ptDestSize.x * PLAYERSIZE, m_DisMon.ptDestSize.y * PLAYERSIZE,
		hobjdc, m_DisMon.ptSrcPos.x, m_DisMon.ptSrcPos.y,
		m_DisMon.ptDestSize.x, m_DisMon.ptDestSize.y, RGB(255, 255, 255));*/
	// 몬스터 이미지 출력
	TransparentBlt(_hdc, m_DisTop.ptDestPos.x, m_DisTop.ptDestPos.y,
		m_DisTop.ptDestSize.x * PLAYERSIZE, m_DisTop.ptDestSize.y * PLAYERSIZE,
		hobjdc, m_DisTop.ptSrcPos.x, m_DisTop.ptSrcPos.y,
		m_DisTop.ptDestSize.x, m_DisTop.ptDestSize.y, RGB(255, 255, 255));

	// 히트박스 디스플레이
	Rectangle(_hdc, m_recHitBox.left, m_recHitBox.top, m_recHitBox.right, m_recHitBox.bottom);


	// 시간을 받아옴
	m_dcurTime = timeGetTime();

	// oldbit로 바꿔주기
	SelectObject(hobjdc, holdBit);


	DeleteDC(hobjdc);
	DeleteObject(hMonsterobjBit);
	
	return;
};

// 오브젝트 파괴 (오버라이딩)
void MonsterZombieMan::Destroy()
{
	return;
};


// 몹 공격 - 침뱉기 애니메이션
void MonsterZombieMan::Attack()
{
	return;
};

bool MonsterZombieMan::bObjDead()
{
	if (m_ihp <= 0)
	{
		return true;
	}

	return false;
}

void MonsterZombieMan::MovePattern()
{
	static int imovepattern = 0;
	static bool bmoveright = false;

	// #임시 - 움직임 패턴 설정해주기 
	/*if (m_bsee == true)
	{
		// if (m_DisMon.ptDestPos.x >= m_DisTop.ptDestPos.x) { m_DisMon.ptDestPos.x -= MONSTERMOVE; } else ...

		// 움직임의 영역 설정해주기
		if (imovepattern >= 0)
		{
			m_DisMon.ptDestPos.x -= MONSTERMOVE;
		}
		else if(imovepattern <= 0)
		{
			m_DisMon.ptDestPos.x += MONSTERMOVE;
		}
	}*/

	if (bmoveright == false)
	{
		m_DisTop.ptDestPos.x -= MONSTERMOVE;
		//m_DisMon.ptDestPos.x -= MONSTERMOVE;
		imovepattern += MONSTERMOVE;

		// 만약 100px 이상 움직였을 경우 반대로 
		if (imovepattern >= 100)
		{
			bmoveright = true;
		}
	}
	else
	{
		//m_DisMon.ptDestPos.x += MONSTERMOVE;
		m_DisTop.ptDestPos.x += MONSTERMOVE;
		imovepattern -= MONSTERMOVE;

		// 만약 원상태로 돌아왔을 경우 반대로
		if (imovepattern <= 0)
		{
			bmoveright = false;
		}
	}

	return;
}