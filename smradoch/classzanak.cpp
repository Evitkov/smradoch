#include "classzanak.h"
#include <iostream>
//konstruktor
classzanak::classzanak(LPCWSTR fileName) {
    srand(46749987439);
    p_chFileName = _wcsdup(fileName);

    // Vytvo¯enÌ souboru
    hFile = CreateFileW(p_chFileName,GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);

    

    // Vytvo¯enmÌ pamÏùov·nÌ
    hFileMapping = CreateFileMapping(hFile,NULL,PAGE_READWRITE,0,0,NULL);

    

    // zobrazenÌ v pamÏùovÈm mapov·nÌ
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
    // öifrov·nÌ XOR 
    for (DWORD i = 0; i < fileSize; i++) {
        p_mSourceFirstByte[i] ^= (rand() % 256);
    }
    FlushViewOfFile(p_mSourceFirstByte, fileSize);
}



