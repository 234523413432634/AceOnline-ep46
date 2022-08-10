// INFTradeItemAdd.cpp: implementation of the CINFTradeItemAdd class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "INFGameMain.h"
#include "INFCityBase.h"
#include "AtumDatabase.h"
#include "ShuttleChild.h"
#include "INFWindow.h"
#include "ItemInfo.h"
#include "INFGroupManager.h"
#include "INFGroupImage.h"
#include "INFToolTip.h"
#include "INFListBox.h"
#include "INFIcon.h"
#include "INFInvenExtend.h"
#include "StoreData.h"
#include "INFNumEditBox.h"
#include "INFTradeItemCenter.h"
#include "INFTradeItemAdd.h"
// 2014-06-17 거래소 추가작업 (주석 처리)
//#include "AtumApplication.h"
//#include "GameDataLast.h"
//#include "INFImage.h"
//#include "D3DHanFont.h"
//#include "Chat.h"
//#include "CharacterChild.h"
//#include "AtumSound.h"
//#include "Interface.h"
//#include "INFEditBox.h"
//#include "INFAutoEditBox.h"
//#include "INFImageBtn.h"
//#include "INFArenaScrollBar.h"
//#include "INFItemInfo.h"
//#include "INFCityLab.h"
// END 2014-06-17 거래소 추가작업 (주석 처리)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// 창 크기
#define TRADEITEMBUY_WIDTH					936
#define	TRADEITEMBUY_HEIGHT					642

// 거래소 창 (그룹)
#define BACKIMAGE_LOCATION_X				19
#define BACKIMAGE_LOCATION_Y				92

// 판매할 아이템
#define SELITEM_ICON_LOCATION_X				737
#define SELITEM_ICON_LOCATION_Y				191
#define SELITEM_NAME_LOCATION_X				637
#define SELITEM_NAME_LOCATION_Y				240
#define ITEM_ICON_WIDTH						28
#define ITEM_ICON_HEIGHT					28
#define SELITEM_ICON_PUTITEM_LEFT_RANGE		112
#define SELITEM_ICON_PUTITEM_RIGHT_RANGE	112
#define SELITEM_ICON_PUTITEM_TOP_RANGE		24
#define SELITEM_ICON_PUTITEM_BOTTOM_RANGE	60

// 수량, 가격
#define NUMEDITBOX_POSITION					{307, 470}
#define NUMEDITBOX_WIDTH					80
#define NUMEDITBOX_CAP						20
#define MONEYEDITBOX_POSITION				{307, 470}
#define MONEYEDITBOX_WIDTH					102
#define MONEYEDITBOX_CAP					20

// 수량 입력
#define NUMEDITBOX_LOCATION_X				747
#define NUMEDITBOX_LOCATION_Y				311
#define UPCNTBTN_LOCATION_X					833
#define UPCNTBTN_LOCATION_Y					307
#define MAXBTN_LOCATION_X					842
#define MAXBTN_LOCATION_Y					304
#define DOWNCNTBTN_LOCATION_X				833
#define DOWNCNTBTN_LOCATION_Y				322

// 가격 입력
#define	MONEY_COMBO_LOCATION_X				765
#define	MONEY_COMBO_LOCATION_Y				380
#define MONEY_COMBO_MAIN_WIDTH				103
#define MONEY_COMBO_MAIN_HEIGHT				17
#define MONEY_COMBO_ELE_WIDTH				87
#define MONEY_COMBO_ELE_HEIGHT				15	
#define MONEYEDITBOX_LOCATION_X				764
#define MONEYEDITBOX_LOCATION_Y				414
#define MONEY_IMAGE_LOCATION_X				726
#define MONEY_IMAGE_LOCATION_Y				414

// 등록 버튼
#define ADDBTN_LOCATION_X					591
#define ADDBTN_LOCATION_Y					512

#define MONEYCOUNT							2	

#define ITEM_MAX_COUNT						2000000000

#define MAXITEMNAME_LEN						37

CINFTradeItemAdd::CINFTradeItemAdd(CAtumNode* pParent)
{
	m_pParent = pParent;
	m_pBackImg = NULL;
	m_pMoneyComboBox = NULL;
	m_pAddBtn = NULL;
	memset(&m_ptStartPos, 0x00, sizeof(POINT));

	m_byMoneySelect = SPI;

	m_pIconInfo = NULL;

	m_pSelItemNameFont = NULL;

	m_pMaxBtn = NULL;

	m_pNumEditBox = NULL;

	m_pMoneyEditBox = NULL;

	m_pUpCntBtn = NULL;
	m_pDownCntBtn = NULL;

	memset(&m_pItemName, 0x00, sizeof(m_pItemName));

	m_pSourceItem = NULL;

	m_nCurerntInfo = NULL;
}

CINFTradeItemAdd::~CINFTradeItemAdd()
{
	SAFE_DELETE(m_pBackImg);
	SAFE_DELETE(m_pMoneyComboBox);
	SAFE_DELETE(m_pAddBtn);

	SAFE_DELETE(m_pSelItemNameFont);

	SAFE_DELETE(m_pMaxBtn);

	SAFE_DELETE(m_pNumEditBox);

	SAFE_DELETE(m_pMoneyEditBox)

	SAFE_DELETE(m_pUpCntBtn);
	SAFE_DELETE(m_pDownCntBtn);

	SAFE_DELETE(m_pSourceItem);
}

HRESULT CINFTradeItemAdd::InitDeviceObjects()
{
	DataHeader *pDataHeader = NULL;
	
	if(NULL == m_pBackImg)
	{
		pDataHeader = g_pGameMain->m_GruopImagemanager->FindResource("tc_reg");
		m_pBackImg = g_pGameMain->m_GruopImagemanager->GetGroupImage( pDataHeader );
		m_pBackImg->InitDeviceObjects( g_pD3dApp->m_pImageList );		
	}

	if(NULL == m_pMoneyComboBox)
	{
		m_pMoneyComboBox = new CINFListBox("cbarena","cbarenab");
		
		m_pMoneyComboBox->SetUseCulling(TRUE); //글씨 컬링 사용
		m_pMoneyComboBox->InitDeviceObjects();
		
	}

	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];
		wsprintf(szUpBtn, "tc_regb03");
		wsprintf(szDownBtn, "tc_regb01");
		wsprintf(szSelBtn, "tc_regb00");
		wsprintf(szDisBtn, "tc_regb02");
		if(NULL == m_pAddBtn)
		{
			m_pAddBtn = new CINFImageBtn;
		}
		m_pAddBtn->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);	
	}
	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];
		wsprintf(szUpBtn, "Mallbtn_1");
		wsprintf(szDownBtn, "Mallbtn_2");
		wsprintf(szSelBtn, "Mallbtn_1");
		wsprintf(szDisBtn, "Mallbtn_2");
		if(NULL == m_pMaxBtn)
		{
			m_pMaxBtn = new CINFImageBtn;
		}
		m_pMaxBtn->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);
		
	}

	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];
		wsprintf(szUpBtn, "mnQup03");
		wsprintf(szDownBtn, "mnQup01");
		wsprintf(szSelBtn, "mnQup00");
		wsprintf(szDisBtn, "mnQup02");
		if(NULL == m_pUpCntBtn)
		{
			m_pUpCntBtn = new CINFImageBtn;
		}
		m_pUpCntBtn->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);		
	}
	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];
		wsprintf(szUpBtn, "mnQdn03");
		wsprintf(szDownBtn, "mnQdn01");
		wsprintf(szSelBtn, "mnQdn00");
		wsprintf(szDisBtn, "mnQdn02");
		if(NULL == m_pDownCntBtn)
		{
			m_pDownCntBtn = new CINFImageBtn;
		}
		m_pDownCntBtn->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);		
	}

	if(NULL == m_pSelItemNameFont)
	{
		m_pSelItemNameFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()),9, D3DFONT_ZENABLE, TRUE,512,32);		
		m_pSelItemNameFont->InitDeviceObjects(g_pD3dDev) ;
	}

	{
		if(NULL == m_pNumEditBox)
		{
			m_pNumEditBox = new CINFNumEditBox;
		}
		char chMaxMixCnt[64];
		
		wsprintf(chMaxMixCnt, "%d", ITEM_MAX_COUNT);
		
		POINT ptPos = NUMEDITBOX_POSITION;
		m_pNumEditBox->InitDeviceObjects(9, ptPos, NUMEDITBOX_WIDTH, TRUE, NUMEDITBOX_CAP);				
		m_pNumEditBox->SetMaxStringLen(strlen(chMaxMixCnt));
		NumEditBoxChangeCount(m_pNumEditBox, 1);
	}

	{
		if(NULL == m_pMoneyEditBox)
		{
			m_pMoneyEditBox = new CINFNumEditBox;
		}
		char chMaxMixCnt[64];
		
		wsprintf(chMaxMixCnt, "%d", ITEM_MAX_COUNT);
		
		POINT ptPos = MONEYEDITBOX_POSITION;
		m_pMoneyEditBox->InitDeviceObjects(9, ptPos, MONEYEDITBOX_WIDTH, TRUE, MONEYEDITBOX_CAP);				
		m_pMoneyEditBox->SetMaxStringLen(strlen(chMaxMixCnt));
		NumEditBoxChangeCount(m_pMoneyEditBox, 1);
	}

	return S_OK;
}
HRESULT CINFTradeItemAdd::RestoreDeviceObjects()
{
	m_ptStartPos.x = (g_pD3dApp->GetBackBufferDesc().Width - TRADEITEMBUY_WIDTH)/2;
	m_ptStartPos.y = CITY_BASE_NPC_BOX_START_Y - (TRADEITEMBUY_HEIGHT - (CITY_BASE_NPC_BOX_SIZE_Y+CITY_BASE_DOWN_BOX_HEIGHT));

	m_byMoneySelect = SPI;

	m_pIconInfo = g_pGameMain->m_pIcon;

	memset(&m_pItemName, 0x00, sizeof(m_pItemName));

	if(m_pBackImg)
	{
		m_pBackImg->RestoreDeviceObjects();
		m_pBackImg->Move(m_ptStartPos.x + BACKIMAGE_LOCATION_X, m_ptStartPos.y + BACKIMAGE_LOCATION_Y);
	}

	if(m_pMoneyComboBox)
	{
		m_pMoneyComboBox->ItemClear();
		m_pMoneyComboBox->RestoreDeviceObjects();
		m_pMoneyComboBox->ShowItem(FALSE);
		m_pMoneyComboBox->AddElement("SPI");
		m_pMoneyComboBox->AddElement("WP");
		m_pMoneyComboBox->SetSelectItem(0);	
	}

	if(m_pAddBtn)
		m_pAddBtn->RestoreDeviceObjects();

	if(m_pSelItemNameFont)
		m_pSelItemNameFont->RestoreDeviceObjects();

	if(m_pMaxBtn)
		m_pMaxBtn->RestoreDeviceObjects();

	if(m_pNumEditBox)
	{
		m_pNumEditBox->RestoreDeviceObjects();
		NumEditBoxChangeCount(m_pNumEditBox, 1);
		m_pNumEditBox->EnableEdit(FALSE);
	}
	if(m_pMoneyEditBox)
	{
		m_pMoneyEditBox->RestoreDeviceObjects();
		NumEditBoxChangeCount(m_pMoneyEditBox,1);
		m_pMoneyEditBox->EnableEdit(FALSE);
	}

	if(m_pUpCntBtn)
		m_pUpCntBtn->RestoreDeviceObjects();
	if(m_pDownCntBtn)
		m_pDownCntBtn->RestoreDeviceObjects();

	SetbtnPos();
	InitData();
	return S_OK;
}
HRESULT CINFTradeItemAdd::DeleteDeviceObjects()
{
	if(m_pBackImg)
	{
		m_pBackImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pBackImg);
	}

	if(m_pMoneyComboBox)
	{
		m_pMoneyComboBox->DeleteDeviceObjects();
		SAFE_DELETE(m_pMoneyComboBox);
	}

	if(m_pAddBtn)
	{
		m_pAddBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pAddBtn);
	}

	if(m_pSelItemNameFont)
	{
		m_pSelItemNameFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pSelItemNameFont);
	}
	if(m_pMaxBtn)
	{
		m_pMaxBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pMaxBtn);
	}
	if(m_pNumEditBox)
	{
		m_pNumEditBox->DeleteDeviceObjects();
		SAFE_DELETE(m_pNumEditBox);
	}
	if(m_pMoneyEditBox)
	{
		m_pMoneyEditBox->DeleteDeviceObjects();
		SAFE_DELETE(m_pMoneyEditBox);
	}

	if(m_pUpCntBtn)
	{
		m_pUpCntBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pUpCntBtn);
	}
	if(m_pDownCntBtn)
	{
		m_pDownCntBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pDownCntBtn);
	}

	return S_OK;
}
HRESULT CINFTradeItemAdd::InvalidateDeviceObjects()
{
	if(m_pBackImg)
		m_pBackImg->InvalidateDeviceObjects();
	if(m_pMoneyComboBox)
		m_pMoneyComboBox->InvalidateDeviceObjects();

	if(m_pAddBtn)
		m_pAddBtn->InvalidateDeviceObjects();

	if(m_pSelItemNameFont)
		m_pSelItemNameFont->InvalidateDeviceObjects();

	if(m_pMaxBtn)
		m_pMaxBtn->InvalidateDeviceObjects();

	if(m_pNumEditBox)
		m_pNumEditBox->InvalidateDeviceObjects();

	if(m_pMoneyEditBox)
		m_pMoneyEditBox->InvalidateDeviceObjects();

	if(m_pUpCntBtn)
		m_pUpCntBtn->InvalidateDeviceObjects();

	if(m_pDownCntBtn)
		m_pDownCntBtn->InvalidateDeviceObjects();

	return S_OK;
}
void CINFTradeItemAdd::Render()
{
	// 2014-06-17 거래소 추가작업
#ifdef SC_MARKET_NOT_USE_NORMAL_INFL
	if(((CINFTradeItemCenter*)m_pParent)->m_bNormalInflMsgAddTab && IS_NORMAL_INFLUENCE_TYPE(g_pShuttleChild->m_myShuttleInfo.InfluenceType))
	{
		((CINFTradeItemCenter*)m_pParent)->m_bNormalInflMsgAddTab = FALSE;
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_060613_0000, _Q_MARKET_NORMAL_MESSAGE);		// "세력 선택전까지는 거래를 할 수 없습니다."
	}
#endif
	// END 2014-06-17 거래소 추가작업

	if(m_pBackImg)
	{
		m_pBackImg->Render();
	}

	if(m_pAddBtn)
		m_pAddBtn->Render();

	if(((CINFTradeItemCenter*)m_pParent)->m_pMoneyImg[m_byMoneySelect])
	{
		((CINFTradeItemCenter*)m_pParent)->m_pMoneyImg[m_byMoneySelect]->Render();
	}

	if(m_pSourceItem && m_pIconInfo)
	{
		char chIconName[64] = {0,};	
		if( !m_pSourceItem->ShapeItemNum)
			wsprintf( chIconName, "%08d", m_pSourceItem->ItemInfo->SourceIndex);	
		else
		{
			ITEM* pShapeItem = g_pDatabase->GetServerItemInfo(m_pSourceItem->ShapeItemNum);
			if( pShapeItem )
				wsprintf( chIconName, "%08d", pShapeItem->SourceIndex );
			else
				wsprintf( chIconName, "%08d", m_pSourceItem->ItemInfo->SourceIndex);
		}		

		m_pIconInfo->SetIcon(chIconName, m_ptStartPos.x + SELITEM_ICON_LOCATION_X , m_ptStartPos.y + SELITEM_ICON_LOCATION_Y, 1.0f);

		m_pIconInfo->Render();

		((CINFTradeItemCenter*)m_pParent)->ChangeMaxLenString(m_pItemName, MAXITEMNAME_LEN);
		m_pSelItemNameFont->DrawText(m_ptStartPos.x + SELITEM_NAME_LOCATION_X, m_ptStartPos.y + SELITEM_NAME_LOCATION_Y, GUI_FONT_COLOR_W, m_pItemName);
	}
	if(m_pMaxBtn)
		m_pMaxBtn->Render();

	if(m_pNumEditBox)
		m_pNumEditBox->Render();

	if(m_pMoneyEditBox)
		m_pMoneyEditBox->Render(TRUE);		// 2014-05-07 by ssjung 거래소 금액에 따라 색이 변하도록 수정

	if(m_pMoneyComboBox)
		m_pMoneyComboBox->Render();

	if(m_pUpCntBtn)
		m_pUpCntBtn->Render();
	if(m_pDownCntBtn)
		m_pDownCntBtn->Render();
}
void CINFTradeItemAdd::Tick()
{
	if(m_pNumEditBox)
		m_pNumEditBox->Tick();

	if(m_pMoneyEditBox)
		m_pMoneyEditBox->Tick();
}

int CINFTradeItemAdd::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_MOUSEWHEEL:
		{
			return OnMouseWheel(wParam, lParam);
		}
		break;
	case WM_LBUTTONDOWN:
		{
			return OnLButtonDown(wParam, lParam);			
		}
		break;
	case WM_MOUSEMOVE:
		{
			return OnMouseMove(wParam, lParam);
		}
		break;
	case WM_LBUTTONUP:
		{
			return OnLButtonUp(wParam, lParam);
		}
		break;

	case WM_IME_STARTCOMPOSITION:
		//	case WM_IME_NOTIFY:
	case WM_IME_COMPOSITION:
	case WM_INPUTLANGCHANGE:	
	case WM_IME_ENDCOMPOSITION:
	case WM_IME_SETCONTEXT:	
	case WM_CHAR:
	case WM_KEYDOWN:
		{
			if(WM_KEYDOWN == uMsg)
			{
				if(m_pNumEditBox->WndProc(uMsg, wParam, lParam))
				{
					// 갱신
					return INF_MSGPROC_BREAK;
				}
				else
				{
					if(wParam == VK_RETURN)
					{
						if(m_pNumEditBox->IsEditMode())
						{
							int nNum = 0;
							m_pNumEditBox->EnableEdit(FALSE);
							CItemInfo* pItemInfo = g_pStoreData->FindItemInInventoryByUniqueNumber( m_pSourceItem->UniqueNumber );
							if(m_pSourceItem)
							{
								if(!pItemInfo)
								{
									if(m_pSourceItem->CurrentCount <= NumEditBoxMaxAndMIN(m_pNumEditBox, m_pSourceItem->CurrentCount))
										return INF_MSGPROC_BREAK;

									g_pStoreData->PutItem((char*)((ITEM_GENERAL*)m_pSourceItem), TRUE);
									pItemInfo = g_pStoreData->FindItemInInventoryByUniqueNumber( m_pSourceItem->UniqueNumber );
									ASSERT_ASSERT( pItemInfo );
									pItemInfo->CopyItemInfo( m_pSourceItem );
									pItemInfo->CurrentCount = 0;
								}
								nNum = NumEditBoxMaxAndMIN(m_pNumEditBox, m_pSourceItem->CurrentCount + pItemInfo->CurrentCount);
								nNum = nNum - m_pSourceItem->CurrentCount;
								InvenToSourceItem(pItemInfo, nNum);
								return INF_MSGPROC_BREAK;
							}
						}
					}
				}

				if(m_pMoneyEditBox->WndProc(uMsg, wParam, lParam))
				{
					// 갱신
					return INF_MSGPROC_BREAK;
				}
				else
				{
					if(wParam == VK_RETURN)
					{
						if(m_pMoneyEditBox->IsEditMode())
						{
							if(m_pSourceItem)
							{
								m_pMoneyEditBox->EnableEdit(FALSE);
								NumEditBoxMaxAndMIN(m_pMoneyEditBox, ITEM_MAX_COUNT);
							}
						}
					}

				}
			}
		}
		break;
	}
	return INF_MSGPROC_NORMAL;
}

int	 CINFTradeItemAdd::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	if(m_pNumEditBox->IsEditMode())
	{
		int nNum = 0;
		m_pNumEditBox->EnableEdit(FALSE);
		CItemInfo* pItemInfo = g_pStoreData->FindItemInInventoryByUniqueNumber( m_pSourceItem->UniqueNumber );
		if(m_pSourceItem)
		{
			if(!pItemInfo)
			{
				if(m_pSourceItem->CurrentCount <= NumEditBoxMaxAndMIN(m_pNumEditBox, m_pSourceItem->CurrentCount))
					return INF_MSGPROC_BREAK;
				
				g_pStoreData->PutItem((char*)((ITEM_GENERAL*)m_pSourceItem), TRUE);
				pItemInfo = g_pStoreData->FindItemInInventoryByUniqueNumber( m_pSourceItem->UniqueNumber );
				ASSERT_ASSERT( pItemInfo );
				pItemInfo->CopyItemInfo( m_pSourceItem );
				pItemInfo->CurrentCount = 0;
			}
			nNum = NumEditBoxMaxAndMIN(m_pNumEditBox, m_pSourceItem->CurrentCount + pItemInfo->CurrentCount);
			nNum = nNum - m_pSourceItem->CurrentCount;
			InvenToSourceItem(pItemInfo, nNum);
		}
	}
	m_pNumEditBox->EnableEdit(FALSE);

	if(m_pMoneyEditBox->IsEditMode())
	{
		if(m_pSourceItem)
			NumEditBoxMaxAndMIN(m_pMoneyEditBox, ITEM_MAX_COUNT);
	}

	m_pMoneyEditBox->EnableEdit(FALSE);


	if(TRUE == m_pAddBtn->OnLButtonDown(pt))
	{
		return  INF_MSGPROC_BREAK;
	}

	if(1 == m_pMoneyComboBox->LButtonDown(pt))
	{
		m_byMoneySelect = m_pMoneyComboBox->GetSelect();
		return  INF_MSGPROC_BREAK; 
	}
	if(TRUE == m_pMaxBtn->OnLButtonDown(pt))
	{
		return INF_MSGPROC_BREAK;
	}

	if(TRUE == m_pNumEditBox->OnLButtonDown(pt) )
	{
		if(m_pSourceItem && IS_COUNTABLE_ITEM(m_pSourceItem->Kind))
		m_pNumEditBox->EnableEdit(TRUE);
		return  INF_MSGPROC_BREAK;				
	}
	

	if(TRUE == m_pMoneyEditBox->OnLButtonDown(pt) )
	{
		if(m_pSourceItem)
			m_pMoneyEditBox->EnableEdit(TRUE);
		return  INF_MSGPROC_BREAK;				
	}

	if(TRUE == m_pUpCntBtn->OnLButtonDown(pt))
	{
		return INF_MSGPROC_BREAK;
	}
	if(TRUE == m_pDownCntBtn->OnLButtonDown(pt))
	{
		return INF_MSGPROC_BREAK;
	}

	return INF_MSGPROC_NORMAL;
}
int	 CINFTradeItemAdd::OnLButtonUp(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);
	
	if(TRUE == m_pAddBtn->OnLButtonUp(pt))
	{
		// 2014-06-17 거래소 추가작업
#ifdef SC_MARKET_NOT_USE_NORMAL_INFL
		if(IS_NORMAL_INFLUENCE_TYPE(g_pShuttleChild->m_myShuttleInfo.InfluenceType))
			g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_060613_0000, _Q_MARKET_NORMAL_MESSAGE);		// "세력 선택전까지는 거래를 할 수 없습니다."
		else if(!m_pSourceItem)
#else
		if(!m_pSourceItem)
#endif
		// END 2014-06-17 거래소 추가작업
			g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0037, _Q_MARKET_NORMAL_MESSAGE);			// "입력되지 않은 항목으로 인해 등록 할 수 없습니다. "
		else
			g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0038, _Q_MARKET_ADD_ITEM);	// "물품을 거래소에 등록 하시겠습니까 ?"
		return  INF_MSGPROC_BREAK;
	}

	{
		int nStartX = m_ptStartPos.x;
		int nStartY = m_ptStartPos.y;		
		
		if( pt.x > nStartX + SELITEM_ICON_LOCATION_X - SELITEM_ICON_PUTITEM_LEFT_RANGE && pt.x < nStartX + SELITEM_ICON_LOCATION_X + ITEM_ICON_WIDTH + SELITEM_ICON_PUTITEM_RIGHT_RANGE &&
			pt.y > nStartY + SELITEM_ICON_LOCATION_Y - SELITEM_ICON_PUTITEM_TOP_RANGE && pt.y < nStartY + SELITEM_ICON_LOCATION_Y + ITEM_ICON_HEIGHT + SELITEM_ICON_PUTITEM_BOTTOM_RANGE)
 		{
			if(g_pGameMain && g_pGameMain->m_stSelectItem.pSelectItem && g_pGameMain->m_stSelectItem.pSelectItem->pItem)
			{
				UID64_t uItemUniNum = g_pGameMain->m_stSelectItem.pSelectItem->pItem->UniqueNumber;
				CItemInfo* pItemInfo = g_pStoreData->FindItemInInventoryByUniqueNumber(uItemUniNum);
				if(pItemInfo)
					UpLoadItem(pItemInfo);

				return INF_MSGPROC_NORMAL;
			}
 		}
	}

	if(TRUE == m_pMaxBtn->OnLButtonUp(pt))
	{
		if(m_pSourceItem)
		{
			CItemInfo* pItemInfo = g_pStoreData->FindItemInInventoryByUniqueNumber( m_pSourceItem->UniqueNumber );

			if(pItemInfo && IS_COUNTABLE_ITEM(pItemInfo->Kind))
			{
				InvenToSourceItem(pItemInfo, pItemInfo->CurrentCount);
				NumEditBoxChangeCount(m_pNumEditBox, m_pSourceItem->CurrentCount);
			}
		}
		return INF_MSGPROC_BREAK;
	}

 	int nNum = 0;
	if(TRUE == m_pUpCntBtn->OnLButtonUp(pt))
	{
 		if(m_pSourceItem && IS_COUNTABLE_ITEM(m_pSourceItem->Kind))
 		{
			CItemInfo* pItemInfo = g_pStoreData->FindItemInInventoryByUniqueNumber( m_pSourceItem->UniqueNumber );

			if(pItemInfo)
			{
				NumEditBoxChangeCount(m_pNumEditBox, m_pSourceItem->CurrentCount+1);
				nNum = NumEditBoxMaxAndMIN(m_pNumEditBox, m_pSourceItem->CurrentCount + pItemInfo->CurrentCount);
				nNum = nNum - m_pSourceItem->CurrentCount;
				InvenToSourceItem(pItemInfo, nNum);
			}
		}
		return INF_MSGPROC_BREAK;
	}
	if(TRUE == m_pDownCntBtn->OnLButtonUp(pt))
	{
		int nNum = 0;
		m_pNumEditBox->EnableEdit(FALSE);
		if(m_pSourceItem && IS_COUNTABLE_ITEM(m_pSourceItem->Kind))
		{
			CItemInfo* pItemInfo = g_pStoreData->FindItemInInventoryByUniqueNumber( m_pSourceItem->UniqueNumber );
			if(m_pSourceItem->CurrentCount <= 1)
				return INF_MSGPROC_BREAK;
			else
				NumEditBoxChangeCount(m_pNumEditBox, m_pSourceItem->CurrentCount-1);

			if(!pItemInfo)
			{			
				g_pStoreData->PutItem((char*)((ITEM_GENERAL*)m_pSourceItem), TRUE);
				pItemInfo = g_pStoreData->FindItemInInventoryByUniqueNumber( m_pSourceItem->UniqueNumber );
				ASSERT_ASSERT( pItemInfo );
				pItemInfo->CopyItemInfo( m_pSourceItem );
				pItemInfo->CurrentCount = 0;
			}
			nNum = NumEditBoxMaxAndMIN(m_pNumEditBox, m_pSourceItem->CurrentCount + pItemInfo->CurrentCount);
			nNum = nNum - m_pSourceItem->CurrentCount;
			InvenToSourceItem(pItemInfo, nNum);
		}
		return INF_MSGPROC_BREAK;
	}
	return INF_MSGPROC_NORMAL;
}
int	 CINFTradeItemAdd::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);
	
	if(TRUE == m_pAddBtn->OnMouseMove(pt))
	{
		return  INF_MSGPROC_BREAK;
	}

	m_pMoneyComboBox->MouseMove(pt);

	if( pt.x > m_ptStartPos.x + SELITEM_ICON_LOCATION_X && pt.x < m_ptStartPos.x + SELITEM_ICON_LOCATION_X + ITEM_ICON_WIDTH &&
		pt.y > m_ptStartPos.y + SELITEM_ICON_LOCATION_Y && pt.y < m_ptStartPos.y + SELITEM_ICON_LOCATION_Y + ITEM_ICON_HEIGHT)
	{
		if(m_pSourceItem && !g_pGameMain->m_stSelectItem.pSelectItem)
		{
			if(m_nCurerntInfo != m_pSourceItem)
				g_pGameMain->SetItemInfoUser( m_pSourceItem, pt.x, pt.y);

			m_nCurerntInfo = m_pSourceItem;
		}
		else
			m_nCurerntInfo = NULL;		
	}
	else
		m_nCurerntInfo = NULL;

	if(!m_nCurerntInfo)
		g_pGameMain->SetItemInfoUser( NULL, 0, 0);


	if(TRUE == m_pMaxBtn->OnMouseMove(pt))
	{
		
		return INF_MSGPROC_BREAK;
	}

	if(TRUE == m_pUpCntBtn->OnMouseMove(pt))
	{
		return INF_MSGPROC_BREAK;
	}
	if(TRUE == m_pDownCntBtn->OnMouseMove(pt))
	{
		return INF_MSGPROC_BREAK;
	}

	return INF_MSGPROC_NORMAL;
}

int	 CINFTradeItemAdd::OnMouseWheel(WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);
	
	return INF_MSGPROC_NORMAL;
}

void CINFTradeItemAdd::SetbtnPos()
{
	int nPosX, nPosY;
	nPosX = nPosY = 0;
	if(m_pMoneyComboBox)
	{		
		// 장치
		int nMainWidth, nMainHeight;
		int nEleWidth, nEleHeight;
		int nElePosX, nElePosY;
		nElePosX = nElePosY =0;
		
		nMainWidth = MONEY_COMBO_MAIN_WIDTH;
		nMainHeight = MONEY_COMBO_MAIN_HEIGHT;
		nEleWidth = MONEY_COMBO_ELE_WIDTH;
		nEleHeight = MONEY_COMBO_ELE_HEIGHT;		
		
		nPosX = m_ptStartPos.x + MONEY_COMBO_LOCATION_X;
		nPosY = m_ptStartPos.y + MONEY_COMBO_LOCATION_Y;		
		
		nElePosX = nPosX;
		nElePosY = nPosY + nMainHeight;
	
		m_pMoneyComboBox->SetMainArea(nPosX, nPosY,nMainWidth, nMainHeight);
		m_pMoneyComboBox->SetElementArea(nElePosX, nElePosY+2, nEleWidth, nEleHeight);
		m_pMoneyComboBox->SetBGPos(nElePosX+6, nElePosY+4,nEleWidth, nEleHeight);
	}
	
	if(m_pAddBtn)
		m_pAddBtn->SetBtnPosition(m_ptStartPos.x + ADDBTN_LOCATION_X, m_ptStartPos.y + ADDBTN_LOCATION_Y);

	if(m_pMaxBtn)
		m_pMaxBtn->SetBtnPosition(m_ptStartPos.x + MAXBTN_LOCATION_X, m_ptStartPos.y + MAXBTN_LOCATION_Y);

	if(m_pNumEditBox)
		m_pNumEditBox->SetPos(m_ptStartPos.x + NUMEDITBOX_LOCATION_X, m_ptStartPos.y + NUMEDITBOX_LOCATION_Y);

	if(m_pMoneyEditBox)
		m_pMoneyEditBox->SetPos(m_ptStartPos.x + MONEYEDITBOX_LOCATION_X, m_ptStartPos.y + MONEYEDITBOX_LOCATION_Y);

	for(int i = 0; i<MONEYCOUNT; ++i)
	{
		if(((CINFTradeItemCenter*)m_pParent)->m_pMoneyImg[i])
		{
			((CINFTradeItemCenter*)m_pParent)->m_pMoneyImg[i]->Move(m_ptStartPos.x + MONEY_IMAGE_LOCATION_X, m_ptStartPos.y + MONEY_IMAGE_LOCATION_Y);
		}
	}

	if(m_pUpCntBtn)
		m_pUpCntBtn->SetBtnPosition(m_ptStartPos.x + UPCNTBTN_LOCATION_X, m_ptStartPos.y + UPCNTBTN_LOCATION_Y);
	
	if(m_pDownCntBtn)
		m_pDownCntBtn->SetBtnPosition(m_ptStartPos.x + DOWNCNTBTN_LOCATION_X, m_ptStartPos.y + DOWNCNTBTN_LOCATION_Y);

}
BOOL CINFTradeItemAdd::UpLoadItem(CItemInfo* i_pItem)
{
	if(!g_pGameMain)
		return FALSE;
	
	if(i_pItem->Wear != WEAR_NOT_ATTACHED)
	{
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_CITYLAP_0002, _Q_MARKET_NORMAL_MESSAGE );//"착용된 아이템은 올릴 수 없습니다."
		return FALSE;
	}
	else if(COMPARE_BIT_FLAG(i_pItem->ItemInfo->ItemAttribute, ITEM_ATTR_NO_TRANSFER | ITEM_ATTR_KILL_MARK_ITEM | ITEM_ATTR_ACCOUNT_POSSESSION))
	{
		// 거래 할 수 없는 아이템
		g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_060728_0003, _Q_MARKET_NORMAL_MESSAGE);	// "등록을 할 수 없는 아이템 입니다."
		return FALSE;
	}
	else if(m_pSourceItem &&  m_pSourceItem ->UniqueNumber == i_pItem->UniqueNumber)
	{
		// 중복
		g_pGameMain->m_pInfWindow->AddMsgBox(STRERR_ERROR_0140, _Q_MARKET_NORMAL_MESSAGE);		// "목록에 이미 등록되어 있습니다."
		return FALSE;
	}
	else
	{
		// 2007-12-13 by dgwoo 시간제 아이템이면서 사용한 아이템이라면 팩토리에 올릴수 없다.
		if((i_pItem->ItemInfo->Kind == ITEMKIND_ACCESSORY_TIMELIMIT 
			|| COMPARE_BIT_FLAG(i_pItem->ItemInfo->ItemAttribute, ITEM_ATTR_TIME_LIMITE)
			|| COMPARE_BIT_FLAG(i_pItem->ItemInfo->ItemAttribute, ITEM_ATTR_DELETED_TIME_LIMITE_AFTER_USED)) // 2008-11-26 by bhsohn 절대시간 제한 아이템 구현
			&& i_pItem->GetItemPassTime() != 0)
		{
			g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_060728_0003, _Q_MARKET_NORMAL_MESSAGE);	// "등록을 할 수 없는 아이템 입니다."
			return FALSE;
		}
		else
		{
			if( IS_COUNTABLE_ITEM(i_pItem->Kind))
			{
				InvenToSourceItem(i_pItem, 1);
			}
			else
			{
				// 2013-06-13 by ssjung 외형 변경 컬렉션 예외처리 추가(외형 적용이 안되야 할 부분에 외형 적용이 안될 수 있도록)
#ifdef SC_COLLECTION_ARMOR_JHSEOL_BCKIM
				if(i_pItem->FixedTermShape.nStatShapeItemNum && i_pItem->FixedTermShape.nStatLevel)
				{
					g_pStoreData->RqCollectionShapeChange(i_pItem->UniqueNumber,0);
				}
#endif
				//end 2013-06-13 by ssjung 외형 변경 컬렉션 예외처리 추가(외형 적용이 안되야 할 부분에 외형 적용이 안될 수 있도록)
				InvenToSourceItem(i_pItem, 1);
			}
			if(m_pParent)
				((CINFTradeItemCenter*)m_pParent)->GetItemName(m_pSourceItem, m_pItemName);

			NumEditBoxChangeCount(m_pNumEditBox, 1);
			m_pNumEditBox->EnableEdit(FALSE);
			NumEditBoxChangeCount(m_pMoneyEditBox, 1);
			m_pMoneyEditBox->EnableEdit(FALSE);

			return TRUE;
		}
		
	}
}

void CINFTradeItemAdd::InvenToSourceItem(CItemInfo* pItemInfo, int nCount)
{
	BOOL bRefresh = FALSE;
	if(IS_COUNTABLE_ITEM(pItemInfo->Kind))
	{
		ASSERT_ASSERT(pItemInfo->CurrentCount >= nCount);
		
		if(m_pSourceItem && m_pSourceItem->UniqueNumber == pItemInfo->UniqueNumber )
		{
			m_pSourceItem->CurrentCount += nCount;
			g_pStoreData->UpdateItemCount( pItemInfo->UniqueNumber, pItemInfo->CurrentCount - nCount);
		}
		else
		{
			InitData();

			CItemInfo* pNewItem = new CItemInfo((ITEM_GENERAL*)pItemInfo);
			pNewItem->CopyItemInfo( pItemInfo );
			pNewItem->CurrentCount = nCount;
			m_pSourceItem = pNewItem;
			g_pStoreData->UpdateItemCount( pItemInfo->UniqueNumber, pItemInfo->CurrentCount - nCount);
		}	
	}
	else
	{
		InitData();

		CItemInfo* pNewItem = new CItemInfo((ITEM_GENERAL*)pItemInfo);
		
		pNewItem->CopyItemInfo( pItemInfo );
		m_pSourceItem = pNewItem;
		g_pStoreData->DeleteItem( pItemInfo->UniqueNumber );
	}
}

void CINFTradeItemAdd::InitData()
{
	if(!m_pSourceItem)
		return;

	g_pStoreData->PutItem((char*)((ITEM_GENERAL*)m_pSourceItem), TRUE);
	CItemInfo* pItemInfo = g_pStoreData->FindItemInInventoryByUniqueNumber( m_pSourceItem->UniqueNumber );
	ASSERT_ASSERT( pItemInfo );
	
	pItemInfo->CopyItemInfo( m_pSourceItem );
	
	g_pShuttleChild->ResortingItem();
	if(g_pGameMain && g_pGameMain->m_pInven)
	{
		g_pGameMain->m_pInven->SetScrollEndLine();
		g_pGameMain->m_pInven->SetAllIconInfo();
	}
	SAFE_DELETE(m_pSourceItem);
	m_pSourceItem = NULL;
}

void CINFTradeItemAdd::NumEditBoxChangeCount(CINFNumEditBox* pNumEditBox, int nNum)
{
	char chBuff[32];
	wsprintf(chBuff, "%d", nNum);		
	pNumEditBox->SetString(chBuff, 32);
} 	

int CINFTradeItemAdd::NumEditBoxMaxAndMIN(CINFNumEditBox* pNumEditBox, int nMaxCount)
{
	if(!pNumEditBox || !m_pSourceItem)
	{
		return 0;
	}
	INT nMixCounts = 0;
	char chBuff[256] = {0,};
	pNumEditBox->GetString(chBuff, 256);

	int nLen = strlen(chBuff);
	if(nLen > 10)
	{
		nMixCounts = ITEM_MAX_COUNT;
	}
	else if(nLen == 10 && chBuff[0] != 49)
	{
		nMixCounts = ITEM_MAX_COUNT;
	}
	else
		nMixCounts = atoi(chBuff);
	
	if(nMixCounts <= 0)
	{
		nMixCounts = 1;
	}
	else if(nMixCounts > nMaxCount)
	{
		nMixCounts = nMaxCount;
	}
	NumEditBoxChangeCount(pNumEditBox,nMixCounts);

	return nMixCounts;
}

void CINFTradeItemAdd::ADDItem()
{
	char cNameTemp[MARKET_ITEM_FULL_NAME] = {0,};
 	MSG_FC_MARKET_SELL_REQUEST sMsg;
 	memset(&sMsg,0x00,sizeof(sMsg));
	UINT nSelect = m_pMoneyComboBox->GetSelect();
 
 	sMsg.ItemUID = m_pSourceItem->UniqueNumber;
 	sMsg.MoneyType = m_pMoneyComboBox->GetSelect();
  	sMsg.Price = NumEditBoxMaxAndMIN(m_pMoneyEditBox,ITEM_MAX_COUNT);
	sMsg.Count = m_pSourceItem->CurrentCount;
  	//sMsg.Count = NumEditBoxMaxAndMIN(m_pNumEditBox,ITEM_MAX_COUNT);

	((CINFTradeItemCenter*)m_pParent)->GetItemName(m_pSourceItem, cNameTemp, FALSE);

	if(cNameTemp[0] == 32)
		strcpy(sMsg.Name, &cNameTemp[1]);
	else 
		strcpy(sMsg.Name, cNameTemp);

 	g_pFieldWinSocket->SendMsg( T_FC_MARKET_SELL_REQUEST, (char*)&sMsg, sizeof(sMsg) );
	((CINFTradeItemCenter*)m_pParent)->TradeCenterLock(TRUE);
}
void CINFTradeItemAdd::ADDItemOk(UID64_t ItemUID)
{
	((CINFTradeItemCenter*)m_pParent)->TradeCenterLock(FALSE);
	g_pGameMain->m_pInfWindow->AddMsgBox(STRMSG_C_131205_0039, _Q_MARKET_NORMAL_MESSAGE);	// "물품이 성공적으로 거래소에 등록 되었습니다. "
	if(m_pSourceItem->UniqueNumber == ItemUID)
	{
		if(m_pSourceItem)
		{
			SAFE_DELETE(m_pSourceItem);
			m_pSourceItem = NULL;
		}
		RestoreDeviceObjects();
	}
}