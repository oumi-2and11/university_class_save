#include <iostream>
#include <cstring>

using namespace std;


#define TEXT_LEN	64
#define KEY_LEn		16

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
	
	j = 0;
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
	
	cout << "\nCipher text:\n";
	for(i = 0; i < strlen(cipher); i ++)
	{
		cout << hex << cipher[i];
		if(i % 6 == 0)
		{
			cout << '\n';
		}
	}
	
	j = 0;
	for(i = 0; i < strlen(cipher); i ++)
	{
		result[i] = cipher[i] ^ key[j];
		j ++;
		if(j >= strlen(key))
		{
			j = 0;
		}
	}
	result[i] = '\0';
	
	cout << "result is :" << result;
	
   	return 0;
}