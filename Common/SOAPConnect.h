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


	// SOAP ���� ó�� �Լ�
	BOOL SOAP_Authentication(BSTR i_URLstring, BSTR i_WebMethodstring, BSTR i_ID, BSTR i_Password,BSTR i_GameID);
	
	// 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - �� ��ȯ �Լ� ��� �Ŀ��� �޸� ���� �ʼ�!
 	BSTR	Char2bBSTR(char* i_asc);
	
	// END 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - �� ��ȯ �Լ� ��� �Ŀ��� �޸� ���� �ʼ�!
};

#endif // !defined(AFX_SOAPCONNECT_H__3A5FDDED_C673_43B6_97D1_A77BB9105600__INCLUDED_)
