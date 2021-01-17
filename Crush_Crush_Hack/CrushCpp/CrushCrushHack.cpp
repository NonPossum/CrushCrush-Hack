
#include <iostream>
#include <Windows.h>
#include <vector>
#include <TlHelp32.h>
#include <tchar.h>
using namespace std;
int Hack(int newDiamonds);


DWORD dwGetModuleBaseAddress(TCHAR* lpszModuleName, DWORD pID) {
	DWORD dwModuleBaseAddress = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);
	MODULEENTRY32 ModuleEntry32 = { 0 };
	ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

	if (Module32First(hSnapshot, &ModuleEntry32))
	{
		do {
			if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0)
			{
				dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
				break;
			}
		} while (Module32Next(hSnapshot, &ModuleEntry32));


	}
	CloseHandle(hSnapshot);
	return dwModuleBaseAddress;
}






int main()
{
	DWORD pID;
	DWORD off1, off2, off3, off4, off5;
	DWORD baseAddress;
	DWORD diamonds;
	int currentDiamonds;
	char moduleName[] = "CrushCrush.exe";
	HWND hGameWindow;
	HANDLE pHandle;
	int newDiamonds;

	hGameWindow = FindWindow(NULL, "Crush Crush");

	GetWindowThreadProcessId(hGameWindow, &pID);

	pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);


	DWORD clientBase = dwGetModuleBaseAddress(_T(moduleName), pID);

	ReadProcessMemory(pHandle, (LPCVOID)(clientBase + 0x00FD3814), &baseAddress, sizeof(baseAddress), NULL);


	ReadProcessMemory(pHandle, (LPCVOID)(baseAddress + 0x40), &off1, sizeof(off1), NULL);
	ReadProcessMemory(pHandle, (LPCVOID)(off1 + 0xA4), &off2, sizeof(off2), NULL);
	ReadProcessMemory(pHandle, (LPCVOID)(off2 + 0x4), &off3, sizeof(off3), NULL);
	ReadProcessMemory(pHandle, (LPCVOID)(off3 + 0x10), &off4, sizeof(off4), NULL);


	diamonds = off4 + 0x11C;


	ReadProcessMemory(pHandle, (LPCVOID)diamonds, &currentDiamonds, sizeof(currentDiamonds), NULL);

	cout << "Diamonds to add:";
	cin >> newDiamonds;

	WriteProcessMemory(pHandle, (LPVOID)(diamonds), &newDiamonds, sizeof(newDiamonds), 0);


	cin.get();
	return 0;

}





