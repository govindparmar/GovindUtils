#pragma once
#include <Windows.h>
#include <PathCch.h>
#include <strsafe.h>

#define EXTERN extern

BOOL APIENTRY DllMain(_In_ HINSTANCE hInstDLL, _In_ DWORD dwReason, _In_ LPVOID lpReserved);
EXTERN HANDLE g_hFile;
