#pragma once
#include <Windows.h>
#include <PathCch.h>
#include <strsafe.h>

BOOL APIENTRY DllMain(_In_ HINSTANCE hInstDLL, _In_ DWORD dwReason, _In_ LPVOID lpReserved);
INT WINAPI RemoveDirectoryRecursivelyW(LPCWSTR lpPathName);
DWORD WINAPI GetFilePointer(_In_ HANDLE hFile, _Out_ LPDWORD lpdwHigh);
LARGE_INTEGER WINAPI GetFilePointerEx(_In_ HANDLE hFile);