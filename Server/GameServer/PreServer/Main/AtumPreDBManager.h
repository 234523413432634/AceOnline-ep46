#ifndef __ATUM_PRE_DB_MANAGER_H__
#define __ATUM_PRE_DB_MANAGER_H__

#include "AtumDBManager.h"


struct MSG_DB_TOTAL_USER
{
	char		szServerGroup[SIZE_MAX_SERVER_NAME];
	int			nMGameServerID;
	int			nUserCounts;
#ifdef S_ARARIO_HSSON
	int			nUserCountsOtherPublisherConncect;		// 2010-11 by dhjin, �ƶ󸮿� ä�θ� �α���.
#endif
};

struct QPARAM_GLOG_INSERT_ACCOUNT
{// 2010-06-01 by shcho, GLogDB ���� -
	char		szAccountName[SIZE_MAX_ACCOUNT_NAME];
};

// start 2012-01-13 by hskim, EP4 [������ 1ȸ ���]
struct QPARAM_UPDATE_ACCOUNT_LASTGAMEENDDATE
{
	UID32_t		AccountUniqueNumber;
};
// end 2012-01-13 by hskim, EP4 [������ 1ȸ ���]

class CPreIOCP;
class CAtumPreDBManager : public CAtumDBManager
{
public:
	CAtumPreDBManager(CPreIOCP *pPreIOCP);

	BOOL ProcessServerQuery(DB_QUERY dbquery, SQLHSTMT &hstmt, SQLHSTMT &hstmt_mc, SQLHSTMT &hstmt_extAuth, SQLHSTMT &hstmt_GLog);		// 2013-06-20 by jhseol,bckim GLog ����

	// For PreServer
	void QP_PRE_Login(DB_QUERY q, SQLHSTMT &hstmt, SQLHSTMT &hstmt_extAuth);
	void QP_MGameLogin(DB_QUERY q, SQLHSTMT hstmt);
	void QP_BlockUser(DB_QUERY q, SQLHSTMT hstmt);
	void QP_UnblockUser(DB_QUERY q, SQLHSTMT hstmt);
//	void QP_LoadBlockedAccount(DB_QUERY q, SQLHSTMT hstmt);
	void QP_LogTotalUser(DB_QUERY q, SQLHSTMT hstmt);

	// 2010-06-01 by shcho, GLogDB ���� -
	void QP_InsertGlogAccount(DB_QUERY q, SQLHSTMT hstmt);

	// start 2011-12-12 by hskim, GLog 2��
	BOOL IsExistAccount(char *pAccountName, SQLHSTMT &hstmt);
	// end 2011-12-12 by hskim, GLog 2��

	// start 2012-01-13 by hskim, EP4 [������ 1ȸ ���]
	void QP_UpdateAccountLastGameEndDate(DB_QUERY q, SQLHSTMT hstmt);
	// end 2012-01-13 by hskim, EP4 [������ 1ȸ ���]

	// 2008-01-30 by cmkwon, ���� �� �α� ����� ���� - CAtumPreDBManager::LogInsertBlockUnblock() �߰�
	BOOL LogInsertBlockUnblock(SQLHSTMT hstmt, SBLOCKED_ACCOUNT_INFO *i_pBlockAccInfo, BYTE i_byLogType);

	// 2010-04-26 by cmkwon, ���þ� Innva ����/���� �ý��� ���� - 
	BOOL ExternalAuthentication(CAccountInfo *o_pAccInfo, MSG_PC_CONNECT_LOGIN *i_pLogin, SQLHSTMT &hstmt, SQLHSTMT &hstmt_extAuth, BOOL i_bAuthenticateCheck=TRUE, UINT i_nClientIP=0);

	BOOL ExecuteExtAuth(char *i_szAccName, char *i_szPwd, SQLHSTMT &hstmt_extAuth, EN_DBCONN_TYPE i_dbConnTy=EN_DBCONN_EXT_AUTH);
	BOOL ExecuteExtAuth_GalaNet(INT *o_pnExtAccountIDNum, char *i_szAccName, char *i_szPwd, SQLHSTMT &hstmt_extAuth, EN_DBCONN_TYPE i_dbConnTy=EN_DBCONN_EXT_AUTH);
	BOOL ExecuteExtAuth2(char *i_szAccName, char *i_szPwd, char *i_szWebLoginAuthKey, SQLHSTMT &hstmt_extAuth, EN_DBCONN_TYPE i_dbConnTy=EN_DBCONN_EXT_AUTH);
	// 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó��
	BOOL ExecuteExtAuth_Arg(char *i_szAccName, char *i_szPwd);
	// end 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó��

	BOOL ExecuteExtAuthChina(char *o_szJuminNumber, char *i_szAccName, char *i_szPwd, SQLHSTMT &hstmt_extAuth, EN_DBCONN_TYPE i_dbConnTy=EN_DBCONN_EXT_AUTH);	// 2007-06-29 by cmkwon, td_account ���̺� �ֹι�ȣ�����ϱ� - �����Լ� �߰�	

	// 2008-10-08 by cmkwon, �븸 Netpower_Tpe �ܺ����� ���� - 
	BOOL ExecuteExtAuth_Taiwanese(MSG_PC_CONNECT_LOGIN *i_pLogin, char *i_szMD5Pwd, SQLHSTMT &hstmt_extAuth, EN_DBCONN_TYPE i_dbConnTy=EN_DBCONN_EXT_AUTH);

	// 2008-12-18 by cmkwon, �Ϻ� Arario �ܺ�����, ���� ��� �����ϱ� - 
	BOOL ExecuteExtAuth_Arario(MSG_PC_CONNECT_LOGIN *i_pLogin, char *i_szMD5Pwd, char *i_szSessionKey);

	///////////////////////////////////////////////////////////////////////////////
	// 2010-04-26 by cmkwon, ���þ� Innva ����/���� �ý��� ���� - 
	BOOL ExecuteExtAuth_Innova(MSG_PC_CONNECT_LOGIN *i_pLogin, UINT i_nClientIP);


	///////////////////////////////////////////////////////////////////////////////
	// 2008-12-01 by cmkwon, �������� �����带 ����� ó���ϴ� �ý��� ���� - 
	virtual BOOL ProcessDinamicServerQuery(DB_QUERY *i_qQuery, CODBCStatement *i_pODBC);

public:
	CPreIOCP	*m_pPreIOCP2;
};

#endif