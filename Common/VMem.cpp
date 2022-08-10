// VMem.cpp: implementation of the CVMem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VMem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVMem::CVMem()
{
	InitializeCriticalSection(&m_csLock);
	m_dwSizeObjType				= 0;
	m_dwCntCommitedObjPool		= 0;
	m_dwCntCurrentAllocObjPool	= 0;
	m_dwSizeCommitVMem			= 0;
}

CVMem::~CVMem()
{
	DeleteCriticalSection(&m_csLock);
}

BOOL CVMem::AllocVMem(DWORD dwTypeSize, DWORD dwPoolCount)
{	
	LockVMem();
	if(0 == dwTypeSize || 0 == dwPoolCount)
	{
		UnlockVMem();
		
		char	szError[256];
		sprintf(szError, "[Error] CVMem::AllocVMem_1 invalid parameter, TypeSize[%4d] PoolCount[%4d]\r\n"
			, dwTypeSize, dwPoolCount);
//		g_pGlobal->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}


	const DWORD	dwPAGESIZE = 4096;
	DWORD	dwCalcPoolCnt = 0;
	DWORD	dwCommitVMSize = 0;
	void	*pVMem = NULL;
	
	//////////////////////////////////////////////////////////////////////
	// ��û�� PoolCount�� Page ũ�⿡ �ִ��� ���ߴ� ���
	if((dwTypeSize * dwPoolCount)%dwPAGESIZE != 0)
	{		
		dwCalcPoolCnt = (((dwTypeSize * dwPoolCount)/dwPAGESIZE + 1) * dwPAGESIZE)/dwTypeSize;
	}
	else
	{
		dwCalcPoolCnt = dwPoolCount;
	}
	
	//////////////////////////////////////////////////////////////////////
	// �޸�Ǯ ũ�⸦ Page ������ ���
	dwCommitVMSize	= dwTypeSize * dwCalcPoolCnt;
	if(dwCommitVMSize%dwPAGESIZE != 0)
	{	
		dwCommitVMSize = ((dwCommitVMSize/dwPAGESIZE) + 1) * dwPAGESIZE;		
	}
		
	pVMem = (char*)VirtualAlloc(NULL, dwCommitVMSize, MEM_RESERVE|MEM_TOP_DOWN, PAGE_READWRITE);
	if(NULL == pVMem)
	{	
		UnlockVMem();

		int nErr = GetLastError();
		SetLastError(0);
		char	szError[256];
		sprintf(szError, "[ERROR] CVMem::AllocVMem VirtualAlloc() LastError[%d] CommitSize[%d]\r\n", nErr, dwCommitVMSize);
//		g_pGlobal->WriteSystemLog(szError);
		DBGOUT(szError);
		
		return FALSE;
	}
	if(CommitVMem(pVMem, dwCommitVMSize) == FALSE)
	{
		UnlockVMem();
		return FALSE;
	}	
	m_vectorVMemPtr.push_back(pVMem);
	
	char	szError[256];
	sprintf(szError, "CVMem::AllocVMem VirtualAlloc() success, TypeSize[%5d] PoolCnt[%5d] CommitSize[%8d] vectorSize[%d] Address Range(0x%X ~ 0x%X)\r\n"
		, dwTypeSize, dwCalcPoolCnt, dwCommitVMSize, m_vectorVMemPtr.size()
		, pVMem, (char*)pVMem + dwCommitVMSize);
//	g_pGlobal->WriteSystemLog(szError);
	DBGOUT(szError);
	
	m_dwSizeObjType			= dwTypeSize;
	m_dwCntCommitedObjPool	= dwCalcPoolCnt;
	m_dwSizeCommitVMem		= dwCommitVMSize;

	m_vectorMemoryPointer.reserve(m_dwCntCommitedObjPool * 2);
	for(int i = 0; i < m_dwCntCommitedObjPool; i++)
	{
		InsertFree((char*)pVMem + i*m_dwSizeObjType);
	}

	UnlockVMem();
	return TRUE;
}

BOOL CVMem::FreeAllVMem(void)
{
	LockVMem();	
	m_vectorMemoryPointer.clear();

	vector<void *>::iterator itr = m_vectorVMemPtr.begin();
	while(itr != m_vectorVMemPtr.end())
	{
		this->FreeVMem(*itr);
		itr++;
	}

	m_dwSizeObjType				= 0;
	m_dwCntCommitedObjPool		= 0;
	m_dwCntCurrentAllocObjPool	= 0;
	m_dwSizeCommitVMem			= 0;	
	UnlockVMem();

	return TRUE;
}

BOOL CVMem::FreeVMem(void * pVMem)
{
	if(NULL == pVMem)
	{
		char	szError[1024];
		sprintf(szError, "CVMem::FreeVMem invalid variable, pVMem[x%X]\r\n", pVMem);
//		g_pGlobal->WriteSystemLog(szError);
		DBGOUT(szError);
		return FALSE;
	}
	
	if(VirtualFree(pVMem, 0, MEM_RELEASE) == FALSE)
	{
		int nErr = GetLastError();
		SetLastError(0);
		
		char	szError[1024];
		sprintf(szError, "CVMem::FreeVMem VirtualFree Failure LastError[%d] pVMem[x%X]\r\n",
			nErr, pVMem);
//		g_pGlobal->WriteSystemLog(szError);
		DBGOUT(szError);
	}
	
	return TRUE;
}
