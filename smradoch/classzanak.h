#pragma once
#include <windows.h>

class classzanak
{

public:
	classzanak(void);       //konstruktor
	~classzanak(void);      //destruktor

	bool Encrypt(void);                  //za�ifrovat
	bool Decrypt(void);                 //de�ifrovat

};
