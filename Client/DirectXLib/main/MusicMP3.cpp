
#include "MusicMP3.h"
#include <initguid.h>
#include "mp3uuids.h"
#include "FunctionLog.h"
#include "FunctionLogGFunctions.h"



#define SAFE_RELEASE(x) { if (x) x->Release(); x = NULL; }




CMusicMP3::CMusicMP3()
{
	FLOG( "CMusicMP3()" );
	CoInitialize(NULL);
	m_pGB=NULL;
	m_pME = NULL;
	m_pMS = NULL;
//	m_pMC = NULL;
	m_pLPos = 0;
	m_pLStopPos = 0;
	m_ppMS = NULL;
	m_bNowPlay = FALSE;
	m_bDefaultMusic = TRUE;
}


CMusicMP3::~CMusicMP3()
{
	FLOG( "~CMusicMP3()" );
	if(m_pME)
		SAFE_RELEASE(m_pME);
	if(m_pMS)
		SAFE_RELEASE(m_pMS);
//	if(m_pMC)
//		SAFE_RELEASE(m_pMC);
	if(m_pGB)
	SAFE_RELEASE(m_pGB);
	CoUninitialize();
}

/*----------------------------------------------------------------------------*
			Atum_MusicInit	
*-----------------------------------------------------------------------------*/
HRESULT CMusicMP3::Atum_MusicInit(TCHAR * strFileName)
{
	FLOG( "CMusicMP3::Atum_MusicInit(TCHAR * strFileName)" );
	MultiByteToWideChar(CP_ACP,0,strFileName,-1,m_wFileName,1024);
	
	if(m_pGB)
		SAFE_RELEASE(m_pGB);
	if(m_pME)
		SAFE_RELEASE(m_pME);
	if(m_pMS)
		SAFE_RELEASE(m_pMS);
//	if(m_pMC)
//		SAFE_RELEASE(m_pMC);

    if( FAILED(CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)&m_pGB)) )
		return E_FAIL;
	if(m_pGB) m_pGB->QueryInterface(IID_IMediaEventEx, (void**)&m_pME);
	if(m_pGB) m_pGB->QueryInterface(IID_IMediaSeeking, (void**)&m_pMS);


	IBaseFilter *pFilterFileSourceAsync;
    if(FAILED(CoCreateInstance(CLSID_L544_FileSourceAsync, NULL, CLSCTX_INPROC_SERVER, IID_IBaseFilter, (void **)&pFilterFileSourceAsync)) )
	{		
		return E_FAIL;
	}
	if(m_pGB)
		m_pGB->AddFilter(pFilterFileSourceAsync, L"File Source (Async.)");
		
	IBaseFilter *pFilterMPEGIStreamSplitter;
    if(FAILED(CoCreateInstance(CLSID_L544_MPEGIStreamSplitter, NULL, CLSCTX_INPROC_SERVER, IID_IBaseFilter, (void **)&pFilterMPEGIStreamSplitter)) )
	{
		if(pFilterFileSourceAsync)
	SAFE_RELEASE(pFilterFileSourceAsync);
		return E_FAIL;
	}
	if(m_pGB)
		m_pGB->AddFilter(pFilterMPEGIStreamSplitter, L"MPEG-I Stream Splitter");
	
	HRESULT hr;
	//
	IBaseFilter *pFilterMPEGLayer3Decoder;
    if(FAILED(hr = CoCreateInstance(CLSID_L544_MPEGLayer3Decoder, NULL, 
		CLSCTX_ALL, IID_IBaseFilter, (void **)&pFilterMPEGLayer3Decoder)) )
	{
		if(pFilterFileSourceAsync)
			SAFE_RELEASE(pFilterFileSourceAsync);
		if(pFilterMPEGIStreamSplitter)
			SAFE_RELEASE(pFilterMPEGIStreamSplitter);
		return E_FAIL;
	}		
	if(m_pGB)
		m_pGB->AddFilter(pFilterMPEGLayer3Decoder, L"MPEG Layer-3 Decoder");
	
	// 
	IBaseFilter *pFilterDirectSoundAudioRenderer;	
    if(FAILED( hr = CoCreateInstance(CLSID_L544_DirectSoundAudioRenderer, NULL, 
		CLSCTX_ALL, IID_IBaseFilter, (void **)&pFilterDirectSoundAudioRenderer)) )
	{
		if(pFilterFileSourceAsync)
			SAFE_RELEASE(pFilterFileSourceAsync);
		if(pFilterMPEGIStreamSplitter)
			SAFE_RELEASE(pFilterMPEGIStreamSplitter);
		if(pFilterMPEGLayer3Decoder)
			SAFE_RELEASE(pFilterMPEGLayer3Decoder);
		return E_FAIL;
	}
	if(m_pGB)	
		m_pGB->AddFilter(pFilterDirectSoundAudioRenderer, L"DirectSound Audio Renderer");
	
	// ���� ����.
	IFileSourceFilter *pFSF;
	pFilterFileSourceAsync->QueryInterface(IID_IFileSourceFilter, (void **)&pFSF);
	if (pFSF != NULL)
	{

		if(FAILED(pFSF->Load(m_wFileName, NULL)))
		{
			return E_FAIL;
		}
	}
	else
	{
		if(pFilterFileSourceAsync)
			SAFE_RELEASE(pFilterFileSourceAsync);
		if(pFilterMPEGIStreamSplitter)
			SAFE_RELEASE(pFilterMPEGIStreamSplitter);
		if(pFilterMPEGLayer3Decoder)
			SAFE_RELEASE(pFilterMPEGLayer3Decoder);
		return E_FAIL;
	}
	
	if(pFilterFileSourceAsync && pFilterMPEGIStreamSplitter &&  pFilterMPEGLayer3Decoder && pFilterDirectSoundAudioRenderer)
	{
		ConnectFilters( pFilterFileSourceAsync, pFilterMPEGIStreamSplitter);
		ConnectFilters( pFilterMPEGIStreamSplitter, pFilterMPEGLayer3Decoder);
		ConnectFilters( pFilterMPEGLayer3Decoder, pFilterDirectSoundAudioRenderer);
	}
	

	if(pFilterFileSourceAsync)
		SAFE_RELEASE(pFilterFileSourceAsync);
	if(pFilterMPEGIStreamSplitter)
		SAFE_RELEASE(pFilterMPEGIStreamSplitter);
	if(pFilterMPEGLayer3Decoder)
		SAFE_RELEASE(pFilterMPEGLayer3Decoder);
	if(pFilterDirectSoundAudioRenderer)
	SAFE_RELEASE(pFilterDirectSoundAudioRenderer);
	if(pFSF)
	SAFE_RELEASE(pFSF);

	return	S_OK;

}


/*----------------------------------------------------------------------------*
			Atum_MusicPlayMP3	
*-----------------------------------------------------------------------------*/
HRESULT	CMusicMP3::Atum_PlayMP3(long Volumn)
{
	FLOG( "CMusicMP3::Atum_PlayMP3(long Volumn)" );
//	if(Volumn > 0)
//		Volumn = 0;
	// �̵�������� ����� ���� IMediaControl������
	IMediaControl* pMC = NULL;
	IBasicAudio   *pBA = NULL;

	if(!m_pGB)
		return E_FAIL;

	if(m_pGB)
	{
		m_pGB->QueryInterface(IID_IBasicAudio, (void **)&pBA);
		m_pGB->QueryInterface(IID_IMediaControl, (void**)&pMC);
	}
	
	if(pBA)	
		pBA->put_Volume(Volumn);
	if(pMC)
		pMC->Run();
	
	
	if(pBA)
		SAFE_RELEASE(pBA);
	if(pMC)
		SAFE_RELEASE(pMC);
	
	return	S_OK;
}

HRESULT	CMusicMP3::SetAtumMusicVolume(long volume)
{
	FLOG( "CMusicMP3::SetAtumMusicVolume(long volume)" );
	IBasicAudio   *pBA = NULL;

	if(!m_pGB)
		return E_FAIL;

	if(m_pGB) 
		m_pGB->QueryInterface(IID_IBasicAudio, (void **)&pBA);
	
	if(pBA)
		pBA->put_Volume(volume);

	if(pBA)
		SAFE_RELEASE(pBA);
	
	return S_OK;
}


/*----------------------------------------------------------------------------*
			Atum_PlayMP3	
*-----------------------------------------------------------------------------*/
HRESULT CMusicMP3::Atum_MusicStop()
{
	FLOG( "CMusicMP3::Atum_MusicStop()" );
	if(!m_pGB)
		return S_OK;
	
	IMediaControl* pMC=NULL;
	
	if(m_pGB)
		m_pGB->QueryInterface(IID_IMediaControl, (void**)&pMC);
	
	if(pMC)
		pMC->Stop();
	
	
	LONGLONG pos=0L;
	
	// �̵�������� �����ġ�� ã�� ���� IMediaSeeking ������
	IMediaSeeking* pMS=NULL;
	
	if(m_pGB)
		m_pGB->QueryInterface(IID_IMediaSeeking, (void**)&pMS);
	
		
	// �����ÿ��� ��ġ�� �Ǿ����� �������´�.
	if(pMS)
		pMS->SetPositions(&pos, AM_SEEKING_AbsolutePositioning,NULL, AM_SEEKING_NoPositioning);
	
	if(pMC)
		SAFE_RELEASE(pMC);
	if(pMS)
		SAFE_RELEASE(pMS);

	return S_OK;
}




/*----------------------------------------------------------------------------*
		Atum_LoopMusic
*-----------------------------------------------------------------------------*/
HRESULT CMusicMP3::Atum_LoopMusic(LONGLONG LMute)
{
	FLOG( "CMusicMP3::Atum_LoopMusic()" );

	if(!m_pME) return E_FAIL;
	if(!m_pMS) return E_FAIL;
//	if(!m_pMC) return E_FAIL;
	if(!m_pGB) return E_FAIL;

/*	IMediaControl* pMC=NULL;
	if(FAILED(m_pGB->QueryInterface(IID_IMediaControl, (void**)&pMC)))
		return E_FAIL;

	OAFilterState pfs;
	hr = pMC->GetState(INFINITE,&pfs);
	int i;
	if(hr == VFW_S_STATE_INTERMEDIATE)
		i=0;
	else if(hr == VFW_S_CANT_CUE)
		i=1;
	else if(hr == E_FAIL)
		i=2;
*/	
	

	m_ppMS = NULL;

	if(FAILED(m_pGB->QueryInterface(IID_IMediaSeeking, (void**)&m_ppMS)))
		return E_FAIL;	
	
	if(m_ppMS)
	{
		LONGLONG nTemp = m_pLPos;
		m_ppMS->GetPositions(&m_pLPos,&m_pLStopPos);
		if(m_pLPos == m_pLStopPos)
			m_bNowPlay = FALSE;
		else
			m_bNowPlay = TRUE;
	}
	if(LMute != 0)
	{
		m_pLPos = LMute;
		m_ppMS->SetPositions(&m_pLPos, AM_SEEKING_AbsolutePositioning,NULL, AM_SEEKING_NoPositioning);
	}		

	
	if(TRUE == m_bDefaultMusic)
	{
		if(m_pLPos >= m_pLStopPos)
		{
			m_pLPos = 0;
			if(m_ppMS)
				m_ppMS->SetPositions(&m_pLPos, AM_SEEKING_AbsolutePositioning,NULL, AM_SEEKING_NoPositioning);
		}
	}
	
	if(m_ppMS)
		SAFE_RELEASE(m_ppMS);

	return S_OK;
	
}



/*----------------------------------------------------------------------------*
		ConnectFilters	
*-----------------------------------------------------------------------------*/
HRESULT CMusicMP3::ConnectFilters( IBaseFilter *pUpFilter, 
								  IBaseFilter *pDownFilter, 
								  int nMAX)
{
	FLOG( "CMusicMP3::ConnectFilters( IBaseFilter *pUpFilter, IBaseFilter *pDownFilter, int nMAX)" );
	HRESULT hr;

	// Get the first output pin of the new source filter. Audio sources 
	// typically have only one output pin, so for most audio cases finding 
	// any output pin is sufficient.

	IEnumPins *pUpEnumPins = NULL, *pDownEnumPins = NULL;
	IPin *ppinOut = NULL, *pDownstreamPin;
	IPin *ppinIn = NULL, *pUpstreamPin;
	PIN_DIRECTION direction;
	bool bIsAnySuccess = false;

	
	// ���� ������ �ɵ��� ������ �޾ƿ´�.
	hr=pUpFilter->EnumPins(&pUpEnumPins);
	if (FAILED(hr)) return hr;

	// ������ ������ ���� �޾ƿ´�. ����...���� ��� �˻��Ѵ�,
	while (pUpEnumPins->Next(1, &ppinOut, 0) == S_OK)
	{
		// ������ ���� ������ �����. (��,�ƿ�)
		hr=(ppinOut->QueryDirection(&direction));
		if (FAILED(hr)) return hr;
		// ������ �ƿ��϶����� ����, ���϶��� if���� ����������.
		if (direction == PINDIR_OUTPUT)
		{
			// ppinOut�� ����Ǿ� �ִ� ���� �ִ����� �˾Ƴ��� pDownstreanmPin�� �����͸���.
			ppinOut->ConnectedTo(&pDownstreamPin);
			// ����� ���� ������.
			if (pDownstreamPin == NULL)
			{
				// Downstream filter: pin enumeration
				hr=(pDownFilter->EnumPins(&pDownEnumPins));
				if (FAILED(hr)) return hr;

				while (pDownEnumPins->Next(1, &ppinIn, 0) == S_OK)
				{
					hr=(ppinIn->QueryDirection(&direction));
					if (FAILED(hr)) return hr;

					if (direction == PINDIR_INPUT)
					{
						ppinIn->ConnectedTo(&pUpstreamPin);
						
						if (pUpstreamPin == NULL)
						{
							//
							// We have two pins. Connect it
							//

							// ���� ���� ���� ���� ������ ��
							// �߻��ϴ� ���� ������ ���´�!
							if (nMAX-- > 0)
							{
								hr = m_pGB->Connect(ppinOut, ppinIn);
							}

							if (hr == S_OK)
								bIsAnySuccess |= true;
							else if (hr == VFW_S_PARTIAL_RENDER)
								bIsAnySuccess |= false;
							else if (hr == E_ABORT)
								bIsAnySuccess |= false;
							else if (hr == E_POINTER)
								bIsAnySuccess |= false;
							else if (hr == VFW_E_CANNOT_CONNECT)
								bIsAnySuccess |= false;
							else if (hr == VFW_E_NOT_IN_GRAPH)
								bIsAnySuccess |= false;
						}
						SAFE_RELEASE(pUpstreamPin);
					}
					SAFE_RELEASE(ppinIn);
				}
				SAFE_RELEASE(pDownEnumPins);
			}
			// end of downstream
			SAFE_RELEASE(pDownstreamPin);
		}
		SAFE_RELEASE(ppinOut);
	}
	SAFE_RELEASE(pUpEnumPins);
	// end of upstream

	return (bIsAnySuccess == false ? E_FAIL : S_OK);
}

// 2007-07-24 by bhsohn �����̼� mp3�߰�
BOOL CMusicMP3::IsNowPlay()
{
	return m_bNowPlay;
}