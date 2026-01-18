#include<stdio.h>
#include<Windows.h>
 
int main(int argc,char *argv[])
{
    printf("*****************So Let's play a Game!*****************\n");

    __asm
    {
        xor eax,eax
		// jz直接跳转到__label，不会执行jnz指令
        jz __label
		// jnz指令指向__label2，混淆递归行进算法
        jnz __label2
__label2:
        __emit 0xE8
    }

__label:
    printf("*****************So Let's play a Game!*****************\n");

    system("pause");
    return 0;
}
