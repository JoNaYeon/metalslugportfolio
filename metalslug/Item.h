#pragma once
#include "Object.h"

class Item :
	public Object
{
protected:

public:
	// ������
	Item()
	{

	};
	// �Ҹ���
	virtual ~Item()
	{

	};

	// ������Ʈ �ʱ�ȭ
	virtual void Init() PURE
	// ������Ʈ ������
	virtual void Run() PURE
	// ������Ʈ ���
	virtual void Render() PURE
	// ������Ʈ �ı�
	virtual void Destroy() PURE

	virtual void ItemState() PURE
};

