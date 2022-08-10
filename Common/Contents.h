#pragma once
//File has been reorganized and translated to humanish by Inetpub 17-07-2021 - added some comments how it works 

#if defined(_DEBUG)
#define _ATUM_DEVELOP										// 서버용) 서버소스상 디버깅일 때 활성화 해줘야 함
#endif

#define S_CAN_SERVER_SETTING_HSSON	//this remains here just for valid compiler profile setting validation

#if defined(_KOR)
#define KOR_YEDANG_WEB_LAUNCHER_HSSON				// 예당 웹런쳐
#define YEDANG_RELEASE								// 핵쉴드, 몇가지 기능 한국만 수행
#define S_ARARIO_HSSON								// used to strtok email to get first token as username
#define KOR_INPUT_LANGUAGE_HSSON					// 입력 언어 변환
#define KOR_HANGEUL_START_HSSON						// 한글 모드로 시작
#define KOR_CASHSHOP_INTERFACE_HSSON				// 캐쉬샵 인터페이스
#define KOR_GAME_RATINGS_HSSON						// 게임 등급물 위원회 아이콘 추가
#define KOR_CHARACTER_INTERFACE_POS_HSSON			// 언어에 따라 위치 수정
#include "Str_KOR/StringDefineCommon.h"
#include "Str_KOR/StringDefineServer.h"
#include "Str_KOR/StringDefineClient.h"
#endif

#if defined(_JPN)
#define LANGUAGE_JAPAN								// 일본에 기존에 사용하던 디파인
#define S_ARARIO_HSSON								// 아라리오 채널링
#include "Str_JPN/StringDefineCommon.h"
#include "Str_JPN/StringDefineServer.h"
#include "Str_JPN/StringDefineClient.h"
#endif

#if defined(_ENG)
#include "Str_CAN/StringDefineCommon.h"
#include "Str_CAN/StringDefineServer.h"
#include "Str_CAN/StringDefineClient.h"
#endif

#if defined(_RUS)
#include "Str_RUS/StringDefineCommon.h"
#include "Str_RUS/StringDefineServer.h"
#include "Str_RUS/StringDefineClient.h"
#endif

#if defined(_VIE)
#include "Str_VIE/StringDefineCommon.h"
#include "Str_VIE/StringDefineServer.h"
#include "Str_VIE/StringDefineClient.h"
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// predefinitions - checked by Inetpub
/***************************** NOT EXIST IN SOURCE ***********************************/
//#define S_LOGIN_ITEM_EVENT_SHCHO						    // Item event server sided (not used)
//#define S_OPTION_PARTNER__JHAHN							// commented content at client side , server sided non exist
//#define C_INTERFACE_RESOURCE_ORGANIZE_ISSHIN				// not exist in client and in server
//#define S_IMSI_MONSTER_LOCKED_SHCHOI						// not exist in client and in server
//#define C_USER_EFFECT_CONTROL								// used other way (on/off)
//#define C_USER_COPYPAST_JHSHN								// not exist in client and in server
/******************************** DISABLED *******************************************/
/*#if defined(TEST140) || defined(YEDANG_KOR)
#define KOR_INPUT_LANGUAGE_HSSON							// 입력 언어 변환
#define KOR_HANGEUL_START_HSSON								// 한글 모드로 시작
#define KOR_CASHSHOP_INTERFACE_HSSON						// 캐쉬샵 인터페이스
#define KOR_GAME_RATINGS_HSSON								// 게임 등급물 위원회 아이콘 추가
#define KOR_CHARACTER_INTERFACE_POS_HSSON					// 언어에 따라 위치 수정
#define KOR_YEDANG_WEB_LAUNCHER_HSSON						// 예당 웹런쳐
#endif*/
//#define S_ARARIO_HSSON									// used to strtok email to get first token as username
//#define C_CASHSHOP_IMAGE_REMOVE							// ItemShop:: remove GIFT button
//#define C_CASH_SHOP_CHARGE_NOT_USE_JWLEE					// ItemShop:: remove REFILL button
//#define S_AUTHENTICATION_SERVER_HSKIM						// Enable Auth Server (preserver will require auth server validation to start)
////#define S_AUTHENTICATION_SERVER_2ND_HSKIM				// Enable extended Auth Server
//#define SC_SECURITY_COMMAND_HSKIM							// Enable masang command to take down server (lol)
//#define C_SECURITY_COMMAND_JHAHN							// Client sided security command
//#define S_ACCESS_INTERNAL_SERVER_HSSON					// Connect to test server (TESTSERVER_LAUNCHER_WEB_URL in launcher and other IP in LocalizationDefineCommon.h)
//#define S_EP4_TEST_SERVER_HSKIM							//change IP to 127.0.0.1 in Launcher & PreLauncher
//#define S_AUTO_UPDATE_VERSION_BY_PRESVR_HSSON				// Load version info from HTTP server instead of version.ver from config (requires proper .ver files on update server)
//#define _USING_INNOVA_FROST_								// Frost game guard
//#define CUSTOM_OPTIMIZER_HSSON							// ini configs for freak things
//#define MULTI_LOADER_HSSON								// allow multiple client instances
//#define GAMEGUARD_NOT_EXECUTE_HSSON						// dont start game guard
//#define S_GLOG_HSSON										// GLog on off
//#define S_GLOG_1ST_BCKIM									// GLog 1st stage
//#define S_GLOG_2ND_HSKIM									// GLog 2nd stage
//#define S_GLOG_3ND_KHK									// GLog 3rd stage
//#define S_KOR_TEST_GLOG_CHARDATA							// test char data by glog
//#define SC_SHUT_DOWNMIN_SHCHO								// "Players under the age of 16 cannot play from 12 A.M. to 6 A.M. by the regulation of the juvenile protection."
//#define C_OBJECT_RESOURCE_ORGANIZE_MSPARK					// print all loaded objects to ftext file )objectdata monsterdata
//#define S_SELECTIVE_SHUTDOWN_HSKIM						// remote server shutdown
//#define SC_SHUT_DOWNMIN_JHAHN								// another age limitation feature (suppose for koreans)
//#define S_NPLAY_PCBANG_MODULE_JHSEOL						// Korean NPlay feature - another pay per play
//#define S_WEB_CASHSHOP_SERVER_MODULE_HSKIM				// client open website instead of ingame cash shop
//#define C_MASANG_WEB_CASHSHOP								// client open website instead of ingame cash shop
//#define SC_WEB_CASHSHOP_SSJUNG_JHSEOL						// client open website instead of ingame cash shop
//#define S_B_GEAR_DAMAGE_PROBABILITY_INFO					// Logging BG proxy if possible to hit player
//#define C_CLIENT_FILE_LOG									// Client logging to file
//#define S_DISABLE_ALONE_RUN_MODE_HSKIM					// Mutex check for server binaries
//#define C_FIRST_ANNIVERSARY_EVENT							// text event
//#define S_ALL_MONSTER_KILL_LOG							// log all monsters dead
//#define S_USE_SKILL_LOG_JEKIM								// skill usage log
//#define S_TEMP_RESTRICTION_ITEMEVENT_PYLONES_SERVER		// if mgame serverid 10066 then dont give item event
//#define S_DISABLE_PREPARE_SHUTDOWN						// disable prepare shutdown
//#define C_ADMINISTRATOR_COPYPASTE_PERMISSION				// allow only admins to copy paste
//#define C_COLLECTION_ARMOR_NO_STAT					    // dont add stats from collection
//#define S_ADMIN_CHARACTER_LOGIN_IP_CHECK					// check Allowed IP in T_FC_GAMESTART for every account with 130 type
//#define S_KOR_BUSAN_MONITORTOOL_MAKE						// korean settings for AtumParamProtocol - not really usefull for anyone else than masangs
//#define S_BPSOFTBILLING_JHSEOL							// enable billing for masang
//#define SC_BUGTRAP_BCKIM_SSJUNG							// bugtrap support - need to configure and prepare all to use this first!
//#define S_MANAGER_ADMIN_HSSON								// partially disable functionality of Admin Tool for users with 256 account type (GM)
//#define S_ARENA_NOT_INFO									// disable checking if ArenaInfo.State is not equal to ARENA_STATE_NONE
//#define C_ARENA_PASSWORD_ALPHABET							// only letters for arena password
//#define SC_XTRAP_VTC_GAMEGUARD_BHSOHN_JHSEOL				// XTRAP anticheat
//#define S_HACK_SHIELD_AUTO_UPDATE_HSKIM					// HShield with autoupdate
//#define C_USER_CTRL_KEY_LOCK								// users cannout use CTRL key
//#define S_GAMEFORGE_KEY_CHANGE_JHSEOL						// change xor keys to GF
//#define S_TEMP_PRESERVER_MAKE_HSKIM						// temporary PreServer without db connection
//#define TEMP_PRESERVER_MAKE_IP		"182.162.137.2"		// IP for temp preserver
//#define SC_ARENA_EX_1ST_RESTORE_JHSEOL_MSPARK				// dont use level restrictions and arena slots
//#define S_ARENA_EX_GAMEFORGE_VERSION_JHSEOL				// GF Arena variance
//#define S_EP4_DEBUG_HSKIM									// Logging of protocols
//#define S_DISABLE_CHECKSUM_RESOURCE						// disable server side checksum checking (if in use check CHECK_SUM_ON)
//#define S_CHANNELING_LAUNCHER_SERVER_FILTER				// use order in launcher and filtering by servername
//#define SC_CHANNELING_JHSEOL_BCKIM_SSJUNG					// use tokens, certs and chanels for users
//#define S_ITEMUID_ZERO_DEBUG_LOG_JHSEOL					// debug log for SPI items - logging only
//#define C_GM_MESSAGE_BOX_ENTER_YMJOO						// only GM can use enter to fast write in chat
//#define S_DELETE_BUY_CASH_GIVE							// disable gifts (server side)
//#define ONLY_FULL_WINDOW_HSSON							// possible to play only full screen

// Ep 4-2
#define EP402
// Ep 4-3
#define EP403
// Ep 4-4
#define EP404
// Ep 4-5
#define EP405
// Ep 4-6
#define EP406

// Ep 4-2 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Ep 4-2 //
#if defined(EP402)
#define C_MOUSEFOCUS_BACKGROUND_NOTRESET					//better mouse handling
#define C_USER_SCREENSHOTMODE_ISSHIN						// allow users to make SS
#define S_BONUSEXPSYSTEM_RENEWAL							// Bonus exp feature for killing monsters (right side counter)
#define S_ADDITIONAL_EXPERIENCE								// Save additional exp at game end
#define SC_BUFF_PENALTY_JHSEOL_BCKIM						// BUFF penalty feature (251 des param)
#define GUILD_WAREHOUSE_ACCESS_HSSON						// allow using guild wh
#define NEW_CASHSHOP_INTERFACE_HSSON						// ItemShop:: used to enable GIFT button NOTE! if C_CASHSHOP_IMAGE_REMOVE is defined then gift button would be disabled
//#define KOR_CASHSHOP_REFILL_WEB_HSSON						// ItemShop:: Show refill button if defined YEDANG_RELEASE ItemShop will be disabled NOTE! Changed by Inet - when defined C_CASH_SHOP_CHARGE_NOT_USE_JWLEE it will not be shown
#define WAREHOUSE_SHARES_HSSON								// allow shared wh between characters on the same account (tabs in wh)
#define SC_GROWING_PARTNER_HSKIM_JHAHN						// allow PET leveling
#define S_INFINITY1_HSKIM									// Enable IF1 - switch added by Inetpub
#define S_INFINITY2_HSKIM									// Enable IF2 - switch added by Inetpub
#define S_INFINITY3_HSKIM									// Enable IF3
#define INFI_QUEST_JSKIM								    // Enable IF3 Quests
#define MULTI_TARGET_JSKIM									// Monster multi target (Enable load from OMI.tex by client)
#define S_EP4_HSKIM											// EP4 fetures : map trigger, bonus exp in burning map system, DES_ENCHANT_ONCE_APPLY enable, DES_SKILL_STOPMAGIC enable, DES_GAMBLE_RARE_ITEM_FIX (f2p), trigger map buffs, systemevent (m_OpeningMovieStandard)
#define S_STATISTICS_HSKIM									// Statistics of server (StatisticsManager enable) - you can review it in Statistics Manager (admin tool, dbtool)
#define S_DELETE_DROP_ITEM_HSKIM							// Delete drop that is hanging on map after time defined in TICKGAP_DROP_ITEM_TIMEOUT (AtumParam.h)
#define CHECK_SUM_ON										// Check files: client executable, omi.tex, interface.tex, quest.tex , Res-Obj and all .dat files from res-map
#define C_EPSODE4_UI_CHANGE_JSKIM							// Change interface to EP4
#define C_EPSODE4_SETTING_JHAHN								// Bigger city maps (minimap handling) & FX
#define S_MINI_DUMP_HSKIM									// server side dump files
#define SC_DARK_CRASH_HSSON									// Dark crash feature
#define SC_DARK_CRASH_FILE_OUTPUT_HSSON						// Dark crash output file generation feature
#define S_GM_COMMAND_USE_SHCHO								// forbid using admin only command(not used normally) from ingame
#define S_LAUNCHER_USE_ID_PASSWORD_HSKIM					// Use id & password in launcher
#define S_MS_WAR_FIN_SUPPLY_ITEM_ADD						// 7037060 add to all users after ms
#define S_FULL_LOG_JHSEOL									// Full log to DB
#define S_DB_FULL_LOG_JHSEOL								// Extended log to DB
#define SC_ITEM_VIEW_UNCONDITIONAL_ON_JHSEOL				// show ItemInfo of every user no matter or privacy setting (users cannot disable item preview)
#define S_REMANING_PROCESS_REMOVE_MSPARK					// delete currently opened launcher.atm (here Updater.exe) - usefull when it will remain opened by bug
#define SC_ARENA_EX_1ST_JHSEOL_MSPARK						// Enable EP4 Arena
#define C_UI_REPAIR_ISSHIN									// Fix for UI In Character Info
#define SC_ENEMY_INFO_JHSEOL_ISSHIN							// Enable Enemy item info preview by alt+click > ItemInfo
#define S_TIMEITEM_LOG_HIDE_JHSEOL							// Hide logs for time items (reduce spam)
#define S_ARENA_SUPPLY_ITEMNUM4								// 4th supply item on Arena
#define S_ADMINTOOL_ENCHANT_DELETE_MODIFY_BCKIM				// Enchanced enchanting by AdminTool
#define C_WAR_SYSTEM_RENEWAL_STRATEGYPOINT_JHSEOL			// Treat SP/MS/AB as influence war
#define SC_SEARCHEYE_SHUTTLE_POSITION_JHSEOL_MSPARK			// Search Eye scanning area would fly with player
#define SC_PARTNER_SHAPE_CHANGE_HSKIM						// PET contours
#define S_KOR_TEST_MSWAR_BACK_TO_CITY_HSKIM					// Return users from influence maps when MS starts
#endif
// end Ep 4-2

// Ep 4-3 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Ep 4-3 //
#if defined(EP403)
#define C_JOIN_CHATROOM_MESSAGE								// Enable "%s joined the chat room." message 
#define	S_TRIGGER_OUTPOST_JHSEOL							// 4th outpost (trigger)
#define S_ADMINTOOL_CASHSHOP_REALIGNMENT_BCKIM				// Change positions of ItemShop items by admin tool dialog enable
#define C_INGAME_MIX_ITEM									// Enable new factory and preview for item mixing 
#define SC_ITEM_EVENT_RETURN_USER_BCKIM_BHSOHN				// Gift receivied button
#define SC_SKILL_NUMBERING_RENEWAL_JHSEOL_BHSOHN			// Better skill organization
#define S_ITEM_EVENT_SUB_TYPE_JHSEOL						// Enable itemevent des params
#define S_MONTHL_CASH_BUY_GIFT_JHSEOL						// Enable another option for ItemEvent - gift for buy gift 1/month
#define C_ITEM_EVENT_NOTIFY_MSG_CHANGE_JHSEOL				// Enable "Gift has arrived. Please click the present box button on your right." message
#define S_MONTHL_ARMOR_EVENT_JHSEOL_BCKIM					// Monthly armor event enable
#define SC_UPGRADE_INFLUENCE_POINT_HSKIM_BHSOHN				// Upgrade infl points - consecutive victories and statues
#define SC_COLLECTION_ARMOR_JHSEOL_BCKIM					// Contour collection enable
#define S_TRIGGER_SYSTEM_EX									// 6000,7000 trigger id enable 
#define C_MONTHLY_ARMOR_ADD_CHANGE							// Special buff duration text add
#define S_GIVE_EVENT_ITEM_AT_TIME_BCKIM						// Added option in Set Item Event (admin tool) to give gift at specified time
#define C_AUTO_USE_KIT_SOCKET_ADD_SP_KIT_D					// Automatically use kit socket in PET
#endif
// end Ep 4-3

// Ep 4-4 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Ep 4-4 //
#if defined(EP404)
#define SC_RENEWER_HAPPY_HOUR_BHSOHN_BCKIM					// extended HH: energy, shield,sp recovery,weapon ench prob,armor enchant prob, radar&engine enchant prob,spi shop discount, wp shop discount
#define SC_STRATEGYPOINTWAR_RENEWAL_JHSEOL_SSJUNG			// show SP as ms on top
#define SC_BOSS_MONSTER_REWARD_BCKIM_SSJUNG					// Boss monster rewards extended and info about killed boss added
#define S_UPGRADE_INFLUENCE_POINT_RENEWAL_JHSEOL			// Extended influence point rating
#define C_WARNING_APPEARANCE_CHANGE							//"Applying a new contour kit will replace the existing contour kit. Are you sure you want to replace it?" message when contour appling
#define SC_PVPBUFF_COMBAT_POWER_JEKIM_SSJUNG				// PVP combat buff
#define SC_UNBALANCED_FORCES_ADJUST_RATIO					// unbalance adjust
#define SC_UNBALANCED_FORCES_ADJUST_SHOW_INFLUNCE_INFO		// show info about balance
#define SC_UNBALANCED_FORCES_ADJUST_SPLEVEL_MAX				// SP LEVEL 10 to 20
#define C_AGEAR_REFINERYSHOP_CLOSE_MSPARK					// close refill shop (pad menu) when AG is movin on it
#define C_CHECK_COLL_MAP									// Better map collisions check
#define C_SHUTTLE_WING_COLL_ADD_REFLECT						// Wing collisions
#endif
// Ep 4-4

// Ep 4-5 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Ep 4-5 //
#if defined(EP405)
#define S_COMBAT_POWER_LOGGING								// CombatPower log & command
#define S_COMBAT_POWER_LOGGING_DEBUG						// Additional log print
#define SC_WORLDCUP_EVENT_MAP_CHANNEL_INCREASES				// 4190 map will have more channels as it will be treated as multichannel map
#define C_TERRAIN_EFFECT_DETAIL_ON_OFF_YMJOO				// Enable option to ON/OFF terrain details
#define C_FONT_COLOR_ADD									// add p:pink, t:lightgreen, l:black colors for chat
#define SC_MARKET_JHSEOL_BCKIM_SSJUNG						// Added Trade Center
#define C_REMOVE_VOIP_YMJOO									// Remove VOIP chat
#define C_CHATROOM_MEMBER_LEVEL_YMJOO						// Show char level in chat room
#define C_PARTY_MEMBER_GEAR_YMJOO							// Show Gear in party
#define SC_MARKET_NOT_USE_NORMAL_INFL						// Dissallow normal infl from using trade center
#define S_SERVER_CRASH_FILENAME_ADD_INFO					//add info to dmp files on server bins
#endif
// Ep 4-5

// Ep 4-6 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Ep 4-6 //
#if defined(EP406)
#define C_WORLD_MAP_SSJUNG_YMJOO							// World map with descriptions etc
#define C_CLIENT_LIVE_TIME									// Enter lock after non response (default 3s)
#define C_LONGTIME_WINDOW_ON								// when client is opened really long time reset counter to avoid overflow
#define S_AUTO_BLOCK_SYSTEM_HSKIM							// block by autoblocksystem for obvious memory hack (mss detection)
#define S_BUGFIX_DUPLICATE_ITEM_HSKIM						// server side bugfix (masangs -.-)
#define S_ALLOWED_IP_RELOAD_JHSEOL							// allow reload AllowedToolIP config (usefuull if ynamic ip used for admin tool)
#define C_ABUSE_FILTER_RELAX								// softer bad word filter
#define C_SHOP_ITEMCNT_INIT_BHSOHN							// Client side bugfix for currently selected item in shop reopen
#define S_ADMINTOOL_IP_SEARCH_JHSEOL						// better search by ip in admin tool
#define S_CANNOT_DO_GIFT_UNDER_LEVEL_BCKIM					// cannot send gift if your level smaller than 70 (hardcoded as masang)
#define C_LEAST_LV_GIFT										// "You must be at least level 70 to send gifts." message in client
#define C_DECA_TOOLTIP										// tooltips for newbies
#define GAMEFORGE4D_CHAT_MACRO_OUTPUT_TIME					// if defined text macro time is 300s else 15s
#define S_MULTI_RESOLUTION_JHSEOL 							// add current player resoultion to list
#define S_QUEST_MISSION_FREE_PASS_BCKIM						// mission complete pass to finish currently opened quest
#define C_LEAST_LV_ARENA									// "You must be at least level 25 to use the Arena." lock for lower than 25 lv from arena usage
#define C_INVEN_SPIWP_TOOLTIP								// tooltips for spi and wp on hover
#define C_ENGINE_ENCHANT_WARNING							// show warning when enchanting engines
#define S_MSWAR_CALLOFHERO_SKILL_JEKIM						// cannot coh 60s before ms start
#define C_DATE_SHORT_FORM									// shorter date representation ingame - changed by inet to ex. 17-Jul-2021
#define C_NOT_COLOR_TEXT									// dont use colors in notice
//#define C_END_GAME_STATE_FADE_OUT_AUTO_CANCEL_YMJOO			// auto close game after fade out effect
#define S_SERVER_CRASH_MSGBOX_REMOVE_MSPARK					// Remove messagebox when server crashed with xc005 (stay defined for auto reboot)
#define SC_DESTROY_AUCTION_JHSEOL_BCKIM_SSJUNG				// Destroy auction feature
#define C_CAPSULE_CASH_ITEM_MESSAGE_YMJOO					//"Once you open %s, exchange or refund will not be available.\\nWould you still like to open it?"
#define C_DUMP_FILE_NAME_CURRENT_TIME_YMJOO					// dmp file name with datetime
#define	C_CASH_SHOP_TOOLTIP_DETAILS_YMJOO					// extended tooltips in cash shop
#define S_LOADING_PROGRESSBAR_JEKIM							// Progressbar for server side (loading of server)
#define C_RESOURCE_FILE_ERROR_CLOSE_YMJOO					// show resource error for admins
#define S_BOSS_MONSTER_DAMAGE_LOG_BY_SP_MS_OP				// log damage of influence monsters damage
#define C_NOTICE_MESSAGE_STRING_CULLING_YMJOO				// culling for notices and speakers
#define C_CHANGE_WEAR_ITEM_COOLTIME_YMJOO					// show "Reuse Time: %.2fs"
#define C_FRAME_MOVE_LAST_ELAPSED_TIME_YMJOO				// better lost device detection
#define C_PROFILER_YMJOO									// open profiler when push insert button
#define C_DRAWTEXT_UPGRADE_YMJOO							// better getstring size
#define C_TUTORIAL_SPEED_YMJOO								// predefined 260 speed for tutorial
#define C_MINIMAP_SIGHT_IMG_YMJOO							// show fov at minimap
#define SC_PREMIUM_COLLECTION_ARMOR_YMJOO_BCKIM				// premium armor collecion
//#define C_GAME_SINGLE_THREAD_YMJOO							// single threaded game
#define SC_INCREASE_BULLETS_OF_ADVANCED_WEAPONS_BY_EFFECT	// 20% more bullets when effect applied
#define C_SYSTEMMSG_BACK_INF_NO_MOUSE_EVENT					// mouse behavior fixed for sys window msg box
#define SC_OLD_COLLECTION_ARMOR_SHCHOI						// DES_OLD_OPTION_ITEM_DEFAULT_DESPARAM enable handler
#define C_QUICKSLOT_CHECK_DESPARAM_JWLEE					// check item if can be registered on quickslot by desparam
#define S_WARP_INVINCIBLE_SHCHOI							// invincible just after warping
#define C_LABORATORY_UI_CHANGE_JWLEE						// animated labo
#define SC_ANTI_HACKING_CODE_BCKIM_JWLEE					// anticheat by masang (packet filter)
#define S_INFO_ENCHANT_RESULT_DISPLAY						// display enchant result during enchanting
#define SC_LEVEL_EXPANSION_115_BCKIM_JWLEE					// 115level is max
#define SC_IMPROVED_BALANCE_OF_POWER_BCKIM_JWLEE			// balancing solution (combat port for over 100 levels)
#define C_BAZZER_NOT_EXIT									// dont exit game if have bazar (personal shop) opened
#define C_FOCUS_MISS_CLIENT_NO_CLOSE						// alt tab client wont close itself (only if inactivity check will kick off)
#define SC_HACKSHIELD_REMOVE_JHSEOL_JHAHN					// dont use hackshield
#define S_ATUM_EXE_INSTALLPATH_REGISTRY_DELECT				// prelauncher registry path dont create
#define C_FALL_OF_BOOSTER_USE_STOP_MSPARK					// falling when not using booster
#define S_ACCLAIM_OF_VICTORY_JEKIM							// Leveling SP and Turn Around buff enable according to consecutive victories
//#define S_DIRECT_DB_ITEM_INSERT_SECURITY_HSKIM				// directly insert items to db for saefty when server fall (usage of storeextension)
#define C_SERVER_DOWN_ALARM									// play alarm when server fall down instead of brutl message and game exit
#define S_AUTO_BLOCK_REATTACKETIME_EXCEPT_JHSEOL			// dont ban re attack time pseudo hack due to bug
//#define _SHOW_LATENCY
#endif

#ifdef _ATUM_CLIENT
//#define _DBG_INFO
#define _WIREFRAME
#define _NOCLIP
#define _DRAW_EVENTS
#define _ENHANCED_MIXING_DISPLAY
#define _DISABLE_BSTOP_AUTOHORIZONT
#define _INSTANT_LAUNCH
#define _NO_FADE
#endif





