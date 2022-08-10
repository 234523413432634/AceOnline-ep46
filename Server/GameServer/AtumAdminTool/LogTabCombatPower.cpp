// LogTabCombatPower.cpp : implementation file
//

#include "stdafx.h"
#include "atumadmintool.h"
#include "LogTabCombatPower.h"
#include "CombatPowerDetail.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LogTabCombatPower dialog


CLogTabCombatPower::CLogTabCombatPower(CDialog *i_pMainDlg, CWnd* pParent /*=NULL*/)
	: CDialog(CLogTabCombatPower::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogTabCombatPower)
	//}}AFX_DATA_INIT

	m_pMainDlg		= (CSCLogAdminDlg*)i_pMainDlg;
	m_pODBCStmt		= &m_pMainDlg->m_ODBCStmt;
	
	this->ResetVariables();
}


void CLogTabCombatPower::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogTabCombatPower)
	DDX_Control(pDX, IDC_DATETIMEPICKER_START_DATE, m_StartDate);
	DDX_Control(pDX, IDC_DATETIMEPICKER_END_DATE, m_EndDate);
	//}}AFX_DATA_MAP
	DDX_GridControl(pDX, IDC_GRID_COMBATPOWER_LOG, m_GridCombatPowerLog);
}


BEGIN_MESSAGE_MAP(CLogTabCombatPower, CDialog)
	//{{AFX_MSG_MAP(CLogTabCombatPower)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BTN_SAVE_RESULT, OnBtnSaveResult)
	ON_BN_CLICKED(IDC_BUTTON_RESET, OnButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_INFO, OnButtonInfo)
	//}}AFX_MSG_MAP
	ON_NOTIFY(NM_DBLCLK, IDC_GRID_COMBATPOWER_LOG, OnGridRClick)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogTabCombatPower message handlers


void CLogTabCombatPower::InitGrid(void)
{
	CSCGridCtrl *pSCGridCtrl = &m_GridCombatPowerLog;
	
	const char *arrColName[] = {"Date", "BCU", "ANI"
								, "Total Point", "BCU Ratio", "ANI Ratio"
								, "Weak Influence", "Buff"};
	pSCGridCtrl->InitGrid(8, arrColName);
	pSCGridCtrl->SetEditable(FALSE);
	m_gridItems.clear();
}

void CLogTabCombatPower::ResetVariables(void)
{	
//	m_EndDate = COleDateTime::GetCurrentTime();
//	m_StartDate = COleDateTime::GetCurrentTime();
}

BOOL CLogTabCombatPower::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		m_pMainDlg->EndDialog(-1);
		return TRUE;
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CLogTabCombatPower::OnInitDialog() 
{
	CDialog::OnInitDialog();

	this->InitGrid();

	return TRUE;
}
struct sort_ANI
{
	bool operator()(CCombatPower op1, CCombatPower op2)
	{
		return op1.ANI > op2.ANI;
	}
};

struct sort_BCU
{
	bool operator()(CCombatPower op1, CCombatPower op2)
	{
		return op1.BCU > op2.BCU;
	}
};

void CLogTabCombatPower::GetDayBuff(CCombatPower & cp,std::vector<CCombatPower> * o_ani,std::vector<CCombatPower> * o_bcu) {
	std::vector<CCombatPower> ani,bcu;

	for(std::vector<CCombatPower>::iterator itr=m_powers.begin();itr!=m_powers.end();++itr)
	{
		int diffdiff = itr->diff - cp.diff;
		if(diffdiff >= 1 && diffdiff <= 14)
		{
			ani.push_back(*itr);
			bcu.push_back(*itr);
		}
	}
	sort(ani.begin(),ani.end(),sort_ANI());
	sort(bcu.begin(),bcu.end(),sort_BCU());

	*o_ani = ani;
	*o_bcu = bcu;
}
void CLogTabCombatPower::InsertGridRow(CCombatPower & cp)
{
	CSCGridCtrl *i_pSCGridCtrl = &m_GridCombatPowerLog;
	i_pSCGridCtrl->SetRowCount(i_pSCGridCtrl->GetRowCount()+1);
	
	GV_ITEM Item;
	Item.mask = GVIF_TEXT|GVIF_FORMAT;
	Item.row = i_pSCGridCtrl->GetRowCount()-1;
	Item.nFormat = GRID_CELL_FORMAT;
	
	int nColIndex = 0;
	
	Item.col = nColIndex++;
	Item.strText.Format("%04u-%02u-%02u",cp.date.year,cp.date.month,cp.date.day);
	i_pSCGridCtrl->SetItem(&Item);
	
	std::vector<CCombatPower> ani,bcu;
	int aniavg=0,bcuavg=0;

	GetDayBuff(cp,&ani,&bcu);
	if(ani.size() > 7)
	{
		ani.erase(ani.begin()+7,ani.end());
	}
	if(bcu.size() > 7)
	{
		bcu.erase(bcu.begin()+7,bcu.end());
	}
	auto itr = ani.begin();
	for(itr=ani.begin();itr!=ani.end();++itr)
	{
		aniavg += itr->ANI;
	}
	if(ani.size()) aniavg /= ani.size();
	else aniavg = 0;

	for(itr=bcu.begin();itr!=bcu.end();++itr)
	{
		bcuavg += itr->BCU;
	}
	if(bcu.size()) bcuavg /= bcu.size();
	else bcuavg = 0;
	int total = aniavg+bcuavg;


	Item.col = nColIndex++;
	Item.strText.Format("%d",bcuavg);
	i_pSCGridCtrl->SetItem(&Item);
	
	Item.col = nColIndex++;
	Item.strText.Format("%d",aniavg);
	i_pSCGridCtrl->SetItem(&Item);
	
	Item.col = nColIndex++;
	Item.strText.Format("%d",aniavg+bcuavg);
	i_pSCGridCtrl->SetItem(&Item);

	Item.col = nColIndex++;
	Item.strText.Format("%d%%", total ? (int)((((double)bcuavg / (double)total)) * 100) : 0 );
	i_pSCGridCtrl->SetItem(&Item);
	Item.col = nColIndex++;
	Item.strText.Format("%d%%", total ? (int)((((double)aniavg / (double)total)) * 100) : 0 );
	i_pSCGridCtrl->SetItem(&Item);
	Item.col = nColIndex++;
	Item.strText.Format("%s", aniavg > bcuavg ? "BCU" : "ANI" );
	i_pSCGridCtrl->SetItem(&Item);
	Item.col = nColIndex++;
	int buff = abs((int)((  (double)(aniavg -bcuavg) / (double)total) * 100));
	buff = max(0,buff-15);
	buff = min(30,buff);
	Item.strText.Format("%d%%", buff);
	i_pSCGridCtrl->SetItem(&Item);
	m_gridItems.push_back(cp);
}


void CLogTabCombatPower::OnButtonOk() 
{
	COleDateTime start1,end1;
	m_StartDate.GetTime(start1);
	m_EndDate.GetTime(end1);
	if(start1 > end1) {
		AfxMessageBox("m_StartDate > m_EndDate");
		return;
	}
	int nReturn=-1;
	SQL_TIMESTAMP_STRUCT start,end;
	MEMSET_ZERO(&start,sizeof(start));
	MEMSET_ZERO(&end,sizeof(end));
	start.year = start1.GetYear();
	start.month = start1.GetMonth();
	start.day = start1.GetDay();
	end.year = end1.GetYear();
	end.month = end1.GetMonth();
	end.day = end1.GetDay();

	this->InitGrid();
	SQLHSTMT hstmt = m_pODBCStmt->GetSTMTHandle();
	SQLINTEGER CB = SQL_NTS;
	SQLBindParameter(hstmt, 1, SQL_PARAM_OUTPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &nReturn, 0,NULL);
	SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_TYPE_TIMESTAMP, SQL_TYPE_TIMESTAMP, 23, 0, &start, 0, NULL);
	SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_TYPE_TIMESTAMP, SQL_TYPE_TIMESTAMP, 23, 0, &end, 0, NULL);
	BOOL bRet = m_pODBCStmt->ExecuteQuery((char*)(PROCEDURE_140425_0001));
	if(FALSE == bRet)
	{
		m_pODBCStmt->FreeStatement();
		AfxMessageBox("Failed to ExecuteQuery");
		return;
	}
	SQLINTEGER arrCB[5] = {SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS,SQL_NTS};
	CCombatPower cp;
	MEMSET_ZERO(&cp, sizeof(cp));
	SQLBindCol(hstmt, 1, SQL_C_DATE, &cp.date, 0, &arrCB[1]);
	SQLBindCol(hstmt, 2, SQL_C_LONG, &cp.diff, 0, &arrCB[2]);
	SQLBindCol(hstmt, 3, SQL_C_LONG, &cp.ANI, 0, &arrCB[3]);
	SQLBindCol(hstmt, 4, SQL_C_LONG, &cp.BCU, 0, &arrCB[4]);
	m_powers.clear();
	while (SQLFetch(hstmt) != SQL_NO_DATA)
	{
		m_powers.push_back(cp);
		MEMSET_ZERO(&cp, sizeof(cp));
	}
	SQLMoreResults(hstmt);
	m_pODBCStmt->FreeStatement();
	if(nReturn < 0) {
		AfxMessageBox("ERROR");
		m_powers.clear();
		return;
	}
	for(std::vector<CCombatPower>::iterator itr=m_powers.begin();itr!=m_powers.end();++itr) {
		if( itr->diff <= nReturn ) InsertGridRow(*itr);
	}
	//m_GridBlockAccountLog.ArrangeGrid();
}

void CLogTabCombatPower::OnBtnSaveResult() 
{	
	int nRowCount = m_GridCombatPowerLog.GetRowCount();
	if(1 == nRowCount)
	{
		MessageBox("No data !!");
		return;
	}
	
	CSystemLogManager resultLog;
	if(FALSE == resultLog.InitLogManger(TRUE, "InfluencePower", "./resultLog/"))
	{
		return;
	}
	
	for(int i=0; i < nRowCount; i++)
	{
		char szResult[2048];
		MEMSET_ZERO(szResult, 2048);
		sprintf(szResult, "%s;%s;%s;%s;%s;%s;%s;%s\r\n",
			m_GridCombatPowerLog.GetItemText(i, 0), m_GridCombatPowerLog.GetItemText(i, 1), m_GridCombatPowerLog.GetItemText(i, 2),
			m_GridCombatPowerLog.GetItemText(i, 3), m_GridCombatPowerLog.GetItemText(i, 4), m_GridCombatPowerLog.GetItemText(i, 5),
			m_GridCombatPowerLog.GetItemText(i, 6), m_GridCombatPowerLog.GetItemText(i, 7));
		resultLog.WriteSystemLog(szResult, FALSE);
	}
	MessageBox("Save success !!");	
}

void CLogTabCombatPower::OnButtonReset() 
{
	this->InitGrid();
	
}

void CLogTabCombatPower::OnButtonInfo() 
{
	CCellID cellID = m_GridCombatPowerLog.GetFocusCell();
	if(0 >= cellID.row)
	{
		return;
	}
	for(std::vector<CCombatPower>::iterator itr=m_powers.begin();itr!=m_powers.end();++itr)
	{
		CString temp;
		temp.Format("%04u-%02u-%02u",itr->date.year,itr->date.month,itr->date.day);	
		if(m_GridCombatPowerLog.GetItemText(cellID.row, 0) == temp) {
			std::vector<CCombatPower> ani,bcu;
			GetDayBuff(*itr,&ani,&bcu);
			CCombatPowerDetail dialog(&ani,&bcu,this);
			dialog.DoModal();
			break;
		}
	}	
}


void CLogTabCombatPower::OnGridRClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
{
	OnButtonInfo();
}