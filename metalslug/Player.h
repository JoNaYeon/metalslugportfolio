#pragma once
#include "Object.h"


class Player :
	public Object
{
protected:
	int m_ihp;
	int m_istrength;
	int m_ispeed;
	int m_igun;
	int m_ibomb;
	int m_ivirous;
	bool m_bhuman;

	bool m_bmove;

	// player�� �̹��� ��θ� ���� ����
	LPCSTR m_strBitmapTop;
	LPCSTR m_strBitmapBottom;

	Object* m_classobjptr;


	int m_t;		// ��ü�� �ð� 

public:
	// ������
	Player();
	// �Ҹ���
	virtual ~Player()
	{

	}

	// ������Ʈ �ʱ�ȭ (�������̵�)
	void Init();
	// ������Ʈ ������ (�������̵�)
	void Run();
	// ������Ʈ ��� (�������̵�)
	void Render();
	// ������Ʈ �ı� (�������̵�)
	void Destroy();


	// ���� - �� (�������̵�)
	void AttackGun();
	// ���� - ������ (�������̵�)
	void AttackKnife();
	// ���� - ��ź (�������̵�)
	void AttackBomb();
	// ���� (�������̵�)
	void Jump();

	// ���� �Ǵ� �ִϸ��̼� 
	void DeadZombie();

	DISPLAYINFO* GetDisTop() { return &m_DisTop; };
	DISPLAYINFO* GetDisBot() { return &m_DisBot; };
	void SetDisTop(POINT _disTop);
	void SetDisBot(POINT _disBot);
	bool GetBGMove() { return m_bmove; };

	// �÷��̾��� gravity ����
	void SetboolGravity(bool _bGravity);
};

