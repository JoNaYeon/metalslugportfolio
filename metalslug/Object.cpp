#include "Object.h"
#include "Mainfrm.h"
#include "Background.h"

DWORD Object::m_dPrevTime = timeGetTime();


// 생성자
Object::Object()
{
	m_iobjstate = -1;
	m_dcurTime = timeGetTime();
	m_fdelay = 1;

	m_fvelocity = -VELOCITY;
	m_bgravity = true;

	m_bdead = false;

	m_initialt = 0;
};

void Object::Graviy(ST_OBJECT* _obj)
{
	if (m_bgravity == true)
	{
		// 모든 object에 대해 중력을 적용한다.
		//_obj->posoriginDest.y += (m_fvelocity * VELOCITYVALUE * 0.1);

		_obj->posoriginDest.y = 0.5f * 0.4f * m_initialt * m_initialt + m_fvelocity * m_initialt + 0;   // y방향의 위치 결정
		m_initialt++;
		// 물체의 시각을 진행한다
	}   

	return;
}

void Object::Aniimage(ST_OBJECT& _obj)
{
	// state가 달라지면 originsrc를 0,0부터 시작하여 잘려보이는 현상 없애기
	if (m_iobjstatetemp != m_iobjstate)
	{
		m_iobjstatetemp = m_iobjstate;
		_obj.poriginSrc = { 0,0 };
	}

	if (_obj.poriginSrc.x < _obj.recSrc.right * (_obj.iWidthnum - 1))
	{
		_obj.poriginSrc.x += _obj.recSrc.right;
	}
	else
	{
		_obj.poriginSrc.x = 0;
		_obj.poriginSrc.y += _obj.recSrc.bottom;

		if (_obj.poriginSrc.y >= _obj.recSrc.bottom * (_obj.iHightnum - 1))
		{
			_obj.poriginSrc.y = 0;
		}
	}
}

bool Object::IntersectRectCheck(RECT* _rec1, RECT* _rec2)
{
	//bool bInter = IntersectRect(recInter, _rec1, _rec2);

	if ((_rec1->right >= _rec2->left) && (_rec1->left <= _rec2->right))
	{
		if ((_rec1->bottom >= _rec2->top) && (_rec1->top <= _rec2->bottom))
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

/*

#define PLAYER_VEL         10.0f            // 플레이어의 속도
#define GR            0.4f               // 중력가속도

float         x,  y;                     // 위치
float         vx, vy;                     // 속도


int InitCharacter( void )                  // 최초에 한 번만 호출된다
{
   x = 0.0f;                           // （이 경우 무의미）
   vx = PLAYER_VEL;
   y = 200.0f;                           // y방향의 초기 위치(이 경우 무의미)
   vy = -10.0f;                        // y방향의 초속

   return 0;
}


int MoveCharacter( void )                  // 매 프레임 호출된다
{
   static int      t = 0;                   // 물체의 시각

   x = vx * t;                            // x방향의 위치 결정
   y = 0.5f * GR * t * t + vy * t + 200.0f;   // y방향의 위치 결정
   t++;                              // 물체의 시각을 진행한다

*/


void Object::ObjStand(ST_OBJECT* _obj)
{
	// 배경 vector를 가져옴 
	std::vector<Object*> vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_BG);

	for (int i = 0; i < vectemp.size(); i++)
	{
		// 배경 vector 를 넣어줄 변수
		Background* bgtemp = (Background*)vectemp[i];
		// player의 RECT를 넣어줌
		RECT recttemp = { _obj->posoriginDest.x, _obj->posoriginDest.y,
			_obj->posoriginDest.x + (_obj->recDest.right) * PLAYERSIZE,
			_obj->posoriginDest.y + (_obj->recDest.bottom) * PLAYERSIZE };

		// plater과 background Tile에 충돌이 일어나도록 해줌
		//bool btemp = IntersectRectCheck(&recttemp, &bgtemp->BackgroundTile(BACKGROUNDMOVE));

		bool btemp = IntersectRect(&recttemp, &m_recHitBox, bgtemp->BackgroundTile(BACKGROUNDMOVE));

		//IntersectRect();

		// 만약 충돌이 일어날 경우
		if (btemp == true)
		{
			m_bgravity = false;
			//_obj->posoriginDest.y = bgtemp->BackgroundTile(BACKGROUNDMOVE)->top - (_obj->recDest.bottom * PLAYERSIZE);
			_obj->posoriginDest.y -= (recttemp.bottom - recttemp.top);
			m_initialt = _obj->posoriginDest.y;
		}
		else
		{
			m_bgravity = true;
		}
	}

	return;
}


/*void Object::hitbox(RECT _rec1, RECT _rec2)
{
	// 히트판정 
	IntersectRect(NULL, &_rec1, &_rec2);

	return;
}*/

// iter 에 vector 넣기
bool Object::GetIter(std::vector<Object*>& _obj)
{

	return false;
};


void Object::SetObjStruct(ST_OBJECT& _obj, int _recSrcright, int _recSrcbottom, int _poriginSrcx, int _poriginSrcy,
	int _recDestright, int _recDestbottom, int _posoriginDestx, int _posoriginDesty,
	int _iobjmove, int _iWidthnum, int _iHightnum)
{
	_obj.iobjmove = _iobjmove;
	_obj.iHightnum = _iHightnum;
	_obj.iWidthnum = _iWidthnum;

	_obj.recDest.right = _recDestright;
	_obj.recDest.bottom = _recDestbottom;

	_obj.recSrc.right = _recSrcright; 
	_obj.recSrc.bottom = _recSrcbottom; 

	_obj.posoriginDest.x = _posoriginDestx;
	_obj.posoriginDest.y = _posoriginDesty;
	
	_obj.poriginSrc.x = _poriginSrcx;
	_obj.poriginSrc.y = _poriginSrcy;

	return;
}