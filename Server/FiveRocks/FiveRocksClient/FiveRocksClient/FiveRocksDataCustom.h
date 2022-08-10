#pragma once

#include "FiveRocksDataBase.h"
#include <map>

class FiveRocksDataCustom : public FiveRocksDataBase
{
public:
	FiveRocksDataCustom(void);
	virtual ~FiveRocksDataCustom(void);

	CustomData m_Data[FIVEROCKS_MAX_DB_SELECT_COUNT];

	virtual UINT32 Init(FIVEROCKS_DATA_TYPE DataType);
	virtual UINT32 Processing(int Cnt);		// FIVEROCKS_DB_RECORD_NO_DELETE 리턴시 레코드 삭제 안함
	virtual UINT32 ProcessingAllData();

	virtual UINT32 ParsingData(int Cnt, TCHAR* LeftData, TCHAR* RightData);

public:
	CUSTOMTYPE m_CustomType;

	TCHAR m_CustomName[SIZE_MAX_FIVEROCKS_NAME];
	TCHAR m_CustomCategory[SIZE_MAX_FIVEROCKS_CATEGORY];

	virtual void SetCustomType(CUSTOMTYPE CustomType) {m_CustomType = CustomType;}
	virtual void SetCustomName(TCHAR* name) {lstrcpy(m_CustomName,name);}
	virtual void SetCustomCategory(TCHAR* category) {lstrcpy(m_CustomCategory,category);}

public:
	std::map<const TCHAR*,INT64>	m_ccuChanneling;

	virtual UINT32 DBCcuInsert(TCHAR* Data);
};

