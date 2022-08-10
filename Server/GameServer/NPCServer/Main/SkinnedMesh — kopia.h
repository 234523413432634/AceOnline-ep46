// SkinnedMesh.h: interface for the CSkinnedMesh class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKINNEDMESH_H__75E6AD0E_1348_45B4_8A86_614B206812B1__INCLUDED_)
#define AFX_SKINNEDMESH_H__75E6AD0E_1348_45B4_8A86_614B206812B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AtumNode.h"
#include "GameDataLast.h"

#define GXRELEASE(_p) do { if ((_p) != NULL) {(_p)->Release(); (_p) = NULL;} } while (0)

enum METHOD {
    D3DNONINDEXED,
    D3DINDEXED,
    SOFTWARE,
    D3DINDEXEDVS,
    NONE
};

#define OBJECT_ENCODESTRING "dlwlsgk"

struct SMeshContainer
{
    ID3DXMesh *pMesh;
//	LPD3DXMESH pMeshes[5];

	D3DMATERIAL8 *rgMaterials;
    LPDIRECT3DTEXTURE8 *pTextures;
    DWORD cpattr;
    DWORD cMaterials;
    DWORD iAttrSplit;

    SMeshContainer *pmcNext;

    char *szName;

    // Skin info
    LPD3DXSKINMESH m_pSkinMesh;
    D3DXATTRIBUTERANGE *m_pAttrTable;
    D3DXMATRIX** m_pBoneMatrix;
    LPD3DXBUFFER m_pBoneNamesBuf;
    LPD3DXBUFFER m_pBoneOffsetBuf;
    D3DXMATRIX* m_pBoneOffsetMat;
    DWORD* m_rgiAdjacency;
    DWORD m_numBoneComb;
    DWORD m_maxFaceInfl;
    LPD3DXBUFFER m_pBoneCombinationBuf;
    METHOD  m_Method;
    DWORD m_paletteSize;
    BOOL m_bUseSW;

	SMeshContainer()
		:pMesh(NULL),
            rgMaterials(NULL),
            pTextures(NULL),
            cpattr(0),
            iAttrSplit(0),
            cMaterials(0),
            pmcNext(NULL),
            szName(NULL),
            m_pSkinMesh(NULL),
            m_pAttrTable(NULL),
            m_pBoneMatrix(NULL),
            m_pBoneNamesBuf(NULL),
            m_pBoneOffsetBuf(NULL),
            m_pBoneOffsetMat(NULL),
            m_rgiAdjacency(NULL),
            m_numBoneComb(0),
            m_maxFaceInfl(0),
            m_pBoneCombinationBuf(NULL),
            m_Method(NONE),
            m_paletteSize(0),
            m_bUseSW(FALSE)
	{
	}

	~SMeshContainer()
	{
        delete []rgMaterials;
		rgMaterials = NULL;

        if(pTextures)
        {
            for (DWORD i = 0; i < cMaterials; ++i)
            {
                GXRELEASE(pTextures[i]);
            }
			delete []pTextures;//by dhkwon
			pTextures = NULL;
        }

		GXRELEASE(pMesh);
//		if(pMeshes)
//		{
//			for(DWORD i=0;i<5;i++)
//				GXRELEASE(pMeshes[i]);
//		}
        GXRELEASE(m_pSkinMesh);
        GXRELEASE(m_pBoneNamesBuf);
        GXRELEASE(m_pBoneOffsetBuf);
        GXRELEASE(m_pBoneCombinationBuf);

        delete[] m_pBoneMatrix;
		m_pBoneMatrix = NULL;

        delete[] m_pAttrTable;
		m_pAttrTable = NULL;

        delete [] szName;
		szName = NULL;

        delete[] m_rgiAdjacency;
		m_rgiAdjacency = NULL;

        delete pmcNext;
		pmcNext = NULL;
	}
};

// X File formation rotate key
struct SRotateKeyXFile
{
	DWORD			dwTime;
	DWORD			dwFloats;	
	float			w;
	float			x;
	float			y;
	float			z;
};

struct SScaleKeyXFile
{
	DWORD	dwTime;
	DWORD	dwFloats;	
	D3DXVECTOR3	vScale;	
};


struct SPositionKeyXFile
{
	DWORD	dwTime;
	DWORD	dwFloats;	
	D3DXVECTOR3	vPos;	
};

struct SMatrixKeyXFile
{
	DWORD	dwTime;
	DWORD	dwFloats;	
	D3DXMATRIX	mat;	
};

// in memory versions

struct SRotateKey
{
	DWORD			dwTime;
	D3DXQUATERNION	quatRotate;	
};

struct SPositionKey
{
	DWORD	dwTime;
	D3DXVECTOR3	vPos;	
};

struct SScaleKey
{
	DWORD	dwTime;
	D3DXVECTOR3	vScale;	
};

struct SMatrixKey
{
	DWORD	dwTime;
	D3DXMATRIXA16	mat;	
};

struct SFrame
{
//	D3DXVECTOR3 m_vCurrentPos;
    SMeshContainer *pmcMesh;
    D3DXMATRIXA16 matRot;
    D3DXMATRIXA16 matTrans;
    D3DXMATRIXA16 matRotOrig;
    D3DXMATRIXA16 matCombined;

    // animation information
    SPositionKey *m_pPositionKeys;
    UINT m_cPositionKeys;
    SRotateKey *m_pRotateKeys;
    UINT m_cRotateKeys;
    SScaleKey *m_pScaleKeys;
    UINT m_cScaleKeys;
    SMatrixKey *m_pMatrixKeys;
    UINT m_cMatrixKeys;

    SFrame *pframeAnimNext;
    SFrame *pframeToAnimate;

    SFrame *pframeSibling;
    SFrame *pframeFirstChild;

    bool bAnimationFrame;
    char *szName;

    SFrame()
        :
            pmcMesh(NULL),
            m_pPositionKeys(NULL),
            m_cPositionKeys(0),
            m_pScaleKeys(NULL),
            m_cScaleKeys(0),
            m_pRotateKeys(NULL),
            m_cRotateKeys(0),
            m_pMatrixKeys(NULL),
            m_cMatrixKeys(0),
            pframeAnimNext(NULL),
            pframeToAnimate(NULL),
            pframeSibling(NULL),
            pframeFirstChild(NULL),
            bAnimationFrame(false),
            szName(NULL)	
//			m_vCurrentPos(0,0,0)
    {
        D3DXMatrixIdentity(&matRot);
        D3DXMatrixIdentity(&matRotOrig);
        D3DXMatrixIdentity(&matTrans);
    }

    ~SFrame()
    {
        delete []szName;
		szName = NULL;
        delete pmcMesh;        
		pmcMesh = NULL;
        delete pframeFirstChild;
		pframeFirstChild = NULL;
        delete pframeSibling;
		pframeSibling = NULL;

        delete []m_pPositionKeys;
		m_pPositionKeys = NULL;
        delete []m_pRotateKeys;
		m_pRotateKeys = NULL;
        delete []m_pScaleKeys;
		m_pScaleKeys = NULL;
        delete []m_pMatrixKeys;
		m_pMatrixKeys = NULL;

        // do NOT delete pframeAnimNext
        // do NOT delete pframeToAnimate
    }

    void SetTime(float fTime);

    SFrame *FindFrame(char *szFrame)
    {
        SFrame *pframe;

        if ((szName != NULL) && (strcmp(szName, szFrame) == 0))
            return this;

        if (pframeFirstChild != NULL)
        {
            pframe = pframeFirstChild->FindFrame(szFrame);
            if (pframe != NULL)
                return pframe;
        }

        if (pframeSibling != NULL)
        {
            pframe = pframeSibling->FindFrame(szFrame);
            if (pframe != NULL)
                return pframe;
        }

        return NULL;
    }

    void ResetMatrix()
    {
        matRot = matRotOrig;
        D3DXMatrixIdentity(&matTrans);        

        if (pframeFirstChild != NULL)
        {
            pframeFirstChild->ResetMatrix();
        }

        if (pframeSibling != NULL)
        {
            pframeSibling->ResetMatrix();
        }
    }

    void AddFrame(SFrame *pframe)
    {
        if (pframeFirstChild == NULL)
        {
            pframeFirstChild = pframe;
        }
        else
        {
            pframe->pframeSibling = pframeFirstChild->pframeSibling;
            pframeFirstChild->pframeSibling = pframe;
        }
    }

    void AddMesh(SMeshContainer *pmc)
    {
        pmc->pmcNext = pmcMesh;
        pmcMesh = pmc;
    }
};

struct SDrawElement
{
    SFrame *pframeRoot;

    D3DXVECTOR3 vCenter;
    float fRadius;

	// name of element for selection purposes
	char *szName;

    // animation list
    SFrame *pframeAnimHead;

	// next element in list
	SDrawElement *pdeNext;

    float fCurTime;
    float fMaxTime;

	SDrawElement()
		:vCenter(0.0,0.0,0.0),
			fRadius(1.0),
			szName(NULL),
            pframeRoot(NULL),
            pframeAnimHead(NULL),
			pdeNext(NULL)
	{
	}

	~SDrawElement()
	{
        delete pframeRoot;
		pframeRoot = NULL;
		delete pdeNext;
		pdeNext = NULL;
        delete [] szName;
		szName = NULL;

        // do NOT delete pframeAnimHead;
	}

    void AddAnimationFrame(SFrame *pframeAnim)
    {
        pframeAnim->pframeAnimNext = pframeAnimHead;
        pframeAnimHead = pframeAnim;
    }

    SFrame *FindFrame(char *szName)
    {
        if (pframeRoot == NULL)
            return NULL;
        else
            return pframeRoot->FindFrame(szName);
    }
};

#define MAX_INTERSECTIONS 16
struct D3DVERTEX
{
    D3DXVECTOR3 p;
    D3DXVECTOR3 n;
    FLOAT       tu, tv;
};
struct INTERSECTION
{
    DWORD dwFace;                 // mesh face that was intersected
    FLOAT fBary1, fBary2;         // barycentric coords of intersection
    FLOAT fDist;                  // distance from ray origin to intersection
    FLOAT tu, tv;                 // texture coords of intersection
};

class CSkinnedMesh;
typedef map<DWORD, CSkinnedMesh*>		mapSkinnedMeshPtr;


typedef struct _COLLISION_RESULT
{
	int nCollType;
	float fDist;
	D3DXVECTOR3 vNormalVector;
} COLLISION_RESULT;


class CSkinnedMesh : public CAtumNode  
{
public:
	CSkinnedMesh();
	CSkinnedMesh(BOOL bProgressiveMesh);

	float GetRaidus() { return m_fRadius; }

	virtual ~CSkinnedMesh();
	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual void Tick(float fElapsedTime);

	COLLISION_RESULT CheckCollDistDetail(SMeshContainer *pmcMesh,D3DXMATRIX matThis, D3DXMATRIX mat);
	COLLISION_RESULT CheckCollDist(SFrame *pframeCur,D3DXMATRIX mat);
	COLLISION_RESULT CheckCollision(D3DXMATRIX mat);

	void SetMeshRenderState(SMeshContainer *pmcMesh);

	HRESULT LoadMeshHierarchy(char* szFileName);
	HRESULT LoadMeshHierarchyFromMem(CGameData* pGameData, D3DXVECTOR3 vObjScale = D3DXVECTOR3(1.0f, 1.0f, 1.0f));	// 2012-05-23 by isshin 맵툴 개선 오브젝트 스케일 적용
	void SetWorldMatrix(D3DXMATRIX mat){ m_mWorld = mat; }
	//HRESULT LoadTexture(char* szfileName, BYTE tex_num);
	//void AnotherTexture(BYTE tex_num) { m_bTextureNum = tex_num; }
	//void BaseTexture() { m_bTextureNum = 0; }
	//LPDIRECT3DTEXTURE8 SetTexture(LPDIRECT3DTEXTURE8 pTexture, BYTE tex_num);// by dhkwon, 030917

protected:
	HRESULT LoadFrames(LPDIRECTXFILEDATA pxofobjCur, SDrawElement *pde,
                                      DWORD options, DWORD fvf, LPDIRECT3DDEVICE8 pD3DDevice,
                                      SFrame *pframeParent);
	HRESULT LoadMesh(LPDIRECTXFILEDATA pxofobjCur,DWORD options, DWORD fvf, LPDIRECT3DDEVICE8 pD3DDevice,
                                    SFrame *pframeParent);
	HRESULT FindBones(SFrame *pframeCur, SDrawElement *pde);
	HRESULT DeleteSelectedMesh();
	HRESULT LoadAnimationSet(LPDIRECTXFILEDATA pxofobjCur, SDrawElement *pde,
                                            DWORD options, DWORD fvf, LPDIRECT3DDEVICE8 pD3DDevice,
                                            SFrame *pframeParent);
	HRESULT LoadAnimation(LPDIRECTXFILEDATA pxofobjCur, SDrawElement *pde,
                                         DWORD options, DWORD fvf, LPDIRECT3DDEVICE8 pD3DDevice,
                                         SFrame *pframeParent);
    HRESULT GenerateMesh(SMeshContainer* pmcMesh);
    HRESULT UpdateFrames(SFrame *pframeCur, D3DXMATRIX &matCur);
    HRESULT DrawMeshContainer(SMeshContainer *pmcMesh);
	HRESULT SetProjectionMatrix();
	void ReleaseDeviceDependentMeshes(SFrame* pframe);
protected:
    SDrawElement *			m_pdeSelected;
    SFrame *				m_pframeSelected;

    DWORD					m_dwFVF;
    LPD3DXMATRIXA16			m_pBoneMatrices;
    DWORD					m_dwIndexedVertexShader[4];
    DWORD					m_maxBones;
    METHOD					m_method;
	D3DCAPS8				m_d3dCaps;
	D3DXMATRIX				m_mWorld;

	DataHeader*				m_pDataHeader;
public:
	LPDIRECT3DDEVICE8		m_pd3dDevice;  
	float					m_fRadius;
	D3DXVECTOR3				m_vCenter;
	BYTE					m_bTextureNum;
	CGameData *				m_pGameData;
	SMeshContainer *		m_pmcSelectedMesh;
	SDrawElement *			m_pdeHead;
	LPDIRECT3DTEXTURE8	*	m_pTexture;
	INT						m_nRenderCount;						// 렌더링이 사용된 횟수(일정시간동안 사용빈도수가 없으면 메모리에서 내림)
	BOOL					m_bMaterial;						// Material 을 적용할것이냐?
	D3DMATERIAL8			m_material;							// Material
	BOOL					m_bCheckBlend;						// 블렌딩을 체크할것이냐?
	FLOAT					m_fCollDist;						// 충돌 지점 거리
	BYTE					m_bProgressiveMesh;					// 메쉬의 폴리곤 수를를 줄일것이냐?
	BYTE					m_bTotalTextureNum;
	BOOL					m_bMultiTexture;
	LPDIRECT3DTEXTURE8		m_pOrderTexture;					// 강제로 맵핑을하여 그릴때
	INTERSECTION			m_Intersection;						// 충돌 처리용 
};

HRESULT CalculateRadius(SFrame *pframe, D3DXMATRIX *pmatCur, D3DXVECTOR3 *pvCenter, float *pfRadiusSq);
HRESULT CalculateSum(SFrame *pframe, D3DXMATRIX *pmatCur, D3DXVECTOR3 *pvCenter, UINT *pcVertices);
HRESULT CalculateBoundingSphere(SDrawElement *pdeCur, D3DXVECTOR3 vObjScale = D3DXVECTOR3(1.0f, 1.0f, 1.0f));	// 2012-05-23 by isshin 맵툴 개선 오브젝트 스케일 적용

#endif // !defined(AFX_SKINNEDMESH_H__75E6AD0E_1348_45B4_8A86_614B206812B1__INCLUDED_)
