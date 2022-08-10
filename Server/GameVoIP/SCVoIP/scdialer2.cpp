// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "scdialer2.h"

/////////////////////////////////////////////////////////////////////////////
// CSCDialer2

IMPLEMENT_DYNCREATE(CSCDialer2, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CSCDialer2 properties

CString CSCDialer2::GetStrVDServerIP()
{
	CString result;
	GetProperty(0x1, VT_BSTR, (void*)&result);
	return result;
}

void CSCDialer2::SetStrVDServerIP(LPCTSTR propVal)
{
	SetProperty(0x1, VT_BSTR, propVal);
}

long CSCDialer2::GetUsVDServerPort()
{
	long result;
	GetProperty(0x2, VT_I4, (void*)&result);
	return result;
}

void CSCDialer2::SetUsVDServerPort(long propVal)
{
	SetProperty(0x2, VT_I4, propVal);
}

long CSCDialer2::GetNStatus()
{
	long result;
	GetProperty(0x3, VT_I4, (void*)&result);
	return result;
}

void CSCDialer2::SetNStatus(long propVal)
{
	SetProperty(0x3, VT_I4, propVal);
}

BOOL CSCDialer2::GetAudioSendPause()
{
	BOOL result;
	GetProperty(0x4, VT_BOOL, (void*)&result);
	return result;
}

void CSCDialer2::SetAudioSendPause(BOOL propVal)
{
	SetProperty(0x4, VT_BOOL, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// CSCDialer2 operations

long CSCDialer2::JoinRoom(LPCTSTR szUserName, long* pn64RoomID)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR VTS_PI4;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		szUserName, pn64RoomID);
	return result;
}

void CSCDialer2::GoOutRoom()
{
	InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long CSCDialer2::CreateRoom(LPCTSTR szUserName, long* pn64RoomID)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR VTS_PI4;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		szUserName, pn64RoomID);
	return result;
}

long CSCDialer2::CreateRoomEx(LPCTSTR i_szUserName, long* i_pn64RoomID, long i_nConcurrentTalkingCount)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR VTS_PI4 VTS_I4;
	InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		i_szUserName, i_pn64RoomID, i_nConcurrentTalkingCount);
	return result;
}

long CSCDialer2::SetSpkVolume(long i_nVolumeValueOfPercent)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		i_nVolumeValueOfPercent);
	return result;
}

long CSCDialer2::GetSpkVolume()
{
	long result;
	InvokeHelper(0xa, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}
