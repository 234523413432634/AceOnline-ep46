#ifndef _PROTOCOL_FIRETALK_II_H
#define _PROTOCOL_FIRETALK_II_H
// #include "Protocol_FireTalk_II.h"

typedef enum
{
	_PUBLIC_TYPE	= 0,	// Public IP
	_NAT_CONE		= 1,
//	_NAT_CONE_A		= 1,	// Private IP : ��Ŷ�� ������ �����ּҰ� Ʋ���� �ҽ��ּҴ� ����
//	_NAT_CONE_B		= 2,	// Private IP : ��Ŷ�� ������ �����ּҰ� Ʋ���� �ҽ��ּҵ� Ʋ���� ������
	_NAT_SYMETRIC	= 3,	// Private IP : ��Ŷ�� ���� �ҽ��ּҰ� Ŭ���� ���� ����.
	_NOTUSE_UDP		= 4,	// UDP ��Ŷ ������ ���� �ʴ´�.
	_NULL_TYPE		= 9
}NetworkType;

enum NATErrorInfos 
{
	// ��Ʈ���� ���� ����
	ERR_NOTHING					= 0,	// ���� ����
	ERR_GENERAL_POINTER			= 1,	// ��Ʈ���� ���� ����
	ERR_CREATE_CHANNEL			= 2,	// ��Ʈ���� ���� ����
	ERR_START_CHANNEL			= 3,	// ��Ʈ���� ���� ����
	ERR_END_CHANNEL				= 4,	// ��Ʈ���� ���� ����

	// ������ ���� ����
//	INVALID_PRODUCT				= 10,	// ������Ʈ ID�� Ʋ����. 
	INVALID_PRODUCT_VERSION		= 11,	// ������Ʈ version�� Ʋ����
//	INVALID_ID					= 12,	// 
	NOTOPENPORTROUTECREATE		= 13,	// RTP ���Ʈ������ UDP ��Ʈ�� �����Ҽ� ����.	

	// Ŭ���̾�Ʈ�� ���� ����
	ERR_CREATE_OPENPORT			= 30,	// RTP ä�ο��� UDP ��Ʈ�� ���� �Ҽ� ����.
	ERR_NO_RESPONSE_UDP			= 31,	// FireTalk�� UDP ��Ŷ�� ���´µ� ������ ����. FireTalk�� �׾��ְų� UDP ��Ʈ�� Ȯ���ؾ���.
	ERR_No_RESPOnSE_TCP			= 32,	// FireTalk�� TCP ������ �õ������� ������. FireTalk�� �׾��ְų� ��Ʈ�� Ȯ���ؾ���.	

	// NAT �м������� ���� ����
	ERR_NO_RESPONSE_SERVER		= 41,	// ������ NAT �м��� ���� UDP ��Ŷ�� ���´µ� ������ ����. ������ �׾��ְų� UDP ��Ʈ�� Ȯ���ؾ���.
	ERR_No_RESPOnSE_FIRETALK	= 42	// FireTalk II�� NAT �м��� ���� UDP ��Ŷ�� ���´µ� ������ ����. FireTalk II�� �׾��ְų� UDP ��Ʈ�� Ȯ���ؾ���.


};


enum UDPMsgType
{
	_ANALYZE_NAT_A			= 1,
	_ANALYZE_NAT_A_M		= 2,
	_ANALYZE_NAT_A_ACK		= 3,
	_ANALYZE_NAT_B			= 4, 
	_ANALYZE_NAT_B_ACK		= 5, 
	_SEEK_PUBLIC_INFO		= 6,
	_SEEK_PUBLIC_INFO_ACK	= 7,
	_ACTIVE_CONFIRM			= 8
};
typedef struct
{
	UDPMsgType type;
	union
	{
		struct NAT_A_MSG
		{				
			char	strRouteIP[16];
			UINT	uRoutePort;
		} natAmsg;			
		struct NAT_AM_MSG
		{				
			char	strRouteIP[16];
			UINT	uRoutePort;
		} natAMmsg;
		struct NAT_AACK_MSG
		{				
			char	strRouteIP[16];
			UINT	uRoutePort;
		} natAackmsg;
		struct NAT_B_ACK_MSG 
		{
			char	strRouteIP[16];
			UINT	uRoutePort;
		} natBackmsg;
		struct SEEKACK_MSG 
		{
			char	strRouteIP[16];
			UINT	uRoutePort;
		} seekackmsg;
	} Data;
}UDPMSG;


#endif