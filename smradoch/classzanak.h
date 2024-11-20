#pragma once
#include <windows.h>

class classzanak
{
private:
    HANDLE hFile;
    HANDLE hFileMapping;
    PBYTE p_mSourceFirstByte;
    LPWSTR p_chFileName;

   

public:
    classzanak(LPCWSTR fileName);              //konbstruktor

    ~classzanak();                          //destruktor

    void XorEncryptDecrypt();                         //šifrování
    
};