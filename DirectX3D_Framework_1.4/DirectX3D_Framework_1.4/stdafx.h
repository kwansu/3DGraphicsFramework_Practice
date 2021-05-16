// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <d3dx9.h>
#include <assert.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include "Resource.h"
using namespace std;


#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(linker,"/entry:wWinMainCRTStartup /subsystem:console")


// �ܺ� ���� ����
extern HWND			g_hWnd;
extern HINSTANCE	g_hInst;


// ���� �߰� ���
#include "Utility.h"
#include "cDeviceManager.h"
#include "cTimeManager.h"
#include "cInputManager.h"
#include "cGameObjectManager.h"
#include "stVertex.h"
#include "stRay.h"
#include "cObj_Camera.h"