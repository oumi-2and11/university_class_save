#include<stdio.h>
#include<string.h>
int main()
{
	int key_a =3;
	int key_b =7;
	
	//加一块求逆的代码：
	int cs=26; //模数 
	int j=1;
	for(j=1; j<cs ; j++)
	{
		if( (j*key_a) %cs==1)
		{
			printf("a mod cs 的逆为 %d\n", j);
			break;
		}
	 } 
	
	
	
	
	int re_key_a =7;//9是a=3 mod 26的逆 
	char ciphertext[]="ippio";
	char result[20]={0};
	int i;
	int len;
	int temp;
	
	len = strlen(ciphertext);
	for(i=0;i<len;++i){
		temp=ciphertext[i]-'i';
		temp=((temp-key_b+10)*re_key_a)%10;//temp=((temp-key_b+26)*re_key_a)%26;模数26的情况 
		result[i]=temp+'0';
	}
	printf("plaintext is:\n%s\n",result);
	system("pause");
} 
