#pragma once
#include "GovindUtils.h"

HANDLE g_hFile = INVALID_HANDLE_VALUE;

BOOL APIENTRY DllMain(_In_ HINSTANCE hInstDLL, _In_ DWORD dwReason, _In_ LPVOID lpReserved)
{
	if (INVALID_HANDLE_VALUE == g_hFile)
	{
		g_hFile = CreateFileW(L"log.txt", GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	}

	return TRUE;
}
