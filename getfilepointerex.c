#include "GovindUtils.h"

LARGE_INTEGER WINAPI GetFilePointerEx(_In_ HANDLE hFile)
{
	LARGE_INTEGER liZero;
	LARGE_INTEGER liRet;

	ZeroMemory(&liZero, sizeof(LARGE_INTEGER));
	ZeroMemory(&liRet, sizeof(LARGE_INTEGER));

	SetFilePointerEx(hFile, liZero, &liRet, FILE_CURRENT);

	return liRet;
}