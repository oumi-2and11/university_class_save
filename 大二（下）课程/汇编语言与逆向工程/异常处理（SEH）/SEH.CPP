#include <stdio.h>
#include <windows.h>

char pw[10] = "SEH";
char input[1024] = {0};

//异常处理函数
EXCEPTION_DISPOSITION
__cdecl
_except_handler( struct _EXCEPTION_RECORD *ExceptionRecord,
                void * EstablisherFrame,
                struct _CONTEXT *ContextRecord,
                void * DispatcherContext )
{
	//异常处理函数逻辑
	if(strcmp(input, pw) == 0){
		printf("ok, you are here. Congratulation!\n");
		system("pause");
	    exit(0);//完成口令匹配后结束进程——否则因为没有对异常代码进行处理，所以该进程会一直在触发异常和异常处理之间循环。
	}
	else{
		printf("ok, you are here. But your pw is wrong!\n");
	}
	
	
	//返回，告知os继续执行异常代码
	return ExceptionContinueExecution;
}


int main(){

	int a = 1, c = 0;

	int res;

	printf("please input password : ");
	scanf("%s", input);

	DWORD handler = (DWORD)_except_handler;

	//注册异常处理函数
	__asm{
		push handler;
		push FS:[0];
		mov FS:[0], ESP;
	}

	//设计的除零异常
	res = a / c;

	//如果不处理异常则会运行至此
	printf("What a pity, you found a wrong way.\n");
	system("pause");
	return -1;
}

