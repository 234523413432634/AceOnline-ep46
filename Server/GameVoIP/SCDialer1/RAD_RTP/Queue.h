// Queue.h: interface for the CQueue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUEUE_H__B64962C5_F995_495B_9675_6C82B7CCE2F8__INCLUDED_)
#define AFX_QUEUE_H__B64962C5_F995_495B_9675_6C82B7CCE2F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <deque>
using namespace std;

class CQueue  
{
public:
	enum {DEFAULT_MAX_SIZE = 2048};

//protected:
	CRITICAL_SECTION	m_Lock;
	const int			m_iMaxSize;

	BYTE*				m_pBuffer;
	int					m_nfront;
	int					m_nback;
	int					m_nTotalBytes;

	
public:
	CQueue(int max_size);
	virtual ~CQueue();

	//Queue���� �����ִ� ������ size�� return.
	int SpaceFree();

	//Queue���� ������� ������ size�� return.
	int SpaceUsed();

	//insert�� count��ŭ�� data�� Insert�ϰ� �����ϸ�,
	//�� ����ŭ�� return�ϰ�, �����ϸ� 0�� return.
	int InsertFront(byte *data, int count);

	//Queue���� max�� ��ŭ�� data�� extract�ϰ�,
	//���� ����ŭ�� return ,�����ϸ� 0�� return.
	int ExtractBack(byte *data, int max);

	//Queue���� Clear.
	void Clear();
};

#endif // !defined(AFX_QUEUE_H__B64962C5_F995_495B_9675_6C82B7CCE2F8__INCLUDED_)
