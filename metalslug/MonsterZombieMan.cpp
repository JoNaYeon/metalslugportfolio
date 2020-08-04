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
	// ���� ����ü ����
	m_Monster.recSrc = { 0, 0, MONSTERWANIMATION, MONSTERHANIMATION };
	m_Monster.poriginSrc = { 0,0 };
	m_Monster.recDest = { 0, 0, MONSTERWANIMATION, MONSTERHANIMATION };
	m_Monster.posoriginDest = { 1000, 400 };
	m_Monster.iobjmove = MONSTERMOVE;
	m_Monster.iWidthnum = MONSTERWNUM;
	m_Monster.iHightnum = MONSTERHNUM;

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
		Aniimage(m_Monster);

		// ���� �ð��� ���� �ð����� ��ü
		m_dPrevTime = m_dcurTime;
	}

	// ��� ���� �� �� �ְ� ���ִ� �Լ�
	ObjStand(&m_Monster);

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
	TransparentBlt(_hdc, m_Monster.posoriginDest.x, m_Monster.posoriginDest.y,
		m_Monster.recDest.right * PLAYERSIZE, m_Monster.recDest.bottom * PLAYERSIZE,
		// �̹��� ũ�� Ű����� *4 �ص�.
		hobjdc, m_Monster.poriginSrc.x, m_Monster.poriginSrc.y,
		m_Monster.recSrc.right, m_Monster.recSrc.bottom, RGB(255, 255, 255));

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