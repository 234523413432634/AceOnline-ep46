#include "FiveRocksDataActiveUser.h"


FiveRocksDataActiveUser::FiveRocksDataActiveUser(void)
{
}

FiveRocksDataActiveUser::~FiveRocksDataActiveUser(void)
{
}

UINT32 FiveRocksDataActiveUser::Init(FIVEROCKS_DATA_TYPE DataType)
{
	m_TBDataType = DataType;
	return NULL;
}
UINT32 FiveRocksDataActiveUser::Processing(int Cnt)
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
	if(lstrcmp(m_Data[Cnt].referrer,TEXT("")))
	{
		wsprintf(TempData,TEXT("&referrer=%s"),m_Data[Cnt].referrer);
		lstrcat(PostData,TempData);
	}

	int PostLen = WideCharToMultiByte(CP_UTF8,0,PostData, -1,PostDataUTF8, 0,0,0);
	WideCharToMultiByte(CP_UTF8,0,PostData,lstrlen(PostData) + 1,PostDataUTF8, PostLen + 1,0,0);

	UINT32 PostResult = PostHttp(TEXT("ActiveUser::Processing()"),PostDataUTF8);
	if (PostResult) return PostResult;
	return FIVEROCKS_DB_RECORD_NO_DELETE;
}
UINT32 FiveRocksDataActiveUser::ParsingData(int Cnt, TCHAR* LeftData, TCHAR* RightData)
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
	else if (!lstrcmp(LeftData,TEXT("channel")))
	{
	}
	else if (!lstrcmp(LeftData,TEXT("channeling")))
	{
		for (int i = 0 ; i < g_nMax_Count_DbChanneling ; i++)
		{
			if (!lstrcmp(RightData,g_DbChannelingName[i]))
			{
				lstrcpy(m_Data[Cnt].referrer,TEXT(REFERR_NAME));
			}
		}
	}
	else if (!lstrcmp(LeftData,TEXT("influence")))
	{
	}
	else if (!lstrcmp(LeftData,TEXT("geartype")))
	{
	}

	return NULL;
}