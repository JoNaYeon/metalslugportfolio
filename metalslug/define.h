#pragma once

#include "resource.h"

#define PURE = 0;
#define BACKGROUNDMOVE 5

enum E_OBJECT
{
	EOBJECT_BG = 0,
	EOBJECT_TERRAIN,
	EOBJECT_OBJ,
	EOBJECT_UI,
	// ������Ʈ�� ������ �������� �־ ��ƾ� �� ������Ʈ�� ���� �ڵ� ����
	EOBJECT_OBJNUM,
};

enum E_BGSCENE
{
	E_BGSCENE_GAME = 0
};