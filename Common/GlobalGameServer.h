                            // GlobalGameServer.h: interface for the CGlobalGameServer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLOBALGAMESERVER_H__A4741983_FEBC_498A_878A_A082B9852FD1__INCLUDED_)
#define AFX_GLOBALGAMESERVER_H__A4741983_FEBC_498A_878A_A082B9852FD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Global.h"
#include "SocketHeader.h"
#include "AtumParam.h"
#include "Localization.h"


//////////////////////////////////////////////////////////////////////////
// Configuration File Path
#ifdef ARENA
#define GLOBAL_CONFIG_FILE_PATH					(string(CONFIG_ROOT)+string("./arenaglobal.cfg")).c_str()
#define IM_SERVER_CONFIG_FILE_PATH				(string(CONFIG_ROOT)+string("./arenaim.cfg")).c_str()
#define FIELD_SERVER_CONFIG_FILE_PATH			(string(CONFIG_ROOT)+string("./arenafield.cfg")).c_str()
#define NPC_SERVER_CONFIG_FILE_PATH				(string(CONFIG_ROOT)+string("./arenanpc.cfg")).c_str()
#else
#define GLOBAL_CONFIG_FILE_PATH					(string(CONFIG_ROOT)+string("./global.cfg")).c_str()
#define IM_SERVER_CONFIG_FILE_PATH				(string(CONFIG_ROOT)+string("./im.cfg")).c_str()
#define FIELD_SERVER_CONFIG_FILE_PATH			(string(CONFIG_ROOT)+string("./field.cfg")).c_str()
#define NPC_SERVER_CONFIG_FILE_PATH				(string(CONFIG_ROOT)+string("./npc.cfg")).c_str()
#endif
#define HAPPYHOUR_EVENT_CONFIG_FILE_PATH		(string(CONFIG_ROOT)+string("./happyHourEvent.cfg")).c_str()
#define LOCALIZATION_CONFIG_DIRECTORY_PATH		(string(CONFIG_ROOT)+string("/localization")).c_str()
#define AUTHENTICATION_CONFIG_FILE_PATH					(string(CONFIG_ROOT)+string("./authentication.cfg")).c_str()		// 2011-01-26 by hskim, ���� ���� ����

// 2008-04-03 by cmkwon, �ٽ��� ���� ���� �ý��� ���� - �Ʒ��� ���� ���丮�� ����
// // 2008-03-24 by cmkwon, �ٽ��� 2.0 ���� - �Ʒ��� ���� ������, '/' ��� �Ұ�, '\' ��� �ؾ� ��
// //#define SECURITY_HACKSHIELD_DIRECTORY_PATH		(string(CONFIG_ROOT)+string("./Security/HackShield/HackShield.crc")).c_str()		// 2006-06-05 by cmkwon
// #define SECURITY_HACKSHIELD_DIRECTORY_PATH		(string(CONFIG_ROOT)+string(".\\Security\\HackShield\\HackShield.crc")).c_str()		// 2008-03-24 by cmkwon, �ٽ��� 2.0 ���� - �Ʒ��� ���� ������, '/' ��� �Ұ�, '\' ��� �ؾ� ��
#define SECURITY_HACKSHIELD_DIRECTORY_PATH		(string(CONFIG_ROOT)+string(".\\Security\\HackShield")).c_str()		// 2008-04-03 by cmkwon, �ٽ��� ���� ���� �ý��� ���� - ���丮�� ������
#define SECURITY_XIGNCODE_DIRECTORY_PATH		(string(CONFIG_ROOT)+string("Security\\xigncode\\")).c_str()		// 2008-11-28 by cmkwon, �븸 Netpower_Tpe XignCode(���Ӱ���) ���� - 
#define SECURITY_NPROTECT_DIRECTORY_PATH		(string(CONFIG_ROOT)+string("Security\\nProtect\\")).c_str()		// 2009-03-09 by cmkwon, �Ϻ� Arario nProtect�� CS���� �����ϱ� - 
#define SECURITY_XTRAP_DIRECTORY_PATH			(string(CONFIG_ROOT)+string("Security\\XTrap")).c_str()			// 2009-10-06 by cmkwon, ��Ʈ�� ���� ���� X-TRAP���� ���� - 

#define	PCBANG_IPADDR_FILE_PATH					(string(CONFIG_ROOT)+string("./PCBangIPList.cfg")).c_str()						// 2006-08-14 by dhjin
#define	RESOBJ_DIRECTORY_PATH					(string(CONFIG_ROOT)+string("./../map/Res-Obj")).c_str()							// 2007-05-28 by cmkwon
#define	RESTEX_DIRECTORY_PATH					(string(CONFIG_ROOT)+string("./../map/Res-Tex")).c_str()						// 2007-07-18 by cmkwon, omi.tex�� üũ���� üũ ��ƾ �߰�
#define	RESEXE_DIRECTORY_PATH					(string(CONFIG_ROOT)+string("./../map/Res-EXE")).c_str()						// 2008-09-17 by cmkwon, Ŭ���̾�Ʈ �������ϵ� üũ�� üũ �߰� - 


// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
#define CONFIG_NAME_DB_SERVER_IP						"DBServerIP"
#define CONFIG_NAME_DB_SERVER_PORT						"DBServerPort"
#define CONFIG_NAME_DB_SERVER_DATABASE_NAEE				"DBServerDatabaseName"
#define CONFIG_NAME_LOGDB_DB_SERVER_IP					"LOGDB_DBServerIP"
#define CONFIG_NAME_LOGDB_DB_SERVER_PORT				"LOGDB_DBServerPort"
#define CONFIG_NAME_LOGDB_DB_SERVER_DATABASE_NAEE		"LOGDB_DBServerDatabaseName"
#define CONFIG_NAME_EXT_AUTH_DB_SERVER_IP				"ExtAuthDBServerIP"
#define CONFIG_NAME_EXT_AUTH_DB_SERVER_PORT				"ExtAuthDBServerPort"
#define CONFIG_NAME_EXT_AUTH_DB_SERVER_DATABASE_NAEE	"ExtAuthDBServerDatabaseName"
// 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - grobal.cfg, Pre.cfg�� SOAP���� ���� �߰�
#define CONFIG_NAME_EXT_AUTH_SOAP_URL					"ExtAuthSOAPURL"
#define CONFIG_NAME_EXT_AUTH_SOAP_GAMEID				"ExtAuthSOAP"
// END 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - grobal.cfg, Pre.cfg�� SOAP���� ���� �߰�

// 2014-02-10 by jhseol&bckim, ü�θ� - ����� CI�� Ȯ���� �ϱ� ���� �ܺ� �������� DB����
#define CONFIG_NAME_IS_EXTERNAL_USER_INFO					"IsExternalUserInfo"
#define CONFIG_NAME_EXT_USER_INFO_ODBC_UID					"ExtUserInfoODBCUID"
#define CONFIG_NAME_EXT_USER_INFO_ODBC_PASSWD				"ExtUserInfoODBCPASSWD"
#define CONFIG_NAME_EXT_USER_INFO_DB_SERVER_IP				"ExtUserInfoDBServerIP"
#define CONFIG_NAME_EXT_USER_INFO_DB_SERVER_PORT			"ExtUserInfoDBServerPort"
#define CONFIG_NAME_EXT_USER_INFO_DB_SERVER_DATABASE_NAME	"ExtUserInfoDBServerDatabaseName"
// end 2014-02-10 by jhseol&bckim, ü�θ� - ����� CI�� Ȯ���� �ϱ� ���� �ܺ� �������� DB����

//////////////////////////////////////////////////////////////////////////
// Timer Variables
const UINT TIMERID_TRAFFIC						= 100;					// Traffic ����� Timer
const UINT TIMERID_ALIVE_CHECK					= 101;					// �������� Alive Check Timer
const UINT TIMERID_RECONNECT					= 102;
const UINT TIMERID_SERVER_GROUP_INFO			= 103;
const UINT TIMERGAP_TRAFFIC						= 10000;				// 10��(10*1000)
const UINT TIMERGAP_ALIVE_CHECK					= 60000;				// 60��(60*1000)
const UINT TIMERGAP_RECONNECT					= 5000;					// 5��
const UINT TIMERGAP_LOGSYSTEM					= 300000;				// 5��(5*60*1000)
const UINT TIMERGAP_SERVER_GROUP_INFO			= 30000;				// 30��
const UINT TIMERGAP_GLOGSYSTEM					= 550000;				// 10�� (10*60*1000 - ����)		// 2011-12-12 by hskim, GLog 2�� // 2010-06-01 by shcho, GLogDB ����		
const UINT TIMERGAP_TRIGGER_SYSTEM				= 60000;				// 60��(60 * 1000)	// 2011-10-28 by hskim, EP4 [Ʈ���� �ý���] - ũ����Ż �ý���

// 2008-03-03 by cmkwon, SIZE_MAX_ODBC_CONN_STRING ���� ��ġ ���� - AtumParam.h �� ��ġ �̵� �� 
//#define SIZE_MAX_ODBC_CONN_STRING				128

class CGlobalGameServer;
//////////////////////////////////////////////////////////////////////////
// Global Variable
//////////////////////////////////////////////////////////////////////////
extern CGlobalGameServer *	g_pGlobalGameServer;		// �������������� ���� ����Ŭ����������
extern char	*				ArrCommandList[];			// Command List
extern char	*				ArrCommandListforUser[];	// �Ϲ� ������ ���� Command List
extern char	*				ArrGameMasterCommandList[];	// 2007-11-08 by cmkwon, GM ��ɾ� ���� - ��� Command List

//////////////////////////////////////////////////////////////////////////
// Global Function
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// ������ �޼��� ���ν���
int GDeleteNewLine(char *str);


typedef ez_set<string>			ezsetString;

struct SServerGroupForMame
{
	char		szServerGroupName[SIZE_MAX_SERVER_NAME];
	int			nServerIDforMGame;
};
typedef vector<SServerGroupForMame>			vectorServerGroupForMGame;

///////////////////////////////////////////////////////////////////////////////
/// \class		CGlobalGameServer
///
/// \brief		���������� Ŭ������ ����� ó���� ����
/// \author		cmkwon
/// \version	
/// \date		2004-03-18 ~ 2004-03-18
/// \warning	��ü�� �ϳ��� ������ �Ѵ�.
///////////////////////////////////////////////////////////////////////////////
class CIOCP;
class CGlobalGameServer : public CGlobal
{
public:
	CGlobalGameServer();
	virtual ~CGlobalGameServer();

	///////////////////////////////////////////////////////////////////////////
	// public Property
	void SetInstanceHandle(HINSTANCE i_hInstance);
	HINSTANCE GetInstanceHandle(void);
	void SetMainWndHandle(HWND i_hWnd);
	HWND GetMainWndHandle(void);
	UINT GetTimerIDTraffic(void);
	UINT GetTimerIDAliveCheck(void);
	UINT GetTimerIDReconnect(void);
		
	void SetIPLocal(char *i_szIP);
	char *GetIPLocal(void);
	void SetPublicIPLocal(char *i_szIP);
	char *GetPublicIPLocal(void);
	void SetIPPreServer(char *i_szIP);
	char *GetIPPreServer(void);
	void SetPortListening(int i_nPort);
	int GetPortListening(void);
	void SetPortPreServer(int i_nPort);
	int GetPortPreServer(void);	
	CIOCP *GetGIOCP(void);
	CSystemLogManager * GetPtrFieldGameLogManager(void);
	int GetMGameServerID(void){				return m_nMGameServerID1;}
	int GetLanguageType(void){				return m_nLanguageType;}
	char *GetServiceCountry(void);		// 2011-12-12 by hskim, GLog 2��

	void SetMGameEventType(MGAME_EVENT_t i_enEventType);
	void SetServerGroupName(char *i_szServerGroupName);
	char *GetServerGroupName(void);

	BOOL IsTestServer(void);
	BOOL InMasangServer(void);

	//////////////////////////////////////////////////////////////////////////
	// Method
	void PrintPreprocessorDefinitions(void);
	void WndRegisterClass(HINSTANCE hInstance, UINT IDI_Icon, char *szClass);
	BOOL InitInstance(HINSTANCE hInstance, int nCmdShow, char *szClass, char *szWindowText);
	void SetConfigRootPath(void);
//	BOOL WriteGameLog(USHORT msgType, MSG_FL_LOG* log, char* szAction, ofstream* file = NULL);
	const char* GetSZLogType(USHORT type);
	BOOL StartTimerTraffic(void);
	void EndTimerTraffic(void);
	BOOL StartTimerAliveCheck(void);
	void EndTimerAliveCheck(void);
	BOOL StartTimerReconnect(void);	
	void EndTimerReconnect(void);

	void CheckServerThread(void);
	void CalculateIOCPTraffic(void);
	void CheckClientAlive(void);

// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
//	UCHAR* GetODBCDSN() { return m_szODBCDSN; }

	UCHAR* GetODBCUID() { return m_szODBCUID; }
	UCHAR* GetODBCPASSWORD() { return m_szODBCPASSWORD; }

// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
//	UCHAR* GetLogDBODBCDSN(void) {			return m_szLogDBODBCDSN; }		// 2007-12-03 by cmkwon, ���� �α� DB ���� ���� �ϱ� ���� ���� - CGlobalGameServer::GetLogDBODBCDSN() �߰�

	UCHAR* GetLogDBODBCUID(void) {			return m_szLogDBODBCUID; }		// 2007-12-03 by cmkwon, ���� �α� DB ���� ���� �ϱ� ���� ���� - CGlobalGameServer::GetLogDBODBCUID() �߰�
	UCHAR* GetLogDBODBCPASSWORD(void) {		return m_szLogDBODBCPASSWORD; }	// 2007-12-03 by cmkwon, ���� �α� DB ���� ���� �ϱ� ���� ���� - CGlobalGameServer::GetLogDBODBCPASSWORD() �߰�

	// 2006-04-27 by cmkwon
	BOOL IsExternalAuthentication(void){		return m_bIsExternalAuthentication;}

// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
//	UCHAR* GetExtAuthODBCDSN(void) {			return m_szExtAuthODBCDSN; }

	UCHAR* GetExtAuthODBCUID(void) {			return m_szExtAuthODBCUID; }
	UCHAR* GetExtAuthODBCPASSWORD(void) {		return m_szExtAuthODBCPASSWORD; }

	// 2014-02-10 by jhseol&bckim, ü�θ� - ����� CI�� Ȯ���� �ϱ� ���� �ܺ� �������� DB����
	BOOL IsExternalUserInfo(void)					{	return m_bIsExternalUserInfo;				}
	UCHAR* GetExtUserInfoODBCUID(void)				{	return m_szExtUserInfoODBCUID;				}
	UCHAR* GetExtUserInfoODBCPASSWORD(void)			{	return m_szExtUserInfoODBCPASSWORD;			}
	char *GetExtUserInfoDBServerIP(void)			{	return m_szExtUserInfoDBServerIP;			}
	int GetExtUserInfoDBServerPort(void)			{	return m_nExtUserInfoDBServerPort;			}
	char *GetExtUserInfoDBServerDatabaseName(void)	{	return m_szExtUserInfoDBServerDatabaseName;	}
	// end 2014-02-10 by jhseol&bckim, ü�θ� - ����� CI�� Ȯ���� �ϱ� ���� �ܺ� �������� DB����

	USHORT AuthAdminToolUser(const char *i_pUID, const char *i_pPWD);

	BOOL LoadStringList(ezsetString *o_psetStirng, const char *i_szFilePath, BOOL i_bPrintFlag=FALSE);

	// �弳 �� ���� ���̵�
	BOOL LoadAbuseAndProhibitedName();
	BOOL CheckProhibitedName(const char *i_szName);

	// MGameEvent ����/ĳ���͸� �ε�
	BOOL LoadAccountNameAndCharacterNameForMGameEvent(void);
	BOOL IsExistAccountNameForMGameEvent(char *i_szAccountName);

	// 
	BOOL InsertServerGroupforMGame(char *i_szServerGroupName, int i_nServerID);
	int GetServerIDforMGame(char *i_szServerGroupName);
	char *GetServerGroupNameByMGameServerID(int i_nMServerID);

	///////////////////////////////////////////////////////////////////////////////
	// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
	char *GetDBServerIP(void);
	int GetDBServerPort(void);
	char *GetDBServerDatabaseName(void);
	char *GetLogDBDBServerIP(void);
	int GetLogDBDBServerPort(void);
	char *GetLogDBDBServerDatabaseName(void);
	char *GetExtAuthDBServerIP(void);
	int GetExtAuthDBServerPort(void);
	char *GetExtAuthDBServerDatabaseName(void);

	///////////////////////////////////////////////////////////////////////////////
	// 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó��
	BOOL GetIsExtAuthUseSOAP(void); // SOAP ��� ���� FALSE�̸� ��� ����
	char *GetExtAuthSOAPUrlString(void);
	// m_szSOAPUrlString[SIZE_MAX_URL_STRNIG];	// URL ��Ʈ��
	char *GetExtAuthSOAPGameID(void);
	//char				m_szSOAPGameID[SIZE_MAX_GAME_ID];		// GameID ��뿩��
	// END 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó��

	///////////////////////////////////////////////////////////////////////////////
	// 2008-06-05 by cmkwon, AdminTool, Monitor ���� ���� IP�� server config file �� �����ϱ� - 
	vector<string>			m_AllowedToolIPList;
	void AddAllowedToolIP(const char *i_szAllowedToolIP);
	BOOL CheckAllowedToolIP(char *i_szToolIP);

	///////////////////////////////////////////////////////////////////////////////
	// 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
	vector<vector<string> >	m_AllowedToolIPList_ReloadVersion;
	void ReLoad_AllowedToolIPList();
	virtual BOOL ReLoadConfiguration(void){	return FALSE;};
	// end 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����

	int GetServerID()		{ return m_nMGameServerID1; }		// 2013-03-13 by hskim, �� ĳ�� ����

public:	
	///////////////////////////////////////////////////////////////////////////
	// virtual Function	
	virtual BOOL InitServerSocket(void);						// ���ϰ��� �ʱ�ȭ �Լ�
	virtual BOOL EndServerSocket(void);							// ���ϰ��� ���� �Լ�
	virtual BOOL LoadConfiguration(void){	return FALSE;};		// Server ������ ���� Configuration Load

protected:
	//////////////////////////////////////////////////////////////////////////
	// ������ ���� ��� ����
	HINSTANCE			m_hInstanceHandle;				// ����� �ν��Ͻ� �ڵ�
	HWND				m_hMainWndHandle;				// ����� ���� ������ �ڵ�

	//////////////////////////////////////////////////////////////////////////
	// ������ Ÿ�̹� ���� ��� ����
	UINT				m_nTimerIDTraffic;				// ��� �������� Bandwidth ����� ���� TimerID
	UINT				m_nTimerIDAliveCheck;			// ��� �������� Ŭ���̾�Ʈ�� Alive üũ�� ���� TimerID
	UINT				m_nTimerIDReconnect;			// ����(IMServer, FieldServer, NPCServer)���� ���� ������ ������ ���� �Ǿ����� �������� ���� TimerID

	//////////////////////////////////////////////////////////////////////////
	// Configuration Variables
	char				m_szIPLocal[SIZE_MAX_IPADDRESS];				// All (Pre, IM, Field, NPC)
	char				m_szPublicIPLocal[SIZE_MAX_IPADDRESS];			// All (Pre, IM, Field, NPC)// 2006-05-23 by cmkwon
	char				m_szIPPreServer[SIZE_MAX_IPADDRESS];			// two (IM, Field)
	int					m_nPortListening;								// one (Field)
	int					m_nPortPreServer;								// two (IM, Field)
	CSystemLogManager	m_FieldGameLogManager;
	UCHAR				m_szODBCDSN[SIZE_MAX_ODBC_CONN_STRING];			// ODBC_DSN
	UCHAR				m_szODBCUID[SIZE_MAX_ODBC_CONN_STRING];			// ODBC_UID
	UCHAR				m_szODBCPASSWORD[SIZE_MAX_ODBC_CONN_STRING];		// ODBC_PASSWD

	// 2007-12-03 by cmkwon, ���� �α� DB ���� ���� �ϱ� ���� ���� - CGlobalGameServer �� ��� ���� �߰�
	UCHAR				m_szLogDBODBCDSN[SIZE_MAX_ODBC_CONN_STRING];			// LogDB_ODBC_DSN
	UCHAR				m_szLogDBODBCUID[SIZE_MAX_ODBC_CONN_STRING];			// LogDB_ODBC_UID
	UCHAR				m_szLogDBODBCPASSWORD[SIZE_MAX_ODBC_CONN_STRING];		// LogDB_ODBC_PASSWD

	///////////////////////////////////////////////////////////////////////////////
	// 2006-04-27 by cmkwon, �ܺ� DB ���� ����
	BOOL					m_bIsExternalAuthentication;						// �ܺ� DB ���� �÷���
	UCHAR					m_szExtAuthODBCDSN[SIZE_MAX_ODBC_CONN_STRING];			// EXT_AUTH_ODBC_DSN
	UCHAR					m_szExtAuthODBCUID[SIZE_MAX_ODBC_CONN_STRING];			// EXT_AUTH_ODBC_UID
	UCHAR					m_szExtAuthODBCPASSWORD[SIZE_MAX_ODBC_CONN_STRING];		// EXT_AUTH_ODBC_PASSWD

	///////////////////////////////////////////////////////////////////////////////
	// 2014-02-10 by jhseol&bckim, ü�θ� - ����� CI�� Ȯ���� �ϱ� ���� �ܺ� �������� DB����
	BOOL					m_bIsExternalUserInfo;						// �ܺ� user info ��ȸ���� �÷���
	UCHAR					m_szExtUserInfoODBCUID[SIZE_MAX_ODBC_CONN_STRING];			// EXT_USER_INFO_ODBC_UID
	UCHAR					m_szExtUserInfoODBCPASSWORD[SIZE_MAX_ODBC_CONN_STRING];		// EXT_USER_INFO_ODBC_PASSWD
	char					m_szExtUserInfoDBServerIP[SIZE_MAX_ODBC_CONN_STRING];
	int						m_nExtUserInfoDBServerPort;
	char					m_szExtUserInfoDBServerDatabaseName[SIZE_MAX_ODBC_CONN_STRING];

	///////////////////////////////////////////////////////////////////////////////
	// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
	char				m_szDBServerIP[SIZE_MAX_ODBC_CONN_STRING];
	int					m_nDBServerPort;
	char				m_szDBServerDatabaseName[SIZE_MAX_ODBC_CONN_STRING];

	// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
	char				m_szLogDBDBServerIP[SIZE_MAX_ODBC_CONN_STRING];
	int					m_nLogDBDBServerPort;
	char				m_szLogDBDBServerDatabaseName[SIZE_MAX_ODBC_CONN_STRING];

	// 2008-07-11 by cmkwon, MySQL ������ ���� ����(IP,Port �� DB ���� ����) - 
	char				m_szExtAuthDBServerIP[SIZE_MAX_ODBC_CONN_STRING];
	int					m_nExtAuthDBServerPort;
	char				m_szExtAuthDBServerDatabaseName[SIZE_MAX_ODBC_CONN_STRING];


	char				m_szServerGroupName[SIZE_MAX_SERVER_NAME];		// one (IM)
	
	///////////////////////////////////////////////////////////////////////////////
	// 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó��
	BOOL				m_IsSOAPUse;			// SOAP ��� ���� FALSE�̸� ��� ����
	char				m_szSOAPUrlString[SIZE_MAX_URL_STRNIG];	// URL ��Ʈ��
	char				m_szSOAPGameID[SIZE_MAX_GAME_ID];		// GameID ��뿩��
	// END 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó��

	vectorServerGroupForMGame		m_vectorServerGroupForMGame;		// Log, Field
	int					m_nMGameServerID1;								// Log, Field


	ezsetString			m_setAbuseWords;
	ezsetString			m_setProhibitedNames;

	ezsetString			m_setAccountNameForMGameEvent;
	ezsetString			m_setCharacterNameForMGameEvent;

	BOOL				m_bIsTestServer;								// TestServer ����

	int					m_nLanguageType;

	CIOCP *				m_pGIOCP;


public:
	CLocalization		m_Localization;
	MGAME_EVENT_t		m_enMGameEventType;							// MGameEvent 
};

typedef mt_set<UID32_t>		mtsetUID32;

#endif // !defined(AFX_GLOBALGAMESERVER_H__A4741983_FEBC_498A_878A_A082B9852FD1__INCLUDED_)
