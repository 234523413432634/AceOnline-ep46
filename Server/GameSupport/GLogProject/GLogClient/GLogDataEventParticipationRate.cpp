#include "StdAfx.h"
#include "GLogDataEventParticipationRate.h"

CGLogDataEventParticipationRate::CGLogDataEventParticipationRate(_RecordsetPtr i_pSourceRecordSet,_CommandPtr i_pSourceCommand,_RecordsetPtr i_pDestRecordSet,_CommandPtr i_pDestCommand)
{
	this->Init(i_pSourceRecordSet,i_pSourceCommand,i_pDestRecordSet,i_pDestCommand);
}

CGLogDataEventParticipationRate::~CGLogDataEventParticipationRate(void)
{
}

void CGLogDataEventParticipationRate::ResetData()
{
	MEMSET_ZERO(m_arrEventParticipationRateData,sizeof(CEventParticipationRateData)*GLOG_DATA_MAX_CNT);
}

Err_t CGLogDataEventParticipationRate::GLogProcessing()
{
	int SelectCnt = 0;
	Err_t Err =	this->GLogDBSelect(&SelectCnt);
	if(ERR_NO_ERROR != Err)
	{
		return this->ErrorProcessing(Err);
	}
	g_pLogGlobal->m_pGlobalLogManager->WriteSystemLog(L"============== GLog EventParticipationRate Select Fin!!! ==============\r\n",TRUE);

	//Insert & Delete는 한행씩 처리.
	for(int Cnt = 0 ; Cnt < SelectCnt; Cnt++)
	{
		Err = this->GLogDBInsert(Cnt);
		if(ERR_NO_ERROR != Err
			&& ERR_DB_COM_DUPLICATE_INSERT != Err)
		{
			return this->ErrorProcessing(Err);
		}

		Err = this->GLogDBDelete(Cnt);
		if(ERR_NO_ERROR != Err)
		{
			return this->ErrorProcessing(Err);
		}
	}
	g_pLogGlobal->m_pGlobalLogManager->WriteSystemLog(L"============== GLog EventParticipationRate Update Fin!!! ==============\r\n",TRUE);
	this->ResetData();

	return ERR_NO_ERROR;
}

Err_t CGLogDataEventParticipationRate::GLogDBSelect(int * o_pSelectCnt)
{
	m_pSourceCommand->CommandText = QDB_GLOG_EVENT_PARTICIPATION_RATE_SELECT;
	try
	{
		m_pSourceRecordSet = m_pSourceCommand->Execute(NULL,NULL,adCmdStoredProc);  // 저장된 select문을 수행합니다.
	}
	catch(_com_error& e)
	{
		return ErrorLog(L"CGLogDataEventParticipationRate",e);
	}

	if(m_pSourceRecordSet->EndOfFile)     
	{
		m_pSourceRecordSet->Close();   // 레코드셋을 닫는다.(항상 레코드셋 오픈 후엔 닫아주는 작업을 수행해야 합니다.)
		return ERR_DB_NO_DATA;
	}   

	int				nCnt = 0;
	CEventParticipationRateData	tmpEventParticipationRateData;
	// 조회된 레코드의 끝까지 루핑을 돌며 데이터를 확인합니다.
	while(!m_pSourceRecordSet->EndOfFile)
	{
		tmpEventParticipationRateData.UID	= m_pSourceRecordSet->Fields->GetItem("UID")->GetValue();	// 해당 필드를 선언한 variant변수에 저장합니다.
		LSTRNCPY_OLEDB(tmpEventParticipationRateData.GamePublisher,m_pSourceRecordSet->Fields->GetItem("GamePublisher")->GetValue());
		LSTRNCPY_OLEDB(tmpEventParticipationRateData.GameName,m_pSourceRecordSet->Fields->GetItem("GameName")->GetValue());
		LSTRNCPY_OLEDB(tmpEventParticipationRateData.GameServerName,m_pSourceRecordSet->Fields->GetItem("GameServerName")->GetValue());
		tmpEventParticipationRateData.StartDate = m_pSourceRecordSet->Fields->GetItem("StartDate")->GetValue();
		tmpEventParticipationRateData.EndDate = m_pSourceRecordSet->Fields->GetItem("EndDate")->GetValue();
		tmpEventParticipationRateData.ParticipationCount = m_pSourceRecordSet->Fields->GetItem("ParticipationCount")->GetValue();
		tmpEventParticipationRateData.ParticipationRate = m_pSourceRecordSet->Fields->GetItem("ParticipationRate")->GetValue();
		LSTRNCPY_OLEDB(tmpEventParticipationRateData.Description,m_pSourceRecordSet->Fields->GetItem("Description")->GetValue());
		memcpy(&m_arrEventParticipationRateData[nCnt],&tmpEventParticipationRateData,sizeof(CEventParticipationRateData));
		MEMSET_ZERO(&tmpEventParticipationRateData,sizeof(CEventParticipationRateData));
		// 리스트 컨트롤을 추가하셨거나 화면에 출력하실 생각이 있으시다면 
		// 루핑을 돌리며 값을 채워넣는 작업을 이부분에서 하시면 됩니다.
		m_pSourceRecordSet->MoveNext();    // 레코드셋을 다음으로 이동시킵니다.
		nCnt++;
	}

	*o_pSelectCnt = nCnt;
	m_pSourceRecordSet->Close();           // 레코드셋을 닫아줍니다.
	return ERR_NO_ERROR;
}

Err_t CGLogDataEventParticipationRate::GLogDBInsert(int i_nCnt)
{
	try
	{
		// 프로시저 설정
		m_pDestCommand->CommandText = QDB_GLOG_EVENT_PARTICIPATION_RATE_INSERT;

		// 프로시저에 들어갈 인자값 설정
		this->DBInsertParametersAppend(i_nCnt);

		// 프로시저 실행
		m_pDestCommand->Execute(NULL,NULL,adCmdStoredProc);
		
		// 인자값 초기화
		this->DBInsertParametersDelete();
	}
	catch(_com_error& e)
	{
		// 인자값 초기화
		this->DBInsertParametersDelete();
		return ErrorLog(L"CGLogDataEventParticipationRate",e);
	}
	return ERR_NO_ERROR;
}

Err_t CGLogDataEventParticipationRate::GLogDBDelete(int i_nCnt)
{
	try
	{
		// 프로시저 설정
		m_pSourceCommand->CommandText = QDB_GLOG_EVENT_PARTICIPATION_RATE_DELETE;

		// 프로시저에 들어갈 인자값 설정
		m_pSourceCommand->Parameters->Append(m_pSourceCommand->CreateParameter(_bstr_t("UID"),adBigInt,adParamInput,8,_variant_t(m_arrEventParticipationRateData[i_nCnt].UID)));

		// 프로시저 실행
		m_pSourceCommand->Execute(NULL,NULL,adCmdStoredProc);
		// 인자값 초기화
		m_pSourceCommand->Parameters->Delete(_bstr_t("UID"));
	}
	catch(_com_error& e)
	{
		return ErrorLog(L"CGLogDataEventParticipationRate",e);
	}
	return ERR_NO_ERROR;
}

void CGLogDataEventParticipationRate::DBInsertParametersAppend(int i_nCnt)
{
	VARIANT vGamePublisher;
	vGamePublisher.vt = VT_BSTR;
	vGamePublisher.bstrVal = _bstr_t(m_arrEventParticipationRateData[i_nCnt].GamePublisher); 
	m_pDestCommand->Parameters->Append(m_pDestCommand->CreateParameter(_bstr_t("GamePublisher"),adWChar,adParamInput,SIZE_MAX_GAME_PUBLISHER_NAME+1,vGamePublisher));
	VARIANT vGameName;
	vGameName.vt = VT_BSTR;
	vGameName.bstrVal = _bstr_t(m_arrEventParticipationRateData[i_nCnt].GameName); 
	m_pDestCommand->Parameters->Append(m_pDestCommand->CreateParameter(_bstr_t("GameName"),adWChar,adParamInput,SIZE_MAX_GAME_NAME+1,vGameName));
	VARIANT vGameServerName;
	vGameServerName.vt = VT_BSTR;
	vGameServerName.bstrVal = _bstr_t(m_arrEventParticipationRateData[i_nCnt].GameServerName); 
	m_pDestCommand->Parameters->Append(m_pDestCommand->CreateParameter(_bstr_t("GameServerName"),adWChar,adParamInput,SIZE_MAX_GAME_SERVER_NAME+1,vGameServerName));
	m_pDestCommand->Parameters->Append(m_pDestCommand->CreateParameter(_bstr_t("StartDate"),adDate,adParamInput,8,_variant_t(m_arrEventParticipationRateData[i_nCnt].StartDate)));
	m_pDestCommand->Parameters->Append(m_pDestCommand->CreateParameter(_bstr_t("EndDate"),adDate,adParamInput,8,_variant_t(m_arrEventParticipationRateData[i_nCnt].EndDate)));
	m_pDestCommand->Parameters->Append(m_pDestCommand->CreateParameter(_bstr_t("ParticipationCount"),adInteger,adParamInput,0,_variant_t(m_arrEventParticipationRateData[i_nCnt].ParticipationCount)));
	m_pDestCommand->Parameters->Append(m_pDestCommand->CreateParameter(_bstr_t("ParticipationRate"),adSmallInt,adParamInput,0,_variant_t(m_arrEventParticipationRateData[i_nCnt].ParticipationRate)));
	VARIANT vDescription;
	vDescription.vt = VT_BSTR;
	vDescription.bstrVal = _bstr_t(m_arrEventParticipationRateData[i_nCnt].Description); 
	m_pDestCommand->Parameters->Append(m_pDestCommand->CreateParameter(_bstr_t("Description"),adWChar,adParamInput,SIZE_MAX_DESCRIPTION+1,vDescription));
}

void CGLogDataEventParticipationRate::DBInsertParametersDelete()
{
	m_pDestCommand->Parameters->Delete(_bstr_t("GamePublisher"));
	m_pDestCommand->Parameters->Delete(_bstr_t("GameName"));		
	m_pDestCommand->Parameters->Delete(_bstr_t("GameServerName"));
	m_pDestCommand->Parameters->Delete(_bstr_t("StartDate"));
	m_pDestCommand->Parameters->Delete(_bstr_t("EndDate"));
	m_pDestCommand->Parameters->Delete(_bstr_t("ParticipationCount"));
	m_pDestCommand->Parameters->Delete(_bstr_t("ParticipationRate"));
	m_pDestCommand->Parameters->Delete(_bstr_t("Description"));
}
