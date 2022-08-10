// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_)
#define AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#define _WIN32_WINNT 0x0501

// Windows Header Files:
// #include <windows.h>
#include <afxwin.h>
#include <Afxdisp.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <assert.h>

// Local Header Files
#pragma warning(disable:4786)
#include <Winbase.h>
#include <winsock2.h>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
#include <functional>


#include "DbgOut_Field.h"
#include "mt_stl.h"

#include "DefineGlobal.h"
#include "GlobalGameServer.h"
#include "AtumProtocol.h"
#include "AtumError.h"					// 2006-09-25 by cmkwon
#include "StringDefineQuery.h"			// 2008-07-02 by cmkwon, MySQL ���� ���� - 
#include "StringDefineProcedure.h"	// 2008-08-22 by cmkwon, MySQL ����(Procedure �̾Ƴ���) - 


using namespace std;


typedef mt_vector<ITEM*>					mtvectorItemPtr;
typedef mt_vector<MSG_SIGN_BOARD_STRING>	mtvectMSG_SIGN_BOARD_STRINGList;		// 2006-04-17 by cmkwon

struct MONSTER_DROP_ITEM_GENERAL
{
	ITEM_GENERAL	*pItemGeneral;
	INT				QuestIndex;
};
typedef list<MONSTER_DROP_ITEM_GENERAL>		listMonsterDropItem;					// 2006-07-13 by cmkwon
typedef vector<UID64_t>						vectUID64_t;							// 2006-07-26 by cmkwon

// start 2012-02-13 by hskim, ���� ������ ��� �׽�Ʈ ��ɾ�
struct MONSTER_DROP_ITEM_TEST_INFO
{
	INT				ItemNum;
	UINT64			CurrentCount;
};
typedef map<INT, MONSTER_DROP_ITEM_TEST_INFO>		mapMonsterDropItemTest;
typedef vector<MONSTER_DROP_ITEM_TEST_INFO>	vectorMonsterDropItemTest;

struct Sort_MonsterDropItemTestInfo_by_CurrentCount
{
	bool operator()(MONSTER_DROP_ITEM_TEST_INFO op1, MONSTER_DROP_ITEM_TEST_INFO op2)
	{
		return op1.CurrentCount > op2.CurrentCount;		// �������� ����
	}
};
// end 2012-02-13 by hskim, ���� ������ ��� �׽�Ʈ ��ɾ�

typedef mt_vector<FC_CONNECT_LOGIN_INFO>	mtvectFC_CONNECT_LOGIN_INFO;

typedef vector<ITEM_GENERAL*>				vectITEM_GENERALPtr;					// 2006-09-25 by cmkwon

typedef vector<ENCHANT>						vectENCHANT;							// 2006-09-25 by cmkwon
typedef mt_map<UID64_t, vectENCHANT>		mtmapUID2EnchantVector;					// 2006-09-25 by cmkwon
typedef map<UID64_t, vectENCHANT>			mapUID2EnchantVector;					// 2006-09-25 by cmkwon


// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_)
