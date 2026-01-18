#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char check[] = "GMBH|Xfmd1nf`u1`uif`xpsme`pg`Sfwfstf~";

int readInput(char *buf, int len) {
	char ch;
	int i;
	for (i = 0; i<len; i++) {
		ch = getchar();
		if (ch == '\n')
			break;
		buf[i] = ch;
	}
	buf[i] = 0;
	return i;
}

int checkflag(char *buf) {
	int i;
	if (strlen(buf) != 37)
		return 0;
	for (i = 0; i<37; i++) {
		if (buf[i] + 1 != check[i])
			return 0;
	}
	if (i == 37)
		return 1;
}

/*
int checkstrGen(){
char flag[] = "FLAG{Welc0me_t0_the_world_of_Reverse}";
char check[40] = {0};
int i;
for(i=0;i<strlen(flag);i++){
check[i] = flag[i] + 1;
}
printf("%s",check);
return 0;
}*/

int main() {
	char input[50];
	printf("Please give me your input: ");
	readInput(input, 40);
	if (checkflag(input)) {
		printf("Good! The flag is your input!!!\n");
	}
	else {
		printf("Sorry! You are wrong!!!\n");
	}
	return 0;
}