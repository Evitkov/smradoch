

#include <iostream>
#include <windows.h>

#include "classzanak.h"

char vyber;
classzanak* objEncrypt;

int main()
{
	//výbìr encrypt decrypt
	scanf_s(" %c", &vyber);
	objEncrypt = new classzanak();
	if (vyber == 'e')
	{
		objEncrypt->Encrypt();
	}
	//výbìr encrypt decrypt
	if (vyber == 'd')
	{
		objEncrypt->Decrypt();
	}
	delete(objEncrypt);
}

