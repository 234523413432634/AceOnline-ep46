// INFBaseWarManager.h: interface for the CINFBaseWarManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFBASEWARMANAGER_H__DA19B9C9_2BC8_4862_AE32_A240485F1DA4__INCLUDED_)
#define AFX_INFBASEWARMANAGER_H__DA19B9C9_2BC8_4862_AE32_A240485F1DA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "INFBase.h"
#include "INFImageBtn.h"
#include "INFImageBtnBoth.h"
#include "INFImportantInfo.h"
#include "INFNumEditBox.h"
#include "INFGroupImage.h"

#define SLIDE_TIME						0.25f

#define BASEWAR_INFO_BALON			9		// 정보창 테두리
//  최대 글씨 라인 수
#define	BASEWAR_MAXLINE				6
//#define	BASEWAR_INFLUENCE_LINE		3

enum {BASEHIDE, BASESHOW};

struct ShowToolTipInfo
{
	POINT pMousePos;
	char sMapName[256];
	char sTime[128];
};

enum INFLSTATE{INFLNONE, INFLBCU, INFLANI, INFLBCUANI, INFLANIBCU};

typedef vector<CINFImportantInfo*>							vecINFImportantInfo;
typedef vector<CINFImportantInfo*>::iterator				vecINFImportantInfoIter;

class CINFImage;
class CD3DHanFont;

class CINFBaseWarManager : public CINFBase  
{
public:
	CINFBaseWarManager();
	virtual ~CINFBaseWarManager();
	CINFBaseWarManager(CGameData * pData);

	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();
	virtual void	Render();
	virtual void	Tick();

	void AdventBaseBCU(SMSWARINFO_DISPLAY * pInfo);
	void AdventBaseAHI(SMSWARINFO_DISPLAY * pInfo);
	void AdventBaseNGC(MSG_NGCSPWAR_DISPLAY * pInfo, BOOL bPopUp);

	void RenderBaseInfo();

	BOOL SetBaseWarPointMapInfo(SMSWARINFO_DISPLAY * pWarInfo);

	SIZE GetStringSize(char* pTxt);
	SIZE GetBaseInfoFontWidth();

	BOOL SetButtonPos0(UINT i_nPosX,UINT i_nPosY);
	BOOL SetButtonPos1(UINT i_nPosX,UINT i_nPosY);
	BOOL SetButtonPos2(UINT i_nPosX,UINT i_nPosY);

	void RenderBaseWarInfoBalon(int x, int y, int cx, int cy);
/////////////////////////////////////////////////////////////////////////////////////
	USHORT SetBaseOption(USHORT i_Option = 0x00F0);
	int WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SendBaseShipOption();

	int GetInfluenceState(){return m_nInfluenceState;};
	void SetInfluenceState(int nInfluence){m_nInfluenceState = nInfluence;}

	void AddBaseInfo(MapIndex_t	MapIndex, float fSummonLiveTime, short MapInfluenceType);

	void ShowBaseWarToolTipInfo(POINT pt, DWORD	nMapNum, float fSummonLiveTime);
	void RenderBaseWarToolTip();

	void DestroyBaseWarInfo(MapIndex_t MapIndex, SHORT MapInfluenceType);

	void RenderTimeLimit();

	void TimeSetting(float fTime);
	
	void RenderInflGauge();			// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)

	BOOL GetNGCWarState(){return m_bNGCbaseWar;}

	BOOL FindBaseWarMapIdx(MapIndex_t i_MapIndex , BOOL bCurrent = FALSE);	//0이면 기본 , 1이면 현재 진행중);	// 2014-03-11 by ssjung&ymjoo 월드맵 구현

	CINFImageBtnBoth*		m_pImgBaseWarBCUButton;
	CINFImageBtnBoth*		m_pImgBaseWarANIButton;
	CINFImageBtnBoth*		m_pImgBaseWarNGCButton;
	
	DWORD					m_nButtonState0;
	DWORD					m_nButtonState1;
	DWORD					m_nButtonState2;
	
	USHORT					m_nOption;						// 옵션.
	
	DWORD					m_nShowNum0;
	DWORD					m_nShowNum1;
			
	float					m_fShowTime;
	
	BOOL					m_bShow0;
	BOOL					m_bShow1;
	BOOL					m_bShow2;
	
	DWORD					m_nButtonPosX0;
	DWORD					m_nButtonPosY0;
	DWORD					m_nButtonPosX1;
	DWORD					m_nButtonPosY1;
	DWORD					m_nButtonPosX2;
	DWORD					m_nButtonPosY2;

	
// 	//--------------------------------------------------------------------------//
	
	CINFImageEx	*					m_pBalonChat[BASEWAR_INFO_BALON];

	vecINFImportantInfo				m_vecImportBCU;
	vecINFImportantInfo				m_vecImportANI;
	vecINFImportantInfo				m_vecImportNGC;

	vecINFImportantInfo				m_vecImportStateBCU;
	vecINFImportantInfo				m_vecImportStateANI;
	vecINFImportantInfo				m_vecImportStateNGC;

	SIZE							m_sizeBaseInfo;

	// 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)
#ifdef C_DRAWTEXT_UPGRADE_YMJOO
	CD3DHanFont*					m_pFontBaseInfo[BASEWAR_MAXLINE][7];
#else
	CD3DHanFont*					m_pFontBaseInfo[BASEWAR_MAXLINE];
#endif
	// END 2014-06-30 by ymjoo DrawText 성능 개선 작업 (거점전)

	INT								m_nInfluenceState;
	char							m_sInfluence[2][256];

	BOOL							m_bShowToolTip;

	ShowToolTipInfo*				m_strShowToolTipInfo;
	CD3DHanFont*					m_pFontPToolTip[2];


	UINT							m_nMin, m_nSec;

	CINFImageEx*					m_pTimeNumImage[ 10 ];		// 숫자 이미지
	
	CINFImageEx*					m_pColonImage;				// 콜론

	BOOL							m_bShowTimeImage;

	// 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
	BOOL							m_bNGCbaseWar;

	CINFImageEx*		m_pImgResetBarBack;								// 리셋바 배경.
	CINFImageEx*		m_pImgResetBarBar1;								// 리셋바1(빨강:공격)
	CINFImageEx*		m_pImgResetBarBar2;								// 리셋바2(파랑:방어)
	CINFImageEx*		m_pImgResetBarInf1;								// 리셋바세력 1.(바이제니유)
	CINFImageEx*		m_pImgResetBarInf2;								// 리셋바세력 2.(알링턴)

	float				m_fBarScale;
	BOOL				m_bBarRender;			//NGC거점 초기에  바 관련 초기 셋팅
	BYTE				m_enumNgcState;

	// end 2013-08-28 by ssjung 거점전 리뉴얼(NGC)
};

#endif // !defined(AFX_INFBASEWARMANAGER_H__DA19B9C9_2BC8_4862_AE32_A240485F1DA4__INCLUDED_)
