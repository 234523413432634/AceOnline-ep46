// VCGlobal.h: interface for the CVCGlobal class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VCGLOBAL_H__AD010054_99C4_45A8_A903_E3F9AFFE1B1F__INCLUDED_)
#define AFX_VCGLOBAL_H__AD010054_99C4_45A8_A903_E3F9AFFE1B1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "VoIPGlobal.h"


///////////////////////////////////////////////////////////////////////////
// Global Variable
class CVCGlobal;
extern CVCGlobal *		g_pVCGlobal;


///////////////////////////////////////////////////////////////////////////////
/// \class		CVCGlobal
///
/// \brief		
/// \author		cmkwon
/// \version	
/// \date		2004-03-24 ~ 2004-03-24
/// \warning	
///////////////////////////////////////////////////////////////////////////////
class CC2DWinSocket;
class CVCIOCP;
class CVCGlobal : public CVoIPGlobal  
{
public:
	CVCGlobal();
	virtual ~CVCGlobal();

	///////////////////////////////////////////////////////////////////////////
	// Property
	char *GetVDServerIP(void){					return m_szVDServerIP;}
	USHORT GetVDServerPort(void){				return m_usVDServerPort;}
	CC2DWinSocket *GetC2DWinSocket(void){		return m_pC2DWinSocket;}
	DWORD GetMaxRoomCounts(void){				return m_dwMaxRoomCounts;}
	DWORD GetMaxUserCounts(void){				return m_dwMaxUserCounts;}
	DWORD GetMaxBandwidth(void){				return m_dwMaxBandwidth;}

	BOOL StartTimerSendSelfStatus(void);
	void EndTimerSendSelfStatus(void);


	// virtual Function	
	virtual BOOL InitServerSocket(void);
	virtual BOOL EndServerSocket(void);
	virtual BOOL LoadConfiguration(void);

	///////////////////////////////////////////////////////////////////////////
	// Method
	BOOL CreateC2DWinSocket(HWND i_hWnd);
	BOOL ConnectC2DWinSocket(char *i_szIP, USHORT i_usPort);	
	void DestroyC2DWinSocket(void);
	BOOL Send2VDServer(BYTE *i_pData, int i_nDataSize);
	BOOL Send2VDServer(MessageType_t i_msgType);
	void OnAsyncEventC2DWinSocket(SOCKET i_hSocket, LPARAM i_lParam);
	void OnPacketNotifyC2DWinSocket(WPARAM i_wParam);
	BOOL OnTimer(WPARAM i_TimerId);

protected:
	CVCIOCP					*m_pVCIOCP2;
	//////////////////////////////////////////////////////////////////////////
	//  VDServer�� ���� ����
	CC2DWinSocket			*m_pC2DWinSocket;				// VDServer�� �����ϱ� ���� Socket
	UINT					m_nTimerIDSendSelfStatus;		// ������ VDServer�� �ڽ��� ���� ������ �����ϱ� ���� TimerID

	//////////////////////////////////////////////////////////////////////////
	//  Config ���� ��� ����
	char					m_szVDServerIP[SIZE_MAX_IPADDRESS];
	USHORT					m_usVDServerPort;
	DWORD					m_dwMaxRoomCounts;
	DWORD					m_dwMaxUserCounts;
	DWORD					m_dwMaxBandwidth;
};

#endif // !defined(AFX_VCGLOBAL_H__AD010054_99C4_45A8_A903_E3F9AFFE1B1F__INCLUDED_)
