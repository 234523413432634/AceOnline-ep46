#pragma once

#include "FiveRocksDataBase.h"

class FiveRocksDataMonetization : public FiveRocksDataBase
{
public:
	FiveRocksDataMonetization(void);
	virtual ~FiveRocksDataMonetization(void);

	MonetizationData m_Data[FIVEROCKS_MAX_DB_SELECT_COUNT];

	virtual UINT32 Init(FIVEROCKS_DATA_TYPE DataType);
	virtual UINT32 Processing(int Cnt);		// FIVEROCKS_DB_RECORD_NO_DELETE 리턴시 레코드 삭제 안함

	virtual UINT32 ParsingData(int Cnt, TCHAR* LeftData, TCHAR* RightData);
};

