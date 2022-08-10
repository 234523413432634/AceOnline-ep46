#ifndef __DIALERDEFINE__H__
#define __DIALERDEFINE__H__
// coded by palbang //////////////////
// ȯ�� ����
// ����â ������, ��, ����
#define STATUS_X	10
#define STATUS_Y	45
#define STATUS_W	140
// ��ü �ؽ�Ʈ ����
#define TEXT_H		17
// �ð� ǥ��â ������
#define TIME_X		70
#define TIME_Y		8
// ���׳� ������, ��, ����
#define	ANTENA_X	2
#define	ANTENA_Y	1
#define ANTENA_W	36
#define ANTENA_H	22
// ��ȭ ��ȣ �Է� ������, ��
#define	PHONE_X		8
#define	PHONE_Y		29
#define PHONE_W		144  //??
// ����, ���� �ϳ� ����
#define NUMBER_W	12
// ���� ���� ��ǥ
//#define COUPON_X	96
//#define COUPON_Y	52
//#define COUPON_W	35
// ���Ϲ�ư ��ġ
//#define BOOK_X		8
//#define BOOK_Y		52
///////end of added code////////////////////////

#define PRODUCTID	0
#define MAXDATALENGTH 80

enum MessageType 
{
	_ERROR = 0x10, 
	_LOGIN, 
	_OK, 
	_DIAL, 
	_ALERT, //20
	_STARTRTP, 
	_CONNECTED, 
	_HANGUP, 
	_BUTTON, 
	_COMPLETE, //25
	_ALIVE, 
	_REGISTRATION, 
	_RETRIEVE, 
	_REGOK, 
	_ROUTERTP, //30
	_ROUTEOK, 
	_REQPROXY, //32
	_RESPROXY, 
	_NOPROXY, 
	_PHONEBOOK, 
	_PREREGISTRATION/*PCN;PWD ������ �ʹ� �涧 PWD ��������*/, 
	_SIGNUP, 
	_SEARCHUSER = 0x26, //38
	_MYSTATUS,
	_FORWARDING, //40
	_VIDEOMSG,
	_NOTICE,
	_TEXT,
	_REREGISTRATION,  // ���� �α׾ƿ� �Ŀ� �ٽ� �α���
	_GETRATE, //45
	_MONEY,
	_UPDATE,
	_NONFASTSTART,
	_ASK_ACTIVE_CONFIRM, //by cje 021112
	_RETRY_ACTIVE_CONFIRM, //50
	_ACTIVE_CONFIRM_OK,
	_PASSIVE_START,
	_VIDEOPAUSE,
	_VOICECODEC = 54,
	_VIDEOCODEC = 55,
	_REQMAKECONFERENCE,
	_RESMAKECONFERENCE, 
	_REQJOINCONFERENCE,
	_RESJOINCONFERENCE,
	_REQINVITECONFERENCE = 60,
	_RESINVITECONFERENCE,
	_STATUSCONFERENCE,
	_LEAVECONFERENCE, 
	_CLOSECONFERENCE
};
enum ProgressType {_SIGNUPING = 0, _MODIFYING, _PHONEBOOKING, _BILLING, /*_FORWARDING, */_LOGINING, _DIALING, _SEARCHUSERING};
//enum {INVALID_PRODUCT = 1, INVALID_ID, INVALID_NUMBER, NETWORK_ERROR, NO_FREE_CHANNEL, OVER_TIME, NO_ANSWER, BUSY, REFUSE, INVALID_PWD};
enum ErrorInfos {
	INVALID_PRODUCT = 1, 
	INVALID_ID, // SCDialer1 --> Invalid PCN
	INVALID_NUMBER,  // WebCallient + SCDialer1 --> Invalid Number
	NETWORK_ERROR, // WebCallient + SCDialer1 --> Server error
	NO_FREE_CHANNEL,
	OVER_TIME, // WebCallient + SCDialer1 --> Server error
	NOBANDWIDTH, // WebCallient --> Invalid Number ?
	GATEKEEPERRESOURCE, 
	UNREACHABLEDESTINATION, 
	DESTINATIONREJECTION = 10, 
	INVALIDREVISION, 
	NOPERMISION, 
	UNREACHABLEGATEKEEPER,
	GATEWAYRESOURCE, 
	BADFORMATADDRESS, // WebCallient + SCDialer1 --> Invalid Number
	ADAPTIVEBUSY, 
	INCONF = 17, // WebCallient + SCDialer1 --> Busy.. Try again
	UNDEFINEREASON, 
	ROUTECALLTOGATEKEEPER, 
	CALLFORWARDED = 20, 
	ROUTECALLTOMC,
	FACILITYCALLDEFLECTION, 
	SECURITYDENIED, // PC2PC ������ �Ͻ� �������
	CALLEDPARTYNOTREGISTERED, 
	CALLERNOTREGISTERED, 
	NEWCONNECTIONNEEDED, 
	NOH245, 
	CONFERENCELISTCHOICE, 
	STARTH245,
	NO_ANSWER = 30, // SCDialer1 ���� ������ ���ӵǾ� ���� ������ --> No Answer
	REFUSE = 31, // SCDialer1 ���� ������ ���ӵǾ� ������ ��ȭ�ޱ⸦ �ź��� �� --> Refuse
	INVALID_PWD = 32, // SCDialer1 ���� password �� Ʋ���� ��.. --> Invalid PWD
	DUPLICATEPCN,
	DBERROR,
	NOTLOGIN,
	LOGINSOMEWHERE, // �ٸ� ������ �α����� �ؿԴٴ� Error msg
	INSUFFICIENTBALANCE,
	DBPROTOCOLERROR,
	CONFERENCEDISABLE, // ���۷��� ����� Ȱ��ȭ �Ǿ� ���� ����
	CONFERENCENOPERMISSIONTOMAKE = 40, // ���۷����� ���� ������ ����
	CONFERENCENOPERMISSIONTOJOIN, // ���۷����� ������ ������ ����
	CONFERENCENOBANDWIDTHTOJOIN = 42, // ���۷����� ������ ������ ����
	CONFERENCENOCONFERENCEID, // ��û�� ���۷��� id �� ����
	CONFERENCENOSERVERINFO, // ���۷����� ������ FireTalk server �� ����
	CONFERENCEINVITENOUSERID, // �ʴ��� ����ڰ� ����
	CONFERENCEINVITENOPERMISSION, // �ʴ��� ����ڰ� Conference permission �� ����
	SERIAL_DEVICE_USEING	= 50,
	SERIAL_INVALID_PORT		= 51,
	SERIAL_INVALID_DEVICE	= 52,
	NOTSUPPROTED_VOICECODEC = 53,
    NOTSUPPROTED_VIDEOCODEC,
    NOTSUPPORTED_VIDOSIZE
};
typedef struct {
	MessageType Type;
	union {
		struct SIGNUP_MSG {
			unsigned long step; // 0 : pcn;pwd, 1 : e-mail;name, 2 : pwd modify, 3 : e-mail modify
			char UserInfo[MAXDATALENGTH];
		} signupmsg; // 
		struct SERCHUSER_MSG {
			unsigned long type;
			char UserInfo[MAXDATALENGTH];
		} searchusermsg; // signup �� duplicate �˻翡�� �̿�
		struct REGISTRATION_MSG {
			unsigned long version;
			char UserPhoneNumber[MAXDATALENGTH];
		} registrationmsg;
		struct UPDATE_MSG {
			unsigned long version;
			char Url[MAXDATALENGTH];
		} updatemsg;
		struct LOGIN_MSG {
			unsigned long Product;
			char UserID[MAXDATALENGTH];
		} loginmsg;
		struct DIAL_MSG {
			unsigned long RtpPort;
			char PhoneNumber[MAXDATALENGTH];  // Caller IP Addr in SCDialer1 
		} dialmsg;
		struct STARTRTP_MSG {  
			unsigned long RtpPort;
			char RtpAddr[MAXDATALENGTH];  
		} startrtpmsg;  
		struct ROUTE_MSG {
			unsigned long ProxyServerPort;
			char ProxyServerIP[MAXDATALENGTH];
		} routemsg;
		struct PHONEBOOK_MSG {
			unsigned long count;
			char PhoneBook[MAXDATALENGTH];
		} phonebookmsg;
		struct MYSTATUS_MSG {
			unsigned long status;
			char MyStatus[MAXDATALENGTH];
		} mystatusmsg;
		struct FORWARDING_MSG {
			unsigned long type;
			char Forwarding[MAXDATALENGTH];
		} forwardingmsg;
		struct VIDEO_MSG {
			unsigned long VideoPort;
			char VideoIP[MAXDATALENGTH];
		} videomsg;
		struct NOTICE_MSG {
			unsigned long Type;
			char Message[MAXDATALENGTH];
		} noticemsg;
		struct TEXT_MSG {
			unsigned long length;
			char Message[MAXDATALENGTH];
		} textmsg;
		struct NONFASTSTART_MSG {
			unsigned long RtpPort;
			char RTPAddr[MAXDATALENGTH];
		} nonfaststartmsg;		
		struct VIDEOPAUSE_MSG {
			unsigned long Flag;
			char Pause[MAXDATALENGTH];
		} videopausemsg;
		struct MONEY_MSG {
			unsigned long Interval;
			char Money[MAXDATALENGTH];
		} moneymsg;
		struct REQMAKECONFERENCE_MSG {
			unsigned AttendantCount;
			char MakeConferenceInfo[MAXDATALENGTH];
		} reqmakeconferencemsg;
		struct RESMAKECONFERENCE_MSG {
			unsigned FireTalkPort;
			char FireTalkIP[MAXDATALENGTH];
		} resmakeconferencemsg;
		struct REQJOINCONFERENCE_MSG {
			unsigned JoinData;
			char JoinRoomID[MAXDATALENGTH];
		} reqjoinconferencemsg;
		struct RESJOINCONFERENCE_MSG {
			unsigned Permission;
			char JoinConferenceInfo[MAXDATALENGTH];
		} resjoinconferencemsg;
		struct REQINVITECONFERENCE_MSG {
			unsigned ReqInviteData;
			char InviteUserID[MAXDATALENGTH];
		} reqinviteconferencemsg;
		struct RESINVITECONFERENCE_MSG {
			unsigned Accept;
			char InviteUserID[MAXDATALENGTH];
		} resinviteconferencemsg;
		struct STATUSCONFERENCE_MSG {
			unsigned Status;
			char StatusInfo[MAXDATALENGTH];
		} statusconferencemsg;
		struct LEAVECONFERENCE_MSG {
			unsigned LeaveConferenceData;
			char LeaveConferenceInfo[MAXDATALENGTH];
		} leaveconferencemsg;
		struct CLOSECONFERENCE_MSG {
			unsigned CloseConferenceData;
			char CloseConferenceInfo[MAXDATALENGTH];
		} closeconferencemsg;
		struct VOICECODEC_MSG{
			unsigned long voicecodec;
			char voicecodecinfo[MAXDATALENGTH];
		} voicecodecmsg;
        struct VIDEOCODEC_MSG{
			unsigned long videocodec;
			char videocodecinfo[MAXDATALENGTH];
        } videocodecmsg;
		short ErrorInfo; /*{INVALID_PRODUCT = 1, INVALID_ID, INVALID_NUMBER, NETWORK_ERROR, NO_FREE_CHANNEL, OVER_TIME}*/
		char Button[MAXDATALENGTH]; // phone button 'type : string' 1,2,3,4,5...,*,#
	} Data;
} MESSAGE, *PMESSAGE;

typedef struct {
	BOOL bSet;
	unsigned int MediaPort;
} MEDIAPORTINFO;

enum clientSate 
{ 
	_READYSTATE		= 0,
	_DIALBLOCK		= 1,
	_ALERTINGSTATE	= 2,
	_DIALINGSTATE	= 3,
	_ERRORSTATE		= 4
};

enum AuthType { _PCN = 0, _ID, _EMAIL, _NAME, _UNKNOWN };
//enum CallNetWorkType { _INTERNAL =0 , _EXTERNAL}; //by cje 011206
enum CallNetworkType {
			_INTERNAL = 0x00,	
			_OPENINTERNET ,
			_FULLCONE,
			_RESTRICTED,
			_UDPBLOCK,
			_NOACCESS,
			_NOINFO= 0x06
};
enum RTPTRANSFERTYPE {
			_NORMAL = 0x00,
			_ACTIVE,
			_PASSIVE = 0x02
};
#ifdef _SCDialer1
enum CallMode { SCDialer1, PC2PHONE };
#endif // _SCDialer1

#define UM_MSGSOCKET		WM_USER+100
#define UM_SOKET_ERROR		WM_USER+101
#define UM_WCASOCKET		WM_USER+102

#endif
