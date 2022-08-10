#pragma once

#import "msado60_Backcompat_i386.tlb" no_namespace rename("EOF", "EndOfFile")

#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <atlstr.h>
#include "LogFile.h"
#include "InternetHttp.h"

#define		APP_NAME					"FiveRocksClient"

#define		LOGFILE_FILENAME			"FiveRocksLog"
#define		LOGFILE_DIRECTORY			"../../Log/SystemLog/"

// �����͸� �ο� ����Ʈ ������
// enum TAPJOY_SITE
// {
// 	TAPJOY_ACEONLINE_TEST = 0,
// 	TAPJOY_ACEONLINE,
// 	TAPJOY_ACEONLINE_GLOBALSERVICE,
// 	TAPJOY_END
// };

#define		TAPJOY_ACEONLINE_TEST

#if defined(TAPJOY_ACEONLINE_TEST)

#define TAPJOY_HTTP_URL "rpc.tapjoy.com"
#define TAPJOY_HTTP_APPID "/api/v1/sevs/"
#define TAPJOY_HTTP_APIKEY "VLi9mbzRgACAAACCHQAAAQER0Zuy7P4cEL3Lt9xXlXPoPZJFcR49JV_AQRcU"
#define FIVEROCKS_HTTP_CONTENTTYPE "Content-Type:application/x-www-form-urlencoded"

#elif defined(TAPJOY_ACEONLINE)

#define TAPJOY_HTTP_URL "rpc.tapjoy.com"
#define TAPJOY_HTTP_APPID "/api/v1/sevs/"
#define TAPJOY_HTTP_APIKEY "VLi79GhmgACAAACCHQAAAwER6L5ZCgdH70rYCiJ3yVcm7143XX2wO7l5O0nB"
#define FIVEROCKS_HTTP_CONTENTTYPE "Content-Type:application/x-www-form-urlencoded"

#elif defined(TAPJOY_ACEONLINE_GLOBALSERVICE)

#define TAPJOY_HTTP_URL "rpc.tapjoy.com"
#define TAPJOY_HTTP_APPID "/api/v1/sevs/"
#define TAPJOY_HTTP_APIKEY "VTiDeH09gACAAK2icxPxEAER7Y3IUhoAQ12mPewBYzhs9CdTx9vQxS39u6Vm"
#define FIVEROCKS_HTTP_CONTENTTYPE "Content-Type:application/x-www-form-urlencoded"

#endif

enum FIVEROCKS_DATA_TYPE
{
	FIVEROCKS_DATA_TYPE_DEFAULT,
	FIVEROCKS_DATA_TYPE_LOGIN,
	FIVEROCKS_DATA_TYPE_CCU,
	FIVEROCKS_DATA_TYPE_BUYITEM,
	FIVEROCKS_DATA_TYPE_PKINFO,
	FIVEROCKS_DATA_TYPE_END
};

enum CUSTOMTYPE
{
	CUSTOMTYPE_CCU_MIN,
	CUSTOMTYPE_CCU_HOUR,
	CUSTOMTYPE_CCU_DAY,
	CYSTOMTYPE_PKINFO,
	CUSTOMTYPE_END
};

//KST�ð��� �������� SEGMENT�ð� ������ ��� �ð��� �����
#define DEFAULT_TIME_SEGMENT	600	// 10�и���
#define DEFAULT_TIME_CHECK		300	// 5�б�������

#define ACTIVEUSER_TIME_SEGMENT	1800	// 60�� * 10 * 30�� = 1800��
#define ACTIVEUSER_TIME_CHECK	0		// x�� y * 30���� �������� 30�п� �ѹ���

#define MONETIZATION_TIME_SEGMENT	600	// 60�� * 10 = 600��
#define MONETIZATION_TIME_CHECK		300 // x�� y*10+5���� �������� 10�п� �ѹ���

#define CCU_MIN_TIME_SEGMENT	600 // 60�� * 10 = 600��
#define CCU_MIN_TIME_CHECK		300 // x�� y*10+5���� �������� 10�п� �ѹ���
#define CCU_HOUR_TIME_SEGMENT	3600 // 60�� * 60�� = 3600��
#define CCU_HOUR_TIME_CHECK		1800//1800 // x�� 30���� �������� 1�ð��� �ѹ���
#define CCU_DAY_TIME_SEGMENT	86400 // 60�� * 60�� * 24�ð� = 86400��
#define CCU_DAY_TIME_CHECK		85800 // x�� 23�� 50���� �������� 1�Ͽ� �ѹ���

#define	KST_TIME	32400 // UTC�ð��� KST(�ѱ�)�ð���

#define FIVEROCKS_MAX_DB_SELECT_COUNT	1000
#define FIVEROCKS_MAX_DATA_LENGTH	512

#define		FILE_PATH_SERVER_INFO_UNI		L"../../config/global.cfg"	// L"../Config/Global.cfg"
#define		FILE_PATH_SERVER_INFO_MBC		"../../config/Global.cfg"	//"../Config/Global.cfg" // ".\..\..\config\Global.cfg"

#define		FILE_PATH_CONFIG_ROOT_UNI		L"./config_root.cfg"
#define		FILE_NAME_GLOBAL_CFG_UNI		L"./global.cfg"		

#define		SOURCE_DB_CONNECT			L"Provider=SQLOLEDB.1;Persist Security Info=False;User ID=%s ;pwd=%s; Initial Catalog=5Rocks;Data Source=%s;Network Address=%s,%s; Network Library=dbmssocn"
//#define		GLOG_SOURCE_DB_CONNECT			L"Provider=SQLOLEDB.1;Persist Security Info=False;User ID=21474103 ;pwd=2352580204405E; Initial Catalog=GLog;Data Source=49.254.155.91;Network Address=49.254.155.91,9979; Network Library=dbmssocn"

#define		SIZE_MAX_DB_NAME			30
#define		SIZE_MAX_CHANNEL_NAME		20
#define		SIZE_MAX_CHANNELING_NAME	20
#define		SIZE_MAX_DB_CHANNELING_NAME	20

#define		SIZE_MAX_DB_USER_ID				128
#define		SIZE_MAX_DB_USER_PWD			128
#define		SIZE_MAX_ODBC_CONN_STRING		128

#define		STR_XOR_KEY_STRING_DB_ID_PWD	"@34ns%<<fdsa(Tflsd!sndsa^#)fndsla$nvsa$fndsla&nfdsJak(fnldsa!#F"	// 2008-09-01 by cmkwon, global.cfg ���Ͽ� DB ID/PWD ��ȣȭ - 
#define		SOURCE_DB_ID					"$LOG_SERVER_GROUP_ODBC_UID"
#define		SOURCE_DB_PASSWORD				"$LOG_SERVER_GROUP_ODBC_PASSWD"
#define		SOURCE_DB_IP					"$LOG_SERVER_GROUP_DB_SERVER_IP"
#define		SOURCE_DB_PORT					"$LOG_SERVER_GROUP_DB_SERVER_PORT"

#define	DB_ATUM_FIVEROCKS_SELECT		L"PROC_5Rocks_Select"
#define	DB_ATUM_FIVEROCKS_DELETE		L"PROC_5Rocks_Delete"
#define	DB_ATUM_FIVEROCKS_DELETE_OPTION	L"PROC_5Rocks_Delete_Option"
#define	DB_ATUM_FIVEROCKS_INSERT		L"PROC_5Rocks_Insert"

// Error Define

// DB Error
#define ERR_DB_NO_DATA					(UINT32)0x00000010
#define ERR_DB_COM_CONNECT_FAIL			(UINT32)0x80004005
#define ERR_DB_COM_DUPLICATE_INSERT		(UINT32)0x80040e2f
#define ERR_DB_COM_PROCEDURE			(UINT32)0x80040e14

#define LSTRNCPY_OLEDB(pDest, pSource) { if(VT_NULL != pSource.vt) { lstrcpy(pDest,(TCHAR*)((_bstr_t)pSource));}}

#define		TAPJOY_CURRENCY_KOR				"KRW"
#define		TAPJOY_CURRENCY_JAPAN			"JPY"
#define		TAPJOY_CURRENCY_CANADA			"CAD"

// ���� DB
#if defined(SERVER_KOR)

// #define		DB_NAME_DEKA		"atum2_db_1"
// #define		DB_NAME_BISHOP		"atum2_db_7"
// #define		DB_NAME_PHILON		"atum2_db_6"
// 
// #define		CHANNEL_NAME_1		"��ī"
// #define		CHANNEL_NAME_2		"���"
// #define		CHANNEL_NAME_3		"�ʷ�"
// 
// #define		REFFER_NAME			"KOREA"

const TCHAR	g_DbName[][SIZE_MAX_DB_NAME] = 
{TEXT("atum2_db_1"), TEXT("atum2_db_7"), TEXT("atum2_db_6")};
const TCHAR	g_ChannelName[][SIZE_MAX_CHANNEL_NAME] = 
{TEXT("��ī"), TEXT("���"), TEXT("�ʷ�")};
const TCHAR	g_ChannelingName[][SIZE_MAX_CHANNELING_NAME] = 
{TEXT("�������Ʈ"), TEXT("���Ǿ�")};
const TCHAR	g_DbChannelingName[][SIZE_MAX_DB_CHANNELING_NAME] = 
{TEXT("MASANGSOFT"), TEXT("MUNPIA")};

const int g_nMax_Count_Db			= (sizeof(g_DbName) / (sizeof(TCHAR) * SIZE_MAX_DB_NAME));
const int g_nMax_Count_Channel		= (sizeof(g_ChannelName) / (sizeof(TCHAR) * SIZE_MAX_CHANNEL_NAME));
const int g_nMax_Count_Channeling	= (sizeof(g_ChannelingName) / (sizeof(TCHAR) * SIZE_MAX_CHANNELING_NAME));
const int g_nMax_Count_DbChanneling	= (sizeof(g_DbChannelingName) / (sizeof(TCHAR) * SIZE_MAX_DB_CHANNELING_NAME));

#define		CCU_CHNNELING_ALL_NAME	"��ü" // ��ü

#define		TAPJOY_CURRENCY		TAPJOY_CURRENCY_KOR
#define		REFERR_NAME			"KOREA"

// �Ϻ� DB
#elif defined(SERVER_JPN)
// DB_NAME_1			"atum2_db_8" //���ڶ�
// DB_NAME_2			"atum2_db_7" //�糪

// CHANNEL_NAME_1		"Stella"
// CHANNEL_NAME_2		"Luna"

// CAHNNELING_NAME_1	"JAPAN"
// DBCAHNNELING_NAME_1	"JAPAN"

const TCHAR	g_DbName[][SIZE_MAX_DB_NAME] = 
			{TEXT("atum2_db_8"), TEXT("atum2_db_7")};
const TCHAR	g_ChannelName[][SIZE_MAX_CHANNEL_NAME] = 
			{TEXT("Stella"), TEXT("Luna")};
const TCHAR	g_ChannelingName[][SIZE_MAX_CHANNELING_NAME] = 
			{TEXT("JAPAN")};
const TCHAR	g_DbChannelingName[][SIZE_MAX_DB_CHANNELING_NAME] = 
			{TEXT("JAPAN")};

const int g_nMax_Count_Db			= (sizeof(g_DbName) / (sizeof(TCHAR) * SIZE_MAX_DB_NAME));
const int g_nMax_Count_Channel		= (sizeof(g_ChannelName) / (sizeof(TCHAR) * SIZE_MAX_CHANNEL_NAME));
const int g_nMax_Count_Channeling	= (sizeof(g_ChannelingName) / (sizeof(TCHAR) * SIZE_MAX_CHANNELING_NAME));
const int g_nMax_Count_DbChanneling	= (sizeof(g_DbChannelingName) / (sizeof(TCHAR) * SIZE_MAX_DB_CHANNELING_NAME));

#define		CCU_CHNNELING_ALL_NAME	"ALL" // ��ü

#define		TAPJOY_CURRENCY		TAPJOY_CURRENCY_JAPAN
#define		REFERR_NAME			"JAPAN"

#elif defined(SERVER_CAN)
// DB_NAME_1			"atum2_db_1" //

// CHANNEL_NAME_1		"Canada"

// CAHNNELING_NAME_1	"CANADA"
// DBCAHNNELING_NAME_1	"CANADA"
#define USE_SERVER2003_R2

const TCHAR	g_DbName[][SIZE_MAX_DB_NAME] = 
{TEXT("atum2_db_1")};
const TCHAR	g_ChannelName[][SIZE_MAX_CHANNEL_NAME] = 
{TEXT("Canada")};
const TCHAR	g_ChannelingName[][SIZE_MAX_CHANNELING_NAME] = 
{TEXT("Wikigames_Eng")};
const TCHAR	g_DbChannelingName[][SIZE_MAX_DB_CHANNELING_NAME] = 
{TEXT("CANADA")};

const int g_nMax_Count_Db			= (sizeof(g_DbName) / (sizeof(TCHAR) * SIZE_MAX_DB_NAME));
const int g_nMax_Count_Channel		= (sizeof(g_ChannelName) / (sizeof(TCHAR) * SIZE_MAX_CHANNEL_NAME));
const int g_nMax_Count_Channeling	= (sizeof(g_ChannelingName) / (sizeof(TCHAR) * SIZE_MAX_CHANNELING_NAME));
const int g_nMax_Count_DbChanneling	= (sizeof(g_DbChannelingName) / (sizeof(TCHAR) * SIZE_MAX_DB_CHANNELING_NAME));

#define		CCU_CHNNELING_ALL_NAME	"ALL" // ��ü

#define		TAPJOY_CURRENCY		TAPJOY_CURRENCY_CANADA
#define		REFERR_NAME			"CANADA"

// 238 DB
#elif defined(SERVER_TEST238)

// DB_NAME_1		"atum2_db_1"

// CHANNEL_NAME_1		"238"
// CHANNEL_NAME_2		"238"

// CAHNNELING_NAME_1	"MS_238"
// DBCAHNNELING_NAME_1	"MASANGSOFT"

const TCHAR	g_DbName[][SIZE_MAX_DB_NAME] = 
			{TEXT("atum2_db_1")};
const TCHAR	g_ChannelName[][SIZE_MAX_CHANNEL_NAME] = 
			{TEXT("238")};
const TCHAR	g_ChannelingName[][SIZE_MAX_CHANNELING_NAME] = 
			{TEXT("MS_238")};
const TCHAR	g_DbChannelingName[][SIZE_MAX_DB_CHANNELING_NAME] = 
			{TEXT("MASANGSOFT")};

const int g_nMax_Count_Db			= (sizeof(g_DbName) / (sizeof(TCHAR) * SIZE_MAX_DB_NAME));
const int g_nMax_Count_Channel		= (sizeof(g_ChannelName) / (sizeof(TCHAR) * SIZE_MAX_CHANNEL_NAME));
const int g_nMax_Count_Channeling	= (sizeof(g_ChannelingName) / (sizeof(TCHAR) * SIZE_MAX_CHANNELING_NAME));
const int g_nMax_Count_DbChanneling	= (sizeof(g_DbChannelingName) / (sizeof(TCHAR) * SIZE_MAX_DB_CHANNELING_NAME));

#define		CCU_CHNNELING_ALL_NAME	"��ü" // ��ü

#define		TAPJOY_CURRENCY		TAPJOY_CURRENCY_KOR
#define		REFERR_NAME			"KOREA_TEST_MS238"
#elif defined(SERVER_TEST_CAN)
// DB_NAME_1			"atum2_db_1" //

// CHANNEL_NAME_1		"Canada"

// CAHNNELING_NAME_1	"JAPAN"
// DBCAHNNELING_NAME_1	"JAPAN"
#define USE_SERVER2003_R2

const TCHAR	g_DbName[][SIZE_MAX_DB_NAME] = 
{TEXT("atum2_db_1")};
const TCHAR	g_ChannelName[][SIZE_MAX_CHANNEL_NAME] = 
{TEXT("CANADA_TEST")};
const TCHAR	g_ChannelingName[][SIZE_MAX_CHANNELING_NAME] = 
{TEXT("CANADA_TEST")};
const TCHAR	g_DbChannelingName[][SIZE_MAX_DB_CHANNELING_NAME] = 
{TEXT("CANADA")};

const int g_nMax_Count_Db			= (sizeof(g_DbName) / (sizeof(TCHAR) * SIZE_MAX_DB_NAME));
const int g_nMax_Count_Channel		= (sizeof(g_ChannelName) / (sizeof(TCHAR) * SIZE_MAX_CHANNEL_NAME));
const int g_nMax_Count_Channeling	= (sizeof(g_ChannelingName) / (sizeof(TCHAR) * SIZE_MAX_CHANNELING_NAME));
const int g_nMax_Count_DbChanneling	= (sizeof(g_DbChannelingName) / (sizeof(TCHAR) * SIZE_MAX_DB_CHANNELING_NAME));

#define		CCU_CHNNELING_ALL_NAME	"ALL" // ��ü

#define		TAPJOY_CURRENCY		TAPJOY_CURRENCY_CANADA
#define		REFERR_NAME			"CANADA_TEST"

#endif

class FiveRocksTBData
{
public:
	FiveRocksTBData(void)
	{
		Reset();
	}
	~FiveRocksTBData(void) {}

	INT64			UID;
	INT64			DataType;
	INT64			UserSerial;
	TCHAR			Data[FIVEROCKS_MAX_DATA_LENGTH];
	INT64			Flag;								// �ϴ��� ������� ������ ���Ŀ� ����ϱ� ���� ��

	void Reset()
	{
		UID = NULL;
		DataType = NULL;
		UserSerial = NULL;
		for (int i = 0 ; i < FIVEROCKS_MAX_DATA_LENGTH ; i++)
		{
			Data[i] = NULL;
		}
		Flag = 255;	// ����Ʈ���� 255�̸� DB���� 255�϶� �������� ���� �÷��׷� �Ǵ��ϰ� ���� �� ������ ���� ����
	}
};

#define		SIZE_MAX_FIVEROCKS_TYPE			7	// "custom" ���� + 1
#define		SIZE_MAX_FIVEROCKS_NAME			21
//#define		SIZE_MAX_FIVEROCKS_APPKEY		21	// "0Zuy7P4cEL3Lt9xXlXPo" ���� + 1
#define		SIZE_MAX_FIVEROCKS_APIKEY		71	// " ���� + 1
#define		SIZE_MAX_FIVEROCKS_USERID		21	// "-9223372036854775808" ~ "9223372036854775807"

#define		SIZE_MAX_FIVEROCKS_PRODUCT_ID	128
#define		SIZE_MAX_FIVEROCKS_CURRENCY		10
#define		SIZE_MAX_FIVEROCKS_CATEGORY		11	// 10���� ������ ī�װ��� ��������
#define		SIZE_MAX_FIVEROCKS_PARAM		20	// 20 byte ������ �Ķ���� �̸� ����
#define		SIZE_MAX_FIVEROCKS_REFERRER		40
#define		SIZE_MAX_FIVEROCKS_UV			11	// �ӽ÷� ����
#define		SIZE_MAX_FIVEROCKS_VALUES		20
#define		SIZE_MAX_FIVEROCKS_CHANNEL		15	// ä�� ��) "��ī", "�ʷ�", "���"
#define		SIZE_MAX_FIVEROCKS_CHANNELING	30	// ä�θ� ����Ʈ
#define		SIZE_MAX_FIVEROCKS_INFLUENCE	30	// ���� ��) "�˸���", "����������"
#define		SIZE_MAX_FIVEROCKS_GEARTYPE		15	// ��� Ÿ�� ��) "A-Gear", "B-Gear", "I-Gear", "M-Gear"
#define		SIZE_MAX_FIVEROCKS_TIMETYPE		10

#define		FIVEROCKS_CUSTOM_VALUES_COUNT		3			// �ѹ��� 3���� ���� �� ���� 3�� �̻��� ���� �����Ұ�� ������ ������ ���� ����
#define		FIVEROCKS_CUSTOM_VALUES_COUNT_MAX	6

class ActiveUserData
{
public:
	ActiveUserData() 
	{ 
		memset(this,0x00,sizeof(ActiveUserData)); 
		lstrcpy(type,TEXT("app")); 
		lstrcpy(name,TEXT("bootup")); 
		lstrcpy(api_key,TEXT(TAPJOY_HTTP_APIKEY));
	}
	~ActiveUserData() {}

	TCHAR	type[SIZE_MAX_FIVEROCKS_TYPE];
	TCHAR	name[SIZE_MAX_FIVEROCKS_NAME];
	//TCHAR	app_key[SIZE_MAX_FIVEROCKS_APPKEY];
	TCHAR	api_key[SIZE_MAX_FIVEROCKS_APIKEY];
	TCHAR	user_id[SIZE_MAX_FIVEROCKS_USERID];
	INT64	user_level;
	INT64	freind_count;
	TCHAR	referrer[SIZE_MAX_FIVEROCKS_REFERRER];
	TCHAR	uv1[SIZE_MAX_FIVEROCKS_UV];
	TCHAR	uv2[SIZE_MAX_FIVEROCKS_UV];
	TCHAR	uv3[SIZE_MAX_FIVEROCKS_UV];
	TCHAR	uv4[SIZE_MAX_FIVEROCKS_UV];
	TCHAR	uv5[SIZE_MAX_FIVEROCKS_UV];
	INT64	time;	

	void Reset() 
	{
		memset(this,0x00,sizeof(ActiveUserData)); 
		lstrcpy(type,TEXT("app")); 
		lstrcpy(name,TEXT("bootup")); 
		lstrcpy(api_key,TEXT(TAPJOY_HTTP_APIKEY));
	}
};

class MonetizationData
{
public:
	MonetizationData() 
	{
		memset(this,0x00,sizeof(MonetizationData));
		lstrcpy(type,TEXT("app")); 
		lstrcpy(name,TEXT("purchase")); 
		lstrcpy(api_key,TEXT(TAPJOY_HTTP_APIKEY));
	}
	~MonetizationData() {}

	TCHAR	type[SIZE_MAX_FIVEROCKS_TYPE];
	TCHAR	name[SIZE_MAX_FIVEROCKS_NAME];
	//TCHAR	app_key[SIZE_MAX_FIVEROCKS_APPKEY];
	TCHAR	api_key[SIZE_MAX_FIVEROCKS_APIKEY];
	TCHAR	user_id[SIZE_MAX_FIVEROCKS_USERID];
	TCHAR	product_id[SIZE_MAX_FIVEROCKS_PRODUCT_ID];
	INT64	price;
	TCHAR	currency[SIZE_MAX_FIVEROCKS_CURRENCY];
	INT64	user_level;
	INT64	freind_count;
	TCHAR	referrer[SIZE_MAX_FIVEROCKS_REFERRER];
	TCHAR	uv1[SIZE_MAX_FIVEROCKS_UV];
	TCHAR	uv2[SIZE_MAX_FIVEROCKS_UV];
	TCHAR	uv3[SIZE_MAX_FIVEROCKS_UV];
	TCHAR	uv4[SIZE_MAX_FIVEROCKS_UV];
	TCHAR	uv5[SIZE_MAX_FIVEROCKS_UV];
	INT64	time;	

	INT64	product_num;

	void Reset()
	{
		memset(this,0x00,sizeof(MonetizationData));
		lstrcpy(type,TEXT("app")); 
		lstrcpy(name,TEXT("purchase")); 
		lstrcpy(api_key,TEXT(TAPJOY_HTTP_APIKEY));
	}
};

class CustomData
{
public:
	CustomData() 
	{
		memset(this,0x00,sizeof(CustomData));
		lstrcpy(type,TEXT("custom")); 
		lstrcpy(api_key,TEXT(TAPJOY_HTTP_APIKEY));
	}
	~CustomData() {}

	TCHAR	type[SIZE_MAX_FIVEROCKS_TYPE];
	TCHAR	name[SIZE_MAX_FIVEROCKS_NAME];
	//TCHAR	app_key[SIZE_MAX_FIVEROCKS_APPKEY];
	TCHAR	api_key[SIZE_MAX_FIVEROCKS_APIKEY];
	TCHAR	user_id[SIZE_MAX_FIVEROCKS_USERID];
	TCHAR	category[SIZE_MAX_FIVEROCKS_CATEGORY];
	TCHAR	p1[SIZE_MAX_FIVEROCKS_PARAM];
	TCHAR	p2[SIZE_MAX_FIVEROCKS_PARAM];
	TCHAR	key[FIVEROCKS_CUSTOM_VALUES_COUNT][SIZE_MAX_FIVEROCKS_VALUES];
	INT64	values[FIVEROCKS_CUSTOM_VALUES_COUNT];
	INT64	user_level;
	INT64	freind_count;
	TCHAR	referrer[SIZE_MAX_FIVEROCKS_REFERRER];
	TCHAR	uv1[SIZE_MAX_FIVEROCKS_UV];
	TCHAR	uv2[SIZE_MAX_FIVEROCKS_UV];
	TCHAR	uv3[SIZE_MAX_FIVEROCKS_UV];
	TCHAR	uv4[SIZE_MAX_FIVEROCKS_UV];
	TCHAR	uv5[SIZE_MAX_FIVEROCKS_UV];
	INT64	time;

	TCHAR	channel[SIZE_MAX_FIVEROCKS_CHANNEL];
	TCHAR	channeling[SIZE_MAX_FIVEROCKS_CHANNELING];
	TCHAR	influence[SIZE_MAX_FIVEROCKS_INFLUENCE];
	TCHAR	geartype[SIZE_MAX_FIVEROCKS_GEARTYPE];
	BOOL	iskill;

	//ccu
	TCHAR	time_type[SIZE_MAX_FIVEROCKS_TIMETYPE];
	INT64	ccu[g_nMax_Count_Channeling];
	INT64	ccuall;

	void Reset()
	{
		memset(this,0x00,sizeof(CustomData));
		lstrcpy(type,TEXT("custom")); 
		lstrcpy(api_key,TEXT(TAPJOY_HTTP_APIKEY));
	}
};