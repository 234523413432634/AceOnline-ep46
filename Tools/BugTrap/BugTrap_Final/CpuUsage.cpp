#include "StdAfx.h"
#pragma comment(lib, "pdh.lib")
#include <pdhmsg.h>
#include "CpuUsage.h"


bool CCpuUsage::init()
{
	{
		PDH_STATUS      status = PdhOpenQuery (0, 0, &m_hQuery);

		if( status != ERROR_SUCCESS )
			return false;

		status = PdhAddCounter( m_hQuery, L"\\Processor(_TOTAL)\\% Processor Time", 0, &m_hCounter );

		if( status != ERROR_SUCCESS )
			return false;

		status = PdhCollectQueryData( m_hQuery );

		if( status != ERROR_SUCCESS )
		{
			return false;
		}

		return true;
	}
}

void CCpuUsage::destroy()
{
	{
		if( m_hQuery )
			PdhCloseQuery( m_hQuery );
		m_hQuery = 0;
	}
}

bool CCpuUsage::getCpuUsage( double * val )
{
	{
		PDH_STATUS      status = PdhCollectQueryData( m_hQuery );

		if( status != ERROR_SUCCESS )
			return false;

		PDH_FMT_COUNTERVALUE    value;

		status = PdhGetFormattedCounterValue( m_hCounter, PDH_FMT_DOUBLE,       0, &value);

		if (status != ERROR_SUCCESS)
			return false;
		*val = value.doubleValue;
		return true;
	}
}