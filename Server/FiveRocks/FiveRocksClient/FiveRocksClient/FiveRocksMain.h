#pragma once
#include "FiveRocksDefine.h"
#include "FiveRocksDataActiveUser.h"
#include "FiveRocksDataMonetization.h"
#include "FiveRocksDataCustom.h"
#include "FiveRocksDB.h"
#include "Config.h"
#include "XOR_Lib.h"

class FiveRocksMain
{
public:
	FiveRocksMain(void);
	~FiveRocksMain(void);
public:
	CString m_strConfigRoot;

	CString	m_strSourceDBID;
	CString m_strSourceDBPW;
	CString m_strSourceDBIP;
	CString m_strSourceDBPort;

	FiveRocksDB*			m_SourceDB;

	time_t m_ActiveUserUpdateTime;
	int m_ActiveUserSegmentTime;
	int m_ActiveUserCheckTime;
	FiveRocksDataActiveUser* m_ActiveUser;

	time_t m_MonetizationUpdateTime;
	int m_MonetizationSegmentTime;
	int m_MonetizationCheckTime;
	FiveRocksDataMonetization* m_Monetization;

	time_t m_CustomUpdateTime[CUSTOMTYPE_END];
	int m_CustomSegmentTime[CUSTOMTYPE_END];
	int m_CustomCheckTime[CUSTOMTYPE_END];
	FiveRocksDataCustom*		m_Custom;

	HANDLE	m_hMutexMonoInstance;

public:
	bool Init();
	bool Run();
	bool Release();

	bool SourceDBCnn();
	void SourceDBDisCnn();

	void SourceDBDeleteOption(FIVEROCKS_DATA_TYPE DataType);

	bool GetConfigFile();
	void SetConfigRootPath();
};

