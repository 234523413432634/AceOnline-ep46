// H323Connection.cpp: implementation of the CH323Connection class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "H323Connection.h"
#include "RTPCtrl.h"
#include "SCDialer1Ctl.h"				// 2008-10-22 by cmkwon, SCDialer1, SCDialer2 ���� - 

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//
//
//

/*
// Constructin Parameter 
typedef enum
{
	t_PCMU		= 0,
	t_G7231Low	= 50,		// G.7231 Low
	t_G7231		= 4,		// G.7231 High
	t_PCMA		= 8,
	t_G722		= 9, 
	t_G728		= 15,
	t_G729		= 18,
	t_H261		= 31,
	t_H263		= 34
} MediaType;
//*/

//////////////////////////////////////////////////////////////////////////////////////////////////
// Construction(MediaType audioPayload, MediaType videoPayload, int nFrameCount, int JitterBufferSize)
// 
// - CH323Connection �� ������ 
// - Ŭ������ ��� ������ �ʱ�ȭ �ϰ� _Initialize�Լ��� ȣ���Ѵ�.
// - audioPayload �� ���ῡ ����� Audio Codec Type
// - videoPayload �� ���ῡ ����� Video Codec Type
// - InbandDTMF �� Inband DTMF�� ���� Flag
// - nFrameCount �� �ϳ��� RTP Packet���� ������ Audio Frame �� ����( 1 ~ 5 ������ ���̾����)
// - JitterBufferSize �� ���͹����� Play ����� ��Ÿ����( 4 ~ 10 ������ ���� ������)
//////////////////////////////////////////////////////////////////////////////////////////////////

// 2008-10-22 by cmkwon, SCDialer1, SCDialer2 ���� - �����߰�(CSCDialer1Ctrl *i_pDialer1)
CH323Connection::CH323Connection(CSCDialer1Ctrl *i_pDialer1, MediaType audioPayload, MediaType videoPayload, BOOL InbandDTMF, int nFrameCount, int JitterBufferSize
								 , HWND hCtrl, BOOL bSerial, int nSerialPort, int nTermperSecond)
{
#ifdef _KWON_DEBUG
	TRACE("\n\n===============================================================");
	TRACE("\n==> CH323Connection Constructor");
#endif

	SetAudioPayloadType(audioPayload);		// ���ῡ ����� Audio Codec Type setting
	SetVideoPayloadType(videoPayload);		// ���ῡ ����� Video Codec Type setting

	m_ConnType = t_NULL;

	if(audioPayload != t_NULL && videoPayload != t_NULL)
	{
		m_ConnType = t_AudioAndVideo;						// Both Audio and Video
	}
	else if(videoPayload == t_NULL)
	{	
		m_ConnType = t_Audio;								// Only Audio
	}
	else 
	{
		m_ConnType = t_Video;								// Only Video
	}
	
	m_pAudioSound		= NULL;
	m_pRTPCtrlManager	= NULL;	

	memset(&m_bitFlag, 0x00, sizeof(BitFlag));				// 
	m_bitFlag.InbandDTMF = InbandDTMF;

	m_pSCDialer1Ctrl		= i_pDialer1;			// 2008-10-22 by cmkwon, SCDialer1, SCDialer2 ���� - 

	_Initialize(nFrameCount,JitterBufferSize, hCtrl, bSerial, nSerialPort, nTermperSecond);											// Initialization Function
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// ~CH323Connection()
//
// - �Ҹ��� 
// - ��� �������� �Ҹ��Ű�� �۾��� �Ѵ�.
//////////////////////////////////////////////////////////////////////////////////////////////////
CH323Connection::~CH323Connection()
{
#ifdef _KWON_DEBUG
	TRACE("\n==> CH323Connection Destructor");
#endif
	TRACE("\nCH323Connection::~CH323Connection()\n");
	if(m_pAudioSound && m_bitFlag.MixStart == 1)
	{
		// audio rtp buffering starting
		m_pAudioSound->PostThreadMessage(WM_MIX_STOP, 0, 0);				
		m_bitFlag.MixStart = 0;
		Sleep(20);
	}
	if(m_pAudioSound)
	{
		HANDLE	hThread = m_pAudioSound->m_hThread;
		if(hThread)
		{
			Sleep(100);
			m_pAudioSound->PostThreadMessage(WM_AUDIO_ENDTHREAD,0,0);
			::WaitForSingleObject(hThread, 1000);
			m_pAudioSound = NULL;
		}
	}
	
	if(m_pRTPCtrlManager)
	{
		delete m_pRTPCtrlManager;	
		m_pRTPCtrlManager = NULL;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// _Initialize()
//
// - Ŭ������ �����ڿ��� ȣ��Ǵ� �Լ��� ��� ������ �����Ѵ�. 
//////////////////////////////////////////////////////////////////////////////////////////////////
void CH323Connection::_Initialize(int nFrameCount, int JitterBufferSize, HWND hCtrl, BOOL bSerial, int nSerialPort,int nTermperSecond)
{	
	// audio channel�� ���ɶ��� audio ���� Ŭ���� ��ü�� �����Ѵ�.
	TRACE("\nCH323Connection FrameCount=%d, JitterBufferSize=%d bSerial=%d, nSerialPort=%d\n", nFrameCount, JitterBufferSize, bSerial, nSerialPort);
	if( m_ConnType == t_Audio || m_ConnType == t_AudioAndVideo)			
	{
		// ������ �����ϴ� Ŭ���� ���� (thread)
		// 2008-10-22 by cmkwon, SCDialer1, SCDialer2 ���� - �����߰�(, CH323Connection *i_p323Conn)
		m_pAudioSound = new CAudioSound(nFrameCount, JitterBufferSize, hCtrl, bSerial, nSerialPort, nTermperSecond, this);
		if(m_pAudioSound && !m_pAudioSound->CreateThread())		// ������ ����
		{
			AfxMessageBox("m_pAudioSound CreateThread Error!");
			return;
		}		
	}
	
	// RTP Channel �����ϴ� Ŭ������ CRTPCtrlManager ��ü�� ����.
	// ���ڷ� RTP Channel�� audio���� video���� Ȥ�� audio�� video�� �Ѵ� 
	// ����ϴ����� �������� ���ڷ� ����Ѵ�.
	m_pRTPCtrlManager = new CRTPCtrlManager(m_ConnType, m_pAudioSound);		
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// int CH323Connection::CreateRTPSession(UINT Port, MediaType ty, int sNum);
//
// - RTP Channel�� �ϳ� �����.
// - Port �� channel�� open�� ��Ʈ��ȣ�̴�.
// - ty �� Open�� ä���� �̵�� Ÿ��
// - sNum �� RTP channel�� �������̴�.  channel���� �ٸ� �����ڸ� ���ڷ� �ָ�ȴ�.
// - channel�� ����� ���� ������� channel�� data�� ������ �ִ� ���°� �ȴ�.
// - return ���� open �� ä���� �̵�� Ÿ��
//////////////////////////////////////////////////////////////////////////////////////////////////
BOOL CH323Connection::CreateRTPSession(UINT Port, MediaType ty, int sNum)
{
	MediaType Ret = t_NULL ;

	if(!(m_ConnType & ty) || ty == t_AudioAndVideo)
	{
		// ������ H323Connection�� �̵�� Ÿ�԰� CreateRTPSession �� �̵�� Ÿ���� ���� �ʴ´�.
		return Ret;
	}
	
	// audio channel�� ���ɶ� CPlaySoundŬ������  play ���� ���·� �غ��Ű��
	// CMixSoundŬ���� ���� ���۸��� �����ϰ� �غ��Ų��.
	if(ty == t_Audio || ty == t_AudioAndVideo)
	{
		if(m_bitFlag.PlayStart == 0)
		{
			// Play Sound Start before Audio Port open
			m_pAudioSound->PostThreadMessage(WM_PLAY_START, 0, 0);	
			m_bitFlag.PlayStart = 1;
			// Times for Audio Device open
			Sleep(100);
		}

		if(m_bitFlag.MixStart == 0)
		{
			// audio rtp buffering starting
			m_pAudioSound->PostThreadMessage(WM_MIX_START, 0, 0);				
			m_bitFlag.MixStart = 1;
		}
	}

	// rtp channel open
	Ret = m_pRTPCtrlManager->RtpOpen(sNum, ty, Port);

#ifdef _KWON_DEBUG
	TRACE("\n	CreateRTPSession index[%d],  In[%d] ==> return [%d]", sNum, m_ConnType, Ret);	
#endif
	
	if(ty == t_NULL)
	{
		return FALSE;
	}
	
	return TRUE;		
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// int CH323Connection::StartRTPSession(char* ip, UINT port, MediaType ty, int sNum)
//
// - channel�� ���� IP Address��  Port�� �����Ѵ�.
// - ip �� RTP ����Ÿ�� ������ ������ IP Address
// - port �� RTP ����Ÿ�� ������ ������ Port
// - ty �� Start�� ä���� �̵�� Ÿ��
// - sNum �� channel�� �����ڷ� �̹� ������� channel�� �����ڸ� �޴´�.
// - return ���� Start �� ä���� �̵�� Ÿ��
//////////////////////////////////////////////////////////////////////////////////////////////////
BOOL CH323Connection::StartRTPSession(char* ip, UINT port, MediaType ty, int sNum)
{
	MediaType Ret = t_NULL ;

	if(!(m_ConnType & ty) || ty == t_AudioAndVideo)
	{
		// ������ H323Connection�� �̵�� Ÿ�԰� StartRTPSession �� �̵�� Ÿ���� ���� �ʴ´�.
		return Ret;
	}

#ifdef _KWON_DEBUG
		TRACE("\n	StartRTPSession MediaType[%d] index[%d] Destination IP:%s,  Audio Port:%d", ty, sNum, ip, port);
#endif		

	// ���� IP Address�� Video Port�� �����Ѵ�.
	Ret = m_pRTPCtrlManager->RTPStart(sNum, ip, ty, port);
	
	// audio channel���� sound recording�� �����Ѵ�.
	if(ty == t_Audio && m_bitFlag.RecordStart == 0 )
	{		
		m_pAudioSound->PostThreadMessage(WM_RECORD_START, (WPARAM)NULL, (LPARAM)m_pRTPCtrlManager );
		m_bitFlag.RecordStart = 1;
	}
	
	if(ty == t_NULL)
	{
		return FALSE;
	}
	
	return TRUE;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// int CH323Connection::EndRTPSession(MediaType ty, int sNum);
//
// - �̹� ������� channel �� �ݴ� �Լ��̴�.
// - ������ sNum�� ������� channel�� �������̴�.
//////////////////////////////////////////////////////////////////////////////////////////////////
BOOL CH323Connection::EndRTPSession(MediaType ty, int sNum)
{	
	int count;
	MediaType	Ret = t_NULL;

	if(!(m_ConnType & ty) || ty == t_AudioAndVideo)
	{
		// ������ H323Connection�� �̵�� Ÿ�԰� StartRTPSession �� �̵�� Ÿ���� ���� �ʴ´�.
		return Ret;
	}

	if(ty == t_Audio)
	{
		// ���� ����Ǿ� �ִ� Audio session�� count�� ���Ѵ�.
		count = m_pRTPCtrlManager->GetSessionCount(ty);
		
#ifdef _KWON_DEBUG
		if(count > 0)
		{
			TRACE("\n	EndRTPSession Audio index[%d] SessionCount[%d]", sNum, count);
		}
#endif		
		// audio channel�� ����ϰ� ���� ����� session�� count�� 1�̸� 		
		if(count <= 1)
		{
			if(m_bitFlag.RecordStart)
			{
				m_pAudioSound->PostThreadMessage(WM_RECORD_STOP, 0L, 0L);
				m_bitFlag.RecordStart = 0;
				Sleep(100);
			}

			// ������ rtp channel�� �ݴ´�.
			Ret = m_pRTPCtrlManager->RTPEnd(sNum, ty);
			
			//if(m_bitFlag.MixStart)
			//{
			//	m_pAudioSound->PostThreadMessage(WM_MIX_STOP, 0, 0);
			//	m_bitFlag.MixStart = 0;				
			//}

			if(m_bitFlag.PlayStart)
			{
				m_pAudioSound->PostThreadMessage(WM_PLAY_STOP,0L,0L);
				m_bitFlag.PlayStart = 0;
			}						
		}
		else if( count > 1)
		{
			int idx = m_pRTPCtrlManager->SessionToIndex(ty, sNum);
			// ������ rtp channel�� �ݴ´�.
			Ret = m_pRTPCtrlManager->RTPEnd(sNum, ty);

			m_pAudioSound->PostThreadMessage(WM_MIX_ENDRTPSESSION, 0, idx);
		}

	}
	else
	{
		// ���� ����Ǿ� �ִ� Video session�� count�� ���Ѵ�.
		count = m_pRTPCtrlManager->GetSessionCount(ty);
#ifdef _KWON_DEBUG
		TRACE("\n	EndRTPSession Video index[%d] SessionCount[%d]", sNum, count);
#endif
		// ������ rtp channel�� �ݴ´�.
		Ret = m_pRTPCtrlManager->RTPEnd(sNum, ty);

	}
	
	if(ty == t_NULL)
	{
		return FALSE;
	}
	
	return TRUE;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// int	CH323Connection::EndAllRTPSession();
//
// - ���� ����� session�� ��� �ݴ´�.
//////////////////////////////////////////////////////////////////////////////////////////////////
int	CH323Connection::EndAllRTPSession()
{
	int r;
	
	// audio channel�� ����Ѵٸ� audio recording�� audio playing�� �����.
	if(m_ConnType == t_Audio || m_ConnType == t_AudioAndVideo)
	{
		m_pAudioSound->PostThreadMessage(WM_RECORD_STOP, 0L, 0L);
		m_bitFlag.RecordStart = 0;
		Sleep(100);
				
		// ��� rtp channel�� �ݴ´�.
		if(m_pRTPCtrlManager){ r = m_pRTPCtrlManager->ALLRTPEnd();}
		
		//if(m_bitFlag.MixStart)
		//{
		//	m_pAudioSound->PostThreadMessage(WM_MIX_STOP, 0, 0);
		//	m_bitFlag.MixStart = 0;
		//	Sleep(100);
		//}
		
		m_pAudioSound->PostThreadMessage(WM_PLAY_STOP,0L,0L);
		m_bitFlag.PlayStart = 0;				
	}
	else
	{
		// ��� rtp channel�� �ݴ´�.
		r = m_pRTPCtrlManager->ALLRTPEnd();
	}	

	return r;
}


//////////////////////////////////////////////////////////////////////
// UINT CH323Connection::GetLocalAudioPort(int sNum);
//
// - ���ڷ� ���� sNum�� �����ڸ� ���� channel�� ������ Audio port�� �����Ѵ�.
//////////////////////////////////////////////////////////////////////
UINT CH323Connection::GetLocalAudioPort(int sNum)
{
	return m_pRTPCtrlManager->GetLocalPort(sNum, t_Audio);
}


//////////////////////////////////////////////////////////////////////
// UINT CH323Connection::GetLocalVideoPort(int sNum)
//
// - ���ڷ� ���� sNum�� �����ڸ� ���� channel�� ������ Video port�� �����Ѵ�.
//////////////////////////////////////////////////////////////////////
UINT CH323Connection::GetLocalVideoPort(int sNum)
{
	return m_pRTPCtrlManager->GetLocalPort(sNum, t_Video);
}

//////////////////////////////////////////////////////////////////////
// UINT CH323Connection::GetLocalVideoPort(int sNum)
//
// - ���ڷ� ���� sNum�� �����ڸ� ���� channel�� ������ Video port�� �����Ѵ�.
//////////////////////////////////////////////////////////////////////
UINT CH323Connection::GetLocalPort(MediaType ty, int sNum)
{
	return m_pRTPCtrlManager->GetLocalPort(sNum, ty);
}


//////////////////////////////////////////////////////////////////////
// int CH323Connection::SendVideoData(BYTE *Data, DWORD dwSize, int ty);
//
// - Video Data�� rtp channel�� ������.
//////////////////////////////////////////////////////////////////////
int CH323Connection::SendVideoData(BYTE *Data, DWORD dwSize)
{
	return m_pRTPCtrlManager->SendRTPData(Data, dwSize, t_Video);
}



//////////////////////////////////////////////////////////////////////
// SendDTMF(int number);
//
// - ���濡 DTMF�� RTP Packet���� ������.( In-band )
// - m_bitFlag.InbandDTMF �÷��װ� TRUE �϶� In-band �� �����Ѵ�
// - number �� ���� �� DTMF �� ���ڿ��� �޾Ƽ� �޼����� ������ int������ ����
//////////////////////////////////////////////////////////////////////
void CH323Connection::SendDTMF(const char* number)
{
	if(m_pAudioSound && m_bitFlag.InbandDTMF)
	{
		m_pAudioSound->PostThreadMessage(WM_RECORD_SENDDTMF, 0L, atoi(number));
	}
}



#ifdef	_LOCAL_PLAY_G7231
//////////////////////////////////////////////////////////////////////
// void CH323Connection::PlayRingBackTone(BOOL bIN);
//
// - Ringback Tone�� ��ü������ Play �Ѵ�.
// - ������ bIN�� ���̸� Ringback Tone play�� �����ϰ� �����̸� play�� �����.
// - windows98���� PlaySound()�Լ��� �������� ������ �����. 
// - nFlag : 0 �̸� Ring back tone play, 1 �̸� �ȳ���Ʈ play
//////////////////////////////////////////////////////////////////////
void CH323Connection::LocalPlayG7231(int nFlag, BOOL bIN)
{	
	TRACE("\nLocalPlayG7231(%d,%d)\n",nFlag,bIN);
	if(bIN)
	{		
		if(m_bitFlag.PlayStart == 0)
		{
			// Play Sound Start before Audio Port open
			m_pAudioSound->PostThreadMessage(WM_PLAY_START, 0, 0);	
			m_bitFlag.PlayStart = 1;
			// Times for Audio Device open
			Sleep(50);
		}
		
		if(m_bitFlag.MixStart == 0)
		{
			// audio rtp buffering starting
			m_pAudioSound->PostThreadMessage(WM_MIX_START, 0, 0);				
			m_bitFlag.MixStart = 1;				
		}
	}
	else
	{
		/*
		// ���� ����Ǿ� �ִ� Audio session�� count�� ���Ѵ�.			
		if(!m_pRTPCtrlManager->GetSessionCount(t_Audio))
		{
			if(m_bitFlag.PlayStart)
			{
				m_pAudioSound->PostThreadMessage(WM_PLAY_STOP,0L,0L);
				m_bitFlag.PlayStart = 0;
			}
		}
		//*/
	}
				
	m_pAudioSound->PostThreadMessage(WM_MIX_LOCALPLAYG7231, nFlag, bIN); // 	
}
#endif

//////////////////////////////////////////////////////////////////////
// void CH323Connection::SendMuteAudioRTP(BOOL bIN);
//
// - ������ ������.
//////////////////////////////////////////////////////////////////////
void CH323Connection::SendMuteAudioRTP(BOOL bIN)
{
	if(m_pAudioSound)
	{
		m_pAudioSound->PostThreadMessage(WM_RECORD_SENDMUTEAUDIORTP, (WPARAM)0, (LPARAM)bIN );
	}
}

//////////////////////////////////////////////////////////////////////
// BOOL CH323Connection::SetVideoDecoder(void *de);
//
// - 
//////////////////////////////////////////////////////////////////////
BOOL CH323Connection::SetVideoDecoder(void *de)
{
	m_pRTPCtrlManager->SettingPARAM(de, t_Video);		// 2 is Video
	return TRUE;
}



#ifdef	_RECORDING_FILE
//////////////////////////////////////////////////////////////////////
// void CH323Connection::SetRecordingFilePointer(FILE* pfA, FILE* pfC)
//
// - ���뿡 �ʿ��� file pointer�� �����ϴ� ������
// - pfA�� Agent�� file pointer (�ڽ��� ����)
// - pfC�� Client�� file pointer (���� ����)
//////////////////////////////////////////////////////////////////////
void CH323Connection::SetRecordingFilePointer(FILE* pfA, FILE* pfC)
{
	if(m_pAudioSound && m_pMixSound)
	{
		m_pAudioSound->PostThreadMessage(WM_RECORDSOUND_RECORDINGFILEPOINTER, (WPARAM)NULL, (LPARAM)pfA);
		m_pMixSound->PostThreadMessage(WM_MIXSOUND_RECORDINGFILEPOINTER, (WPARAM)NULL, (LPARAM)pfC);
	}	
}

//////////////////////////////////////////////////////////////////////
// void CH323Connection::PlayRecordingFile(FILE* pfA, FILE* pfC)
//
// - ������ �� file�� play �ϴ� �Լ��� 
// - �� ȭ���� ������ �Ŀ� �ٷ� �÷��̸� �����Ѵ�.
// - pfA�� Agent�� file pointer
// - pfC�� Client�� file pointer
//////////////////////////////////////////////////////////////////////
void CH323Connection::PlayRecordingFile(FILE* pfA, FILE* pfC)
{
	if(m_pPlaySound && m_pMixSound)
	{
		
		if(m_bitFlag.PlayStart == 0)
		{
			// Play Sound Start before Audio Port open
			m_pPlaySound->PostThreadMessage(WM_PLAYSOUND_STARTPLAYING, 0, 0);	
			m_bitFlag.PlayStart = 1;
			// Times for Audio Device open
			Sleep(100);
		}						
		
		m_pMixSound->PostThreadMessage(WM_MIXSOUND_SETPLAYRECORDINGFILE, (WPARAM)pfA, (LPARAM)pfC);

		if(m_bitFlag.MixStart == 0)
		{
			// audio rtp buffering starting
			m_pMixSound->PostThreadMessage(WM_MIXSOUND_STARTMIXTHREAD, 0, 0);				
			m_bitFlag.MixStart = 1;
		}
	}
}	
#endif

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CH323Connection::GetPlayVolumeW(BYTE *o_pbyVolPercent)
/// \brief		// 2008-06-12 by cmkwon, SCVoIP.exe �� Volume ���� ��� �߰� - 
/// \author		cmkwon
/// \date		2008-06-12 ~ 2008-06-12
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CH323Connection::GetPlayVolumeW(BYTE *o_pbyVolPercent)
{
	if(NULL == m_pAudioSound)
	{
		return FALSE;
	}
	return m_pAudioSound->GetPlayVolume(o_pbyVolPercent);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			BOOL CH323Connection::SetPlayVolumeW(BYTE i_byVolPercent)
/// \brief		// 2008-06-12 by cmkwon, SCVoIP.exe �� Volume ���� ��� �߰� - 
/// \author		cmkwon
/// \date		2008-06-12 ~ 2008-06-12
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
BOOL CH323Connection::SetPlayVolumeW(BYTE i_byVolPercent)
{
	if(NULL == m_pAudioSound)
	{
		return FALSE;
	}
	return m_pAudioSound->SetPlayVolume(i_byVolPercent);
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			void CH323Connection::OnVolumeW(BOOL i_bIsSpkDevice, BYTE i_byVolPercent)
/// \brief		// 2008-10-22 by cmkwon, SCDialer1, SCDialer2 ���� - 
/// \author		cmkwon
/// \date		2008-10-22 ~ 2008-10-22
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CH323Connection::OnVolumeW(BOOL i_bIsSpkDevice, BYTE i_byVolPercent)
{
	m_pSCDialer1Ctrl->OnVolume(i_bIsSpkDevice, i_byVolPercent);	
}

CString CH323Connection::CheckAudioDevice()
{
	CString strDeviceList;
	CString strDevice;
	UINT num = ::waveOutGetNumDevs();
	for(UINT id = 0; id < num; id++)
	{
		WAVEOUTCAPS wodc;
		::waveOutGetDevCaps(id, &wodc, sizeof(WAVEOUTCAPS));
		
		strDevice.Format("%s", wodc.szPname);	
		strDeviceList += strDevice;
		strDeviceList += ";";
	} 

	strDeviceList.Delete(strDeviceList.GetLength() - 1);

	strDeviceList += ",";

	num = ::waveInGetNumDevs();
	for(id = 0; id < num; id++)
	{
		WAVEINCAPS widc;
		::waveInGetDevCaps(id, &widc, sizeof(WAVEINCAPS));

		strDevice.Format("%s", widc.szPname);
		strDeviceList += strDevice;
		strDeviceList += ";";
	}

	strDeviceList.Delete(strDeviceList.GetLength() - 1);

	return strDeviceList;
}

BOOL CH323Connection::SetRecordSoundDevice(CString strDevice)
{
	if(m_pAudioSound)
	{
		return m_pAudioSound->SetRecordSoundDevice(strDevice);		
	}
	return FALSE;
}

BOOL CH323Connection::SetPlaySoundDevice(CString strDevice)
{
	if(m_pAudioSound)
	{
		return m_pAudioSound->SetPlaySoundDevice(strDevice);		
	}
	return FALSE;
}

void CH323Connection::SerialPhoneMessage(DWORD dwMsg)
{
	if(m_pAudioSound)
	{
		m_pAudioSound->PostThreadMessage(WM_SERIAL_MESSAGE, 0, dwMsg);
	}
}

void CH323Connection::SetInBandDTMF(BOOL bInBand)
{
	m_bitFlag.InbandDTMF = bInBand;
}

void CH323Connection::ShowVolumeConfig(short nMode)
{
	if(m_pAudioSound)
		m_pAudioSound->ShowVolumeConfig(nMode);
}

void CH323Connection::SetKeepAliveSerial(CString strAliveKeyList)
{

	TRACE("\n[SetKeepAliveKey] Key = %s, m_pAudioSound - 0x%0x\n", strAliveKeyList, m_pAudioSound);


	if(!m_pAudioSound)
		return;

	CStringArray arrayTemp;
	int count = ParseData(strAliveKeyList, ',', &arrayTemp);
	if(count > 1)
	{
		CStringArray arrayValid;
		count = ParseData(arrayTemp.GetAt(0), ';', &arrayValid);
		if(count == 2)
		{
			m_pAudioSound->m_nKeepAliveHookOn = atoi(arrayValid.GetAt(0));
			m_pAudioSound->m_nKeepAliveHookOff = atoi(arrayValid.GetAt(1));
			TRACE("\n[SetKeepAliveKey] ValidKey : HookOn(%d), HookOff(%d)\n", m_pAudioSound->m_nKeepAliveHookOn, m_pAudioSound->m_nKeepAliveHookOff);
		}
		count = ParseData(arrayTemp.GetAt(1), ';', &m_pAudioSound->m_arrayInvalidKeepAliveList);
		TRACE("\n[SetKeepAliveKey] InValidKey : %s, Count = %d\n", arrayTemp.GetAt(1), m_pAudioSound->m_arrayInvalidKeepAliveList.GetSize());
	}
}

int CH323Connection::ParseData(CString str, char sep, CStringArray *array)
{
	int start = 0;
	int step = 0;
	int count = 0;
	array->RemoveAll();

	if(str.Right(1) != sep)
		str += sep;

	do
	{
		step = str.Find(sep, start);
		array->Add(str.Mid(start, step - start));
		start = step + 1;
		count++;
	}while(start < str.GetLength());

	int size = array->GetSize();
	if(size > 9 )
	{
		for(int i=0; i<size; i++)
		{
			CString str = array->GetAt(i);
			str.Remove(' ');
			array->SetAt(i, str); 
		}	
	}
	
	return count;

}

void CH323Connection::SetBusyTone(BOOL bUse)
{
	if(m_pAudioSound)
		m_pAudioSound->m_bSerialBusytoneReady = bUse;
}

BOOL CH323Connection::LogRecordStart()
{
/*	LocalPlayG7231(0, FALSE);

	if(m_pAudioSound && m_pAudioSound->m_pRawFile)
	{
		m_pAudioSound->m_pRawFile->Close(); 
		delete m_pAudioSound->m_pRawFile; 
		m_pAudioSound->m_pRawFile = NULL;
	}
	m_pAudioSound->m_pRawFile = new CFile();
	if(m_pAudioSound->m_pRawFile->Open("record.raw", CFile::modeCreate | CFile::modeWrite | CFile::shareDenyWrite) != 0)
	{
		CreateRTPSession(4010, t_Audio, 0);
		StartRTPSession("127.0.0.1", 4010, t_Audio, 0);
		m_pAudioSound->m_bLogWriteFile = TRUE;
	}
	else
	{
		delete m_pAudioSound->m_pRawFile;
		m_pAudioSound->m_pRawFile = NULL;
		m_pAudioSound->m_bLogWriteFile = FALSE;
		AfxMessageBox("ȭ���� Open�Ҽ� �����ϴ�.");
		return FALSE;
	}
*/
	return TRUE;
}

BOOL CH323Connection::LogRecordStop()
{
/*	EndAllRTPSession();		
	
	if(m_pAudioSound && m_pAudioSound->m_pRawFile)
	{
		m_pAudioSound->m_bLogWriteFile = FALSE;
		m_pAudioSound->m_pRawFile->Close();
		delete m_pAudioSound->m_pRawFile;
		m_pAudioSound->m_pRawFile = NULL;
	}
*/
	return TRUE;
}

BOOL CH323Connection::LogPlayStart()
{
	LocalPlayG7231(0, FALSE);

/*	if(m_pAudioSound && m_pAudioSound->m_pRawFile)
	{
		m_pAudioSound->m_pRawFile->Close();
		delete m_pAudioSound->m_pRawFile;
		m_pAudioSound->m_pRawFile = NULL;
	}
	
	m_pAudioSound->m_pRawFile = new CFile();
	if(m_pAudioSound->m_pRawFile->Open("record.raw", CFile::modeNoTruncate | CFile::modeRead) != 0)
	{
		m_pAudioSound->m_pRawFile->SeekToBegin(); 
		CreateRTPSession(4010, t_Audio, 0);
		StartRTPSession("127.0.0.1", 4010, t_Audio, 0);
	}
	else
	{
		delete m_pAudioSound->m_pRawFile;
		m_pAudioSound->m_pRawFile = NULL;
		AfxMessageBox("ȭ���� Open�Ҽ� �����ϴ�.");
		return FALSE;
	}
*/
	if(m_pAudioSound)
	{
		CreateRTPSession(5010, t_Audio, 0);
		StartRTPSession("127.0.0.1", 5010, t_Audio, 0);
	}
	return TRUE;
}

BOOL CH323Connection::LogPlayStop()
{
	if(m_pAudioSound)
	{
		EndAllRTPSession();
	}	
	
	return TRUE;
}

#ifdef _ECHO_CANCELLER
//////////////////////////////////////////////////////////////////////////
// cmkwon 2003.09.05�� �߰�
// EchoCanceller�� ������ �����ϴ� �Լ�
// bFlag�� ����� TRUE�� �ϸ��
// nOffset�� ��ġ�� ���� �ٸ��� ����
//		- Windows Audio ��ġ�� �̿��� ��� 1�� �ϸ��
void CH323Connection::ApplyEchoCanceller(BOOL bFlag, int nOffset)
{
	if(NULL == m_pAudioSound){	return;}

	m_pAudioSound->InitEchoCanceller(bFlag, nOffset);
}
#endif

void CH323Connection::LogEnable()
{
	if(m_pAudioSound)
	{
		m_pAudioSound->m_bSerialTestMode = TRUE;
	}	
}

void CH323Connection::LogDisable()
{
	if(m_pAudioSound)
	{
		m_pAudioSound->m_bSerialTestMode = FALSE;
	}	
}