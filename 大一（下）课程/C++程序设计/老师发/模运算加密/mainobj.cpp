#include <iostream>
#include <cstring>

using namespace std;


#define TEXT_LEN	64
#define KEY_LEn		16

class Crypt
{
private:
    char Plain[TEXT_LEN];
	char Key[KEY_LEn];
	char Cipher[TEXT_LEN];
	char Result[TEXT_LEN];

public:
    int InputCipher(char p[]);
    int InputKey(char k[]);
    int Encypt();
    int Decrypt();
    int OutputCipher();
    int OutputResult();
};


int Crypt::InputCipher(char p[])
{
    strcpy(Plain, p);

    return 0;
}
int Crypt::InputKey(char k[])
{
    strcpy(Key, k);

    return 0;
}
int Crypt::Encypt()
{
    int i, j;

    j = 0;
	for(i = 0; i < strlen(Plain); i ++)
	{
		Cipher[i] = Plain[i] ^ Key[j];
		j ++;
		if(j >= strlen(Key))
		{
			j = 0;
		}
	}
	Cipher[i] = '\0';

    return 0;
}
int Crypt::Decrypt()
{
    int i, j;

    j = 0;
	for(i = 0; i < strlen(Cipher); i ++)
	{
		Result[i] = Cipher[i] ^ Key[j];
		j ++;
		if(j >= strlen(Key))
		{
			j = 0;
		}
	}
	Result[i] = '\0';

    return 0;
}
int Crypt::OutputCipher()
{
    int i;

	cout << "\nCipher text:\n";
	for(i = 0; i < strlen(Cipher); i ++)
	{
		cout << hex << "0x" << Cipher[i] << " ";
		if(i % 6 == 0)
		{
			cout << '\n';
		}
	}

    return 0;
}

int Crypt::OutputResult()
{
	cout << "result is :" << Result;

    return 0;
}

int main()
{
	int i, j;
	
	char plain[TEXT_LEN];
	char key[KEY_LEn];
	char cipher[TEXT_LEN];
	char result[TEXT_LEN];
	
   	cout << "\nInput plain text:";
	cin >> plain;
	
   	cout << "Input plain key:";
	cin >> key;
	
	Crypt crt;

    crt.InputCipher(plain);
    crt.InputKey(key);

    crt.Encypt();

    crt.OutputCipher();

    crt.Decrypt();

    crt.OutputResult();
    
	
   	return 0;
}