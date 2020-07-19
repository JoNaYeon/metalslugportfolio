#include "Object.h"
#include "Mainfrm.h"

DWORD Object::m_dPrevTime = timeGetTime();


// 생성자
Object::Object()
{
	m_iobjstate = -1;
	m_dcurTime = timeGetTime();
	m_fdelay = 1;

	m_bdead = false;
	m_bfire = false;
};

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
			m_bfire = false;
		}
	}
}

void Object::Animation(HDC& _hdc, ST_OBJECT& _obj, int& _iobjstate)
{

	return;
}


void Object::hitbox(RECT _rec1, RECT _rec2)
{
	// 히트판정 
	IntersectRect(NULL, &_rec1, &_rec2);

	return;
}

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

	_obj.recDest.right = _recSrcright;
	_obj.recDest.bottom = _recSrcbottom;

	_obj.recSrc.right = _recDestright;
	_obj.recSrc.bottom = _recDestbottom;

	_obj.posoriginDest.x = _posoriginDestx;
	_obj.posoriginDest.y = _posoriginDesty;
	
	_obj.poriginSrc.x = _poriginSrcx;
	_obj.poriginSrc.y = _poriginSrcy;

	return;
}