// SOAPConnect.cpp: implementation of the CSOAPConnect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PreGlobal.h"
#include "SOAPConnect.h"
// 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - include �߰�
#include <comdef.h>
#include <atlbase.h>
#include <exception>
#include <assert.h>
#include <cstring>
// END 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - include �߰�

#if defined(SERVICE_TYPE_ARGENTINA_SERVER_1)
#import <msxml4.dll>
#import "c:\Windows\System32\mssoap30.dll" named_guids exclude("IStream", "IErrorInfo", "ISequentialStream", "_LARGE_INTEGER", "_ULARGE_INTEGER", "tagSTATSTG", "_FILETIME")

class CException;
using namespace MSXML2;
using namespace MSSOAPLib30;
#endif

// 2010-12-23 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - �� �޼ҵ� ������ ���ϰ� ������ �߰�
#define LIN_WEB_METHOD_SUCCESS_RETURN		1	// �������� �α��� �ÿ� 1������ ���� �ȴ�.
// END 2010-12-23 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - �� �޼ҵ� ������ ���ϰ� ������ �߰�

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSOAPConnect::CSOAPConnect()
{
	CoInitialize(NULL); // Com��ü �ʱ�ȭ
}

CSOAPConnect::~CSOAPConnect()
{
	CoUninitialize();	// Com��ü �ʱ�ȭ
}

// 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - �� ���� ó�� �Լ�
BOOL CSOAPConnect::SOAP_Authentication(BSTR i_URLstring, BSTR i_GameID ,BSTR i_WebMethodstring, BSTR i_ID, BSTR i_Password)
{
// 	BSTR    bstrWsdl   = SysAllocString (L"http://auth.tst.axeso5.com/webservice/axeso5ws.asmx?wsdl"); //�� ����Ʈ�� ���� �ϴ� �κ�
// 	BSTR    bstrMethod = SysAllocString (L"AuthenticateUser"); // ������ ������ �޼��带 �����ϴ� �κ�
// 	BSTR    bstrParam1  = SysAllocString (L"op7auth1"); // �Ķ���͸� �����Ѵ�.
// 	BSTR    bstrParam2  = SysAllocString (L"8e607a4752fa2e59413e5790536f2b42"); // �Ķ���͸� �����Ѵ�.
// 	BSTR    bstrParam3  = SysAllocString (L"2"); // �Ķ���͸� �����Ѵ�.
	#if defined(SERVICE_TYPE_ARGENTINA_SERVER_1)
 	VARIANT varResult;

	CComPtr<ISoapClient> pSoapClient;

	HRESULT    hr;
	DISPPARAMS dispparams;
	EXCEPINFO  excepinfo;
	DISPID     dispid;
    UINT       uArgErr;

	UINT uDim        = 0;
	long lLBound     = 0l;
	long lUBound     = 0l;
	long nBoundIndex = 0l;
	BSTR bstrElement = NULL;


#if !(defined(_UNICODE) || defined(OLE2ANSI))
	USES_CONVERSION;
#endif


	VariantInit(&varResult);
	ZeroMemory (&excepinfo,  sizeof(EXCEPINFO));
	ZeroMemory (&dispparams, sizeof(DISPPARAMS));

	try
	{
		hr = pSoapClient.CoCreateInstance (__uuidof(SoapClient30)); //���� ��ü ����
		if(S_OK!=hr)
		{
			//AfxMessageBox ("[ERROR]SOAP_OBJECT_CREATED_FIELD!\r\n");
			g_pPreGlobal->WriteSystemLog("[ERROR] CSOAPConnect::InvokeWebSvc() SOAP_OBJECT_CREATED_FIELD!\r\n");
		}

		pSoapClient->MSSoapInit (i_URLstring, L"", L"", L""); // ��ü �ʱ�ȭ ó��

		dispparams.rgvarg             = new VARIANTARG[3]; // ���� ���� ��ŭ �Ҵ�
		dispparams.cArgs              = 3; // ���� ����
		dispparams.cNamedArgs         = 0;
		dispparams.rgdispidNamedArgs  = NULL;	 
		dispparams.rgvarg[0].vt	      = VT_BYREF|VT_BSTR;
		dispparams.rgvarg[0].pbstrVal = &i_GameID;		// �迭�� ������ ��, �������� �����Ѵ�. ID, PW, GameID��� GameID,PW,ID�� �����ϵ��� �Ѵ�.
		dispparams.rgvarg[1].vt	      = VT_BYREF|VT_BSTR;
		dispparams.rgvarg[1].pbstrVal = &i_Password;
		dispparams.rgvarg[2].vt	      = VT_BYREF|VT_BSTR;
		dispparams.rgvarg[2].pbstrVal = &i_ID;
		
		// web method ID�� �����´�.
		hr = pSoapClient->GetIDsOfNames(IID_NULL, &i_WebMethodstring, 3, LOCALE_SYSTEM_DEFAULT, &dispid);
		if(S_OK!=hr) // ���н� ���� ó��
		{
			g_pPreGlobal->WriteSystemLog("[ERROR] CSOAPConnect::InvokeWebSvc() SOAP_WEB_METHOD_ID_NOT_FOUND!\r\n"); 
		}
		// ������ web method ����
		hr = pSoapClient->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD,
                                 &dispparams, &varResult, &excepinfo, &uArgErr);
		// ��ȣ �׽�Ʈ ���ϰ� üũ
		// g_pPreGlobal->WriteSystemLogEX(TRUE,"VarResult = VarType[%d], VarReturn = [%d]\r\n",varResult.vt,varResult.boolVal); 
		
		if(S_OK!=hr) // ���н� ���� ó��
		{
			g_pPreGlobal->WriteSystemLog("[ERROR] CSOAPConnect::InvokeWebSvc() SOAP_WEB_METHOD_EXEC_FIELD!\r\n"); 
		}

		// 2010-12-23 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - ���ϰ��� ���� ���� ���� ��ƾ �߰�
		if(LIN_WEB_METHOD_SUCCESS_RETURN != varResult.boolVal) // ����
		{
			g_pPreGlobal->WriteSystemLogEX(TRUE,"User Invalid Password!!\r\n");
			// �ʱ�ȭ ó��
			VariantClear (&varResult);		
			if (bstrElement)		SysFreeString (bstrElement);
			if (i_ID)				SysFreeString (bstrElement);
			if (i_Password)			SysFreeString (bstrElement);
			if (i_GameID)			SysFreeString (bstrElement);
			if (i_WebMethodstring)	SysFreeString (bstrElement);
			if (i_URLstring)		SysFreeString (bstrElement);
			if (pSoapClient)		pSoapClient.Release();
			if (dispparams.rgvarg) delete [] dispparams.rgvarg;
			// END �ʱ�ȭ ó��
			return FALSE;
		}
		else	// ����
		{
			g_pPreGlobal->WriteSystemLogEX(TRUE,"User Success checked!!\r\n");
		}

		if ((VT_BSTR|VT_ARRAY)==varResult.vt)
		{		
			uDim = SafeArrayGetDim    (varResult.parray);
			hr   = SafeArrayGetLBound (varResult.parray, uDim, &lLBound);
			hr   = SafeArrayGetUBound (varResult.parray, uDim, &lUBound);

			assert(uDim == 1);
			for (nBoundIndex=lLBound; nBoundIndex<=lUBound; nBoundIndex++)
			{
				hr = SafeArrayGetElement(varResult.parray, &nBoundIndex, &bstrElement);

#if !(defined(_UNICODE) || defined(OLE2ANSI))
				//SendMessage (hWnd, LB_ADDSTRING, 0, (LPARAM)W2A(bstrElement));
#else
				//SendMessage (hWnd, LB_ADDSTRING, 0, (LPARAM)bstrElement);
#endif
				SysFreeString (bstrElement);
				bstrElement = NULL;
			}
		}
	}
	catch (exception* pE)
	{
		// TCHAR szErrMessage[512];
		// ZeroMemory (szErrMessage, sizeof(TCHAR[512]));
		g_pPreGlobal->WriteSystemLogEX(TRUE,"CSOAPConnect::InvokeWebSvc Exception Error( %s ) \r\n",pE->what()); // excption ���� ��Ʈ�� ó��
		delete pE;
	}
	catch (...)
	{
		g_pPreGlobal->WriteSystemLog("CSOAPConnect::InvokeWebSvc Unknown Exception!\r\n"); // excption ���� ��Ʈ�� ó��
		//AfxMessageBox (TEXT("Unknown Exception!"));
	}
	// �ʱ�ȭ ó��
	VariantClear (&varResult);		
	if (bstrElement)		SysFreeString (bstrElement);
	if (i_ID)				SysFreeString (bstrElement);
	if (i_Password)			SysFreeString (bstrElement);
	if (i_GameID)			SysFreeString (bstrElement);
	if (i_WebMethodstring)	SysFreeString (bstrElement);
	if (i_URLstring)		SysFreeString (bstrElement);
	if (pSoapClient)		pSoapClient.Release();
	if (dispparams.rgvarg) delete [] dispparams.rgvarg;
	// END �ʱ�ȭ ó��
	#endif
	return TRUE;
	
}
// END 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - �� ���� ó�� �Լ�

// 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - �� ��ȯ �Լ� ��� �Ŀ��� �޸� ���� �ʼ�!
BSTR CSOAPConnect::Char2bBSTR(char * i_asc)
{ // char to BSTR
	BSTR bstr;
	
	// sTime�� �����ڵ�� ��ȯ�ϱ⿡ �ռ� ���� �װ��� �����ڵ忡���� ���̸� �˾ƾ� �Ѵ�.
	int nLen = MultiByteToWideChar(CP_ACP, 0, i_asc, strlen(i_asc), NULL, NULL);
	
	// �� ���̸�ŭ �޸𸮸� �Ҵ��Ѵ�.
	bstr = SysAllocStringLen(NULL, nLen);
	
	// ���� ��ȯ�� �����Ѵ�.
	MultiByteToWideChar(CP_ACP, 0, i_asc,strlen(i_asc), bstr, nLen);
	
	return bstr;
	
}
// 2010-11-29 by shcho, �Ƹ���Ƽ�� �ܺ����� ���� SOAP ó�� - �� ��ȯ �Լ� ��� �Ŀ��� �޸� ���� �ʼ�!
