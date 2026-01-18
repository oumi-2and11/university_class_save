
#include <stdio.h>
#include <windows.h>

int main(){
	int a = 0, b = 1, c = 0;

	__try{
		c = b / a;//触发异常
	}

	__except(EXCEPTION_EXECUTE_HANDLER){
		MessageBox(NULL, TEXT("Integer divide by zero."), TEXT("ERROR"), MB_OK);
	
		a = 1;//修正异常
		c = b / a;
	}

	printf("b / a = %d\n", c);
	
	system("pause");

	return 0;
}