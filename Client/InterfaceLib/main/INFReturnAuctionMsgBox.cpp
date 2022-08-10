// INFReturnAuctionMsgBox.cpp: implementation of the CINFReturnAuctionMsgBox class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "INFGameMain.h"
#include "AtumDatabase.h"
#include "ShuttleChild.h"
#include "ItemInfo.h"
#include "INFGroupManager.h"
#include "INFGroupImage.h"
#include "INFToolTip.h"
#include "INFItemInfo.h"
#include "INFNumEditBox.h"
#include "INFReturnAuctionCenter.h"
#include "INFReturnAuctionMsgBox.h"
// 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)
//#include "AtumApplication.h"
//#include "INFCityBase.h"
//#include "GameDataLast.h"
//#include "INFImage.h"
//#include "D3DHanFont.h"
//#include "Chat.h"
//#include "CharacterChild.h"
//#include "INFWindow.h"
//#include "Interface.h"
//#include "INFImageBtn.h"
//#include "INFIcon.h"
// END 2014-06-12 by ymjoo 파괴 경매장 추가작업 (주석처리)
#include "INFIcon.h"		// 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define WINSTART_POS_X					((g_pD3dApp->GetBackBufferDesc().Width - 286) / 2)
#define WINSTART_POS_Y					((g_pD3dApp->GetBackBufferDesc().Height - 436) / 2)

// 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경
#define SMALL_ICON_POS_X				131
#define SMALL_ICON_POS_Y				56
// #define BIG_ICON_POS_X					103
// #define BIG_ICON_POS_Y					42
// END 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경

#define OK_BTN_POS_X					90
#define OK_BTN_POS_Y					372

#define CANCEL_BTN_POS_X				(OK_BTN_POS_X + 72)
#define CANCEL_BTN_POS_Y				372

#define LIST_NAME_POS_X					29
#define LIST_NAME_POS_Y					116
#define LIST_NAME_WIDTH					228

#define LIST_BIDDING_MONEY_POS_X		120
#define LIST_BIDDING_MONEY_POS_Y		179
#define LIST_BIDDING_MONEY_WIDTH		102

#define LIST_TOTAL_MONEY_POS_X			247

#define LIST_FINAL_MONEY_POS_X			17
#define LIST_FINAL_MONEY_POS_Y			201
#define LIST_FINAL_MONEY_WIDTH			253

#define LIST_FAILGETITEM_MONEY_POS_X	120
#define LIST_FAILGETITEM_MONEY_POS_Y	179
#define LIST_FAILGETITEM_MONEY_SIZE_X	102
#define LIST_FAILGETITEM_MYMONEY_POS_Y	247

#define MAX_PERCENT						100

#define ITEMLIST_MAXITEMNAME_LEN		40

#define NUMEDITBOX_POS_X				120
#define NUMEDITBOX_POS_Y				213

#define OK_BTN_FAILGETITEM_POS_X		125
#define OK_BTN_FAILGETITEM_POS_Y		372

CINFReturnAuctionMsgBox::CINFReturnAuctionMsgBox()
{
	m_pReturnAuctionCenter = NULL;
	m_pBackImg = NULL;
	m_pOkBtn = NULL;
	m_pCanCelBtn = NULL;
	// 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경
	//m_pBigIcon = NULL;
	m_pIcon = NULL;
	// END 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경
	m_pInchantNum = NULL;

	m_pListFont = NULL;
	m_nCurerntInfo = NULL;

	m_pFinalMoneyFont = NULL;

	m_nMode = ITEMNONE;
	m_pData = NULL;
	m_pNumEditBox = NULL;

	m_nTotalMoney = 0;
}

CINFReturnAuctionMsgBox::~CINFReturnAuctionMsgBox()
{
	SAFE_DELETE(m_pBackImg);
	SAFE_DELETE(m_pOkBtn);
	SAFE_DELETE(m_pCanCelBtn);
	SAFE_DELETE(m_pInchantNum);
	SAFE_DELETE(m_pListFont);
	SAFE_DELETE(m_pNumEditBox);
	SAFE_DELETE(m_pFinalMoneyFont)
}

HRESULT CINFReturnAuctionMsgBox::InitDeviceObjects(char* cBkName, void* nData ,int nMode, void* pCenter)
{
	DataHeader* pDataHeader = NULL;
	if(NULL == m_pBackImg)		//배경 이미지 
	{
		pDataHeader = g_pGameMain->m_GruopImagemanager->FindResource(cBkName);		//배경이미지 파일 이름 
		m_pBackImg = g_pGameMain->m_GruopImagemanager->GetGroupImage(pDataHeader);
		m_pBackImg->InitDeviceObjects(g_pD3dApp->m_pImageList);
	}
	
	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];
		wsprintf(szUpBtn, "okb03");
		wsprintf(szDownBtn, "okb01");
		wsprintf(szSelBtn, "okb00");
		wsprintf(szDisBtn, "okb02");
		if(NULL == m_pOkBtn)
		{
			m_pOkBtn = new CINFImageBtn;
		}
		m_pOkBtn->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);	
	}

	if(FAILGETITEM != nMode)
	{
		char szUpBtn[30], szDownBtn[30], szSelBtn[30], szDisBtn[30];
		wsprintf(szUpBtn, "canb03");
		wsprintf(szDownBtn, "canb01");
		wsprintf(szSelBtn, "canb00");
		wsprintf(szDisBtn, "canb02");
		if(NULL == m_pCanCelBtn)
		{
			m_pCanCelBtn = new CINFImageBtn;
		}
		m_pCanCelBtn->InitDeviceObjects(szUpBtn, szDownBtn, szSelBtn, szDisBtn);	
	}

	// 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경
// 	{
// 		CItemInfo* pTempItem = ((AUCTION_MY_ITEM_INFO*)nData)->pItem;
// 
// 		if(!pTempItem->ShapeItemNum)
// 		{
// 			m_pBigIcon = g_pGameMain->GetINFItemInfo()->FindBigIcon(pTempItem->ItemInfo->SourceIndex);
// 		}
// 		else
// 		{
// 			ITEM* pShapeItem = g_pDatabase->GetServerItemInfo(pTempItem->ShapeItemNum);
// 			if(pShapeItem)
// 			{
// 				m_pBigIcon = g_pGameMain->GetINFItemInfo()->FindBigIcon(pShapeItem->SourceIndex);
// 			}
// 			else
// 			{
// 				m_pBigIcon = g_pGameMain->GetINFItemInfo()->FindBigIcon(pTempItem->ItemInfo->SourceIndex);
// 			}
// 		}	
// 	}
	m_pIcon = g_pGameMain->m_pIcon;
	// END 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경

	if(NULL == m_pInchantNum)
	{
		m_pInchantNum = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 8, D3DFONT_ZENABLE|D3DFONT_BOLD, FALSE, 512, 32);
		m_pInchantNum->InitDeviceObjects(g_pD3dDev);
	}
	if(NULL == m_pListFont)
	{
		m_pListFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 512, 32);
		m_pListFont->InitDeviceObjects(g_pD3dDev);
	}
	if(NULL == m_pFinalMoneyFont)
	{
		m_pFinalMoneyFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE|D3DFONT_BOLD, TRUE, 512, 32);
		m_pFinalMoneyFont->InitDeviceObjects(g_pD3dDev);
	}

	if(BIDDING == nMode)
	{
		if(NULL == m_pNumEditBox)
		{
			m_pNumEditBox = new CINFNumEditBox;
			char chMaxMixCnt[64];
			wsprintf(chMaxMixCnt, "%d", MAX_PERCENT);
			POINT ptPos;
			memset(&ptPos, 0x00, sizeof(POINT));
			m_pNumEditBox->InitDeviceObjects(9, ptPos, 102, TRUE, 16);				
			m_pNumEditBox->SetMaxStringLen(strlen(chMaxMixCnt));
			NumEditBoxChangeCount(m_pNumEditBox, 1);
		}
	}	

	m_pData = (AUCTION_MY_ITEM_INFO*)nData;
	m_nMode = nMode;
	m_pReturnAuctionCenter = (CINFReturnAuctionCenter*)pCenter;
	return S_OK;
}

HRESULT CINFReturnAuctionMsgBox::RestoreDeviceObjects()
{
	if(m_pBackImg)
	{
		m_pBackImg->RestoreDeviceObjects();
	}

	if(m_pOkBtn)
	{
		m_pOkBtn->RestoreDeviceObjects();
	}

	if(m_pCanCelBtn)
	{
		m_pCanCelBtn->RestoreDeviceObjects();
	}

	if(m_pInchantNum)
	{
		m_pInchantNum->RestoreDeviceObjects();
	}

	if(m_pListFont)
	{
		m_pListFont->RestoreDeviceObjects();
	}

	if(m_pNumEditBox)
	{
		m_pNumEditBox->RestoreDeviceObjects();
	}

	if(m_pFinalMoneyFont)
	{
		m_pFinalMoneyFont->RestoreDeviceObjects();
	}

	SetBtnPos();

	return S_OK;
}

HRESULT CINFReturnAuctionMsgBox::DeleteDeviceObjects()
{
	if(m_pBackImg)
	{
		m_pBackImg->DeleteDeviceObjects();
		SAFE_DELETE(m_pBackImg);
	}

	if(m_pOkBtn)
	{
		m_pOkBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pOkBtn);
	}

	if(m_pCanCelBtn)
	{
		m_pCanCelBtn->DeleteDeviceObjects();
		SAFE_DELETE(m_pCanCelBtn);
	}

	if(m_pInchantNum)
	{
		m_pInchantNum->DeleteDeviceObjects();
		SAFE_DELETE(m_pInchantNum);
	}
	if(m_pListFont)
	{
		m_pListFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pListFont);
	}

	if(m_pNumEditBox)
	{
		m_pNumEditBox->DeleteDeviceObjects();
		SAFE_DELETE(m_pNumEditBox);
	}

	if(m_pFinalMoneyFont)
	{
		m_pFinalMoneyFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pFinalMoneyFont);
	}
		
	return S_OK;
}

HRESULT CINFReturnAuctionMsgBox::InvalidateDeviceObjects()
{
	if(m_pBackImg)
	{
		m_pBackImg->InvalidateDeviceObjects();
	}

	if(m_pOkBtn)
	{
		m_pOkBtn->InvalidateDeviceObjects();
	}

	if(m_pCanCelBtn)
	{
		m_pCanCelBtn->InvalidateDeviceObjects();
	}

	if(m_pInchantNum)
	{
		m_pInchantNum->InvalidateDeviceObjects();
	}

	if(m_pListFont)
	{
		m_pListFont->InvalidateDeviceObjects();
	}

	if(m_pNumEditBox)
	{
		m_pNumEditBox->InvalidateDeviceObjects();
	}

	if(m_pFinalMoneyFont)
	{
		m_pFinalMoneyFont->InvalidateDeviceObjects();
	}

	return S_OK;
}
void CINFReturnAuctionMsgBox::Render()
{
	if(!m_bShow)
	{
		return;
	}

	if(m_pBackImg)
	{
		m_pBackImg->Render();
	}

	{
		CItemInfo* pTempItem = m_pData->pItem;
		// 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경
// 		if(m_pBigIcon)
// 		{
// 			m_pBigIcon->Render();
// 			if(pTempItem && pTempItem->GetEnchantNumber())
// 			{
// 				char buf[62];
// 				sprintf(buf, STRMSG_C_070329_0100, pTempItem->GetEnchantNumber());
// 				m_pInchantNum->DrawText(WINSTART_POS_X + BIG_ICON_POS_X + INCHANTNUM_X,WINSTART_POS_Y + BIG_ICON_POS_Y + 42, GUI_FONT_COLOR, buf, 0L);
// 			}
// 		}
		if(m_pIcon)
		{
			char chIconName[64] = {0, };	
			if(!pTempItem->ShapeItemNum)
			{
				wsprintf(chIconName, "%08d", pTempItem->ItemInfo->SourceIndex);
			}
			else
			{
				ITEM* pShapeItem = g_pDatabase->GetServerItemInfo(pTempItem->ShapeItemNum);
				if(pShapeItem)
				{
					wsprintf(chIconName, "%08d", pShapeItem->SourceIndex);
				}
				else
				{
					wsprintf(chIconName, "%08d", pTempItem->ItemInfo->SourceIndex);
				}
			}		
			m_pIcon->SetIcon(chIconName, WINSTART_POS_X + SMALL_ICON_POS_X, 
										 WINSTART_POS_Y + SMALL_ICON_POS_Y, 1.0f);
			m_pIcon->Render();
		}
		// END 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경
	}

	if(m_pListFont)
	{
		char buf[512] = {0, };
		wsprintf(buf, "%s", m_pData->Name);
		m_pReturnAuctionCenter->ChangeMaxLenString(buf, ITEMLIST_MAXITEMNAME_LEN);
		int nX = m_pListFont->GetStringSize(buf).cx;
		m_pListFont->DrawText(WINSTART_POS_X + LIST_NAME_POS_X + LIST_NAME_WIDTH / 2 - nX / 2,  WINSTART_POS_Y + LIST_NAME_POS_Y, GUI_FONT_COLOR_W, buf);

		char cTemp[512] = {0, };
		if(BIDDING == m_nMode)
		{
			wsprintf(cTemp, "%d", m_pData->pINFO->DAuctionInfo.Price);
			MakeCurrencySeparator(buf, cTemp,3, ',');
			nX = m_pListFont->GetStringSize(buf).cx;
			m_pListFont->DrawText(WINSTART_POS_X + LIST_BIDDING_MONEY_POS_X + LIST_BIDDING_MONEY_WIDTH - nX, WINSTART_POS_Y + LIST_BIDDING_MONEY_POS_Y, GUI_FONT_COLOR_W, buf);

			int nPerCent = NumEditBoxMaxAndMIN(m_pNumEditBox, MAX_PERCENT, TRUE);
			m_nTotalMoney = (m_pData->pINFO->DAuctionInfo.Price + (int)(m_pData->pINFO->DAuctionInfo.Price * (nPerCent * 0.01)));
			wsprintf(cTemp, "%d", m_nTotalMoney);		
			MakeCurrencySeparator(buf, cTemp, 3, ',');
			nX = m_pListFont->GetStringSize(buf).cx;
			m_pListFont->DrawText(WINSTART_POS_X + LIST_BIDDING_MONEY_POS_X + LIST_BIDDING_MONEY_WIDTH - nX, WINSTART_POS_Y + LIST_TOTAL_MONEY_POS_X, GUI_FONT_COLOR_W, buf);
		}

		if(GETITEM == m_nMode)
		{
			wsprintf(buf, "%d", m_pData->pINFO->DAuctionInfo.Price);
			MakeCurrencySeparator(cTemp, buf, 3, ',');
			wsprintf(buf, STRMSG_C_140121_0010, cTemp);			//"\\y낙찰가 (%s) SPI\\y"
			nX = m_pFinalMoneyFont->GetStringSize(buf).cx;
			m_pFinalMoneyFont->DrawText(WINSTART_POS_X + LIST_FINAL_MONEY_POS_X + LIST_FINAL_MONEY_WIDTH / 2 - nX / 2, WINSTART_POS_Y + LIST_FINAL_MONEY_POS_Y, GUI_FONT_COLOR_W, buf);
		}

		if(FAILGETITEM == m_nMode)
		{
			wsprintf(buf, "%d", m_pData->pINFO->DAuctionInfo.Price);
			MakeCurrencySeparator(cTemp, buf, 3, ',');
			// 2014-06-12 by ymjoo 파괴 경매장 추가작업
// 			nX = m_pFinalMoneyFont->GetStringSize(buf).cx;
			wsprintf(buf, "%s", cTemp);
			nX = m_pFinalMoneyFont->GetStringSize(buf).cx;
			// END 2014-06-12 by ymjoo 파괴 경매장 추가작업
			m_pFinalMoneyFont->DrawText(WINSTART_POS_X + LIST_FAILGETITEM_MONEY_POS_X + LIST_FAILGETITEM_MONEY_SIZE_X - nX, WINSTART_POS_Y + LIST_FAILGETITEM_MONEY_POS_Y, GUI_FONT_COLOR_W, buf);

			wsprintf(buf, "%d", m_pData->pINFO->DAuctionInfo.MyTenderPrice);
			MakeCurrencySeparator(cTemp, buf, 3, ',');
			// 2014-06-12 by ymjoo 파괴 경매장 추가작업
// 			nX = m_pFinalMoneyFont->GetStringSize(buf).cx;
			wsprintf(buf, "\\r%s\\r", cTemp);
			nX = m_pFinalMoneyFont->GetStringSize(buf).cx;
			// END 2014-06-12 by ymjoo 파괴 경매장 추가작업
			m_pFinalMoneyFont->DrawText(WINSTART_POS_X + LIST_FAILGETITEM_MONEY_POS_X + LIST_FAILGETITEM_MONEY_SIZE_X - nX, WINSTART_POS_Y + LIST_FAILGETITEM_MYMONEY_POS_Y, GUI_FONT_COLOR_W, buf);
		}

		if(m_pOkBtn)
		{
			m_pOkBtn->Render();
		}
		
		if(m_pCanCelBtn)
		{
			m_pCanCelBtn->Render();
		}
	}

	if(m_pNumEditBox)
	{
		m_pNumEditBox->Render();
	}
}

void CINFReturnAuctionMsgBox::Tick()
{
	if(m_pNumEditBox)
	{
		m_pNumEditBox->Tick();
	}
}

int CINFReturnAuctionMsgBox::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(!m_bShow)
	{
		return INF_MSGPROC_NORMAL;
	}

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
	case WM_LBUTTONDBLCLK:
		{
			return INF_MSGPROC_BREAK;
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
				if(m_pNumEditBox)
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
								m_pNumEditBox->EnableEdit(FALSE);
								NumEditBoxMaxAndMIN(m_pNumEditBox, MAX_PERCENT);
							}
						}
					}
				}

				if(wParam == VK_ESCAPE)
				{
					return INF_MSGPROC_CLOSE;
				}
			}
		}
	}
	return INF_MSGPROC_NORMAL;
}

int CINFReturnAuctionMsgBox::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	if(m_pNumEditBox)
	{
		if(m_pNumEditBox->IsEditMode())
		{
			NumEditBoxMaxAndMIN(m_pNumEditBox, MAX_PERCENT);
		}
		m_pNumEditBox->EnableEdit(FALSE);

		if(TRUE == m_pNumEditBox->OnLButtonDown(pt) )
		{
			m_pNumEditBox->EnableEdit(TRUE);
			return INF_MSGPROC_BREAK;				
		}
	}

	if(TRUE == m_pOkBtn->OnLButtonDown(pt))
	{
		return INF_MSGPROC_BREAK;
	}	
	
	if(m_pCanCelBtn && TRUE == m_pCanCelBtn->OnLButtonDown(pt))
	{
		return INF_MSGPROC_BREAK;
	}	

	return INF_MSGPROC_BREAK;
}

int CINFReturnAuctionMsgBox::OnLButtonUp(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	if(TRUE == m_pOkBtn->OnLButtonUp(pt))
	{
		OkBtnDown(m_nMode);
		return INF_MSGPROC_CLOSE;
	}	

	if(m_pCanCelBtn && TRUE == m_pCanCelBtn->OnLButtonUp(pt))
	{
		return INF_MSGPROC_CLOSE;
	}	

	return INF_MSGPROC_BREAK;
}

int CINFReturnAuctionMsgBox::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);

	if(m_pOkBtn)
	{
		m_pOkBtn->OnMouseMove(pt);
	}
	if(m_pCanCelBtn)
	{
		m_pCanCelBtn->OnMouseMove(pt);
	}

	// 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경
// 	if(m_pBigIcon
// 		&& WINSTART_POS_X + BIG_ICON_POS_X < pt.x && pt.x < WINSTART_POS_X + BIG_ICON_POS_X + m_pBigIcon->GetImgSize().x
// 		&& WINSTART_POS_Y + BIG_ICON_POS_Y < pt.y && pt.y < WINSTART_POS_Y + BIG_ICON_POS_Y + m_pBigIcon->GetImgSize().y)
// 	{
// 		if(m_nCurerntInfo != m_pData->pItem)
// 		{
// 			g_pGameMain->SetItemInfoUser(m_pData->pItem, pt.x, pt.y);
// 		}
// 		m_nCurerntInfo = m_pData->pItem;
// 	}
	if(m_pIcon
		&& WINSTART_POS_X + SMALL_ICON_POS_X < pt.x && pt.x < WINSTART_POS_X + SMALL_ICON_POS_X + m_pIcon->GetIconSize().x
		&& WINSTART_POS_Y + SMALL_ICON_POS_Y < pt.y && pt.y < WINSTART_POS_Y + SMALL_ICON_POS_Y + m_pIcon->GetIconSize().y)
	{
		if(m_nCurerntInfo != m_pData->pItem)
		{
			g_pGameMain->SetItemInfoUser(m_pData->pItem, pt.x, pt.y);
		}
		m_nCurerntInfo = m_pData->pItem;
	}
	// END 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경
	else
	{
		m_nCurerntInfo = NULL;
	}
	
	if(!m_nCurerntInfo)
	{
		g_pGameMain->SetItemInfoUser(NULL, 0, 0);
	}
	
	return INF_MSGPROC_BREAK;
}

int CINFReturnAuctionMsgBox::OnMouseWheel(WPARAM wParam, LPARAM lParam)
{
	int nCnt = 0;
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	CheckMouseReverse(&pt);
	
	return INF_MSGPROC_BREAK;
}

void CINFReturnAuctionMsgBox::SetBtnPos()
{
	if(m_pBackImg)
	{
		m_pBackImg->Move(WINSTART_POS_X, WINSTART_POS_Y);
	}

	if(m_pOkBtn)
	{
		if(FAILGETITEM != m_nMode)
		{
			m_pOkBtn->SetBtnPosition(WINSTART_POS_X + OK_BTN_POS_X, WINSTART_POS_Y + OK_BTN_POS_Y);
		}
		else
		{
			m_pOkBtn->SetBtnPosition(WINSTART_POS_X + OK_BTN_FAILGETITEM_POS_X, WINSTART_POS_Y + OK_BTN_FAILGETITEM_POS_Y);
		}
	}

	if(m_pCanCelBtn)
	{
		m_pCanCelBtn->SetBtnPosition(WINSTART_POS_X + CANCEL_BTN_POS_X, WINSTART_POS_Y + CANCEL_BTN_POS_Y);
	}

	// 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경 (주석 처리)
// 	if(m_pBigIcon)
// 	{
// 		m_pBigIcon->Move(WINSTART_POS_X + BIG_ICON_POS_X, WINSTART_POS_Y + BIG_ICON_POS_Y);
// 	}
	// END 2014-07-11 by ymjoo 파괴경매장 빅아이콘을 스몰아이콘으로 변경

	if(m_pNumEditBox)
	{
		m_pNumEditBox->SetPos(WINSTART_POS_X + NUMEDITBOX_POS_X, WINSTART_POS_Y + NUMEDITBOX_POS_Y);
		NumEditBoxChangeCount(m_pNumEditBox, 1);
		m_pNumEditBox->EnableEdit(FALSE);
	}
}

void CINFReturnAuctionMsgBox::OkBtnDown(int nMode)
{
	switch(nMode)
	{
	case ITEMNONE : 
		{
			return;
		}
		break;
	case BIDDING :
		{
			MSG_FC_DESTROY_AUCTION_TENDER_REQUEST sMsg;
			memset(&sMsg, 0x00, sizeof(sMsg));
			
			sMsg.DAuctionUID	= m_pData->pINFO->DAuctionInfo.DAuctionUID;
			sMsg.AccountUID		= g_pD3dApp->m_pShuttleChild->m_myShuttleInfo.AccountUniqueNumber;
			sMsg.CharacterUID	= g_pD3dApp->m_pShuttleChild->m_myShuttleInfo.CharacterUniqueNumber;
			sMsg.TenderPrice	= m_nTotalMoney;
						
			g_pFieldWinSocket->SendMsg( T_FC_DESTROY_AUCTION_TENDER_REQUEST, (char*)&sMsg, sizeof(sMsg) );
		}
		break;
	case GETITEM :
		{
			MSG_FC_DESTROY_AUCTION_GET_REQUEST sMsg;
			memset(&sMsg, 0x00, sizeof(sMsg));

			sMsg.DAuctionGetPossibleTime	= m_pData->pINFO->DAuctionInfo.DAuctionEndTime;
			sMsg.DAuctionStatus				= AUCTION_ITEM_STATE_END;
			sMsg.DAuctionUID				= m_pData->pINFO->DAuctionInfo.DAuctionUID;
			sMsg.ItemUID					= m_pData->pINFO->DAuctionInfo.ItemUID;
			sMsg.Price						= m_pData->pINFO->DAuctionInfo.Price;

			g_pFieldWinSocket->SendMsg( T_FC_DESTROY_AUCTION_GET_REQUEST, (char*)&sMsg, sizeof(sMsg) );
		}
		break;
	case FAILGETITEM :
		{
		}
		break;
	}
}

void CINFReturnAuctionMsgBox::ShowWnd(BOOL bShow)
{
	m_bShow = bShow;
	if(m_bShow)
	{
	}
	else
	{
	} 	
}

void CINFReturnAuctionMsgBox::NumEditBoxChangeCount(CINFNumEditBox* pNumEditBox, int nNum)
{
	char chBuff[32];
	wsprintf(chBuff, "%d", nNum);		
	pNumEditBox->SetString(chBuff, 32);
} 

int CINFReturnAuctionMsgBox::NumEditBoxMaxAndMIN(CINFNumEditBox* pNumEditBox, int nMaxCount, BOOL bTick)
{
	if(!pNumEditBox)
	{
		return 0;
	}
	INT nMixCounts = 0;
	char chBuff[256] = {0, };
	pNumEditBox->GetString(chBuff, 256);
	
	int nLen = strlen(chBuff);
	if(10 < nLen)
	{
		nMixCounts = MAX_PERCENT;
	}
	else if(10 == nLen && 49 != chBuff[0])
	{
		nMixCounts = MAX_PERCENT;
	}
	else
	{
		nMixCounts = atoi(chBuff);
	}
	
	if(nMixCounts <= 0)
	{
		nMixCounts = bTick ? 0 : 1;
	}
	else if(nMaxCount < nMixCounts)
	{
		nMixCounts = nMaxCount;
	}
	NumEditBoxChangeCount(pNumEditBox, nMixCounts);
	
	return nMixCounts;
}