#include "MonsterZombieMan.h"
#include "ObjManager.h"
#include "define.h"
#include "Mainfrm.h"


// ������
MonsterZombieMan::MonsterZombieMan()
{
	m_iobjstate = E_USERSTATE_IDLE;
	m_fdelay = 0.5;
	// ���� ����ü ����
	m_Monster.recSrc = { 0, 0, MONSTERWANIMATION, MONSTERHANIMATION };
	m_Monster.poriginSrc = { 0,0 };
	m_Monster.recDest = { 0, 0, MONSTERWANIMATION, MONSTERHANIMATION };
	m_Monster.posoriginDest = { 1000, 500 };
	m_Monster.iobjmove = MONSTERMOVE;
	m_Monster.iWidthnum = MONSTERWNUM;
	m_Monster.iHightnum = MONSTERHNUM;
};


// ������Ʈ �ʱ�ȭ (�������̵�)
void MonsterZombieMan::Init()
{
	return;
};

// ������Ʈ ������ (�������̵�)
void MonsterZombieMan::Run()
{
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


	// ��ü �̹����� ������ HBITMAP
	//hMonsterobjBit = CreateCompatibleBitmap(_hdc, m_Monster.recSrc.right, m_Monster.recSrc.bottom);


	// ��Ʈ���� hBIt�� �ѷ��ֱ�
	// hinst�� null�� ���� ���� 
	hMonsterobjBit = (HBITMAP)LoadBitmap(hInst, MAKEINTRESOURCE(ZOMBIEMAN));
	// oldbit �� ��ü �̹��� ���� 
	holdBit = (HBITMAP)SelectObject(hobjdc, hMonsterobjBit);

	// ���� �̹��� ���
	TransparentBlt(_hdc, m_Monster.posoriginDest.x, m_Monster.posoriginDest.y,
		m_Monster.recDest.right * 4, m_Monster.recDest.bottom * 4,
		// �̹��� ũ�� Ű����� *4 �ص�.
		hobjdc, m_Monster.poriginSrc.x, m_Monster.poriginSrc.y,
		m_Monster.recSrc.right, m_Monster.recSrc.bottom, RGB(255, 255, 255));


	// �ð��� �޾ƿ�
	m_dcurTime = timeGetTime();

	// ���� ���� �ð����� ���� �ð��� 0.1float ������ �� 
	if (m_dcurTime - m_dPrevTime >= 0.1f * m_fdelay)
	{
		// object ���� ������ ���� 
		Animation(_hdc, m_Monster, m_iobjstate);

		// ���� �ð��� ���� �ð����� ��ü
		m_dPrevTime = m_dcurTime;
	}

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
	return false;
}