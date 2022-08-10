// SkillEffect.h: interface for the CSkillEffect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKILLEFFECT_H__F52F0042_5CFE_4989_A33C_150E79ED7264__INCLUDED_)
#define AFX_SKILLEFFECT_H__F52F0042_5CFE_4989_A33C_150E79ED7264__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "stdafx.h"

class CUnitData;
class CCharacterInfo;

typedef struct {
	int					nSkillNum;			// ��ų ��ȣ
	CCharacterInfo*		pCharacterInfo;		// ��ų ����Ʈ
} SkillEffectInfo;

class CSkillEffect  
{
public:
	CSkillEffect(CUnitData* pParent);
	virtual ~CSkillEffect();
	virtual	HRESULT		InitDeviceObjects();
	virtual HRESULT		RestoreDeviceObjects();
	virtual HRESULT		InvalidateDeviceObjects();
	virtual HRESULT		DeleteDeviceObjects();
	void				Tick(float fElapsedTime);
	void				CreateSkillEffect(int nSkillNum, BodyCond_t hySingleBodyCondition);
	void				DeleteSkillEffect(int nSKillNum);
	void				ChangeBodyCondition(int nSkillNum, BodyCond_t hySingleBodyCondition);
	void				SetBodyConditionMatrix(BodyCond_t hySingleBodyCondition, D3DXMATRIX mat);
	CCharacterInfo*		FindSkillEffect(int nSkillNum);
	void				DeleteCastingStateSkillEffect();
	void				DeleteChargingStateSkillEffect();

	// 2009. 09. 21 by ckPark ���Ǵ�Ƽ �ʵ� ���� ��ų ����
	void				DeleteCastingStateMonsterSkillEffect( void );
	// end 2009. 09. 21 by ckPark ���Ǵ�Ƽ �ʵ� ���� ��ų ����

	BOOL				CheckTargetSkillEffect(INT ItemNum);

public:
	vector<SkillEffectInfo>		m_vecSkillEffect;		// ��ų����Ʈ

protected:
	CUnitData *					m_pParent;				
	
};

#endif // !defined(AFX_SKILLEFFECT_H__F52F0042_5CFE_4989_A33C_150E79ED7264__INCLUDED_)