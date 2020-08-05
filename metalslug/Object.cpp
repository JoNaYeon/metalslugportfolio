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
	m_bfire = false;

	m_bCollisionCheck = false;
};

//void Object::Gravity(ST_OBJECT* _obj)
//{
//	if (m_bgravity == true)
//	{
//	}   
//
//	return;
//}

void Object::Aniimage(DISPLAYINFO& _displayInfo, IMAGEINFO _imageInfo)
{
	// state�� �޶����� originsrc�� 0,0���� �����Ͽ� �߷����̴� ���� ���ֱ�
	if (m_iobjstatetemp != m_iobjstate)
	{
		m_iobjstatetemp = m_iobjstate;
		_displayInfo.ptSrcPos = { 0,0 };
	}

	if (_displayInfo.ptSrcPos.x < _displayInfo.ptDestSize.x * (_imageInfo.iWidthnum - 1))
	{
		_displayInfo.ptSrcPos.x += _displayInfo.ptDestSize.x;
	}
	else
	{
		_displayInfo.ptSrcPos.x = 0;
		_displayInfo.ptSrcPos.y += _displayInfo.ptDestSize.y;

		if (_displayInfo.ptSrcPos.y >= _displayInfo.ptDestSize.y * (_imageInfo.iHightnum - 1))
		{
			_displayInfo.ptSrcPos.y = 0;
		}
	}
}

bool Object::IntersectRectCheck(RECT* _rec1, RECT* _rec2)
{
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

//void Object::ObjStand(ST_OBJECT* _obj)
//{
//	// ��� vector�� ������ 
//	std::vector<Object*> vectemp = ObjManager::GetInstance()->GetVector(EOBJECT_BG);
//
//	for (int i = 0; i < vectemp.size(); i++)
//	{
//		// ��� vector �� �־��� ����
//		Background* bgtemp = (Background*)vectemp[i];
//		// player�� RECT�� �־���
//		RECT recttemp = { _obj->posoriginDest.x, _obj->posoriginDest.y,
//			_obj->posoriginDest.x + (_obj->recDest.right) * PLAYERSIZE,
//			_obj->posoriginDest.y + (_obj->recDest.bottom) * PLAYERSIZE };
//
//		bool btemp = IntersectRect(&recttemp, &m_recHitBox, bgtemp->BackgroundTile(BACKGROUNDMOVE));
//
//		// ���� �浹�� �Ͼ ���
//		if (btemp == true)
//		{
//			m_bgravity = false;
//			_obj->posoriginDest.y -= (recttemp.bottom - recttemp.top);
//		}
//		else
//		{
//			m_bgravity = true;
//		}
//	}
//
//	return;
//}

void Object::SetImgInfo(IMAGEINFO& _imgInfo, POINT _ptSrcSize, int _iWidthNum, int _iHightNum)
{
	_imgInfo.iHightnum = _iHightNum;
	_imgInfo.iWidthnum = _iWidthNum;
	_imgInfo.ptSrcSize = _ptSrcSize;
}