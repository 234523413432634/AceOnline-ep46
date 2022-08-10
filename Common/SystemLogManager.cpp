#include "stdafx.h"
#include "SystemLogManager.h"

#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>

// constructor
CSystemLogManager::CSystemLogManager()
{
	InitializeCriticalSection(&m_criticalSection);
	m_hFile		= NULL;
	memset(m_szFileName, 0x00, 512);
	memset(m_szDirectory, 0x00, 512);

	m_bChangingFlagFile = FALSE;
	// 2013-10-09 by jhseol, 로그파일에 서버 생성시간 추가
	m_nLogFileCreateCount = 0;
	memset(m_szServerCreateTime, 0x00, SIZE_MAX_STRING_128);
	// end 2013-10-09 by jhseol, 로그파일에 서버 생성시간 추가
}

// destructor
CSystemLogManager::~CSystemLogManager()
{
	CloseFile();
	DeleteCriticalSection(&m_criticalSection);
}

void CSystemLogManager::Clean()
{
	CloseFile();
}

BOOL CSystemLogManager::InitLogManger(BOOL bUse, char *szFileName, char *szDirectory)
{
	if(!bUse
		|| strncmp(szFileName, "", 512) == 0
		|| strncmp(szDirectory, "", 512) == 0
		|| strlen(szFileName) > 511
		|| strlen(szDirectory) > 511)
	{
		return FALSE;
	}

	EnterCriticalSection(&m_criticalSection);
	if(!OpenFile(szFileName, szDirectory))
	{
		LeaveCriticalSection(&m_criticalSection);
		return FALSE;
	}
	LeaveCriticalSection(&m_criticalSection);

	// 2013-10-09 by jhseol, 로그파일에 서버 생성시간 추가 - 위치변경 주석처리
// 	// 2009-02-23 by cmkwon, PC 재부팅 경과 시간 로금 남기기 추가
// 	int nElapsedSec	= GetTickCount()/1000;
// 	int nSecond		= nElapsedSec%60;
// 	int nMinute		= (nElapsedSec/60)%60;
// 	int nHour		= (nElapsedSec/3600)%24;
// 	int nDay		= nElapsedSec/86400;
// 	char szTemp[1024];
//	sprintf(szTemp, "[Notify] elapsed time after turn on !! %2dDay %2dh:%2dm:%2ds \r\n", nDay, nHour, nMinute, nSecond);
//	this->WriteSystemLog(szTemp);
	// end 2013-10-09 by jhseol, 로그파일에 서버 생성시간 추가 - 위치변경 주석처리
	return TRUE;
}

BOOL CSystemLogManager::OpenFile(char *szFileName, char *szDirectory)
{
	if(m_hFile != NULL){	return FALSE;}

	if(CreateDirectory(szDirectory, NULL) == 0)
	{
		// error
		int nErr = GetLastError();
		SetLastError(0);

		if(nErr != ERROR_ALREADY_EXISTS)
		{
			///////////////////////////////////////////////////////////////////////////////
			// 2008-09-24 by cmkwon, 게임 로그 폴더  \Log\ 자동 생성되게 구현 - 
			char szTmDir[MAX_PATH];
			MEMSET_ZERO(szTmDir, MAX_PATH);
			memcpy(szTmDir, szDirectory, strlen(szDirectory)-1);	// 2008-09-24 by cmkwon, 마지막 / or \ 문자를 제거하고 복사

			char *pParentDirEnd = strrchr(szTmDir, '\\');
			if(NULL == pParentDirEnd)
			{
				pParentDirEnd = strrchr(szTmDir, '/');
			}			
			if(pParentDirEnd)
			{// 2008-09-24 by cmkwon, 2번째 상위 디렉토리가 있다면 생성해 본다.
				char szParentDirPath[MAX_PATH];
				MEMSET_ZERO(szParentDirPath, MAX_PATH);
				memcpy(szParentDirPath, szTmDir, min(pParentDirEnd-szTmDir, MAX_PATH));

				CreateDirectory(szParentDirPath, NULL);
				CreateDirectory(szDirectory, NULL);
				nErr = GetLastError();
				SetLastError(0);
			}

			if(NO_ERROR != nErr
				&& ERROR_ALREADY_EXISTS != nErr)
			{
				char szTemp[256];
				sprintf(szTemp, "[ERROR] CSystemLogManager::OpenFile_ CreateDirectory_ error, LastError[%d] FileName[%s] Directory[%s]\r\n",
					nErr, szFileName, szDirectory);
				MessageBox(NULL, szTemp, "ERROR", MB_OK);
				return FALSE;
			}
		}
	}
	STRNCPY_MEMSET(m_szFileName, szFileName, 512);
	STRNCPY_MEMSET(m_szDirectory, szDirectory, 512);

	time_t		ltime;
	struct tm	*today = NULL;
	char		szCurrTime[128];
	_tzset();
	time(&ltime);
	strftime(szCurrTime, 128, "%Y%m%d_%H%M%S.log", localtime(&ltime));
	
	sprintf(m_szOpenedFilePath, "%s%s_%s", m_szDirectory, m_szFileName, szCurrTime);

	m_hFile = CreateFile(m_szOpenedFilePath, GENERIC_WRITE, FILE_SHARE_READ, NULL,
							CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if ( m_hFile == INVALID_HANDLE_VALUE)
	{
		// error
		int nErr = GetLastError();
		SetLastError(0);

		char szTemp[256];
		sprintf(szTemp, "[ERROR] CSystemLogManager::OpenFile_ CreateFile_ error, LastError[%d] OpenFileName[%s]\r\n",
			nErr, m_szOpenedFilePath);
		MessageBox(NULL, szTemp, "ERROR", MB_OK);
		return FALSE;
	}

	// 2013-10-09 by jhseol, 로그파일에 서버 생성시간 추가 - 위치변경 코드추가
	// 2009-02-23 by cmkwon, PC 재부팅 경과 시간 로금 남기기 추가
	int nElapsedSec	= GetTickCount()/1000;
	int nSecond		= nElapsedSec%60;
	int nMinute		= (nElapsedSec/60)%60;
	int nHour		= (nElapsedSec/3600)%24;
	int nDay		= nElapsedSec/86400;
	char szTemp[1024];
//	sprintf(szTemp, "[Notify] elapsed time after turn on !! %2dDay %2dh:%2dm:%2ds \r\n", nDay, nHour, nMinute, nSecond);
	
// 	char szServerCreateTime[SIZE_MAX_STRING_128] = {NULL,};
// 	strcpy(szServerCreateTime, );
	SetServerCreateTime(szFileName);
	m_nLogFileCreateCount++;	// 2013-10-09 by jhseol, 로그파일에 서버 생성시간 추가
	sprintf(szTemp, "[Notify] elapsed time after turn on !! %2dDay %2dh:%2dm:%2ds LogFileCreateCount(%2d) ServerCreateTime[%s]\r\n", nDay, nHour, nMinute, nSecond, m_nLogFileCreateCount, m_szServerCreateTime);
	this->WriteSystemLog(szTemp);
	// end 2013-10-09 by jhseol, 로그파일에 서버 생성시간 추가 - 위치변경 코드추가
	return TRUE;
}

BOOL CSystemLogManager::CloseFile()
{
	EnterCriticalSection(&m_criticalSection);
	if(m_hFile)
	{
		DWORD dwSize = GetFileSize(m_hFile, NULL);
		CloseHandle(m_hFile);
		m_hFile = NULL;

		if(dwSize == 0)
		{
			DeleteFile(m_szOpenedFilePath);
		}
	}
	LeaveCriticalSection(&m_criticalSection);
	return TRUE;
}

BOOL CSystemLogManager::ChangeFile()
{
	m_bChangingFlagFile = TRUE;
	EnterCriticalSection(&m_criticalSection);	
	CloseFile();
	char szTempFileName[512];
	char szTempDirectory[512];
	STRNCPY_MEMSET(szTempFileName, m_szFileName, 512);
	STRNCPY_MEMSET(szTempDirectory, m_szDirectory, 512);
	if(!OpenFile(szTempFileName, szTempDirectory))
	{
		LeaveCriticalSection(&m_criticalSection);
		m_bChangingFlagFile = FALSE;
		return FALSE;
	}	
	LeaveCriticalSection(&m_criticalSection);
	m_bChangingFlagFile = FALSE;
	return TRUE;
}

BOOL CSystemLogManager::WriteSystemLog(char* log, BOOL bTimeFlag)
{
	// 2013-09-23 by jekim, 계정 블락시 메세지 뿌려주기.
	if(strlen(log) >= 1024 - 18)
	{
		log[1002]='$';
		log[1003]='\r';
		log[1004]='\n';
		log[1005]=NULL;
	}
	// end 2013-09-23 by jekim, 계정 블락시 메세지 뿌려주기.
	if(strlen(log) >= 1024 - 18
		|| (m_bChangingFlagFile == FALSE && m_hFile == INVALID_HANDLE_VALUE)
		|| (m_bChangingFlagFile == FALSE && m_hFile == 0))
	{	// error, file not opened
		DbgOut("\r\nCSystemLogManager::WriteSystemLog error, m_hFile[0x%X] StringSize[%d]\n",
			m_hFile, strlen(log));
		return FALSE;
	}

	char szLogLineBuffer[1024];
	char szTime[128];
	// 2013-09-11 by jekim, 로그 시간 밀리세컨드까지 표시
	SYSTEMTIME ltime;
// 	time_t ltime;
// 	struct tm *today = NULL;
	// end 2013-09-11 by jekim, 로그 시간 밀리세컨드까지 표시
	DWORD	nWritten;
	DWORD	dwFileSize = 0;

	if(bTimeFlag)
	{

		EnterCriticalSection(&m_criticalSection);
		
		///////////////////////////////////////////////////////////////////////////////
		// 2007-02-28 by cmkwon, 위치 이동함
		// 2013-09-11 by jekim, 로그 시간 밀리세컨드까지 표시
		GetLocalTime(&ltime);
		sprintf(szTime,"%02d-%02d %02d:%02d:%02d.%03d|",ltime.wMonth,ltime.wDay,ltime.wHour,ltime.wMinute,ltime.wSecond,ltime.wMilliseconds);
// 		time(&ltime);
// 		today = localtime(&ltime);
// 		// 2007-07-25 by cmkwon, 엑셀로 로딩 할때를 위해서 구분자로 아래와 같이 수정함
// 		//strftime(szTime, 128, "[%m-%d %H:%M:%S] ", today );
// 		strftime(szTime, 128, "%m-%d %H:%M:%S|", today );
		// end 2013-09-11 by jekim, 로그 시간 밀리세컨드까지 표시
		strcpy(szLogLineBuffer, szTime);
		strcat(szLogLineBuffer, log);

		dwFileSize = GetFileSize(m_hFile, NULL);
		// 2009-04-02 by cmkwon, 아래와 같이 10MBtyes(10485760Bytes) 로 체크 변경함.
		//if(dwFileSize > 3*1024*1024)
		if(dwFileSize > 10485760)
		{	// System Log File이 3 MBytes 보다 크면 새로운 File을 open한다.
			if(ChangeFile() == FALSE)
			{
				LeaveCriticalSection(&m_criticalSection);
				return FALSE;
			}
		}
		WriteFile(m_hFile, szLogLineBuffer, strlen(szLogLineBuffer), &nWritten, NULL);
		LeaveCriticalSection(&m_criticalSection);
	}
	else
	{
		szLogLineBuffer[0] = NULL;
		strcpy(szLogLineBuffer, "                  ");
		strcat(szLogLineBuffer, log);

		EnterCriticalSection(&m_criticalSection);
		WriteFile(m_hFile, szLogLineBuffer, strlen(szLogLineBuffer), &nWritten, NULL);
		dwFileSize = GetFileSize(m_hFile, NULL);
		LeaveCriticalSection(&m_criticalSection);
	}
	return TRUE;
}

// 2013-10-09 by jhseol, 로그파일에 서버 생성시간 추가
void CSystemLogManager::SetServerCreateTime(char *szFileName/* = "ERROR"*/)
{
	if (strlen(m_szServerCreateTime) > 0)
	{
		return;
	}
	char szCreateTime[SIZE_MAX_STRING_128] = {NULL,};
	char szServerName[SIZE_MAX_STRING_128] = {NULL,};

	if ( szFileName == "PreSystem" )
	{
		sprintf(szServerName, "%s../Bin/Release/PreServer.exe", CONFIG_ROOT);
	}
	else if ( szFileName == "LogSystem" || szFileName == "LogGameLog" )
	{
		sprintf(szServerName, "%s../Bin/Release/LogServer.exe", CONFIG_ROOT);
	}
	else if ( szFileName == "IMSystem" || szFileName == "IMChatting" )
	{
		sprintf(szServerName, "%s../Bin/Release/IMServer.exe", CONFIG_ROOT);
	}
	else if ( szFileName == "FieldSystem" )
	{
		sprintf(szServerName, "%s../Bin/Release/FieldServer.exe", CONFIG_ROOT);
	}
	else if ( szFileName == "NPCSystem" )
	{
		sprintf(szServerName, "%s../Bin/Release/NPCServer.exe", CONFIG_ROOT);
	}
	else
	{
		strcpy(m_szServerCreateTime, "ERROR");
		return;
	}

	int nPEHeaderOffset;
	int nReaded;
	FILE* fp;
	fp = fopen( szServerName, "rb" );
	if (NULL == fp)
	{
		strcpy(m_szServerCreateTime, "[ERROR] fopen( szServerName, rb )");
		return;
	}
	
	IMAGE_DOS_HEADER idh;
	
	nReaded = fread( &idh, sizeof(idh), 1, fp );
	if( nReaded != 1 )
	{
		fclose(fp);
		strcpy(m_szServerCreateTime, "[ERROR] fread( buf, sizeof(IMAGE_DOS_HEADER), 1, fp )");
		return;
	}
	
	if( idh.e_magic != 'ZM' )        // check 'MZ'
	{
		fclose(fp);
		strcpy(m_szServerCreateTime, "[ERROR] DOS signature error");
		return;
	}
	
	nPEHeaderOffset = idh.e_lfanew;
	
	if( 0 != fseek( fp, nPEHeaderOffset, SEEK_SET ) )
	{
		fclose(fp);
		strcpy(m_szServerCreateTime, "[ERROR] seek( fp, SEEK_SET, nPEHeaderOffset )");
		return;
	}
	
	DWORD pe_sig;
	nReaded = fread( &pe_sig, sizeof(pe_sig), 1, fp );
	if( nReaded != 1 )
	{
		fclose(fp);
		strcpy(m_szServerCreateTime, "[ERROR] fread( buf, sizeof(pe_sig), 1, fp )");
		return;
	}
	if( pe_sig != 'EP' ) // 'PE  ' signature check
	{
		fclose(fp);
		strcpy(m_szServerCreateTime, "[ERROR] PE signature error");
		return;
	}
	
	IMAGE_FILE_HEADER ifh;
	nReaded = fread( &ifh, sizeof(ifh), 1, fp );
	if( nReaded != 1 )
	{
		fclose(fp);
		strcpy(m_szServerCreateTime, "[ERROR] fread( buf, sizeof(IMAGE_FILE_HEADER), 1, fp )");
		return;
	}
	SYSTEMTIME st;
	FILETIME ft;
	ULARGE_INTEGER li;
	
	memset(&st, 0x00, sizeof(st));
	st.wYear = 1970, st.wMonth = 1, st.wDay = 1, st.wHour = 9;
	
	SystemTimeToFileTime(&st, &ft);
	li.HighPart  = ft.dwHighDateTime;
	li.LowPart   = ft.dwLowDateTime;
	li.QuadPart += ((unsigned __int64)ifh.TimeDateStamp * 10000000L);
	ft.dwHighDateTime = li.HighPart;
	ft.dwLowDateTime  = li.LowPart;
	FileTimeToSystemTime(&ft, &st);
	
	sprintf(szCreateTime, "%04d/%02d/%02d %02d:%02d:%02d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
	fclose(fp);
	strcpy(m_szServerCreateTime, szCreateTime);
	return;
}
// end 2013-10-09 by jhseol, 로그파일에 서버 생성시간 추가