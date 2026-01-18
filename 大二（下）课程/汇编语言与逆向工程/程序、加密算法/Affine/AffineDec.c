#include<stdio.h>
#include<string.h>
int main()
{
	int key_a =3;
	int key_b =7;
	int re_key_a =9;
	char ciphertext[]="qxbxpluxvwhuzjct";
	char result[20]={0};
	int i;
	int len;
	int temp;
	
	len = strlen(ciphertext);
	for(i=0;i<len;++i){
		temp=ciphertext[i]-'a';
		temp=((temp-key_b+26)*re_key_a)%26;
		result[i]=temp+'a';
	}
	printf("plaintext is:\n%s\n",result);
	system("pause");
} 
