#include "Scene.h"

// static 을 cpp에 NULL로 초기화 해야지 쓸 수 있음.
HWND Scene::m_hWnd = NULL;
HDC Scene::m_hdc = NULL;