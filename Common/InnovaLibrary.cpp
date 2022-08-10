// InnovaLibrary.cpp: implementation of the CInnovaLibrary class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "InnovaLibrary.h"
#include "AtumError.h"
#include "GlobalGameServer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInnovaLibrary::CInnovaLibrary()
{
	ms_pProcInnBill_initialize					= NULL;
	ms_pProcInnBill_uninitialize				= NULL;
	ms_pProcInnBill_login_a						= NULL;
	ms_pProcInnBill_logout_a					= NULL;
	ms_pProcInnBill_check_user_status_a			= NULL;
	ms_pProcInnBill_buy_item_aia				= NULL;
	ms_pProcInnBill_cancel_buy_item_a			= NULL;
	ms_pProcInnBill_error_description_a			= NULL;
	ms_pProcInnBill_free_error_description_a	= NULL;
}

CInnovaLibrary::~CInnovaLibrary()
{
	this->FreeLibraryw();
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2010-04-26 by cmkwon, 러시아 Innva 인증/빌링 시스템 변경 - 
/// \author		cmkwon
/// \date		2010-04-26 ~ 2010-04-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CInnovaLibrary::LoadProcList(void)
{	
#if defined(SERVICE_TYPE_RUSSIAN_SERVER_1)
	if(FALSE == CLoadLibrary::GetProcAddressw((FARPROC *)(&ms_pProcInnBill_initialize), "innbill_initialize"))
	{
		return FALSE;
	}
	if(FALSE == CLoadLibrary::GetProcAddressw((FARPROC *)(&ms_pProcInnBill_uninitialize), "innbill_uninitialize"))
	{
		return FALSE;
	}

	if(FALSE == CLoadLibrary::GetProcAddressw((FARPROC *)(&ms_pProcInnBill_login_a), "innbill_login_a"))
	{
		return FALSE;
	}
	if(FALSE == CLoadLibrary::GetProcAddressw((FARPROC *)(&ms_pProcInnBill_logout_a), "innbill_logout_a"))
	{
		return FALSE;
	}
	if(FALSE == CLoadLibrary::GetProcAddressw((FARPROC *)(&ms_pProcInnBill_check_user_status_a), "innbill_check_user_status_a"))
	{
		return FALSE;
	}
	if(FALSE == CLoadLibrary::GetProcAddressw((FARPROC *)(&ms_pProcInnBill_buy_item_aia), "innbill_buy_item_aia"))
	{
		return FALSE;
	}
	if(FALSE == CLoadLibrary::GetProcAddressw((FARPROC *)(&ms_pProcInnBill_cancel_buy_item_a), "innbill_cancel_buy_item_a"))
	{
		return FALSE;
	}
	if(FALSE == CLoadLibrary::GetProcAddressw((FARPROC *)(&ms_pProcInnBill_error_description_a), "innbill_error_description_a"))
	{
		return FALSE;
	}
	if(FALSE == CLoadLibrary::GetProcAddressw((FARPROC *)(&ms_pProcInnBill_free_error_description_a), "innbill_free_error_description_a"))
	{
		return FALSE;
	}

	return TRUE;
#endif

	return FALSE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2010-04-26 by cmkwon, 러시아 Innva 인증/빌링 시스템 변경 - 
/// \author		cmkwon
/// \date		2010-04-26 ~ 2010-04-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CInnovaLibrary::INNBILL_initialize(void)
{
#if defined(SERVICE_TYPE_RUSSIAN_SERVER_1)
	mt_auto_lock mtA(this->GetmtlockPtr());

	if(NULL == ms_pProcInnBill_initialize){			return FALSE;}

	uint_64  serviID	= 0;
	int nRet = ms_pProcInnBill_initialize(&serviID);
	if(0 != nRet)
	{
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[ERROR] innbill CInnovaLibrary::INNBILL_initialize# nRetCode(%d:%s) ServiceID(%I64d) \r\n", nRet, this->INNBILL_ErrorDescription(string(), nRet), serviID);
		return FALSE;
	}
	
	return TRUE;
#endif

	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2010-04-26 by cmkwon, 러시아 Innva 인증/빌링 시스템 변경 - 
/// \author		cmkwon
/// \date		2010-04-26 ~ 2010-04-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CInnovaLibrary::INNBILL_uninitialize(void)
{
#if defined(SERVICE_TYPE_RUSSIAN_SERVER_1)

	mt_auto_lock mtA(this->GetmtlockPtr());

	if(NULL == ms_pProcInnBill_uninitialize){			return FALSE;}

	int nRet = ms_pProcInnBill_uninitialize();
	if(0 != nRet)
	{
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[ERROR] innbill CInnovaLibrary::INNBILL_uninitialize# nRetCode(%d:%s) \r\n", nRet, this->INNBILL_ErrorDescription(string(), nRet));
		return FALSE;
	}
	return TRUE;
#endif

	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2010-04-26 by cmkwon, 러시아 Innva 인증/빌링 시스템 변경 - 
/// \author		cmkwon
/// \date		2010-04-26 ~ 2010-04-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
Err_t CInnovaLibrary::INNBILL_login_a(char *i_szAccName, char *i_szPassword, UINT i_nClientIP)
{
	if(NULL == ms_pProcInnBill_login_a){			return ERR_INVALID_HANDLE;}

	int				nExpTime		= 0;
	uint_64			n64ClientIP		= i_nClientIP;
	login_result	tmResult;
	MEMSET_ZERO( &tmResult, sizeof(tmResult));

	int nRet = ms_pProcInnBill_login_a(i_szAccName, i_szPassword, nExpTime, n64ClientIP, &tmResult);
	if(0 != nRet)
	{
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[ERROR] innbill CInnovaLibrary::INNBILL_login_a# nRetCode(%d:%s) AccName(%s) status(%d) \r\n", nRet, this->INNBILL_ErrorDescription(string(), nRet), i_szAccName, tmResult.user_status);
		return ERR_KNOWN_ERROR;
	}
	if(2 == tmResult.user_status)
	{
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[ERROR] innbill CInnovaLibrary::INNBILL_login_a# nRetCode(%d:%s) AccName(%s) status(%d) \r\n", nRet, this->INNBILL_ErrorDescription(string(), nRet), i_szAccName, tmResult.user_status);
		return ERR_PROTOCOL_ACCOUNT_BLOCKED;
	}

	return ERR_NO_ERROR;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2010-04-26 by cmkwon, 러시아 Innva 인증/빌링 시스템 변경 - 
/// \author		cmkwon
/// \date		2010-04-26 ~ 2010-04-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CInnovaLibrary::INNBILL_logout_a(char *i_szAccName, uint_64 i_elapsedMin)
{
	if(NULL == ms_pProcInnBill_logout_a){				return FALSE;}

	int nRet = ms_pProcInnBill_logout_a(i_szAccName, i_elapsedMin);
	if(0 != nRet)
	{
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[ERROR] innbill CInnovaLibrary::INNBILL_logout_a# nRetCode(%d:%s) AccName(%s) \r\n", nRet, this->INNBILL_ErrorDescription(string(), nRet), i_szAccName);
		return FALSE;
	}
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2010-04-26 by cmkwon, 러시아 Innva 인증/빌링 시스템 변경 - 
/// \author		cmkwon
/// \date		2010-04-26 ~ 2010-04-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
Err_t CInnovaLibrary::INNBILL_check_user_status_a(char *i_szAccName, int *o_pnTotalMoney)
{
	if(NULL == ms_pProcInnBill_check_user_status_a){			return ERR_INVALID_HANDLE;}

	double	fBalance	= 0;
	int		nStatus		= 0;
	int nRet = ms_pProcInnBill_check_user_status_a(i_szAccName, &fBalance, &nStatus);
	if(0 != nRet)
	{
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[ERROR] innbill CInnovaLibrary::INNBILL_check_user_status_a# nRetCode(%d:%s) AccName(%s) \r\n", nRet, this->INNBILL_ErrorDescription(string(), nRet), i_szAccName);
		return ERR_CASH_NORMAL_ERROR;
	}

	*o_pnTotalMoney = fBalance;
	return ERR_NO_ERROR;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2010-04-26 by cmkwon, 러시아 Innva 인증/빌링 시스템 변경 - 
/// \author		cmkwon
/// \date		2010-04-26 ~ 2010-04-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
Err_t CInnovaLibrary::INNBILL_buy_item_aia(char *i_szAccName, int *o_pnTotalMoney, ITEM *i_pBuyItemInfo, char *i_szServerGroupName, char *i_szCharName, uint_64* o_pbillTranID)
{
	if(NULL == ms_pProcInnBill_buy_item_aia){			return ERR_INVALID_HANDLE;}

	uint_64		nItemID			= i_pBuyItemInfo->ItemNum;
	int			nItemTy			= 0;		// 
	double		fItem_price		= i_pBuyItemInfo->CashPrice;
	int			nItemPriceTy	= 0;
	int			nItemCnt		= 1;		// always
	uint_64		nServTranID		= 0;
	double		fBalance		= 0;

	int nRet = ms_pProcInnBill_buy_item_aia(i_szAccName, nItemID, nItemTy, fItem_price, nItemPriceTy, nItemCnt, nServTranID, i_szServerGroupName, i_szCharName, o_pbillTranID, &fBalance);
	if(0 != nRet)
	{
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[ERROR] innbill CInnovaLibrary::INNBILL_buy_item_aia# nRetCode(%d:%s) AccName(%s) CharName(%s) BuyItem(%d:%s) \r\n", nRet, this->INNBILL_ErrorDescription(string(), nRet), i_szAccName, i_szCharName, i_pBuyItemInfo->ItemNum, i_pBuyItemInfo->ItemName);
		return ERR_CASH_NORMAL_ERROR;
	}

	*o_pnTotalMoney		= fBalance;
	return ERR_NO_ERROR;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2010-04-26 by cmkwon, 러시아 Innva 인증/빌링 시스템 변경 - 
/// \author		cmkwon
/// \date		2010-04-26 ~ 2010-04-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CInnovaLibrary::INNBILL_cancel_buy_item_a(char *i_szAccName, uint_64 i_billTranID)
{
	if(NULL == ms_pProcInnBill_cancel_buy_item_a){			return FALSE;}

	uint_64		nServTranID		= 0;
	int nRet = ms_pProcInnBill_cancel_buy_item_a(i_szAccName, nServTranID, i_billTranID);
	if(0 != nRet)
	{
		g_pGlobalGameServer->WriteSystemLogEX(TRUE, "[ERROR] innbill CInnovaLibrary::INNBILL_cancel_buy_item_a# nRetCode(%d:%s) AccName(%s) BillingTransactionID(%I64d) \r\n", nRet, this->INNBILL_ErrorDescription(string(), nRet), i_szAccName, i_billTranID);
		return FALSE;
	}

	return TRUE;
}


///////////////////////////////////////////////////////////////////////////////
/// \fn			
/// \brief		// 2010-04-26 by cmkwon, 러시아 Innva 인증/빌링 시스템 변경 - 
/// \author		cmkwon
/// \date		2010-04-26 ~ 2010-04-26
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
const char* CInnovaLibrary::INNBILL_ErrorDescription(string &o_strErrDescription, int i_nErrCode)
{
	if(NULL == ms_pProcInnBill_error_description_a
		|| NULL == ms_pProcInnBill_free_error_description_a)
	{
		o_strErrDescription = "Function Point is null !!";
		return o_strErrDescription.c_str();
	}

	char *pErrDesc = NULL;
	pErrDesc = ms_pProcInnBill_error_description_a(i_nErrCode);
	if(NULL == pErrDesc)
	{
		o_strErrDescription = "error string is null !!";
		return o_strErrDescription.c_str();
	}
	o_strErrDescription = pErrDesc;

	ms_pProcInnBill_free_error_description_a(pErrDesc);
	return o_strErrDescription.c_str();
}
