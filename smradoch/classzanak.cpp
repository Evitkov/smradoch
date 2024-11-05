#include "classzanak.h"
#include <iostream>



classzanak::classzanak(void)
{
	
}
classzanak::~classzanak(void)
{

}


bool classzanak::Encrypt(void)
{
	FILE* p_file;
	FILE* p_file2;
	// Sem budeme nacitat 'chary' 
	unsigned char uchReadBuffer;
	int lintCount;
	// Zdroj 
	fopen_s(&p_file, "c:\\temp\\matej splatej.txt", "r");
	fopen_s(&p_file2, "c:\\temp\\dzula.txt", "w");
	do
	{
		
		// Cteni bytu 
		lintCount = fread_s(&uchReadBuffer, 1, 1, 1, p_file);
		if (lintCount != 0)
		{
			// Zasifrovat 
			uchReadBuffer = uchReadBuffer + 1;

			// Zápis bytu

			fwrite(&uchReadBuffer, 1, 1, p_file2);
		}
	} while (lintCount != 0);

	fclose(p_file);
	fclose(p_file2);
	return false;
}
bool classzanak::Decrypt(void)
{
	FILE* p_file;
	FILE* p_file2;
	// Sem budeme nacitat 'chary' 
	unsigned char uchReadBuffer;
	int lintCount;
	// Zdroj 
	fopen_s(&p_file, "c:\\temp\\dzula.txt", "r");
	fopen_s(&p_file2, "c:\\temp\\matej splatej.txt", "w");
	
	do
	{
		// Cteni bytu 
		lintCount = fread_s(&uchReadBuffer, 1, 1, 1, p_file);
		if (lintCount != 0)
		{
			// Zasifrovat 
			uchReadBuffer = uchReadBuffer - 1;

			// Zápis bytu

			fwrite(&uchReadBuffer, 1, 1, p_file2);
		}
	} while (lintCount != 0);

	fclose(p_file);
	fclose(p_file2);
	return false;
}






