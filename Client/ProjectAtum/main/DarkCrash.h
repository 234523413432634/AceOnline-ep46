// 2011-08-17 by hsson Ŭ���̾�Ʈ ũ���� ���� ������ Ŭ�� ���� ����

#include <Windows.h>
#include <Shlwapi.h>

/*
"���ܽ�ȣ�����Լ�"�� SetUnhandledExceptionFilter�Լ��� ��� �� "���ܽ�ȣ�����Լ�"�ȿ���
Exception::CDarkCrash::OnPlayMiniDump( pException ) �� ȣ�� �� �ָ� �ȴ�.
�׸���, ���� �̸��� ���ӿ� �����ϰ� ƴ�� �� �� �ѹ� ������.

LONG WINAPI ���ܽ�ȣ�����Լ�(_EXCEPTION_POINTERS *pException)
{
	Exception::CDarkCrash::OnPlayMiniDump( pException );

	char* strBuf[1024] = {0, };
	Exception::CDarkCrash::OutInfo( strBuf );
	return 0;
}

void main()
{
	::SetUnhandledExceptionFilter( ���ܽ�ȣ�����Լ� )
	SetUserName("hsson");
}
*/

namespace Exception
{
	class CDarkCrash
	{
        public: 
		static bool SetUserName( char* _pUserName );
		static bool OnPlayMiniDump( _EXCEPTION_POINTERS *pException );
		static bool OutInfo( char* _val );
     };
}

// end 2011-08-17 by hsson Ŭ���̾�Ʈ ũ���� ���� ������ Ŭ�� ���� ����