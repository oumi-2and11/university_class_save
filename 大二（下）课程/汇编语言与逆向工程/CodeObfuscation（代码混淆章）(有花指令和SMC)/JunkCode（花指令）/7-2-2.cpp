#include<stdio.h>
#include<Windows.h>
 
int main(int argc,char *argv[])
{
    printf("*****************So Let's play a Game!*****************\n");

    __asm
    {
        xor eax,eax
		// jz跳转到下面的__label，导致__emit 0xE8无法执行
        jz __label 
        __emit 0xE8
    }

__label:
    printf("*****************So Let's play a Game!*****************\n");

    system("pause");
    return 0;
}
