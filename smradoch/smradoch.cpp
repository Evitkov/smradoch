

#include <iostream>
#include <windows.h>

#include "classzanak.h"

char vyber;
classzanak* objEncrypt;

int main()
{
	//v�b�r encrypt decrypt
	scanf_s(" %c", &vyber);
	objEncrypt = new classzanak();
	if (vyber == 'e')
	{
		objEncrypt->Encrypt();
	}
	//v�b�r encrypt decrypt
	if (vyber == 'd')
	{
		objEncrypt->Decrypt();
	}
	delete(objEncrypt);
}

