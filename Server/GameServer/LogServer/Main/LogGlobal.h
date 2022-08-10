// LogGlobal.h: interface for the CLogGlobal class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGGLOBAL_H__08391A32_1888_4503_AE1D_79961DF9DDCE__INCLUDED_)
#define AFX_LOGGLOBAL_H__08391A32_1888_4503_AE1D_79961DF9DDCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GLogExecManager.h"		// 2011-12-12 by hskim, GLog 2��

class CLogGlobal;
extern CLogGlobal *					g_pLogGlobal;

///////////////////////////////////////////////////////////////////////////////
/// \class		CLogGlobal
///
/// \brief
/// \author		cmkwon
/// \version
/// \date		2004-03-19 ~ 2004-03-19
/// \warning
///////////////////////////////////////////////////////////////////////////////
class CLogGlobal : public CGlobalGameServer
{
public:
	CLogGlobal();
	virtual ~CLogGlobal();

	virtual BOOL InitServerSocket(void);				// ���ϰ��� �ʱ�ȭ �Լ�
	virtual BOOL EndServerSocket(void);					// ���ϰ��� ���� �Լ�

	virtual BOOL LoadConfiguration(void);				// Server ������ ���� Configuration Load
	virtual BOOL ReLoadConfiguration(void);				// 2013-03-14 by jhseol, �������� ���ε� �� ���� ��� IP����Ʈ�� ����
	
	// 2010-06-01 by shcho, GLogDB ���� -
	char *	GetGamePublisherName(void);
	char	m_szGamePublisherName[SIZE_MAX_GAME_PUBLISHER_NAME];			// 2010-06-01 by shcho, GLogDB ���� -

	BOOL	m_bArenaFieldServerCheck;										// 2011-12-12 by hskim, GLog 2��
	BOOL	IsArenaServer(void)	{ return m_bArenaFieldServerCheck; }	// 2011-12-12 by hskim, GLog 2��

public:
	CGLogExecManager GLogExec;		// 2011-12-12 by hskim, GLog 2��
};

#endif // !defined(AFX_LOGGLOBAL_H__08391A32_1888_4503_AE1D_79961DF9DDCE__INCLUDED_)
