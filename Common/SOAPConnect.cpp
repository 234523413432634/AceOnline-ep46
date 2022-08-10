// SOAPConnect.cpp: implementation of the CSOAPConnect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PreGlobal.h"
#include "SOAPConnect.h"
// 2010-11-29 by shcho, 아르헨티나 외부인증 변경 SOAP 처리 - include 추가
#include <comdef.h>
#include <atlbase.h>
#include <exception>
#include <assert.h>
#include <cstring>
// END 2010-11-29 by shcho, 아르헨티나 외부인증 변경 SOAP 처리 - include 추가

#if defined(SERVICE_TYPE_ARGENTINA_SERVER_1)
#import <msxml4.dll>
#import "c:\Windows\System32\mssoap30.dll" named_guids exclude("IStream", "IErrorInfo", "ISequentialStream", "_LARGE_INTEGER", "_ULARGE_INTEGER", "tagSTATSTG", "_FILETIME")

class CException;
using namespace MSXML2;
using namespace MSSOAPLib30;
#endif

// 2010-12-23 by shcho, 아르헨티나 외부인증 변경 SOAP 처리 - 웹 메소드 성공시 리턴값 디파인 추가
#define LIN_WEB_METHOD_SUCCESS_RETURN		1	// 성공적인 로그인 시에 1값으로 리턴 된다.
// END 2010-12-23 by shcho, 아르헨티나 외부인증 변경 SOAP 처리 - 웹 메소드 성공시 리턴값 디파인 추가

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSOAPConnect::CSOAPConnect()
{
	CoInitialize(NULL); // Com객체 초기화
}

CSOAPConnect::~CSOAPConnect()
{
	CoUninitialize();	// Com객체 초기화
}

// 2010-11-29 by shcho, 아르헨티나 외부인증 변경 SOAP 처리 - 웹 접속 처리 함수
BOOL CSOAPConnect::SOAP_Authentication(BSTR i_URLstring, BSTR i_GameID ,BSTR i_WebMethodstring, BSTR i_ID, BSTR i_Password)
{
// 	BSTR    bstrWsdl   = SysAllocString (L"http://auth.tst.axeso5.com/webservice/axeso5ws.asmx?wsdl"); //웹 사이트를 정의 하는 부분
// 	BSTR    bstrMethod = SysAllocString (L"AuthenticateUser"); // 웹에서 생성된 메서드를 정의하는 부분
// 	BSTR    bstrParam1  = SysAllocString (L"op7auth1"); // 파라메터를 정의한다.
// 	BSTR    bstrParam2  = SysAllocString (L"8e607a4752fa2e59413e5790536f2b42"); // 파라메터를 정의한다.
// 	BSTR    bstrParam3  = SysAllocString (L"2"); // 파라메터를 정의한다.
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
		hr = pSoapClient.CoCreateInstance (__uuidof(SoapClient30)); //소프 객체 생성
		if(S_OK!=hr)
		{
			//AfxMessageBox ("[ERROR]SOAP_OBJECT_CREATED_FIELD!\r\n");
			g_pPreGlobal->WriteSystemLog("[ERROR] CSOAPConnect::InvokeWebSvc() SOAP_OBJECT_CREATED_FIELD!\r\n");
		}

		pSoapClient->MSSoapInit (i_URLstring, L"", L"", L""); // 객체 초기화 처리

		dispparams.rgvarg             = new VARIANTARG[3]; // 인자 개수 만큼 할당
		dispparams.cArgs              = 3; // 인자 개수
		dispparams.cNamedArgs         = 0;
		dispparams.rgdispidNamedArgs  = NULL;	 
		dispparams.rgvarg[0].vt	      = VT_BYREF|VT_BSTR;
		dispparams.rgvarg[0].pbstrVal = &i_GameID;		// 배열은 전송할 때, 역순으로 저장한다. ID, PW, GameID라면 GameID,PW,ID로 정의하도록 한다.
		dispparams.rgvarg[1].vt	      = VT_BYREF|VT_BSTR;
		dispparams.rgvarg[1].pbstrVal = &i_Password;
		dispparams.rgvarg[2].vt	      = VT_BYREF|VT_BSTR;
		dispparams.rgvarg[2].pbstrVal = &i_ID;
		
		// web method ID를 가져온다.
		hr = pSoapClient->GetIDsOfNames(IID_NULL, &i_WebMethodstring, 3, LOCALE_SYSTEM_DEFAULT, &dispid);
		if(S_OK!=hr) // 실패시 에러 처리
		{
			g_pPreGlobal->WriteSystemLog("[ERROR] CSOAPConnect::InvokeWebSvc() SOAP_WEB_METHOD_ID_NOT_FOUND!\r\n"); 
		}
		// 가져온 web method 실행
		hr = pSoapClient->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD,
                                 &dispparams, &varResult, &excepinfo, &uArgErr);
		// 상호 테스트 리턴값 체크
		// g_pPreGlobal->WriteSystemLogEX(TRUE,"VarResult = VarType[%d], VarReturn = [%d]\r\n",varResult.vt,varResult.boolVal); 
		
		if(S_OK!=hr) // 실패시 에러 처리
		{
			g_pPreGlobal->WriteSystemLog("[ERROR] CSOAPConnect::InvokeWebSvc() SOAP_WEB_METHOD_EXEC_FIELD!\r\n"); 
		}

		// 2010-12-23 by shcho, 아르헨티나 외부인증 변경 SOAP 처리 - 리턴값에 따른 성공 실패 루틴 추가
		if(LIN_WEB_METHOD_SUCCESS_RETURN != varResult.boolVal) // 실패
		{
			g_pPreGlobal->WriteSystemLogEX(TRUE,"User Invalid Password!!\r\n");
			// 초기화 처리
			VariantClear (&varResult);		
			if (bstrElement)		SysFreeString (bstrElement);
			if (i_ID)				SysFreeString (bstrElement);
			if (i_Password)			SysFreeString (bstrElement);
			if (i_GameID)			SysFreeString (bstrElement);
			if (i_WebMethodstring)	SysFreeString (bstrElement);
			if (i_URLstring)		SysFreeString (bstrElement);
			if (pSoapClient)		pSoapClient.Release();
			if (dispparams.rgvarg) delete [] dispparams.rgvarg;
			// END 초기화 처리
			return FALSE;
		}
		else	// 성공
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
		g_pPreGlobal->WriteSystemLogEX(TRUE,"CSOAPConnect::InvokeWebSvc Exception Error( %s ) \r\n",pE->what()); // excption 에러 스트링 처리
		delete pE;
	}
	catch (...)
	{
		g_pPreGlobal->WriteSystemLog("CSOAPConnect::InvokeWebSvc Unknown Exception!\r\n"); // excption 에러 스트링 처리
		//AfxMessageBox (TEXT("Unknown Exception!"));
	}
	// 초기화 처리
	VariantClear (&varResult);		
	if (bstrElement)		SysFreeString (bstrElement);
	if (i_ID)				SysFreeString (bstrElement);
	if (i_Password)			SysFreeString (bstrElement);
	if (i_GameID)			SysFreeString (bstrElement);
	if (i_WebMethodstring)	SysFreeString (bstrElement);
	if (i_URLstring)		SysFreeString (bstrElement);
	if (pSoapClient)		pSoapClient.Release();
	if (dispparams.rgvarg) delete [] dispparams.rgvarg;
	// END 초기화 처리
	#endif
	return TRUE;
	
}
// END 2010-11-29 by shcho, 아르헨티나 외부인증 변경 SOAP 처리 - 웹 접속 처리 함수

// 2010-11-29 by shcho, 아르헨티나 외부인증 변경 SOAP 처리 - 형 변환 함수 사용 후에는 메모리 해제 필수!
BSTR CSOAPConnect::Char2bBSTR(char * i_asc)
{ // char to BSTR
	BSTR bstr;
	
	// sTime을 유니코드로 변환하기에 앞서 먼저 그것의 유니코드에서의 길이를 알아야 한다.
	int nLen = MultiByteToWideChar(CP_ACP, 0, i_asc, strlen(i_asc), NULL, NULL);
	
	// 얻어낸 길이만큼 메모리를 할당한다.
	bstr = SysAllocStringLen(NULL, nLen);
	
	// 이제 변환을 수행한다.
	MultiByteToWideChar(CP_ACP, 0, i_asc,strlen(i_asc), bstr, nLen);
	
	return bstr;
	
}
// 2010-11-29 by shcho, 아르헨티나 외부인증 변경 SOAP 처리 - 형 변환 함수 사용 후에는 메모리 해제 필수!
