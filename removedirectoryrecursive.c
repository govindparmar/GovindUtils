#include "GovindUtils.h"

// -1 : First file not found
// -2 : 

INT WINAPI RemoveDirectoryRecursivelyW(LPCWSTR lpPathName)
{
	HANDLE hFind;
	WIN32_FIND_DATAW wfd;
	WCHAR wszPattern[MAX_PATH], wszBuffer2[MAX_PATH];

	PathCchCombine(wszPattern, MAX_PATH, lpPathName, L"*");

	hFind = FindFirstFileW(wszPattern, &wfd);
	
	if (INVALID_HANDLE_VALUE == hFind)
	{
		goto end;
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
				return -3;
			}
		}
	}
	while (FindNextFileW(hFind, &wfd));
	FindClose(hFind);
end:
	if (FALSE == RemoveDirectoryW(lpPathName))
	{
		return -4;
	}

	return 1;
}