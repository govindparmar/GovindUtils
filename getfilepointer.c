#include "GovindUtils.h"

DWORD WINAPI GetFilePointer(_In_ HANDLE hFile, _Out_ LPDWORD lpdwHigh)
{
	DWORD dwLow;
	*lpdwHigh = 0UL;
	dwLow = SetFilePointer(hFile, 0, lpdwHigh, FILE_CURRENT);
	return dwLow;
}