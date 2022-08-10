#include "StdAfx.h"
#include "DefineMap.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace msclr::interop;


//////////////
/// ������ ///
//////////////
CDefineMap::CDefineMap(System::String^ filePath)
{
	m_filePath = msclr::interop::marshal_as<std::string>(filePath);
}

//////////////////////////////
/// ���� �а� #define ���� ///
//////////////////////////////
int CDefineMap::ReadAllFile()
{
	System::String^ filePath = gcnew String(m_filePath.c_str());
	if(!File::Exists(filePath))
	{
		SAFE_DELETE(filePath);
		return _READ_FILE_FILE_PATH_ERROR;
	}

	StreamReader^ sr = gcnew StreamReader (filePath, System::Text::Encoding::Default);
	SAFE_DELETE(filePath);

	try
	{
		while( sr -> Peek() >= 0 )
		{
			_ReadLine( sr -> ReadLine() );
		}
	}
	catch (Exception^)
	{
		return _READ_FILE_UNDEFINED_ERROR;
	}
	finally
	{
		SAFE_DELETE(sr);
	}
	
	return _READ_FILE_NORMAL;
}

////////////////////////////
/// �� �а� #define ���� ///
////////////////////////////
void CDefineMap::_ReadLine(System::String^ lineStr)
{
	// 2013-11-28 by ymjoo ��� ���ڿ��� std::string���� ����
	m_sReadLineKey = "";
	m_sReadLineMapSecondAllString = "";
	m_sReadLineMapSecondKeyString = "";
	m_sReadLineTempString = "";
	m_nReadLineTempStringCnt = 0;

	m_ReadLineFindStep = _FIND_STEP_FIND_DEFINE;
	m_ReadLineLastFindStep = _FIND_STEP_FIND_DEFINE;

	marshal_context context;
	m_sReadLineLineString = context.marshal_as<std::string>(lineStr);
	m_nReadLineCnt = -1;
	m_bReadLineEndLoop = false;

	while( m_sReadLineLineString.c_str()[++m_nReadLineCnt] && !m_bReadLineEndLoop )
	{
		if( _FIND_STEP_COMMENT != m_ReadLineFindStep )
		{
			if( _ReadLine_CheckCommentStart() )
			{
				continue;
			}
		}

		switch( m_ReadLineFindStep )
		{
		case _FIND_STEP_FIND_DEFINE:
			_ReadLine_FindDefineStep();
			break;

		case _FIND_STEP_PRE_IDENTIFIER:
			_ReadLine_PreIdentifierStep();
			break;

		case _FIND_STEP_IDENTIFIER:
			_ReadLine_IdentifierStep();
			break;

		case _FIND_STEP_PRE_TOKEN:
			_ReadLine_PreTokenStep();
			break;

		case _FIND_STEP_TOKEN:
			_ReadLine_TokenStep();
			break;

		case _FIND_STEP_COMMENT:
			_ReadLine_CommentStep();
			break;
		}
	}
	
	////////////////////////////////
	/// #define�� ã�� ��� ���� ///
	////////////////////////////////
	_ReadLine_PushMapData();
}

///////////////////////////////////////////////////////////////////
/// this�� �ٸ� CDefineMap�� str2�� �ٸ� ���� ����Ʈ�� �����Ѵ� ///
///////////////////////////////////////////////////////////////////
int CDefineMap::GetErrorList(std::list<ErrorListMapData>* errorList, CDefineMap* object)
{
	int thisSize = GetMapSize();
	int objectSize = object -> GetMapSize();

	if( 0 == thisSize * objectSize )
	{
		return _GET_ERROR_LIST_NO_DEFINE_FILE;
	}

	MAP::iterator iter;
	for(iter = m_map.begin() ; m_map.end() != iter ; ++iter)
	{
		MAP::iterator objectIter = object -> FindIter(iter -> first);
		
		/// ����� this�� ������, object�� ���� ///
		if( object -> FindEndIter() == objectIter )
			continue;

		/// ����� this�� object���� ���� �ٸ� ///
		std::string iterStr2 = iter -> second.keyString;
		std::string objectStr2 = objectIter -> second.keyString;
		if( iterStr2 != objectStr2 )
		{

			ErrorListMapData errorData;
			errorData.key = iter -> first;
			errorData.file1AllString = iter -> second.allString;
			errorData.file1KeyString = iter -> second.keyString;
			errorData.file2AllString = objectIter -> second.allString;
			errorData.file2KeyString = objectIter -> second.keyString;
			
			errorList -> push_back(errorData);
		}
	}
	return _GET_ERROR_LIST_NORMAL;
}

////////////////////////////////////
/// ReadLine Check Comment Start ///
////////////////////////////////////
bool CDefineMap::_ReadLine_CheckCommentStart()
{
	if( '/' == m_sReadLineLineString.c_str()[m_nReadLineCnt] )
	{
		if( '/' == m_sReadLineLineString.c_str()[m_nReadLineCnt + 1] )
		{
			m_bReadLineEndLoop = true;
		}

		else if( '*' == m_sReadLineLineString.c_str()[m_nReadLineCnt + 1] )
		{
			++m_nReadLineCnt;
			m_ReadLineLastFindStep = m_ReadLineFindStep;
			m_ReadLineFindStep = _FIND_STEP_COMMENT;
		}
		return true;
	}
	return false;
}

/////////////////////////////////
/// ReadLine Find Define Step ///
///          #define          ///
/////////////////////////////////
void CDefineMap::_ReadLine_FindDefineStep()
{
	if( ' ' == m_sReadLineLineString.c_str()[m_nReadLineCnt] || '\t' == m_sReadLineLineString.c_str()[m_nReadLineCnt] )
	{
		return;
	}

	else if( '#' == m_sReadLineLineString.c_str()[m_nReadLineCnt] )
	{
		char define[] = "define";
		for(int i = 0 ; i < ARRAY_SIZE(define) - 1 ; ++i)
		{
			if( m_sReadLineLineString.c_str()[++(m_nReadLineCnt)] != define[i] ) 
			{
				break;
			}
		}

		++m_nReadLineCnt;
		if( ' ' != m_sReadLineLineString.c_str()[m_nReadLineCnt] && '\t' != m_sReadLineLineString.c_str()[m_nReadLineCnt] )
		{
			m_bReadLineEndLoop = true;
			return;
		}

		m_ReadLineFindStep = _FIND_STEP_PRE_IDENTIFIER;
	}

	else 
	{
		m_bReadLineEndLoop = true;
	}
}

////////////////////////////////////
/// ReadLine Pre-Identifier Step ///
///       #define ( ) A B        ///
////////////////////////////////////
void CDefineMap::_ReadLine_PreIdentifierStep()
{
	if( ' ' == m_sReadLineLineString.c_str()[m_nReadLineCnt] || '\t' == m_sReadLineLineString.c_str()[m_nReadLineCnt] )
	{
		return;
	}

	else
	{
		m_ReadLineFindStep = _FIND_STEP_IDENTIFIER;
		--m_nReadLineCnt;
	}
}

////////////////////////////////
/// ReadLine Identifier Step ///
///      #define (A) B       ///
////////////////////////////////
void CDefineMap::_ReadLine_IdentifierStep()
{
	if( ' ' == m_sReadLineLineString.c_str()[m_nReadLineCnt] || '\t' == m_sReadLineLineString.c_str()[m_nReadLineCnt] )
	{
		m_ReadLineFindStep = _FIND_STEP_PRE_TOKEN;
	}

	else
	{
		m_sReadLineKey += m_sReadLineLineString.c_str()[m_nReadLineCnt];
	}
}

///////////////////////////////////
///   ReadLine Pre-Token Step   ///
///       #define A ( ) B       ///
/// B�� " something " �� ��츸 ///
///////////////////////////////////
void CDefineMap::_ReadLine_PreTokenStep()
{
	if( ' ' == m_sReadLineLineString.c_str()[m_nReadLineCnt] || '\t' == m_sReadLineLineString.c_str()[m_nReadLineCnt] ) 
	{ return; }

	else if( '\"' == m_sReadLineLineString.c_str()[m_nReadLineCnt] ) 
	{ m_ReadLineFindStep = _FIND_STEP_TOKEN; }

	else
	{ m_bReadLineEndLoop = true; }
}

///////////////////////////
/// ReadLine Token Step ///
///    #define A (B)    ///
///    " something "    ///
///////////////////////////
void CDefineMap::_ReadLine_TokenStep()
{
	if( '\"' == m_sReadLineLineString.c_str()[m_nReadLineCnt] )
	{
		m_bReadLineEndLoop = true;
	}

	else if( '\\' == m_sReadLineLineString.c_str()[m_nReadLineCnt] )
	{
		m_sReadLineMapSecondAllString += '\\';
		m_sReadLineMapSecondAllString += m_sReadLineLineString.c_str()[++m_nReadLineCnt];
	}

	else if( '%' == m_sReadLineLineString.c_str()[m_nReadLineCnt] )
	{
		m_sReadLineMapSecondAllString += '%';

		if( '%' == m_sReadLineLineString.c_str()[m_nReadLineCnt + 1] )
		{
			m_sReadLineMapSecondAllString += '%';
			++m_nReadLineCnt;
		}
		else
		{
			m_sReadLineTempString += '%';
			++m_nReadLineTempStringCnt;

			while( _IsFormatStreamChar(m_sReadLineLineString.c_str()[m_nReadLineCnt + 1]) )
			{
				++m_nReadLineCnt;

				m_sReadLineMapSecondAllString += m_sReadLineLineString.c_str()[m_nReadLineCnt];

				m_sReadLineTempString += m_sReadLineLineString.c_str()[m_nReadLineCnt];
				++m_nReadLineTempStringCnt;

				if( _IsFormatStreamEndChar(m_sReadLineLineString.c_str()[m_nReadLineCnt]) )
				{
					for(int i = 0 ; i < m_nReadLineTempStringCnt ; ++i) 
					{ 
						m_sReadLineMapSecondKeyString += m_sReadLineTempString.c_str()[i];
					}
					break;
				}
			}

			m_sReadLineTempString = "";
			m_nReadLineTempStringCnt = 0;
		}
	}

	else
	{
		m_sReadLineMapSecondAllString += m_sReadLineLineString.c_str()[m_nReadLineCnt];
	}
}

/////////////////////////////
/// ReadLine Comment Step ///
///    /* something */    ///
/////////////////////////////
void CDefineMap::_ReadLine_CommentStep()
{
	if( '*' == m_sReadLineLineString.c_str()[m_nReadLineCnt] && '/' == m_sReadLineLineString.c_str()[m_nReadLineCnt + 1] )
	{
		++m_nReadLineCnt;
		m_ReadLineFindStep = m_ReadLineLastFindStep;
	}
}

////////////////////////////////
/// #define�� ã�� ��� ���� ///
////////////////////////////////
void CDefineMap::_ReadLine_PushMapData()
{
	if( m_sReadLineKey.c_str()[0] )
	{
		MapData newData;
		newData.allString = m_sReadLineMapSecondAllString;
		newData.keyString = m_sReadLineMapSecondKeyString;
		m_map.insert( MAP::value_type(m_sReadLineKey, newData) );
	}
}

////////////////////////////////////////////////////////////////
/// %.2d ���� '.' '2' 'd' �� ���˽�Ʈ���� �������� ���� �˻� ///
////////////////////////////////////////////////////////////////
bool CDefineMap::_IsFormatStreamChar(char ch)
{
	if( ( 'a' <= ch && ch <= 'z' ) ||
		( 'A' <= ch && ch <= 'Z' ) ||
		( '0' <= ch && ch <= '9' ) ||
		( '.' == ch ) )
	{
		return true;
	}

	return false;
}

////////////////////////////////////////
/// %d ���� ���˽�Ʈ���� ������ �˻� ///
////////////////////////////////////////
bool CDefineMap::_IsFormatStreamEndChar(char ch)
{
	const char formatStreamEndChar[] = { 'c', 'd', 'i', 'f', 'F', 'e', 'E', 'g', 'G', 's', 'p', 'u', 'o', 'x', 'X', 'n' };
	for(int i = 0 ; i < ARRAY_SIZE(formatStreamEndChar) ; ++i)
	{
		if( formatStreamEndChar[i] == ch )
		{
			return true;
		}
	}

	return false;
}