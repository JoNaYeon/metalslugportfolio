#pragma once
#include "Object.h"
class Helper :
	public Object
{
protected:
	int m_ispeed;
	int m_item;

public:
	// ������
	Helper()
	{

	};
	// �Ҹ���
	virtual ~Helper()
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

	// ������ ����Ʈ����
	void ItemDrop();
};


