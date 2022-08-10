#pragma once
#include <map>
#include <list>
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>
#include <iostream>
#include <string>

//#define MAX_LEN		1024				// 2013-11-28 by ymjoo 모든 문자열을 std::string으로 변경
#define MAP			std::map<std::string, MapData>
#define _FIND_STEP	int

// 2013-11-28 by ymjoo 모든 문자열을 std::string으로 변경
/*
#define _READLINE_DATA_PARAM_SET_RECEIVE	char* key, char* mapSecondAllString, char* mapSecondKeyString, char* tempStr, \
											int* keyCnt, int* mapSecondAllStringCnt, int* mapSecondKeyStringCnt, int* tempStrCnt, \
											_FIND_STEP* step, _FIND_STEP* lastStep, const char* lineString, int* cnt, bool* endLoop
#define _READLINE_DATA_PARAM_SET_SEND		key, mapSecondAllString, mapSecondKeyString, tempStr, \
											&keyCnt, &mapSecondAllStringCnt, &mapSecondKeyStringCnt, &tempStrCnt, \
											&step, &lastStep, lineString, &cnt, &endLoop
*/
#define ARRAY_SIZE(arr)				sizeof(arr) / sizeof(arr[0])
//#define INIT_CHAR_ARRAY(target)		for(int i = 0 ; i < ARRAY_SIZE(target) ; ++i) target[i] = NULL
// END 2013-11-28 by ymjoo 모든 문자열을 std::string으로 변경

#define SAFE_DELETE(target)			if(target) { delete target; target = nullptr; }

enum _READ_FILE_RETURN_CODE_ENUM
{
	_READ_FILE_NORMAL,
	_READ_FILE_FILE_PATH_ERROR,
	_READ_FILE_UNDEFINED_ERROR,
};

enum _FIND_STEP_ENUM
{
	_FIND_STEP_FIND_DEFINE,
	_FIND_STEP_PRE_IDENTIFIER,
	_FIND_STEP_IDENTIFIER,
	_FIND_STEP_PRE_TOKEN,
	_FIND_STEP_TOKEN,
	_FIND_STEP_COMMENT,
};

enum _GET_ERROR_LIST_RETURN_CODE_ENUM
{
	_GET_ERROR_LIST_NORMAL,
	_GET_ERROR_LIST_NO_DEFINE_FILE,
};

struct MapData
{
	std::string allString;
	std::string keyString;

};

struct ErrorListMapData
{
	std::string key;
	std::string file1AllString;
	std::string file1KeyString;
	std::string file2AllString;
	std::string file2KeyString;
};

class CDefineMap
{
public:
	CDefineMap(System::String^ filePath);

	int ReadAllFile();

	int GetErrorList(std::list<ErrorListMapData>* errorList, CDefineMap* object);

	int GetMapSize()						{ return m_map.size(); }
	MAP::iterator FindIter(std::string key)	{ return m_map.find(key); }
	MAP::iterator FindEndIter()				{ return m_map.end(); }

private:
	void _ReadLine(System::String^ lineStr);
	// 2013-11-28 by ymjoo 모든 문자열을 std::string으로 변경
	bool _ReadLine_CheckCommentStart();
	void _ReadLine_FindDefineStep();
	void _ReadLine_PreIdentifierStep();
	void _ReadLine_IdentifierStep();
	void _ReadLine_PreTokenStep();
	void _ReadLine_TokenStep();
	void _ReadLine_CommentStep();
	void _ReadLine_PushMapData();
	/* 
	bool _ReadLine_CheckCommentStart(_READLINE_DATA_PARAM_SET_RECEIVE);
	void _ReadLine_FindDefineStep(_READLINE_DATA_PARAM_SET_RECEIVE);
	void _ReadLine_PreIdentifierStep(_READLINE_DATA_PARAM_SET_RECEIVE);
	void _ReadLine_IdentifierStep(_READLINE_DATA_PARAM_SET_RECEIVE);
	void _ReadLine_PreTokenStep(_READLINE_DATA_PARAM_SET_RECEIVE);
	void _ReadLine_TokenStep(_READLINE_DATA_PARAM_SET_RECEIVE);
	void _ReadLine_CommentStep(_READLINE_DATA_PARAM_SET_RECEIVE);
	void _ReadLine_PushMapData(_READLINE_DATA_PARAM_SET_RECEIVE);
	*/
	// END 2013-11-28 by ymjoo 모든 문자열을 std::string으로 변경
	
	bool _IsFormatStreamChar(char ch);
	bool _IsFormatStreamEndChar(char ch);

private:
	MAP			m_map;
	std::string	m_filePath;

	// 2013-11-28 by ymjoo 모든 문자열을 std::string으로 변경
	std::string	m_sReadLineKey;
	std::string	m_sReadLineMapSecondAllString;
	std::string	m_sReadLineMapSecondKeyString;
	std::string	m_sReadLineTempString;
//	int			m_nReadLineKeyCnt;
//	int			m_nReadLineMapSecondAllStringCnt;
//	int			m_nReadLineMapSecondKeyStringCnt;
	int			m_nReadLineTempStringCnt;
	_FIND_STEP	m_ReadLineFindStep;
	_FIND_STEP	m_ReadLineLastFindStep;
	std::string	m_sReadLineLineString;
	int			m_nReadLineCnt;
	bool		m_bReadLineEndLoop;
	// END 2013-11-28 by ymjoo 모든 문자열을 std::string으로 변경
};