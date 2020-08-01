#include "Object.h"
#include "Mainfrm.h"
#include "Background.h"

DWORD Object::m_dPrevTime = timeGetTime();


// ������
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
		// ��� object�� ���� �߷��� �����Ѵ�.
		//_obj->posoriginDest.y += (m_fvelocity * VELOCITYVALUE * 0.1);

		_obj->posoriginDest.y = 0.5f * 0.4f * m_initialt * m_initialt + m_fvelocity * m_initialt + 0;   // y������ ��ġ ����
		m_initialt++;
		// ��ü�� �ð��� �����Ѵ�
	}   

	return;
}

void Object::Aniimage(ST_OBJECT& _obj)
{
	// state�� �޶����� originsrc�� 0,0���� �����Ͽ� �߷����̴� ���� ���ֱ�
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

#define PLAYER_VEL         10.0f            // �÷��̾��� �ӵ�
#define GR            0.4f               // �߷°��ӵ�

float         x,  y;                     // ��ġ
float         vx, vy;                     // �ӵ�


int InitCharacter( void )                  // ���ʿ� �� ���� ȣ��ȴ�
{
   x = 0.0f;                           // ���� ��� ���ṇ̀�
   vx = PLAYER_VEL;
   y = 200.0f;                           // y������ �ʱ� ��ġ(�� ��� ���ǹ�)
   vy = -10.0f;                        // y������ �ʼ�

   return 0;
}


int MoveCharacter( void )                  // �� ������ ȣ��ȴ�
{
   static int      t = 0;                   // ��ü�� �ð�

   x = vx * t;                            // x������ ��ġ ����
   y = 0.5f * GR * t * t + vy * t + 200.0f;   // y������ ��ġ ����
   t++;                              // ��ü�� �ð��� �����Ѵ�

*/


void Object::ObjStand(ST_OBJECT* _obj)
{
	// ��� vector�� ������ 
	std::vector<Object*> vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_BG);

	for (int i = 0; i < vectemp.size(); i++)
	{
		// ��� vector �� �־��� ����
		Background* bgtemp = (Background*)vectemp[i];
		// player�� RECT�� �־���
		RECT recttemp = { _obj->posoriginDest.x, _obj->posoriginDest.y,
			_obj->posoriginDest.x + (_obj->recDest.right) * PLAYERSIZE,
			_obj->posoriginDest.y + (_obj->recDest.bottom) * PLAYERSIZE };

		// plater�� background Tile�� �浹�� �Ͼ���� ����
		//bool btemp = IntersectRectCheck(&recttemp, &bgtemp->BackgroundTile(BACKGROUNDMOVE));

		bool btemp = IntersectRect(&recttemp, &m_recHitBox, bgtemp->BackgroundTile(BACKGROUNDMOVE));

		//IntersectRect();

		// ���� �浹�� �Ͼ ���
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
	// ��Ʈ���� 
	IntersectRect(NULL, &_rec1, &_rec2);

	return;
}*/

// iter �� vector �ֱ�
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