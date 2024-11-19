#include <iostream>
#include "classzanak.h"

int main()
{
    const LPCWSTR filename = L"c:\\temp\\matej splatej.txt";
    classzanak objEncrypt(filename);
    objEncrypt.Encrypt();
    return 0;
}