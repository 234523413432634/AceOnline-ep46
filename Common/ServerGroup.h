///////////////////////////////////////////////////////////////////////////////
//  SocketGroup.h : 
//  
//  Date	: 2004-03-17 by cmkwon
///////////////////////////////////////////////////////////////////////////////

#ifndef _SERVER_GROUP_H_
#define _SERVER_GROUP_H_

///////////////////////////////////////////////////////////////////////////////
// ������ ����
///////////////////////////////////////////////////////////////////////////////
class CIOCPSocket;
struct ServerInfo
{
public:
	ServerInfo() { Reset(); }
	virtual ~ServerInfo() { Reset(); }

	virtual void Reset()
	{
		ServerType = ST_INVALID_TYPE;
		memset(&serverID, 0x00, sizeof(SERVER_ID));
		IsActive = FALSE;
		pSocket = NULL;
	}

public:
	ENServerType	ServerType;
	SERVER_ID		serverID;
	BOOL			IsActive;
	CIOCPSocket		*pSocket;
};

struct FieldServerInfo : public ServerInfo
{
public:
	FieldServerInfo() 
	{
		MapIndexVector.reserve(50);
		Reset();
	}
	virtual ~FieldServerInfo() { Reset(); }

	void Reset()
	{
		MapIndexVector.clear();		
		AccumulatedFieldUserCounts = 0;
		CurrentFieldUserCounts = 0;
		MaxFieldUserCounts = 0;
		AccumulatedFieldMonsterCounts = 0;
		CurrentFieldMonsterCounts = 0;

		ServerInfo::Reset();
	}

	BOOL IsExistMapIndex(MapIndex_t i_mapIdx)
	{
		vector<MapIndex_t>::iterator itr(MapIndexVector.begin());
		for(; itr != MapIndexVector.end(); itr++)
		{
			if(*itr == i_mapIdx)
			{
				return TRUE;
			}
		}
		return FALSE;
	}

public:
	vector<MapIndex_t>	MapIndexVector;
	UINT				AccumulatedFieldUserCounts;
	UINT				CurrentFieldUserCounts;
	UINT				MaxFieldUserCounts;
	UINT				AccumulatedFieldMonsterCounts;
	UINT				CurrentFieldMonsterCounts;
};

class CServerGroup
{
public:
	CServerGroup();
	~CServerGroup();

	void InitServerGroup(void);
	void ResetServerGroup(BOOL i_bExcludeIMServer=FALSE);

	INT GetUserCount();
	void SendMessageToFieldServer(BYTE *i_pBuff, int i_nSize);
	void SendMsgToIMServer(BYTE *i_pBuff, int i_nSize);
public:
	char							m_ServerGroupName[SIZE_MAX_SERVER_NAME];
	BOOL							m_bEnableServerGroup;
	BOOL							m_bForbidViewServer;		// 2007-12-22 by dhjin, �Ʒ��� ���� - ���� ����Ʈ���� ���̸� �ȵǴ� ���� üũ, TRUE = ������ �ʴ´�.

	// statistics
	UINT							m_AccumulatedGroupUserCounts;
	UINT							m_MaxGroupUserCounts;
	UINT							m_LimitGroupUserCounts;
	int								m_nMGameServerID;
	BOOL							m_bLockCreateCharacterForNewAccount;	// 2008-04-29 by cmkwon, ������ ���� DB�� �߰�(�ű� ���� ĳ���� ���� ���� �ý����߰�) - from FieldServer

	// server management
	ServerInfo						m_IMServerInfo;						// IMServer
	FieldServerInfo					m_FieldServerInfo;					// FieldServer
	mt_set<string>					m_setLoginedAccount;				// �������� account ����Ʈ
};

#endif	// _SERVER_GROUP_H_endif