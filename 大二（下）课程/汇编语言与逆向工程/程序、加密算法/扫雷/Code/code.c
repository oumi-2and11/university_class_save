#include<stdio.h>
#include<windows.h>

int main()
{
	HWND hwnd;
	HANDLE hPr;
	DWORD dProc;
	DWORD col = 0x1005334;
	DWORD row = 0x1005338;
	byte bufcol;
	byte bufrow;
	DWORD base = 0x1005361;
	byte buf;
	int count = 0;
	int i = 0;
	int j = 0;
	int pX;
	int pY;
	hwnd = FindWindow(NULL, "É¨À×");
	if (hwnd == NULL)
	{
		MessageBox(NULL, "no", "no!", MB_OK);
		return 0;
	}
	GetWindowThreadProcessId(hwnd, &dProc);

	hPr = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dProc);
	if (hPr == NULL)
	{
		printf("wrong!\n");
		return 0;
	}
	ReadProcessMemory(hPr, (LPWORD)col, &bufcol, 1, NULL);
	ReadProcessMemory(hPr, (LPWORD)row, &bufrow, 1, NULL);
	for (i = 0; i < bufrow; i++)
	{
		for (j = 0; j < bufcol; j++)
		{
			ReadProcessMemory(hPr, (LPWORD)(base + i * 32 + j), &buf, 1, NULL);

			count++;
			if (buf == 0x8f)
			{
				pX = (j + 1) * 16;
				pY = (i + 1) * 16 + 48;
				PostMessage(hwnd, WM_RBUTTONDOWN, 0, ((pY << 16) + pX));
				PostMessage(hwnd, WM_RBUTTONUP, 0, ((pY << 16) + pX));
				buf = 'X';
			}
			else
			{
				pX = (j + 1) * 16;
				pY = (i + 1) * 16 + 48;
				PostMessage(hwnd, WM_LBUTTONDOWN, 0, ((pY << 16) + pX));
				PostMessage(hwnd, WM_LBUTTONUP, 0, ((pY << 16) + pX));
				buf = '0';
			}
			Sleep(10);
			printf("%c ", buf);
			if (count % bufcol == 0)
				printf("\n");
		}
	}
	system("pause");
	return 0;
}
