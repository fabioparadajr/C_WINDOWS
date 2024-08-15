#include <stdio.h>
#include <Windows.h>


int main(){

const char* filename = "script.ps1";
const char* text = "Test-Connection www.google.com";


HANDLE hFile = CreateFileA(filename, GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);

if (hFile == INVALID_HANDLE_VALUE){
  printf("Error\n");
  return 1;
}

DWORD bytesWritten;
BOOL success = WriteFile(hFile, text, strlen(text), &bytesWritten, NULL);

if (!success){
  printf("Not\n");
  CloseHandle(hFile);
  return 1;
}
/*CloseHandle(hFile);
return 0; */

ShellExecute(NULL, NULL, filename, NULL, NULL, 1);

}


