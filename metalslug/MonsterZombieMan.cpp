#include "MonsterZombieMan.h"
#include "ObjManager.h"
#include "define.h"
#include "Mainfrm.h"
#include "Background.h"


// 생성자
MonsterZombieMan::MonsterZombieMan()
{
	m_iobjstate = E_USERSTATE_IDLE;
	m_fdelay = 0.5;
	// 몬스터 구조체 정의
	m_Monster.recSrc = { 0, 0, MONSTERWANIMATION, MONSTERHANIMATION };
	m_Monster.poriginSrc = { 0,0 };
	m_Monster.recDest = { 0, 0, MONSTERWANIMATION, MONSTERHANIMATION };
	m_Monster.posoriginDest = { 1000, 400 };
	m_Monster.iobjmove = MONSTERMOVE;
	m_Monster.iWidthnum = MONSTERWNUM;
	m_Monster.iHightnum = MONSTERHNUM;

	m_fdelay = 0.5;
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
		//Animation(_hdc, m_Monster, m_iobjstate);
		Aniimage(m_Monster);

		// 이전 시간을 현재 시간으로 대체
		m_dPrevTime = m_dcurTime;
	}

	// 배경 위에 설 수 있게 해주는 함수
	ObjStand(&m_Monster);

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
	TransparentBlt(_hdc, m_Monster.posoriginDest.x, m_Monster.posoriginDest.y,
		m_Monster.recDest.right * PLAYERSIZE, m_Monster.recDest.bottom * PLAYERSIZE,
		// 이미지 크기 키우려고 *4 해둠.
		hobjdc, m_Monster.poriginSrc.x, m_Monster.poriginSrc.y,
		m_Monster.recSrc.right, m_Monster.recSrc.bottom, RGB(255, 255, 255));

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
	std::vector<Object*> vectemp = ObjManager::GetInstance() -> GetVector(EOBJECT_MONSTER);
	

	return false;
}