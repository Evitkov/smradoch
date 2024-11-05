

#include <iostream>
#include <windows.h>

#include "classzanak.h"

char vyber;
classzanak* objTManager;

int main()
{
	scanf_s(" %c", &vyber);
	objTManager = new classzanak();
	if (vyber == 'e')
	{
		objTManager->Encrypt();
	}
	
	if (vyber == 'd')
	{
		objTManager->Decrypt();
	}
	delete(objTManager);
}

