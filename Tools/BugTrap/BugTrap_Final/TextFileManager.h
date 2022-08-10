#pragma once
class CTextFileManager
{
public:
	CTextFileManager();
	~CTextFileManager(void);
	void CreateTextFile(wchar_t* wFilePath);
	wchar_t* GetOsVersion(LPTSTR pszText);

	void GetCpuInfo(LPTSTR pszText);
	void GetMemoryInfo(LPTSTR pszText);
	void GetHddinfo(LPTSTR pszText);
	void GetVGAinfo(LPTSTR pszText);


	wchar_t* m_pFilePath;
	std::wstring	m_strData;
	wchar_t		m_strTemp[512];
	DWORD		m_dwTempSize;
};


