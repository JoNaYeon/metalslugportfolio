#include "MonsterZombieMan.h"
#include "ObjManager.h"
#include "define.h"
#include "Mainfrm.h"
#include "Background.h"


// ������
MonsterZombieMan::MonsterZombieMan()
{
	m_iobjstate = E_USERSTATE_IDLE;
	m_fdelay = 0.5;
	m_iobjmove = MONSTERMOVE;

	// ���� ����ü ����
	m_DisMon.ptSrcPos = { 0,0 };
	m_DisMon.ptDestPos = { 1000, 400 };
	m_DisMon.ptDestSize = { MONSTERWANIMATION, MONSTERHANIMATION };
	

	m_ImgMon.iWidthnum = MONSTERWNUM;
	m_ImgMon.iHightnum = MONSTERHNUM;
	m_ImgMon.ptSrcSize = { MONSTERWANIMATION, MONSTERHANIMATION };

	m_fdelay = 0.5;
};


// ������Ʈ �ʱ�ȭ (�������̵�)
void MonsterZombieMan::Init()
{
	return;
};

// ������Ʈ ������ (�������̵�)
void MonsterZombieMan::Run()
{
	if (m_dcurTime - m_dPrevTime >= 0.1f * m_fdelay)
	{
		// object ���� ������ ���� 
		//Animation(_hdc, m_Monster, m_iobjstate);
		Aniimage(m_DisMon, m_ImgMon);

		// ���� �ð��� ���� �ð����� ��ü
		m_dPrevTime = m_dcurTime;
	}

	// ��� ���� �� �� �ְ� ���ִ� �Լ�
	//ObjStand(&m_Monster);

	return;
};

// ������Ʈ ��� (�������̵�)
void MonsterZombieMan::Render(HDC& _hdc, HWND& _hWnd)
{
	// �̹����� hdc
	HDC hobjdc;
	// �̹��� �ε���� hbitmap
	HBITMAP hMonsterobjBit;
	// �̹��� ������� hbitmap
	HBITMAP holdBit;

	// ���� ���� 
	RECT recClient = ObjManager::GetInstance()->GetRect();
	GetClientRect(_hWnd, &recClient);

	// �̹��� ����� hdc ��� 
	hobjdc = CreateCompatibleDC(_hdc);

	// ��Ʈ���� hBIt�� �ѷ��ֱ�
	// hinst�� null�� ���� ���� 
	hMonsterobjBit = (HBITMAP)LoadImage(NULL, "..\\source\\monster\\zombie1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// oldbit �� ��ü �̹��� ���� 
	holdBit = (HBITMAP)SelectObject(hobjdc, hMonsterobjBit);

	// ���� �̹��� ���
	TransparentBlt(_hdc, m_DisMon.ptDestPos.x, m_DisMon.ptDestPos.y,
		m_DisMon.ptDestSize.x * PLAYERSIZE, m_DisMon.ptDestSize.y * PLAYERSIZE,
		hobjdc, m_DisMon.ptSrcPos.x, m_DisMon.ptSrcPos.y,
		m_DisMon.ptDestSize.x, m_DisMon.ptDestSize.y, RGB(255, 255, 255));


	// �ð��� �޾ƿ�
	m_dcurTime = timeGetTime();

	// oldbit�� �ٲ��ֱ�
	SelectObject(hobjdc, holdBit);


	DeleteDC(hobjdc);
	DeleteObject(hMonsterobjBit);
	
	return;
};

// ������Ʈ �ı� (�������̵�)
void MonsterZombieMan::Destroy()
{
	return;
};


// �� ���� - ħ��� �ִϸ��̼�
void MonsterZombieMan::Attack()
{
	return;
};

bool MonsterZombieMan::bObjDead()
{
	std::vector<Object*> vectemp = ObjManager::GetInstance() -> GetVector(EOBJECT_MONSTER);
	

	return false;
}