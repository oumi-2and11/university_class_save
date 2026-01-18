#include<stdio.h>
#include<string.h>

int main(){
	unsigned char check[]={137, 40, 169, 72, 145, 100, 197, 104, 50, 20, 80, 16, 97, 194, 110, 152, 226, 160, 233, 168, 175, 146, 55, 76, 16, 176, 43};
	unsigned char xor[]={25, 125, 189, 93, 79, 52, 18, 188, 126, 79, 76, 11, 56, 21, 63, 3, 58, 60, 183, 180, 178, 70, 45, 21, 11, 171, 116};
	unsigned char flag[30]={0};
	int len,i;
	len = 27;
	for(i=0;i<len;i++){
		flag[i] = check[i]^xor[i];
		flag[i] = ((flag[i]&0x3f)<<2)+(flag[i]>>6);
	}
	printf("The flag is: %s\n",(char *)flag);
	return 0;
}