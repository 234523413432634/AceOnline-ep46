// VMemPool.cpp: implementation of the CSaveLastError class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VMemPool.h"
//#include "Global.h"

//////////////////////////////////////////////////////////////////////
// Global Variable/Function
//////////////////////////////////////////////////////////////////////
bool operator<(SObjectInfo lhObj, SObjectInfo rhObj)
{
	return lhObj.dwObjTypeSize < rhObj.dwObjTypeSize;
}

//////////////////////////////////////////////////////////////////////
//	Static Variable
//////////////////////////////////////////////////////////////////////
SObjectInfo	CVMemPool::ms_ArrayObjInfo[SIZE_MAX_VIRTUALPOOL_ARRAY];
DWORD		CVMemPool::ms_dwCountArrayObjInfo = 0;
CVMem		CVMemPool::ms_ArrayVMem[SIZE_MAX_VIRTUALPOOL_ARRAY];
DWORD		CVMemPool::ms_dwSizeArrayVMem = 0;
BOOL		CVMemPool::ms_bFlagVMemInit = FALSE;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CVMemPool::CVMemPool()
{
}

CVMemPool::~CVMemPool()
{
}


////////////////////////////////////////////////////////////////////////////////
//
// �� �� �� ��  : CVMemPool::vmPoolAddObject
// ��ȯ�Ǵ� ��  : BOOL
// �� �� �� ��  : DWORD dwObjTypeSize
// �� �� �� ��  : DWORD dwObjPoolSize
// �� �� �� ��  : static �Լ�
//					�޷θ� Ǯ�� �Ҵ��ϱ� ���� �޸𸮸� �Ҵ��� Object�� Ÿ�԰� ����� �߰��ϴ� �Լ�
BOOL CVMemPool::vmPoolAddObject(DWORD dwObjTypeSize, DWORD dwObjPoolSize)
{
	if(0 == dwObjTypeSize
		|| dwObjTypeSize%4 != 0
		|| SIZE_MAX_OBJECTTYPE < dwObjTypeSize 
		|| dwObjTypeSize * dwObjPoolSize > 1024 * 1024 * 100)
	{	// ��ȿ�� üũ
		// ��û�� Memory Pool ����� 100 �ް� ���� ũ�� FALSE�� �����Ѵ�.
		
		char	szError[1024];
		sprintf(szError, "CVMemPool::vmPoolAddObject invalid parameter, ObjTypeSize[%4d] ObjPoolSize[%d]\r\n"
			, dwObjTypeSize, dwObjPoolSize);
//		g_pGlobal->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}
	
	BOOL		bAddedFlag = FALSE;	
	for(DWORD i = 0; i < ms_dwCountArrayObjInfo; i++)
	{
		if(ms_ArrayObjInfo[i].dwObjTypeSize == dwObjTypeSize)
		{
			if(ms_ArrayObjInfo[i].dwObjTypeSize * (ms_ArrayObjInfo[i].dwObjPoolSize + dwObjPoolSize) > 1024*1024*100)
			{
				return FALSE;
			}
			ms_ArrayObjInfo[i].dwObjPoolSize += dwObjPoolSize;
			bAddedFlag = TRUE;
			break;
		}
	}

	if(FALSE == bAddedFlag && ms_dwCountArrayObjInfo < SIZE_MAX_VIRTUALPOOL_ARRAY - 1)
	{
		ms_ArrayObjInfo[ms_dwCountArrayObjInfo].dwObjTypeSize = dwObjTypeSize;
		ms_ArrayObjInfo[ms_dwCountArrayObjInfo].dwObjPoolSize = dwObjPoolSize;
		ms_dwCountArrayObjInfo++;
		bAddedFlag = TRUE;
		
		if(ms_dwCountArrayObjInfo > 1)
		{	// Object Info�� 2�� �̻��϶� ObjectTypeSize�� �������� �����Ѵ�.
			
			sort(&ms_ArrayObjInfo[0], &ms_ArrayObjInfo[ms_dwCountArrayObjInfo]);
		}
	}

	return bAddedFlag;
}

////////////////////////////////////////////////////////////////////////////////
//
// �� �� �� ��  : CVMemPool::vmPoolInit
// ��ȯ�Ǵ� ��  : BOOL
// �� �� �� ��  : void
// �� �� �� ��  : static �Լ�
//					�޸� Ǯ�� ���� �޸𸮸� �Ҵ��Ѵ�.
BOOL CVMemPool::vmPoolInit(void)
{
	if(ms_bFlagVMemInit 
		|| !ms_dwCountArrayObjInfo 
		|| ms_dwCountArrayObjInfo >= SIZE_MAX_VIRTUALPOOL_ARRAY)
	{
		char	szError[1024];
		sprintf(szError, "CVMemPool::vmPoolInit invalid variable, FlagVMemInit[%2d] CountArrayObjInfo[%2d]\r\n"
			, ms_bFlagVMemInit, ms_dwCountArrayObjInfo);
//		g_pGlobal->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}

	BOOL bRet;
	for(UINT i = 0; i < ms_dwCountArrayObjInfo; i++)
	{
		bRet = ms_ArrayVMem[i].AllocVMem(ms_ArrayObjInfo[i].dwObjTypeSize, ms_ArrayObjInfo[i].dwObjPoolSize);
		if(FALSE == bRet)
		{
			return FALSE;
		}
	}
	ms_dwSizeArrayVMem	= ms_dwCountArrayObjInfo;
	ms_bFlagVMemInit	= TRUE;

	return ms_bFlagVMemInit;
}



////////////////////////////////////////////////////////////////////////////////
//
// �� �� �� ��  : CVMemPool::vmPoolClean
// ��ȯ�Ǵ� ��  : void
// �� �� �� ��  : �޸� Ǯ�� �޷θ��� �����Ѵ�.
//
void CVMemPool::vmPoolClean()
{
	if(FALSE == ms_bFlagVMemInit)
	{
		char	szError[1024];
		sprintf(szError, "CVMemPool::vmPoolClean invalid variable, FlagVMemInit[%2d]\r\n"
			, ms_bFlagVMemInit);
//		g_pGlobal->WriteSystemLog(szError);
		DBGOUT(szError);		
		return;
	}
	ms_bFlagVMemInit = FALSE;
	for(UINT i = 0; i < ms_dwCountArrayObjInfo; i++)
	{
		ms_ArrayVMem[i].FreeAllVMem();
	}
}
