#pragma once
#include <windows.h>

class classzanak
{

public:
	classzanak(void);       //konstruktor
	~classzanak(void);      //destruktor

	void Encrypt(void);                  //zašifrovat
	void Decrypt(void);                 //dešifrovat

};
