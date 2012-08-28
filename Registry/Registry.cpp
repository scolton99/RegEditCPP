#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;

HKEY hKey;

int _WinMain() {
	if(RegOpenKeyEx(HKEY_CURRENT_USER,L"Software\\Scolton\\test",0,KEY_SET_VALUE,&hKey) == ERROR_SUCCESS){
		DWORD dwValue = 245;

		if(RegSetValueEx(hKey,L"NameOfValue",0,REG_DWORD,reinterpret_cast<BYTE *>(&dwValue),sizeof(dwValue)) != ERROR_SUCCESS){
			RegCloseKey(hKey);
		}
	}else{
		cout << "The key could not be opened" << endl;
		RegCloseKey(hKey);
	}
	return 0;
}