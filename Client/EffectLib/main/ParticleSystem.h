// ParticleSystem.h: interface for the CParticleSystem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARTICLESYSTEM_H__96E094F7_D630_44BD_A363_2C624A4665ED__INCLUDED_)
#define AFX_PARTICLESYSTEM_H__96E094F7_D630_44BD_A363_2C624A4665ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//inline DWORD FtoDW( FLOAT f ) { return *((DWORD*)&f); }
/*
struct PARTICLE_VERTEX
{
    D3DXVECTOR3 p; // The position.
	float		s; // The PointSize
    D3DCOLOR    c; // The color.
};
struct SPRITE_VERTEX
{
    D3DXVECTOR3 p; // The position.
    D3DCOLOR    c; // The color.
	float		tu,tv;
};

#define D3DFVF_PARTICLE_VERTEX (D3DFVF_XYZ|D3DFVF_PSIZE|D3DFVF_DIFFUSE)
#define D3DFVF_SPRITE_VERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX1)

enum { PARTICLE_TYPE, SPRITE_TYPE };
enum { EMITTER_POINT, EMITTER_CIRCLE, EMITTER_SPHERE, EMITTER_AREA };
enum { TEXTURE_SIZE_RANDOM, TEXTURE_SIZE_STEP, TEXTURE_SIZE_FIX };
enum { TEXTURE_ANIMATION_NONE=-1, TEXTURE_ANIMATION_RANDOM, TEXTURE_ANIMATION_STEP };

struct ComParticle
{
	template<typename T>
		bool operator()(const T *pPtr1, const T *pPtr2)
	{
		if(pPtr1->m_fDistance > pPtr2->m_fDistance)
		{
			return true;
		}
		return false;
	}
};
*/
class CEffectInfo;
class CObjectAni;
class CTraceAni;
class CParticleSystem;
class CParticle : public Effect
{
public:
	CParticle(int nParticleType);
	~CParticle();

	HRESULT InitDeviceObjects();
	HRESULT RestoreDeviceObjects();
	HRESULT InvalidateDeviceObjects();
	HRESULT DeleteDeviceObjects();
	BOOL Tick(float fElapsedTime);

	int			m_nParticleType;// ��ƼŬ ����(PARTICLE, SPRITE)
	float		m_fSize;		// ũ��
	float		m_fLifeTime;	// ��ƼŬ�� ������ Ÿ��
	float		m_fCurrentLifeTime;	// ���� ��ƼŬ�� ������ Ÿ��

	D3DXCOLOR	m_cColor;		// ��
	D3DXCOLOR	m_cColorStep;	// �� ��ȭ��
	D3DXVECTOR3	m_vPos;			// ��ġ
	D3DXVECTOR3 m_vVel;			// ��ġ ��ȭ ���ӵ�

	D3DXVECTOR3 m_vDir;			// ��ġ ��ȭ �ӵ�
//	D3DXVECTOR3 m_vArea;		// ���� ��ǥ(2)
	BOOL		m_bCreateRandom;// �������� �����ϰ� ������ ��� TRUE
	float		m_fCircleForce;	// ���ɷ�
//	float		m_fCreateDensity;// ���� �е�(���ӵ��� ���� �ִ밢)
//	float		m_fEmitRadius;	// �߻�Ǵ� ���� 
	float		m_fRotateAngle;	// ȸ�� �ӵ�
	float		m_fTextureAnimationTime;// �ؽ��� �ִϸ��̼� �ð�
//	int			m_nEmitterType;	// �߻�� Ÿ��
	int			m_nTextureAnimationType;// �ؽ��� �ִϸ��̼� Ÿ��(����,����,����)
	int			m_nTextureType;	// �ؽ��� Ÿ��

	float		m_fTextureSizeVel;	// �ؽ��İ� ��ȭ�ϴ� �ӵ�
	float		m_fTextureStartSize;// �ؽ����� ���� ������
	float		m_fTextureSizeMax;	// �ؽ��� �ִ� ������
	float		m_fTextureSizeMin;	// �ؽ��� �ּ� ������
	int			m_nTextureSizeChangeType;// �ؽ��� ������ ��ȭ Ÿ��
	float		m_fCurrentTextureAnimationTime;// ���� �ؽ��� �ִϸ��̼� �ð�
	int			m_nTextureNumber;

	float		m_fGravity;		// �߷�

	int			m_nPersistence;
//	float		m_fDistance;
	float		m_fColorChangeStartTime;

	float		m_fCurrentRotateAngle;
	float		m_fCurrentRotateTime;

	D3DXVECTOR3	m_vObjTarget;
	D3DXVECTOR3	m_vObjUp;
//	LPDIRECT3DVERTEXBUFFER8	m_pVBParticle;
	D3DXVECTOR3 m_vStartPos;
	D3DXMATRIX	m_mOldParentMatrix;
	CParticleSystem* m_pParent;
	// object particle
	CObjectAni*	m_pObjectAni;
	CTraceAni*	m_pTraceAni;
	float		m_fCullRadius;
};

struct ParticleData
{
//	DWORD	m_dwStateBlock;		// ������ ���� ��
	char	m_strName[20];		// ��ƼŬ �̸�
	BOOL	m_bLoop;			// ������ ���� TRUE
	float	m_fDelayTime;		// �����ÿ� ��ٸ��� �ð�
	float	m_fCurrentDelayTime;// ���� �罺 �ð�
	DWORD	m_dwDestBlend;		// DEST���ĺ��� ��
	DWORD	m_dwSrcBlend;		// SOURCE���ĺ��� ��
	int		m_nEmitMass;		// �ѹ��� �߻�Ǵ� ��
	float	m_fEmitTime;		// ��ƼŬ�� �߻��ϴ� ��
	float	m_fCurrentEmitTime;	// ���� �߻���� �ð�(���� ���� ����ϱ� ���� ���)
	float	m_fGravity;			// �߷�
//	float	m_fLifeTime;		
	float	m_fEmitLifeTime;	// �߻�ý����� LifeTime
	float	m_fCurrentEmitLifeTime;// �߻�ý����� ���� LifeTime;
	float	m_fParticleLifeTime;// ��ƼŬ�� LifeTime
	D3DXCOLOR m_cStartColor;	// ��ƼŬ�� ���� �÷���
	D3DXCOLOR m_cColorVel;		// ��ƼŬ�� �÷� ��ȭ��
	D3DXVECTOR3 m_vPos;			// ���� ��ǥ
	D3DXVECTOR3 m_vVel;			// ���ӵ�
	float	m_fTextureSizeVel;	// �ؽ��İ� ��ȭ�ϴ� �ӵ�
	float	m_fTextureStartSize;// �ؽ����� ���� ������
	float	m_fTextureSizeMax;	// �ؽ��� �ִ� ������
	float	m_fTextureSizeMin;	// �ؽ��� �ּ� ������
	float	m_fTick;			// ��ƼŬ�� ��� ��
	int		m_nTextureSizeChangeType;// �ؽ��� ������ ��ȭ Ÿ��
	float	m_fCurrentTick;		// ��ƼŬ�� ��� ���� ����ϱ� ���� ���

	D3DXVECTOR3 m_vDir;			// ��ƼŬ ���� ����
	D3DXVECTOR3 m_vArea;		// ���� ����
	BOOL	m_bCreateRandom;	// ���� �������� �����ϰ� �����ɶ� TRUE
	float	m_fCircleForce;		// ���ɷ�(����)
	float	m_fCreateDensity;	// �������� �е�(�߻�Ǵ� ������ ���ӵ��� �������� ������)
	float	m_fEmitRadius;		// ������ ���̳� ���� �����ɶ� ������
	float	m_fRotateAngle;		// ����(ȸ��)�� ��� ȸ����
	float	m_fTextureAnimationTime;// �ؽ��� �ִϸ��̼� �ð�
	int		m_nEmitterType;		// �߻���� Ÿ��(��, ��,��, ����)
	int		m_nTextureAnimationType;// �ؽ��� �ִϸ��̼� Ÿ��(����, ����)
	int		m_nParticleType;	// ��ƼŬ Ÿ��(��ƼŬ, ��������Ʈ)
	float	m_fEmitAngle;		// Circle������ ��ƼŬ�� �ѹ��� ������ ��� ȸ����
	int		m_nTextureNumber;	// �ؽ��� ����
	char	m_strTextureName[20][20];// �ؽ��� �̸�, 20�� �̻��� ���� ����.!
	int		m_nPersistence;
	BOOL	m_bZbufferEnable;
	float	m_fColorChangeStartTime;
//	BOOL	m_bColorLoop;
	int		m_nColorLoop;

	int		m_nObjCreateTargetType;
	int		m_nObjCreateUpType;
	int		m_nObjMoveTargetType;
	BOOL	m_bZWriteEnable;
	
};

class CParticleSystem  : public ParticleData
{
public:
	CParticleSystem();
	~CParticleSystem();
	
	BOOL Tick(float fElapsedTime);
	void Render();
	HRESULT InitDeviceObjects();
	HRESULT RestoreDeviceObjects();
	HRESULT InvalidateDeviceObjects();
	HRESULT DeleteDeviceObjects();
	void EmitterStop() { m_fCurrentEmitLifeTime = 0; }
	void SetTexture(char* strTexture, int index = 0);// by dhkwon, 030917

	DWORD	m_dwStateBlock;		// ������ ���� ��

	vector<Effect*>			m_vecParticle;

	CEffectInfo*				m_pParent;
	
	float		m_fRadius;

};
#endif // !defined(AFX_PARTICLESYSTEM_H__96E094F7_D630_44BD_A363_2C624A4665ED__INCLUDED_)
