#include "Bullet.h"
#include "InputManager.h"
#include "ObjManager.h"
#include "define.h"
#include "Monster.h"


Bullet::Bullet(POINT _playerpos)
{
	// dest = ��� , src = ����
	m_DisBullet.ptSrcPos = { 0, 0 };
	m_DisBullet.ptDestSize = { BULLETSIZE, BULLETSIZE };
	m_DisBullet.ptDestPos = { _playerpos.x + (FIREPLAYERWANIMATION * 3), _playerpos.y + (FIREPLAYERHANIMATION) };

	m_iobjmove = BULLETMOVE;

	m_ImgBullet.iWidthnum = BULLETWNUM;
	m_ImgBullet.iHightnum = BULLETHNUM;
	m_ImgBullet.ptSrcSize = { BULLETSIZE, BULLETSIZE };

	m_fdelay = 0.2;
	
	m_iobjstate = E_GUNSTATE_NORMAL;

	// HitBox ����
	m_recHitBox = { m_DisBullet.ptDestPos.x, m_DisBullet.ptDestPos.y,
		m_DisBullet.ptDestPos.x + m_DisBullet.ptDestSize.x, m_DisBullet.ptDestPos.y + m_DisBullet.ptDestSize.y };
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
			m_DisBullet.ptDestPos.x += m_iobjmove;

			// �Ѿ� ���� �� ������ ObjManager ���� ���ְ� ����. 
		}
	break;
	}

	// HitBox ����
	m_recHitBox = { m_DisBullet.ptDestPos.x, m_DisBullet.ptDestPos.y,
		m_DisBullet.ptDestPos.x + m_DisBullet.ptDestSize.x, m_DisBullet.ptDestPos.y + m_DisBullet.ptDestSize.y };

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

	TransparentBlt(_hdc, m_DisBullet.ptDestPos.x, m_DisBullet.ptDestPos.y,
		m_DisBullet.ptDestSize.x, m_DisBullet.ptDestSize.y,
		hMemdc, m_DisBullet.ptSrcPos.x, m_DisBullet.ptSrcPos.y,
		m_DisBullet.ptDestSize.x, m_DisBullet.ptDestSize.y, RGB(255, 255, 255));

	// hitbox �����ֱ�
	//Rectangle(_hdc, m_recHitBox.left, m_recHitBox.top, m_recHitBox.right, m_recHitBox.bottom);


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
//bool Bullet::Hit()
//{
//	RECT recHit = { 0,0,0,0 };
//	// �ε����� obj�� RECT
//	RECT recHitobj = { _obj.posoriginDest.x, _obj.posoriginDest.y,
//		_obj.recDest.right, _obj.recDest.bottom };
//	// �ε����� bullet�� RECT
//	RECT recbullet = { m_bullet.posoriginDest.x, m_bullet.posoriginDest.y,
//		m_bullet.recDest.right, m_bullet.recDest.bottom };
//
//
//	return IntersectRect(&recHit, &recHitobj, &recbullet);
//};

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
		if (m_DisBullet.ptDestPos.x > ObjManager::GetInstance()->GetRect().right)
		{
			m_bdead = true;
		}
		//// ��򰡿� �΋H���� (intercetcRect())
		//else if (Hit(*(monstertemp->GetMonsterObj())) == true)
		//{
		//	monstertemp->bObjDead();

		//	m_bdead = true;
		//}
		else
		{
			m_bdead = false;
		}
	}

	return m_bdead;
}