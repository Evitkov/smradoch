#include "classzanak.h"
#include <iostream>

classzanak::classzanak(LPCWSTR fileName) {
    p_chFileName = _wcsdup(fileName);

    // Open file
    hFile = CreateFileW(
        p_chFileName,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        0
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        std::wcerr << L"Could not open file" << std::endl;
        return;
    }

    // Create file mapping
    hFileMapping = CreateFileMapping(
        hFile,
        NULL,
        PAGE_READWRITE,
        0,
        0,
        NULL
    );

    if (hFileMapping == NULL) {
        std::wcerr << L"Could not create file mapping" << std::endl;
        CloseHandle(hFile);
        return;
    }

    // Map view of file
    p_mSourceFirstByte = (PBYTE)MapViewOfFile(
        hFileMapping,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        0
    );

    if (p_mSourceFirstByte == NULL) {
        std::wcerr << L"Could not map view of file" << std::endl;
        CloseHandle(hFileMapping);
        CloseHandle(hFile);
        return;
    }
}

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

void classzanak::XorEncryptDecrypt(DWORD fileSize) {
    // Simple XOR encryption/decryption
    for (DWORD i = 0; i < fileSize; i++) {
        p_mSourceFirstByte[i] ^= (i % 256);  // Use index-based XOR key
    }
    FlushViewOfFile(p_mSourceFirstByte, fileSize);
}

void classzanak::Encrypt() {
    DWORD fileSize = GetFileSize(hFile, NULL);
    XorEncryptDecrypt(fileSize);
}


