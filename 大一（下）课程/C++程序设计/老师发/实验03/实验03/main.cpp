#include <iostream>
#include <string.h>
#include "Encryptor.h"
#include "main.h"

using namespace std;

int main()
{
	int i = 0;
	int j = 0;
	int n = 0;

	int Rslt = 0;
	
	char *plain[WORD_NUMBER] = {NULL};
	char key[KEY_LEN];
	char *cipher[WORD_NUMBER] = {NULL};
	char *result[WORD_NUMBER] = {NULL};

	cout << "Input word number:";
	cin >> n;
	if(n <= 0 || n > WORD_NUMBER)
	{
		return -1;
	}

   	cout << "\nInput plain text:";
	for(int i = 0; i < n; i ++)
	{
		if(plain[i] == NULL)
		{
			plain[i] = new char[TEXT_LEN];
			if(plain[i] == NULL)
			{
				return MEM_EMPTY;
			}
		}
		if(cipher[i] == NULL)
		{
			cipher[i] = new char[TEXT_LEN];
			if(cipher[i] == NULL)
			{
				return MEM_EMPTY;
			}
		}
		if(result[i] == NULL)
		{
			result[i] = new char[TEXT_LEN];
			if(result[i] == NULL)
			{
				return MEM_EMPTY;
			}
		}

		cin >> plain[i];
	}
		
   	cout << "Input plain key:";
	cin >> key;
	
	Rslt = Sort(plain, n);

	Rslt = EncSort(plain, key, n, cipher);

	cout << "\nCipher text:\n";
	
	for(i = 0; i < n; i ++)
	{
		for(j = 0; j < strlen(cipher[i]); j ++)
		{
			cout << hex << cipher[i][j];
			if(j % 6 == 0)
			{
				cout << '\n';
			}
		}
	}
	Rslt = DecSort(cipher, key, n, result);

	cout << "\nresult is :\n";
	for(i = 0; i < n; i ++)
	{
		cout << result[i] << "\n";
	}
	
	for(int i = 0; i < n; i ++)
	{
		if(plain[i] != NULL)
		{
			delete plain[i];
			plain[i] = NULL;
		}
		if(cipher[i] != NULL)
		{
			delete cipher[i];
			cipher[i] = NULL;
		}
		if(result[i] != NULL)
		{
			delete result[i];
			result[i] = NULL;
		}
	}

   	return SUCCESS;
}


int Sort(char *p[], int n)
{
	int i = 0;
	int j = 0;
	int k = 0;

	for(k = 0; k < n; k ++)
	{
		for(i = 0; i < n-k; i++)
		{
			if(p[i] == NULL)
			{
				return PLAIN_NULL;
			}

			int len0 = strlen(*p[i]);
			int len1 = strlen(*p[i+1]);
			int len = len0 > len1 ? len0 : len1;

			for(j = 0; j < len; j++)
			{
				if(p[i][j] > p[i+1][j])
				{
					char *tmp = p[i];
					p[i] = p[i+1];
					p[i+1] = tmp;

					break;
				}
			}
		}
	}

	return SUCCESS;
}

int EncSort(char *plain[], char key[KEY_LEN], int cnt, char *cipher[])
{
	int i = 0;
	int Rslt = 0;

	for(i = 0; i < cnt; i ++) 
	{
		Rslt = Encryptor(plain[cnt], key, cipher[cnt]);
		if(Rslt != SUCCESS)
		{
			break;
		}
	}
	
	return Rslt;
}

int DecSort(char *cipher[], char key[KEY_LEN], int cnt, char *result[])
{
	int i = 0;
	int Rslt = 0;
	
	for(i = 0; i < cnt; i ++) 
	{
		Rslt = Decryptor(cipher[cnt], key, result[cnt]);
		if(Rslt != SUCCESS)
		{
			break;
		}
	}
	
	return Rslt;
}