#include "classzanak.h"
#include <iostream>
//konstruktor
classzanak::classzanak(LPCWSTR fileName) {
    srand(46749987439);
    p_chFileName = _wcsdup(fileName);

    // Vytvo�en� souboru
    hFile = CreateFileW(p_chFileName,GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);

    

    // Vytvo�enm� pam�ov�n�
    hFileMapping = CreateFileMapping(hFile,NULL,PAGE_READWRITE,0,0,NULL);

    

    // zobrazen� v pam�ov�m mapov�n�
    p_mSourceFirstByte = (PBYTE)MapViewOfFile(hFileMapping,FILE_MAP_ALL_ACCESS,0,0,0);

    
}
// destruktor
classzanak::~classzanak() {
    if (p_mSourceFirstByte) {
        UnmapViewOfFile(p_mSourceFirstByte);
    }
    if (hFileMapping) {
        CloseHandle(hFileMapping);
    }
    if (hFile) {
        CloseHandle(hFile);
    }
    if (p_chFileName) {
        free(p_chFileName);
    }
}
//encrypt decrypt
void classzanak::XorEncryptDecrypt() {
    
    DWORD fileSize = GetFileSize(hFile, NULL);
    // �ifrov�n� XOR 
    for (DWORD i = 0; i < fileSize; i++) {
        p_mSourceFirstByte[i] ^= (rand() % 256);
    }
    FlushViewOfFile(p_mSourceFirstByte, fileSize);
}



