

#include <iostream>
#include <windows.h>

#include "classzanak.h"


classzanak* objTManager;

int main()
{
	objTManager = new classzanak();
	//objTManager->Encrypt();
	objTManager->Decrypt();

	delete(objTManager);
}

