// VoIPGlobal.h: interface for the CVoIPGlobal class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VOIPGLOBAL_H__9634F468_5556_4123_8871_213E5FC927D3__INCLUDED_)
#define AFX_VOIPGLOBAL_H__9634F468_5556_4123_8871_213E5FC927D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Global.h"
#include "SocketHeader.h"


//////////////////////////////////////////////////////////////////////////
// Configuration
#define GLOBAL_CONFIG_FILE_NAME					"Global.cfg"
#define VD_SERVER_CONFIG_FILE_NAME				"VDServer.cfg"
#define VC_SERVER_CONFIG_FILE_NAME				"VCServer.cfg"

//////////////////////////////////////////////////////////////////////////
// Timer Variables
const UINT TIMERID_TRAFFIC						= 100;					// Traffic ����� Timer
const UINT TIMERID_ALIVE_CHECK					= 101;					// �������� Alive Check Timer
const UINT TIMERID_RECONNECT					= 102;
const UINT TIMERID_SELFSTATUS					= 103;
const UINT TIMERGAP_TRAFFIC						= 10000;				// 10��(10 * 1000)
const UINT TIMERGAP_ALIVE_CHECK					= 30000;				// 30��(30 * 1000)
const UINT TIMERGAP_RECONNECT					= 5000;
const UINT TIMERGAP_SELFSTATUS					= 1000;

class CVoIPGlobal;
//////////////////////////////////////////////////////////////////////////
// Global Variable
//////////////////////////////////////////////////////////////////////////
extern CVoIPGlobal			*g_pVoIPGlobal;		// �������������� ���� ����Ŭ����������

//////////////////////////////////////////////////////////////////////////
// Global Function
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// ������ �޼��� ���ν���

class CIOCP;
class CVoIPGlobal : public CGlobal  
{
public:
	CVoIPGlobal();
	virtual ~CVoIPGlobal();

	void SetConfigRootPath(void);
	char *GetConfigRootPath(void);
	HINSTANCE GetInstanceHandle(void);
	HWND GetMainWndHandle(void);
	UINT GetTimerIDTraffic(void);
	UINT GetTimerIDAliveCheck(void);
	UINT GetTimerIDReconnect(void);

	void SetIPLocal(char *i_szIP);
	char *GetIPLocal(void);
	void SetPublicIPLocal(char *i_szIP);
	char *GetPublicIPLocal(void);
	void SetPortListening(int i_nPort);
	int GetPortListening(void);
	CIOCP *GetGIOCP(void);

	///////////////////////////////////////////////////////////////////////////
	// virtual Function	
	virtual BOOL InitServerSocket(void);						// ���ϰ��� �ʱ�ȭ �Լ�
	virtual BOOL EndServerSocket(void);							// ���ϰ��� ���� �Լ�
	virtual BOOL LoadConfiguration(void){	return FALSE;};		// Server ������ ���� Configuration Load


	///////////////////////////////////////////////////////////////////////////
	// Method
	void WndRegisterClass(HINSTANCE hInstance, UINT IDI_Icon, char *szClass);
	BOOL InitInstance(HINSTANCE hInstance, int nCmdShow, char *szClass, char *szWindowText);

	BOOL StartTimerTraffic(void);
	void EndTimerTraffic(void);
	BOOL StartTimerAliveCheck(void);
	void EndTimerAliveCheck(void);
	BOOL StartTimerReconnect(void);	
	void EndTimerReconnect(void);

	void CheckServerThread(void);
	void CalculateIOCPTraffic(void);
	void CheckClientAlive(void);

	
protected:
	//////////////////////////////////////////////////////////////////////////
	// ������ ���� ��� ����
	HINSTANCE			m_hInstanceHandle;						// ����� �ν��Ͻ� �ڵ�
	HWND				m_hMainWndHandle;						// ����� ���� ������ �ڵ�

	//////////////////////////////////////////////////////////////////////////
	// ������ Ÿ�̹� ���� ��� ����
	UINT				m_nTimerIDTraffic;						// ��� �������� Bandwidth ����� ���� TimerID
	UINT				m_nTimerIDAliveCheck;					// ��� �������� Ŭ���̾�Ʈ�� Alive üũ�� ���� TimerID
	UINT				m_nTimerIDReconnect;					// ����(IMServer, FieldServer, NPCServer)���� ���� ������ ������ ���� �Ǿ����� �������� ���� TimerID
	
	//////////////////////////////////////////////////////////////////////////
	// Config ���� ��� ����
	char				m_szConfigRootPath[MAX_PATH];
	char				m_szIPLocal[SIZE_MAX_IPADDRESS];		//
	char				m_szPublicIPLocal[SIZE_MAX_IPADDRESS];			// All (Pre, IM, Field, NPC)// 2006-05-23 by cmkwon
	int					m_nPortListening;						//
	
	CIOCP *				m_pGIOCP;
};

#endif // !defined(AFX_VOIPGLOBAL_H__9634F468_5556_4123_8871_213E5FC927D3__INCLUDED_)
