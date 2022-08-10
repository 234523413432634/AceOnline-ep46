// SkinnedMesh.cpp: implementation of the CSkinnedMesh class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "SkinnedMesh.h"
#include "rmxfguid.h"
#include "tchar.h"
#include "stdio.h"
#include "d3dutil.h"
#include "dxutil.h"
#include "NPCGlobal.h"
#include "rmxftmpl.h"
#include "DebugCheckTime.h"

#define D3DRM_XTEMPLATE_BYTES 3278
#define D3DFVF_VERTEX (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//extern unsigned char * D3DRM_XTEMPLATES;

char *szTemplates = "xof 0303txt 0032\
template XSkinMeshHeader {\
 <3cf169ce-ff7c-44ab-93c0-f78f62d172e2>\
 WORD nMaxSkinWeightsPerVertex;\
 WORD nMaxSkinWeightsPerFace;\
 WORD nBones;}\
template VertexDuplicationIndices {\
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>\
 DWORD nIndices;\
 DWORD nOriginalVertices;\
 array DWORD indices[nIndices];}\
template SkinWeights {\
 <6f0d123b-bad2-4167-a0d0-80224f25fabb>\
 STRING transformNodeName;\
 DWORD nWeights;\
 array DWORD vertexIndices[nWeights];\
 array FLOAT weights[nWeights];\
 Matrix4x4 matrixOffset;}";


void SFrame::SetTime(float fGlobalTime)
{
    UINT iKey;
    UINT dwp2;
    UINT dwp3;
    D3DXMATRIXA16 matResult;
    D3DXMATRIXA16 matTemp;
    float fTime1;
    float fTime2;
    float fLerpValue;
    D3DXVECTOR3 vScale;
    D3DXVECTOR3 vPos;
    D3DXQUATERNION quat;
    BOOL bAnimate = false;
    float fTime;

    if (m_pMatrixKeys )
    {
        fTime = (float)fmod(fGlobalTime, m_pMatrixKeys[m_cMatrixKeys-1].dwTime);

        for (iKey = 0 ;iKey < m_cMatrixKeys ; iKey++)
        {
            if ((float)m_pMatrixKeys[iKey].dwTime > fTime)
            {
                dwp3 = iKey;

                if (iKey > 0)
                {
                    dwp2= iKey - 1;
                }
                else  // when iKey == 0, then dwp2 == 0
                {
                    dwp2 = iKey;
                }

                break;
            }
        }
        fTime1 = (float)m_pMatrixKeys[dwp2].dwTime;
        fTime2 = (float)m_pMatrixKeys[dwp3].dwTime;

        if ((fTime2 - fTime1) ==0)
            fLerpValue = 0;
        else
            fLerpValue =  (fTime - fTime1)  / (fTime2 - fTime1);

        if (fLerpValue > 0.5)
        {
            iKey = dwp3;
        }
        else
        {
            iKey = dwp2;
        }

        pframeToAnimate->matRot = m_pMatrixKeys[iKey].mat;
    }
    else
    {
        D3DXMatrixIdentity(&matResult);

        if (m_pScaleKeys)
        {
            dwp2 = dwp3 = 0;

            fTime = (float)fmod(fGlobalTime, m_pScaleKeys[m_cScaleKeys-1].dwTime);

            for (iKey = 0 ;iKey < m_cScaleKeys ; iKey++)
            {
                if ((float)m_pScaleKeys[iKey].dwTime > fTime)
                {
                    dwp3 = iKey;

                    if (iKey > 0)
                    {
                        dwp2= iKey - 1;
                    }
                    else  // when iKey == 0, then dwp2 == 0
                    {
                        dwp2 = iKey;
                    }

                    break;
                }
            }
            fTime1 = (float)m_pScaleKeys[dwp2].dwTime;
            fTime2 = (float)m_pScaleKeys[dwp3].dwTime;

            if ((fTime2 - fTime1) ==0)
                fLerpValue = 0;
            else
                fLerpValue =  (fTime - fTime1)  / (fTime2 - fTime1);

            D3DXVec3Lerp(&vScale,
                    &m_pScaleKeys[dwp2].vScale,
                    &m_pScaleKeys[dwp3].vScale,
                    fLerpValue);


            D3DXMatrixScaling(&matTemp, vScale.x, vScale.y, vScale.z);

            D3DXMatrixMultiply(&matResult, &matResult, &matTemp);

            bAnimate = true;
        }

        //check rot keys
        if (m_pRotateKeys )
        {
            int i1 = 0;
            int i2 = 0;

            fTime = (float)fmod(fGlobalTime, m_pRotateKeys[m_cRotateKeys-1].dwTime);

            for (iKey = 0 ;iKey < m_cRotateKeys ; iKey++)
            {
                if ((float)m_pRotateKeys[iKey].dwTime > fTime)
                {
                    i1 = (iKey > 0) ? iKey - 1 : 0;
                    i2 = iKey;
                    break;
                }
            }

            fTime1 = (float)m_pRotateKeys[i1].dwTime;
            fTime2 = (float)m_pRotateKeys[i2].dwTime;

            if ((fTime2 - fTime1) ==0)
                fLerpValue = 0;
            else
                fLerpValue =  (fTime - fTime1)  / (fTime2 - fTime1);
           D3DXQuaternionSlerp(&quat, &m_pRotateKeys[i1].quatRotate, &m_pRotateKeys[i2].quatRotate, fLerpValue);

            quat.w = -quat.w;
            D3DXMatrixRotationQuaternion(&matTemp, &quat);
            D3DXMatrixMultiply(&matResult, &matResult, &matTemp);

            bAnimate = true;
        }

        if (m_pPositionKeys)
        {
            dwp2=dwp3=0;

            fTime = (float)fmod(fGlobalTime, m_pPositionKeys[m_cPositionKeys-1].dwTime);

            for (iKey = 0 ;iKey < m_cPositionKeys ; iKey++)
            {
                if ((float)m_pPositionKeys[iKey].dwTime > fTime)
                {
                    dwp3 = iKey;

                    if (iKey > 0)
                    {
                        dwp2= iKey - 1;
                    }
                    else  // when iKey == 0, then dwp2 == 0
                    {
                        dwp2 = iKey;
                    }

                    break;
                }
            }
            fTime1 = (float)m_pPositionKeys[dwp2].dwTime;
            fTime2 = (float)m_pPositionKeys[dwp3].dwTime;

            if ((fTime2 - fTime1) ==0)
                fLerpValue = 0;
            else
                fLerpValue =  (fTime - fTime1)  / (fTime2 - fTime1);


            D3DXVec3Lerp((D3DXVECTOR3*)&vPos,
                    &m_pPositionKeys[dwp2].vPos,
                    &m_pPositionKeys[dwp3].vPos,
                    fLerpValue);

//			m_vCurrentPos = vPos;
            D3DXMatrixTranslation(&matTemp, vPos.x, vPos.y, vPos.z);

            D3DXMatrixMultiply(&matResult, &matResult, &matTemp);
            bAnimate = true;
        }
        else
        {
            D3DXMatrixTranslation(&matTemp, pframeToAnimate->matRotOrig._41, pframeToAnimate->matRotOrig._42, pframeToAnimate->matRotOrig._43);

            D3DXMatrixMultiply(&matResult, &matResult, &matTemp);
        }

        if (bAnimate)
        {
            pframeToAnimate->matRot = matResult;
        }
    }
}

//////////////////////////////////////////////////////////////////
// CSkinnedMesh 
CSkinnedMesh::CSkinnedMesh()
{
	//	FLOG( "CSkinnedMesh()" );
	m_pd3dDevice = NULL;

    m_pmcSelectedMesh = NULL;
    m_pframeSelected = NULL;
    m_pdeHead = NULL;
    m_pdeSelected = NULL;
    m_pBoneMatrices = NULL;
    m_maxBones = 0;
    m_method = SOFTWARE;
//    m_method = D3DNONINDEXED;
    m_dwFVF = D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_NORMAL | D3DFVF_TEX1;

	m_bTotalTextureNum = 0;
	m_bTextureNum = 0;
	m_pTexture = NULL;

	m_pGameData = NULL;
	m_pDataHeader = NULL;
	m_nRenderCount = 0;
	m_bMaterial = FALSE;
	m_bCheckBlend = FALSE;
	m_bProgressiveMesh = 0;
	D3DUtil_InitMaterial( m_material, 1.0f, 1.0f, 1.0f );// 임시 코드
	m_material.Specular.r = 1.0f;
	m_material.Specular.g = 1.0f;
	m_material.Specular.b = 1.0f;
	m_material.Power = 1.0f;
	m_bMultiTexture = FALSE;
	m_pOrderTexture = NULL;
	m_fRadius = 0.0f;
	m_vCenter = D3DXVECTOR3(0,0,0);
}

CSkinnedMesh::CSkinnedMesh(BOOL bProgressiveMesh)
{
	//	FLOG( "CSkinnedMesh(BOOL bProgressiveMesh)" );
	m_pd3dDevice = NULL;

    m_pmcSelectedMesh = NULL;
    m_pframeSelected = NULL;
    m_pdeHead = NULL;
    m_pdeSelected = NULL;
    m_pBoneMatrices = NULL;
    m_maxBones = 0;
    m_method = SOFTWARE;
//    m_method = D3DNONINDEXED;
    m_dwFVF = D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_NORMAL | D3DFVF_TEX1;

	m_bTotalTextureNum = 0;
	m_bTextureNum = 0;
	m_pTexture = NULL;

	m_pGameData = NULL;
	m_pDataHeader = NULL;
	m_nRenderCount = 0;
	m_bMaterial = FALSE;
	m_bCheckBlend = FALSE;
	m_bProgressiveMesh = bProgressiveMesh;
	D3DUtil_InitMaterial( m_material, 1.0f, 1.0f, 1.0f );// 임시 코드
	m_material.Specular.r = 1.0f;
	m_material.Specular.g = 1.0f;
	m_material.Specular.b = 1.0f;
	m_material.Power = 1.0f;
	m_bMultiTexture = FALSE;
	m_pOrderTexture = NULL;
	m_fRadius = 0.0f;
	m_vCenter = D3DXVECTOR3(0,0,0);
}

CSkinnedMesh::~CSkinnedMesh()
{
	//	FLOG( "~CSkinnedMesh()" );
	SAFE_DELETE_ARRAY(m_pDataHeader);
}

HRESULT CSkinnedMesh::InitDeviceObjects()
{
	//	FLOG( "CSkinnedMesh::InitDeviceObjects()" );
// 2004-06-17, cmkwon,
	m_pd3dDevice = g_pNPCGlobal->m_D3DApp.GetD3DDevice();
    m_pd3dDevice->GetDeviceCaps( &m_d3dCaps );
	return CAtumNode::InitDeviceObjects();
}

HRESULT CSkinnedMesh::RestoreDeviceObjects()
{
 	//	FLOG( "CSkinnedMesh::RestoreDeviceObjects()" );
   HRESULT hr = S_OK;

	return CAtumNode::RestoreDeviceObjects();
}

HRESULT CSkinnedMesh::InvalidateDeviceObjects()
{
	//	FLOG( "CSkinnedMesh::InvalidateDeviceObjects()" );
	for (SDrawElement* pdeCurr = m_pdeHead; pdeCurr != NULL; pdeCurr = pdeCurr->pdeNext)
	{
		ReleaseDeviceDependentMeshes(pdeCurr->pframeRoot);
	}
	return CAtumNode::InvalidateDeviceObjects();
}
HRESULT CSkinnedMesh::DeleteDeviceObjects()
{
	//	FLOG( "CSkinnedMesh::DeleteDeviceObjects()" );
	if( m_pdeSelected == m_pdeHead )
		m_pdeSelected = NULL;
	delete m_pdeHead;
	m_pdeHead = NULL;
	delete [] m_pBoneMatrices;
	m_pBoneMatrices = NULL;
	if(m_pTexture)
	{
		for(int n=0 ; n<m_bTotalTextureNum ; n++) 
		{
			SAFE_RELEASE(m_pTexture[n]);
		}
		if(m_bTotalTextureNum > 0)
			SAFE_DELETE_ARRAY(m_pTexture);
	}
	SAFE_DELETE_ARRAY(m_pDataHeader);
	m_pOrderTexture = NULL;
	return CAtumNode::DeleteDeviceObjects();
}

void CSkinnedMesh::Tick(float fElapsedTime)
{
	//	FLOG( "CSkinnedMesh::Tick(float fElapsedTime)" );
	SDrawElement *pdeCur;
	SFrame *pframeCur;

	pdeCur = m_pdeHead;
	while (pdeCur != NULL)
	{
		pdeCur->fCurTime = fElapsedTime*160;
		pframeCur = pdeCur->pframeAnimHead;
		while (pframeCur != NULL)
		{
			pframeCur->SetTime(pdeCur->fCurTime);
			pframeCur = pframeCur->pframeAnimNext;
		}

		pdeCur = pdeCur->pdeNext;
	}
}

HRESULT CSkinnedMesh::SetProjectionMatrix()
{
//	//	FLOG( "CSkinnedMesh::SetProjectionMatrix()" );
	D3DXMATRIX mat;

	if (m_pdeHead == NULL)
		return S_OK;

	FLOAT fAspect = 1.0f;
//	D3DXMatrixPerspectiveFovRH(&mat, 0.25f*3.141592654f, fAspect, m_pdeSelected->fRadius / 64, m_pdeSelected->fRadius * 200);
	D3DXMatrixPerspectiveFovRH(&mat, D3DX_PI/3, 800.0f/600.0f, 1.0f, 10000.0f);
	HRESULT hr = m_pd3dDevice->SetTransform( D3DTS_PROJECTION, (D3DMATRIX*)&mat );
	if (FAILED(hr))
		return hr;
	// Set Projection Matrix for vertex shader
	D3DXMatrixTranspose(&mat, &mat);
	return S_OK;
}

COLLISION_RESULT CSkinnedMesh::CheckCollision(D3DXMATRIX mat)
{
//	//	FLOG( "CSkinnedMesh::CheckCollision(D3DXMATRIX mat)" );
	COLLISION_RESULT collResult,checkcollResult;
	SDrawElement *pdeCur;
    pdeCur = m_pdeHead;
	collResult.fDist = 10000.0f;
	collResult.vNormalVector = D3DXVECTOR3(0,0,0);
    while (pdeCur != NULL)
    {
        UpdateFrames(pdeCur->pframeRoot, m_mWorld);
		checkcollResult = CheckCollDist(pdeCur->pframeRoot,mat);
		if(collResult.fDist > checkcollResult.fDist)
			collResult = checkcollResult;
        pdeCur = pdeCur->pdeNext;
    }
	return collResult;
}

COLLISION_RESULT CSkinnedMesh::CheckCollDist(SFrame *pframeCur,D3DXMATRIX mat)
{
//	//	FLOG( "CSkinnedMesh::CheckCollDist(SFrame *pframeCur,D3DXMATRIX mat)" );
	COLLISION_RESULT collResult,checkcollResult;
	SMeshContainer *pmcMesh;
	SFrame *pframeChild;
	collResult.fDist = 10000.0f;
	collResult.vNormalVector = D3DXVECTOR3(0,0,0);
//	if (pframeCur->pmcMesh != NULL)
//	{
//		m_pd3dDevice->SetTransform(D3DTS_WORLD, &pframeCur->matCombined);
//	}
	pmcMesh = pframeCur->pmcMesh;
	while (pmcMesh != NULL)
	{
		// 충돌 체크해야함
		checkcollResult = CheckCollDistDetail(pmcMesh, pframeCur->matCombined,mat);
		if(collResult.fDist > checkcollResult.fDist)
			collResult = checkcollResult;
		pmcMesh = pmcMesh->pmcNext;
	}
	pframeChild = pframeCur->pframeFirstChild;
	while (pframeChild != NULL)
	{
		checkcollResult = CheckCollDist(pframeChild,mat);
		if(collResult.fDist > checkcollResult.fDist)
			collResult = checkcollResult;
		pframeChild = pframeChild->pframeSibling;
	}
	return collResult;
}

COLLISION_RESULT CSkinnedMesh::CheckCollDistDetail(SMeshContainer *pmcMesh,D3DXMATRIX matThis,D3DXMATRIX mat)
{
//	//	FLOG( "CSkinnedMesh::CheckCollDistDetail(SMeshContainer *pmcMesh,D3DXMATRIX mat)" );
	COLLISION_RESULT collResult;
    if (pmcMesh->m_pSkinMesh)
    {
        if (m_method == SOFTWARE)
        {
            D3DXMATRIX  Identity;
            DWORD       cBones  = pmcMesh->m_pSkinMesh->GetNumBones();
            // set up bone transforms
            for (DWORD iBone = 0; iBone < cBones; ++iBone)
            {
                D3DXMatrixMultiply
                (
                    &m_pBoneMatrices[iBone],                 // output
                    &pmcMesh->m_pBoneOffsetMat[iBone], 
                    pmcMesh->m_pBoneMatrix[iBone]
                );
            }
            // set world transform
            D3DXMatrixIdentity(&Identity);
            m_pd3dDevice->SetTransform(D3DTS_WORLD, &Identity);
            // generate skinned mesh
			if(!pmcMesh->pMesh)
			{
				collResult.fDist = 10000.0f;
				return collResult;
			}
            pmcMesh->m_pSkinMesh->UpdateSkinnedMesh(m_pBoneMatrices, NULL, pmcMesh->pMesh);
		}
	}

    BOOL bHit,bIntersections;
    DWORD dwFace;
	FLOAT fBary1, fBary2, fDist;

	D3DXMATRIX matProj;
	D3DXVECTOR3 vPickRayDir, vPickRayOrig;
	D3DXMATRIX m, matWorld;
// 2004-06-17, cmkwon,
//	m_pd3dDevice->GetTransform( D3DTS_PROJECTION, &matProj );

// 2004-06-17, cmkwon,
	D3DXMatrixInverse( &m, NULL, &matThis );
	matWorld = matThis;
	m = mat*m;
	//D3DXMatrixInverse( &m, NULL, &m );
	vPickRayDir.x = m._31;
	vPickRayDir.y = m._32;	
	vPickRayDir.z = m._33;	
	vPickRayOrig.x = m._41;
	vPickRayOrig.y = m._42;
	vPickRayOrig.z = m._43;

// 2004-07-03 jschoi
	D3DXIntersect(pmcMesh->pMesh, &vPickRayOrig, &vPickRayDir, &bHit, &dwFace, &fBary1, &fBary2, &fDist, 
		NULL, NULL);
	if( bHit )
	{
		bIntersections = TRUE;
		m_Intersection.dwFace = dwFace;
		m_Intersection.fBary1 = fBary1;
		m_Intersection.fBary2 = fBary2;
		m_Intersection.fDist = fDist;
	}
	else
	{
		bIntersections = FALSE;
	}
		
	if( bIntersections )
	{
		WORD*			pIndices;
		D3DVERTEX*		pVertices;
		
		D3DVERTEX vThisTri[3];
		WORD* iThisTri;

		LPDIRECT3DVERTEXBUFFER8 pVB;
		LPDIRECT3DINDEXBUFFER8  pIB;	
		pmcMesh->pMesh->GetVertexBuffer(&pVB);
		pmcMesh->pMesh->GetIndexBuffer( &pIB );
		pIB->Lock( 0,0,(BYTE**)&pIndices, 0 );
		pVB->Lock( 0,0,(BYTE**)&pVertices, 0 );
		
//		vThisTri = &pVertices[0];
		iThisTri = &pIndices[3*m_Intersection.dwFace];
		// get vertices hit
		vThisTri[0] = pVertices[iThisTri[0]];
		vThisTri[1] = pVertices[iThisTri[1]];
		vThisTri[2] = pVertices[iThisTri[2]];

		pVB->Unlock();
        pIB->Unlock();
		
        pVB->Release();
        pIB->Release();

////		D3DXMatrixInverse( &matWorld, NULL, &matWorld );
//		D3DXVec3TransformCoord(&vThisTri[0].p, &vThisTri[0].p, &matWorld);
//		D3DXVec3TransformCoord(&vThisTri[1].p, &vThisTri[1].p, &matWorld);
//		D3DXVec3TransformCoord(&vThisTri[2].p, &vThisTri[2].p, &matWorld);
//		D3DXVec3TransformNormal(&vThisTri[0].n, &vThisTri[0].n, &matWorld);
//		D3DXVec3TransformNormal(&vThisTri[1].n, &vThisTri[1].n, &matWorld);
//		D3DXVec3TransformNormal(&vThisTri[2].n, &vThisTri[2].n, &matWorld);
//		
////		// 법선을 구한다.  -  2004-07-03  jschoi
////	
////		D3DXVECTOR3 vTempNormal;
////		D3DXVECTOR3 vDir1,vDir2;
////		
////		vDir1 = vThisTri[0].p - vThisTri[1].p;
////		vDir2 = vThisTri[1].p - vThisTri[2].p;
////
////		D3DXVec3Cross(&vTempNormal,&vDir1,&vDir2);
////		D3DXVec3Normalize(&vTempNormal, &vTempNormal);
//	
//		D3DXVECTOR3 vNormalVector;
//		vNormalVector = vThisTri[0].n + vThisTri[1].n + vThisTri[2].n;
//		D3DXVec3Normalize(&vNormalVector, &vNormalVector);
//		
//		collResult.fDist = fDist;
//		collResult.vNormalVector = vNormalVector;
//		D3DXMatrixInverse( &matWorld, NULL, &matWorld );


		D3DXVec3TransformCoord(&vThisTri[0].p, &vThisTri[0].p, &matWorld);
		D3DXVec3TransformCoord(&vThisTri[1].p, &vThisTri[1].p, &matWorld);
		D3DXVec3TransformCoord(&vThisTri[2].p, &vThisTri[2].p, &matWorld);
		
		D3DXVECTOR3 vTempNormal, vNormalVector;
		D3DXVECTOR3 vCross1,vCross2;
		vCross1 = vThisTri[0].p - vThisTri[1].p;
		vCross2 = vThisTri[1].p - vThisTri[2].p;
		D3DXVec3Cross(&vTempNormal,&vCross1,&vCross2);
		D3DXVec3Normalize(&vNormalVector, &vTempNormal);
	
		collResult.fDist = fDist;
		collResult.vNormalVector = vNormalVector;
		return collResult;
	}
	
	collResult.fDist = 10000.0f;
	collResult.vNormalVector = D3DXVECTOR3 (0,0,0);

	return collResult;
}

// by dhkwon, 030917, 텍스쳐 강제 세팅을 위해 사용, 렌더링 후에는 이함수를 통해 원래대로 돌려야 한다.
//LPDIRECT3DTEXTURE8 CSkinnedMesh::SetTexture(LPDIRECT3DTEXTURE8 pTexture
//											, BYTE tex_num)
//{
//	//	FLOG( "CSkinnedMesh::SetTexture(LPDIRECT3DTEXTURE8 pTexture, BYTE tex_num)" );
//	LPDIRECT3DTEXTURE8 pTemp = m_pTexture[tex_num];
//	m_pTexture[tex_num] = pTexture;
//	return pTemp;
//}

HRESULT CSkinnedMesh::LoadMeshHierarchy(char* szFileName)
{
	//	FLOG( "CSkinnedMesh::LoadMeshHierarchy(char* szFileName)" );
    TCHAR* pszFile = szFileName;
    SDrawElement *pdeMesh = NULL;
    HRESULT hr = S_OK;
    LPDIRECTXFILE pxofapi = NULL;
    LPDIRECTXFILEENUMOBJECT pxofenum = NULL;
    LPDIRECTXFILEDATA pxofobjCur = NULL;
    DWORD dwOptions;
    int cchFileName;

    if (pszFile == NULL)
        return E_INVALIDARG;
    
    pdeMesh = new SDrawElement();
    
    delete pdeMesh->pframeRoot;
    pdeMesh->pframeAnimHead = NULL;
    
    pdeMesh->pframeRoot = new SFrame();
    if (pdeMesh->pframeRoot == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto e_Exit;
    }
    
    
    dwOptions = 0;
    
    cchFileName = strlen(pszFile);
    if (cchFileName < 2)
    {
        hr = E_FAIL;
        goto e_Exit;
    }
    
    hr = DirectXFileCreate(&pxofapi);
    if (FAILED(hr))
        goto e_Exit;  
    
    // Register templates for d3drm.
    hr = pxofapi->RegisterTemplates((LPVOID)D3DRM_XTEMPLATES,
        D3DRM_XTEMPLATE_BYTES);
    if (FAILED(hr))
        goto e_Exit;
 

    hr = pxofapi->RegisterTemplates((LPVOID)szTemplates,
        strlen(szTemplates));
    if (FAILED(hr))
        goto e_Exit;

	
    // Create enum object.
    hr = pxofapi->CreateEnumObject((LPVOID)pszFile,
        DXFILELOAD_FROMFILE,
        &pxofenum);
    if (FAILED(hr))
        goto e_Exit;
     
    
    // Enumerate top level objects.
    // Top level objects are always data object.
    while (SUCCEEDED(pxofenum->GetNextDataObject(&pxofobjCur)))
    {
        hr = LoadFrames(pxofobjCur, pdeMesh, dwOptions, m_dwFVF,
            m_pd3dDevice,
            pdeMesh->pframeRoot);
        GXRELEASE(pxofobjCur);
        
        if (FAILED(hr))
            goto e_Exit;
    }
    
    hr = FindBones(pdeMesh->pframeRoot, pdeMesh);
    if (FAILED(hr))
        goto e_Exit;
    
    
    delete []pdeMesh->szName;
    pdeMesh->szName = new char[cchFileName+1];
    if (pdeMesh->szName == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto e_Exit;
    }
    memcpy(pdeMesh->szName, pszFile, cchFileName+1);

    // delete the current mesh, now that the load has succeeded
    DeleteSelectedMesh();

    // link into the draw list
    pdeMesh->pdeNext = m_pdeHead;
    m_pdeHead = pdeMesh;
    
    m_pdeSelected = pdeMesh;
    m_pmcSelectedMesh = pdeMesh->pframeRoot->pmcMesh;
    
    
    m_pframeSelected = pdeMesh->pframeRoot;
    
    hr = CalculateBoundingSphere(pdeMesh);
	m_fRadius = pdeMesh->fRadius;
	m_vCenter = pdeMesh->vCenter;

    if (FAILED(hr))
        goto e_Exit;
    
    SetProjectionMatrix();
    
    m_pdeSelected->fCurTime = 0.0f;
    m_pdeSelected->fMaxTime = 2000.0f;
    
    D3DXMatrixTranslation(&m_pdeSelected->pframeRoot->matRot,
        -pdeMesh->vCenter.x, -pdeMesh->vCenter.y, -pdeMesh->vCenter.z);
    m_pdeSelected->pframeRoot->matRotOrig = m_pdeSelected->pframeRoot->matRot;
    
e_Exit:
    GXRELEASE(pxofobjCur);
    GXRELEASE(pxofenum);
    GXRELEASE(pxofapi);
    
    if (FAILED(hr))
    {
		// 에러 발생
//cmkwon		g_pD3dApp->CheckError(CLIENT_ERR_MESHLOAD);  
        delete pdeMesh;
    }

    SDrawElement *pdeCur;
    pdeCur = m_pdeHead;
    while (pdeCur != NULL)
    {
        D3DXMatrixIdentity(&pdeCur->pframeRoot->matRot);
        D3DXMatrixIdentity(&pdeCur->pframeRoot->matTrans);
        pdeCur = pdeCur->pdeNext;
    }
    return hr;
}

HRESULT CSkinnedMesh::LoadMeshHierarchyFromMem(CGameData* pGameData, D3DXVECTOR3 vObjScale)	// 2012-05-23 by isshin 맵툴 개선 오브젝트 스케일 적용
{
	// 2012-05-23 by isshin 맵툴 개선 오브젝트 스케일 적용
	D3DXMATRIX objscale;
	D3DXMatrixIdentity(&objscale);
	D3DXMatrixScaling(&objscale, vObjScale.x, vObjScale.y, vObjScale.z);
	// end 2012-05-23 by isshin 맵툴 개선 오브젝트 스케일 적용

	//	FLOG( "CSkinnedMesh::LoadMeshHierarchyFromMem(CGameData* pGameData)" );
	SDrawElement *pdeMesh = NULL;
	HRESULT hr = S_OK;
	LPDIRECTXFILE pxofapi = NULL;
	LPDIRECTXFILEENUMOBJECT pxofenum = NULL;
	LPDIRECTXFILEDATA pxofobjCur = NULL;
	LPDXFILELOADMEMORY pMemory = NULL;
	DWORD dwOptions;

    pdeMesh = new SDrawElement();
	pMemory = new DXFILELOADMEMORY;
    
    delete pdeMesh->pframeRoot;
    pdeMesh->pframeAnimHead = NULL;
    
    pdeMesh->pframeRoot = new SFrame();

	// object file loading
	char* pPointer = NULL;
	m_pGameData = pGameData;

	int totalNum = m_pGameData->GetTotalNumber();
	m_pDataHeader = new DataHeader[totalNum];
	DataHeader* pHeader = m_pGameData->GetStartPosition();
	int i=0;
	while(pHeader)
	{
		m_pDataHeader[i] = *pHeader;
		m_pDataHeader[i++].m_pData = pHeader->m_pData;
		pHeader = m_pGameData->GetNext();
	}

    if (pdeMesh->pframeRoot == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto e_Exit;
    }
    
    dwOptions = 0;

    hr = DirectXFileCreate(&pxofapi);
    if (FAILED(hr))
        goto e_Exit;  
    
    // Register templates for d3drm.
    hr = pxofapi->RegisterTemplates((LPVOID)D3DRM_XTEMPLATES,
        D3DRM_XTEMPLATE_BYTES);
    if (FAILED(hr))
        goto e_Exit;

    hr = pxofapi->RegisterTemplates((LPVOID)szTemplates,
        strlen(szTemplates));
    if (FAILED(hr))
        goto e_Exit;

	pMemory->lpMemory = m_pDataHeader[0].m_pData;
	pMemory->dSize = m_pDataHeader[0].m_DataSize;
    // Create enum object.
    hr = pxofapi->CreateEnumObject((LPVOID)pMemory,
        DXFILELOAD_FROMMEMORY,
        &pxofenum);
    if (FAILED(hr))
        goto e_Exit;

	/*********************************************************************************/
	/* 여기에서 텍스쳐를 로드 하지 않는다.
    // Create enum texture
	if(totalNum > 1)
	{
		m_pTexture = new LPDIRECT3DTEXTURE8[totalNum-1];
		m_bTotalTextureNum = totalNum-1;
		for(i=1; i<totalNum; i++)
		{
			if( FAILED( D3DXCreateTextureFromFileInMemory(m_pd3dDevice, (LPCVOID)m_pDataHeader[i].m_pData, m_pDataHeader[i].m_DataSize, &m_pTexture[i-1] ))) 
			{
				hr = E_FAIL;
	//			goto e_Exit;
			}
		}
	}
	else
	{
		m_pTexture = new LPDIRECT3DTEXTURE8[1];
		m_pTexture[0] = NULL;
	}
	*/
/*****************************************************************************************/

    // Enumerate top level objects.
    // Top level objects are always data object.
    while (SUCCEEDED(pxofenum->GetNextDataObject(&pxofobjCur)))
    {
        hr = LoadFrames(pxofobjCur, pdeMesh, dwOptions, m_dwFVF,
            m_pd3dDevice,
            pdeMesh->pframeRoot);
        GXRELEASE(pxofobjCur);
        
        if (FAILED(hr))
            goto e_Exit;
    }
    
    hr = FindBones(pdeMesh->pframeRoot, pdeMesh);
    if (FAILED(hr))
        goto e_Exit;
    
    
    delete []pdeMesh->szName;
	pdeMesh->szName = NULL;

    // delete the current mesh, now that the load has succeeded
    DeleteSelectedMesh();

    // link into the draw list
    pdeMesh->pdeNext = m_pdeHead;
    m_pdeHead = pdeMesh;
    
    m_pdeSelected = pdeMesh;
    m_pmcSelectedMesh = pdeMesh->pframeRoot->pmcMesh;
    
    m_pframeSelected = pdeMesh->pframeRoot;
    
    hr = CalculateBoundingSphere(pdeMesh, vObjScale);	// 2012-05-23 by isshin 맵툴 개선 오브젝트 스케일 적용
  	m_fRadius = pdeMesh->fRadius;
	m_vCenter = pdeMesh->vCenter;

	if (FAILED(hr))
        goto e_Exit;
    
    SetProjectionMatrix();
    
    m_pdeSelected->fCurTime = 0.0f;
    m_pdeSelected->fMaxTime = 2000.0f;
    
	D3DXMatrixMultiply(&m_pdeSelected->pframeRoot->matRot,  &objscale, &m_pdeSelected->pframeRoot->matRot);	// 2012-05-23 by isshin 맵툴 개선 오브젝트 스케일 적용
    
    D3DXMatrixTranslation(&m_pdeSelected->pframeRoot->matRot,
        -pdeMesh->vCenter.x, -pdeMesh->vCenter.y, -pdeMesh->vCenter.z);
    m_pdeSelected->pframeRoot->matRotOrig = m_pdeSelected->pframeRoot->matRot;
    
e_Exit:
//	SAFE_DELETE(m_pGameData);// m_pDataHeader는 m_pData는 무효하고, 나머지는 유효하다.
	SAFE_DELETE(pMemory);
	for(i=0; i<totalNum; i++)
		m_pDataHeader[i].m_pData = NULL;
    GXRELEASE(pxofobjCur);
    GXRELEASE(pxofenum);
    GXRELEASE(pxofapi);
    
    if (FAILED(hr))
    {
		// 에러 발생
        delete pdeMesh;
		pdeMesh = NULL;
    }

    SDrawElement *pdeCur;
    pdeCur = m_pdeHead;
    while (pdeCur != NULL)
    {
        D3DXMatrixIdentity(&pdeCur->pframeRoot->matRot);
        D3DXMatrixIdentity(&pdeCur->pframeRoot->matTrans);
        pdeCur = pdeCur->pdeNext;
    }
    return hr;
}

//HRESULT CSkinnedMesh::LoadTexture(char* szfileName, 
//								  BYTE tex_num)
//{
//	//	FLOG( "CSkinnedMesh::LoadTexture(char* szfileName, BYTE tex_num)" );
//	if( FAILED( D3DXCreateTextureFromFile(m_pd3dDevice, szfileName, &m_pTexture[tex_num-1]))) return E_FAIL;
//		return TRUE;
//}

HRESULT CSkinnedMesh::LoadFrames(LPDIRECTXFILEDATA pxofobjCur, 
								 SDrawElement *pde, 
								 DWORD options, DWORD fvf, 
								 LPDIRECT3DDEVICE8 pD3DDevice, 
								 SFrame *pframeParent)
{
//	//	FLOG( "CSkinnedMesh::LoadFrames(LPDIRECTXFILEDATA pxofobjCur, SDrawElement *pde, DWORD options, DWORD fvf, LPDIRECT3DDEVICE8 pD3DDevice, SFrame *pframeParent)" );
    HRESULT hr = S_OK;
    LPDIRECTXFILEDATA pxofobjChild = NULL;
    LPDIRECTXFILEOBJECT pxofChild = NULL;
    const GUID *type;
    DWORD cbSize;
    D3DXMATRIX *pmatNew;
    SFrame *pframeCur;
    DWORD cchName;
    
    // Get the type of the object
    hr = pxofobjCur->GetType(&type);
    if (FAILED(hr))
        goto e_Exit;
    
    
    if (*type == TID_D3DRMMesh)
    {
        hr = LoadMesh(pxofobjCur, options, fvf, pD3DDevice, pframeParent);
        if (FAILED(hr))
            goto e_Exit;
    }
    else if (*type == TID_D3DRMFrameTransformMatrix)
    {
        hr = pxofobjCur->GetData(NULL, &cbSize, (PVOID*)&pmatNew);
        if (FAILED(hr))
            goto e_Exit;
        
        // update the parents matrix with the new one
        pframeParent->matRot = *pmatNew;
        pframeParent->matRotOrig = *pmatNew;
    }
    else if (*type == TID_D3DRMAnimationSet)
    {
        LoadAnimationSet(pxofobjCur, pde, options, fvf, pD3DDevice, pframeParent);
    }
    else if (*type == TID_D3DRMAnimation)
    {
        LoadAnimation(pxofobjCur, pde, options, fvf, pD3DDevice, pframeParent);
    }
    else if (*type == TID_D3DRMFrame)
    {
        pframeCur = new SFrame();
        if (pframeCur == NULL)
        {
            hr = E_OUTOFMEMORY;
            goto e_Exit;
        }
        
        hr = pxofobjCur->GetName(NULL, &cchName);
        if (FAILED(hr))
            goto e_Exit;
        
        if (cchName > 0)
        {
            pframeCur->szName = new char[cchName];
            if (pframeCur->szName == NULL)
            {
                hr = E_OUTOFMEMORY;
                goto e_Exit;
            }
            
            hr = pxofobjCur->GetName(pframeCur->szName, &cchName);
            if (FAILED(hr))
                goto e_Exit;
        }
        
        pframeParent->AddFrame(pframeCur);
        
        // Enumerate child objects.
        // Child object can be data, data reference or binary.
        // Use QueryInterface() to find what type of object a child is.
        while (SUCCEEDED(pxofobjCur->GetNextObject(&pxofChild)))
        {
            // Query the child for it's FileData
            hr = pxofChild->QueryInterface(IID_IDirectXFileData,
                (LPVOID *)&pxofobjChild);
            if (SUCCEEDED(hr))
            {
                hr = LoadFrames(pxofobjChild, pde, options, fvf, pD3DDevice, pframeCur);
                if (FAILED(hr))
                    goto e_Exit;
                
                GXRELEASE(pxofobjChild);
            }
            
            GXRELEASE(pxofChild);
        }
        
    }
    
e_Exit:
    GXRELEASE(pxofobjChild);
    GXRELEASE(pxofChild);
    return hr;
}

HRESULT CSkinnedMesh::LoadMesh(LPDIRECTXFILEDATA pxofobjCur,
                                    DWORD options, DWORD fvf, 
									LPDIRECT3DDEVICE8 pD3DDevice,
                                    SFrame *pframeParent)
{
//	//	FLOG( "CSkinnedMesh::LoadMesh(LPDIRECTXFILEDATA pxofobjCur, DWORD options, DWORD fvf, LPDIRECT3DDEVICE8 pD3DDevice, SFrame *pframeParent)" );
    HRESULT hr = S_OK;
    SMeshContainer *pmcMesh = NULL;
    LPD3DXBUFFER pbufMaterials = NULL;
    LPD3DXBUFFER pbufAdjacency = NULL;
    DWORD cchName;
    UINT cFaces;
    UINT iMaterial;
    LPDIRECT3DDEVICE8 m_pDevice = m_pd3dDevice;
    LPDWORD pAdjacencyIn;
//    LPD3DXPMESH  pPMesh = NULL;
 //   LPD3DXPMESH  pPMeshTemp = NULL;
 //   LPD3DXMESH   pMesh = NULL;
//    LPD3DXMESH   pTempMesh = NULL;
	int i;  
//	DWORD num;
  
    pmcMesh = new SMeshContainer();
//	for(i = 0;i < 5;i++)
//		pmcMesh->pMeshes[i] = NULL;
	if (pmcMesh == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto e_Exit;
    }
    
    hr = pxofobjCur->GetName(NULL, &cchName);
    if (FAILED(hr))
        goto e_Exit;
    
    if (cchName > 0)
    {
        pmcMesh->szName = new char[cchName];
        if (pmcMesh->szName == NULL)
        {
            hr = E_OUTOFMEMORY;
            goto e_Exit;
        }
        
        hr = pxofobjCur->GetName(pmcMesh->szName, &cchName);
        if (FAILED(hr))
            goto e_Exit;
    }
    
    hr = D3DXLoadSkinMeshFromXof(pxofobjCur, options, pD3DDevice, &pbufAdjacency, &pbufMaterials, &pmcMesh->cMaterials, 
        &pmcMesh->m_pBoneNamesBuf, &pmcMesh->m_pBoneOffsetBuf, &pmcMesh->m_pSkinMesh);

//	DWORD num;//,num2,num3;

    if (FAILED(hr))
    {
        if (hr == D3DXERR_LOADEDMESHASNODATA)
            hr = S_OK;
        goto e_Exit;
    }
	
	
    cFaces = pmcMesh->m_pSkinMesh->GetNumFaces();

    pAdjacencyIn = static_cast<LPDWORD>(pbufAdjacency->GetBufferPointer());

    pmcMesh->m_rgiAdjacency = new DWORD[cFaces * 3];

    if (pmcMesh->m_rgiAdjacency == NULL)
    {
        hr = E_OUTOFMEMORY;

        goto e_Exit;
    }

    memcpy(pmcMesh->m_rgiAdjacency, pAdjacencyIn, cFaces * 3 * sizeof(DWORD));

    // Process skinning data
    if (pmcMesh->m_pSkinMesh->GetNumBones())
    {
        // Update max bones of any mesh in the app
        m_maxBones = max(pmcMesh->m_pSkinMesh->GetNumBones(), m_maxBones);
        
        pmcMesh->m_pBoneMatrix = new D3DXMATRIX*[pmcMesh->m_pSkinMesh->GetNumBones()];
        if (pmcMesh->m_pBoneMatrix == NULL)
            goto e_Exit;
        pmcMesh->m_pBoneOffsetMat = reinterpret_cast<D3DXMATRIX*>(pmcMesh->m_pBoneOffsetBuf->GetBufferPointer());
        
        hr = GenerateMesh(pmcMesh);

        if (FAILED(hr))
            goto e_Exit;
		/////////////////////// 본데이타를 무시하고 Temp Mesh를 생성하고 Progressive 를 적용한다 /////////////////////////////////////
//		if(m_bProgressiveMesh)
//		{
//	        pmcMesh->m_pSkinMesh->GetOriginalMesh(&pTempMesh);
//			D3DXCleanMesh(pTempMesh, (DWORD*)pbufAdjacency->GetBufferPointer(), &pMesh, (DWORD*)pbufAdjacency->GetBufferPointer(), NULL );
//		}
    }
    else
    {
        pmcMesh->m_pSkinMesh->GetOriginalMesh(&(pmcMesh->pMesh));
        pmcMesh->m_pSkinMesh->Release();
        pmcMesh->m_pSkinMesh = NULL;
        pmcMesh->cpattr = pmcMesh->cMaterials;
		/////////////////////// 본데이타가 없으면 Temp Mesh를 생성하고 Progressive 를 적용한다 ///////////////////////////////////////
//		if(m_bProgressiveMesh)
//			D3DXCleanMesh(pmcMesh->pMesh, (DWORD*)pbufAdjacency->GetBufferPointer(), &pMesh, (DWORD*)pbufAdjacency->GetBufferPointer(), NULL );
    }
    if ((pbufMaterials == NULL) || (pmcMesh->cMaterials == 0))
    {
        pmcMesh->rgMaterials = new D3DMATERIAL8[1];
        pmcMesh->pTextures = new LPDIRECT3DTEXTURE8[1];
        if (pmcMesh->rgMaterials == NULL || pmcMesh->pTextures == NULL)
        {
            hr = E_OUTOFMEMORY;
            goto e_Exit;
        }
        
        memset(pmcMesh->rgMaterials, 0, sizeof(D3DMATERIAL8));
        pmcMesh->rgMaterials[0].Diffuse.r = 1.0f;
        pmcMesh->rgMaterials[0].Diffuse.g = 1.0f;
        pmcMesh->rgMaterials[0].Diffuse.b = 1.0f;
        pmcMesh->rgMaterials[0].Specular = pmcMesh->rgMaterials[0].Diffuse;
        pmcMesh->pTextures[0] = NULL;
    }
    else
    {
        pmcMesh->rgMaterials = new D3DMATERIAL8[pmcMesh->cMaterials];
        pmcMesh->pTextures = new LPDIRECT3DTEXTURE8[pmcMesh->cMaterials];
        if (pmcMesh->rgMaterials == NULL || pmcMesh->pTextures == NULL)
        {
            hr = E_OUTOFMEMORY;
            goto e_Exit;
        }
        
        LPD3DXMATERIAL pMaterials = (LPD3DXMATERIAL)pbufMaterials->GetBufferPointer();
        
        for (iMaterial = 0; iMaterial < pmcMesh->cMaterials; iMaterial++)
        {
            
            pmcMesh->rgMaterials[iMaterial] = pMaterials[iMaterial].MatD3D;
			pmcMesh->rgMaterials[iMaterial].Ambient.r = 1.0f;
 			pmcMesh->rgMaterials[iMaterial].Ambient.g = 1.0f;
 			pmcMesh->rgMaterials[iMaterial].Ambient.b = 1.0f;
          
            pmcMesh->pTextures[iMaterial] = NULL;
            if (pMaterials[iMaterial].pTextureFilename != NULL)
            {
				if(m_pDataHeader && m_pGameData)
				{
					int num = m_pGameData->GetTotalNumber();
					for(i=1; i<num; i++ )
					{
						if(strcmp(m_pDataHeader[i].m_FileName, pMaterials[iMaterial].pTextureFilename) == 0 && m_pTexture)
						{
							m_pTexture[i-1]->AddRef();
							pmcMesh->pTextures[iMaterial] = m_pTexture[i-1];
							break;
						}
					}

				}
				else 
				{
					TCHAR szPath[MAX_PATH];
					DXUtil_FindMediaFile(szPath, pMaterials[iMaterial].pTextureFilename);

					hr = D3DXCreateTextureFromFile(m_pDevice, szPath, &(pmcMesh->pTextures[iMaterial]));
					if (FAILED(hr))
						pmcMesh->pTextures[iMaterial] = NULL;
				}
            }
        }
    }
    // add the mesh to the parent frame
    pframeParent->AddMesh(pmcMesh);
/* 	// 임시
	if(m_bProgressiveMesh)
	{
		DWORD maxnum = pMesh->GetNumVertices();
		DWORD minnum = maxnum/10;
		num = (DWORD)((maxnum-minnum)/5);
		for(i = 0;i < 5;i++)
			D3DXSimplifyMesh(pMesh,(DWORD*)pbufAdjacency->GetBufferPointer(),NULL,NULL,(maxnum-(num*(i+1))),D3DXMESHSIMP_VERTEX,&pmcMesh->pMeshes[i]);
		SAFE_RELEASE(pTempMesh);
		SAFE_RELEASE(pPMesh);
	}
*/	pmcMesh = NULL;
   
e_Exit:
    delete pmcMesh;
	pmcMesh = NULL;
    
//    SAFE_RELEASE( pMesh );
//    SAFE_RELEASE( pPMesh );
    GXRELEASE(pbufAdjacency);
    GXRELEASE(pbufMaterials);
    return hr;
}


HRESULT CSkinnedMesh::GenerateMesh(SMeshContainer *pmcMesh)
{
//	//	FLOG( "CSkinnedMesh::GenerateMesh(SMeshContainer *pmcMesh)" );
	// ASSUMPTION:  pmcMesh->m_rgiAdjacency contains the current adjacency
	HRESULT hr = S_OK;
	LPDIRECT3DDEVICE8 pDevice = NULL;
	DWORD cFaces = pmcMesh->m_pSkinMesh->GetNumFaces();
//	DWORD* rgiAdjacency;

	hr  = pmcMesh->m_pSkinMesh->GetDevice(&pDevice);
	if (FAILED(hr))
		goto e_Exit;

	GXRELEASE(pmcMesh->pMesh);
	delete [] m_pBoneMatrices;

	pmcMesh->pMesh      = NULL;
	m_pBoneMatrices     = NULL;
    
	if (m_method == D3DNONINDEXED)
	{
		LPD3DXBONECOMBINATION   rgBoneCombinations;

		hr = pmcMesh->m_pSkinMesh->ConvertToBlendedMesh
                                   (
                                       D3DXMESH_MANAGED|D3DXMESHOPT_VERTEXCACHE, 
                                       pmcMesh->m_rgiAdjacency, 
                                       NULL, 
                                       &pmcMesh->cpattr, 
                                       &pmcMesh->m_pBoneCombinationBuf, 
                                       NULL,
                                       NULL,
                                       &pmcMesh->pMesh
                                   );
		
		if (FAILED(hr))
		{
			goto e_Exit;
		}

		// calculate the max face influence count

		if ((pmcMesh->pMesh->GetFVF() & D3DFVF_POSITION_MASK) != D3DFVF_XYZ)
		{
			pmcMesh->m_maxFaceInfl = 1 + ((pmcMesh->pMesh->GetFVF() & D3DFVF_POSITION_MASK) - D3DFVF_XYZRHW) / 2;
		}
		else
		{
			pmcMesh->m_maxFaceInfl = 1;
		}

		/* If the device can only do 2 matrix blends, ConvertToBlendedMesh cannot approximate all meshes to it
			Thus we split the mesh in two parts: The part that uses at most 2 matrices and the rest. The first is
			drawn using the device's HW vertex processing and the rest is drawn using SW vertex processing. */
		if (m_d3dCaps.MaxVertexBlendMatrices <= 2)       
		{
			// calculate the index of the attribute table to split on
			rgBoneCombinations  = reinterpret_cast<LPD3DXBONECOMBINATION>(pmcMesh->m_pBoneCombinationBuf->GetBufferPointer());

			for (pmcMesh->iAttrSplit = 0; pmcMesh->iAttrSplit < pmcMesh->cpattr; pmcMesh->iAttrSplit++)
			{
                DWORD   cInfl   = 0;

                for (DWORD iInfl = 0; iInfl < pmcMesh->m_maxFaceInfl; iInfl++)
                {
                    if (rgBoneCombinations[pmcMesh->iAttrSplit].BoneId[iInfl] != UINT_MAX)
                    {
                        ++cInfl;
                    }
                }

                if (cInfl > m_d3dCaps.MaxVertexBlendMatrices)
                {
                    break;
                }
            }

            // if there is both HW and SW, add the Software Processing flag
            if (pmcMesh->iAttrSplit < pmcMesh->cpattr)
            {
                LPD3DXMESH pMeshTmp;

                hr = pmcMesh->pMesh->CloneMeshFVF(D3DXMESH_SOFTWAREPROCESSING|pmcMesh->pMesh->GetOptions(), 
                                                    pmcMesh->pMesh->GetFVF(),
                                                    pDevice, &pMeshTmp);
                if (FAILED(hr))
                {
                    goto e_Exit;
                }

                pmcMesh->pMesh->Release();
                pmcMesh->pMesh = pMeshTmp;
                pMeshTmp = NULL;
            }
        }
        else
        {
            pmcMesh->iAttrSplit = pmcMesh->cpattr;
        }
    }
    else if (m_method == D3DINDEXEDVS)
    {
        // Get palette size
        pmcMesh->m_paletteSize = min(28, pmcMesh->m_pSkinMesh->GetNumBones());

        DWORD flags = D3DXMESHOPT_VERTEXCACHE;
        if (m_d3dCaps.VertexShaderVersion >= D3DVS_VERSION(1, 1))
        {
            pmcMesh->m_bUseSW = false;
            flags |= D3DXMESH_MANAGED;
        }
        else
        {
            pmcMesh->m_bUseSW = true;
            flags |= D3DXMESH_SYSTEMMEM;
        }

        hr = pmcMesh->m_pSkinMesh->ConvertToIndexedBlendedMesh(flags, pmcMesh->m_rgiAdjacency, pmcMesh->m_paletteSize, NULL,
            &pmcMesh->cpattr, &pmcMesh->m_pBoneCombinationBuf, NULL, NULL, &pmcMesh->pMesh);
        if (FAILED(hr))
            goto e_Exit;

        if ((pmcMesh->pMesh->GetFVF() & D3DFVF_POSITION_MASK) != D3DFVF_XYZ)
        {
            pmcMesh->m_maxFaceInfl = ((pmcMesh->pMesh->GetFVF() & D3DFVF_POSITION_MASK) - D3DFVF_XYZRHW) / 2;
        }
        else
        {
            pmcMesh->m_maxFaceInfl = 1;
        }

        // FVF has to match our declarator. Vertex shaders are not as forgiving as FF pipeline
        DWORD newFVF = (pmcMesh->pMesh->GetFVF() & D3DFVF_POSITION_MASK) | D3DFVF_NORMAL | D3DFVF_TEX1 | D3DFVF_LASTBETA_UBYTE4;
        if (newFVF != pmcMesh->pMesh->GetFVF())
        {
            LPD3DXMESH pMesh;
            hr = pmcMesh->pMesh->CloneMeshFVF(pmcMesh->pMesh->GetOptions(), newFVF, pDevice, &pMesh);
            if (!FAILED(hr))
            {
                pmcMesh->pMesh->Release();
                pmcMesh->pMesh = pMesh;
                pMesh = NULL;
            }
        }
    }
    else if (m_method == D3DINDEXED)
    {
        DWORD maxFaceInfl;
        DWORD flags = D3DXMESHOPT_VERTEXCACHE;

        hr = pmcMesh->m_pSkinMesh->GetMaxFaceInfluences(&maxFaceInfl);
        if (FAILED(hr))
            goto e_Exit;

        // 12 entry palette guarantees that any triangle (4 independent influences per vertex of a tri)
        // can be handled
        maxFaceInfl = min(maxFaceInfl, 12);

        if (m_d3dCaps.MaxVertexBlendMatrixIndex + 1 < maxFaceInfl)
        {
            // HW does not support indexed vertex blending. Use SW instead
            pmcMesh->m_paletteSize = min(256, pmcMesh->m_pSkinMesh->GetNumBones());
            pmcMesh->m_bUseSW = true;
            flags |= D3DXMESH_SYSTEMMEM;
        }
        else
        {
            pmcMesh->m_paletteSize = min(m_d3dCaps.MaxVertexBlendMatrixIndex + 1, pmcMesh->m_pSkinMesh->GetNumBones());
            pmcMesh->m_bUseSW = false;
            flags |= D3DXMESH_MANAGED;
        }

        hr = pmcMesh->m_pSkinMesh->ConvertToIndexedBlendedMesh(flags, pmcMesh->m_rgiAdjacency, pmcMesh->m_paletteSize, NULL,
            &pmcMesh->cpattr, &pmcMesh->m_pBoneCombinationBuf, NULL, NULL, &pmcMesh->pMesh);
        if (FAILED(hr))
            goto e_Exit;

        // Here we are talking of max vertex influence which we determine from 
        // the FVF of the returned mesh
        if ((pmcMesh->pMesh->GetFVF() & D3DFVF_POSITION_MASK) != D3DFVF_XYZ)
        {
            pmcMesh->m_maxFaceInfl = ((pmcMesh->pMesh->GetFVF() & D3DFVF_POSITION_MASK) - D3DFVF_XYZRHW) / 2;
        }
        else
        {
            pmcMesh->m_maxFaceInfl = 1;
        }
    }
    else if (m_method == SOFTWARE)
    {
        hr = pmcMesh->m_pSkinMesh->GenerateSkinnedMesh
                                   (
                                       D3DXMESH_DYNAMIC,          // options
                                       0.0f,                        // minimum bone weight allowed
                                       pmcMesh->m_rgiAdjacency,     // adjacency of in-mesh
                                       NULL,     // adjacency of out-mesh
                                       NULL,     // face remap array
                                       NULL,     // vertex remap buffer
                                       &pmcMesh->pMesh              // out-mesh
                                   );
        if (FAILED(hr))
            goto e_Exit;

        hr = pmcMesh->pMesh->GetAttributeTable(NULL, &pmcMesh->cpattr);
        if (FAILED(hr))
            goto e_Exit;

        delete[] pmcMesh->m_pAttrTable;
        pmcMesh->m_pAttrTable  = new D3DXATTRIBUTERANGE[pmcMesh->cpattr];
        if (pmcMesh->m_pAttrTable == NULL)
        {
            hr = E_OUTOFMEMORY;
            goto e_Exit;
        }

        hr = pmcMesh->pMesh->GetAttributeTable(pmcMesh->m_pAttrTable, NULL);
        if (FAILED(hr))
            goto e_Exit;

        hr = pmcMesh->m_pSkinMesh->GetMaxFaceInfluences(&pmcMesh->m_maxFaceInfl);
        if (FAILED(hr))
            goto e_Exit;

        // Allocate space for blend matrices
        m_pBoneMatrices  = new D3DXMATRIXA16[m_maxBones];
        if (m_pBoneMatrices == NULL)
        {
            hr = E_OUTOFMEMORY;
            goto e_Exit;
        }
    }
    pmcMesh->m_Method = m_method;

e_Exit:

    GXRELEASE(pDevice);
    return hr;
}


HRESULT CSkinnedMesh::FindBones(SFrame *pframeCur, 
								SDrawElement *pde)
{
	//	FLOG( "CSkinnedMesh::FindBones(SFrame *pframeCur, SDrawElement *pde)" );
    HRESULT hr = S_OK;
    SMeshContainer *pmcMesh;
    SFrame *pframeChild;
    
    pmcMesh = pframeCur->pmcMesh;
    while (pmcMesh != NULL)
    {
        if (pmcMesh->m_pSkinMesh)
        {
            char** pBoneName = static_cast<char**>(pmcMesh->m_pBoneNamesBuf->GetBufferPointer());
            for (DWORD i = 0; i < pmcMesh->m_pSkinMesh->GetNumBones(); ++i)
            {
                SFrame* pFrame = pde->FindFrame(pBoneName[i]);
                pmcMesh->m_pBoneMatrix[i] = &(pFrame->matCombined);
            }
        }
        pmcMesh = pmcMesh->pmcNext;
    }
    
    pframeChild = pframeCur->pframeFirstChild;
    while (pframeChild != NULL)
    {
        hr = FindBones(pframeChild, pde);
        if (FAILED(hr))
            return hr;
        
        pframeChild = pframeChild->pframeSibling;
    }
    
    return S_OK;
}

HRESULT CSkinnedMesh::LoadAnimation(LPDIRECTXFILEDATA pxofobjCur, 
									SDrawElement *pde,
                                    DWORD options, DWORD fvf, 
									LPDIRECT3DDEVICE8 pD3DDevice,
                                    SFrame *pframeParent)
{
//	//	FLOG( "CSkinnedMesh::LoadAnimation(LPDIRECTXFILEDATA pxofobjCur, SDrawElement *pde, DWORD options, DWORD fvf, LPDIRECT3DDEVICE8 pD3DDevice, SFrame *pframeParent)" );
    HRESULT hr = S_OK;
    SRotateKeyXFile *pFileRotateKey;
    SScaleKeyXFile *pFileScaleKey;
    SPositionKeyXFile *pFilePosKey;
    SMatrixKeyXFile *pFileMatrixKey;
    SFrame *pframeCur1;
    LPDIRECTXFILEDATA pxofobjChild = NULL;
    LPDIRECTXFILEOBJECT pxofChild = NULL;
    LPDIRECTXFILEDATAREFERENCE pxofobjChildRef = NULL;
    const GUID *type;
    DWORD dwSize;
    PBYTE pData;
    DWORD dwKeyType;
    DWORD cKeys;
    DWORD iKey;
    DWORD cchName;
    char *szFrameName;
    
    pframeCur1 = new SFrame();
    if (pframeCur1 == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto e_Exit;
    }
    pframeCur1->bAnimationFrame = true;
    
    pframeParent->AddFrame(pframeCur1);
    pde->AddAnimationFrame(pframeCur1);
    
    // Enumerate child objects.
    // Child object can be data, data reference or binary.
    // Use QueryInterface() to find what type of object a child is.
    while (SUCCEEDED(pxofobjCur->GetNextObject(&pxofChild)))
    {
        // Query the child for it's FileDataReference
        hr = pxofChild->QueryInterface(IID_IDirectXFileDataReference,
            (LPVOID *)&pxofobjChildRef);
        if (SUCCEEDED(hr))
        {
            hr = pxofobjChildRef->Resolve(&pxofobjChild);
            if (SUCCEEDED(hr))
            {
                hr = pxofobjChild->GetType(&type);
                if (FAILED(hr))
                    goto e_Exit;
                
                if( TID_D3DRMFrame == *type )
                {
                    if (pframeCur1->pframeToAnimate != NULL)
                    {
                        hr = E_INVALIDARG;
                        goto e_Exit;
                    }
                    
                    hr = pxofobjChild->GetName(NULL, &cchName);
                    if (FAILED(hr))
                        goto e_Exit;
                    
                    if (cchName == 0)
                    {
                        hr = E_INVALIDARG;
                        goto e_Exit;
                        
                    }
                    
                    szFrameName = (char*)_alloca(cchName);
                    if (szFrameName == NULL)
                    {
                        hr = E_OUTOFMEMORY;
                        goto e_Exit;
                    }
                    
                    hr = pxofobjChild->GetName(szFrameName, &cchName);
                    if (FAILED(hr))
                        goto e_Exit;
                    
                    pframeCur1->pframeToAnimate = pde->FindFrame(szFrameName);
                    if (pframeCur1->pframeToAnimate == NULL)
                    {
                        hr = E_INVALIDARG;
                        goto e_Exit;
                    }
                }
                
                GXRELEASE(pxofobjChild);
            }
            
            GXRELEASE(pxofobjChildRef);
        }
        else
        {
            
            // Query the child for it's FileData
            hr = pxofChild->QueryInterface(IID_IDirectXFileData,
                (LPVOID *)&pxofobjChild);
            if (SUCCEEDED(hr))
            {
                hr = pxofobjChild->GetType(&type);
                if (FAILED(hr))
                    goto e_Exit;
                
                if ( TID_D3DRMFrame == *type )
                {
                    hr = LoadFrames(pxofobjChild, pde, options, fvf, pD3DDevice, pframeCur1);
                    if (FAILED(hr))
                        goto e_Exit;
                }
                else if ( TID_D3DRMAnimationOptions == *type )
                {
                }
                else if ( TID_D3DRMAnimationKey == *type )
                {
                    hr = pxofobjChild->GetData( NULL, &dwSize, (PVOID*)&pData );
                    if (FAILED(hr))
                        goto e_Exit;
                    
                    dwKeyType = ((DWORD*)pData)[0];
                    cKeys = ((DWORD*)pData)[1];
                    
                    if (dwKeyType == 0)
                    {
                        if (pframeCur1->m_pRotateKeys != NULL)
                        {
                            hr = E_INVALIDARG;
                            goto e_Exit;
                        }
                        
                        pframeCur1->m_pRotateKeys = new SRotateKey[cKeys];
                        if (pframeCur1->m_pRotateKeys == NULL)
                        {
                            hr = E_OUTOFMEMORY;
                            goto e_Exit;
                        }
                        
                        pframeCur1->m_cRotateKeys = cKeys;
                        //NOTE x files are w x y z and QUATERNIONS are x y z w
                        
                        pFileRotateKey =  (SRotateKeyXFile*)(pData + (sizeof(DWORD) * 2));
                        for (iKey = 0;iKey < cKeys; iKey++)
                        {
                            pframeCur1->m_pRotateKeys[iKey].dwTime = pFileRotateKey->dwTime;
                            pframeCur1->m_pRotateKeys[iKey].quatRotate.x = pFileRotateKey->x;
                            pframeCur1->m_pRotateKeys[iKey].quatRotate.y = pFileRotateKey->y;
                            pframeCur1->m_pRotateKeys[iKey].quatRotate.z = pFileRotateKey->z;
                            pframeCur1->m_pRotateKeys[iKey].quatRotate.w = pFileRotateKey->w;
                            
                            pFileRotateKey += 1;
                        }
                    }
                    else if (dwKeyType == 1)
                    {
                        if (pframeCur1->m_pScaleKeys != NULL)
                        {
                            hr = E_INVALIDARG;
                            goto e_Exit;
                        }
                        
                        pframeCur1->m_pScaleKeys = new SScaleKey[cKeys];
                        if (pframeCur1->m_pScaleKeys == NULL)
                        {
                            hr = E_OUTOFMEMORY;
                            goto e_Exit;
                        }
                        
                        pframeCur1->m_cScaleKeys = cKeys;
                        
                        pFileScaleKey =  (SScaleKeyXFile*)(pData + (sizeof(DWORD) * 2));
                        for (iKey = 0;iKey < cKeys; iKey++)
                        {
                            pframeCur1->m_pScaleKeys[iKey].dwTime = pFileScaleKey->dwTime;
                            pframeCur1->m_pScaleKeys[iKey].vScale = pFileScaleKey->vScale;
                            
                            pFileScaleKey += 1;
                        }
                    }
                    else if (dwKeyType == 2)
                    {
                        if (pframeCur1->m_pPositionKeys != NULL)
                        {
                            hr = E_INVALIDARG;
                            goto e_Exit;
                        }
                        
                        pframeCur1->m_pPositionKeys = new SPositionKey[cKeys];
                        if (pframeCur1->m_pPositionKeys == NULL)
                        {
                            hr = E_OUTOFMEMORY;
                            goto e_Exit;
                        }
                        
                        pframeCur1->m_cPositionKeys = cKeys;
                        
                        pFilePosKey =  (SPositionKeyXFile*)(pData + (sizeof(DWORD) * 2));
                        for (iKey = 0;iKey < cKeys; iKey++)
                        {
                            pframeCur1->m_pPositionKeys[iKey].dwTime = pFilePosKey->dwTime;
                            pframeCur1->m_pPositionKeys[iKey].vPos = pFilePosKey->vPos;
                            
                            pFilePosKey += 1;
                        }
                    }
                    else if (dwKeyType == 4)
                    {
                        if (pframeCur1->m_pMatrixKeys != NULL)
                        {
                            hr = E_INVALIDARG;
                            goto e_Exit;
                        }
                        
                        pframeCur1->m_pMatrixKeys = new SMatrixKey[cKeys];
                        if (pframeCur1->m_pMatrixKeys == NULL)
                        {
                            hr = E_OUTOFMEMORY;
                            goto e_Exit;
                        }
                        
                        pframeCur1->m_cMatrixKeys = cKeys;
                        
                        pFileMatrixKey =  (SMatrixKeyXFile*)(pData + (sizeof(DWORD) * 2));
                        for (iKey = 0;iKey < cKeys; iKey++)
                        {
                            pframeCur1->m_pMatrixKeys[iKey].dwTime = pFileMatrixKey->dwTime;
                            pframeCur1->m_pMatrixKeys[iKey].mat = pFileMatrixKey->mat;
                            
                            pFileMatrixKey += 1;
                        }
                    }
                    else
                    {
                        hr = E_INVALIDARG;
                        goto e_Exit;
                    }
                }
                
                GXRELEASE(pxofobjChild);
            }
        }
        
        GXRELEASE(pxofChild);
    }
    
e_Exit:
    GXRELEASE(pxofobjChild);
    GXRELEASE(pxofChild);
    GXRELEASE(pxofobjChildRef);
    return hr;
}

HRESULT CSkinnedMesh::LoadAnimationSet(LPDIRECTXFILEDATA pxofobjCur, 
									   SDrawElement *pde,
                                       DWORD options, 
									   DWORD fvf, 
									   LPDIRECT3DDEVICE8 pD3DDevice,
                                       SFrame *pframeParent)
{
//	//	FLOG( "CSkinnedMesh::LoadAnimationSet(LPDIRECTXFILEDATA pxofobjCur, SDrawElement *pde,DWORD options, DWORD fvf, LPDIRECT3DDEVICE8 pD3DDevice, SFrame *pframeParent)" );
    SFrame *pframeCur;
    const GUID *type;
    HRESULT hr = S_OK;
    LPDIRECTXFILEDATA pxofobjChild = NULL;
    LPDIRECTXFILEOBJECT pxofChild = NULL;
    DWORD cchName;
    
    pframeCur = new SFrame();
    if (pframeCur == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto e_Exit;
    }
    pframeCur->bAnimationFrame = true;
    
    pframeParent->AddFrame(pframeCur);
    
    hr = pxofobjCur->GetName(NULL, &cchName);
    if (FAILED(hr))
        goto e_Exit;
    
    if (cchName > 0)
    {
        pframeCur->szName = new char[cchName];
        if (pframeCur->szName == NULL)
        {
            hr = E_OUTOFMEMORY;
            goto e_Exit;
        }
        
        hr = pxofobjCur->GetName(pframeCur->szName, &cchName);
        if (FAILED(hr))
            goto e_Exit;
    }
   // Enumerate child objects.
    // Child object can be data, data reference or binary.
    // Use QueryInterface() to find what type of object a child is.
    while (SUCCEEDED(pxofobjCur->GetNextObject(&pxofChild)))
    {
        // Query the child for it's FileData
        hr = pxofChild->QueryInterface(IID_IDirectXFileData,
            (LPVOID *)&pxofobjChild);
        if (SUCCEEDED(hr))
        {
            hr = pxofobjChild->GetType(&type);
            if (FAILED(hr))
                goto e_Exit;
            
            if( TID_D3DRMAnimation == *type )
            {
                hr = LoadAnimation(pxofobjChild, pde, options, fvf, pD3DDevice, pframeCur);
                if (FAILED(hr))
                    goto e_Exit;
            }
            
            GXRELEASE(pxofobjChild);
        }
        
        GXRELEASE(pxofChild);
    }
    
e_Exit:
    GXRELEASE(pxofobjChild);
    GXRELEASE(pxofChild);
    return hr;
}
HRESULT CSkinnedMesh::UpdateFrames(SFrame *pframeCur, 
								   D3DXMATRIX &matCur)
{
//	//	FLOG( "CSkinnedMesh::UpdateFrames(SFrame *pframeCur, D3DXMATRIX &matCur)" );
    HRESULT hr = S_OK;
    pframeCur->matCombined = matCur;
    D3DXMatrixMultiply(&pframeCur->matCombined, &pframeCur->matRot, &matCur);
    D3DXMatrixMultiply(&pframeCur->matCombined, &pframeCur->matCombined, &pframeCur->matTrans );
    SFrame *pframeChild = pframeCur->pframeFirstChild;
    while (pframeChild != NULL)
    {
        hr = UpdateFrames(pframeChild, pframeCur->matCombined);
        if (FAILED(hr))
            return hr;

        pframeChild = pframeChild->pframeSibling;
    }
    return S_OK;
}


HRESULT  CSkinnedMesh::DeleteSelectedMesh()
{
	//	FLOG( "CSkinnedMesh::DeleteSelectedMesh()" );
	if (m_pdeSelected != NULL)
    {
        SDrawElement *pdeCur = m_pdeHead;
        SDrawElement *pdePrev = NULL;
        while ((pdeCur != NULL) && (pdeCur != m_pdeSelected))
        {
            pdePrev = pdeCur;
            pdeCur = pdeCur->pdeNext;
        }

        if (pdePrev == NULL)
        {
            m_pdeHead = m_pdeHead->pdeNext;
        }
        else
        {
            pdePrev->pdeNext = pdeCur->pdeNext;
        }

        m_pdeSelected->pdeNext = NULL;
        if (m_pdeHead == m_pdeSelected)
            m_pdeHead = NULL;
        delete m_pdeSelected;
        m_pdeSelected = NULL;
    }

    return S_OK;
}

void CSkinnedMesh::ReleaseDeviceDependentMeshes(SFrame* pframe)
{
//	//	FLOG( "CSkinnedMesh::ReleaseDeviceDependentMeshes(SFrame* pframe)" );
    if (pframe->pmcMesh != NULL)
    {
        for (SMeshContainer* pmcCurr = pframe->pmcMesh; pmcCurr != NULL; pmcCurr = pmcCurr->pmcNext)
        {
            if (pmcCurr->m_pSkinMesh != NULL)
            {
                GXRELEASE(pmcCurr->pMesh);
				pmcCurr->m_Method = NONE;
			}
/*			for(i=0;i<5;i++)
			{
				if(pmcCurr->pMeshes[i])
					GXRELEASE(pmcCurr->pMeshes[i]);
			}
*/        }
    }

    if (pframe->pframeFirstChild != NULL)
        ReleaseDeviceDependentMeshes(pframe->pframeFirstChild);

    if (pframe->pframeSibling != NULL)
        ReleaseDeviceDependentMeshes(pframe->pframeSibling);
}

// global func

HRESULT CalculateBoundingSphere(SDrawElement *pdeCur, D3DXVECTOR3 vObjScale)	// 2012-05-23 by isshin 맵툴 개선 오브젝트 스케일 적용
{
    HRESULT hr = S_OK;
    D3DXVECTOR3 vCenter(0,0,0);
    UINT cVertices = 0;
    float fRadiusSq = 0;
    D3DXMATRIXA16 matCur;
    
//    D3DXMatrixIdentity(&matCur);
//    hr = CalculateSum(pdeCur->pframeRoot, &matCur, &vCenter, &cVertices);
//    if (FAILED(hr))
//        goto e_Exit;
    
//    if (cVertices > 0)
//    {
//        vCenter /= (float)cVertices;
        
        D3DXMatrixIdentity(&matCur);
		
		// 2012-05-23 by isshin 맵툴 개선 오브젝트 스케일 적용
		D3DXMATRIX objscale;
		D3DXMatrixIdentity(&objscale);
		D3DXMatrixScaling(&objscale, vObjScale.x, vObjScale.y, vObjScale.z);		
		D3DXMatrixMultiply(&matCur,  &objscale, &matCur);
		// end 2012-05-23 by isshin 맵툴 개선 오브젝트 스케일 적용

        hr = CalculateRadius(pdeCur->pframeRoot, &matCur, &vCenter, &fRadiusSq);
        if (FAILED(hr))
            goto e_Exit;
//      }
    
    pdeCur->fRadius = (float)sqrt((double)fRadiusSq);;
    pdeCur->vCenter = vCenter;
e_Exit:
    return hr;
}

HRESULT CalculateSum(SFrame *pframe, D3DXMATRIX *pmatCur, D3DXVECTOR3 *pvCenter, 
                     UINT *pcVertices)
{
    HRESULT hr = S_OK;
    PBYTE pbPoints = NULL;
    UINT cVerticesLocal = 0;
    PBYTE pbCur;
    D3DXVECTOR3 *pvCur;
    D3DXVECTOR3 vTransformedCur;
    UINT iPoint;
    SMeshContainer *pmcCur;
    SFrame *pframeCur;
    UINT cVertices;
    D3DXMATRIXA16 matLocal;
    
    D3DXMatrixMultiply(&matLocal, &pframe->matRot, pmatCur);
    
    pmcCur = pframe->pmcMesh;
    while (pmcCur != NULL)
    {
        DWORD fvfsize = D3DXGetFVFVertexSize(pmcCur->pMesh->GetFVF());
        
        cVertices = pmcCur->pMesh->GetNumVertices();
        
        hr = pmcCur->pMesh->LockVertexBuffer(0, &pbPoints);
        if (FAILED(hr))
            goto e_Exit;
        
        for( iPoint=0, pbCur = pbPoints; iPoint < cVertices; iPoint++, pbCur += fvfsize)
        {
            pvCur = (D3DXVECTOR3*)pbCur;
            
            if ((pvCur->x != 0.0) || (pvCur->y != 0.0) || (pvCur->z != 0.0))
            {
                cVerticesLocal++;
                
                D3DXVec3TransformCoord(&vTransformedCur, pvCur, &matLocal);
                
                pvCenter->x += vTransformedCur.x;
                pvCenter->y += vTransformedCur.y;
                pvCenter->z += vTransformedCur.z;
            }
        }
        
        
        pmcCur->pMesh->UnlockVertexBuffer();
        pbPoints = NULL;
        
        pmcCur = pmcCur->pmcNext;
    }
    
    *pcVertices += cVerticesLocal;
    
    pframeCur = pframe->pframeFirstChild;
    while (pframeCur != NULL)
    {
        hr = CalculateSum(pframeCur, &matLocal, pvCenter, pcVertices);
        if (FAILED(hr))
            goto e_Exit;
        
        pframeCur = pframeCur->pframeSibling;
    }
    
e_Exit:
    if (pbPoints != NULL)
    {
        pmcCur->pMesh->UnlockVertexBuffer();
    }
    
    return hr;
}




HRESULT CalculateRadius(SFrame *pframe, D3DXMATRIX *pmatCur, D3DXVECTOR3 *pvCenter, 
                        float *pfRadiusSq)
{
    HRESULT hr = S_OK;
    PBYTE pbPoints = NULL;
    PBYTE pbCur;
    D3DXVECTOR3 *pvCur;
    D3DXVECTOR3 vDist;;
    UINT iPoint;
    UINT cVertices;
    SMeshContainer *pmcCur;
    SFrame *pframeCur;
    float fRadiusLocalSq;
    float fDistSq;
    D3DXMATRIXA16 matLocal;
    
    D3DXMatrixMultiply(&matLocal, &pframe->matRot, pmatCur);
    
    pmcCur = pframe->pmcMesh;
    fRadiusLocalSq = *pfRadiusSq;
    while (pmcCur != NULL)
    {
        DWORD fvfsize = D3DXGetFVFVertexSize(pmcCur->pMesh->GetFVF());
        
        cVertices = pmcCur->pMesh->GetNumVertices();
        
        hr = pmcCur->pMesh->LockVertexBuffer(0, &pbPoints);
        if (FAILED(hr))
            goto e_Exit;
        
        for( iPoint=0, pbCur = pbPoints; iPoint < cVertices; iPoint++, pbCur += fvfsize )
        {
            pvCur = (D3DXVECTOR3*)pbCur;
            
            if ((pvCur->x == 0.0) && (pvCur->y == 0.0) && (pvCur->z == 0.0))
                continue;
            
            D3DXVec3TransformCoord(&vDist, pvCur, &matLocal);
            
            vDist -= *pvCenter;
            
            fDistSq = D3DXVec3LengthSq(&vDist);
            
            if( fDistSq > fRadiusLocalSq )
                fRadiusLocalSq = fDistSq;
        }
        
        
        pmcCur->pMesh->UnlockVertexBuffer();
        pbPoints = NULL;
        
        pmcCur = pmcCur->pmcNext;
    }
    
    *pfRadiusSq = fRadiusLocalSq;
    
    pframeCur = pframe->pframeFirstChild;
    while (pframeCur != NULL)
    {
        hr = CalculateRadius(pframeCur, &matLocal, pvCenter, pfRadiusSq);
        if (FAILED(hr))
            goto e_Exit;
        
        pframeCur = pframeCur->pframeSibling;
    }
    
e_Exit:
    if (pbPoints != NULL)
    {
        pmcCur->pMesh->UnlockVertexBuffer();
    }
    
    return hr;
}

