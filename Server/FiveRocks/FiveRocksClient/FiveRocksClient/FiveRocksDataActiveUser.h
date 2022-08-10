#pragma once

#include "FiveRocksDataBase.h"

class FiveRocksDataActiveUser : public FiveRocksDataBase
{
public:
	FiveRocksDataActiveUser(void);
	virtual ~FiveRocksDataActiveUser(void);

	ActiveUserData m_Data[FIVEROCKS_MAX_DB_SELECT_COUNT];

	virtual UINT32 Init(FIVEROCKS_DATA_TYPE DataType);
	virtual UINT32 Processing(int Cnt);		// FIVEROCKS_DB_RECORD_NO_DELETE ���Ͻ� ���ڵ� ���� ����

	virtual UINT32 ParsingData(int Cnt, TCHAR* LeftData, TCHAR* RightData);
};

