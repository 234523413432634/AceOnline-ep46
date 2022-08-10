///////////////////////////////////////////////////////////////////////////////
//  DefineGlobal.h : ������Ʈ�� ������� �⺻������ ����Ǵ� #define
//
//  Date	: 2004-03-17 by cmkwon
///////////////////////////////////////////////////////////////////////////////

#ifndef _DEFINE_GLOBAL_H_
#define _DEFINE_GLOBAL_H_

#include "DebugAssert.h"
#include <math.h>
#include <process.h>

///////////////////////////////////////////////////////////////////////////////
/// �������� ����� ���� ���, c++ code�μ��� �ǹ̴� ����
#define ARRAY_(x)			/// x�� n�� �ִ� ��
#define _ARRAY(x)			/// x�� n�� �ִ� ��
#define STRUCT_(x)			/// x��� struct �ϳ�

#define LODWORD(ll)			((DWORD)(ll))
#define HIDWORD(ll)			((DWORD)(((UINT64)(ll) >> 32) & 0xFFFFFFFF))

// RAND_MAX�� 0x7FFF�̹Ƿ� �� �̻��� �ʿ��� ���� �̳��� ����ϱ�, 20040708, kelovon
inline int rand32()
{
	int i1, i2, i3;
	i1 = rand()&0x0FFF;
	i2 = (rand()&0x0FFF) << 12;
	i3 = (rand()&0x007F) << 24;
	return (i1|i2|i3);
}

#define RANDF1(min, max)	((float)((min)*10 + (rand32() % (int)(((max)-(min)+0.1)*10)))/10)		// float, �Ҽ��� ���� 1�ڸ�, (min) ~ (max), [min, max], ����: max�� ���Ե�
#define RANDF2(min, max)	((float)((min)*100 + (rand32() % (int)(((max)-(min)+0.01)*100)))/100)	// float, �Ҽ��� ���� 2�ڸ�, (min) ~ (max), [min, max], ����: max�� ���Ե�
#define RANDI(min, max)		((min) + (rand32() % ((max)-(min)+1)))			// int, (min) ~ (max), [min, max], ����: max�� ���Ե�
#define RAND100()			(rand32() % 100)								// int, 0 ~ 99
#define RAND1000()			(rand32() % 1000)								// int, 0 ~ 999
#define RAND10K()			(rand32() % 10000)								// int, 0 ~ 9999
#define RAND100K()			(rand32() % 100000)								// int, 0 ~ 99999
#define RAND1000K()			(rand32() % 1000000)							// int, 0 ~ 999999
#define RAND256()			(rand32() % 256)								// int, 0 ~ 255

#define IS_IN_RANGE(_MIN, _VALUE, _MAX)		((_MIN) <= (_VALUE) && (_MAX) >= (_VALUE))

#define LENGTH(_X, _Y)						sqrt((double)((_X)*(_X)+(_Y)*(_Y)))

#define MAX_INT64_VALUE			((INT64)0x7FFFFFFFFFFFFFFF)
#define MAX_UINT64_VALUE		((UINT64)0xFFFFFFFFFFFFFFFF)
#define MAX_INT_VALUE			((INT)0x7FFFFFFF)
#define MAX_UINT_VALUE			((UINT)0x7FFFFFFF)
#define MAX_SHORT_VALUE			((SHORT)0x7FFF)
#define MAX_USHORT_VALUE		((USHORT)0xFFFF)
#define MAX_BYTE_VALUE			((BYTE)0x7F)
#define MAX_RAND100_VALUE		99				// int, 0 ~ 99
#define MAX_RAND1000_VALUE		999				// int, 0 ~ 999
#define MAX_RAND10K_VALUE		9999			// int, 0 ~ 9999
#define MAX_RAND100K_VALUE		99999			// int, 0 ~ 99999
#define MAX_RAND1000K_VALUE		999999			// int, 0 ~ 999999
#define MAX_RAND256_VALUE		255				// int, 0 ~ 255

// 2012-10-10 by jhjang ���� �ƿ� ����ġ ���ʽ� �ý��� ������
#define BONUS_EXP_RATE_PARTY_COUNT				0.1f
#define BONUS_EXP_RATE_PARTY_DEFAULT			1.2f
// end 2012-10-10 by jhjang ���� �ƿ� ����ġ ���ʽ� �ý��� ������

#define SAFE_DELETE(p) { if(NULL != p){ delete (p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p) { if(NULL != p){ delete[] (p); (p) = NULL;}}
#define SAFE_DELETE_DESTROY(p) { if(NULL != p) { p->Destroy(); delete (p); (p) = NULL; }}
#define IS_VALID_ARRAY_INDEX(idx, ArraySize) (((idx) >= 0) && ((idx) < (ArraySize)))
#define MEMSET_ZERO(p, Size) (memset((p), 0x00, (Size)))

///////////////////////////////////////////////////////////////////////////////
// 2006-05-24 by cmkwon, szDest�� �ʱ�ȭ �ϰ� �����Ѵ�.
#define STRNCPY_MEMSET(szDest, szSource, MaxSize)		{ MEMSET_ZERO((szDest), (MaxSize));	\
														  strncpy( (szDest), (szSource), (MaxSize)-1 );}

#define GET_CASERETURN_STRING_BY_TYPE(str)	case str:		return #str ""


struct Delete_Object
{
	template<typename T>
		void operator()(T *ptr)
	{
		delete ptr;
	}
};

struct Delete_Object_MAP
{
	template<typename T>
		void operator()(T ptr)
	{
		delete ptr.second;
	}
};


#ifndef chBEGINTHREADEX
typedef unsigned (__stdcall *PTHREAD_START) (void *);

#define chBEGINTHREADEX(psa, cbStack, pfnStartAddr, \
   pvParam, fdwCreate, pdwThreadID)                 \
      ((HANDLE) _beginthreadex(                     \
         (void *) (psa),                            \
         (unsigned) (cbStack),                      \
         (PTHREAD_START) (pfnStartAddr),            \
         (void *) (pvParam),                        \
         (unsigned) (fdwCreate),                    \
         (unsigned *) (pdwThreadID)))
#endif

#endif	// _DEFINE_GLOBAL_H_endif