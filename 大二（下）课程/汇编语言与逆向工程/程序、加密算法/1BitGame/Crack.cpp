#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define PASSWORD "1234567"

int verify_password (char *password)
{
	int authenticated;
	authenticated=strcmp(password,PASSWORD);
	return authenticated;
}

int main()
{
	int valid_flag=0;
	char password[1024];
	while(1)
	{
		printf("please input password:     ");
		scanf("%s",password);
		valid_flag=verify_password(password);
		if (valid_flag)
		{
			printf("Incorrect passward!\n\n");
		}
		else
		{
			printf("Congratulations! You have passed the verification!\n");
			break;
		}
	}
	system("pause");
	return 0;
}