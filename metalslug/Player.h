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

	// player�� �̹��� ��θ� ���� ����
	LPCSTR m_strBitmapTop;
	LPCSTR m_strBitmapBottom;

	Object* m_classobjptr;

	// �÷��̾� ����ü
	DISPLAYINFO	m_DisTop;
	DISPLAYINFO	m_DisBot;

	IMAGEINFO	m_ImgTop;
	IMAGEINFO	m_ImgBot;

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
};

