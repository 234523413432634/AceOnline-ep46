
// TEstb.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTEstbApp:
// �� Ŭ������ ������ ���ؼ��� TEstb.cpp�� �����Ͻʽÿ�.
//

class CBugTrapbApp : public CWinApp
{
public:
	CBugTrapbApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CBugTrapbApp theApp;