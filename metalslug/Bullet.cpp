#include "Bullet.h"
#include "InputManager.h"
#include "ObjManager.h"
#include "define.h"
#include "Monster.h"


Bullet::Bullet(POINT _playerpos)
{
	// dest = 출력 , src = 원본
	m_DisBullet.ptSrcPos = { 0, 0 };
	m_DisBullet.ptDestSize = { BULLETSIZE, BULLETSIZE };
	m_DisBullet.ptDestPos = { _playerpos.x + (FIREPLAYERWANIMATION * 3), _playerpos.y + (FIREPLAYERHANIMATION) };

	m_iobjmove = BULLETMOVE;

	m_ImgBullet.iWidthnum = BULLETWNUM;
	m_ImgBullet.iHightnum = BULLETHNUM;
	m_ImgBullet.ptSrcSize = { BULLETSIZE, BULLETSIZE };

	m_fdelay = 0.2;
	
	m_iobjstate = E_GUNSTATE_NORMAL;

	// HitBox 갱신
	m_recHitBox = { m_DisBullet.ptDestPos.x, m_DisBullet.ptDestPos.y,
		m_DisBullet.ptDestPos.x + m_DisBullet.ptDestSize.x, m_DisBullet.ptDestPos.y + m_DisBullet.ptDestSize.y };
};
 

// 오브젝트 초기화
void Bullet::Init()
{
	return;
};

// 오브젝트 움직임
void Bullet::Run()
{
	// Object 관련
	switch (m_iobjstate)
	{
		case E_GUNSTATE_NORMAL:
		{
			// 총알 발사시키기 
			m_DisBullet.ptDestPos.x += m_iobjmove;

			// 총알 죽을 때 삭제는 ObjManager 에서 해주고 있음. 
		}
	break;
	}

	// HitBox 갱신
	m_recHitBox = { m_DisBullet.ptDestPos.x, m_DisBullet.ptDestPos.y,
		m_DisBullet.ptDestPos.x + m_DisBullet.ptDestSize.x, m_DisBullet.ptDestPos.y + m_DisBullet.ptDestSize.y };

	return;
};

// 오브젝트 출력
void Bullet::Render(HDC& _hdc, HWND& _hWnd)
{
	// 이미지를 담을 HDC
	HDC hMemdc = NULL;
	// 이미지를 담을 hbitmap 
	HBITMAP hbit = NULL;
	HBITMAP holdbit = NULL;

	// client 갱신 
	RECT recClient = ObjManager::GetInstance()->GetRect();

	hMemdc = CreateCompatibleDC(_hdc);

	// 이미지 HBITMAP 에 로드하여 넣음 
	hbit = (HBITMAP)LoadImage(NULL, "..\\source\\weapon\\bullet1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	holdbit = (HBITMAP)SelectObject(hMemdc, hbit);


	// 시간을 받아옴
	m_dcurTime = timeGetTime();

	TransparentBlt(_hdc, m_DisBullet.ptDestPos.x, m_DisBullet.ptDestPos.y,
		m_DisBullet.ptDestSize.x, m_DisBullet.ptDestSize.y,
		hMemdc, m_DisBullet.ptSrcPos.x, m_DisBullet.ptSrcPos.y,
		m_DisBullet.ptDestSize.x, m_DisBullet.ptDestSize.y, RGB(255, 255, 255));

	// hitbox 보여주기
	//Rectangle(_hdc, m_recHitBox.left, m_recHitBox.top, m_recHitBox.right, m_recHitBox.bottom);


	SelectObject(hMemdc, holdbit);


	DeleteDC(hMemdc);
	DeleteObject(hbit);
	
	return;
};

// 오브젝트 파괴
void Bullet::Destroy()
{
	return;
};


// 총알 닿으면
//bool Bullet::Hit()
//{
//	RECT recHit = { 0,0,0,0 };
//	// 부딪히는 obj의 RECT
//	RECT recHitobj = { _obj.posoriginDest.x, _obj.posoriginDest.y,
//		_obj.recDest.right, _obj.recDest.bottom };
//	// 부딪히는 bullet의 RECT
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
		

		// client 밖으로 나가면 
		if (m_DisBullet.ptDestPos.x > ObjManager::GetInstance()->GetRect().right)
		{
			m_bdead = true;
		}
		//// 어딘가에 부딫히면 (intercetcRect())
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