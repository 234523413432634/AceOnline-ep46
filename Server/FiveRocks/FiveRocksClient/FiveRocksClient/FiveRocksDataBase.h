#pragma once

#include "FiveRocksDefine.h"

#define FIVEROCKS_DB_RECORD_NO_DELETE	(UINT32) 0x0000000F

class FiveRocksDataBase
{
public:
	FiveRocksDataBase(void);
	virtual ~FiveRocksDataBase(void);

	// table 관련 변수
	FiveRocksTBData		m_TBData[FIVEROCKS_MAX_DB_SELECT_COUNT];
	int					m_TBSelectCnt;
	FIVEROCKS_DATA_TYPE	m_TBDataType;

	_RecordsetPtr 	m_pSourceRecordSet;
	_CommandPtr		m_pSourceCommand;

	virtual UINT32 Init(FIVEROCKS_DATA_TYPE DataType) = 0;
	virtual UINT32 Processing(int Cnt) = 0;		// FIVEROCKS_DB_RECORD_NO_DELETE 리턴시 레코드 삭제 안함
	virtual UINT32 ProcessingAllData();

	virtual UINT32 InitDB(_RecordsetPtr i_pSourceRecordSet,_CommandPtr i_pSourceCommand);
	virtual	UINT32 SelectProc();
	virtual UINT32 Run();

	virtual UINT32 Parsing(int Cnt);
	virtual UINT32 ParsingData(int Cnt, TCHAR* LeftData, TCHAR* RightData) = 0;

protected:
	virtual UINT32	DBSelect(int* pSelectCnt);
	virtual UINT32	DBDelete(int nCnt);

	virtual UINT32	ResetData();

	UINT32 ErrorLog(TCHAR * pTableName, _com_error e);
	UINT32 ErrorProcessing(UINT32 i_Err);

	virtual UINT32 PostHttp(TCHAR* Pos, char* PostData);
};

