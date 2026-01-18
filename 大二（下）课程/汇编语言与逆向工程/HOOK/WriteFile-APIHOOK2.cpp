#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h> 
BYTE pOrgByte[5] = { 0, };
typedef BOOL(WINAPI *PFWriteFile)(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
void unhook()
{
	DWORD dwOldProtect;
	PBYTE pWriteFile;
	FARPROC pFunc;
	pFunc = GetProcAddress(GetModuleHandleA("kernel32.dll"), "WriteFile");
	pWriteFile = (PBYTE)pFunc;
	VirtualProtect(pWriteFile, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);	
	memcpy(pWriteFile, pOrgByte, 5);	
	VirtualProtect(pWriteFile, 5, dwOldProtect, &dwOldProtect);
}
BOOL __stdcall MyWriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped)
{	FARPROC pFunc;	
	char buf[] ="hook";	
	unhook();	
	pFunc = GetProcAddress(GetModuleHandleA("kernel32.dll"), "WriteFile");		
	((PFWriteFile)pFunc)(hFile, buf, strlen(buf), lpNumberOfBytesWritten, lpOverlapped);	
	return TRUE;
}
int main()
{
	HANDLE hFile;	
	HMODULE hKernel32;	
	FARPROC pWriteFile;	
	FILE *fp=NULL;
	FILE *fkey=NULL;
	PBYTE pEditFunc;	
	BYTE pJmpCode[6] = { 0xE9,0, };	
	char pwd[15];
	char key[15];
	int ret;
	DWORD dwOldProtect, pOffset,dwWritenSize;	
	char buf[] = "real_pwd";	
	hKernel32 = GetModuleHandle("kernel32.dll");	
	pWriteFile = GetProcAddress(hKernel32, "WriteFile");	
	pEditFunc = (PBYTE)pWriteFile;	
	if (VirtualProtect(pEditFunc, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect))	
	{		
		memcpy(pOrgByte, pEditFunc, 5);		
		pOffset = (ULONGLONG)MyWriteFile - (ULONGLONG)pWriteFile - 5;		
		memcpy(&pJmpCode[1], &pOffset, 4);		
		memcpy(pWriteFile, &pJmpCode[0], 5);		
		VirtualProtect(pWriteFile, 5, dwOldProtect, &dwOldProtect);	
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
	ret=lstrcmp(key,pwd);
	if(ret == 0)
        printf("congratulations!\n");
    else
        printf("try again!\n");
	
	system("Pause");
	return 0;	
}
