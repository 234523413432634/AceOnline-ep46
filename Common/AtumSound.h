// AtumSound.h: interface for the CAtumSound class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ATUMSOUND_H__7A46D706_C6C0_4F7F_985C_BC9415B61698__INCLUDED_)
#define AFX_ATUMSOUND_H__7A46D706_C6C0_4F7F_985C_BC9415B61698__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <dsound.h>

#define MAX_SOUND_FILE_NAME_SIZE			64
#define COUNT_3DSOUND_PLAY_MULTI_BUFFER		4
// 2015-05-15 by jwlee COUNT_3DSOUND_PLAY_MULTI_BUFFER_UPKEEP �߰�
#define COUNT_3DSOUND_PLAY_MULTI_BUFFER_UPKEEP		24
// end 2015-05-15 by jwlee COUNT_3DSOUND_PLAY_MULTI_BUFFER_UPKEEP �߰�

///////////////////////////////////////////////////////////////////////////////
/// \class		CAtumSound
///
/// \brief		Atum�� �������, ����Ʈ ���� ����Ʈ ����
/// \author		dhkwon
/// \version	
/// \date		2004-03-19 ~ 2004-03-19
/// \warning	
///////////////////////////////////////////////////////////////////////////////

// 2009-01-20 by bhsohn ���� �ý��� ����
//class CMusicMP3;
class CMusicMP3Ex;
// end 2009-01-20 by bhsohn ���� �ý��� ����
class CSound;
typedef vector<CSound*>		vectorSoundPtr;
class CSoundManager;
class CAtumSound  
{
public:
	CAtumSound();
	virtual ~CAtumSound();

	HRESULT	InitDeviceObjects();
	HRESULT	DeleteDeviceObjects();
	void	Tick();	
	
	VOID	PlayD3DSound(int nType,D3DXVECTOR3 vPos, BOOL i_b3DSound=TRUE);
	// 2014-12-08 by jwLee ���� ���ܳ����� ���� �ذ�
	//VOID	PlayD3DSound(char * str,D3DXVECTOR3 vPos, BOOL i_b3DSound=TRUE);
	VOID	PlayD3DSound(char * str,D3DXVECTOR3 vPos, BOOL i_b3DSound=TRUE, DWORD dwCreateNumBuffer=COUNT_3DSOUND_PLAY_MULTI_BUFFER);
	// end 2014-12-08 by jwLee ���� ���ܳ����� ���� �ذ�
	VOID	PlayD3DSound(int nType, char* pBuffer, D3DXVECTOR3 vPos, BOOL i_b3DSound=TRUE);
	VOID	StopD3DSound(int nType);
	VOID	StopD3DSound(char * str);
	VOID	CheckD3DSoundGround();
	VOID	PlayBackSound();
	VOID	SetBackMusic(DWORD dwType);
	VOID	SetAtumMusicVolume(int nVolume);

	// 2007-07-24 by bhsohn �����̼� mp3�߰�
	// 2009. 01. 22 by ckPark �� ���º� ���۷����� MP3 �и�
	//VOID	PlayNarrationSound(char* pNarration);
	BOOL	PlayNarrationSound(char* pNarration);
	void	EndNarrationSound();

	CSound * FindSCSoundWithSoundType(int nType);
	HRESULT	 SetResourceFile(char* szFileName);
	// WAVEFORMATEX�� ã�Ƽ� �V���ϰ� , ���� ����Ÿ�� ��ġ�� ���̸� ����
	BYTE * SetWaveFormatEx(BYTE* pbData, DWORD& dwWaveFromLen, WAVEFORMATEX* pwfx );
 	void SetDefaultMusicLoop(BOOL bFlag);

	// 2006-09-07 by ispark
	void	DelD3DSound(int nType);
	void	DelSCSoundWithSoundType(int nType);

	// 2013-02-05 by bhsohn Sound ���� ��񿡼� Exception���� ���� ���� ����
	BOOL	IsSoundDevice(){return m_bNotDevice;}

public:
	BOOL						m_bPlayMusic;
	// 2009-01-20 by bhsohn ���� �ý��� ����
	//CMusicMP3 *					GetMusicMp3(){return  m_pMusic;}
	CMusicMP3Ex *					GetMusicMp3(){return  m_pMusic;}
	// end 2009-01-20 by bhsohn ���� �ý��� ����

protected:
	// 2009-01-20 by bhsohn ���� �ý��� ����
	//CMusicMP3		*			m_pMusic;	
	CMusicMP3Ex		*			m_pMusic;	
	
	// 2007-07-24 by bhsohn �����̼� mp3�߰�
	// 2009-01-20 by bhsohn ���� �ý��� ����
	//CMusicMP3		*			m_pNarrationMusic;	
	CMusicMP3Ex		*			m_pNarrationMusic;	
	BOOL						m_bPlayNarrationMusic;
	char 						m_strNarrationMusic[MAX_SOUND_FILE_NAME_SIZE];			// ��� ���� �̸�

	FLOAT						m_fSetSoundGroundCheckTime;		// Ground �� ��� ���� ���� üũ Ÿ��
	char 						m_strBackMusic[MAX_SOUND_FILE_NAME_SIZE];			// ��� ���� �̸�

	vectorSoundPtr				m_vectorSoundPtr;
	CSoundManager				*m_pSoundManager;
	CSoundManager				*m_p3DSoundManager;
	LPDIRECTSOUND3DLISTENER		m_pDSListener;				   // 3D listener object
	DS3DLISTENER				m_dsListenerParams;             // Listener properties

	CGameData					*m_pGameData;

	int							m_nMusicVolume;
	int							m_nOnlyBackMusicState;
	BOOL						m_bOnlyBackMusic;

	BOOL						m_bNotDevice;					// 2006-09-15 by ispark, ��ġ Ȱ�� ��, ��

	// 2007-07-24 by bhsohn �����̼� mp3�߰�
	//int							m_nSoundType;
};



#endif // !defined(AFX_ATUMSOUND_H__7A46D706_C6C0_4F7F_985C_BC9415B61698__INCLUDED_)
