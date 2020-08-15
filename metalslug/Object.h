#pragma once

#include "define.h"

class Object
{
protected:
	int m_iobjstate;
	int m_iobjstatetemp;

	// �ð��� ������ ����
	DWORD m_dcurTime;
	static DWORD m_dPrevTime;
	float m_fdelay;

	// ��ü�� ���� ���� Ȯ���ϴ� bool ����
	bool m_bdead;

	// �߷��� ��Ʈ�� �� ������
	//float m_fvelocity;
	//float m_fgravity;
	// jump ����
	bool m_bjump;
	// fire ����
	bool m_bfire;
	// �߷��� ����
	bool m_bgravity;
	// collision Check 
	bool m_bCollisionCheck;

	// �浹 �����ϴ� �浹 �ڽ�
	RECT m_recHitBox;

	// ���� �����ߴ� st_object�� �ִ� ����, ������Ʈ �̵������̶� �̵�
	int m_iobjmove;
	
public:
	// ������
	Object();
	// �Ҹ���
	virtual ~Object()
	{

	};

	// ������Ʈ �ʱ�ȭz
	virtual void Init() PURE;
	// ������Ʈ ������
	virtual void Run() PURE;
	// ������Ʈ ��� 
	virtual void Render(HDC& _hdc, HWND& _hWnd) PURE;
	// ������Ʈ �ı�
	virtual void Destroy() PURE;

	// dbject�� �������� �ִϸ��̼ǿ� �߰��� �Լ�
	void Aniimage(DISPLAYINFO& _displayInfo, IMAGEINFO _imageInfo);

	int Getobjstate() { return m_iobjstate; };
	void Setobjstate(int _objstate) { m_iobjstate = _objstate; };
	
	// object�� ������� �Լ�
	virtual bool bObjDead() PURE;

	void SetImgInfo(IMAGEINFO& _imgInfo, POINT _ptSrcSize, int _iWidthNum, int _iHightNum);
	void Gravity(DISPLAYINFO* _objdis, E_OBJECT _eobj);
	bool IntersectRectCheck(RECT* _rec1, RECT* _rec2);
	// Object���� ��濡 �� �� �ֵ��� ���ִ� �Լ� 
	//void ObjStand(ST_OBJECT* _obj);

	RECT GetHitBox() { return m_recHitBox; };
	// �ǰ� üũ
	void SetCollisionCheck(bool _CollisionCheck) { m_bCollisionCheck = _CollisionCheck; };
	
	void SetboolGravity(bool _bGravity) { m_bgravity = _bGravity; return; };
	bool GetboolGravity() { return m_bgravity; };

	bool GetJump() { return m_bjump; };
};

