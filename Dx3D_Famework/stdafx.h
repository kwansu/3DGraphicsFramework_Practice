// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
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
#include <vector>
#include "cInput.h"
#include "Resource.h"
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

using namespace std;


// �ܺ� ���� ����:
extern HWND			g_hWnd;
extern HINSTANCE	g_hInst;
extern cInput*		g_pInput;


// ��ũ�� :
#define SAFE_RELEASE(p)	{if(p) (p)->Release(); (p) = NULL;}

#define cVec3			D3DXVECTOR3
#define cMatrixA		D3DXMATRIXA16
#define xColor			D3DCOLOR
#define cpDDevice		LPDIRECT3DDEVICE9
