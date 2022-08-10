// Queue.cpp: implementation of the CQueue class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Queue.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CQueue::CQueue(int max_size): m_iMaxSize(max_size)
{
	::InitializeCriticalSection( &m_Lock );
	m_pBuffer		= new BYTE[m_iMaxSize];
	m_nfront		= 0;
	m_nback			= 0;
	m_nTotalBytes	= 0;
}

CQueue::~CQueue()
{
	if(m_pBuffer)
	{
		delete[] m_pBuffer;
	}
	::DeleteCriticalSection( &m_Lock );
}

int CQueue::SpaceFree()
{
	::EnterCriticalSection( &m_Lock );
	int size = m_iMaxSize - m_nTotalBytes - 1;
	::LeaveCriticalSection( &m_Lock );
	return size;
}

int CQueue::SpaceUsed()
{
	::EnterCriticalSection( &m_Lock );
	int size = m_nTotalBytes + 1;
	::LeaveCriticalSection( &m_Lock );
	return size;                      
}

int CQueue::InsertFront(byte *data, int count)
{
	int nRet = 0;
	int i;

	EnterCriticalSection(&m_Lock);
	if(m_iMaxSize < count || m_iMaxSize <= m_nTotalBytes + count)
	// �Է� ����Ÿ�� ť������ ���� ũ�ų� �̵���Ÿ�� �Է��Ұ�� ť����� �ʰ��ϴ� ���
	{
		LeaveCriticalSection(&m_Lock);
		return nRet;
	}

	if(m_nfront == m_nback)
	// Queue�� ����ִ� ����
	{
		if(m_nfront+count < m_iMaxSize)
		{
			CopyMemory(m_pBuffer+m_nfront, data, count);
		}
		else
		{
			i = m_iMaxSize - m_nfront;
			CopyMemory(m_pBuffer+m_nfront, data, i);
			CopyMemory(m_pBuffer, data + i, count - i);
		}		
	}
	else
	{
		if(m_nfront < m_nback)
		{
			CopyMemory(m_pBuffer+m_nfront, data, count);			
		}
		else
		{
			i = (m_iMaxSize - m_nfront) > count ? count : m_iMaxSize - m_nfront;
			CopyMemory(m_pBuffer+m_nfront, data, i);
			if(count - i > 0)
			{
				CopyMemory(m_pBuffer, data + i, count - i);
			}			
		}	
	}
	m_nfront = (m_nfront + count)%m_iMaxSize;
	m_nTotalBytes += count;
	nRet = m_nTotalBytes;

	LeaveCriticalSection(&m_Lock);

	return nRet;
}


int CQueue::ExtractBack(byte *data, int max)
{
	int nRet = 0;
	int i;

	EnterCriticalSection(&m_Lock);
	if(m_nTotalBytes - max < 0 )
	// ť�� �����Ͱ� ������ ������ ũ�� ���� �۰ų� ť�� �����Ͱ� ����.
	{ 
		LeaveCriticalSection(&m_Lock);
		return nRet;
	}
	
	if(m_nfront > m_nback)
	{
		CopyMemory(data, m_pBuffer+m_nback, max);
	}
	else
	{
		i = m_iMaxSize - m_nback > max ? max : m_iMaxSize - m_nback;
		CopyMemory(data, m_pBuffer+m_nback, i);
		if(max - i > 0)
		{
			CopyMemory(data + i, m_pBuffer, max - i);
		}
	}
	m_nback = (m_nback + max)%m_iMaxSize;
	m_nTotalBytes -= max;
	nRet = max;

	LeaveCriticalSection(&m_Lock);
	return nRet;
}

void CQueue::Clear()
{
	::EnterCriticalSection( &m_Lock ); 
	m_nfront		= 0;
	m_nback			= 0;
	m_nTotalBytes	= 0;
	::LeaveCriticalSection( &m_Lock ); 
}