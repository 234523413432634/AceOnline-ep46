// 2011-08-17 by hsson Ŭ���̾�Ʈ ũ���� ���� ������ Ŭ�� ���� ����

#include "DarkCrash.h"
#include "ErrorController.h"

namespace Exception
{ 
	bool CDarkCrash::SetUserName( char* _pUserName )
	{ 
		g_cErrorController.SetUserName( _pUserName );
		return true;
	}
	bool CDarkCrash::OnPlayMiniDump( _EXCEPTION_POINTERS *pException )
	{
		g_cErrorController.OnPlayMiniDump( pException );
		return true;
	}
	bool CDarkCrash::OutInfo( char* _val )
	{
		CopyMemory( _val, g_cErrorController.m_strOutInfo, 1024 );
		return true;
	}

}

// end 2011-08-17 by hsson Ŭ���̾�Ʈ ũ���� ���� ������ Ŭ�� ���� ����