// VDGlobal.h: interface for the CVDGlobal class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VDGLOBAL_H__00B90D44_963E_4514_AF6E_AD42AF410E2A__INCLUDED_)
#define AFX_VDGLOBAL_H__00B90D44_963E_4514_AF6E_AD42AF410E2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "VoIPGlobal.h"


class CVDGlobal;
//////////////////////////////////////////////////////////////////////////
// Global Variable
//////////////////////////////////////////////////////////////////////////
extern CVDGlobal		*g_pVDGlobal;		// �������������� ���� ����Ŭ����������

class CVDIOCP;
class CVDGlobal : public CVoIPGlobal  
{
public:
	CVDGlobal();
	virtual ~CVDGlobal();



	///////////////////////////////////////////////////////////////////////////
	// virtual Function	
	virtual BOOL InitServerSocket(void);						// ���ϰ��� �ʱ�ȭ �Լ�
	virtual BOOL EndServerSocket(void);							// ���ϰ��� ���� �Լ�
	virtual BOOL LoadConfiguration(void);						// Server ������ ���� Configuration Load

protected:
	

};

#endif // !defined(AFX_VDGLOBAL_H__00B90D44_963E_4514_AF6E_AD42AF410E2A__INCLUDED_)
