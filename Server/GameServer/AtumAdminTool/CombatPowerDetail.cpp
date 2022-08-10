// CombatPowerDetail.cpp : implementation file
//

#include "stdafx.h"
#include "atumadmintool.h"
#include "CombatPowerDetail.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCombatPowerDetail dialog


CCombatPowerDetail::CCombatPowerDetail(std::vector<CCombatPower> *ani,std::vector<CCombatPower> *bcu,CWnd* pParent /*=NULL*/)
	: CDialog(CCombatPowerDetail::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCombatPowerDetail)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_ani = *ani;
	m_bcu = *bcu;
}


void CCombatPowerDetail::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCombatPowerDetail)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_GridControl(pDX, IDC_GRID_ANI, m_GridANI);
	DDX_GridControl(pDX, IDC_GRID_BCU, m_GridBCU);
}


BEGIN_MESSAGE_MAP(CCombatPowerDetail, CDialog)
	//{{AFX_MSG_MAP(CCombatPowerDetail)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCombatPowerDetail message handlers


void CCombatPowerDetail::InitGrid(void)
{	
	const char *arrColName[] = {"Date", "ANI Point"};
	m_GridANI.InitGrid(2, arrColName);
	m_GridANI.SetEditable(FALSE);
	const char *arrColName2[] = {"Date", "BCU Point"};
	m_GridBCU.InitGrid(2, arrColName2);
	m_GridBCU.SetEditable(FALSE);
	m_GridBCU.SetSingleRowSelection(FALSE);
	m_GridANI.SetSingleRowSelection(FALSE);
}
BOOL CCombatPowerDetail::OnInitDialog() 
{
	CDialog::OnInitDialog();
	InitGrid();
	auto itr = m_ani.begin();
	for(itr=m_ani.begin();itr!=m_ani.end();++itr)
	{
		m_GridANI.SetRowCount(m_GridANI.GetRowCount()+1);
		GV_ITEM Item;
		Item.mask = GVIF_TEXT|GVIF_FORMAT;
		Item.row = m_GridANI.GetRowCount()-1;
		Item.nFormat = GRID_CELL_FORMAT;
		
		int nColIndex = 0;	
		Item.col = nColIndex++;
		Item.strText.Format("%04u-%02u-%02u",itr->date.year,itr->date.month,itr->date.day);
		m_GridANI.SetItem(&Item);
		
		Item.col = nColIndex++;
		Item.strText.Format("%d",itr->ANI);
		m_GridANI.SetItem(&Item);
	}
	for(itr=m_bcu.begin();itr!=m_bcu.end();++itr)
	{
		m_GridBCU.SetRowCount(m_GridBCU.GetRowCount()+1);
		GV_ITEM Item;
		Item.mask = GVIF_TEXT|GVIF_FORMAT;
		Item.row = m_GridBCU.GetRowCount()-1;
		Item.nFormat = GRID_CELL_FORMAT;
		
		int nColIndex = 0;	
		Item.col = nColIndex++;
		Item.strText.Format("%04u-%02u-%02u",itr->date.year,itr->date.month,itr->date.day);
		m_GridBCU.SetItem(&Item);
		
		Item.col = nColIndex++;
		Item.strText.Format("%d",itr->BCU);
		m_GridBCU.SetItem(&Item);
	}
	return TRUE;
}
