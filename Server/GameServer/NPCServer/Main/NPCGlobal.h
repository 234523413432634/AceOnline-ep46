// NPCGlobal.h: interface for the CNPCGlobal class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NPCGLOBAL_H__12EE2E44_49ED_4053_AB20_B0601FFF49DD__INCLUDED_)
#define AFX_NPCGLOBAL_H__12EE2E44_49ED_4053_AB20_B0601FFF49DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxstr.h>

#include "d3dapp.h"

class CNPCGlobal;
extern CNPCGlobal *			g_pNPCGlobal;

///////////////////////////////////////////////////////////////////////////////
/// \class		CNPCGlobal
///
/// \brief
/// \author		cmkwon
/// \version
/// \date		2004-03-19 ~ 2004-03-19
/// \warning
///////////////////////////////////////////////////////////////////////////////
class CNPCIOCP;
class CN2FSocket;
class CNPCGlobal : public CGlobalGameServer
{
public:
	CNPCGlobal();
	virtual ~CNPCGlobal();

	///////////////////////////////////////////////////////////////////////////
	// Property
	void SetIPFieldServer(char *i_szIP);
	char *GetIPFieldServer(void);
	void SetPortFieldServer(int i_nPort);
	int GetPortFieldServer(void);

	CN2FSocket * GetN2FSocket(void);
	BOOL WriteN2FSocket(BYTE *pData, int nSize);	// 2007-11-26 by cmkwon, ���� �ڵ����� �޽��� TCP�� ����(N->F) -

	///////////////////////////////////////////////////////////////////////////
	// Method
	BOOL CreateN2FSocket(HWND i_hWnd);

	void DestroyN2FSocket(void);


	// virtual Function
	virtual BOOL InitServerSocket(void);				// ���ϰ��� �ʱ�ȭ �Լ�
	virtual BOOL EndServerSocket(void);					// ���ϰ��� ���� �Լ�

	virtual CString LoadConfiguration1(void);				// Server ������ ���� Configuration Load

	CD3DApplication		m_D3DApp;

	BOOL				m_bIsArenaServer;				// 2008-09-10 by cmkwon, ���վƷ��� �ʼ���(map.cfg) ���� ���� - 
	BOOL GetIsArenaServer(void);						// 2008-09-10 by cmkwon, ���վƷ��� �ʼ���(map.cfg) ���� ���� - 
protected:
	//////////////////////////////////////////////////////////////////////////
	// Configuration Variables
	char				m_szIPFieldServer[SIZE_MAX_IPADDRESS];			// one (NPC)
	int					m_nPortFieldServer;								// one (NPC)

	CN2FSocket *		m_pN2FSocket;
};

#endif // !defined(AFX_NPCGLOBAL_H__12EE2E44_49ED_4053_AB20_B0601FFF49DD__INCLUDED_)
