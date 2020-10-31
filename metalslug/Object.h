#pragma once

#include "define.h"

class Object
{
protected:
	// ������Ʈ�� ����
	int m_iobjstate;
	int m_iobjstatetemp;

	// y���� ���� ������Ʈ�� ���ϸ��� ����
	int m_iuserycase = 0;

	// �ð��� ������ ����
	DWORD m_dcurTime;
	static DWORD m_dPrevTime;
	float m_fdelay;

	// ��ü�� ���� ���� Ȯ���ϴ� bool ����
	bool m_bdead;

	// jump ����
	bool m_bjump;
	// fire ����
	bool m_bfire;
	// �߷��� ����
	bool m_bgravity;
	// collision Check 
	bool m_bCollisionCheck;
	// line �� ������ �޴� ��ü���� �ƴ��� Ȯ���ϵ��� ���� 
	bool m_bypos;

	// �浹 �����ϴ� �浹 �ڽ�
	RECT m_recHitBox;

	// ���� �����ߴ� st_object�� �ִ� ����, ������Ʈ �̵������̶� �̵�
	int m_iobjmove;

	// Object�� ����ü
	DISPLAYINFO	m_DisTop;
	DISPLAYINFO	m_DisBot;

	IMAGEINFO	m_ImgTop;
	IMAGEINFO	m_ImgBot;

	int m_gravitytemp;

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

	int Getobjstate();
	void Setobjstate(int _objstate) { m_iobjstate = _objstate; };

	// object�� ������� �Լ�
	virtual bool bObjDead() PURE;

	void SetImgInfo(IMAGEINFO& _imgInfo, POINT _ptSrcSize, int _iWidthNum, int _iHightNum);
	void Gravity(DISPLAYINFO* _objdis, E_OBJECT _eobj);
	bool IntersectRectCheck(RECT* _rec1, RECT* _rec2);

	// y��(��ġ ����)�� ���ϸ� �����ִ� �Լ�
	int ObjectyLevel(int _iobjdistancey);
	// ������Ʈ�� y���� �ö��� ���ƾ� �� �� �¿�� ������ �� ������ �ϴ� �Լ�
	void ObjectStopYLevelControl(int _iobjyLevel);

	RECT GetHitBox() { return m_recHitBox; };
	// �ǰ� üũ
	void SetCollisionCheck(bool _CollisionCheck) { m_bCollisionCheck = _CollisionCheck; };

	virtual void SetboolGravity(bool _bGravity);
	bool GetboolGravity() { return m_bgravity; };

	bool GetJump() { return m_bjump; };
	void SetJump(bool _bjump) { m_bjump = _bjump; return; };
	int GetGravityTemp() { return m_gravitytemp; };
	void SetGravityTemp(int _igravitytemp) { m_gravitytemp = _igravitytemp; return; };

	virtual DISPLAYINFO* GetDisTop();
	virtual DISPLAYINFO* GetDisBot();
	virtual void SetDisTop(POINT _disTop);
	virtual void SetDisBot(POINT _disTop);
	virtual bool GetbCollision() { return m_bypos; };	
};

