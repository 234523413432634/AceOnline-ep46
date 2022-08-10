// TraceAni.cpp: implementation of the CTraceAni class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TraceAni.h"
#include "AtumApplication.h"
#include "DbgOut_C.h"
#include "CharacterInfo.h"
#include "Camera.h"
#include "dxutil.h"

#define NUMBER_OF_EFFECT_PLANE		1//(m_nNumberOfCross*4)
#define PLANE_VB_SIZE				16//�ּ� ������ : 8
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CEffectPlane::CEffectPlane(CTraceAni* pParent, int nIBIndex )
{
	FLOG("CEffectPlane::CEffectPlane(CTraceAni* pParent, int nIBIndex )");
	m_pParent = pParent;
	m_vPos = D3DXVECTOR3(0,0,0);
	m_nIBIndex = nIBIndex;
	m_bIsFirstIndex = FALSE;
	if(pParent)
	{
		m_bZbufferEnable = pParent->m_bZbufferEnable;
	}
	dwType = EFFECT_TYPE_TRACE;
	fDistance = 0;
	m_pVB = NULL;
}

CEffectPlane::~CEffectPlane()
{
	FLOG("CEffectPlane::~CEffectPlane()");
}

HRESULT CEffectPlane::InitDeviceObjects()
{
	FLOG("CEffectPlane::InitDeviceObjects()");
	return S_OK;
}

HRESULT CEffectPlane::RestoreDeviceObjects()
{
	FLOG("CEffectPlane::RestoreDeviceObjects()");
	if( FAILED( g_pD3dDev->CreateVertexBuffer( sizeof(SPRITE_VERTEX)*4*PLANE_VB_SIZE,
												0, 
												D3DFVF_SPRITE_VERTEX, 
												D3DPOOL_MANAGED, 
												&m_pVB,
												NULL) ) )
	{
		return E_FAIL;
	}
/*	m_pVB->Lock( 0, 0, (BYTE**)&v, 0 );
		D3DXVECTOR3 vPos = m_pParent->m_vCurrentPos;
		D3DXVECTOR3 vSide(m_pParent->m_pParent->m_pParent->m_mMatrix._11,//CTraceAni->CEffectInfo->CBodyConditionInfo
							m_pParent->m_pParent->m_pParent->m_mMatrix._12,
							m_pParent->m_pParent->m_pParent->m_mMatrix._13);
		D3DXVECTOR3 vTarget = m_pParent->m_vCurrentPos - m_pParent->m_vOldPos;
		D3DXVec3Normalize( &vSide, &vSide);

		D3DXMATRIX mat;
		D3DXMatrixRotationAxis(&mat,&vTarget,PI/4*(m_nIBIndex/2));
		D3DXVec3TransformCoord( &vSide, &vSide, &mat );
		if( m_nIBIndex%2 > 0 )
		{
			v[0].p = m_pParent->m_vOldPos;
			v[1].p = m_pParent->m_vOldPos+vSide;
			v[2].p = m_pParent->m_vCurrentPos;
			v[3].p = m_pParent->m_vCurrentPos+vSide;
		}
		else
		{
			v[0].p = m_pParent->m_vOldPos;
			v[1].p = m_pParent->m_vOldPos+vSide;
			v[2].p = m_pParent->m_vCurrentPos+vSide;
			v[3].p = m_pParent->m_vCurrentPos;
		}
		v[0].tu=0; v[0].tv=0.5;	v[0].c=0x00000000;//�������� �Ⱥ��̰�
		v[1].tu=0; v[1].tv=0;	v[1].c=0x00000000;
		v[2].tu=0; v[2].tv=0.5;	v[2].c=0xFFFFFFFF;
		v[3].tu=0; v[3].tv=0;	v[3].c=0xFFFFFFFF;
	}
	else
	{
		m_bIsFirstIndex = FALSE;
		v[0].c=0xFFFFFFFF;
		v[1].c=0xFFFFFFFF;
	}
	m_vPos = ( m_pParent->m_vOldPos + 
			   (m_pParent->m_vOldPos+vSide*m_pParent->m_fHalfSize) +
			   m_pParent->m_vCurrentPos + 
			   (m_pParent->m_vCurrentPos+vSide*m_pParent->m_fHalfSize) ) / 4;
	m_pVB->Unlock();
*/	
	return S_OK;
}

///////////////////////////////////////////////////////////////////////////////
/// \fn			CEffectPlane::SetEndIndex()
/// \brief		�ܻ� ������ ������ �÷����� ǥ���Ѵ�. ���� ������ ������
/// \author		dhkwon
/// \date		2004-10-15 ~ 2004-10-15
/// \warning	
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
void CEffectPlane::SetEndIndex()
{
	SPRITE_VERTEX* v;
	m_pVB->Lock( 0, 0, (void**)&v, 0 );
	int i; for(i=0;i<PLANE_VB_SIZE;i++)
	{
		if( i%2 > 0 )
		{
			v[i*4+0].c=0x00000000;
			v[i*4+1].c=0x00000000;
			v[i*4+2].c=0x33333333;
			v[i*4+3].c=0x33333333;
		}
		else
		{
			v[i*4+0].c=0x00000000;
			v[i*4+1].c=0x33333333;
			v[i*4+2].c=0x00000000;
			v[i*4+3].c=0x33333333;
		}
	}
	m_pVB->Unlock();
}
///////////////////////////////////////////////////////////////////////////////
/// \fn			VOID CEffectPlane::SetFirstIndex(BOOL bSet)
/// \brief		���� ������ �����̸� bSet=TRUE���� ��ǥ���,
///				�׷��� ������ bSet=FALSE�� �÷��� �ٲ��ش�.
/// \author		dhkwon
/// \date		2004-03-30 ~ 2004-03-30
/// \warning	RestoreDeviceObjects���Ŀ� �ݵ�� �ҷ���� �Ѵ�.
///
/// \param		
/// \return		
///////////////////////////////////////////////////////////////////////////////
VOID CEffectPlane::SetFirstIndex(BOOL bSet)
{
	FLOG("CEffectPlane::SetFirstIndex(BOOL bSet)");
	m_bIsFirstIndex = bSet;
	D3DXVECTOR3 vSide[PLANE_VB_SIZE];
	vSide[0] = D3DXVECTOR3(m_pParent->m_pParent->m_pParent->m_mMatrix._11,
						m_pParent->m_pParent->m_pParent->m_mMatrix._12,
						m_pParent->m_pParent->m_pParent->m_mMatrix._13);
	D3DXVECTOR3 vTarget = m_pParent->m_vCurrentPos - m_pParent->m_vOldPos;
	D3DXVec3Normalize( &vSide[0], &vSide[0]);
	D3DXMATRIX mat;
	int i;
	for(i=1;i<PLANE_VB_SIZE;i++)
	{
		D3DXMatrixRotationAxis(&mat,&vTarget,PI/(PLANE_VB_SIZE/8)*(i/2));
		D3DXVec3TransformCoord( &vSide[i], &vSide[0], &mat );
	}
	SPRITE_VERTEX* v;
	m_pVB->Lock( 0, 0, (void**)&v, 0 );
	for(i=0;i<PLANE_VB_SIZE;i++)
	{
		if( i%2 > 0 )
		{
			v[i*4+0].p = m_pParent->m_vOldPos;
			v[i*4+1].p = m_pParent->m_vOldPos + vSide[i]*m_pParent->m_fHalfSize;
			v[i*4+2].p = m_pParent->m_vCurrentPos;
			v[i*4+3].p = m_pParent->m_vCurrentPos + vSide[i]*m_pParent->m_fHalfSize;
			v[i*4+0].tu=0; v[i*4+0].tv=1;	v[i*4+0].c=0x33333333;
			v[i*4+1].tu=0; v[i*4+1].tv=0;	v[i*4+1].c=0x33333333;
			v[i*4+2].tu=1; v[i*4+2].tv=1;	v[i*4+2].c=0x33333333;
			v[i*4+3].tu=1; v[i*4+3].tv=0;	v[i*4+3].c=0x33333333;
		}
		else
		{
			v[i*4+0].p = m_pParent->m_vOldPos;
			v[i*4+1].p = m_pParent->m_vCurrentPos;
			v[i*4+2].p = m_pParent->m_vOldPos + vSide[i]*m_pParent->m_fHalfSize;
			v[i*4+3].p = m_pParent->m_vCurrentPos + vSide[i]*m_pParent->m_fHalfSize;
			v[i*4+0].tu=0; v[i*4+0].tv=1;	v[i*4+0].c=0x33333333;
			v[i*4+1].tu=1; v[i*4+1].tv=1;	v[i*4+1].c=0x33333333;
			v[i*4+2].tu=0; v[i*4+2].tv=0;	v[i*4+2].c=0x33333333;
			v[i*4+3].tu=1; v[i*4+3].tv=0;	v[i*4+3].c=0x33333333;
		}
	}
/*
#ifdef _DEBUG
		char buf[256];
		sprintf( buf, "[%x][%d][%5.2f,%5.2f,%5.2f][%5.2f,%5.2f,%5.2f]\n", 
			this, bSet, m_pParent->m_vCurrentPos.x, m_pParent->m_vCurrentPos.y, m_pParent->m_vCurrentPos.z,
			m_pParent->m_vOldPos.x, m_pParent->m_vOldPos.y, m_pParent->m_vOldPos.z);
		DBGOUT( buf );
#endif // _DEBUG_endif*/
	m_pVB->Unlock();
}

BOOL CEffectPlane::Tick(float fElapsedTime)
{
	FLOG("CEffectPlane::Tick(float fElapsedTime)");
	if(m_bIsFirstIndex)
	{
		D3DXVECTOR3 vSide[PLANE_VB_SIZE];
		vSide[0] = D3DXVECTOR3(m_pParent->m_pParent->m_pParent->m_mMatrix._11,//CTraceAni->CEffectInfo->CBodyConditionInfo
							m_pParent->m_pParent->m_pParent->m_mMatrix._12,
							m_pParent->m_pParent->m_pParent->m_mMatrix._13);
		D3DXVECTOR3 vTarget = m_pParent->m_vCurrentPos - m_pParent->m_vOldPos;
		D3DXVec3Normalize( &vSide[0], &vSide[0]);
		D3DXMATRIX mat;
		int i;
		for(i=1;i<PLANE_VB_SIZE;i++)
		{
			D3DXMatrixRotationAxis(&mat,&vTarget,PI/(PLANE_VB_SIZE/8)*(i/2));
			D3DXVec3TransformCoord( &vSide[i], &vSide[0], &mat );
		}

		SPRITE_VERTEX* v;
		m_pVB->Lock( 0, 0, (void**)&v, 0 );
		for(i=0;i<PLANE_VB_SIZE;i++)
		{
			if( i%2 > 0 )
			{
				v[i*4+2].p = m_pParent->m_vCurrentPos;
				v[i*4+3].p = m_pParent->m_vCurrentPos + vSide[i]*m_pParent->m_fHalfSize;
			}
			else
			{
				v[i*4+1].p = m_pParent->m_vCurrentPos;
				v[i*4+3].p = m_pParent->m_vCurrentPos + vSide[i]*m_pParent->m_fHalfSize;
			}
		}
		m_pVB->Unlock();
	}
	return TRUE;
}

void CEffectPlane::Render()
{
	FLOG("CEffectPlane::Render()");
	g_pD3dDev->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_MODULATE );
	g_pD3dDev->SetStreamSource( 0,m_pVB,0, sizeof(SPRITE_VERTEX) );
	//g_pD3dDev->SetTexture( 0, m_pTexture );
	g_pD3dDev->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2*PLANE_VB_SIZE );
}


HRESULT CEffectPlane::InvalidateDeviceObjects()
{
	FLOG("CEffectPlane::InvalidateDeviceObjects()");
	SAFE_RELEASE( m_pVB );
	return S_OK;
}

HRESULT CEffectPlane::DeleteDeviceObjects()
{
	FLOG("CEffectPlane::DeleteDeviceObjects()");
	return S_OK;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CTraceAni::CTraceAni()
{
	FLOG( "CTraceAni()" );
	memset((void*)this,0,sizeof(CTraceAni));
	m_fRadius = 0.0f;
}

CTraceAni::~CTraceAni()
{
	FLOG( "~CTraceAni()" );

}

BOOL CTraceAni::Tick(float fElapsedTime)
{
	FLOG( "CTraceAni::Tick(float fElapsedTime)" );
	m_fCurrentTextureTick += fElapsedTime;
	if(m_nTextureNumber > 0 && m_fCurrentTextureTick > m_fTextureAnimationTime)
	{
		// texture �ִϸ��̼�
		m_nCurrentTextureNumber++;
		if(m_nCurrentTextureNumber == m_nTextureNumber)
		{
			m_nCurrentTextureNumber = 0;
		}
		m_fCurrentTextureTick = 0.0f;
	}
	m_fCurrentCreateTick += fElapsedTime;
	if(m_pParent)
	{
		D3DXMATRIX mat = m_pParent->m_pParent->m_mMatrix;
		mat._41 = 0;
		mat._42 = 0;
		mat._43 = 0;
		D3DXVECTOR3 vPos;
		D3DXVec3TransformCoord( &vPos, &m_pParent->m_vPos, &mat );
		m_vCurrentPos.x = m_pParent->m_pParent->m_mMatrix._41 + vPos.x;
		m_vCurrentPos.y = m_pParent->m_pParent->m_mMatrix._42 + vPos.y;
		m_vCurrentPos.z = m_pParent->m_pParent->m_mMatrix._43 + vPos.z;
	}
	if(m_fCurrentCreateTick > m_fCreateTick )
	{
		if(m_bCreateTrace)
		{
			int nOldIndex = m_nCurrentCreateIndex;
			//���� ������ VB ��ġ�� �������̸� ������ ���ư���
			if(++m_nCurrentCreateIndex > m_nNumberOfTrace-1 )
			{
				m_nCurrentCreateIndex = 0;
			}
			//���� �����ϴ� VB 16�� ������ ����
			if(++m_nCurrentNumberOfTrace > m_nNumberOfTrace )// ���ۿ� ������ ������� ���
			{
				m_nCurrentNumberOfTrace = m_nNumberOfTrace;
				m_pEffectPlane[m_nCurrentCreateIndex]->InvalidateDeviceObjects();
				m_pEffectPlane[m_nCurrentCreateIndex]->DeleteDeviceObjects();
				SAFE_DELETE(m_pEffectPlane[m_nCurrentCreateIndex]);

				if(++m_nCurrentDeleteIndex > m_nNumberOfTrace-1 )
				{
					m_nCurrentDeleteIndex = 0;
				}
				int nEndIndex = m_nCurrentCreateIndex+1>m_nNumberOfTrace-1?0:m_nCurrentCreateIndex+1;
				m_pEffectPlane[nEndIndex]->SetEndIndex();
			}
			else
			{
				// delete index�� ����� �ʿ䰡 ����. �������� ������ ���� ���� �ε����̱� ������.
				
			}

			if(m_pEffectPlane[nOldIndex])
			{
				m_pEffectPlane[nOldIndex]->SetFirstIndex(FALSE);
			}
		
			m_vOldPos = m_vCurrentPos;
			if(m_pEffectPlane[m_nCurrentCreateIndex])
			{
				m_pEffectPlane[m_nCurrentCreateIndex]->InvalidateDeviceObjects();
				m_pEffectPlane[m_nCurrentCreateIndex]->DeleteDeviceObjects();
				SAFE_DELETE(m_pEffectPlane[m_nCurrentCreateIndex]);
			}
			m_pEffectPlane[m_nCurrentCreateIndex] = new CEffectPlane(this, 0);
			m_pEffectPlane[m_nCurrentCreateIndex]->InitDeviceObjects();
			m_pEffectPlane[m_nCurrentCreateIndex]->RestoreDeviceObjects();
			m_pEffectPlane[m_nCurrentCreateIndex]->SetFirstIndex(TRUE);


			m_nCurrentRenderIndex = m_nCurrentCreateIndex;
		// CEffectPlane�� IB �����Ϳ� 1:1�� ��Ī. ���� ������ ���� �߽����� �ٲ۴�.
		// �ε��� = m_nCurrentCreateIndex X 16

		// U ��ǥ ���
		// VB�� ������ ��ĭ�� �̵��Ѵ�. memcpy�� �̿��� �ѹ��� ����
		// �������� �ܻ� ���� : m_pVBTrace : ī�޶� ���̵庤Ÿ + m_vCurrentPos
		}
		else	
		{
			DBGOUT("CTraceAni::Tick(float fElapsedTime), Trace Delete[index:%d]\n",m_nCurrentDeleteIndex);
			// �ܻ��� �ϳ��� �ٿ� ������.
			//���� ������ VB ��ġ�� �������̸� ������ ���ư���
			if(m_nCurrentNumberOfTrace > 0)
			{
				int nDeleteIndex = m_nCurrentDeleteIndex;
				// delete old CEffecTPlane

//				int i; for(i=0;i<NUMBER_OF_EFFECT_PLANE;i++)
//				{
//					m_pEffectPlane[NUMBER_OF_EFFECT_PLANE*m_nCurrentCreateIndex+i]->InvalidateDeviceObjects();
//					m_pEffectPlane[NUMBER_OF_EFFECT_PLANE*m_nCurrentCreateIndex+i]->DeleteDeviceObjects();
//					SAFE_DELETE(m_pEffectPlane[NUMBER_OF_EFFECT_PLANE*m_nCurrentCreateIndex+i]);
//				}


				m_pEffectPlane[m_nCurrentCreateIndex]->InvalidateDeviceObjects();
				m_pEffectPlane[m_nCurrentCreateIndex]->DeleteDeviceObjects();
				SAFE_DELETE(m_pEffectPlane[m_nCurrentCreateIndex]);


				if(++m_nCurrentDeleteIndex > m_nNumberOfTrace )// ���� �ε����� �Ѿ� ó�� �ε����� �̵�
				{
					m_nCurrentDeleteIndex = 0;
				}
				m_nCurrentNumberOfTrace--;
			}
			else
			{
				// �ܻ� ������ 0�̸� �Ҹ�
				return FALSE;
			}
		}
		m_fCurrentCreateTick = 0.0f;
	}
	else	// ������ �� �̵� ���
	{
//		m_vCurrentPos = D3DXVECTOR3(m_pParent->m_pParent->m_mMatrix._41,
//								m_pParent->m_pParent->m_mMatrix._42,
//								m_pParent->m_pParent->m_mMatrix._43);
		// CEffectPlane�߿� ���� �������� �͵��� ��ǥ�� ���� �����Ѵ�.
		int i; for(i=0;i<m_nNumberOfTrace;i++)
		{
			if(m_pEffectPlane[i])
			{
				m_pEffectPlane[i]->Tick( fElapsedTime );
				m_fRadius = D3DXVec3Length(&(m_pEffectPlane[i]->GetPos() - m_pEffectPlane[0]->GetPos()));
			}
		}
	}

	return TRUE;
}

void CTraceAni::Render()
{
	FLOG( "CTraceAni::Render()" );

}

HRESULT CTraceAni::InitDeviceObjects()
{
	FLOG("CTraceAni::InitDeviceObjects()");
	m_pEffectPlane = new CEffectPlane*[m_nNumberOfTrace];
	memset(m_pEffectPlane, 0x00, sizeof(DWORD)*m_nNumberOfTrace);
	return S_OK;
}

HRESULT CTraceAni::RestoreDeviceObjects()
{
	FLOG( "CTraceAni::RestoreDeviceObjects()" );
	if(m_pParent)
	{
		D3DXMATRIX mat = m_pParent->m_pParent->m_mMatrix;//���� ��Ʈ����
		mat._41 = 0;
		mat._42 = 0;
		mat._43 = 0;
		D3DXVECTOR3 vPos;
		D3DXVec3TransformCoord( &vPos, &m_pParent->m_vPos, &mat );// ����Ʈ ��� ��ǥ
		m_vOldPos.x = m_pParent->m_pParent->m_mMatrix._41 + vPos.x;
		m_vOldPos.y = m_pParent->m_pParent->m_mMatrix._42 + vPos.y;
		m_vOldPos.z = m_pParent->m_pParent->m_mMatrix._43 + vPos.z;
		m_vCurrentPos = m_vOldPos;

		if(m_pEffectPlane[0])
		{
			m_pEffectPlane[0]->InvalidateDeviceObjects();
			m_pEffectPlane[0]->DeleteDeviceObjects();
			SAFE_DELETE(m_pEffectPlane[0]);							// 2006-07-07 by ispark
		}
		m_pEffectPlane[0] = new CEffectPlane(this, 0);
		m_pEffectPlane[0]->InitDeviceObjects();
		if(m_pEffectPlane[0]->RestoreDeviceObjects() == S_OK)
		{
			m_pEffectPlane[0]->SetFirstIndex(TRUE);
			m_pEffectPlane[0]->SetEndIndex();
		}

	}

	m_nCurrentNumberOfTrace = 1;
	m_fCurrentCreateTick = 0;//���� �������� ���� �ܻ��� �׸���.
	m_nCurrentTextureNumber = 0;
	m_bCreateTrace = TRUE;
//	m_vPos1 = m_vCurrentPos;
	m_fCurrentTextureTick = 0;
	m_nCurrentCreateIndex = 0;
	m_nCurrentRenderIndex = 0;
	m_nCurrentDeleteIndex = 0;
	m_bRestored = TRUE;
	return S_OK;
}

HRESULT CTraceAni::InvalidateDeviceObjects()
{
	FLOG( "CTraceAni::InvalidateDeviceObjects()" );
//	g_pD3dDev->DeleteStateBlock( m_dwStateBlock );
	int i; for(i=0;i<m_nNumberOfTrace;i++)
	{
		if(m_pEffectPlane[i])
		{
			m_pEffectPlane[i]->InvalidateDeviceObjects();
			m_pEffectPlane[i]->DeleteDeviceObjects();
			SAFE_DELETE(m_pEffectPlane[i]);
		}
	}
	m_bRestored = FALSE;
	return S_OK;
}

HRESULT CTraceAni::DeleteDeviceObjects()
{
	FLOG( "CTraceAni::DeleteDeviceObjects()" );
	SAFE_DELETE_ARRAY(m_pEffectPlane);
	return S_OK;
}
/*
CTraceAni::CTraceAni()
{
	FLOG( "CTraceAni()" );
	memset((void*)this,0,sizeof(CTraceAni));
//	m_pRenderer = g_pD3dApp->m_pTraceAniRender;
}

CTraceAni::~CTraceAni()
{
	FLOG( "~CTraceAni()" );

}

BOOL CTraceAni::Tick(float fElapsedTime)
{
	FLOG( "CTraceAni::Tick(float fElapsedTime)" );
	m_fCurrentTextureTick += fElapsedTime;
	if(m_nTextureNumber > 0 && m_fCurrentTextureTick > m_fTextureAnimationTime)
	{
		// texture �ִϸ��̼�
		m_nCurrentTextureNumber++;
		if(m_nCurrentTextureNumber == m_nTextureNumber)
		{
			m_nCurrentTextureNumber = 0;
		}
		m_fCurrentTextureTick = 0.0f;
	}
	m_fCurrentCreateTick += fElapsedTime;
	if(m_pParent)
	{
		D3DXMATRIX mat = m_pParent->m_pParent->m_mMatrix;
		mat._41 = 0;
		mat._42 = 0;
		mat._43 = 0;
		D3DXVECTOR3 vPos;
		D3DXVec3TransformCoord( &vPos, &m_pParent->m_vPos, &mat );
		m_vCurrentPos.x = m_pParent->m_pParent->m_mMatrix._41 + vPos.x;
		m_vCurrentPos.y = m_pParent->m_pParent->m_mMatrix._42 + vPos.y;
		m_vCurrentPos.z = m_pParent->m_pParent->m_mMatrix._43 + vPos.z;
	}
	if(m_fCurrentCreateTick > m_fCreateTick )
	{
		if(m_bCreateTrace)
		{
			SPRITE_VERTEX* v1, *v2;
			m_pVBTrace[0]->Lock( 0, 0, (BYTE**)&v1, 0 );
			m_pVBTrace[1]->Lock( 0, 0, (BYTE**)&v2, 0 );
			m_nCurrentNumberOfTrace++;
			if(m_nCurrentNumberOfTrace > m_nNumberOfTrace )
			{
				m_nCurrentNumberOfTrace = m_nNumberOfTrace;
				char* pVB = new char[sizeof(SPRITE_VERTEX)*m_nCurrentNumberOfTrace*2];
				memcpy( pVB, ((char*)v1)+sizeof(SPRITE_VERTEX)*2, sizeof(SPRITE_VERTEX)*m_nCurrentNumberOfTrace*2);
				memcpy( v1, pVB, sizeof(SPRITE_VERTEX)*m_nCurrentNumberOfTrace*2 );
				memcpy( pVB, ((char*)v2)+sizeof(SPRITE_VERTEX)*2, sizeof(SPRITE_VERTEX)*m_nCurrentNumberOfTrace*2);
				memcpy( v2, pVB, sizeof(SPRITE_VERTEX)*m_nCurrentNumberOfTrace*2 );
				delete pVB;
			}
			// U ��ǥ ���
			//int nNum = m_nCurrentNumberOfTrace>m_nNumberOfTrace ? m_nNumberOfTrace*2 : m_nCurrentNumberOfTrace*2;
//			m_vPos3 = m_vPos2;
//			m_vPos2 = m_vPos1;
			int nNum = m_nCurrentNumberOfTrace*2;
			int i; for(i=0;i<nNum;i++)
			{
				if(v1[i].p.x == 0)
				{
					char buf[256];
					sprintf( buf, "1.index[%d],p[%f,%f,%f],tu[%f],tv[%f]\n", i, v1[i].p.x,v1[i].p.y,v1[i].p.z,v1[i].tu, v1[i].tv );
					DBGOUT( buf );
				}
				if(nNum == 2)
				{
					v1[i].tu = 0.0f;
					v2[i].tu = 0.0f;
				}
				else if(i/2 == nNum/2-1)// ������ ������ �ٷ� ����
				{
					if(nNum/2 == 1)
					{
						v1[i].tu = 0.0f;// ���� 2���ۿ� ���°��(�Ʒ� �����Ǵ°ͱ��� 4���� ���)
						v2[i].tu = 0.0f;// ���� 2���ۿ� ���°��(�Ʒ� �����Ǵ°ͱ��� 4���� ���)
					}
					else
					{
						v1[i].tu = m_fUPosOfTail;
						v2[i].tu = m_fUPosOfTail;
					}
				}
				else
				{
					v1[i].tu = ((1.0f-m_fUPosOfTail) * (i/2)) / ((nNum/2)-1) ;// i/2:������ ����, nNum/2:��ü ����
					v2[i].tu = ((1.0f-m_fUPosOfTail) * (i/2)) / ((nNum/2)-1) ;// i/2:������ ����, nNum/2:��ü ����
				}
			}
			// VB�� ������ ��ĭ�� �̵��Ѵ�. memcpy�� �̿��� �ѹ��� ����
			// �������� �ܻ� ���� : m_pVBTrace : ī�޶� ���̵庤Ÿ + m_vCurrentPos
			if(m_pParent)
			{
				D3DXVECTOR3 vSide;
				D3DXVECTOR3 vTarget(m_pParent->m_pParent->m_mMatrix._31,m_pParent->m_pParent->m_mMatrix._32,m_pParent->m_pParent->m_mMatrix._33);
				D3DXVec3Cross(&vSide, &g_pD3dApp->m_pCamera->GetViewDir(), &vTarget);
				D3DXVec3Normalize( &vSide, &vSide);
				v1[nNum].p = m_vCurrentPos - vSide * m_fHalfSize;	v1[nNum].tu=1;	v1[nNum].tv=1;	v1[nNum].c=0xFFFFFFFF;
				v1[nNum+1].p = m_vCurrentPos + vSide * m_fHalfSize;	v1[nNum+1].tu=1;	v1[nNum+1].tv=0;	v1[nNum+1].c=0xFFFFFFFF;
				v2[nNum].p = m_vCurrentPos + vSide * m_fHalfSize;	v2[nNum].tu=1;	v2[nNum].tv=1;	v2[nNum].c=0xFFFFFFFF;
				v2[nNum+1].p = m_vCurrentPos - vSide * m_fHalfSize;	v2[nNum+1].tu=1;	v2[nNum+1].tv=0;	v2[nNum+1].c=0xFFFFFFFF;
			}
//			D3DXVECTOR3 vCamSide;
//			D3DXVec3Normalize( &vCamSide, &g_pD3dApp->m_pCamera->GetCross());
///			char buf[256];
//			v[nNum].p = m_vCurrentPos - vCamSide * m_fHalfSize;		v[nNum].tu=1;	v[nNum].tv=1;	v[nNum].c=0xFFFFFFFF;
//			if(v[nNum].p.x == 0)
//			{
//				sprintf( buf, "2.index[%d],p[%f,%f,%f],tu[%f],tv[%f]\n", nNum, v[nNum].p.x,v[nNum].p.y,v[nNum].p.z,v[nNum].tu, v[nNum].tv );
//				DBGOUT( buf );
//			}
//			v[nNum+1].p = m_vCurrentPos + vCamSide * m_fHalfSize;	v[nNum+1].tu=1;	v[nNum+1].tv=0;	v[nNum+1].c=0xFFFFFFFF;
//			if(v[nNum+1].p.x == 0)
//			{
//				sprintf( buf, "3.index[%d],p[%f,%f,%f],tu[%f],tv[%f]\n", nNum+1, v[nNum+1].p.x,v[nNum+1].p.y,v[nNum+1].p.z,v[nNum+1].tu, v[nNum+1].tv );
//				DBGOUT( buf );
//			}
			m_pVBTrace[0]->Unlock();
			m_pVBTrace[1]->Unlock();
		}
		else
		{
			// �ܻ��� �ϳ��� �ٿ� ������.
			m_nCurrentNumberOfTrace--;
			if(m_nCurrentNumberOfTrace == 0)
			{
				m_nCurrentNumberOfTrace = 0;
				return FALSE;
			}
			SPRITE_VERTEX* v1,* v2;
			m_pVBTrace[0]->Lock( 0, 0, (BYTE**)&v1, 0 );
			m_pVBTrace[1]->Lock( 0, 0, (BYTE**)&v2, 0 );
			char* pVB = new char[sizeof(SPRITE_VERTEX)*m_nCurrentNumberOfTrace*2];
			memcpy( pVB, v1+sizeof(SPRITE_VERTEX)*2, sizeof(SPRITE_VERTEX)*m_nCurrentNumberOfTrace*2);
			memcpy( v1, pVB, sizeof(SPRITE_VERTEX)*m_nCurrentNumberOfTrace*2 );
			memcpy( pVB, v2+sizeof(SPRITE_VERTEX)*2, sizeof(SPRITE_VERTEX)*m_nCurrentNumberOfTrace*2);
			memcpy( v2, pVB, sizeof(SPRITE_VERTEX)*m_nCurrentNumberOfTrace*2 );
			delete pVB;
			m_pVBTrace[0]->Unlock();
			m_pVBTrace[1]->Unlock();
			// �ܻ� ������ 0�̸� �Ҹ�
		}
		m_fCurrentCreateTick = 0.0f;
	}
	else
	{
		SPRITE_VERTEX* v1,* v2;
		m_pVBTrace[0]->Lock( 0, 0, (BYTE**)&v1, 0 );
		m_pVBTrace[1]->Lock( 0, 0, (BYTE**)&v2, 0 );
		//int nNum = m_nCurrentNumberOfTrace>m_nNumberOfTrace ? m_nNumberOfTrace*2 : m_nCurrentNumberOfTrace*2;
		int nNum = m_nCurrentNumberOfTrace*2;
		if(m_pParent)
		{
			D3DXVECTOR3 vSide;
			D3DXVECTOR3 vTarget(m_pParent->m_pParent->m_mMatrix._31,m_pParent->m_pParent->m_mMatrix._32,m_pParent->m_pParent->m_mMatrix._33);
			D3DXVec3Cross(&vSide, &g_pD3dApp->m_pCamera->GetViewDir(), &vTarget);
			D3DXVec3Normalize( &vSide, &vSide);
			v1[nNum].p = m_vCurrentPos - vSide * m_fHalfSize;
			v1[nNum+1].p = m_vCurrentPos + vSide * m_fHalfSize;
			v2[nNum].p = m_vCurrentPos + vSide * m_fHalfSize;
			v2[nNum+1].p = m_vCurrentPos - vSide * m_fHalfSize;
		}
//		D3DXVECTOR3 vCamSide;
//		D3DXVec3Normalize( &vCamSide, &g_pD3dApp->m_pCamera->GetCross());
//		v[nNum].p = m_vCurrentPos - vCamSide * m_fHalfSize;
//		v[nNum+1].p = m_vCurrentPos + vCamSide * m_fHalfSize;
		m_pVBTrace[0]->Unlock();
		m_pVBTrace[1]->Unlock();
//		m_vPos1 = m_vCurrentPos;
	}

	return TRUE;
}

void CTraceAni::Render()
{
	FLOG( "CTraceAni::Render()" );

}

HRESULT CTraceAni::InitDeviceObjects()
{
	FLOG( "CTraceAni::InitDeviceObjects()" );
	return S_OK;
}

HRESULT CTraceAni::RestoreDeviceObjects()
{
	FLOG( "CTraceAni::RestoreDeviceObjects()" );
	if( FAILED( g_pD3dDev->CreateVertexBuffer( (m_nNumberOfTrace+1)*2 * sizeof(SPRITE_VERTEX),
		D3DUSAGE_WRITEONLY, D3DFVF_SPRITE_VERTEX, D3DPOOL_MANAGED, &m_pVBTrace[0] ) ) )
		return E_FAIL;
	if( FAILED( g_pD3dDev->CreateVertexBuffer( (m_nNumberOfTrace+1)*2 * sizeof(SPRITE_VERTEX),
		D3DUSAGE_WRITEONLY, D3DFVF_SPRITE_VERTEX, D3DPOOL_MANAGED, &m_pVBTrace[1] ) ) )
		return E_FAIL;

	SPRITE_VERTEX* v1,* v2;
    m_pVBTrace[0]->Lock( 0, 0, (BYTE**)&v1, 0 );
    m_pVBTrace[1]->Lock( 0, 0, (BYTE**)&v2, 0 );
		memset( v1, 0x00, (m_nNumberOfTrace+1)*2 * sizeof(SPRITE_VERTEX));
		memset( v2, 0x00, (m_nNumberOfTrace+1)*2 * sizeof(SPRITE_VERTEX));
		if(m_pParent)
		{
			D3DXMATRIX mat = m_pParent->m_pParent->m_mMatrix;
			mat._41 = 0;
			mat._42 = 0;
			mat._43 = 0;
			D3DXVECTOR3 vPos;
			D3DXVec3TransformCoord( &vPos, &m_pParent->m_vPos, &mat );
			m_vCurrentPos.x = m_pParent->m_pParent->m_mMatrix._41 + vPos.x;
			m_vCurrentPos.y = m_pParent->m_pParent->m_mMatrix._42 + vPos.y;
			m_vCurrentPos.z = m_pParent->m_pParent->m_mMatrix._43 + vPos.z;
			D3DXVECTOR3 vSide;
			D3DXVECTOR3 vTarget(m_pParent->m_pParent->m_mMatrix._31,m_pParent->m_pParent->m_mMatrix._32,m_pParent->m_pParent->m_mMatrix._33);
			D3DXVec3Cross(&vSide, &g_pD3dApp->m_pCamera->GetViewDir(), &vTarget);
			D3DXVec3Normalize( &vSide, &vSide);
			v1[0].p = m_vCurrentPos - vSide * m_fHalfSize;
			v1[1].p = m_vCurrentPos + vSide * m_fHalfSize;
			v1[0].tu=0; v1[0].tv=1;	v1[0].c=0xFFFFFFFF;
			v1[1].tu=0; v1[1].tv=0;	v1[1].c=0xFFFFFFFF;
			v2[0].p = m_vCurrentPos + vSide * m_fHalfSize;
			v2[1].p = m_vCurrentPos - vSide * m_fHalfSize;
			v2[0].tu=0; v2[0].tv=1;	v2[0].c=0xFFFFFFFF;
			v2[1].tu=0; v2[1].tv=0;	v2[1].c=0xFFFFFFFF;
		}
    m_pVBTrace[0]->Unlock();
    m_pVBTrace[1]->Unlock();

	m_nCurrentNumberOfTrace = 0;
	m_fCurrentCreateTick = m_fCreateTick;//���� Tick���� �ٷ� ù��° �ܻ��� �׸���.
	m_nCurrentTextureNumber = 0;
	m_bCreateTrace = TRUE;
//	m_vPos1 = m_vCurrentPos;

//	g_pD3dDev->BeginStateBlock();
//		g_pD3dDev->SetRenderState( D3DRS_ZENABLE, m_bZbufferEnable );
//		g_pD3dDev->SetRenderState( D3DRS_LIGHTING, TRUE );
//		g_pD3dDev->SetRenderState( D3DRS_ALPHABLENDENABLE, m_bAlphaBlendEnable );
//		g_pD3dDev->SetRenderState( D3DRS_SRCBLEND, m_dwSrcBlend );
//		g_pD3dDev->SetRenderState( D3DRS_DESTBLEND, m_dwDestBlend );
//	g_pD3dDev->EndStateBlock( &m_dwStateBlock );
	m_bRestored = TRUE;
	return S_OK;
}

HRESULT CTraceAni::InvalidateDeviceObjects()
{
	FLOG( "CTraceAni::InvalidateDeviceObjects()" );
	SAFE_RELEASE( m_pVBTrace[0] );
	SAFE_RELEASE( m_pVBTrace[1] );
//	g_pD3dDev->DeleteStateBlock( m_dwStateBlock );
	m_bRestored = FALSE;
	return S_OK;
}

HRESULT CTraceAni::DeleteDeviceObjects()
{
	FLOG( "CTraceAni::DeleteDeviceObjects()" );
	return S_OK;
}
*/