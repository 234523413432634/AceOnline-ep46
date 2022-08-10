#include "FiveRocksDataMonetization.h"


FiveRocksDataMonetization::FiveRocksDataMonetization(void)
{
}

FiveRocksDataMonetization::~FiveRocksDataMonetization(void)
{
}

UINT32 FiveRocksDataMonetization::Init(FIVEROCKS_DATA_TYPE DataType)
{
	m_TBDataType = DataType;
	return NULL;
}
UINT32 FiveRocksDataMonetization::Processing(int Cnt)
{
	m_Data[Cnt].Reset();
	Parsing(Cnt);

	TCHAR PostData[FIVEROCKS_MAX_DATA_LENGTH] = {0};
	char PostDataUTF8[FIVEROCKS_MAX_DATA_LENGTH] = {0};

	TCHAR TempData[FIVEROCKS_MAX_DATA_LENGTH] = {0};

	if(lstrcmp(m_Data[Cnt].type,TEXT("")))
	{
		wsprintf(TempData,TEXT("&type=%s"),m_Data[Cnt].type);
		lstrcat(PostData,TempData);
	}
	if(lstrcmp(m_Data[Cnt].name,TEXT("")))
	{
		wsprintf(TempData,TEXT("&name=%s"),m_Data[Cnt].name);
		lstrcat(PostData,TempData);
	}
	if(lstrcmp(m_Data[Cnt].api_key,TEXT("")))
	{
		wsprintf(TempData,TEXT("&api_key=%s"),m_Data[Cnt].api_key);
		lstrcat(PostData,TempData);
	}
	if(lstrcmp(m_Data[Cnt].user_id,TEXT("")))
	{
		wsprintf(TempData,TEXT("&user_id=%s"),m_Data[Cnt].user_id);
		lstrcat(PostData,TempData);
	}
	if(m_Data[Cnt].user_level)
	{
		wsprintf(TempData,TEXT("&user_level=%d"),m_Data[Cnt].user_level);
		lstrcat(PostData,TempData);
	}
	if(m_Data[Cnt].freind_count)
	{
		wsprintf(TempData,TEXT("&freind_count=%d"),m_Data[Cnt].freind_count);
		lstrcat(PostData,TempData);
	}
	if(lstrcmp(m_Data[Cnt].product_id,TEXT("")))
	{
		if(m_Data[Cnt].product_num) wsprintf(TempData,TEXT("&product_id=%s(%d)"),m_Data[Cnt].product_id,m_Data[Cnt].product_num);
		else wsprintf(TempData,TEXT("&product_id=%s"),m_Data[Cnt].product_id);
		lstrcat(PostData,TempData);
	}
	if(m_Data[Cnt].price)
	{
		wsprintf(TempData,TEXT("&price=%d"),m_Data[Cnt].price);
		lstrcat(PostData,TempData);
	}
	if(lstrcmp(m_Data[Cnt].currency,TEXT("")))
	{
		wsprintf(TempData,TEXT("&currency=%s"),m_Data[Cnt].currency);
		lstrcat(PostData,TempData);
	}
	else
	{
		wsprintf(TempData,TEXT("&currency=%s"),TAPJOY_CURRENCY_JAPAN);
		lstrcat(PostData,TempData);
	}
	if(lstrcmp(m_Data[Cnt].referrer,TEXT("")))
	{
		wsprintf(TempData,TEXT("&referrer=%s"),m_Data[Cnt].referrer);
		lstrcat(PostData,TempData);
	}
	TCHAR aa[1000];
	wsprintf(aa,TEXT("%s\r\n"),PostData);
	g_LogFile->WriteSystemLog(aa);

	int PostLen = WideCharToMultiByte(CP_UTF8,0,PostData, -1,PostDataUTF8, 0,0,0);
	WideCharToMultiByte(CP_UTF8,0,PostData,lstrlen(PostData) + 1,PostDataUTF8, PostLen + 1,0,0);

	UINT32 PostResult = PostHttp(TEXT("Moentization::Processing()"),PostDataUTF8);
	if (PostResult) return PostResult;
	return NULL;
}
UINT32 FiveRocksDataMonetization::ParsingData(int Cnt, TCHAR* LeftData, TCHAR* RightData)
{
	if (!lstrcmp(LeftData,TEXT("auid")))
	{
		lstrcpy(m_Data[Cnt].user_id,RightData);
	}
	else if (!lstrcmp(LeftData,TEXT("level")))
	{
		INT64 user_level = _wtoi64(RightData);
		m_Data[Cnt].user_level = user_level;
	}
	else if (!lstrcmp(LeftData,TEXT("friends")))
	{
		INT64 freind_count = _wtoi64(RightData);
		m_Data[Cnt].freind_count = freind_count;
	}
	else if (!lstrcmp(LeftData,TEXT("itemname")))
	{
		lstrcpy(m_Data[Cnt].product_id,RightData);
	}
	else if (!lstrcmp(LeftData,TEXT("itemnum")))
	{
		INT64 product_num = _wtoi64(RightData);
		m_Data[Cnt].product_num = product_num;
	}
	else if (!lstrcmp(LeftData,TEXT("price")))
	{
		INT64 price = _wtoi64(RightData);
		m_Data[Cnt].price = price;
	}
	else if (!lstrcmp(LeftData,TEXT("currency")))
	{
		lstrcpy(m_Data[Cnt].currency,RightData);
		lstrcpy(m_Data[Cnt].referrer,TEXT(REFERR_NAME));
	}

	return NULL;
}