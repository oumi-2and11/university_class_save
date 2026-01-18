#include<stdio.h>
#include<string.h>
#define MAX_ARRAY 100

char answer[]="qxbxpluxvwhuzjct";

int main()
{
    int key_a = 3;
    int key_b = 7;
    int re_key_a = 9;
    char array[MAX_ARRAY]={0};
    int temp;
    int len;
    int i;
    puts("please input a string:");
    scanf("%s",array);

    len = strlen(array);//使 len为 array的长度，就是输入的长度 
    for(i=0;i<len;++i){
        if(array[i]<'a'||array[i]>'z')
            return -1;
    }
    for(i=0;i<len;++i){
        temp=array[i]-'a';
        temp = (temp*key_a+key_b)%26;//从这里看出来这是一个仿射密码 ， 
        array[i]=temp+'a';
    }
    
    //输出一下加密后是什么
    char miwen[MAX_ARRAY]={0};
	 for(i=0;i<len;++i){
        temp=array[i]-'a';
        temp = (temp*key_a+key_b)%26;
        miwen[i]=temp+'a';
    }
    printf("你的输入经过仿射加密后为：");
     for(i=0;i<len;++i){
        printf("%c",miwen[i]) ;
    }
    printf("\n");
	
	 
    
	if(strcmp(array,answer)==0){
		puts("ok, you really know");
	}
	else{
		puts("sorry");
	}
	system("pause");
}
