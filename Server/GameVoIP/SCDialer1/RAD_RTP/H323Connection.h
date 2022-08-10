// H323Connection.h: interface for the CH323Connection class.
//
//////////////////////////////////////////////////////////////////////



#if !defined(AFX_H323CONNECTION_H__F20BD5BF_5AF8_40E2_A028_3C301488B941__INCLUDED_)
#define AFX_H323CONNECTION_H__F20BD5BF_5AF8_40E2_A028_3C301488B941__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*///////////////////////////////////////////////////////////////////////
 		CH323Connection class
 
  1. Project->Settings->C/C++->Project Options�� ���� include�� �߰��Ѵ�. 
 
 		/I "." /I "./RAD_RTP" /I "./RAD_RTP/include"
 
 
  2. ���� Project->Settings->C/C++->Preprocessor Definitions ��ġ�� 
     �����ؾ� �ϴ� ��

	 1) Audio Codec Type     
 			Audio Codec G.723.1 ==>  _G7231CODEC
 						G.729   ==>  _G729CODEC

  
  3. �ʿ�� Project->Settings->C/C++->Preprocessor Definitions ��ġ�� 
     �����Ͽ� ����Ҽ� �ִ� ���

     1) _LOCAL_PLAY_G7231
		- Ringback tone, �λ縻�� Play�ϴµ� ����Ѵ�.
	 
	 2) _RECORDING_FILE
		- 1:1 ���� ��ȭ�� ȭ�Ϸ� �����ϱ� ���� ���
		
      
 ///////////////////////////////////////////////////////////////////////////////*/

#include "AudioSound.h"
#include "RTPCtrlManager.h"
#include "INCLUDE\rvcommon.h"	// Added by ClassView

class CSCDialer1Ctrl;			// 2008-10-22 by cmkwon, SCDialer1, SCDialer2 ���� - 
class CH323Connection  
{
public:
	typedef struct
	{
		unsigned RecordStart:2;
		unsigned PlayStart:2;
		unsigned MixStart:2;
		unsigned InbandDTMF:2;
	} BitFlag;
public:

	// 2008-10-22 by cmkwon, SCDialer1, SCDialer2 ���� - �����߰�(CSCDialer1Ctrl *i_pDialer1)
	CH323Connection(CSCDialer1Ctrl *i_pDialer1, MediaType audioPayload, MediaType videoPayload, BOOL InbandDTMF, int nFrameCount, int JitterBufferSize
		, HWND hCtrl, BOOL bSerial = FALSE, int nSerialPort = 0, int nTermperSecond = -5);
	virtual ~CH323Connection();

public:	
	// log
	BOOL LogPlayStop();
	BOOL LogPlayStart();
	BOOL LogRecordStop();
	BOOL LogRecordStart();
	void LogEnable();
	void LogDisable();

	void SetBusyTone(BOOL bUse);
	int ParseData(CString str, char sep, CStringArray *array);
	void SetKeepAliveSerial(CString strAliveKeyList);
	void ShowVolumeConfig(short nMode);
	void SetInBandDTMF(BOOL bInBand);
	BOOL CreateRTPSession(UINT Port, MediaType ty, int sNum );
	BOOL StartRTPSession(char* ip, UINT Port, MediaType ty, int sNum);
	BOOL EndRTPSession(MediaType ty, int sNum );
	int	EndAllRTPSession();
	UINT GetLocalAudioPort(int sNum);
	UINT GetLocalPort(MediaType ty, int sNum);
	UINT GetLocalVideoPort(int sNum);
	BOOL SetRecordSoundDevice(CString strDevice);
	BOOL SetPlaySoundDevice(CString strDevice);
	CString CheckAudioDevice();

	int		SendVideoData(BYTE* Data, DWORD dwSize);
	BOOL	SetVideoDecoder(void* de);
	DWORD	AudioVolume(BOOL flag, int value);
	void	SendMuteAudioRTP(BOOL bIN);
	void	SendDTMF(const char* number);

	void	SerialPhoneMessage(DWORD dwMsg);

#ifdef _ECHO_CANCELLER
	void ApplyEchoCanceller(BOOL bFlag, int nOffset);
#endif	
#ifdef	_LOCAL_PLAY_G7231
	void	LocalPlayG7231(int nFlag, BOOL bIN);
#endif

#ifdef	_RECORDING_FILE
	void	SetRecordingFilePointer(FILE* pfA, FILE* pfC);
	void	PlayRecordingFile(FILE* pfA, FILE* pfC);
#endif

	///////////////////////////////////////////////////////////////////////////////
	// 2008-06-12 by cmkwon, SCVoIP.exe �� Volume ���� ��� �߰� - 
	BOOL GetPlayVolumeW(BYTE *o_pbyVolPercent);
	BOOL SetPlayVolumeW(BYTE i_byVolPercent);

	void OnVolumeW(BOOL i_bIsSpkDevice, BYTE i_byVolPercent);		// 2008-10-22 by cmkwon, SCDialer1, SCDialer2 ���� - 


private:
	void _Initialize(int nFrameCount, int JitterBufferSize, HWND hCtrl, BOOL bSerial, int nSerialPort, int nTermperSecond);

	CRTPCtrlManager*	m_pRTPCtrlManager;
	CAudioSound*		m_pAudioSound;
	MediaType			m_ConnType;
	BitFlag				m_bitFlag;

	CSCDialer1Ctrl		*m_pSCDialer1Ctrl;		// 2008-10-22 by cmkwon, SCDialer1, SCDialer2 ���� - 
};

#endif // !defined(AFX_H323CONNECTION_H__F20BD5BF_5AF8_40E2_A028_3C301488B941__INCLUDED_)
