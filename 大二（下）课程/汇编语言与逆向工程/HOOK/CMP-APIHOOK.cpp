#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h> 
BYTE pOrgByte[5] = { 0, };
void unhook()

{
	DWORD dwOldProtect;
	PBYTE plstrcmp;
	FARPROC pFunc;
	pFunc = GetProcAddress(GetModuleHandleA("kernel32.dll"), "lstrcmp");
	plstrcmp = (PBYTE)pFunc;
	VirtualProtect(plstrcmp, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);	
	memcpy(plstrcmp, pOrgByte, 5);	
	VirtualProtect(plstrcmp, 5, dwOldProtect, &dwOldProtect);
}

int __stdcall Mylstrcmp(LPCTSTR lpString1,LPCTSTR lpString2)
{	
	printf("hook!\n");
	unhook();		
	return 0;
}

int main()
{
	HANDLE hFile;	
	HMODULE hKernel32;	
	FARPROC plstrcmp;	
	FILE *fp=NULL;
	PBYTE pEditFunc;	
	BYTE pJmpCode[6] = { 0xE9,0, };	
	char pwd[15];
	char key[15];
	int ret;
	DWORD dwOldProtect, pOffset,dwWritenSize;	
	char buf[] = "real_pwd";	
	hKernel32 = GetModuleHandle("kernel32.dll");	
	plstrcmp = GetProcAddress(hKernel32, "lstrcmp");	
	pEditFunc = (PBYTE)plstrcmp;	

	if (VirtualProtect(pEditFunc, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect))	
	{		
		memcpy(pOrgByte, pEditFunc, 5);		
		pOffset = (ULONGLONG)Mylstrcmp - (ULONGLONG)plstrcmp - 5;		
		memcpy(&pJmpCode[1], &pOffset, 4);		
		memcpy(plstrcmp, &pJmpCode[0], 5);		
		VirtualProtect(plstrcmp, 5, dwOldProtect, &dwOldProtect);	
	}	
	hFile = CreateFile("pwd.txt", GENERIC_ALL,0, NULL, CREATE_ALWAYS, 0x80, NULL);	

	/*
	if(hFile!=NULL)
		printf("open1 success\n");
	else
		printf("open1 fail\n");
	*/

	WriteFile(hFile, buf, strlen(buf), &dwWritenSize, NULL);
	CloseHandle(hFile);

	if(fp=fopen("pwd.txt","r"))
		printf("open success\n");
	else
		printf("open fail\n");
	if(fp!=NULL)
		fscanf(fp,"%s",pwd);
	else
		printf("scan fail\n");

	printf("plz input key\n");
	scanf("%s",key);

	if(fp!=NULL)
		fclose(fp);

	ret=lstrcmp((LPCTSTR)key,(LPCTSTR)pwd);

	if(ret == 0)
        printf("congratulations!\n");
        else
        printf("try again!\n");
		
	system("Pause");
        return 0;
}
