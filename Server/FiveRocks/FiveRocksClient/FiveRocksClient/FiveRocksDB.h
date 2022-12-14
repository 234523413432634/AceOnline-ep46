#pragma once

#include "FiveRocksDefine.h"

class FiveRocksDB
{
public:
	FiveRocksDB(void);
	virtual ~FiveRocksDB(void);

public:
	void Init();
	bool DBCnn(TCHAR * i_strSourceDBCnn);
	void DBDisCnn();
	bool GetIsDBCnn()						{return m_bIsDBCnn;}

	_RecordsetPtr 	GetRecordsetPtr()		{return m_pRecordSet;}
	_CommandPtr		GetCommandPtr()			{return m_pCommand;}

private:
	_RecordsetPtr 	m_pRecordSet;
	_ConnectionPtr	m_pConnection;
	_CommandPtr		m_pCommand;

	bool			m_bIsDBCnn;

	inline void TESTHR(HRESULT x) { if FAILED(x) _com_issue_error(x); };
};

