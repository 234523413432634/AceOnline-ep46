#include "FiveRocksDataCustom.h"


FiveRocksDataCustom::FiveRocksDataCustom(void)
{
}

FiveRocksDataCustom::~FiveRocksDataCustom(void)
{
}

UINT32 FiveRocksDataCustom::Init(FIVEROCKS_DATA_TYPE DataType)
{
	m_TBDataType = DataType;

	for (int i = 0 ; i < g_nMax_Count_Channeling ; i++)
	{
		m_ccuChanneling[g_ChannelingName[i]] = 0;
	}
	m_ccuChanneling[TEXT(CCU_CHNNELING_ALL_NAME)] = 0;
	return NULL;
}
UINT32 FiveRocksDataCustom::Processing(int Cnt)
{
	m_Data[Cnt].Reset();
	Parsing(Cnt);

	TCHAR PostData[FIVEROCKS_MAX_DATA_LENGTH] = {0};
	char PostDataUTF8[FIVEROCKS_MAX_DATA_LENGTH] = {0};

	TCHAR TempData[FIVEROCKS_MAX_DATA_LENGTH] = {0};
	switch(m_CustomType)
	{
	case CUSTOMTYPE_CCU_MIN:
		for (int i = 0 ; i < g_nMax_Count_Channeling ; i++)
		{
			if (!lstrcmp(m_Data[Cnt].channeling,g_ChannelingName[i]))
			{
				m_ccuChanneling[g_ChannelingName[i]] += 1;
				m_ccuChanneling[TEXT(CCU_CHNNELING_ALL_NAME)] += 1;
			}
		}
		return FIVEROCKS_DB_RECORD_NO_DELETE;
	case CUSTOMTYPE_CCU_HOUR:
		if (lstrcmp(m_Data[Cnt].time_type,TEXT("min"))) return FIVEROCKS_DB_RECORD_NO_DELETE;
		if (m_Data[Cnt].ccuall > m_ccuChanneling[TEXT(CCU_CHNNELING_ALL_NAME)])
		{
			for (int i = 0 ; i < g_nMax_Count_Channeling ; i++)
			{
				m_ccuChanneling[g_ChannelingName[i]] = m_Data[Cnt].ccu[i];
			}
			m_ccuChanneling[TEXT(CCU_CHNNELING_ALL_NAME)] = m_Data[Cnt].ccuall;
		}
		
		return NULL;
	case CUSTOMTYPE_CCU_DAY:
		if (lstrcmp(m_Data[Cnt].time_type,TEXT("hour"))) return FIVEROCKS_DB_RECORD_NO_DELETE;
		if (m_Data[Cnt].ccuall > m_ccuChanneling[TEXT(CCU_CHNNELING_ALL_NAME)])
		{
			for (int i = 0 ; i < g_nMax_Count_Channeling ; i++)
			{
				m_ccuChanneling[g_ChannelingName[i]] = m_Data[Cnt].ccu[i];
			}
			m_ccuChanneling[TEXT(CCU_CHNNELING_ALL_NAME)] = m_Data[Cnt].ccuall;
		}
		return NULL;
	case CYSTOMTYPE_PKINFO:
		lstrcpy(m_Data[Cnt].category,TEXT("PK"));
		for (int i = 0 ; i < g_nMax_Count_Channel ; i++)
		{
			if(!lstrcmp(m_Data[Cnt].channel,g_ChannelName[i]))
			{
				wsprintf(m_Data[Cnt].name, TEXT("%s PK Info"), g_ChannelName[i]);
			}
		}
		if(lstrcmp(m_Data[Cnt].influence,TEXT(""))) 
		{
			TCHAR isKill[10];
			lstrcpy(isKill, m_Data[Cnt].iskill? TEXT(" Kill"):TEXT(" Dead"));
			TCHAR* PKInfo = new TCHAR[lstrlen(m_Data[Cnt].influence) + lstrlen(isKill) + 1];
			lstrcpy(PKInfo,m_Data[Cnt].influence);
			lstrcat(PKInfo,isKill);
			lstrcpy(m_Data[Cnt].p1,PKInfo);

			for (int i = 0 ; i < FIVEROCKS_CUSTOM_VALUES_COUNT ; i++)
			{
				if(!lstrcmp(m_Data[Cnt].key[i],TEXT("")) &&
					!lstrcmp(isKill,TEXT(" Kill")))
				{
					lstrcpy(m_Data[Cnt].key[i],PKInfo);
					m_Data[Cnt].values[i] = 1;
					break;
				}
			}

			delete[] PKInfo;
			PKInfo = NULL;
		}
		if(lstrcmp(m_Data[Cnt].geartype,TEXT(""))) lstrcpy(m_Data[Cnt].p2,m_Data[Cnt].geartype);
		break;
	}

	if(lstrcmp(m_Data[Cnt].type,TEXT("")))
	{
		wsprintf(TempData,TEXT("&type=%s"),m_Data[Cnt].type);
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
	if(lstrcmp(m_Data[Cnt].category,TEXT("")))
	{
		wsprintf(TempData,TEXT("&category=%s"),m_Data[Cnt].category);
		lstrcat(PostData,TempData);
	}
	if(lstrcmp(m_Data[Cnt].name,TEXT("")))
	{
		wsprintf(TempData,TEXT("&name=%s"),m_Data[Cnt].name);
		lstrcat(PostData,TempData);
	}
	if(lstrcmp(m_Data[Cnt].p1,TEXT("")))
	{
		wsprintf(TempData,TEXT("&p1=%s"),m_Data[Cnt].p1);
		lstrcat(PostData,TempData);
	}
	if(lstrcmp(m_Data[Cnt].p2,TEXT("")))
	{
		wsprintf(TempData,TEXT("&p2=%s"),m_Data[Cnt].p2);
		lstrcat(PostData,TempData);
	}
	for (int i = 0 ; i < FIVEROCKS_CUSTOM_VALUES_COUNT ; i++)
	{
		if (lstrcmp(m_Data[Cnt].key[i],TEXT("")))
		{
			wsprintf(TempData,TEXT("&values[%s]=%d"),m_Data[Cnt].key[i], m_Data[Cnt].values[i]);
			lstrcat(PostData,TempData);
		}
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

	int PostLen = WideCharToMultiByte(CP_UTF8,0,PostData, -1,PostDataUTF8, 0,0,0);
	WideCharToMultiByte(CP_UTF8,0,PostData,lstrlen(PostData) + sizeof(TCHAR),PostDataUTF8, PostLen + sizeof(TCHAR),0,0);
	UINT32 PostResult = PostHttp(TEXT("Custom::Processing()"),PostDataUTF8);
	if(PostResult) return PostResult;
	
	return NULL;
}
UINT32 FiveRocksDataCustom::ProcessingAllData()
{
	if (m_CustomType != CUSTOMTYPE_CCU_MIN &&
		m_CustomType != CUSTOMTYPE_CCU_HOUR &&
		m_CustomType != CUSTOMTYPE_CCU_DAY)
	{
		return FIVEROCKS_DB_RECORD_NO_DELETE;
	}

	TCHAR PostData[FIVEROCKS_MAX_DATA_LENGTH] = {0};
	char PostDataUTF8[FIVEROCKS_MAX_DATA_LENGTH] = {0};

	TCHAR TempData[FIVEROCKS_MAX_DATA_LENGTH] = {0};

	wsprintf(TempData,TEXT("&type=%s"),TEXT("custom"));
	lstrcat(PostData,TempData);

	if(lstrcmp(m_CustomName,TEXT("")))
	{
		wsprintf(TempData,TEXT("&name=%s"),m_CustomName);
		lstrcat(PostData,TempData);
	}
	wsprintf(TempData,TEXT("&api_key=%s"),TEXT(TAPJOY_HTTP_APIKEY));
	lstrcat(PostData,TempData);

	wsprintf(TempData,TEXT("&user_id=%s"),TEXT("tapjoy_ccu"));
	lstrcat(PostData,TempData);

	if(lstrcmp(m_CustomCategory,TEXT("")))
	{
		wsprintf(TempData,TEXT("&category=%s"),m_CustomCategory);
		lstrcat(PostData,TempData);
	}
	for (std::map<const TCHAR*,INT64>::iterator iter = m_ccuChanneling.begin() ; 
		iter != m_ccuChanneling.end() ; iter++)
	{
		wsprintf(TempData,TEXT("&values[%s]=%d"), iter->first, iter->second);
		lstrcat(PostData,TempData);
	}
	int PostLen = WideCharToMultiByte(CP_UTF8,0,PostData, -1,PostDataUTF8, 0,0,0);
	WideCharToMultiByte(CP_UTF8,0,PostData,lstrlen(PostData) + sizeof(TCHAR),PostDataUTF8, PostLen + sizeof(TCHAR),0,0);
	PostHttp(TEXT("Custom::ProcessingAllData()"), PostDataUTF8);
	g_LogFile->WriteSystemLog(L"Send = ",true);
	g_LogFile->WriteSystemLog(PostData,false);
	g_LogFile->WriteSystemLog(L"\r\n",false);

	TCHAR CCUData[FIVEROCKS_MAX_DATA_LENGTH] = {0,};
	switch (m_CustomType)
	{
	case CUSTOMTYPE_CCU_MIN:
		lstrcpy(CCUData,TEXT("time_type=min;"));
		for (std::map<const TCHAR*,INT64>::iterator iter = m_ccuChanneling.begin() ; 
			iter != m_ccuChanneling.end() ; iter++)
		{
			TCHAR ccuKeyValue[FIVEROCKS_MAX_DATA_LENGTH] = {0,};
			for (int i = 0 ; i < g_nMax_Count_Channeling ; i++)
			{
				if (!lstrcmp(iter->first,g_ChannelingName[i]))
				{
					wsprintf(ccuKeyValue,TEXT("ccu[%s]=%d;"), g_DbChannelingName[i], iter->second);
					lstrcat(CCUData,ccuKeyValue);
				}
			}
			if (!lstrcmp(iter->first,TEXT(CCU_CHNNELING_ALL_NAME)))
			{
				wsprintf(ccuKeyValue,TEXT("ccu[%s]=%d;"),TEXT("ALL"),iter->second);
				lstrcat(CCUData,ccuKeyValue);
			}
		}
		DBCcuInsert(CCUData);
		break;
	case CUSTOMTYPE_CCU_HOUR:
		lstrcpy(CCUData,TEXT("time_type=hour;"));
		for (std::map<const TCHAR*,INT64>::iterator iter = m_ccuChanneling.begin() ; 
			iter != m_ccuChanneling.end() ; iter++)
		{
			TCHAR ccuKeyValue[FIVEROCKS_MAX_DATA_LENGTH] = {0,};
			for (int i = 0 ; i < g_nMax_Count_Channeling ; i++)
			{
				if (!lstrcmp(iter->first,g_ChannelingName[i]))
				{
					wsprintf(ccuKeyValue,TEXT("ccu[%s]=%d;"), g_DbChannelingName[i], iter->second);
					lstrcat(CCUData,ccuKeyValue);
				}
			}
			if (!lstrcmp(iter->first,TEXT(CCU_CHNNELING_ALL_NAME)))
			{
				wsprintf(ccuKeyValue,TEXT("ccu[%s]=%d;"),TEXT("ALL"),iter->second);
				lstrcat(CCUData,ccuKeyValue);
			}
		}
		DBCcuInsert(CCUData);
		break;
	}
	for (int i = 0 ; i < g_nMax_Count_Channeling ; i++)
	{
		m_ccuChanneling[g_ChannelingName[i]] = 0;
	}
	m_ccuChanneling[TEXT(CCU_CHNNELING_ALL_NAME)] = 0;

	return FIVEROCKS_DB_RECORD_NO_DELETE;
}
UINT32 FiveRocksDataCustom::ParsingData(int Cnt, TCHAR* LeftData, TCHAR* RightData)
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
		for (int i = 0 ; i < g_nMax_Count_Db ; i++)
		{
			if(!lstrcmp(RightData,g_DbName[i]))
			{
				lstrcpy(m_Data[Cnt].channel,g_ChannelName[i]);
			}
		}
	}
	else if (!lstrcmp(LeftData,TEXT("channeling")))
	{
		for (int i = 0 ; i < g_nMax_Count_DbChanneling ; i++)
		{
			if (!lstrcmp(RightData,g_DbChannelingName[i]))
			{
				lstrcpy(m_Data[Cnt].channeling,g_ChannelingName[i]);
				lstrcpy(m_Data[Cnt].referrer,TEXT(REFERR_NAME));
				break;
			}
		}
	}
	else if (!lstrcmp(LeftData,TEXT("influence")))
	{
		if(!lstrcmp(RightData,TEXT("ANI")))
		{
			lstrcpy(m_Data[Cnt].influence,TEXT("Arlington"));
		}
		else if (!lstrcmp(RightData,TEXT("BCU")))
		{
			lstrcpy(m_Data[Cnt].influence,TEXT("Bygeniou"));
		}
		else if(!lstrcmp(RightData,TEXT("NORMAL")))
		{
			lstrcpy(m_Data[Cnt].influence,TEXT("Normal"));
		}
	}
	else if (!lstrcmp(LeftData,TEXT("geartype")))
	{
		lstrcpy(m_Data[Cnt].geartype,RightData);
	}
	else if (!lstrcmp(LeftData,TEXT("time_type")))
	{
		lstrcpy(m_Data[Cnt].time_type,RightData);
	}
	else if (!StrNCmp(LeftData,TEXT("ccu["),lstrlen(TEXT("ccu["))))
	{
		TCHAR* TempLeftData = &LeftData[lstrlen(TEXT("ccu["))];

		for (int i = 0 ; i < g_nMax_Count_DbChanneling ; i++)
		{
			if (!StrNCmp(TempLeftData,g_DbChannelingName[i],lstrlen(TempLeftData) - 1))
			{
				m_Data[Cnt].ccu[i] = _wtoi64(RightData);
				break;
			}
		}
		if (!StrNCmp(TempLeftData,TEXT("ALL"),lstrlen(TempLeftData) - 1))
		{
			m_Data[Cnt].ccuall = _wtoi64(RightData);
		}
	}

	else if (!lstrcmp(LeftData,TEXT("iskill")))
	{
		BOOL iskill = _wtoi(RightData);
		m_Data[Cnt].iskill = iskill;
	}

	return NULL;
}
UINT32 FiveRocksDataCustom::DBCcuInsert(TCHAR* Data)
{
	try
	{
		// 프로시저 설정
		m_pSourceCommand->CommandText = DB_ATUM_FIVEROCKS_INSERT;

		// 프로시저에 들어갈 인자값 설정
		m_pSourceCommand->Parameters->Append(m_pSourceCommand->CreateParameter(_bstr_t("i_AccountUID"),adInteger,adParamInput,4,_variant_t(0)));
		m_pSourceCommand->Parameters->Append(m_pSourceCommand->CreateParameter(_bstr_t("i_Datatype"),adTinyInt,adParamInput,1,_variant_t(FIVEROCKS_DATA_TYPE_CCU)));
		VARIANT vData;
		vData.vt = VT_BSTR;
		vData.bstrVal = _bstr_t(Data); 
		m_pSourceCommand->Parameters->Append(m_pSourceCommand->CreateParameter(_bstr_t("i_Data"),adVarChar,adParamInput,FIVEROCKS_MAX_DATA_LENGTH,vData));
		m_pSourceCommand->Parameters->Append(m_pSourceCommand->CreateParameter(_bstr_t("i_Flag"),adTinyInt,adParamInput,1,_variant_t(1)));
		// 프로시저 실행
		m_pSourceCommand->Execute(NULL,NULL,adCmdStoredProc);

		// 인자값 초기화
		m_pSourceCommand->Parameters->Delete(_bstr_t("i_AccountUID"));
		m_pSourceCommand->Parameters->Delete(_bstr_t("i_Datatype"));		
		m_pSourceCommand->Parameters->Delete(_bstr_t("i_Data"));
		m_pSourceCommand->Parameters->Delete(_bstr_t("i_Flag"));
	}
	catch(_com_error& e)
	{
		// 인자값 초기화
		m_pSourceCommand->Parameters->Delete(_bstr_t("AccountUID"));
		m_pSourceCommand->Parameters->Delete(_bstr_t("Datatype"));		
		m_pSourceCommand->Parameters->Delete(_bstr_t("Data"));
		m_pSourceCommand->Parameters->Delete(_bstr_t("Flag"));
		return ErrorLog(L"CCU_Insert",e);
	}
	return NULL;
}