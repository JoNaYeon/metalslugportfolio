#pragma once
#include "Object.h"
class Effect :
	public Object
{
protected:

public:
	// ������
	Effect()
	{

	};
	// �Ҹ���
	virtual ~Effect()
	{

	};

	// ������Ʈ �ʱ�ȭ
	void Init();
	// ������Ʈ ������
	void Run();
	// ������Ʈ ���
	void Render();
	// ������Ʈ �ı�
	void Destroy();

};

