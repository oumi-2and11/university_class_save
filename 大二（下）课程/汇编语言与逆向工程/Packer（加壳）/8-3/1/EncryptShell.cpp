#include <iostream>
#include <string.h>
using namespace std;
int main(){
	char input[30];
	unsigned char check[]={137, 40, 169, 72, 145, 100, 197, 104, 50, 20, 80, 16, 97, 194, 110, 152, 226, 160, 233, 168, 175, 146, 55, 76, 16, 176, 43};
	unsigned char xor[]={25, 125, 189, 93, 79, 52, 18, 188, 126, 79, 76, 11, 56, 21, 63, 3, 58, 60, 183, 180, 178, 70, 45, 21, 11, 171, 116};
	unsigned char result[30];
	int len,i;
	printf("Please input: ");
	cin.getline(input,30,'\n');
	len = strlen(input);
	if(len<27){
		printf("Sorry, you are wrong!\n");
		return 0;
	}
	else{
		for(i=0;i<len;i++){
			result[i] = (input[i]>>2) + ((input[i]&0x3)<<6);
		}
		for(i=0;i<len;i++){
			result[i] = result[i]^xor[i];
		}
		for(i=0;i<len;i++){
			if(result[i]!=check[i])
				break;
		}
		if(i==len)
			printf("Correct! The flag is:%s\n",input);
		else
			printf("Sorry, you are wrong!\n");
	}
	return 0;
}
