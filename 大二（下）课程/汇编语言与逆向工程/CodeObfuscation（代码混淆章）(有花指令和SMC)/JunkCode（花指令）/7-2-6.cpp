#include<stdio.h>
#include<Windows.h>
 
int main(int argc,char *argv[])
{
    printf("*****************So Let's play a Game!*****************\n");

    __asm
    {
        xor eax,eax
        jz __label
        add esp,0x48
    }

__label:
    printf("*****************So Let's play a Game!*****************\n");

    system("pause");
    return 0;
}
