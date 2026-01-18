#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>
#include <string>
#include <atlbase.h>
BOOL IATHook(HMODULE hModule, LPCTSTR pImageName, LPCVOID pTargetFuncAddr, LPCVOID pReplaceFuncAddr )
{
    IMAGE_DOS_HEADER* pImgDosHdr = ( IMAGE_DOS_HEADER* )hModule;
    IMAGE_OPTIONAL_HEADER* pImgOptHdr = ( IMAGE_OPTIONAL_HEADER* )( ( DWORD )hModule + pImgDosHdr->e_lfanew + 24 );
    IMAGE_IMPORT_DESCRIPTOR* pImgImportDes = ( IMAGE_IMPORT_DESCRIPTOR* )( ( DWORD )hModule + pImgOptHdr->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress );
    IMAGE_THUNK_DATA* pImgThunkData = NULL;
	std::string TargetLibraryName;
    DWORD Value = 0;
    DWORD OldProtect = 0;
    DWORD NewProtect = 0;
    LPDWORD FuncAddress = NULL;
     
    while ( pImgImportDes->Characteristics != 0 )
    {
        USES_CONVERSION;
        LPCTSTR lpszName =  ( ( LPCSTR )( DWORD )hModule + pImgImportDes->Name ) ;
        TargetLibraryName = lpszName;
        if ( TargetLibraryName.compare( pImageName ) == 0 )
        {
            pImgThunkData = ( IMAGE_THUNK_DATA* )( ( DWORD )hModule + pImgImportDes->FirstThunk );
            break;
        }
        pImgImportDes++;
    }
    if ( pImgThunkData == NULL )
    {
        return FALSE;
    }
    while ( pImgThunkData->u1.Function )
    {
        FuncAddress = ( LPDWORD ) & ( pImgThunkData->u1.Function );
        if ( *FuncAddress == ( DWORD )pTargetFuncAddr )
        {
            VirtualProtect( FuncAddress, sizeof( DWORD ), PAGE_READWRITE, &OldProtect );
            if ( !WriteProcessMemory( ( HANDLE ) - 1, FuncAddress, &pReplaceFuncAddr, 4, NULL ) )
            {
                return FALSE;
            }
            VirtualProtect( FuncAddress, sizeof( DWORD ), OldProtect, 0 );
            return TRUE;
        }
        pImgThunkData++;
    }
    return FALSE;
}
 
typedef int ( WINAPI* pWriteFile )( HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten,LPOVERLAPPED lpOverlapped );
pWriteFile p_WriteFile = 0;
 
int WINAPI MyWriteFile( HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten,LPOVERLAPPED lpOverlapped )
{
    char mybuffer[7]="hooked";
    return p_WriteFile(hFile, mybuffer, sizeof(mybuffer), lpNumberOfBytesWritten, lpOverlapped);
}
 
BOOL Hook(HMODULE hModule,LPCTSTR pImageName,LPCSTR pTargetFuncName)
{
    HMODULE hLib = LoadLibrary( pImageName );
    if ( NULL != hLib )
    {
        p_WriteFile = ( pWriteFile )GetProcAddress( hLib, pTargetFuncName );
        BOOL bRet = IATHook( hModule, pImageName, p_WriteFile, MyWriteFile );
        FreeLibrary( hLib );
        return bRet;
    }
     
    return FALSE;
}
 
int main()
{
    
    char buffer[10]="a";
    DWORD bytesWritten;
    
    HANDLE fh = CreateFile("pwd.txt", GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);


    if(fh == INVALID_HANDLE_VALUE){
        printf("File handle not opened.\n");
        system("Pause");
        exit(EXIT_FAILURE);
    } else {
        printf("File handle opened.\n");
    }
    printf("Please set your password(no more than 10 letters):\n");
    scanf("%s",&buffer);

    Hook( GetModuleHandle( NULL ), _T( "KERNEL32.dll" ), ( "WriteFile" ) );
 
    WriteFile(fh, buffer, sizeof(buffer), &bytesWritten, NULL);

    system("Pause");
    return 0;
}