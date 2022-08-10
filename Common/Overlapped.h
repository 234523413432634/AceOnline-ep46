///////////////////////////////////////////////////////////////////////////////
//  Overlapped.h : 
//  
//  Date	: 2004-03-17 by cmkwon
///////////////////////////////////////////////////////////////////////////////

#ifndef _OVERLAPPED_H_
#define _OVERLAPPED_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SocketHeader.h"


///////////////////////////////////////////////////////////////////////////////
// COverlapped ��ü�� delete �ϱ� ���� define
#define SAFE_DELETE_COverlapped(pOver)	\
	{									\
		if(NULL != pOver				\
			&& pOver->GetOverlappedType() == COverlapped::EN_OVERLAPPED_TYPE_DYNAMIC)	\
		{								\
			delete (pOver);				\
			(pOver) = NULL;				\
		}								\
	}


class COverlapped;				// 2008-03-13 by cmkwon, ��Ը� ����� Ŭ���̾�Ʈ �ñ�°� ���� - 
struct SSendedOverlappedInfo	// 2008-03-13 by cmkwon, ��Ը� ����� Ŭ���̾�Ʈ �ñ�°� ���� - 
{
	COverlapped		*pOverlapped;
	BYTE			*pbyData;
	int				nSendedSize;
};
typedef vector<SSendedOverlappedInfo>		vectSSendedOverlappedInfo;	// 2008-03-13 by cmkwon, ��Ը� ����� Ŭ���̾�Ʈ �ñ�°� ���� - 

class COverlapped : public OVERLAPPED
{
public:
	typedef enum
	{
		EN_OPERATION_MODE_READ		= 0,
		EN_OPERATION_MODE_WRITE		= 1
	} ENOperationMode;
	typedef enum
	{
		EN_OVERLAPPED_TYPE_STATIC	= 2,
		EN_OVERLAPPED_TYPE_DYNAMIC	= 3
	} ENOverlappedType;

	// 2013-03-13 by hskim, �� ĳ�� ���� - RawData ���� ��� �߰�
	typedef enum
	{
		EN_DATA_TYPE_ACEONLINE	= 0,
		EN_DATA_TYPE_RAW		= 1
	} ENDataType;
	// end 2013-03-13 by hskim, �� ĳ�� ���� - RawData ���� ��� �߰�

public:	
	COverlapped(ENOperationMode i_enOperationMode, 
		ENOverlappedType i_enOverlappedType, BOOL Encoding = FALSE, ENDataType i_enDataType = EN_DATA_TYPE_ACEONLINE);		// 2013-03-13 by hskim, �� ĳ�� ���� - RawData ���� ��� �߰�
	~COverlapped();

	///////////////////////////////////////////////////////////////////////////
	// Property
	BYTE GetOperationMode(void){				return m_enOperationMode;};
	BYTE GetOverlappedType(void){				return m_enOverlappedType;};
	BYTE GetDataType(void){						return m_enDataType;};			// 2013-03-13 by hskim, �� ĳ�� ���� - RawData ���� ��� �߰�
	WSABUF * GetWSABUFPtr(void){				return &m_WSABUF;};
	sockaddr_in * Getsocketaddr_inPtr(void){	return &m_socketaddr_in;};
	int GetSizesocketaddr_in(void){				return m_nSizesocketaddr_in;};
	int * GetSizesocketaddr_inPtr(void){		return &m_nSizesocketaddr_in;};
	BYTE GetSessionEnd(void){					return m_bSessionEnd;};			// 2013-03-13 by hskim, �� ĳ�� ���� - RawData ���� ��� �߰�

	// Operations
	// 2008-03-13 by cmkwon, ��Ը� ����� Ŭ���̾�Ʈ �ñ�°� ���� - �����߰�(SSendedOverlappedInfo *o_pSendedOverInfo)
	BOOL AddData(SSendedOverlappedInfo *o_pSendedOverInfo, BYTE* pData, int nSize);					// COverlapped Ŭ������ ���� ���ۿ� ����Ÿ�� �߰��Ѵ�.
	int GetDataSize(void);									// COverlapped Ŭ������ ���� ���ۿ� �߰��� ����Ÿ�� ����� ����
	void ResetOverlapped(void);								// COverlapped Ŭ������ �ʱ�ȭ �Ѵ�.
	void EncodePacket(BYTE seq);							// m_bEncodingFlag �� TRUE�̰� m_bEncodedFlag �� FALSE�϶� Encoding�� �Ѵ�.
	void SetSequenceNumber(BYTE seq);						// m_bEncodingFlag �� FALSE�϶� Sequence Number �� �����Ѵ�.
	BYTE GetSequenceNumber();								// m_bEncodingFlag �� TRUE�̰� m_bEncodedFlag �� TRUE�϶� ��Ŷ�� ������ Sequence Number
															// m_bEncodingFlag �� FALSE�϶� ��Ŷ�� ������ Sequence Number
	BOOL IsPacketEncoded();									// ��Ŷ�� Encoding �Ǿ������� ���θ� ����

	void SetSessionEnd(BYTE bSessionEnd);					// 2013-03-13 by hskim, �� ĳ�� ���� - RawData ���� ��� �߰�

	///////////////////////////////////////////////////////////////////////////
	// new, delete �� �������̵��Ѵ�.
	void * operator new(size_t size);
	void operator delete(void* p);
	
private:	
	BYTE				m_enOperationMode;					// Read Or Write Mode ����
	BYTE				m_enOverlappedType;					// Overlapped ��ü�� Static or Dynamic Type ����
	BYTE				m_bEncodingFlag;					// COverlapped �� Encoding �� ���� �������� Flag
	BYTE				m_bEncodedFlag;						// COverlapped �� Encoding �Ǿ������� Flag
	WSABUF				m_WSABUF;							// ReadFile and WriteFile ����	
	char				lpBuff[SIZE_MAX_SOCKET_BUFFER];		// Data Buffer
	sockaddr_in			m_socketaddr_in;					// UDP ������ ���� ����(����� �ּҸ� ����)
	int					m_nSizesocketaddr_in;				// UDP ������ ���� ����(socketaddr ������)

	BYTE				m_enDataType;						// Date Type (Raw / Game Packet Type ����)	- // 2013-03-13 by hskim, �� ĳ�� ���� - RawData ���� ��� �߰�
	BYTE				m_bSessionEnd;						// ������ ���� �� ���� ���� ����			- // 2013-03-13 by hskim, �� ĳ�� ���� - RawData ���� ��� �߰�

	///////////////////////////////////////////////////////////////////////////
	// static ��� ����
	static char*		pXOR_ENCODE_BYTES;	
};
#endif // _OVERLAPPED_H_endif
