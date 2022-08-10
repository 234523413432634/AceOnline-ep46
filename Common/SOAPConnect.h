// SOAPConnect.h: interface for the CSOAPConnect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOAPCONNECT_H__3A5FDDED_C673_43B6_97D1_A77BB9105600__INCLUDED_)
#define AFX_SOAPCONNECT_H__3A5FDDED_C673_43B6_97D1_A77BB9105600__INCLUDED_

#if _MSC_VER > 1000
#pragma once

#endif // _MSC_VER > 1000


class CSOAPConnect
{
private:
public:
	CSOAPConnect();
	virtual ~CSOAPConnect();


	// SOAP 접속 처리 함수
	BOOL SOAP_Authentication(BSTR i_URLstring, BSTR i_WebMethodstring, BSTR i_ID, BSTR i_Password,BSTR i_GameID);
	
	// 2010-11-29 by shcho, 아르헨티나 외부인증 변경 SOAP 처리 - 형 변환 함수 사용 후에는 메모리 해제 필수!
 	BSTR	Char2bBSTR(char* i_asc);
	
	// END 2010-11-29 by shcho, 아르헨티나 외부인증 변경 SOAP 처리 - 형 변환 함수 사용 후에는 메모리 해제 필수!
};

#endif // !defined(AFX_SOAPCONNECT_H__3A5FDDED_C673_43B6_97D1_A77BB9105600__INCLUDED_)
