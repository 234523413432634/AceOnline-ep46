#ifndef	_BILLING_YETIME_CHN_H_
#define	_BILLING_YETIME_CHN_H_


#include "AtumParam.h"


#ifdef SERVICE_TYPE_CHINESE_SERVER_1		// 2008-01-17 by cmkwon, 다른 나라 컴파일 오류 발생하지 않도록 수정

#import "./../lib/acepay.tlb" named_guids
using namespace ACEPay;

///////////////////////////////////////////////////////////////////////////////
/// \fn			Err_t BillingPayW_Yetime_Chn(int *o_pnCurTotalMoney, char *i_szServerGroupName, char *i_szAccountName, char *i_szCharacterName, int i_nBuyItemNum=0, int i_nBuyCnts=0, int i_nBuyTotalMoney=0)
/// \brief		// 2007-08-22 by cmkwon, 중국 Yetime 빌링 라이브러리 적용 - Wrapper 한 함수
/// \author		cmkwon
/// \date		2007-08-22 ~ 2007-08-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
Err_t BillingPayW_Yetime_Chn(int *o_pnCurTotalMoney, char *o_szErrString, char *i_szServerGroupName, char *i_szAccountName, char *i_szCharacterName, int i_nBuyItemNum=0, int i_nBuyCnts=0, int i_nBuyTotalMoney=0);

#endif	// 2008-01-17 by cmkwon, 다른 나라 컴파일 오류 발생하지 않도록 수정

#endif