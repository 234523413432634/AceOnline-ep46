// Localization.h: interface for the CLocalization class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOCALIZATION_H__B7B1ED42_2FED_47F5_BD37_A99EF4F3B58C__INCLUDED_)
#define AFX_LOCALIZATION_H__B7B1ED42_2FED_47F5_BD37_A99EF4F3B58C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AtumParam.h"

struct SLOCAL_ti_BuildingNPC
{
	INT		BuildingIndex;
	char	szNPCName[SIZE_MAX_NPC_NAME];
	char	szGreetingTalk[SIZE_MAX_BUILDING_NPC_TALK_STRING];
};
typedef vector<SLOCAL_ti_BuildingNPC>		vectLOCAL_ti_BuildingNPC;

struct SLOCAL_ti_Item
{
	INT		ItemNum;
	char	szItemName[SIZE_MAX_ITEM_NAME];
	char	szDescription[SIZE_MAX_ITEM_DESCRIPTION];
};
typedef vector<SLOCAL_ti_Item>				vectLOCAL_ti_Item;

struct SLOCAL_ti_MapInfo
{
	INT		MapIndex;
	char	szMapName[SIZE_MAX_MAP_NAME];
	char	szDescription[SIZE_MAX_MAP_DESCRIPTION];
};
typedef vector<SLOCAL_ti_MapInfo>			vectLOCAL_ti_MapInfo;

struct SLOCAL_ti_Monster
{
	INT		MonsterUnitKind;
	char	szMonsterName[SIZE_MAX_MONSTER_NAME];
};
typedef vector<SLOCAL_ti_Monster>			vectLOCAL_ti_Monster;

struct SLOCAL_ti_RareItemInfo
{
	INT		RareCodeNum;
	char	szRareName[SIZE_MAX_RARE_FIX_NAME];		// DB���� 12 Bytes�� �Ǿ� ����
};
typedef vector<SLOCAL_ti_RareItemInfo>		vectLOCAL_ti_RareItemInfo;

// 2009-03-03 by dhjin, ��Ű�ӽ� ������
struct SLOCAL_ti_LuckyMachine
{
	INT		MachineNum;
	char	szDescription[SIZE_MAX_LUCKYMACHINE_DESCRIPTION];
};
typedef vector<SLOCAL_ti_LuckyMachine>		vectLOCAL_ti_LuckyMachine;

////////////////////////////////////////////////////////////////////////////////
// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ -
struct SLOCAL_ti_HPAction
{
	INT		HPActionUID;
	char	PreHPTalk[SIZE_MAX_HPTALK_DESCRIPTION];		// 2009-09-09 ~ 2010-02-26 by dhjin, ���Ǵ�Ƽ - *.cfg���� �߰�
	char	HPTalk[SIZE_MAX_HPTALK_DESCRIPTION];
};
typedef vector<SLOCAL_ti_HPAction>		vectLOCAL_ti_HPAction;
struct SLOCAL_ti_Cinema {// 2009-09-09 ~ 2010-02-26 by dhjin, ���Ǵ�Ƽ - *.cfg���� �߰�
	CinemaNum_t			CinemaNum;
	CinemaOrder_t		CinemaOrder;
	MSec_t				EffectStartTime;
	CinemaTalk_t		CinemaTalk[SIZE_MAX_CINEMATALK_DESCRIPTION];
};
typedef vector<SLOCAL_ti_Cinema>		vectLOCAL_ti_Cinema;

// 2010-12-03 by shcho, �� �ý��� ���� ��Ʈ�� ���ø����̼� �߰�
struct SLOCAL_ti_OperatorInfo
{	// ���۷����� ����.
	INT		Itemnum;
	INT		FunctionIndex;
	char	ActionDesc[SIZE_MAX_PET_OPERATOR_DESCRIPTION]; 
};
typedef vector<SLOCAL_ti_OperatorInfo>		vectLOCAL_ti_OperatorInfo;
// END 2010-12-03 by shcho, �� �ý��� ���� ��Ʈ�� ���ø����̼� �߰�


class CLocalization  
{
public:
	CLocalization();
	~CLocalization();

	void ResetLocalization(void);

	BOOL IsKoreanLanguageType(void);
	BOOL LoadConfiguration(char *i_szLocalizationFilePath, int i_nReqLanguage);

	BOOL BuildingNPCLocalization(INT i_BuindingIndex, char *o_szNPCName, char *o_szGreetingTalk);
	BOOL ItemLocalization(INT i_ItemNum, char *o_szItemName, char *o_szDescription=NULL);
	BOOL MapInfoLocalization(INT i_MapIndex, char *o_szMapName, char *o_szMapDescription=NULL);		// 2009-09-09 ~ 2010-02-26 by dhjin, ���Ǵ�Ƽ - *.cfg���� �߰�
	BOOL MonsterLocalization(INT i_MonsterUnitKind, char *o_szMonsterName);
	BOOL RareItemInfoLocalization(INT i_RareCodeNum, char *o_szRareName);
	BOOL LuckyMachineLocalization(INT i_MachineNum, char *o_szDescription=NULL);	// 2009-03-03 by dhjin, ��Ű�ӽ� ������
	BOOL HPActionLocalization(INT i_HPActionUID, char *o_szPreHPTalk=NULL, char *o_szHPTalk=NULL);	// 2009-09-09 ~ 2010-02-26 by dhjin, ���Ǵ�Ƽ - *.cfg���� �߰� // 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ -
	BOOL CinemaLocalization(CinemaNum_t i_CinemaNum, CinemaOrder_t i_CinemaOrder, MSec_t i_StartTime, char *o_szCinemaTalk=NULL);	// 2009-09-09 ~ 2010-02-26 by dhjin, ���Ǵ�Ƽ - *.cfg���� �߰�
	// 2010-12-03 by shcho, �� �ý��� ���� ��Ʈ�� ���ø����̼� �߰�
	BOOL PetOperatorActionInfoLocalization(INT i_nItemNum, INT functionIndex, char* o_szActionDesc);
	// END 2010-12-03 by shcho, �� �ý��� ���� ��Ʈ�� ���ø����̼� �߰�

protected:
	BOOL LoadBuildingNPC(char *i_szFileFullPath);
	BOOL LoadItem(char *i_szFileFullPath);
	BOOL LoadMapInfo(char *i_szFileFullPath);
	BOOL LoadMonster(char *i_szFileFullPath);
	BOOL LoadRareItemInfo(char *i_szFileFullPath);
	BOOL LoadLuckyMachine(char *i_szFileFullPath);	// 2009-03-03 by dhjin, ��Ű�ӽ� ������
	BOOL LoadHPAction(char *i_szFileFullPath);		// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ -
	BOOL LoadCinema(char *i_szFileFullPath);		// 2009-09-09 ~ 2010-02-26 by dhjin, ���Ǵ�Ƽ - *.cfg���� �߰�
	// 2010-12-03 by shcho, �� �ý��� ���� ��Ʈ�� ���ø����̼� �߰�
	BOOL LoadPetOperatorActionInfo(char *i_szFileFullPath);
	// END 2010-12-03 by shcho, �� �ý��� ���� ��Ʈ�� ���ø����̼� �߰�

	SLOCAL_ti_BuildingNPC * FindBuildingNPC(INT i_nBuildingIndex);
	SLOCAL_ti_Item * FindItem(INT i_nItemNum);
	SLOCAL_ti_MapInfo * FindMapInfo(INT i_nMapIndex);
	SLOCAL_ti_Monster * FindMonster(INT i_nMonsterUnitKind);
	SLOCAL_ti_RareItemInfo * FindRareItemInfo(INT i_nRareCodeNum);
	SLOCAL_ti_LuckyMachine * FindLuckyMachine(INT i_nMachineNum);	// 2009-03-03 by dhjin, ��Ű�ӽ� ������
	SLOCAL_ti_HPAction * FindHPAction(INT i_HPActionUID);	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ -
	SLOCAL_ti_Cinema * FindCinema(CinemaNum_t i_CinemaNum, CinemaOrder_t i_CinemaOrder, MSec_t i_StartTime);	// 2009-09-09 ~ 2010-02-26 by dhjin, ���Ǵ�Ƽ - *.cfg���� �߰�
	// 2010-12-03 by shcho, �� �ý��� ���� ��Ʈ�� ���ø����̼� �߰�
	SLOCAL_ti_OperatorInfo * FindOperatorAction(INT i_nItemNum, INT functionIndex);
	// END 2010-12-03 by shcho, �� �ý��� ���� ��Ʈ�� ���ø����̼� �߰�
public:
	int							m_nLoadLanguageType;
	vectLOCAL_ti_BuildingNPC	m_vectLocalBuildingNPC;
	vectLOCAL_ti_Item			m_vectLocalItem;
	vectLOCAL_ti_MapInfo		m_vectLocalMapInfo;
	vectLOCAL_ti_Monster		m_vectLocalMonster;
	vectLOCAL_ti_RareItemInfo	m_vectLocalRareItemInfo;
	vectLOCAL_ti_LuckyMachine	m_vectLocalLuckyMachine;	// 2009-03-03 by dhjin, ��Ű�ӽ� ������
	vectLOCAL_ti_HPAction		m_vectLocalHPAction;	// 2009-09-09 ~ 2010 by dhjin, ���Ǵ�Ƽ -
	vectLOCAL_ti_Cinema			m_vectLocalCinema;		// 2009-09-09 ~ 2010-02-26 by dhjin, ���Ǵ�Ƽ - *.cfg���� �߰�
	// 2010-12-03 by shcho, �� �ý��� ���� ��Ʈ�� ���ø����̼� �߰�
	vectLOCAL_ti_OperatorInfo	m_vectLocalOperatorInfo;
	// END 2010-12-03 by shcho, �� �ý��� ���� ��Ʈ�� ���ø����̼� �߰�
};

#endif // !defined(AFX_LOCALIZATION_H__B7B1ED42_2FED_47F5_BD37_A99EF4F3B58C__INCLUDED_)

