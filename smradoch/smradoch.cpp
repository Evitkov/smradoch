#include <iostream>
#include "classzanak.h"

int main()
{
    const LPCWSTR filename = L"c:\\Temp\\matej splatej.txt";
    classzanak objEncrypt(filename);
    objEncrypt.XorEncryptDecrypt();
    return 0;
}