// VMemPool.h: interface for the CVMemMan class.
//
//	//-- CMKWON 2003-05-23 --//
//	- vmPoolAddObject(), vmPoolInit(), vmPoolClean() �Լ��� ����ȭ ó������ ����, ��ü ������ ����ȭ ó���� �ؾ���
//	- ��ü�� �������� ����, ��ü�� �������� static�Լ������� ���۵�
//	-
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VMEMPOOL_H__BD52675B_6C82_4CDE_8618_0141D7A4653F__INCLUDED_)
#define AFX_VMEMPOOL_H__BD52675B_6C82_4CDE_8618_0141D7A4653F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "VMem.h"

const DWORD	SIZE_MAX_VIRTUALPOOL_ARRAY			= 12;
const DWORD SIZE_MAX_OBJECTTYPE					= 65536;	// �ִ� Object Buffer Size 65536 Bytes

typedef struct
{
	DWORD	dwObjTypeSize;
	DWORD	dwObjPoolSize;
} SObjectInfo;

class CVMemPool
{
private:
	CVMemPool();
	~CVMemPool();

public:
	static BOOL vmPoolAddObject(DWORD dwObjTypeSize, DWORD dwObjPoolSize = 1024);
	static BOOL vmPoolInit(void);
	static void vmPoolClean(void);

	inline static void* vmObjectNew(DWORD dwObjSize);
	inline static void vmObjectDelete(void *p, DWORD dwObjSize);

private:
	inline static CVMem* vmSearchValidVMem(DWORD dwObjSize);

private:
	static SObjectInfo		ms_ArrayObjInfo[SIZE_MAX_VIRTUALPOOL_ARRAY];	// �޸� Ǯ�� ����� Object ���� �迭
	static DWORD			ms_dwCountArrayObjInfo;							// �޸� Ǯ�� ����� Object ���� �迭 ī��Ʈ
	static CVMem			ms_ArrayVMem[SIZE_MAX_VIRTUALPOOL_ARRAY];		// �޸� Ǯ �迭
	static DWORD			ms_dwSizeArrayVMem;								// ������� �޸� Ǯ �迭 ������
	static BOOL				ms_bFlagVMemInit;								// �޸�Ǯ �ʱ�ȭ �÷���
};

////////////////////////////////////////////////////////////////////////////////
//
// �� �� �� ��  : CVMemPool::vmObjectNew
// ��ȯ�Ǵ� ��  : void *
// �� �� �� ��  : DWORD dwObjSize
// �� �� �� ��  : inline static �Լ�
//					�޸�Ǯ���� ����� �´� �޸𸮸� �Ҵ��ϰ� �� �ּҸ� �����Ѵ�.
void * CVMemPool::vmObjectNew(DWORD dwObjSize)
{
	CVMem *pVMem = vmSearchValidVMem(dwObjSize);
	if(pVMem)
	{
		return pVMem->ObjectNew();
	}

	char	szError[1024];
	sprintf(szError, "CVMemPool::vmObjectNew error, FlagVMemInit[%2d] SizeArrayVMem[%2d] ObjSize[%4d]\r\n"
		, ms_bFlagVMemInit, ms_dwSizeArrayVMem, dwObjSize);
//	g_pGlobal->WriteSystemLog(szError);
	DBGOUT(szError);
	return NULL;
}


////////////////////////////////////////////////////////////////////////////////
//
// �� �� �� ��  : CVMemPool::vmObjectDelete
// ��ȯ�Ǵ� ��  : void
// �� �� �� ��  : void *p
// �� �� �� ��  : DWORD dwObjSize
// �� �� �� ��  : inline static �Լ�
//					�޸�Ǯ���� ���ڷ� ���� �ּҸ� �����Ѵ�.
void CVMemPool::vmObjectDelete(void *p, DWORD dwObjSize)
{
	CVMem *pVMem = vmSearchValidVMem(dwObjSize);
	if(pVMem)
	{
		pVMem->ObjectDelete(p);
		return;
	}

	char	szError[1024];
	sprintf(szError, "CVMemPool::vmObjectDelete error, FlagVMemInit[%2d] SizeArrayVMem[%2d] p[0x%X] ObjSize[%4d]\r\n"
		, ms_bFlagVMemInit, ms_dwSizeArrayVMem, p, dwObjSize);
//	g_pGlobal->WriteSystemLog(szError);
	DBGOUT(szError);
}


////////////////////////////////////////////////////////////////////////////////
//
// �� �� �� ��  : CVMemPool::vmSearchValidVMem
// ��ȯ�Ǵ� ��  : CVMem*
// �� �� �� ��  : DWORD dwObjSize
// �� �� �� ��  : inline static �Լ�
//					�޸� Ǯ���� ObjectTypeSize�� �´� CVMem�� ��ü�� ã�Ƽ� �����ϴ� �Լ�
CVMem* CVMemPool::vmSearchValidVMem(DWORD dwObjSize)
{
	DWORD i{ 0 };
	for(i = 0; i < ms_dwSizeArrayVMem; i++)
	{
		if(ms_ArrayObjInfo[i].dwObjTypeSize == dwObjSize)
		{
			return &ms_ArrayVMem[i];
		}
	}

	char	szError[1024];
	char	szTemp[512];
	sprintf(szError, "CVMemPool::vmSearchValidVMem error, FlagVMemInit[%2d] SizeArrayVMem[%2d],"
		, ms_bFlagVMemInit, ms_dwSizeArrayVMem);
	for(i = 0; i < ms_dwSizeArrayVMem; i++)
	{
		sprintf(szTemp, " %2d[%4d]", ms_ArrayObjInfo[i].dwObjTypeSize);
		strcat(szError, szTemp);
	}
	strcat(szError, "\r\n");
//	g_pGlobal->WriteSystemLog(szError);
	DBGOUT(szError);
	return NULL;
}

#endif // !defined(AFX_VMEMPool_H__BD52675B_6C82_4CDE_8618_0141D7A4653F__INCLUDED_)
