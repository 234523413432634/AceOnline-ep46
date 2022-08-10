//#if !defined(AFX_LOGTABITEM_H__ED975BD4_DFE3_496F_873C_1F71A1A60960__INCLUDED_)
//#define AFX_LOGTABITEM_H__ED975BD4_DFE3_496F_873C_1F71A1A60960__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogTabItem.h : header file
//
#include "SCGridHelper.h"
#include "mt_stl.h"

#define SIZE_MAX_MARKET_TRADE_CENTER_GRID_COUNT		12		// �ŷ��� �׸��� �÷� ī��Ʈ

struct MARKET_INFO_LOG_DATA	 // �ŷ��� ��� ������ ����  ����� 
{
	UID64_t			TransactionNum;		// �ŷ��� ������ȣ								TransactionNum
	BYTE			LogType;			// �����ۿ� ���� �ŷ��� ����					TradeStatus
	char			CharacterName[SIZE_MAX_CHARACTER_NAME];		// ����(ĳ����) �̸�			
	UID32_t			CharacterUID;		// ������ ĳ���� UID							SellerCharUID
	ATUM_DATE_TIME	DateTime;			// �ŷ��� ��Ͻð�								RegistrationTime
	BYTE			influence;			
	INT				Price;				// �Ǹűݾ�										Price
	BYTE			MoneyType;			// ȭ�� Ÿ��(0=SPI, 1=WP)						TypeOfMoney
	ItemNum_t		ItemCount;			// �Ǹ� ����(������ ��� �Ѿ� ����)				Count
	UID64_t			ItemUID;			// ������ ������ȣ								SellingItemUID
	ItemNum_t		ItemNum;			// ������ ��ȣ									ItemNum
	BYTE			ItemKind;			// ������ ����									TradeItemKind	
	char			ItemName[MARKET_ITEM_FULL_NAME];	// ������ �̸�(����, ���� ����)	ItemName
	ItemNum_t		PrefixCodeNum;		// ���� �ɼ�(������ 0)							PrefixCodeNum			
	ItemNum_t		SuffixCodeNum;		// ���� �ɼ�(������ 0)							SuffixCodeNum
	BYTE			EnchantCount;		// ��þƮ ��(������ 0)							EnchantCount
		
	MARKET_INFO_LOG_DATA()
	{
		MEMSET_ZERO(this, sizeof(MARKET_INFO_LOG_DATA));
	}
	MARKET_INFO_LOG_DATA(MARKET_INFO_LOG_DATA *i_pMarket)
	{
		MEMSET_ZERO(this, sizeof(MARKET_INFO_LOG_DATA));
		memcpy(this, i_pMarket, sizeof(MARKET_INFO_LOG_DATA));
	}
};

typedef vector<MARKET_INFO_LOG_DATA>	vect_MARKET_INFO_LOG_DATA;
typedef vector<MARKET_INFO_LOG_DATA>::iterator	MARKET_INFO_LOG_DATA_ITR;

class CSCLogAdminDlg;
class CODBCStatement;

/////////////////////////////////////////////////////////////////////////////
// CMarketTabTradeCenter dialog

class CMarketTabTradeCenter : public CDialog		// �ŷ��� �� ��Ʈ�� 
{
// Construction
public:
	CMarketTabTradeCenter(CDialog *i_pMainDlg, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogTabItem)
	enum { IDD = IDD_MARKET_TAB_TRADE };	

	//Search Condition
	BOOL		m_bCheckDate;		//�Ⱓ���� 
	CTime		m_dateStart;
	CTime		m_dateEnd;
	CTime		m_timeEnd;
	CTime		m_timeStart;

	BOOL		m_bCheckInfluence;		// ���� ���� 
	CComboBox	m_comboInfluence;
	BYTE		m_InfluenceType;	
	BOOL		m_bCheckCharacterName;	// �ɸ��� �̸� 
	CString		m_szCharacterName;
	BOOL		m_bCheckCharacterUID;	// �ɸ��� UID
	UID32_t		m_nCharacterUID;
	BOOL		m_bCheckItemUID;		// ������ UID
	int			m_ItemUID;
	BOOL		m_bCheckItemNum;		// ������ Num
	ItemNum_t	m_ItemNum;

	BOOL		m_bCheckMaxLogCount;
	int			m_MaxLogCount;
	
	// kind of log
	BOOL	m_bCheckBuyItem;		
	BOOL	m_bCheckSellItem;
	BOOL	m_bCheckCancelTrade;
	BOOL	m_bCheckGetExchange;
	BOOL	m_bCheckUseSPI;		// money type
	BOOL	m_bCheckUseWP;

	CEdit	m_EditTotalLogRowCount;

	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogTabItem)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	
	CGridCtrl			m_GridTradeMarket;
	//CSCMarketLogDlg		*m_pMainDlg;
	CSCLogAdminDlg		*m_pMainDlg;
	
	CODBCStatement		*m_pODBCStmt;

	void ResetVariables();
	INT _AddMarketLogData(CGridCtrl *i_pGridCtrl, MARKET_INFO_LOG_DATA *i_pMarketLogData);

	vect_MARKET_INFO_LOG_DATA		m_vectMarketInfoLogDataList;
	BOOL DBQueryLoadMarketData(vect_MARKET_INFO_LOG_DATA *o_pVectMarketInfoLogDataList);

	char* GetLogtypeString(BYTE i_logtype);
	char* GetInfluenceString(BYTE i_influence);
	
	void InitGrid(CGridCtrl *i_pGridCtrl);

protected:
	// Generated message map functions
	//{{AFX_MSG(CLogTabItem)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonMarketSelectAll();
	afx_msg void OnButtonMarketRemoveAll();

	afx_msg void OnCheckDate();
	afx_msg void OnCheckInflunence();
	afx_msg void OnCheckCharacterName();
	afx_msg void OnCheckCharacterUID();
	afx_msg void OnCheckItemUID();
	afx_msg void OnCheckItemNum();
	afx_msg void OnCheckMaxRowCount();

	afx_msg void OnButtonMarketSearchOk();
	afx_msg void OnButtonMarketReset();
	afx_msg void OnButtonMarketSaveResult();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

//#endif // !defined(AFX_LOGTABITEM_H__ED975BD4_DFE3_496F_873C_1F71A1A60960__INCLUDED_)

