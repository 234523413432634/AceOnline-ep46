// TraceAni.h: interface for the CTraceAni class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRACEANI_H__5E5475D8_C91D_45F0_99AB_6C3DFA865C98__INCLUDED_)
#define AFX_TRACEANI_H__5E5475D8_C91D_45F0_99AB_6C3DFA865C98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "effect.h"

/*
struct TRACEANI_INDEX
{
	WORD _0,_1,_2,_3;
};
*/
struct TraceData : public Effect
{
	char		m_strName[20];				//�̸�
	UINT		m_nNumberOfTrace;			// ������ �ܻ�ڽ��� ���� 
	float		m_fCreateTick;				//���� ����(�������� ������ �ܻ��� �����ȴ�.)
	//D3DXVECTOR3 m_vCreatePos;				//���� ��ǥ(�����ǥ) : CEffectInfo�� �Ѿ
	float		m_fHalfSize;				// �ܻ��� ���� ������ ����
	UINT		m_nTextureNumber;			// �ؽ��� ����
	float		m_fTextureAnimationTime;	// �ؽ��� �ִϸ��̼� Ÿ��
	char		m_strTextureName[20][20];		// �ؽ��Ĵ� �ִ� 20���� ���� �ִ�.
	int			m_nNumberOfCross;				// ũ�ν� ����(1 ~ 4)

	BOOL		m_bAlphaBlendEnable;
	DWORD		m_dwSrcBlend;
	DWORD		m_dwDestBlend;
	DWORD		m_nTextureRenderState;
	BOOL		m_bZbufferEnable;
	BOOL		m_bZWriteEnable;
	
};

class CTraceAni;
class CEffectPlane : public Effect
{
	friend CTraceAni;
public:
	CEffectPlane(CTraceAni*	pParent, int nIBIndex);
	~CEffectPlane();

//	D3DXVECTOR3 &GetReferencePos() { return m_vPos; }
//	TRACEANI_INDEX &GetReferenceTraceAniIndex() { return m_TraceAniIndex; }

	BOOL Tick(float fElapsedTime);
	void Render();
	HRESULT InitDeviceObjects();
	HRESULT RestoreDeviceObjects();
	HRESULT InvalidateDeviceObjects();
	HRESULT DeleteDeviceObjects();
	VOID SetFirstIndex(BOOL bSet);
	void SetEndIndex();
	D3DXVECTOR3 GetPos() { return m_vPos; }

public:
	CTraceAni				*m_pParent;				// �θ� ��ü
protected:
	D3DXVECTOR3				m_vPos ;				// ������ǥ�� ����� ������ǥ(ZEnable�ÿ� �Ÿ���꿡 ���), parent�� m_vPos����
	int						m_nIBIndex;				// 0 ~ 15 ���� ��
	LPDIRECT3DVERTEXBUFFER9 m_pVB;					// ���ؽ�����(4*32)
	BOOL					m_bIsFirstIndex;
	BOOL					m_bZbufferEnable;

};

class CEffectInfo;
class CEffectPlane;
class CTraceAni : public TraceData
{
public:
	float					m_fCurrentCreateTick;		// ������� �ð�
	int						m_nCurrentNumberOfTrace;	// ������� ������ �ܻ󰳼�(MAX=m_nNumberOfTrace)
	int						m_nCurrentTextureNumber;	// ���� ���õ� �ؽ��� ��ȣ
//	LPDIRECT3DVERTEXBUFFER8 m_pVB;					// ���ؽ�����
	float					m_fCurrentTextureTick;		// �ؽ��� �ִϸ��̼� ���ð�
	BOOL					m_bCreateTrace;				// �� ���� FALSE�̸� ���̻� �ܻ��� ������ �ʴ´�.
	CEffectInfo				*m_pParent;					// ����Ʈ ���� ����
	CEffectPlane			**m_pEffectPlane;		// CEffectPlane ����(16 X m_nNumberOfTrace)
//	LPDIRECT3DINDEXBUFFER8	*m_pIB;					// �ε��� ����, 16 X m_nNumberOfTrace, CEffectPlane�� 1:1��ġ
	int						m_nCurrentCreateIndex;	// ���� ������ VB,Plane �ε���(0 ~ m_nNumberOfTrace)
	int						m_nCurrentRenderIndex;	// ���� �������� ���۵Ǵ� �ε���
	int						m_nCurrentDeleteIndex;	// ������ ��� �������� �ε���
	D3DXVECTOR3				m_vOldPos;
	D3DXVECTOR3				m_vCurrentPos;
	BOOL					m_bRestored;

	float					m_fRadius;
public:
	CTraceAni();
	~CTraceAni();
	BOOL Tick(float fElapsedTime);
	void Render();
	HRESULT InitDeviceObjects();
	HRESULT RestoreDeviceObjects();
	HRESULT InvalidateDeviceObjects();
	HRESULT DeleteDeviceObjects();

	void TraceEnable(BOOL bEnable) { m_bCreateTrace = bEnable; }
	void SetTexture(char* strTexture) {};
	void SetTexture(LPDIRECT3DTEXTURE9 pTexture) {};
/*
public:
	float					m_fCurrentCreateTick;		// ������� �ð�
	int						m_nCurrentNumberOfTrace;	// ������� ������ �ܻ󰳼�(MAX=m_nNumberOfTrace)
	int						m_nCurrentTextureNumber;	// ���� ���õ� �ؽ��� ��ȣ
	D3DXVECTOR3				m_vCurrentPos ;				// ������
	LPDIRECT3DVERTEXBUFFER8 m_pVBTrace[2];				// ���ؽ�����
	float					m_fCurrentTextureTick;		// �ؽ��� �ִϸ��̼� ���ð�
	BOOL					m_bCreateTrace;				// �� ���� FALSE�̸� ���̻� �ܻ��� ������ �ʴ´�.
//	CTraceAniRender*		m_pRenderer;				// ������
	CEffectInfo*			m_pParent;					// ����Ʈ ���� ����
	DWORD					m_dwStateBlock;

	BOOL					m_bRestored;
public:
	CTraceAni();
	~CTraceAni();
	BOOL Tick(float fElapsedTime);
	void Render();
	HRESULT InitDeviceObjects();
	HRESULT RestoreDeviceObjects();
	HRESULT InvalidateDeviceObjects();
	HRESULT DeleteDeviceObjects();

	void TraceEnable(BOOL bEnable) { m_bCreateTrace = bEnable; }
	void SetTexture(char* strTexture) {};
	void SetTexture(LPDIRECT3DTEXTURE8 pTexture) {};
*/
};

#endif // !defined(AFX_TRACEANI_H__5E5475D8_C91D_45F0_99AB_6C3DFA865C98__INCLUDED_)
