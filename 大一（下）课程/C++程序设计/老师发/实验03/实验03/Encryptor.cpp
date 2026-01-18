#include <iostream>
#include "Encryptor.h"

int Encryptor(char plain[], char key[], char cipher[])
{	
	int i = 0;
    int j = 0;

    if(plain == NULL)
    {
        return PLAIN_NULL;
    }

    if(key == NULL)
    {
        return KEY_NULL;
    }

    if(cipher == NULL)
    {
        return CHIPHER_NULL;
    }

	for(i = 0; i < strlen(plain); i ++)
	{
		cipher[i] = plain[i] ^ key[j];
		j ++;
		if(j >= strlen(key))
		{
			j = 0;
		}
	}
	cipher[i] = '\0';

    return SUCCESS;

}

int Decryptor(char cipher[], char key[], char result[])
{	
	int i = 0;
    int j = 0;

    if(cipher == NULL)
    {
        return CHIPHER_NULL;
    }

    if(key == NULL)
    {
        return KEY_NULL;
    }

    if(result == NULL)
    {
        return RESULT_NULL;
    }

	for(i = 0; i < strlen(cipher); i ++)
	{
		result[i] = cipher[i] ^ key[j];
		j ++;
		if(j >= strlen(key))
		{
			j = 0;
		}
	}
	cipher[i] = '\0';

    return SUCCESS;

}