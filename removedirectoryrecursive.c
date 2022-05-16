#include "GovindUtils.h"

INT WINAPI RemoveDirectoryRecursivelyW(LPCWSTR lpPathName)
{
	HANDLE hFind;
	WIN32_FIND_DATAW wfd;
	WCHAR wszPattern[MAX_PATH], wszBuffer2[MAX_PATH];

	PathCchCombine(wszPattern, MAX_PATH, lpPathName, L"*");

	hFind = FindFirstFileW(wszPattern, &wfd);
	
	if (INVALID_HANDLE_VALUE == hFind)
	{
		return -1;
	}
	do
	{

		if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if ((wcscmp(wfd.cFileName, L".") == 0) ||
				(wcscmp(wfd.cFileName, L"..") == 0))
			{
				continue;
			}
			else
			{
				//GetFullPathNameW(wfd.cFileName, MAX_PATH, wszPattern, NULL);
				PathCchCombine(wszBuffer2, MAX_PATH, lpPathName, wfd.cFileName);
				if (RemoveDirectoryRecursivelyW(wszBuffer2) == FALSE)
				{
					return -2;
				}
			}
		}
		else
		{//GetFullPathNameW(wfd.cFileName, MAX_PATH, wszPattern, NULL);
			PathCchCombine(wszBuffer2, MAX_PATH, lpPathName, wfd.cFileName);
			if (!DeleteFileW(wszBuffer2))
			{
				
					DWORD dwWritten;
					HRESULT hr;
					UINT uLen;
					WCHAR wszWrite[1000];
					DWORD dwError = GetLastError();

					StringCchPrintfW(wszWrite, 1000, L"Failed to delete file %s: %I32u\r\n", wszBuffer2, dwError);
					hr = StringCbLengthW(wszWrite, 1000 * sizeof(WCHAR), &uLen);
					if (SUCCEEDED(hr))
					{
						WriteFile(g_hFile, wszWrite, uLen, &dwWritten, NULL);
					}
				
				return -3;
			}
		}
	}
	while (FindNextFileW(hFind, &wfd));

	FindClose(hFind);
	if (FALSE == RemoveDirectoryW(lpPathName))
	{
		return -4;
	}

	return 1;
}