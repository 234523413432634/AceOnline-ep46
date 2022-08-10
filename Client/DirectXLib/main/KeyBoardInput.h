// KeyBoardInput.h: interface for the CKeyBoardInput class.
//
//////////////////////////////////////////////////////////////////////
//#define STRICT
#include <tchar.h>
#include <windows.h>
#include <basetsd.h>
#include <dinput.h>

#if !defined(AFX_KEYBOARDINPUT_H__DCEFF74E_3426_4F2E_98DE_D23B9F70607B__INCLUDED_)
#define AFX_KEYBOARDINPUT_H__DCEFF74E_3426_4F2E_98DE_D23B9F70607B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CKeyBoardInput  
{
public:
	BOOL GetAsyncKeyState( int code);
	BYTE m_cDiks[256];
	CKeyBoardInput();
	virtual ~CKeyBoardInput();

	HRESULT OnCreateDevice( HWND hDlg );
	HRESULT ReadImmediateData( HWND hDlg );
//	HRESULT ReadBufferedData( HWND hDlg );
	VOID    FreeDirectInput();

	LPDIRECTINPUT8			m_pDI      ;         
	LPDIRECTINPUTDEVICE8	m_pKeyboard;     

	// 2007-06-18 by bhsohn ��Ʈ�� ���� ���� ó��
	void SetKeyBoardLostDevice(BOOL bLostDevice);

	// 2008-11-13 by bhsohn ���̽�ƽ �۾�
	BOOL GetKeyBoardLostDevice();

	// 2008-01-11 by bhsohn ��Ŀ�� ������, Ű���� ó�� �ȵǰ� ��
	void SetKeyBoardFocus(BOOL bGetFocus);

	// 2008-06-20 by bhsohn EP3 �ɼǰ��� ó��
	BOOL GetKeyBoardFocus();
	
private:
	// 2007-06-18 by bhsohn ��Ʈ�� ���� ���� ó��
	BOOL	m_bLostDevice;

	// 2008-01-11 by bhsohn ��Ŀ�� ������, Ű���� ó�� �ȵǰ� ��
	BOOL				m_bGetFocus;

};

#endif // !defined(AFX_KEYBOARDINPUT_H__DCEFF74E_3426_4F2E_98DE_D23B9F70607B__INCLUDED_)
