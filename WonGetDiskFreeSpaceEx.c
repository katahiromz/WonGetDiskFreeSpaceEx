/* WonWonGetDiskFreeSpaceEx.c --- Wonders API GetDiskFreeSpaceEx */
/* Copyright (C) 2017 Katayama Hirofumi MZ. License: CC0 */

#include "WonGetDiskFreeSpaceEx.h"

/**************************************************************************/

typedef BOOL (WINAPI *GDFSEA)(LPCSTR, PULARGE_INTEGER, 
                              PULARGE_INTEGER, PULARGE_INTEGER);

BOOL WINAPI WonGetDiskFreeSpaceExA(
    const char *lpDirectoryName,
    ULARGE_INTEGER *lpFreeBytesAvailable,
    ULARGE_INTEGER *lpTotalNumberOfBytes,
    ULARGE_INTEGER *lpTotalNumberOfFreeBytes)
{
    HMODULE hKernel32;
    FARPROC fn;
    GDFSEA pGetDiskFreeSpaceExA;
    DWORD dwSectPerClust, dwBytesPerSect;
    DWORD dwFreeClusters, dwTotalClusters;
    BOOL fResult;

    hKernel32 = GetModuleHandleA("kernel32");
    fn = GetProcAddress(hKernel32, "GetDiskFreeSpaceExA");
    if (fn)
    {
        pGetDiskFreeSpaceExA = (GDFSEA)fn;
        return (*pGetDiskFreeSpaceExA)(
            lpDirectoryName,
            lpFreeBytesAvailable,
            lpTotalNumberOfBytes,
            lpTotalNumberOfFreeBytes);
    }
    

    fResult = GetDiskFreeSpaceA(lpDirectoryName, 
                                &dwSectPerClust,
                                &dwBytesPerSect, 
                                &dwFreeClusters,
                                &dwTotalClusters);
    if (fResult)
    {
        if (lpFreeBytesAvailable)
        {
            *lpFreeBytesAvailable = 
                (ULONGLONG)dwFreeClusters * dwSectPerClust *
                    dwBytesPerSect;
        }
        if (lpTotalNumberOfBytes)
        {
            *lpTotalNumberOfBytes = 
                (ULONGLONG)dwTotalClusters * dwSectPerClust * 
                    dwBytesPerSect;
        }
        if (lpTotalNumberOfFreeBytes)
        {
            *lpTotalNumberOfFreeBytes = 
                (ULONGLONG)dwFreeClusters * dwSectPerClust *
                    dwBytesPerSect;
        }
    }
    return fResult;
}

/**************************************************************************/

typedef BOOL (WINAPI *GDFSEW)(LPCWSTR, PULARGE_INTEGER, 
                              PULARGE_INTEGER, PULARGE_INTEGER);

BOOL WINAPI WonGetDiskFreeSpaceExW(
    const WCHAR *lpDirectoryName,
    ULARGE_INTEGER *lpFreeBytesAvailable,
    ULARGE_INTEGER *lpTotalNumberOfBytes,
    ULARGE_INTEGER *lpTotalNumberOfFreeBytes)
{
    HMODULE hKernel32;
    FARPROC fn;
    GDFSEW pGetDiskFreeSpaceExW;
    DWORD dwSectPerClust, dwBytesPerSect;
    DWORD dwFreeClusters, dwTotalClusters;
    BOOL fResult;

    hKernel32 = GetModuleHandleW(L"kernel32");
    fn = GetProcAddress(hKernel32, "GetDiskFreeSpaceExW");
    if (fn)
    {
        pGetDiskFreeSpaceExW = (GDFSEW)fn;
        return (*pGetDiskFreeSpaceExW)(
            lpDirectoryName,
            lpFreeBytesAvailable,
            lpTotalNumberOfBytes,
            lpTotalNumberOfFreeBytes);
    }
    

    fResult = GetDiskFreeSpaceW(lpDirectoryName, 
                                &dwSectPerClust,
                                &dwBytesPerSect, 
                                &dwFreeClusters,
                                &dwTotalClusters);
    if (fResult)
    {
        if (lpFreeBytesAvailable)
        {
            *lpFreeBytesAvailable = 
                (ULONGLONG)dwFreeClusters * dwSectPerClust *
                    dwBytesPerSect;
        }
        if (lpTotalNumberOfBytes)
        {
            *lpTotalNumberOfBytes = 
                (ULONGLONG)dwTotalClusters * dwSectPerClust * 
                    dwBytesPerSect;
        }
        if (lpTotalNumberOfFreeBytes)
        {
            *lpTotalNumberOfFreeBytes = 
                (ULONGLONG)dwFreeClusters * dwSectPerClust *
                    dwBytesPerSect;
        }
    }
    return fResult;
}

/**************************************************************************/
