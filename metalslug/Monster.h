#pragma once
#include "Object.h"
class Monster :
	public Object
{
protected:
	int m_ihp;
	int m_istrength;
	int m_ispeed;

public:
	// ������
	Monster()
	{

	};
	// �Ҹ���
	virtual ~Monster()
	{

	};

	// ������Ʈ �ʱ�ȭ (�������̵�)
	virtual void Init() PURE
	// ������Ʈ ������ (�������̵�)
	virtual void Run() PURE
	// ������Ʈ ��� (�������̵�)
	virtual void Render() PURE
	// ������Ʈ �ı� (�������̵�)
	virtual void Destroy() PURE

	// �� ���� 
	virtual void Attack() PURE
};

