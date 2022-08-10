#pragma once

#define CONFIG_FILE_NAME			"WatchProcessConfig.txt"
#define LOG_FILE_NAME				"WatchProcessLog.txt"

#define MAX_LEN						512

#define CHECKBOX_MARGIN_TOP			5
#define FORM_MARGIN_LEFT			5
#define FORM_MARGIN_RIGHT			5
#define FORM_MARGIN_TOP				25
#define FORM_MARGIN_BOTTOM			5

#define STARTBTN_WIDTH				100
#define STARTBTN_SPACE_WIDTH		5
#define STOPBTN_WIDTH				50
#define STOPBTN_SPACE_WIDTH			20
#define BTN_HEIGHT					70
#define BTN_SPACE_HEIGHT			20
#define BTN_LINE_MAX_NUM			3
#define GROUP_BTN_SET_WIDTH			(STARTBTN_WIDTH + STARTBTN_SPACE_WIDTH + STOPBTN_WIDTH + STOPBTN_SPACE_WIDTH)
#define GROUP_BTN_SET_HEIGHT		(BTN_HEIGHT + BTN_SPACE_HEIGHT)

#define CHECK_GROUP_INTERVAL		3000
#define BTN_RESET_INTERVAL			5
#define PROCESS_TERMINATE_TIME		1

#define GROUP_POS_X					0
#define GROUP_POS_Y					0
#define GROUP_SPACE_WIDTH			(GetSystemMetrics(SM_CXSCREEN) / 3)
#define GROUP_SPACE_HEIGHT			(GetSystemMetrics(SM_CYSCREEN) / 4)		// �ִ� �׷� ���� 12���� ����
#define GROUP_LINE_MAX_NUM			3
#define GROUP_PROCESS_SPACE_WIDTH	0
#define GROUP_PROCESS_SPACE_HEIGHT	30

#define STR_LOG_TIME_OUT			"All processes remained were terminated."
#define STR_LOG_PROC_CLOSED_001		"Process \""
#define STR_LOG_PROC_CLOSED_002		"\" was closed ("
#define STR_LOG_PROC_CLOSED_003		"sec)"

#if defined(LANGUAGE_KOR)
	#define STR_MSG_ERR_0001			"�� �� ���� ������ ����Ʈ�� �ҷ����� ���߽��ϴ�.\nconfig ������ Ȯ�����ּ���."
	#define STR_MSG_STOPBTN_YESNO		"���� �����Ͻðڽ��ϱ�?"
	#define STR_MSG_CLOSING_CANCEL		"�������� ������ �־� ������ �� �����ϴ�."
	#define STR_CHECKBOX_TEXT			"�ڵ� �ǻ츮��"
	#define STR_BTN_RUNNING_TEXT		"\n- ������ -"
	#define STR_CBTN_TEXT				"����"

#elif defined(LANGUAGE_ENG)
	#define STR_MSG_ERR_0001			"Failed to load the server list for unknown reason.\nPlease check the config file."
	#define STR_MSG_STOPBTN_YESNO		"Do you really stop this server?"
	#define STR_MSG_CLOSING_CANCEL		"Can't stop because of running server."
	#define STR_CHECKBOX_TEXT			"Auto restart on crash"
	#define STR_BTN_RUNNING_TEXT		"\n- in running -"
	#define STR_CBTN_TEXT				"Stop"

#else
	#define STR_MSG_ERR_0001			"Failed to load the server list for unknown reason.\nPlease check the config file."
	#define STR_MSG_STOPBTN_YESNO		"Do you really stop this server?"
	#define STR_MSG_CLOSING_CANCEL		"Can't stop because of running server."
	#define STR_CHECKBOX_TEXT			"Auto restart on crash"
	#define STR_BTN_RUNNING_TEXT		"\n- in running -"
	#define STR_CBTN_TEXT				"Stop"

#endif