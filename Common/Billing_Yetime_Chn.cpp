

#include "Billing_Yetime_Chn.h"
#include "AtumError.h"

// 2008-01-08 by cmkwon, �ٸ� ���� ������ ���� �߻����� �ʵ��� ����
#ifdef SERVICE_TYPE_CHINESE_SERVER_1

///////////////////////////////////////////////////////////////////////////////
/// \fn			Err_t BillingPayW_Yetime_Chn(int *o_pnCurTotalMoney, char *o_szErrString, char *i_szServerGroupName, char *i_szAccountName, char *i_szCharacterName, int i_nBuyItemNum=0, int i_nBuyCnts=0, int i_nBuyTotalMoney=0)
/// \brief		// 2007-08-22 by cmkwon, �߱� Yetime ���� ���̺귯�� ���� - Wrapper �� �Լ�
/// \author		cmkwon
/// \date		2007-08-22 ~ 2007-08-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
Err_t BillingPayW_Yetime_Chn(int *o_pnCurTotalMoney, char *o_szErrString, char *i_szServerGroupName, char *i_szAccountName, char *i_szCharacterName, int i_nBuyItemNum/*=0*/, int i_nBuyCnts/*=0*/, int i_nBuyTotalMoney/*=0*/)
{
	_ACEPayLib *pACEPayLib = NULL;

	HRESULT hr = ::CoCreateInstance(__uuidof(ACEPayLib)
							,NULL
							, CLSCTX_INPROC_SERVER
							, __uuidof(_ACEPayLib)
							, (void**)&pACEPayLib);

	if(FAILED(hr)
		|| NULL == pACEPayLib)
	{
		strcpy(o_szErrString, "CoCreateInstance error");
		return ERR_CASH_LIBRARY_INIT_ERROR;
	}

	if(i_nBuyItemNum)
	{
		if(0 >= i_nBuyCnts
			|| 0 >= i_nBuyTotalMoney)
		{
			return ERR_CASH_INVALID_ITEM_INFORMATION;
		}
		
		try
		{
			LONG lErr = pACEPayLib->PayItem(i_szAccountName, i_szServerGroupName, i_szCharacterName, i_nBuyItemNum, i_nBuyCnts, i_nBuyTotalMoney);
			///////////////////////////////////////////////////////////////////////////////
			// PayItem() �Լ��� ���ϰ�
			// 0	: ���� (success), ���̿��� ���� ����
			// 1	: ó�� ����, �ܾ� ����
			// -1	: ó�� ����, ���� ���� ����� ���� ������
			if(0 != lErr)
			{
				sprintf(o_szErrString, "PayItem error(%d)", lErr);
				return ERR_CASH_mgQueryMall_RESULT_CANNOT_PAYMENT;
			}
		}
		catch(_com_error &err)
		{			
			sprintf(o_szErrString, "PayItem catch error(%d)", err.Error());
			return ERR_CASH_mgQueryMall_ERROR;
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	// 2007-08-22 by cmkwon, ���� ���� �ݾ��� �����´�
	try
	{
		*o_pnCurTotalMoney = pACEPayLib->GetBalance(i_szAccountName);
	}
	catch(_com_error &err)
	{
		sprintf(o_szErrString, "GetBalance catch error(0x%X:%s)", err.Error(), err.ErrorMessage());
		return ERR_CASH_mgQueryMall_ERROR;
	}
	pACEPayLib->Release();

	return ERR_NO_ERROR;
}

#endif // END - #ifdef SERVICE_TYPE_CHINESE_SERVER_1
