/* WonWonGetDiskFreeSpaceEx.h --- Wonders API GetDiskFreeSpaceEx */
/* Copyright (C) 2017 Katayama Hirofumi MZ. License: CC0 */
/**************************************************************************/

#pragma once

#ifndef _INC_WINDOWS
    #include <windows.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/

BOOL WINAPI WonGetDiskFreeSpaceExA(
    const char *lpDirectoryName,
    ULARGE_INTEGER *lpFreeBytesAvailable,
    ULARGE_INTEGER *lpTotalNumberOfBytes,
    ULARGE_INTEGER *lpTotalNumberOfFreeBytes);

BOOL WINAPI WonGetDiskFreeSpaceExW(
    const WCHAR *lpDirectoryName,
    ULARGE_INTEGER *lpFreeBytesAvailable,
    ULARGE_INTEGER *lpTotalNumberOfBytes,
    ULARGE_INTEGER *lpTotalNumberOfFreeBytes);

/**************************************************************************/

#ifdef __cplusplus
} // extern "C"
#endif

/**************************************************************************/

#if defined(_WONVER) && (_WONVER < 0x0410)
    #define GetDiskFreeSpaceExW WonGetDiskFreeSpaceExW
    #define GetDiskFreeSpaceExA WonGetDiskFreeSpaceExA
#endif

#undef GetDiskFreeSpaceEx
#ifdef UNICODE
    #define GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#else
    #define GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#endif

/**************************************************************************/
