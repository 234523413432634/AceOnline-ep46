#include <time.h>
#include "FiveRocksMain.h"


FiveRocksMain::FiveRocksMain(void)
{
	m_SourceDB = NULL;

	m_ActiveUser = NULL;
	m_Monetization = NULL;
	m_Custom = NULL;

	m_hMutexMonoInstance = NULL;
}


FiveRocksMain::~FiveRocksMain(void)
{
}
bool FiveRocksMain::Init()
{
	g_LogFile = new LogFile;
	g_LogFile->OpenLogFile(TEXT(LOGFILE_FILENAME),TEXT(LOGFILE_DIRECTORY));

	m_SourceDB = new FiveRocksDB;
	m_SourceDB->Init();

	SetConfigRootPath();
	if( GetConfigFile() == false || NULL != m_hMutexMonoInstance )
	{
		return false;
	}

	g_InternetHttp = new InternetHttp;
	g_InternetHttp->Init(TEXT(TAPJOY_HTTP_URL),TEXT(TAPJOY_HTTP_APPID),TEXT(FIVEROCKS_HTTP_CONTENTTYPE));
	g_InternetHttp->OpenHttp();

	m_ActiveUserSegmentTime = ACTIVEUSER_TIME_SEGMENT;
	m_ActiveUserCheckTime = ACTIVEUSER_TIME_CHECK;

	m_MonetizationSegmentTime = MONETIZATION_TIME_SEGMENT;
	m_MonetizationCheckTime = MONETIZATION_TIME_CHECK;

	m_CustomSegmentTime[CUSTOMTYPE_CCU_MIN] = CCU_MIN_TIME_SEGMENT;
	m_CustomCheckTime[CUSTOMTYPE_CCU_MIN] = CCU_MIN_TIME_CHECK;

	m_CustomSegmentTime[CUSTOMTYPE_CCU_HOUR] = CCU_HOUR_TIME_SEGMENT;
	m_CustomCheckTime[CUSTOMTYPE_CCU_HOUR] = CCU_HOUR_TIME_CHECK;

	m_CustomSegmentTime[CUSTOMTYPE_CCU_DAY] = CCU_DAY_TIME_SEGMENT;
	m_CustomCheckTime[CUSTOMTYPE_CCU_DAY] = CCU_DAY_TIME_CHECK;

	m_CustomSegmentTime[CYSTOMTYPE_PKINFO] = DEFAULT_TIME_SEGMENT;
	m_CustomCheckTime[CYSTOMTYPE_PKINFO] = DEFAULT_TIME_CHECK;

	time_t NowTime = time(NULL) + KST_TIME;
	time_t UpdateTime;

	UpdateTime = NowTime + m_ActiveUserSegmentTime - NowTime % m_ActiveUserSegmentTime;
	UpdateTime += (NowTime % m_ActiveUserSegmentTime) >= m_ActiveUserCheckTime? m_ActiveUserCheckTime : m_ActiveUserCheckTime - m_ActiveUserSegmentTime;
	m_ActiveUserUpdateTime = UpdateTime;

	UpdateTime = NowTime + m_MonetizationSegmentTime - NowTime % m_MonetizationSegmentTime;
	UpdateTime += (NowTime % m_MonetizationSegmentTime) >= m_MonetizationCheckTime? m_MonetizationCheckTime : m_MonetizationCheckTime - m_ActiveUserSegmentTime;
	m_MonetizationUpdateTime = UpdateTime;

	for (int i = 0 ; i < CUSTOMTYPE_END ; i++)
	{
		UpdateTime = NowTime + m_CustomSegmentTime[i] - NowTime % m_CustomSegmentTime[i];
		UpdateTime += (NowTime % m_CustomSegmentTime[i]) >= m_CustomCheckTime[i]? m_CustomCheckTime[i] : m_CustomCheckTime[i] - m_CustomSegmentTime[i];
		m_CustomUpdateTime[i] = UpdateTime;
	}

	m_ActiveUser = new FiveRocksDataActiveUser;
	m_ActiveUser->Init(FIVEROCKS_DATA_TYPE_LOGIN);
	m_ActiveUser->InitDB(m_SourceDB->GetRecordsetPtr(),m_SourceDB->GetCommandPtr());

	m_Monetization = new FiveRocksDataMonetization;
	m_Monetization->Init(FIVEROCKS_DATA_TYPE_BUYITEM);
	m_Monetization->InitDB(m_SourceDB->GetRecordsetPtr(), m_SourceDB->GetCommandPtr());

	m_Custom = new FiveRocksDataCustom[CUSTOMTYPE_END];
	for (int i = 0 ; i < CUSTOMTYPE_END ; i++)
	{
		switch(i)
		{
		case CUSTOMTYPE_CCU_MIN:
			m_Custom[i].Init(FIVEROCKS_DATA_TYPE_LOGIN);
			m_Custom[i].SetCustomName(TEXT("ccu_min"));
			m_Custom[i].SetCustomCategory(TEXT("ccu"));
			break;
		case CUSTOMTYPE_CCU_HOUR:
			m_Custom[i].Init(FIVEROCKS_DATA_TYPE_CCU);
			m_Custom[i].SetCustomName(TEXT("ccu_hour"));
			m_Custom[i].SetCustomCategory(TEXT("ccu"));
			break;
		case CUSTOMTYPE_CCU_DAY:
			m_Custom[i].Init(FIVEROCKS_DATA_TYPE_CCU);
			m_Custom[i].SetCustomName(TEXT("ccu_day"));
			m_Custom[i].SetCustomCategory(TEXT("ccu"));
			break;
		case CYSTOMTYPE_PKINFO:
			m_Custom[i].Init(FIVEROCKS_DATA_TYPE_PKINFO);
			break;
		}
		m_Custom[i].SetCustomType((CUSTOMTYPE)i);
		m_Custom[i].InitDB(m_SourceDB->GetRecordsetPtr(), m_SourceDB->GetCommandPtr());
		
	}

	m_hMutexMonoInstance = CreateMutex(NULL, true, TEXT(APP_NAME));
	if(NULL == m_hMutexMonoInstance)
	{
		g_LogFile->WriteSystemLog(L"ERROR : CheckAlreadyRunning (CreateMutex Error)\r\n",true);
		PostQuitMessage(0);
		return false;
	}

	if(ERROR_ALREADY_EXISTS == ::GetLastError())
	{
		g_LogFile->WriteSystemLog(L"ERROR : Application is running already...\r\n",true);
		PostQuitMessage(0);
		return false;
	}

	g_LogFile->WriteSystemLog(L"FiveRocksMain::Init() Success \r\n",true);

	// FiveRocks 데이터 타입 1 삭제
	SourceDBDeleteOption(FIVEROCKS_DATA_TYPE_LOGIN);

	return true;
}
bool FiveRocksMain::Run()
{
	time_t NowTime = time(NULL) + KST_TIME;
	UINT32 Err = NULL;
	bool bConnectDB = false;
	if(m_ActiveUserUpdateTime <= NowTime ||
		m_MonetizationUpdateTime <= NowTime)
	{
		// DB 연결
		SourceDBCnn();
		bConnectDB = true;
	}
	else
	{
		for(int i = 0 ; i < CUSTOMTYPE_END ; i++)
		{
			if(m_CustomUpdateTime[i] <= NowTime)
			{
				// DB 연결
				SourceDBCnn();
				bConnectDB = true;
			}
		}
	}

	if(bConnectDB)
	{
		if(m_ActiveUserUpdateTime <= NowTime)
		{
			// 시간 계산
			m_ActiveUserUpdateTime += m_ActiveUserSegmentTime;
			// ActiveUser 처리
			Err = m_ActiveUser->SelectProc();
			if (Err != NULL)
			{
				if (Err != ERR_DB_NO_DATA)
				{
					g_LogFile->WriteSystemLog(TEXT("========== ActiveUser SelectProc() Err \r\n"));
				}
			}
			if (Err == NULL)
			{
				g_LogFile->WriteSystemLog(TEXT("========== ActiveUser Run() Start \r\n"));
				Err = m_ActiveUser->Run();
				if (Err == NULL)
				{
					g_LogFile->WriteSystemLog(TEXT("========== ActiveUser Run() Fin \r\n"));
				}
				else
				{
					g_LogFile->WriteSystemLog(TEXT("========== ActiveUser Run() Err \r\n"));
				}
			}
		}

		if(m_MonetizationUpdateTime <= NowTime)
		{
			// 시간 계산
			m_MonetizationUpdateTime += m_MonetizationSegmentTime;
			// Monetization 처리
			Err = m_Monetization->SelectProc();
			if (Err != NULL)
			{
				if (Err != ERR_DB_NO_DATA)
				{
					g_LogFile->WriteSystemLog(TEXT("========== Monetization SelectProc() Err \r\n"));
				}
			}
			if (Err == NULL)
			{
				g_LogFile->WriteSystemLog(TEXT("========== Monetization Run() Start \r\n"));
				Err = m_Monetization->Run();
				if (Err == NULL)
				{
					g_LogFile->WriteSystemLog(TEXT("========== Monetization Run() Fin \r\n"));
				}
				else
				{
					g_LogFile->WriteSystemLog(TEXT("========== Monetization Run() Err \r\n"));
				}
			}
		}

		for(int i = 0 ; i < CUSTOMTYPE_END ; i++)
		{
			if(m_CustomUpdateTime[i] <= NowTime)
			{
				TCHAR	CustomLog[1024];
				// 시간 계산
				m_CustomUpdateTime[i] += m_CustomSegmentTime[i];
				// Custom 처리
				Err = m_Custom[i].SelectProc();
				if (Err != NULL)
				{
					if (Err != ERR_DB_NO_DATA)
					{
						wsprintf(CustomLog,TEXT("========== Custom[%d] SelectProc() Err \r\n"),i);
						g_LogFile->WriteSystemLog(CustomLog);
					}
					else
					{
						switch (i)
						{
						case CUSTOMTYPE_CCU_MIN:
						case CUSTOMTYPE_CCU_HOUR:
						case CUSTOMTYPE_CCU_DAY:
							Err = NULL;
							break;
						}
					}
				}
				if (Err == NULL)
				{
					wsprintf(CustomLog,TEXT("========== Custom[%d] Run() Start \r\n"),i);
					g_LogFile->WriteSystemLog(CustomLog);
					Err = m_Custom[i].Run();
					if (Err == NULL)
					{
						wsprintf(CustomLog,TEXT("========== Custom[%d] Run() Fin \r\n"),i);
						g_LogFile->WriteSystemLog(CustomLog);
					}
					else
					{
						wsprintf(CustomLog,TEXT("========== Custom[%d] Run() Err \r\n"),i);
						g_LogFile->WriteSystemLog(CustomLog);
					}
				}
			}
		}
		// DB 연결 종료
		SourceDBDisCnn();
	}

	return true;
}
bool FiveRocksMain::Release()
{
	if (m_ActiveUser)
	{
		delete m_ActiveUser;
		m_ActiveUser = NULL;
	}
	if (m_Monetization)
	{
		delete m_Monetization;
		m_Monetization = NULL;
	}
	if (m_Custom)
	{
		delete[] m_Custom;
		m_Custom = NULL;
	}
	if(m_SourceDB)
	{
		delete m_SourceDB;
		m_SourceDB = NULL;
	}

	if (g_InternetHttp)
	{
		delete g_InternetHttp;
		g_InternetHttp = NULL;
	}

	if(m_hMutexMonoInstance)
	{
		::CloseHandle(m_hMutexMonoInstance);
		m_hMutexMonoInstance = NULL;
	}

	if(g_LogFile)
	{
		delete g_LogFile;
		g_LogFile = NULL;
	}
	return true;
}
bool FiveRocksMain::SourceDBCnn()
{
	TCHAR strCon[1024];
	wsprintf(strCon, SOURCE_DB_CONNECT, m_strSourceDBID, m_strSourceDBPW, m_strSourceDBIP, m_strSourceDBIP, m_strSourceDBPort); 
	return this->m_SourceDB->DBCnn(strCon);
}
void FiveRocksMain::SourceDBDisCnn()
{
	this->m_SourceDB->DBDisCnn();
}

void FiveRocksMain::SourceDBDeleteOption(FIVEROCKS_DATA_TYPE DataType)
{
	TCHAR strlog[1024];

	wsprintf(strlog,TEXT("SourceDBDeleteOption() Start DataType=%d \r\n"),DataType);
	g_LogFile->WriteSystemLog(strlog, TRUE);

	SourceDBCnn();

	_CommandPtr		pSourceCommand = m_SourceDB->GetCommandPtr();

	try
	{
		// 프로시저 설정
		pSourceCommand->CommandText = DB_ATUM_FIVEROCKS_DELETE_OPTION;

		// 프로시저에 들어갈 인자값 설정
		pSourceCommand->Parameters->Append(pSourceCommand->CreateParameter(_bstr_t("i_Datatype"),adTinyInt,adParamInput,2,_variant_t(DataType)));

		// 프로시저 실행
		pSourceCommand->Execute(NULL,NULL,adCmdStoredProc);
		// 인자값 초기화
		pSourceCommand->Parameters->Delete(_bstr_t("i_Datatype"));
	}
	catch(_com_error& e)
	{
		// Print COM errors.
		_bstr_t bstrSource(e.Source());
		_bstr_t bstrDescription(e.Description());
		TCHAR	szError[1024];
		wsprintf(szError, L"[ERROR] %s _com_error !!! Error = %08lx, Message = %s , Source = %s, Description =%s \r\n"
			, TEXT("DeleteOption"), e.Error(), e.ErrorMessage(), (LPCWSTR)bstrSource, (LPCWSTR)bstrDescription);
		g_LogFile->WriteSystemLog(szError, TRUE);
	}

	SourceDBDisCnn();

	wsprintf(strlog,TEXT("SourceDBDeleteOption() Finished DataType=%d \r\n"),DataType);
	g_LogFile->WriteSystemLog(strlog, TRUE);
}

bool FiveRocksMain::GetConfigFile()
{
	const int	SIZE_BUFF = 1024;
	char		buff[SIZE_BUFF];
	const char	*token;
	char		seps[] = " \t";
	char		DefineValueSeps[] = " \t=";
	ifstream	fin;
	CConfig		config;

	// start 2011-12-12 by hskim, GLog 2차
	TCHAR		szGlobalCfgUNI[SIZE_BUFF] = { 0, };
	char		*pGlobalCfgMBC = NULL;

	USES_CONVERSION;

	wsprintf(szGlobalCfgUNI, L"%s%s", m_strConfigRoot, FILE_NAME_GLOBAL_CFG_UNI);
	pGlobalCfgMBC = T2A(szGlobalCfgUNI);
	// end 2011-12-12 by hskim, GLog 2차

	if (!config.LoadUserDefinedVariables(pGlobalCfgMBC))		// 2011-12-12 by hskim, GLog 2차
	{
		TCHAR	szError[1024];
		wsprintf(szError, L"[ERROR] LoadConfiguration, FileName[%s] Code 1\r\n", FILE_PATH_SERVER_INFO_UNI);
		g_LogFile->WriteSystemLog(szError, true);
		return false;
	}

	fin.open(szGlobalCfgUNI);		// 2011-12-12 by hskim, GLog 2차
	if (!fin.is_open())
	{	// cannot open file...
		int nErr = GetLastError();
		SetLastError(0);
		TCHAR	szError[1024];
		TCHAR	szDir[512];
		GetCurrentDirectory(512, szDir);
		wsprintf(szError, L"[ERROR] ConfigFile open() error, LastError[%d] ConfigFileName[%s] CurrentDirectory[%s] Code 2\r\n"
			, nErr, FILE_PATH_SERVER_INFO_UNI, szDir);
		g_LogFile->WriteSystemLog(szError, true);
		return false;
	}

	char *next_token1 = NULL;
	char szConfigValue[SIZE_MAX_ODBC_CONN_STRING];
	BYTE byEncodedBinary[1024];
	memset(szConfigValue, 0x00, SIZE_MAX_ODBC_CONN_STRING);
	memset(byEncodedBinary, 0x00, 1024);

	while(true)
	{
		memset(buff, 0x00, SIZE_BUFF);
		bool bFlagFileEnd = fin.getline(buff, SIZE_BUFF).eof();
		if(bFlagFileEnd == true
			&& strcmp(buff, "") == 0)
		{
			break;
		}
		token = strtok_s(buff, seps, &next_token1);

		if (token == NULL
			|| strlen(token) == 0
			|| strncmp(token, "#", 1) == 0 )
		{	
			continue;
		}

		if(_stricmp(token, SOURCE_DB_ID) == 0)
		{// GLog에 입력될 원본 DB ID
			token = strtok_s(NULL, seps, &next_token1);
			if(token == NULL
				|| strcmp(token, "") == 0)
			{
				return false;
			}

			memset(szConfigValue, 0x00, SIZE_MAX_ODBC_CONN_STRING);
			memset(byEncodedBinary, 0x00, 1024);
			if(false == XOR::XORString2Binary(byEncodedBinary, (char*)token))
			{
				return false;
			}
			XOR::XOREncode((BYTE*)szConfigValue, byEncodedBinary, strlen(token)/2, STR_XOR_KEY_STRING_DB_ID_PWD);
			m_strSourceDBID = CA2W(szConfigValue);
		}
		else if(_stricmp(token, SOURCE_DB_PASSWORD) == 0)
		{// GLog에 입력될 원본 DB PW
			token = strtok_s(NULL, seps, &next_token1);
			if(token == NULL
				|| strcmp(token, "") == 0)
			{
				return false;
			}

			memset(szConfigValue, 0x00, SIZE_MAX_ODBC_CONN_STRING);
			memset(byEncodedBinary, 0x00, 1024);
			if(false == XOR::XORString2Binary(byEncodedBinary, (char*)token))
			{
				return false;
			}
			XOR::XOREncode((BYTE*)szConfigValue, byEncodedBinary, strlen(token)/2, STR_XOR_KEY_STRING_DB_ID_PWD);
			m_strSourceDBPW = CA2W(szConfigValue);
		}
		else if(_stricmp(token, SOURCE_DB_IP) == 0)
		{// GLog에 입력될 원본 DB IP
			token = strtok_s(NULL, seps, &next_token1);
			if(token == NULL
				|| strcmp(token, "") == 0)
			{
				return false;
			}

			m_strSourceDBIP = CA2W(token);
		}
		else if(_stricmp(token, SOURCE_DB_PORT) == 0)
		{// GLog에 입력될 원본 DB PORT
			token = strtok_s(NULL, seps, &next_token1);
			if(token == NULL
				|| strcmp(token, "") == 0)
			{
				return false;
			}

			m_strSourceDBPort = CA2W(token);
		}
	}

	fin.close();
	return true;	
}

void FiveRocksMain::SetConfigRootPath()
{
	// Default Path를 미리 설정해둠

	const int SIZE_BUFF = 1024;
	char		CONFIG_ROOT[SIZE_BUFF] = { 0, };
	char		buff[SIZE_BUFF] = { 0, };
	const char	*token;
	char		seps[] = "\r\n";
	ifstream	fin;
	char *next_token1 = NULL;

	fin.open(FILE_PATH_CONFIG_ROOT_UNI);
	if (!fin.is_open())
	{
		return ;		// cannot open file...
	}

	while(true)
	{
		memset(buff, 0x00, SIZE_BUFF);
		bool bFlagFileEnd = fin.getline(buff, SIZE_BUFF).eof();
		if(bFlagFileEnd == true
			&& strcmp(buff, "") == 0)
		{
			break;
		}

		token = strtok_s(buff, seps, &next_token1);

		if (token == NULL
			|| strncmp(token, "#", 1) == 0
			|| strncmp(token, "$", 1) == 0)
		{	// ignore blank lines
			// ignore comments
			// ignore user defined variables

			continue;
		}

		strncpy_s(CONFIG_ROOT, token, SIZE_BUFF);
	}

	if('\\' != CONFIG_ROOT[strlen(CONFIG_ROOT)-1]
	&& '/' != CONFIG_ROOT[strlen(CONFIG_ROOT)-1])
	{
		strcat_s(CONFIG_ROOT, "/");
	}

	m_strConfigRoot = CA2W(CONFIG_ROOT);
}
// end 2011-12-12 by hskim, GLog 2차