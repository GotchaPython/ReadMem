// ReadMem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <Windows.h>


DWORD address = {0x02CEAA38};
DWORD temp;
unsigned long _numread;

int main()
{
	printf("Obtaining Process Handle..\n");

	HWND hwnd = FindWindow(0, L"Game here");

	if (hwnd == 0) {
		printf("Could not find window!\n");
	}
	else {
		DWORD pid;
		GetWindowThreadProcessId(hwnd, &pid);
		HANDLE hproc = OpenProcess(PROCESS_ALL_ACCESS, false, pid);

		if (!hproc) {
			printf("Could not open process!\n");
		}
		else {
			ReadProcessMemory(hproc, (LPVOID)address, &temp, sizeof(temp), &_numread);
			printf("Value: %d\n",temp);
		}
	}
	system("PAUSE");

    return 0;
}

