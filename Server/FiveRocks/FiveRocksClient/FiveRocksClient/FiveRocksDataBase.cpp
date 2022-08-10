#include "FiveRocksDataBase.h"


FiveRocksDataBase::FiveRocksDataBase(void)
{
	m_TBSelectCnt = NULL;
}

FiveRocksDataBase::~FiveRocksDataBase(void)
{
}

UINT32 FiveRocksDataBase::InitDB(_RecordsetPtr i_pSourceRecordSet,_CommandPtr i_pSourceCommand)
{
	this->m_pSourceRecordSet	= i_pSourceRecordSet;
	this->m_pSourceCommand		= i_pSourceCommand;
	return NULL;
}

UINT32 FiveRocksDataBase::ResetData()
{
	for (int i = 0 ; i < FIVEROCKS_MAX_DB_SELECT_COUNT ; i++)
	{
		m_TBData[i].Reset();
	}

	return NULL;
}
UINT32 FiveRocksDataBase::SelectProc()
{
	m_TBSelectCnt = 0;
	UINT32 Err = this->DBSelect(&m_TBSelectCnt);
	if(NULL != Err)
	{
		return this->ErrorProcessing(Err);
	}
	return NULL;
}
UINT32 FiveRocksDataBase::Run()
{
	UINT32 Err = NULL;
	for(int Cnt = 0 ; Cnt < m_TBSelectCnt; Cnt++)
	{
		Err = this->Processing(Cnt);
		if (NULL != Err)
		{
			if (Err == FIVEROCKS_DB_RECORD_NO_DELETE)
			{
				continue;
			}
			return this->ErrorProcessing(Err);
		}
		Err = this->DBDelete(Cnt);
		if(NULL != Err)
		{
			return this->ErrorProcessing(Err);
		}
	}

	Err = ProcessingAllData();
	if (Err == NULL)
	{
		for(int Cnt = 0 ; Cnt < m_TBSelectCnt; Cnt++)
		{
			Err = this->DBDelete(Cnt);
			if(NULL != Err)
			{
				return this->ErrorProcessing(Err);
			}
		}
	}
	else if (Err != FIVEROCKS_DB_RECORD_NO_DELETE)
	{
		return this->ErrorProcessing(Err);
	}

	this->ResetData();
	return NULL;
}
UINT32 FiveRocksDataBase::ProcessingAllData()
{
	return FIVEROCKS_DB_RECORD_NO_DELETE;
}

UINT32 FiveRocksDataBase::Parsing(int Cnt)
{
	TCHAR Data[FIVEROCKS_MAX_DATA_LENGTH];
	TCHAR* NextData;
	int nDataMaxLength = 0;

	lstrcpy(Data, m_TBData[Cnt].Data);
	nDataMaxLength = lstrlen(Data);

	NextData = Data;

	while(lstrlen(NextData) > 0)
	{
		TCHAR* NowData = NULL;
		NowData = _tcstok_s(NextData,TEXT(";"),&NextData);
		int DataLen = lstrlen(NowData);
		if (DataLen != 0)
		{
			TCHAR* LeftData = NULL;
			TCHAR Check[] = TEXT("="); 
			TCHAR* RightData = NULL;

			LeftData = _tcstok_s(NowData,Check,&RightData);

			ParsingData(Cnt, LeftData, RightData);
		}
	}
	return NULL;
}
UINT32 FiveRocksDataBase::DBSelect(int * pSelectCnt)
{
	m_pSourceCommand->CommandText = DB_ATUM_FIVEROCKS_SELECT;
	try
	{
		m_pSourceCommand->Parameters->Append(m_pSourceCommand->CreateParameter(_bstr_t("i_Datatype"),adUnsignedTinyInt,adParamInput,1,_variant_t(m_TBDataType)));
		m_pSourceRecordSet = m_pSourceCommand->Execute(NULL,NULL,adCmdStoredProc);
		m_pSourceCommand->Parameters->Delete(_bstr_t("i_Datatype"));
	}
	catch(_com_error& e)
	{
		return ErrorLog(L"DBSelect",e);
	}
	if(m_pSourceRecordSet->EndOfFile)     
	{
		m_pSourceRecordSet->Close();   // 레코드셋을 닫는다.(항상 레코드셋 오픈 후엔 닫아주는 작업을 수행해야 합니다.)
		return ERR_DB_NO_DATA;
	}   

	int				nCnt = 0;
	FiveRocksTBData	tmpData;
	// 조회된 레코드의 끝까지 루핑을 돌며 데이터를 확인합니다.
	while(!m_pSourceRecordSet->EndOfFile)
	{
		tmpData.UID			= m_pSourceRecordSet->Fields->GetItem("UID")->GetValue();
		tmpData.DataType	= m_pSourceRecordSet->Fields->GetItem("DataType")->GetValue();
		tmpData.UserSerial	= m_pSourceRecordSet->Fields->GetItem("AccountUID")->GetValue();
		LSTRNCPY_OLEDB(tmpData.Data,m_pSourceRecordSet->Fields->GetItem("Data")->GetValue());
		tmpData.Flag		= m_pSourceRecordSet->Fields->GetItem("Flag")->GetValue();

		memcpy(&m_TBData[nCnt],&tmpData,sizeof(FiveRocksTBData));
		tmpData.Reset();
		// 리스트 컨트롤을 추가하셨거나 화면에 출력하실 생각이 있으시다면 
		// 루핑을 돌리며 값을 채워넣는 작업을 이부분에서 하시면 됩니다.
		m_pSourceRecordSet->MoveNext();    // 레코드셋을 다음으로 이동시킵니다.
		nCnt++;
	}
	*pSelectCnt = nCnt;
	m_pSourceRecordSet->Close();           // 레코드셋을 닫아줍니다.
	return NULL;
}

UINT32 FiveRocksDataBase::DBDelete(int nCnt)
{
	try
	{
		// 프로시저 설정
		m_pSourceCommand->CommandText = DB_ATUM_FIVEROCKS_DELETE;

		// 프로시저에 들어갈 인자값 설정
		m_pSourceCommand->Parameters->Append(m_pSourceCommand->CreateParameter(_bstr_t("i_UID"),adInteger,adParamInput,4,_variant_t(m_TBData[nCnt].UID)));

		// 프로시저 실행
		m_pSourceCommand->Execute(NULL,NULL,adCmdStoredProc);
		// 인자값 초기화
		m_pSourceCommand->Parameters->Delete(_bstr_t("i_UID"));
	}
	catch(_com_error& e)
	{
		return ErrorLog(L"DBDelete",e);
	}
	return NULL;
}

UINT32 FiveRocksDataBase::ErrorLog(TCHAR * pTableName, _com_error e)
{
	// Print COM errors.
	_bstr_t bstrSource(e.Source());
	_bstr_t bstrDescription(e.Description());
	TCHAR	szError[1024];
	wsprintf(szError, L"[ERROR] %s _com_error !!! Error = %08lx, Message = %s , Source = %s, Description =%s \r\n"
		, pTableName, e.Error(), e.ErrorMessage(), (LPCWSTR)bstrSource, (LPCWSTR)bstrDescription);
	g_LogFile->WriteSystemLog(szError, TRUE);

	return e.Error();
}

UINT32 FiveRocksDataBase::ErrorProcessing(UINT32 i_Err)
{
	switch(i_Err)
	{
	case ERR_DB_COM_CONNECT_FAIL:
	case ERR_DB_NO_DATA:
		{
			this->ResetData();
		}
		break;
	case ERR_DB_COM_PROCEDURE:
		{
			MessageBox(NULL,L"Error Procedure!! Plz, Call MasangSoft!!",L"Error",MB_OK);
			PostQuitMessage(0);
		}
		break;
	}
	return i_Err;
}
UINT32 FiveRocksDataBase::PostHttp(TCHAR* Pos, char* PostData)
{
	if(g_InternetHttp)
	{
		TCHAR ErrMessage[1024];
		DWORD ErrCode = NULL;
		if(ErrCode = g_InternetHttp->ConnectHttp())
		{
			wsprintf(ErrMessage,TEXT("[ERROR] %s ConnectHttp() Failed Code=Error=%08lx\r\n"), Pos, ErrCode);
			g_LogFile->WriteSystemLog(ErrMessage);
			return (UINT32)ErrCode;
		}
		else if(ErrCode = g_InternetHttp->OpenRequestHttp())
		{
			wsprintf(ErrMessage,TEXT("[ERROR] %s OpenRequestHttp() Failed Code=%08lx\r\n"), Pos, ErrCode);
			g_LogFile->WriteSystemLog(ErrMessage);
			return (UINT32)ErrCode;
		}
		ErrCode = g_InternetHttp->SendHttp(PostData);
		if(ErrCode != NO_ERROR)
		{
			wsprintf(ErrMessage,TEXT("[ERROR] %s SendHttp() Failed Code=%08lx\r\n"), Pos, ErrCode);
			g_LogFile->WriteSystemLog(ErrMessage);
			return (UINT32)ErrCode;
		}
		else
		{
			char* ServerMessage = g_InternetHttp->GetServerResult();
			if (strcmp(ServerMessage, "Created\r\n") != 0) // "Created" 메세지가 아니라면
			{
				TCHAR ServerMessageUnicode[INTERNET_HTTP_MESSAGE_MAX_LENGTH];
				TCHAR SendMessageUnicode[FIVEROCKS_MAX_DATA_LENGTH];
				TCHAR ServerLogMessage[1024];
				MultiByteToWideChar(CP_UTF8,0,ServerMessage,strlen(ServerMessage) + 1,ServerMessageUnicode,strlen(ServerMessage) + 1);
				MultiByteToWideChar(CP_UTF8,0,PostData,strlen(PostData) + 1,SendMessageUnicode,strlen(PostData) + 1);
				wsprintf(ServerLogMessage,TEXT("[ERROR] %s SendHttp() ServerMessage=%s SendMessage=%s"), Pos, ServerMessageUnicode,SendMessageUnicode);
				g_LogFile->WriteSystemLog(ServerLogMessage);
			}
			g_InternetHttp->deleteServerResult();
		}
	}
	return NULL;
}