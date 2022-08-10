// InnovaLibrary.h: interface for the CInnovaLibrary class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INNOVALIBRARY_H__24C59265_40AC_44D4_B56A_B29CB169246C__INCLUDED_)
#define AFX_INNOVALIBRARY_H__24C59265_40AC_44D4_B56A_B29CB169246C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LoadLibrary.h"
#include "integration_api.h"


typedef int (*PROC_INNBILL_initialize)(__out_param uint_64* service_id);
typedef int (*PROC_INNBILL_uninitialize)();
typedef int (*PROC_INNBILL_login_a)(__in_param const char* user_name, __in_param const char* password, __in_param int exp_time, __in_param uint_64 ip, __out_param login_result* result);
typedef int (*PROC_INNBILL_logout_a)( __in_param const char* user_name, __in_param uint_64 time_elapsed);
typedef int (*PROC_INNBILL_check_user_status_a)( __in_param const char* user_name, __out_param double* user_balance, __out_param int* status);
typedef int (*PROC_INNBILL_buy_item_aia)( __in_param const char* user_name, __in_param uint_64 item_id, __in_param int item_type, __in_param double item_price, __in_param int item_price_type, __in_param int item_count, __in_param uint_64 service_transaction_id, __in_param const char* server_name, __in_param const char* character_name, __out_param uint_64* billing_transaction_id, __out_param double* user_balance);
typedef int (*PROC_INNBILL_cancel_buy_item_a)( __in_param const char* user_name, __in_param uint_64 service_transaction_id, __in_param uint_64 billing_transaction_id);
typedef char* (*PROC_INNBILL_error_description_a)(int error_code);
typedef int (*PROC_INNBILL_free_error_description_a)(char* err_description);


class CInnovaLibrary  : public CLoadLibrary
{
public:
	CInnovaLibrary();
	virtual ~CInnovaLibrary();

	virtual BOOL LoadProcList(void);

	BOOL INNBILL_initialize(void);
	BOOL INNBILL_uninitialize(void);
	Err_t INNBILL_login_a(char *i_szAccName, char *i_szPassword, UINT i_nClientIP);
	BOOL INNBILL_logout_a(char *i_szAccName, uint_64 i_elapsedMin);
	Err_t INNBILL_check_user_status_a(char *i_szAccName, int *o_pnTotalMoney);
	Err_t INNBILL_buy_item_aia(char *i_szAccName, int *o_pnTotalMoney, ITEM *i_pBuyItemInfo, char *i_szServerGroupName, char *i_szCharName, uint_64* o_pbillTranID);
	BOOL INNBILL_cancel_buy_item_a(char *i_szAccName, uint_64 i_billTranID);
	const char* INNBILL_ErrorDescription(string &o_strErrDescription, int i_nErrCode);


protected:
	
	PROC_INNBILL_initialize					ms_pProcInnBill_initialize;
	PROC_INNBILL_uninitialize				ms_pProcInnBill_uninitialize;
	PROC_INNBILL_login_a					ms_pProcInnBill_login_a;
	PROC_INNBILL_logout_a					ms_pProcInnBill_logout_a;
	PROC_INNBILL_check_user_status_a		ms_pProcInnBill_check_user_status_a;
	PROC_INNBILL_buy_item_aia				ms_pProcInnBill_buy_item_aia;
	PROC_INNBILL_cancel_buy_item_a			ms_pProcInnBill_cancel_buy_item_a;
	PROC_INNBILL_error_description_a		ms_pProcInnBill_error_description_a;
	PROC_INNBILL_free_error_description_a	ms_pProcInnBill_free_error_description_a;
};

#endif // !defined(AFX_INNOVALIBRARY_H__24C59265_40AC_44D4_B56A_B29CB169246C__INCLUDED_)
