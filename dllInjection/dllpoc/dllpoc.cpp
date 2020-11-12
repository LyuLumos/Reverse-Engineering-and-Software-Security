#include <windows.h>
#include <stdio.h>
#include <iostream>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

//extern "C" __declspec(dllexport) int poc(int code, WPARAM wParam, LPARAM lParam) {
extern "C" __declspec(dllexport) BOOL cuc() {
	MessageBox(NULL, L"CUC called!", L"Inject All The Things!", 0);

	TCHAR szExePath[MAX_PATH], szInfo[MAX_PATH + 100];
	GetModuleFileName(NULL, szExePath, MAX_PATH);

	printf("I'm in Process (%d), path is ", GetCurrentProcessId());
#ifdef UNICODE
	char const* format = "%ls";
#else 
	char const* format = "%s";
#endif
	printf(format, szExePath);

	MessageBox(NULL, szExePath, L"Inject All The Things!", 0);

	//return(CallNextHookEx(NULL, code, wParam, lParam));
	return TRUE;
}

BOOL bj() {
	MessageBox(NULL, L"POC called!", L"Inject All The Things!", 0);

	//return(CallNextHookEx(NULL, code, wParam, lParam));
	return TRUE;
}