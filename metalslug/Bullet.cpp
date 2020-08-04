#include "Bullet.h"
#include "InputManager.h"
#include "ObjManager.h"
#include "define.h"
#include "Monster.h"


Bullet::Bullet(POINT _playerpos)
{
	// dest = ��� , src = ����
	// ȭ�� �󿡼� ��𿡼����� �̹����� ����� ������ ���� 
	m_bullet.posoriginDest = { _playerpos.x + (FIREPLAYERWANIMATION * 3), _playerpos.y + (FIREPLAYERHANIMATION)};
	// ȭ��󿡼��� �̹��� ����/�ʺ� ����
	// left top right bottom
	m_bullet.recDest = { 0, 0, BULLETSIZE, BULLETSIZE };
	// �̹��� ��󿡼� ��� ��ǥ�������� ����� ������ ����
	m_bullet.poriginSrc = { 0, 0 };
	// ����� �̹����� ���� ũ��� ������� ����
	m_bullet.recSrc = { 0, 0, BULLETSIZE, BULLETSIZE };
	m_bullet.iobjmove = BULLETMOVE;
	m_bullet.iWidthnum = BULLETWNUM;
	m_bullet.iHightnum = BULLETHNUM;

	m_fdelay = 0.2;
	
	m_iobjstate = E_GUNSTATE_NORMAL;
};
 

// ������Ʈ �ʱ�ȭ
void Bullet::Init()
{
	return;
};

// ������Ʈ ������
void Bullet::Run()
{
	// Object ����
	switch (m_iobjstate)
	{
		case E_GUNSTATE_NORMAL:
		{
			// �Ѿ� �߻��Ű�� 
			m_bullet.posoriginDest.x += m_bullet.iobjmove;

			// �Ѿ� ���� �� ������ ObjManager ���� ���ְ� ����. 
		}
	break;
	}

	return;
};

// ������Ʈ ���
void Bullet::Render(HDC& _hdc, HWND& _hWnd)
{
	// �̹����� ���� HDC
	HDC hMemdc = NULL;
	// �̹����� ���� hbitmap 
	HBITMAP hbit = NULL;
	HBITMAP holdbit = NULL;

	// client ���� 
	RECT recClient = ObjManager::GetInstance()->GetRect();

	hMemdc = CreateCompatibleDC(_hdc);

	// �̹��� HBITMAP �� �ε��Ͽ� ���� 
	hbit = (HBITMAP)LoadImage(NULL, "..\\source\\weapon\\bullet1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	holdbit = (HBITMAP)SelectObject(hMemdc, hbit);


	// �ð��� �޾ƿ�
	m_dcurTime = timeGetTime();


	TransparentBlt(_hdc, m_bullet.posoriginDest.x, m_bullet.posoriginDest.y, m_bullet.recDest.right, m_bullet.recDest.bottom,
		hMemdc, m_bullet.poriginSrc.x, m_bullet.poriginSrc.y, m_bullet.recSrc.right, m_bullet.recSrc.bottom, RGB(255, 255, 255));


	SelectObject(hMemdc, holdbit);


	DeleteDC(hMemdc);
	DeleteObject(hbit);
	
	return;
};

// ������Ʈ �ı�
void Bullet::Destroy()
{
	return;
};


// �Ѿ� ������
bool Bullet::Hit(ST_OBJECT& _obj)
{
	RECT recHit = { 0,0,0,0 };
	// �ε����� obj�� RECT
	RECT recHitobj = { _obj.posoriginDest.x, _obj.posoriginDest.y,
		_obj.recDest.right, _obj.recDest.bottom };
	// �ε����� bullet�� RECT
	RECT recbullet = { m_bullet.posoriginDest.x, m_bullet.posoriginDest.y,
		m_bullet.recDest.right, m_bullet.recDest.bottom };


	return IntersectRect(&recHit, &recHitobj, &recbullet);
};

void Bullet::ItemState()
{
	return;
}

bool Bullet::bObjDead()
{
	std::vector<Object*> vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_MONSTER);

	for (int i = 0; i < vectemp.size(); i++)
	{
		Monster* monstertemp = (Monster*)vectemp[i];
		

		// client ������ ������ 
		if (this->m_bullet.posoriginDest.x > ObjManager::GetInstance()->GetRect().right
			/*|| this->m_bullet.posoriginDest.x < ObjManager::GetInstance()->GetRect().left
			|| this->m_bullet.posoriginDest.y > ObjManager::GetInstance()->GetRect().bottom
			|| this->m_bullet.posoriginDest.y < ObjManager::GetInstance()->GetRect().bottom*/)
		{
			m_bdead = true;
		}
		// ��򰡿� �΋H���� (intercetcRect())
		else if (Hit(*(monstertemp->GetMonsterObj())) == true)
		{
			monstertemp->bObjDead();

			m_bdead = true;
		}
		else
		{
			m_bdead = false;
		}
	}

	return m_bdead;
}