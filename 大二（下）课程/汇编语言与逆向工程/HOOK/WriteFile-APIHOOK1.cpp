#include<stdio.h>
#include<windows.h>
#include<string.h>

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
{
	FARPROC pFunc;
	char buf[] = { "The magic of API Hook!" };
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
	PBYTE pEditFunc;
	byte pJmpCode[6] = { 0xE9,0, };
	DWORD dwOldProtect, pOffset,dwWritenSize;
	char buf[] = "WriteFile";
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
	hFile = CreateFile("hook.txt", GENERIC_WRITE | GENERIC_READ, 0, NULL, CREATE_ALWAYS, 0x80, NULL);
	WriteFile(hFile, buf, strlen(buf), &dwWritenSize, NULL);
	return 0;
}

