#pragma once

#include <pdh.h>
class CCpuUsage
{
public:
	CCpuUsage(void)   :       m_hQuery( 0 ), m_hCounter( 0 )  {}
	~CCpuUsage(void)      {       destroy();      }

	bool  init();
	void    destroy();
	bool    getCpuUsage( double * val );

	PDH_HQUERY      m_hQuery;
	PDH_HCOUNTER    m_hCounter;


	
};