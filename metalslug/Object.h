#pragma once

#include "define.h"

class Object
{
protected:
	
public:
	// ������
	Object()
	{

	};
	// �Ҹ���
	virtual ~Object()
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
};

