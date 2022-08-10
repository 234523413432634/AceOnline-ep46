// PreGlobal.h: interface for the CPreGlobal class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PREGLOBAL_H__C876B35F_9CED_4C8B_BB4C_3BB6B23FD13D__INCLUDED_)
#define AFX_PREGLOBAL_H__C876B35F_9CED_4C8B_BB4C_3BB6B23FD13D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GlobalGameServer.h"
#include "AtumProtocol.h"			// 2007-05-02 by cmkwon


typedef vector<SGAME_SERVER_GROUP>			vectSGAME_SERVER_GROUP;		// 2007-05-02 by cmkwon


class CPreIOCP;
class CPreIOCPSocket;
class CPreGlobal;
class CSecurityManager;			// 2011-06-22 by hskim, �缳 ���� ����
class CSelectiveShutdown;		// 2012-07-11 by hskim, ������ �˴ٿ�

extern CPreGlobal *		g_pPreGlobal;

// start 2011-06-22 by hskim, �缳 ���� ����
#ifndef  S_AUTHENTICATION_SERVER_HSKIM		// 2011-01-26 by hskim, ���� ���� ����
#define MasangPreServerIP		"127.0.0.1"		// �������� Domain
#define MasangPreServerPort		14999
#else
#define MasangPreServerIP		"115.144.35.131"
#define MasangPreServerPort		15100
#endif
// end 2011-06-22 by hskim, �缳 ���� ����

///////////////////////////////////////////////////////////////////////////////
/// \class		CPreGlobal
///
/// \brief
/// \author		cmkwon
/// \version
/// \date		2004-03-18 ~ 2004-03-18
/// \warning	���� �ϳ��� ��ü���� �����Ҽ� �ִ�, ������ ������ �������� ó���� ���� �ʴ´�.
///////////////////////////////////////////////////////////////////////////////
class CServerGroup;
class CSPToMPWinSocket;		// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
// 2012-10-05 by jhseol, NPlay pc�� ���
class CNPlayPCBangModule;
#define NPLAY_CONNECT_SERVER_EMPTY		0
#define NPLAY_CONNECT_SERVER_REAL		1
#define NPLAY_CONNECT_SERVER_BACKUP		2
#define NPLAY_SERVER_PORT				29021
// end 2012-10-05 by jhseol, NPlay pc�� ���

class CPreGlobal : public CGlobalGameServer
{
	friend class CPreIOCP;

public:
	CPreGlobal();
	virtual ~CPreGlobal();

	void Reset();

	BOOL InitGlobal(char * i_szServerName);		// 2011-06-22 by hskim, �缳 ���� ����

	///////////////////////////////////////////////////////////////////////////
	// Property
	void	SetUploadFTPIP(char *i_szIP);
	char*	GetUploadFTPIP(void);
	void	SetUploadFTPPort(int i_nPort);
	int		GetUploadFTPPort(void);
	void	SetUploadFTPAccount(char * i_szAccount);
	char*	GetUploadFTPAccount(void);
	void	SetUploadFTPPassword(char * i_szPassword);
	char*	GetUploadFTPPassword(void);

	void	SetDownloadFTPPort(int i_nPort);
	int		GetDownloadFTPPort(void);
	void	SetDownloadFTPAccount(char * i_szAccount);
	char*	GetDownloadFTPAccount(void);
	void	SetDownloadFTPPassword(char * i_szPassword);
	char*	GetDownloadFTPPassword(void);


	VersionInfo GetClientReinstallVersion(void);
	BOOL GetRandomFieldSelect(void) { return m_bRandomFieldSelect; }

	///////////////////////////////////////////////////////////////////////////////
	// 2007-01-08 by cmkwon, Auto Update FTP or HTTP
	int		GetAutoUpdateServerType(void);
	const char * GetDownloadServerIP(void);
	int		GetDownloadServerPort(void);
	char *	GetDownloadServerAccountName(void);
	char *	GetDownloadServerPassword(void);
	char *	GetClientUpdateDownloadDir(void);
	char *	GetLauncherFileDownloadPath(void);
	char *	GetDeleteFileListDownloadPath(void);
	char *	GetNoticeFileDownloadPath(void);

	///////////////////////////////////////////////////////////////////////////////
	// 2007-01-08 by cmkwon
	void AddDownloadHttpIP(const char * i_szIP);
	const char * GetRandomDownloadHttpIP(void);


	///////////////////////////////////////////////////////////////////////////
	// Method
	void AddDownloadFTPIP(char * i_szIP);
	const char *GetRandomDownloadFTPIP(void);

	BOOL CheckAllowedList(CServerGroup *i_pGroupInfo, char * i_szAccountName, char * i_szPrivateIP, USHORT i_nAccountType);
	void PrintAllowedList(void);
	BOOL CheckAllowedIP(char *i_szPublicIP);		// 2007-10-19 by cmkwon, AllowedIP �ý��� ���� - �㰡 IP üũ �Լ� 

	CServerGroup * GetServerGroupForLoading(const char * szServerGruopName);
	int GetEnableServerGroupCount(void);	// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 

	// 2007-05-02 by cmkwon
	// 2007-09-05 by cmkwon, EXE_1�� �α��� ���� ���� �������̽� ���� - �����߰�(, USHORT i_usTab8OrderIndex), ���� ����(, USHORT i_usPreServerPort, ��Ʈ�� �⺻ ��Ʈ ���)
	BOOL InsertGameServerGroup(char *i_szGameServerGroupName, char *i_szPreServerIP, int i_nTab8OrderIndex);
	BOOL Make_MSG_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST(MSG_PC_CONNECT_GET_GAME_SERVER_GROUP_LIST_OK *o_pGameServerGroupList);
	BOOL Make_MSG_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST_OK(MSG_PC_CONNECT_GET_NEW_GAME_SERVER_GROUP_LIST_OK *o_pGameServerGroupList);	// 2007-09-05 by cmkwon, EXE_1�� �α��� ���� ���� �������̽� ���� - �Ź��� �Լ� �߰�

	// 2007-07-06 by cmkwon, OnlyChoiceServer �÷��� ���� �߰�
	BOOL GetOnlyChoiceServer(void);

	///////////////////////////////////////////////////////////////////////////////
	// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
	BOOL createPreToAllServer(HWND i_hWnd);
	BOOL connectBySPToMPWinSoc(char *i_szIP, int i_nPort);
	BOOL sendToMasangPreServer(BYTE *i_pData, int i_nDataLen);
	BOOL OnAsyncEventOfSPToMPWinSoc(SOCKET i_hSocket, LONG i_nEvent);
	BOOL OnPacketNotifyOfSPToMPWinSoc(WORD i_wNotifyTy, WORD i_wParam);

	char * GetGamePublisherName(void);		// 2010-06-01 by shcho, GLogDB ���� -

	void SendToAuthenticationServer();		// 2011-06-22 by hskim, �缳 ���� ����

	// 2012-10-05 by jhseol, NPlay pc�� ���
	BOOL createNPlayPCBangModule(HWND i_hWnd, char* i_szNPlayServerIP_Real, char* i_szNPlayServerIP_BackUp);
	BOOL connectByNPlayPCBangModuleWinSoc(char *i_szIP, int i_nPort);
	BOOL OnAsyncEventOfNPlayPCBangModuleWinSoc(SOCKET i_hSocket, LONG i_nEvent);
	BOOL OnPacketNotifyOfNPlayPCBangModuleWinSoc(WORD i_wNotifyTy, WORD i_wParam);
	char* GetNPlayServerIP_Real();
	char* GetNPlayServerIP_BackUP();
	void SetNPlayConnectServer(BYTE i_nConnectServer);
	BYTE GetNPlayConnectServer();
	// end 2012-10-05 by jhseol, NPlay pc�� ���

public:
	// virtual Function
	virtual BOOL InitServerSocket(void);				// ���ϰ��� �ʱ�ȭ �Լ�
	virtual BOOL EndServerSocket(void);					// ���ϰ��� ���� �Լ�

	virtual BOOL LoadConfiguration(void);				// Server ������ ���� Configuration Load
	virtual BOOL ReLoadConfiguration(void);				// 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����

protected:
	// �ٿ�ε��
	vector<string>			m_vectorDownloadFTPIP;
	int						m_nDownloadFTPPort;
	char					m_szDownloadFTPAccount[SIZE_MAX_ACCOUNT_NAME];
	char					m_szDownloadFTPPassword[SIZE_MAX_PASSWORD];

	// ���ε�� �� PreServer �����
	char					m_szUploadFTPIP[SIZE_MAX_FTP_URL];	// ������Ʈ �� PreServer�� ������Ʈ ���� Ȯ���� ���� FTP server
	int						m_nUploadFTPPort;
	char					m_szUploadFTPAccount[SIZE_MAX_ACCOUNT_NAME];
	char					m_szUploadFTPPassword[SIZE_MAX_PASSWORD];

	VersionInfo				m_ClientReinstallVersion;		// re-install version
	vector<VersionInfo>		m_vectorCriticalUpdateVersion;	// critical update version list
	vector<string>			m_AllowedIPList;
	vector<vector<string> >	m_AllowedIPList_ReloadVersion;	// 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
	set<string>				m_AllowedAccounts;
	BOOL					m_bRandomFieldSelect;			// Pre Server���� ���ʷ� �����ؾ� �� Field Server�� IP�� ���� �� Random���� �������� ���� ����
	vector<CServerGroup*>	m_AllServerGroupVectorForLoading;	// �� �ε��� �Ŀ��� �ٷ� ������

	///////////////////////////////////////////////////////////////////////////////	
	// 2007-05-02 by cmkwon, PreServer ������ ���
	vectSGAME_SERVER_GROUP	m_vectGameServerGroupList;

	// 2007-07-06 by cmkwon, OnlyChoiceServer �÷��� ���� �߰�
	BOOL					m_bIsOnlyChoiceServer;				// 2007-07-06 by cmkwon, OnlyChoiceServer �÷��� ���� �߰�

	char					m_szGamePublisherName[SIZE_MAX_GAME_PUBLISHER_NAME];		// 2010-06-01 by shcho, GLogDB ���� -
	// 2012-10-05 by jhseol, NPlay pc�� ��� - NPlay ���� IP
	char					m_szNPlayServerIP_Real[SIZE_MAX_IPADDRESS];		// ���󼭹�
	char					m_szNPlayServerIP_BackUP[SIZE_MAX_IPADDRESS];	// �������
	BYTE					m_nNPlayConectServer;							// ����� ����
	// 2012-10-05 by jhseol, NPlay pc�� ��� - NPlay ���� IP
public:
	BOOL					m_bIgnoreClientVersionUpdate;
	int						m_nServerGroupLimiteUserCount;		// 2006-10-11 by cmkwon

public:
	// Ŭ���̾�Ʈ ������Ʈ ���
	char					m_szClientFTPUpdateUploadDir[SIZE_MAX_FTP_FILE_PATH];	// UPDATE_DIR// 2005-12-23 by cmkwon, ������
	char					m_szClientFTPUpdateDownloadDir[SIZE_MAX_FTP_FILE_PATH];	// 2005-12-23 by cmkwon, �߰���, UPDATE_DWONLOAD_DIR
	char					m_szLauncherFileUploadPath[SIZE_MAX_FTP_FILE_PATH];		// LAUNCHER_FILE_NAME,// 2005-12-23 by cmkwon ����
	char					m_szLauncherFileDownloadPath[SIZE_MAX_FTP_FILE_PATH];	// 2005-12-23 by cmkwon, �߰���
	char					m_szDeleteFileListUploadPath[SIZE_MAX_FTP_FILE_PATH];	// DELFILELIST_FILE_NAME// 2005-12-23 by cmkwon
	char					m_szDeleteFileListDownloadPath[SIZE_MAX_FTP_FILE_PATH];	// DELFILELIST_FILE_NAME// 2005-12-23 by cmkwon
	char					m_szNoticeFileUploadPath[SIZE_MAX_FTP_FILE_PATH];		// NOTICE_FILE_NAME// 2005-12-23 by cmkwon
	char					m_szNoticeFileDownloadPath[SIZE_MAX_FTP_FILE_PATH];		// NOTICE_FILE_NAME// 2005-12-23 by cmkwon
	char					m_szVersionListFileUploadPath[SIZE_MAX_FTP_FILE_PATH];	// 2007-01-08 by cmkwon

	///////////////////////////////////////////////////////////////////////////////	
	// 2007-01-06 by cmkwon, Http Auto Update server ���� �߰�
	// 2007-01-06 by cmkwon, HTTP Server ����
	int						m_nAutoUpdateServerType;						// 2007-01-06 by cmkwon, AU_SERVER_TYPE_XXX
	vector<string>			m_vectDownloadHttpServer;
	USHORT					m_nDownloadHttpServerPort;
	char					m_szDownloadHttpServerAccountName[SIZE_MAX_ACCOUNT_NAME];
	char					m_szDownloadHttpServerPassword[SIZE_MAX_PASSWORD];
	char					m_szClientHttpUpdateDownloadDir[SIZE_MAX_FTP_FILE_PATH];
	char					m_szLauncherFileDownloadHttpPath[SIZE_MAX_FTP_FILE_PATH];
	char					m_szDeleteFileListDownloadHttpPath[SIZE_MAX_FTP_FILE_PATH];
	char					m_szNoticeFileDownloadHttpPath[SIZE_MAX_FTP_FILE_PATH];
	char					m_szVersionListFileDownloadHttpPath[SIZE_MAX_FTP_FILE_PATH];	// 2007-01-08 by cmkwon

	///////////////////////////////////////////////////////////////////////////////
	// 2008-02-22 by cmkwon, ServerPreServer->MasangPreServer �� ���� ���� ���� �ý��� �߰� - 
	CSPToMPWinSocket		*m_pSPToMPWinsoc;				

	CSecurityManager		*m_pSecurityManager;			// 2011-06-22 by hskim, �缳 ���� ����
	CSelectiveShutdown		*m_pSelectiveShutdown;			// 2012-07-11 by hskim, ������ �˴ٿ�
	CNPlayPCBangModule		*m_pNPlayPCBangModule;			// 2012-10-05 by jhseol, NPlay pc�� ���
};

#endif // !defined(AFX_PREGLOBAL_H__C876B35F_9CED_4C8B_BB4C_3BB6B23FD13D__INCLUDED_)
